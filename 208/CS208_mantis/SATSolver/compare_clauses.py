'''Checks to see if the clauses produced by a student's code are the same as those produced
   by the solution code. Requires the addition of the following lines to the end of the student code:
   
        with open("clauses.json", "w") as file:
            file.write(str(clauses))
            
   This writes the student's clauses to a json file to make checking easier. You'll also have to 
   create a file called clauses.json if it doesn't already exist.'''

import json
import SATSolver

def main():
    with open("soln_clauses.json") as file1, open("clauses.json") as file2:
        soln = file1.read()
        sub = file2.read()
    orig_soln_clauses = json.loads(soln)
    orig_clauses = json.loads(sub)
    soln_clauses = []
    clauses = []
    for i in range(len(orig_soln_clauses)):
        soln_clauses.append(set(orig_soln_clauses[i]))
    for i in range(len(orig_clauses)):
        clauses.append(set(orig_clauses[i]))
    same_clauses = True
    for clause in soln_clauses:
        if clause not in clauses:
            same_clauses = False
    for clause in clauses:
        if clause not in soln_clauses:
            same_clauses = False
    print(f"Clauses identical: {same_clauses}")
    if not same_clauses:
        soln_not_sub = []
        sub_not_soln = []
        for clause in soln_clauses:
            if clause not in clauses:
                soln_not_sub.append(clause)
        for clause in clauses:
            if clause not in soln_clauses:
                sub_not_soln.append(clause)
        print(f"Clauses not in submission: {len(soln_not_sub)}")
        print(f"Extra clauses in submission: {len(sub_not_soln)}")
        entailed = True
        for clause in sub_not_soln:
            for literal in clause:
                if not SATSolver.testLiteral(literal, orig_soln_clauses):
                    entailed = False
                    break
            if not entailed:
                break
        print(f'Extra clauses entailed by solution KB: {entailed}')
        entailed = True
        for clause in soln_not_sub:
            for literal in clause:
                if not SATSolver.testLiteral(literal, orig_clauses):
                    entailed = False
                    break
            if not entailed:
                break
        print(f"Missing clauses entailed by student KB: {entailed}")

if __name__ == '__main__':
    main()
