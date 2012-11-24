let _ =
  let n = Scanf.scanf " %d" (fun x -> x) in
  let m = Scanf.scanf " %d" (fun x -> x) in
  let a = Array.make m 0 in
  let b = Array.make m 0 in
  for i = 0 to m - 1 do
    let t = Scanf.scanf " %d" (fun x -> x) in
    a.(i) <- t;
    b.(i) <- t
  done;

  let x = ref 0 in
  let r = ref n in
  Array.sort (fun x y -> x - y) a;
  for i = 0 to m - 1 do
    let c = min a.(i) !r in
    x := !x + c * a.(i) - c * (c - 1) / 2;
    r := !r - c
  done;

  let y = ref 0 in
  let r = ref n in
  Array.sort (fun x y -> y - x) b;
  while !r > 0 do
    let c = b.(0) in
    for i = 0 to m - 1 do
      if !r > 0 && b.(i) = c then begin
        y := !y + c;
        r := !r - 1;
        b.(i) <- b.(i) - 1
      end
    done
  done;

  print_int !y;
  print_char ' ';
  print_int !x;
  print_char '\n'
;;
