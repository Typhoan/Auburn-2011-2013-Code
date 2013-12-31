#lang racket
(define (Reverse lst)
  (cond
    ((null? lst)null)
    (else(append (Reverse (cdr lst)) (list (car lst))))))
