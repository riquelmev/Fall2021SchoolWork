# Initializes and solves the TSP with genetic algorithms
# Created by Vicente Riquelme and Eric Wright
import networkx as nx
import matplotlib

matplotlib.use('Agg')
import matplotlib.pyplot as plt
import random

random.seed(10)
# Constants
alpha = 1
beta = 5
sigma = 0.5
starting_trail = 0.5
Q = 100
iterations = 75
num_ants = 10
num_nodes = 100


# Creates graph and finds an approximate solution
def init_graph():
    g = nx.complete_graph(num_nodes)
    for edge in g.edges():
        g[edge[0]][edge[1]]['weight'] = (random.randint(1, 100))
        g[edge[0]][edge[1]]['trail_intensity'] = starting_trail
    return g


g = init_graph()
sol = nx.algorithms.approximation.traveling_salesman.greedy_tsp(g)
sol = sol[:-1]

# Construct a random valid solution
def construct_initial():
    return (random.sample(g.nodes(), len(g.nodes())))


# Strings together nodes to form tuples that have an edge weight.
def construct_path(nodes):
    path = []
    for i in range(len(nodes) - 1):
        move = (nodes[i], nodes[i + 1])
        path.append(move)
    path.append((nodes[-1], nodes[0]))
    return path


# Computes total path weight of list of nodes.
def path_weight(path):
    total = 0
    new_path = construct_path(path)
    for edge in new_path:
        total += g[edge[0]][edge[1]]['weight']
    return total
def mutation(complete_path):
    path_minus_end = complete_path.copy()#[:-1]
    first = random.randint(0, num_nodes-1)
    second = random.randint(0, num_nodes-1)
    path_minus_end[first], path_minus_end[second] = path_minus_end[second], path_minus_end[first]
    return path_minus_end

#Crossesover two solutions while using PMX so that the solution is valid
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
def simulation_genetic(iterations):
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


def update_trail(tabu, pheromones):
    new_path = construct_path(tabu)
    for edge in new_path:
        g[edge[0]][edge[1]]['trail_intensity'] += pheromones


def reset_ants():
    ants = [[0] for i in range(num_ants)]
    return ants


def choose_move(tabu, current):
    possible_moves = []
    for i in range(num_nodes):
        if i not in tabu:
            possible_moves.append(i)
    move_values = []
    for j in possible_moves:
        trail = g[current][j]['trail_intensity']
        visibility = 1 / g[current][j]["weight"]
        value = trail ** alpha + visibility ** beta
        move_values.append(value)
    total = sum(move_values)
    rand_num = random.random() * total
    so_far = move_values[0]
    k = 0
    while rand_num > so_far:
        k += 1
        so_far += move_values[k]
    return possible_moves[k]


# simulates many generations of individuals evolving
def simulation_ants(iterations):
    evolutionary_track = []
    for i in range(iterations):
        print(i)
        ants = reset_ants()
        for j in range(num_nodes - 1):
            for tabu in ants:
                move = choose_move(tabu, tabu[j])
                tabu.append(move)
        for edge in g.edges():
            g[edge[0]][edge[1]]['trail_intensity'] = sigma * g[edge[0]][edge[1]]['trail_intensity']
        for tabu in ants:
            cost = path_weight(tabu)
            pheromones = Q / cost
            update_trail(tabu, pheromones)
            best_current_path, best_current_weight = fittest_individual(ants)
        evolutionary_track.append(best_current_weight)
    best_path, best_weight = fittest_individual(ants)
    return best_path, best_weight, evolutionary_track


# Returns the fittest individual of a generation
def fittest_individual(generation):
    best_weight = 1000000
    best_path = None
    for finalist in generation:
        if path_weight(finalist) < best_weight:
            best_path = finalist
            best_weight = path_weight(finalist)
    return best_path, best_weight


# returns whether a solution is valid
def isValid(solution):
    check = set()
    for node in solution:
        check.add(node)
    if len(check) == 100 and len(solution) == 100:
        return True
    else:
        return False


def main():

    best_path_ants, best_weight_ants, evol_ants = simulation_ants(iterations)
    best_path_gen, best_weight_gen, evol_gen = simulation_genetic(iterations)
    plt.plot(evol_ants)
    plt.ylabel("Path Length")
    plt.xlabel("Iterations")
    plt.title("Path Length of Fittest Individual Over Time Using Ant Colony")
    plt.savefig("Path Length of Fittest Individual Over Time Using Ant Colony")
    print("Our algorithm ran for " + str(iterations) + " iterations.")
    print("The 3/2 Hamilton approximation path using the Christofides algorithm is: ", sol ," with a path weight of:",path_weight(sol))
    print()
    print("The best solution our genetic algorithm could produce is: ", best_path_ants, "with a path weight of:",
          best_weight_ants)
    print("Is our solution valid?", isValid(best_path_ants))


if __name__ == "__main__":
    main()
