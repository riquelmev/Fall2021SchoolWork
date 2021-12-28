# Initializes and solves the TSP with genetic algorithms
# Created by Vicente Riquelme and Eric Wright

import networkx as nx
import matplotlib
matplotlib.use('Agg') 
import matplotlib.pyplot as plt
import random
#random.seed(10)

# Creates graph and finds an approximate solution
num_nodes = 100
g = nx.complete_graph(num_nodes)
for edge in g.edges():
    g[edge[0]][edge[1]]['weight'] = (round(random.random()*100,1))
sol = nx.algorithms.approximation.traveling_salesman.christofides(g)
sol = sol[:-1]

#Construct a random valid solution
def construct_initial():
    return(random.sample(g.nodes(), len(g.nodes())))

#Strings together nodes to form tuples that have an edge weight.
def construct_path(nodes):
    path = []
    for i in range(len(nodes) - 1):
        move = (nodes[i], nodes[i + 1])
        path.append(move)
    path.append((nodes[-1],nodes[0]))
    return path

#Computes total path weight of list of nodes.
def path_weight(path):
    total = 0
    new_path = construct_path(path)
    for edge in new_path:
        total += g[edge[0]][edge[1]]['weight']
    return total

#Mutates a given solution by swapping two random nodes
def mutation(complete_path):
    path_minus_end = complete_path.copy()#[:-1]
    first = random.randint(0, num_nodes-1)
    second = random.randint(0, num_nodes-1)
    path_minus_end[first], path_minus_end[second] = path_minus_end[second], path_minus_end[first]
    return path_minus_end

#Crossesover two solutions while using PMX so that the solution remains valid
def crossover(path1, path2):
    path_minus_end1 = path1.copy()
    path_minus_end2 = path2.copy()
    offset = random.randint(0, num_nodes)
    newpath1 = path_minus_end1
    newpath2 = path_minus_end2
    for i in range(offset):
        swap1 = path_minus_end2[i]
        newpath1[i], newpath1[newpath1.index(swap1)] = newpath1[newpath1.index(swap1)], newpath1[i]
    for i in range(offset):
        swap2 = path_minus_end1[i]
        newpath2[i], newpath2[newpath2.index(swap2)] = newpath2[newpath2.index(swap2)], newpath2[i]
    return newpath1, newpath2

#Culls undesirable individuals while also keeping some random individuals for diversity
def fitness(generation):
    dict = {}
    ordered_generation = []
    survivors = 10
    for path in generation:
        dict[tuple(path)] = path_weight(path)
    sorted_paths = sorted(dict.items(), key=lambda kv: kv[1])
    for path in sorted_paths:
        ordered_generation.append(list(path[0]))
    keepers = ordered_generation[:survivors]
    rand = random.randint(survivors, len(sorted_paths))
    keepers.append(ordered_generation[rand-1])
    rand = random.randint(survivors, len(sorted_paths))
    keepers.append(ordered_generation[rand-1])
    return keepers

#simulates many generations of individuals evolving
def simulation(iterations):
    evolution_track = []
    generation = []
    for i in range(10):
        generation.append(construct_initial())
    potential_generation = []
    for i in range(iterations):
        scrambled_paths = generation
        for j in range(len(scrambled_paths)-1):
            new_mutation = mutation(scrambled_paths[j])
            new_crossover, new_crossover2 = crossover(scrambled_paths[j],scrambled_paths[j+1])
            potential_generation.append(scrambled_paths[j])
            potential_generation.append(new_mutation)
            potential_generation.append(new_crossover)
            potential_generation.append(new_crossover2)
        generation = fitness(potential_generation)
        current_best_path, current_best_weight = fittest_individual(generation)
        evolution_track.append(current_best_weight)
        potential_generation = []
    best_path, best_weight = fittest_individual(generation)
    return best_path, best_weight, evolution_track

#Returns the fittest individual of a generation
def fittest_individual(generation):
    best_weight = 1000000
    best_path = None
    for finalist in generation:
        if path_weight(finalist) < best_weight:
            best_path = finalist
            best_weight = path_weight(finalist)
    return best_path, best_weight

#returns whether a solution is valid
def isValid(solution):
    check = set()
    for node in solution:
        check.add(node)
    if len(check) == 100 and len(solution) == 100:
        return True
    else:
        return False

def main():
    iterations = 2000
    best_path, best_weight, evol = simulation(iterations)
    plt.plot(evol)
    plt.ylabel("Path Length")
    plt.xlabel("Iterations")
    plt.title("Path Length of Fittest Individual Over Time")
    plt.savefig("Path Length of Fittest Individual Over Time")
    print("Our algorithm ran for " + str(iterations) + " iterations.")
    print("The 3/2 Hamilton approximation path using the Christofides algorithm is: ", sol ," with a path weight of:",path_weight(sol))
    print()
    print("The best solution our genetic algorithm could produce is: ", best_path, "with a path weight of:", best_weight)
    print("Is our solution valid?" ,isValid(best_path))

if __name__ == "__main__":
    main()