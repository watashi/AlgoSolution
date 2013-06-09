let _ =
  let fin = open_in "positive.in" in
  let fout = open_out "positive.out" in
  let n = int_of_string (input_line fin) in
  let a = ref [] in
  for i = 1 to n do
    let x = Scanf.fscanf fin " %d" (fun x -> x) in
    a := x :: !a
  done;
  let s = List.fold_left (fun x y -> x + y) 0 !a in
  Printf.fprintf fout "%d\n" (max 0 s)
;;
