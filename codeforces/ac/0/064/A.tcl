proc fact n {
	expr {$n == 0 ? 1 : $n * [fact [incr n -1]]}
}

gets stdin line
puts stdout [fact $line]
