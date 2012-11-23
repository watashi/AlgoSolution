let gao a =
  let s = ref 0 in
  for i = 0 to Array.length a - 1 do
    s := !s + i * a.(i)
  done;
  if a.(0) > 0 && !s mod 3 = 0 then begin
    if !s = 0 then a.(0) <- 1;
    for i = Array.length a - 1 downto 0 do
      for j = 0 to a.(i) - 1 do
        print_int i
      done
    done;
    exit 0
  end
;;

let _ =
  let n = Scanf.scanf " %d" (fun x -> x) in
  let a = Array.create 10 0 in
  for i = 1 to n do
    let d = Scanf.scanf " %d" (fun x -> x) in
    a.(d) <- a.(d) + 1
  done;

  gao a;
  for i = 1 to 9 do
    if a.(i) > 0 then begin
      a.(i) <- a.(i) - 1;
      gao a;
      a.(i) <- a.(i) + 1
    end
  done;
  for i = 1 to 9 do
    if a.(i) > 0 then begin
      a.(i) <- a.(i) - 1;
      for j = 1 to i do
        if a.(j) > 0 then begin
          a.(j) <- a.(j) - 1;
          gao a;
          a.(j) <- a.(j) + 1
        end
      done;
      a.(i) <- a.(i) + 1
    end
  done;

  print_int (-1)
;;
