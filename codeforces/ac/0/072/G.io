n := File standardInput readLine asNumber
a := 1
b := 1
for (i, 1, n,
	c := a + b
	a := b
	b := c
)
a println
