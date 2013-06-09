var
  n, i, x: integer;

begin
  {$IFNDEF __WATASHI__}
  assign(input, 'positive.in');
  assign(output, 'positive.out');
  {$ENDIF}
  readln(n);
  for i := 1 to n do begin
    read(x);
    if x < 0 then dec(n, 2);
  end;
  if n < 0 then n := 0;
  writeln(n);
end.
