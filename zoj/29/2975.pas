program zjppc5k(input, output);

var
	ri, re, i, j, k, m, n: integer;
	ans: cardinal;
	c: array[1..5] of cardinal;
	buf: array[1..255] of string[255];
begin
	readln(re);
	for ri := 1 to re do
	begin
		readln(m, n);
		ans := 0;
		for i := 1 to m do
		begin
			readln(buf[i]);
			for j := 1 to i - 1 do
			begin
				for k := 1 to 5 do
					c[k] := 0;
				for k := 1 to n do
					if buf[i][k] = buf[j][k] then
						case buf[j][k] of
							'B': inc(c[1]);
							'J': inc(c[2]);
							'H': inc(c[3]);
							'Y': inc(c[4]);
							'N': inc(c[5]);
						end;
				for k := 1 to 5 do
					ans := ans + c[k] * (c[k] - 1) div 2;
			end;
		end;
		writeln(ans);
	end;
end.

{
Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
2920329 2008-05-18 01:21:44 Accepted 2975 GPC 00:00.40 2832K Re:ReJudge
}

{ 2012-09-07 03:40:49 | Accepted | 2975 | FPC | 170 | 92 | watashi | Source }
