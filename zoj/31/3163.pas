program F(input, output);
var
	n: integer;
	x: real;
	y: real;
begin
	while not eof(input) do
	begin
		readln(n, x, y);
		writeln(n - 1);
	end
end.
{Run ID  	Submit Time  	Judge Status  	Problem ID  	Language  	Run Time(ms)  	Run Memory(KB)  	User Name
1801107 	2009-03-23 21:08:32 	Accepted 	3163 	FPC 	10 	28 	watashi@Zodiac}

{ 2012-09-07 03:41:01 | Accepted | 3163 | FPC | 10 | 32 | watashi | Source }
