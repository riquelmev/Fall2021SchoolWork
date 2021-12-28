split([], [], []).
split([A], [A], []).
split([A, B | T], [A | L1], [B | L2]) :-
    split(T, L1, L2).