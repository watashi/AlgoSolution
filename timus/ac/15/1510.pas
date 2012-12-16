{经典问题--Vote}

program Order;

var
	i, t, n, k, c: integer;
begin
	readln(n);
	c := 0;
	for i := 1 to n do
	begin
		readln(t);
		if c = 0 then
			k := t;
		if t = k then
			inc(c)
		else
			dec(c);
	end;
	writeln(k);
end.

{
ID	Date	Author	Problem	Language	Judgement result	Test #	Execution time	Memory used
2331626	05:01:00
6 Nov 2008	watashi	1510	Pascal	Accepted	
	0.203	114 KB


/*
id => 4678356
date => 12:22:1116 Dec 2012
user => watashi
pname => Order
lang => Pascal
status => Accepted
testid => 
time => 0.234
mem => 122 KB
pid => 1510
*/
}
