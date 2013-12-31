findMax([X],X):-!.
findMax([X|T1],X):-
	findMax(T1,Y),X>=Y.
findMax([X|T1],Z):-
	findMax(T1,Z),Z>X.

