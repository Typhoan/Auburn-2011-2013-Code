#lang racket

(define (Quicksort lst)
 (let ((pivot (getPivot lst)))
   (if (equal? pivot 'done) lst
     (let ((partition (getPartition pivot lst '() '())))
       (append (Quicksort (car partition)) 
               (Quicksort (cadr partition)))))))

(define getPivot (lambda (lst)
  (cond ((null? lst) 'done)
	((null? (cdr lst)) 'done)
        ((<= (car lst) (cadr lst)) (getPivot (cdr lst)))
	(#t (car lst)))))

(define getPartition (lambda (pivot lst part1 part2)
  (if (null? lst) (list part1 part2)
     (if (< (car lst) pivot) (getPartition pivot (cdr lst) (cons (car lst) part1) part2)
	 (getPartition pivot (cdr lst) part1 (cons (car lst) part2))))))
