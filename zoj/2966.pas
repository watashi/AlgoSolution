program zjppc5b(input, output);

var
	mp: array[0..500, 0..500] of integer;
	mark, mind: array[0..500] of integer;
	ri, re, n, m, i, j, k, ans: integer;
begin
	readln(re);
	for ri := 1 to re do
	begin
		readln(n, m);
		for i := 0 to n - 1 do
		begin
			mark[i] := 0;
			mind[i] := 123456;
			for j := 0 to n - 1 do
				mp[i, j] := 123456;
		end;

		while m <> 0 do
		begin
			readln(i, j, k);
			mp[i, j] := k;
			mp[j, i] := k;
			dec(m);
		end;

		ans := 0;
		mind[0] := 0;
		for i := 0 to n - 1 do
		begin
			k := -1;
			for j := 0 to n - 1 do
				if (mark[j] = 0) and ((k = -1) or (mind[j] < mind[k])) then
					k := j;
			mark[k] := 1;
			ans := ans + mind[k];
			for j := 0 to n - 1 do
				if (mark[j] = 0) and (mp[k, j] < mind[j]) then
					mind[j] := mp[k, j];
		end;
		writeln(ans);
	end;
end.

{
Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
2920294 2008-05-18 01:03:56 Accepted 2966 GPC 00:00.06 3748K Re:ReJudge
}

{ 2012-09-07 03:40:12 | Accepted | 2966 | FPC | 30 | 1016 | watashi | Source }
