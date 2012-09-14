program zjppc5j(input, output);

type
	mat = array[1..22, 1..22] of real;

procedure mul(var a, b, c: mat; const n: integer);
var
	i, j, k: integer;
	t: mat;
begin
	for i := 1 to n do
		for j := 1 to n do
		begin
			t[i, j] := 0;
			for k := 1 to n do
                { inc(t[i, j], a[i, k] * b[k, j]); }
                { Error: Ordinal expression expected }
                t[i, j] := t[i, j] + a[i, k] * b[k, j];
		end;
	for i := 1 to n do
		for j := 1 to n do
			c[i, j] := t[i, j];
end;

var
	ri, re, i, j, k, n, m: integer;
	a, b: mat;
	r, v: array[1..22] of real;
begin
	readln(re);
	for ri := 1 to re do
	begin
		readln(n);
		for i := 1 to n do
			read(v[i]);
		{readln;} {Runtime Error SIGSEGV}
		for i := 1 to n do
		begin
			for j := 1 to n do
			begin
				a[i, j] := 0;
				b[i, j] := 0;
			end;
			a[i, i] := 1;
		end;
		for i := 1 to n do
		begin
			read(m);
			for j := 1 to m do
			begin
				read(k);
				b[k, i] := 1.0 / m;
			end;
			if m = 0 then
				b[i, i] := 1;
			readln;
		end;

		readln(m);
		while m <> 0 do
		begin
			if m mod 2 = 1 then
				mul(a, b, a, n);
			mul(b, b, b, n);
			m := m div 2;
		end;

		for i := 1 to n do
		begin
			r[i] := 0;
			for j := 1 to n do
                { inc(r[i], a[i, j] * v[j]); }
                { Error: Ordinal expression expected }
                r[i] := r[i] + a[i, j] * v[j];
			write(r[i]:0:2);
			if i = n then
				writeln
			else
				write(' ');
		end;
	end;
end.

{
Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
2920317 2008-05-18 01:12:47 Accepted 2974 GPC 00:00.03 2772K Re:ReJudge
}

{ 2012-09-07 03:45:13 | Compilation Error | 2974 | FPC | 0 | 0 | watashi | Source }

{ 2012-09-07 03:49:40 | Accepted | 2974 | FPC | 0 | 40 | watashi | Source }
