dx := list(0, 1, 0, -1)
dy := list(1, 0, -1, 0)

s := File standardInput readLine
l := s split
n := l at(0) asNumber
m := l at(1) asNumber
a := list
for (i, 0, n + 1,
	b := list
	for (j, 0, m + 1, b append(false))
	a append(b)
)
for (i, 1, n, for (j, 1, m, a at(i) atPut(j, true)))

File standardInput readLine split slice(1) foreach(i,
	i = i asNumber
	for (j, 1, m, a at(i) atPut(j, false)))
File standardInput readLine split slice(1) foreach(j,
	j = j asNumber
	for (i, 1, n, a at(i) atPut(j, false)))

ans := 0
for (i, 1, n,
	for (j, 1, m,
		if (a at(i) at(j),
			a at(i) atPut(j, false)
			q := list(list(i, j))
			while (q size > 0,
				l := q removeLast
				x := l at(0) asNumber
				y := l at(1) asNumber
				for (k, 0, 3,
					xx := x + dx at(k)
					yy := y + dy at(k)
					if (a at(xx) at(yy),
						a at(xx) atPut(yy, false)
						q append(list(xx, yy))
					)
				)
			)
			ans = ans + 1
		)
	)
)
ans println
