program A;

type
  board = array[1..4] of string;

const
  dx: array[1..4] of integer = (0, 1, 1, 1);
  dy: array[1..4] of integer = (1, 0, 1, -1);

function ok(a: board; x, y: integer; z: char): boolean;
var
  i, j, tx, ty: integer;
begin
  ok := false;
  for i := 1 to 4 do
  begin
    ok := true;
    for j := 0 to 3 do
    begin
      tx := x + j * dx[i];
      ty := y + j * dy[i];
      if (tx < 1) or (tx > 4) or (ty < 1) or (ty > 4) or
          ((a[tx][ty] <> 'T') and (a[tx][ty] <> z)) then
      begin
        ok := false;
        break
      end;
    end;
    if ok then exit;
  end;
end;

function gao(a: board): string;
var
  x, y: integer;
  draw: boolean;
begin
  draw := true;
  for x := 1 to 4 do
    for y := 1 to 4 do
    begin
      if a[x][y] = '.' then draw := false;
      if ok(a, x, y, 'O') then
      begin
        gao := 'O won';
        exit
      end
      else if ok(a, x, y, 'X') then
      begin
        gao := 'X won';
        exit
      end;
    end;
  if draw then
    gao := 'Draw'
  else
    gao := 'Game has not completed';
end;

var
  s: board;
  ri, re, i: integer;

begin
  readln(re);
  for ri := 1 to re do
  begin
    for i := 1 to 4 do readln(s[i]);
    readln();
    writeln('Case #', ri, ': ', gao(s));
  end;
end.
