program zjppc5a(input, output);

function is7(x: integer): boolean;
begin
	is7 := false;
	if x mod 7 = 0 then
		is7 := true
	else
		while x <> 0 do
		begin
			if x mod 10 = 7 then
			begin
				is7 := true;
				break;
			end
			else
				x := x div 10;
		end;
end;

var
	a: array[1..1000] of integer;
	p: array[1..108] of integer;
	re, i, n: integer;
begin
	n := 0;
	for i := 1 to 100 do
		p[i] := -1;
	for i := 1 to 1000 do
		if is7(i) then
		begin
			inc(n);
			if p[n] = -1 then
				p[n] := i + 1 - n;
		end
		else
			n := 0;
	readln(re);
	for i := 1 to re do
	begin
		readln(n);
		writeln(p[n]);
	end;
end.

{
Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
2920291 2008-05-18 01:01:16 Accepted 2965 GPC 00:00.00 2768K Re:ReJudge
}

{ 2012-09-07 03:40:06 | Accepted | 2965 | FPC | 0 | 36 | watashi | Source }
