concat := method(x, y,
	return x .. y
)

reverse := method(x,
	// 'reverse' cannot be called on an immutable Sequence
	return x asMutable reverse
)

substr := method(x, a, b, c,
	if (c == nil, c = 1)
	y := "" asMutable
	for (i, a - 1, b - 1, c, y append(x at(i)))
	return y
)

gao := method(x,
	f := false
	y := "" asMutable
	x foreach(b,
		b = b asCharacter
		if (b == "\"", f = f not)
		if (f, y append(b at(0)), y append(b asLowercase at(0)))
	)
	return y
)

s := File standardInput readLine
s = gao(s)
s = "\"" .. doString(s) .. "\""
s println
