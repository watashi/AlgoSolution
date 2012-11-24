let rec gcd a b =
  if b == 0 then a else gcd b (a mod b)
;;

let next_int: unit -> int = fun _ ->
  Scanf.scanf " %d" (fun x -> x)
;;

let next_polynomial n =
  let ret = next_int () in
  for i = 1 to n do
    next_int ()
  done;
  ret
;;

let rec print_gcd a b =
  let g = gcd (abs a) (abs b) in
  if b < 0
  then print_gcd (-a) (-b)
  else Printf.printf "%d/%d" (a / g) (b / g)
;;

let _ =
  let n = next_int () in
  let m = next_int () in
  let a = next_polynomial n in
  let b = next_polynomial m in
  if n < m then print_string "0/1"
  else if n = m then print_gcd a b
  else print_string ((if a * b > 0 then "" else "-") ^ "Infinity")
;;
