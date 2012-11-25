let rec gao n a b = match a, b with
  | [], _ | _, [] -> "NO"
  | (x::xs), (y::ys) ->
      if x + y = n then "YES"
      else if x + y > n then gao n a ys
      else gao n xs b
;;

let triangular n =
  if n mod 2 = 0
  then n / 2 * (n + 1)
  else (n + 1) / 2 * n
;;

let a = Array.init 45000 triangular in
let l = List.tl (Array.to_list a) in
let n = Scanf.scanf "%d" (fun x -> x) in
print_endline (gao n l (List.rev l));;

