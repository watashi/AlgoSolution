program zjppc5g(input, output);

function str2int(const s:string): integer;
begin
	if s = 'million' then str2int := 1000000
	else if s = 'thousand' then str2int := 1000
	else if s = 'hundred' then str2int := 100
	else if s = 'zero' then str2int := 0
	else if s = 'one' then str2int := 1
	else if s = 'two' then str2int := 2
	else if s = 'three' then str2int := 3
	else if s = 'four' then str2int := 4
	else if s = 'five' then str2int := 5
	else if s = 'six' then str2int := 6
	else if s = 'seven' then str2int := 7
	else if s = 'eight' then str2int := 8
	else if s = 'nine' then str2int := 9
	else if s = 'ten' then str2int := 10
	else if s = 'eleven' then str2int := 11
	else if s = 'twelve' then str2int := 12
	else if s = 'thirteen' then str2int := 13
	else if s = 'fourteen' then str2int := 14
	else if s = 'fifteen' then str2int := 15
	else if s = 'sixteen' then str2int := 16
	else if s = 'seventeen' then str2int := 17
	else if s = 'eighteen' then str2int := 18
	else if s = 'nineteen' then str2int := 19
	else if s = 'twenty' then str2int := 20
	else if s = 'thirty' then str2int := 30
	else if s = 'forty' then str2int := 40
	else if s = 'fifty' then str2int := 50
	else if s = 'sixty' then str2int := 60
	else if s = 'seventy' then str2int := 70
	else if s = 'eighty' then str2int := 80
	else if s = 'ninety' then str2int := 90
	else str2int := -1;
end;

var
	ri, re, p, cur, tmp, ans: integer;
	buf: string[255];
begin
	readln(re);
	for ri := 1 to re do
	begin
		ans := 0;
		tmp := 0;
		readln(buf);
		repeat
			p := pos(' ', buf);
			{writeln('-', p, copy(buf, 1, p - 1));}
			if p = 0 then
				cur := str2int(buf)
			else
				cur := str2int(copy(buf, 1, p - 1));
			{writeln(cur, buf);}
			if (cur = 1000000) or (cur = 1000) then
			begin
				inc(ans, tmp * cur);
				tmp := 0;
			end
			else if cur = 100 then
				tmp := tmp * 100
			else if cur >= 0 then
				tmp := tmp + cur;
			if p <> 0 then
				delete(buf, 1, p);
		until p = 0;
		ans := ans + tmp;
		writeln(ans);
	end;
end.

{2920308 2008-05-18 01:07:50 Accepted 2971 GPC 00:00.03 2768K Re:ReJudge }

{ 2012-09-07 03:40:30 | Accepted | 2971 | FPC | 10 | 96 | watashi | Source }
