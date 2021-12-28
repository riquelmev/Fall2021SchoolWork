% To run, load it with a puzzle, eg ['numberChain.pro','puzzle.pro'].
% Then run solve(Final). to have Final be polulated with the solution.
% Run solve(Final), show(Final). to view the path
% It is set up to run on 9x9 puzzles, (solSize = 81) so to adjust to a different size edit lines 16,18,57,58.
% Line 16 determines how long a correct solution should be, line 18 determines the number of rows and columns. 
% Line 57 has the row and column hardcoded.
% Works on 1 present and non-1 present cases.


show(Soln) :- reverse(Soln,Forwards), write('\n'),
              member(Row,[1,2,3,4,5,6,7,8,9]),
              write('\n'),
              member(Col,[1,2,3,4,5,6,7,8,9]),
              nth1(Value,Forwards,[Row,Col]),
              write(Value),write('\t'),
              fail.
solSize(81).

inbounds(X):- X > 0, X<10.


plusorminus1(X,Y) :- plus(X,1,Y).
plusorminus1(X,Y) :- plus(Y,1,X).
adjacent(I,J,X,Y) :- X = I, plusorminus1(Y,J), inbounds(Y).  
adjacent(I,J,X,Y) :- Y = J, plusorminus1(X,I), inbounds(X).

complete(Partial, Finished):- [[I,J]|_] = Partial,
                                length(Partial, Len),
                                adjacent(I,J,X,Y),
                                \+ member([X,Y], Partial),
                                init(X,Y, NewVal),
                                plus(1,Len,NewVal),
                                append([[X,Y]],Partial,NewPartial),
                                complete(NewPartial, Finished).
complete(Partial, Finished):- 
                           [[I,J]|_] = Partial,
                                length(Partial, Len),
                                adjacent(I,J,X,Y),
                                \+ member([X,Y], Partial),
                                \+ init(X,Y, _),
                                plus(1,Len,NewVal),
                                \+ init(_,_, NewVal),
                                append([[X,Y]],Partial,NewPartial),
                                complete(NewPartial, Finished).

complete(Partial, Finished):-
length(Partial, Len),
solSize(Len),
Finished = Partial.

solve(Final):- 
init(X,Y,1),
complete([[X,Y]], Final), !.

solve(Final):- 
\+ init(_,_,1),
member(X,[1,2,3,4,5,6,7,8,9]),
member(Y,[1,2,3,4,5,6,7,8,9]),
\+ init(X,Y, _),
complete([[X,Y]], Final), !.
