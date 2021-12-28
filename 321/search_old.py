from puzzle8 import *

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


def itdeep(state):
    depth = 0
    start = time.time()
    timedict = {}
    while depth != -1:
        timedict[depth] = time.time() - start
        result = depth_limited_search(state,depth)
        if result == False:
            depth += 1
        else:
            result.pop(0)
            timedict[depth+1] = time.time() - start
            print(timedict)
            return result

def depth_limited_search(state, depth):
    blank = blankSquare(state)
    if state == solution():
        return [blank]
    elif depth == 0:
        return False
    else:
        choices = neighbors(blank)
        for neighbor in choices:
            answer = depth_limited_search(moveBlank(state, neighbor), depth - 1)
            if answer != False:
                return [blank] + answer
        return False

