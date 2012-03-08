x := File standardInput readLine asString asMutable
y := ""
if (x slice(0, 1) == "-",
	x = x slice(1)
	y = y .. "-"
)
x = x strip("0")
x = x reverse
y = y .. x
y println

/* WA if exSlice, but work on my laptop */
