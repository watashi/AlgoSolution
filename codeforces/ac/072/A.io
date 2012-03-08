n := File standardInput readLine asNumber
p := list
// dp := list
for (i, 0, n,
	p append(true)
//	dp append(false)
)
p atPut(1, true)
// dp atPut(0, true)
// dp atPut(1, 1)
for (i, 2, n,
	if (p at(i),
		for (j, i + i, n, i, p atPut(j, false))
//		for (j, n, i, -1, if (dp at(j - i), dp atPut(j, i)))
	)
)
/*
if (dp at(n) == false,
	0 println,
	ans := list
	m := n
	while (m > 0,
		ans append(dp at(m))
		m = m - dp at(m)
	)
	ans = ans join("+")
	ans = ans .. "=" .. n
	ans println
)
*/
m := n
ans := list
while (m > 0,
	for (i, m, 0, -1,
		if (p at(i),
			ans append(i)
			m := m - i
			break
		)
	)
)
ans = ans join("+")
ans = ans .. "=" .. n
ans println
