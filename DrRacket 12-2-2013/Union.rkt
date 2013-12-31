#lang racket

(define (Union lst1 lst2)
  (cond
    ((null? lst1) lst2)
    ((null? lst2) lst1)
    (else (cons (car lst1) (Union (cdr lst1) lst2)))))