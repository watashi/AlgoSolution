(define (gao s n)
  (* n (+ s s 1 (* 2 (- n 1)))))

(define (solve s t)
  (define (upper-bound l r)
    (let ((m (quotient (+ l r) 2)))
      (cond
        ((= l r) m)
        ((> (gao s m) t) (upper-bound l m))
        (else (upper-bound (+ m 1) r)))))
  (- (upper-bound 1 t) 1))

(define (main)
  (let ((re (read)))
    (do ((ri 1 (+ ri 1)))
      ((> ri re))
      (let* ((s (read)) (t (read)))
        (format #t "Case #~a: ~a~%" ri (solve s t))))))

(main)

