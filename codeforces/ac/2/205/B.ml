let _ =
  let n = Scanf.scanf " %d" (fun x -> x) in
  let b = ref 0 in
  let s = ref Int64.zero in
  for i = 0 to n - 1 do
    let a = Scanf.scanf " %d" (fun x -> x) in
    if !b > a then s := Int64.add !s (Int64.of_int (!b - a));
    b := a
  done;
  print_string (Int64.to_string !s)
;;
