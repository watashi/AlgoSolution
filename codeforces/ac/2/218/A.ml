let _ =
  let n = Scanf.scanf " %d" (fun x -> x) in
  let k = ref (Scanf.scanf " %d" (fun x -> x)) in
  let a = Array.create (2*n+1) 0 in
  for i = 0 to 2 * n do
    a.(i) <- Scanf.scanf " %d" (fun x -> x)
  done;
  for i = 0 to n - 1 do
    let j = 2*i+1 in
    if !k > 0 && a.(j) > a.(j-1) + 1 && a.(j) > a.(j+1) + 1 then begin
      k := !k - 1;
      a.(j) <- a.(j) - 1
    end
  done;
  print_string (String.concat " " (List.map string_of_int (Array.to_list a)))
;;
