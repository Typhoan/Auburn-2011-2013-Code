#lang racket
(define (Power n k)
  (cond
    ((zero? k) 1)
    ((eq? k 1) n)
    ((eq? n 1) 1)
    (else (calc n k 1))))
  

(define (calc i j l)
  (cond
    ((zero? j) l)
    (else (calc i (- j 1) (* l i)))))