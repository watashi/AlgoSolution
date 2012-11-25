let ni () = Scanf.scanf " %d" (fun x -> x) in
let nf () = float_of_int (ni ()) in
let n = ni () in
let t1 = nf () in
let t2 = nf () in
let k = 1.0 -. nf () /. 100.0 in
let f a b = a *. t1 *. k +. b *. t2 in
let a = Array.init n (fun i ->
  let a, b = nf (), nf () in
  (-1. *. max (f a b) (f b a), i + 1)
) in
Array.sort compare a;
Array.iter (fun (e, i) ->
  Printf.printf "%d %.2f\n" i ~-.e
) a;;
