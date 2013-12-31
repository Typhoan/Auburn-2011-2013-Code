#lang racket

(define (FindMaxMin lst)
  (define str (list "Min: " " Max: "))
  (printf "~a~a~a~a" (first str)(Min +inf.0 lst)(second str)(Max -inf.0 lst)))

(define (Min mn lst)
  (cond
    ((null? lst) mn)
    (else (if (< (car lst) mn) (Min (car lst) (cdr lst)) (Min mn (cdr lst))))))

(define (Max mx lst)
  (cond
    ((null? lst) mx)
    (else (if (> (car lst) mx) (Max (car lst) (cdr lst)) (Max mx (cdr lst))))))