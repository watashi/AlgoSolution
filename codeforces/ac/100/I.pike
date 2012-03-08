int main() {
	constant in = Stdio.stdin;
	float k, x, y;
	k = (float)in->gets() / 180.0 * Math.pi;
	sscanf(in->gets(), "%f%f", x, y);
	write("%.9f %.9f", x * cos(k) - y * sin(k), x * sin(k) + y * cos(k));
	return 0;
}
//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//669446 	Sep 5, 2011 6:01:07 PM 	watashi 	100I - Rotation 	Pike 	Accepted 	130 ms 	6500 KB
