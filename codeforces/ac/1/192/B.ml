let ni () = Scanf.scanf " %d" (fun x -> x) in
let n = ni () in
let a = Array.init n (fun _ -> ni ()) in
let ans = ref (min a.(0) a.(n - 1)) in
for i = 2 to n - 1 do
  ans := min !ans (max a.(i - 1) a.(i))
done;
print_int !ans;;
