program zjppc5h(input, output);

const
	inf = 123456;
var
	ri, re, i, j, n, m, ans: integer;
	t1, t2, t3, f1, f2: integer;
	dp: array[0..128, 0..128] of integer;
begin
	readln(re);
	for ri := 1 to re do
	begin
		readln(n, m);
		for i := 0 to n do
			for j := 0 to m do
				dp[i, j] := inf;
		dp[0, m] := 0;
		for i := 0 to n - 1 do
		begin
			readln(t1, t2, t3, f1, f2);
			for j := 0 to m do
			begin
				if (j >= f1) and (dp[i, j] + t1 < dp[i + 1, j - f1]) then
					dp[i + 1, j - f1] := dp[i, j] + t1;
				if dp[i, j] + t2 < dp[i + 1, j] then
					dp[i + 1, j] := dp[i, j] + t2;
				if (j + f2 >= m) and (dp[i, j] + t3 < dp[i + 1, m]) then
					dp[i + 1, m] := dp[i, j] + t3;
				if (j + f2 < m) and (dp[i, j] + t3 < dp[i + 1, j + f2]) then
					dp[i + 1, j + f2] := dp[i, j] + t3;
			end;
		end;
		ans := inf;
		for i := 0 to m do
			if dp[n, i] < ans then
				ans := dp[n, i];
		writeln(ans);
	end;
end.

{
Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
2920310 2008-05-18 01:08:37 Accepted 2972 GPC 00:00.00 2824K Re:ReJudge
}

{ 2012-09-07 03:40:36 | Accepted | 2972 | FPC | 0 | 96 | watashi | Source }
