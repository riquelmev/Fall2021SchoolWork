from pycryptosat import Solver
from SATSolver import *

clauses = [[-1, 3],[-2,-3],[2, 3],[-1,2, -3],[1, 3]]
print("Knowledge Base is satisfiable:", testKb(clauses))
names = ["Amy", "Bob", "Cal"]
for i in range(1,4):
    name = names[i-1]
    print('Is '+ name + ' a truth-teller?', end=' ')
    result = testLiteral(i,clauses)
    if result==True:
        print('Yes.')
    elif result==False:
        print('No.')
    else:
        print('Unknown.')

