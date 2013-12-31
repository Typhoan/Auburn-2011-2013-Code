female(mary).
female(cindy).
female(mindy).
male(jim).

parent(mary,cindy).
parent(mary,mindy).
parent(jim,cindy).
parent(jim,mindy).

sister(X,Y):-
	female(X),
	parent(Z,Y),
	parent(Z,X),
	parent(W,Y),
	parent(W,X),
	female(W),
	male(Z),
	female(X),
        not(X = Y).

