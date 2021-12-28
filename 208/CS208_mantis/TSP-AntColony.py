# Initializes and solves the TSP with genetic algorithms
# Created by Vicente Riquelme and Eric Wright
import networkx as nx
import matplotlib

matplotlib.use('Agg')
import matplotlib.pyplot as plt
import random

random.seed(10)
# Constants
alpha = 2
beta = 5
sigma = 0.5
starting_trail = 1
Q = 100
iterations = 200
num_ants = 10
num_nodes = 100

# Creates graph and finds an approximate solution
def init_graph():
    g = nx.complete_graph(num_nodes)
    for edge in g.edges():
        g[edge[0]][edge[1]]['weight'] = (random.randint(1,100))
        g[edge[0]][edge[1]]['trail_intensity'] = starting_trail
    return g
#sol = nx.algorithms.approximation.traveling_salesman.christofides(g)
#sol = sol[:-1]
g = init_graph()
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
        visibility = 1/g[current][j]["weight"]
        value = trail**alpha + visibility**beta
        move_values.append(value)
    total = sum(move_values)
    rand_num = random.random()*total
    so_far = move_values[0]
    k = 0
    while rand_num>so_far:
        k += 1
        so_far += move_values[k]
    return possible_moves[k]

#simulates many generations of individuals evolving
def simulation(iterations):
    evolutionary_track = []
    for i in range(iterations):
        print(i)
        ants = reset_ants()
        for j in range(num_nodes-1):
            for tabu in ants:
                move = choose_move(tabu, tabu[j])
                tabu.append(move)
        for edge in g.edges():
            g[edge[0]][edge[1]]['trail_intensity'] = sigma * g[edge[0]][edge[1]]['trail_intensity']
        for tabu in ants:
            cost = path_weight(tabu)
            pheromones = Q/cost
            update_trail(tabu, pheromones)
            best_current_path, best_current_weight = fittest_individual(ants)
        evolutionary_track.append(best_current_weight)
    best_path, best_weight = fittest_individual(ants)
    return best_path, best_weight, evolutionary_track
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
    # Constants
    
    best_path, best_weight, evol = simulation(iterations)
    plt.plot(evol)
    plt.ylabel("Path Length")
    plt.xlabel("Iterations")
    plt.title("Path Length of Fittest Individual Over Time Using Ant Colony")
    plt.savefig("Path Length of Fittest Individual Over Time Using Ant Colony")
    print("Our algorithm ran for " + str(iterations) + " iterations.")
    # print("The 3/2 Hamilton approximation path using the Christofides algorithm is: ", sol ," with a path weight of:",path_weight(sol))
    # print()
    print("The best solution our genetic algorithm could produce is: ", best_path, "with a path weight of:", best_weight)
    print("Is our solution valid?" ,isValid(best_path))

if __name__ == "__main__":
    main()
