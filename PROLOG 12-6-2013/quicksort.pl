quicksort([],[]).
quicksort([X|Xs], Sorted):-
	partition(X,Xs,Left,Right),
	quicksort(Left, Lsorted),
	quicksort(Right, Rsorted),
	append(Lsorted, [X|Rsorted], Sorted).

partition(_,[],[],[]).
partition(Pivot,[X|Xs], [X|L], R):-
	isLess(X,Pivot),!,
	partition(Pivot,Xs,L,R).

partition(Pivot,[X|Xs],L,[X|R]):-
	partition(Pivot,Xs,L,R).


isLess(X,Y):-
	Z =..[<,X,Y],
	call(Z).
