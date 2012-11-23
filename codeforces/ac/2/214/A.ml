let _ =
  let n = Scanf.scanf " %d" (fun x -> x) in
  let m = Scanf.scanf " %d" (fun x -> x) in
  let ans = ref 0 in
  for i = 0 to 100 do
    for j = 0 to 100 do
      if i * i + j = n && i + j * j = m then ans := !ans + 1
    done
  done;
  print_int !ans
