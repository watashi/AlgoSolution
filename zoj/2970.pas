program zjppc5f(input, output);

function min(const n: integer; const a: array of integer): integer;
var
	i, ret: integer;
begin
	ret := a[1];
	for i := 2 to n do
	begin
		if a[i] < ret then
			ret := a[i];
	end;
	min := ret;
end;

function max(const n: integer; const a: array of integer): integer;
var
	i, ret: integer;
begin
	ret := a[1];
	for i := 2 to n do
	begin
		if a[i] > ret then
			ret := a[i];
	end;
	max := ret;
end;

var
	a: array[0..10000] of integer;
	ri, re, i, n: integer;
	buf: string[10];
begin
	readln(re);
	for ri := 1 to re do
	begin
		readln(buf);
		readln(n);
		for i := 1 to n do
			read(a[i]);
		readln;
		if buf = 'Faster' then
			writeln(min(n, a))
		else
			writeln(max(n, a));
	end;
end.

{
Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
2920300 2008-05-18 01:05:33 Accepted 2970 GPC 00:00.00 2800K Re:ReJudge
}

{ 2012-09-07 03:40:24 | Accepted | 2970 | FPC | 0 | 100 | watashi | Source }
