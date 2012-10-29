int main() {
	int s = 0;
	for (int i = 0; i < 2; ++i) {
		s += (int)Stdio.stdin->gets();
	}
	write((string)s);
	return 0;
}
//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//669394 	Sep 5, 2011 5:37:21 PM 	watashi 	100C - A+B 	Pike 	Accepted 	130 ms 	6500 KB 
