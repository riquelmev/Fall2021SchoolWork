import heapq
from puzzle8 import *
import time

def numWrongTiles(state):
    count = 0
    solutionState = solution()
    for i in range(9):
        solutionTile = getTile(solutionState,i)
        tile = getTile(state,i)
        if tile == 0:
            continue
        elif tile != solutionTile:
            count +=1
    return count


def manhattanDistance(state):
    total = 0
    solutionState = solution()
    tiles = [1,2,3,8,0,4,7,6,5]
    for i in range(9):
        solutionTile = getTile(solutionState,i)
        tile = getTile(state,i)
        if tile == 0:
            continue
        elif tile != solutionTile:
            current = xylocation(i)
            ideal = tiles.index(tile)
            target = xylocation(ideal)
            xfactor = abs(target[0] - current[0])
            yfactor = abs(target[1] - current[1])
            total_factor = xfactor + yfactor
            total += total_factor
    return total



def astar(state,heuristic):
    hp = []
    start = time.time()
    #f(n) = h(n) + g(n)
    goal = solution()
    heapq.heappush(hp, (heuristic(state), state, []))
    while (len(hp)) != 0:
        current = heapq.heappop(hp)
        blank = blankSquare(current[1])
        if current[1] == goal:
            timeFinished = time.time() - start
            print("Time Taken is:",timeFinished)
            return current[2]
        else:
            choices = neighbors(blank)
            for neighbor in choices:
                neighborState = moveBlank(current[1],neighbor)
                heapq.heappush(hp, (heuristic(neighborState) + len(current[2]) + 1, neighborState, current[2] + [neighbor]))












