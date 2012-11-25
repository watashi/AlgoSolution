let a = read_line () in
let b = read_line () in
let x, y = ref [], ref [] in
let na = String.length a in
let nb = String.length b in
for i = 0 to min na nb - 1 do
  if a.[i] <> b.[i] then begin
    x := a.[i] :: !x;
    y := b.[i] :: !y
  end
done;
let m = List.length !x in
let sort = List.sort (fun a b -> Char.code a - Char.code b) in
print_endline (if na = nb && m = 2 && sort !x = sort !y
  then "YES" else "NO")
