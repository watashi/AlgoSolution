n := File standardInput readLine asNumber
a := 0
b := 0
c := n
while (c > 0,
	a := a + 1
	d := c % 10
	c := (c - d) / 10
	if (n % d == 0, b := b + 1)
)
if (b == 0,
	"upset" println,
	if (b == a,
		"happier" println,
		"happy" println
	)
)
