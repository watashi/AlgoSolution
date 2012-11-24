let ni = fun _ -> Scanf.scanf " %d" (fun x -> x) in
let a = ni () in
let b = ni () in
let d = 2 * ni () in
print_string (if a >= d && b >= d then "First" else "Second");;
