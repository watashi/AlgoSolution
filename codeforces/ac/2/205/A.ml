let _ =
  let n = Scanf.scanf " %d" (fun x -> x) in
  let a = Array.make n 0 in
  for i = 0 to n - 1 do
    Scanf.scanf " %d" (fun x -> a.(i) <- x)
  done;
  let k = ref 0 in
  let m = ref a.(0) in
  for i = 1 to n - 1 do
    if a.(i) < !m then (m := a.(i); k := i)
    else if a.(i) = !m then k := -1
  done;
  if !k = -1
  then print_string "Still Rozdil"
  else print_int (!k + 1)
;;
