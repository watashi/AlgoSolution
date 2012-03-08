n := File standardInput readLine asNumber
if (n % 2 == 0 and n % 4 != 0,
	"yes" println,
	"no" println
)
