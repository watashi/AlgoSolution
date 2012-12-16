program Spiral;

function min(a, b: int64): int64;
begin
	if a < b then
		min := a
	else
		min := b;
end;

var
	n, m: int64;
begin
	readln(n, m);
	writeln(min(n * 2 - 2, m * 2 - 1));
end.

{
ID	Date	Author	Problem	Language	Judgement result	Test #	Execution time	Memory used
2330765	19:59:11
5 Nov 2008	watashi	1224	Pascal	Accepted
	0.031	114 KB

/*
id => 4678072
date => 03:46:3716 Dec 2012
user => watashi
pname => Spiral
lang => Pascal
status => Accepted
testid =>
time => 0.015
mem => 122 KB
pid => 1224
*/
}
