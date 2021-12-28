show(Soln) :- reverse(Soln,Forwards), write('\n'),
              member(Row,[1,2,3,4,5,6,7,8,9]),
              write('\n'),
              member(Col,[1,2,3,4,5,6,7,8,9]),
              nth1(Value,Forwards,[Row,Col]),
              write(Value),write('\t'),
              fail.
solSize(81).

inbounds(X,Y):- X > 0, X<10, Y > 0, Y < 10.


plusorminus1(X,Y) :- plus(X,1,Y).
plusorminus1(X,Y) :- plus(Y,1,X).
adjacent(I,J,X,Y) :- X = I, plusorminus1(Y,J), inbounds(X,Y).  
adjacent(I,J,X,Y) :- Y = J, plusorminus1(X,I), inbounds(X,Y).

complete( Partial, Finished):- length(Partial, Len),
                                solSize(Size),
                                Len<Size,
                                plus(1,Len,NewVal),
                                init(X,Y, NewVal),
                                [[I,J]|_] = Partial,
                                adjacent(I,J,X,Y),
                                append([[X,Y]],Partial,NewPartial),
                                complete(NewPartial, Finished).
complete( Partial, Finished):- 
                            length(Partial, Len),
                            solSize(Size),
                            Len<Size,
                            \+ init(_,_,Len+1),
                            [[I,J]|_] = Partial,
                            adjacent(I,J,X,Y),
                            \+ init(X,Y, _),
                            \+ member([X,Y], Partial),
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
