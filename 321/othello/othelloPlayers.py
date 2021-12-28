import othelloBoard

from typing import Tuple, Optional

'''You should modify the chooseMove code for the ComputerPlayer
class. You should also modify the heuristic function, which should
return a number indicating the value of that board position (the
bigger the better). We will use your heuristic function when running
the tournament between players.

Feel free to add additional methods or functions.'''


class HumanPlayer:
    '''Interactive player: prompts the user to make a move.'''

    def __init__(self, name, color):
        self.name = name
        self.color = color

    def chooseMove(self, board):
        while True:
            try:
                move = eval('(' + input(self.name + \
                                        ': enter row, column (or type "0,0" if no legal move): ') \
                            + ')')

                if len(move) == 2 and type(move[0]) == int and \
                        type(move[1]) == int and (move[0] in range(1, 9) and \
                                                  move[1] in range(1, 9) or move == (0, 0)):
                    break

                print('Illegal entry, try again.')
            except Exception:
                print('Illegal entry, try again.')

        if move == (0, 0):
            return None
        else:
            return move


def heuristic(board) -> int:
    '''New Heuristic takes into account number of legal moves, tiles down and corners.'''
    sum = 0
    moves_white = len(board._legalMoves(1))
    moves_black = len(board._legalMoves(-1))
    sum += 2 * moves_white - moves_black

    for i in range(1, othelloBoard.size - 1):
        for j in range(1, othelloBoard.size - 1):
            sum += board.array[i][j]
            # if i % 7 ==1 or j % 7 == 1:
            #     sum += 3* board.array[i][j]

    corners = [(1,1), (1,8), (8,1),(8,8)]
    for corner in corners:
        #print(corner[1])
        sum += 10* board.array[corner[0]][corner[1]]
    return sum


class ComputerPlayer:
    '''Computer player: chooseMove is where the action is.'''

    def __init__(self, name, color, heuristic, plies) -> None:
        self.name = name
        self.color = color
        self.heuristic = heuristic
        self.plies = plies
        self.heuristicCalls = 0

    # chooseMove should return a tuple that looks like:
    # (row of move, column of move, number of times heuristic was called)
    # We will be using the third piece of information to assist with grading.
    def chooseMove(self, board) -> Optional[Tuple[int, int, int]]:
        '''Finds best move'''
        self.heuristicCalls = 0
        moves = board._legalMoves(self.color)
        if len(moves) == 0:
            return None
        else:
            bestMove = moves[0]
            if self.color == 1:
                best = -4999
                for move in moves:
                    newBoard = board.makeMove(move[0], move[1], self.color)
                    val = self.max_value(newBoard, 1, 0)
                    if val > best:
                        best = val
                        bestMove = move
            else:
                best = 4999
                for move in moves:
                    newBoard = board.makeMove(move[0], move[1], self.color)
                    val = self.min_value(newBoard, 1, 0)
                    if val < best:
                        best = val
                        bestMove = move
            return (bestMove[0], bestMove[1], self.heuristicCalls)



        # None is considered a pass
    def max_value(self, board,depth,passes):
        if (passes == 2):
            scores = board.scores()
            if scores[0] > scores[1]:
                return -5000
            elif scores[1] > scores[0]:
                return 5000
            else:
                return 0
        elif depth == self.plies:
            self.heuristicCalls = self.heuristicCalls + 1
            return self.heuristic(board)
        moves = board._legalMoves(1)
        if len(moves) == 0:
            return self.min_value(board, depth+1,passes+1)
        best = -5000
        for move in moves:
            newBoard = board.makeMove(move[0],move[1], 1)
            value = self.min_value(newBoard, depth+1, passes)
            best = max(best, value)
        return best

    def min_value(self, board,depth,passes):
        if (passes == 2):
            scores = board.scores()
            if scores[0] > scores[1]:
                return -5000
            elif scores[1] > scores[0]:
                return 5000
            else:
                return 0
        elif depth == self.plies:
            self.heuristicCalls = self.heuristicCalls + 1
            return self.heuristic(board)
        moves = board._legalMoves(-1)
        if len(moves) == 0:
            return self.max_value(board, depth+1,passes+1)
        best = 5000
        for move in moves:
            newBoard = board.makeMove(move[0],move[1], -1)
            value = self.max_value(newBoard, depth+1, passes)
            best = min(best, value)
        return best


class ComputerPlayerPruning:
    '''Computer player: chooseMove is where the action is.'''

    def __init__(self, name, color, heuristic, plies) -> None:
        self.name = name
        self.color = color
        self.heuristic = heuristic
        self.plies = plies
        self.heuristicCalls = 0

    # chooseMove should return a tuple that looks like:
    # (row of move, column of move, number of times heuristic was called)
    # We will be using the third piece of information to assist with grading.
    def chooseMove(self, board) -> Optional[Tuple[int, int, int]]:
        '''Finds best move'''
        self.heuristicCalls = 0
        moves = board._legalMoves(self.color)
        if len(moves) == 0:
            return None
        else:
            bestMove = moves[0]
            if self.color == 1:
                best = -4999
                for move in moves:
                    newBoard = board.makeMove(move[0], move[1], self.color)
                    val = self.max_value(newBoard, 1, 0,-5000,5000)
                    if val > best:
                        best = val
                        bestMove = move
            else:
                best = 4999
                for move in moves:
                    newBoard = board.makeMove(move[0], move[1], self.color)
                    val = self.min_value(newBoard, 1, 0,-5000,5000)
                    if val < best:
                        best = val
                        bestMove = move
            return (bestMove[0], bestMove[1], self.heuristicCalls)



        #None is considered a pass
    def max_value(self, board,depth,passes,alpha,beta):
        if (passes == 2):
            scores = board.scores()
            if scores[0] > scores[1]:
                return -5000
            elif scores[1] > scores[0]:
                return 5000
            else:
                return 0
        elif depth == self.plies:
            self.heuristicCalls = self.heuristicCalls + 1
            return self.heuristic(board)
        moves = board._legalMoves(1)
        if len(moves) == 0:
            return self.min_value(board, depth+1,passes+1,alpha,beta)
        best = -5000
        for move in moves:
            newBoard = board.makeMove(move[0],move[1], 1)
            best = max(best,self.min_value(newBoard, depth+1, passes, alpha,beta))
            if best >= beta:
                return best;
            alpha = max(alpha, best)
        return best

    def min_value(self, board,depth,passes,alpha,beta):
        if (passes == 2):
            scores = board.scores()
            if scores[0] > scores[1]:
                return -5000
            elif scores[1] > scores[0]:
                return 5000
            else:
                return 0
        elif depth == self.plies:
            self.heuristicCalls = self.heuristicCalls + 1
            return self.heuristic(board)
        moves = board._legalMoves(-1)
        if len(moves) == 0:
            return self.max_value(board, depth+1,passes+1,alpha,beta)
        best = 5000
        for move in moves:
            newBoard = board.makeMove(move[0],move[1], -1)
            best = min(best,self.max_value(newBoard, depth+1, passes,alpha,beta))
            if best <= alpha:
                return best;
            beta = min(beta, best)
        return best