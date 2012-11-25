let rec gcd a b =
  if b = 0 then a else gcd b (a mod b)
;;

let _ =
  let ni () = Scanf.scanf " %d" (fun x -> x) in
  let re = ni () in
  for ri = 1 to re do
    let n = ni () in
    let n' = float_of_int n in
    Printf.printf "%.0f\n" (1.0 +. match (n + 1) mod 4 with
      | 0 -> n'
      | 2 -> 2.0 *. n'
      | _ -> 4.0 *. n'
    )
  done
;;
