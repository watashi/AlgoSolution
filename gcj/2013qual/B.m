% #!/usr/bin/octave -q
re = dlmread(stdin, '', [0 0 0 0]);
for ri = [1:re]
  rc = dlmread(stdin, '', [0 0 0 1]);
  r = rc(1);
  c = rc(2);
  a = dlmread(stdin, '', [0 0 r-1 c-1]);
  x = max(a, [], 2);
  y = max(a, [], 1);
  f = @(i, j) min(x(i), y(j));
  b = f(repmat([1:r]', 1, c), repmat([1:c], r, 1));
  fprintf(stdout, 'Case #%d: %s\n', ri, ifelse(isequal(a, b), "YES", "NO"));
end
