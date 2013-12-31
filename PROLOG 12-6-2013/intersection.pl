intersection([],_,[]).
intersection([],[],[]).
intersection([X|_], L2, [X|_]):-
	member(X,L2), !, fail.
intersection([_|Xs], L2, R):-
	!,intersection(Xs,L2,R).
