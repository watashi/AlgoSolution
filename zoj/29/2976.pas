program zjppc5l(input, output);

function calc(x, y, z, w: integer): real;
var
	r: real;
begin
	r := x * x + y * y + z * z;
	calc := w * z / r / sqrt(r);
end;

var
	x, y, z, w: array[1..100] of integer;
	ri, re, i, j, k, n: integer;
	tmp, ans: real;
begin
	readln(re);
	for ri := 1 to re do
	begin
		readln(n);
		for k := 1 to n do
			readln(x[k], y[k], z[k], w[k]);
		ans := 0;
		for i := -100 to 100 do
			for j := -100 to 100 do
			begin
				tmp := 0;
				for k := 1 to n do
					tmp := tmp + calc(x[k] - i, y[k] - j, z[k], w[k]);
				if tmp > ans then
					ans := tmp;
			end;
		writeln(ans:0:2);
	end;
end.

{
Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
2920330 2008-05-18 01:22:30 Accepted 2976 GPC 00:00.68 2764K Re:ReJudge
}

{ 2012-09-07 03:40:55 | Accepted | 2976 | FPC | 210 | 32 | watashi | Source }
