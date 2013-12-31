union([],[],[]).
union([],X,X).
union(Z,[],Z).
union([X|Xs], Y, R):-
	member(X,Y), !, union(Xs, Y, R).
union([X|Xs],Y, [X|R]):-
	union(Xs,Y,R).
