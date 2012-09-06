program zjppc5e(input, output);

var
	ri, re, i, n, c: integer;
begin
	readln(re);
	for ri := 1 to re do
	begin
		readln(n);
		if n = 0 then
		begin
			readln(c);
			writeln(0);
		end
		else
		begin
			for i := n downto 1 do
			begin
				read(c);
				write(c * i);
				if i = 1 then
					writeln
				else
					write(' ');
			end;
			readln(c);
		end;
	end;
end.

{
Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
2920297 2008-05-18 01:04:43 Accepted 2969 GPC 00:00.54 2764K Re:ReJudge
}

{ 2012-09-07 03:40:18 | Accepted | 2969 | FPC | 40 | 32 | watashi | Source }
