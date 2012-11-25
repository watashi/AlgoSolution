let n, k = Scanf.scanf "%d %d" (fun n k -> n, k) in
print_int (max 0 (3 * n - k));;
