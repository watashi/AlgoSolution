s := File standardInput readLine
m := Map clone
for (i, 1, s size,
	for (j, 0, s size - i,
		t := s slice(j, j + i)
		m atPut(t, m at(t, 0) + 1)
	)
)
b := s
w := 1
m foreach(k, v,
	if (list(v, k size, k) > list(w, b size, b),
		b = k
		w = v
	)
)
b println
