partition([], _, [],[]).

partition([X | T], V, A, B) :- X =:= V, partition(T,V,A,B).

partition([X | T],V,[X|A],B) :- X < V,
                            partition(T,V,A,B).

partition([X | T],V, A, [X | B]) :- X > V,
                            partition(T,V,A,B).

median(L,M) :- member(M,L), partition(L,M,A,B),length(A,X), length(B,X), !.