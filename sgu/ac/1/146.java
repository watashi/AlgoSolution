// SGU146. The Runner
/*
146. The Runner
time limit per test: 0.50 sec.
memory limit per test: 4096 KB
input: standard input
output: standard output



The runner moves along the ring road with length L. His way consists of N intervals. First he ran T1 minutes with speed V1, then T2 minutes with speed V2 and so on till the N-th interval, where he ran TN minutes with speed VN. Your task is to find the distance from start to finish along the ring road. The distance along the ring road is the length of the shortest way all points of which belongs to the ring road.

Input
Real number L (1<=L<=1000, with 4 signs after decimal point) and natural number N (N<=20000) are written in the first line. Each of the following N lines contains two integer numbers Ti and Vi (1<=Ti<=10^7, 1<=Vi<=10^6).

Output
Write the only one real number with 4 digits after decimal points: the distance from start to finish.

Sample test(s)

Input

2 1
1 3

Output

1.0000
[submit]
[forum]
Author:	Michael R. Mirzayanov
Resource:	Summer School Team Contest, 2002
Date:	August, 2002
*/

import java.io.*;

public class Solution {
	static int nextInt(StreamTokenizer in) throws IOException {
		in.nextToken();
		return (int)(in.nval + .5);
	}

	public static void main(String[] args) throws IOException {
		StreamTokenizer in = new StreamTokenizer(
				new BufferedReader(new InputStreamReader(System.in)));
		in.nextToken();
		double dbl = in.nval;
		long l = (long)(dbl * 10000 + .5);
		int n = nextInt(in);
		long s = 0;
		for (int i = 0; i < n; ++i) {
			s += (long)nextInt(in) * (long)nextInt(in) * 10000L;
			s %= l;
		}
		s = Math.min(s, l - s);
		System.out.printf("%d.%04d\n", s / 10000, s % 10000);
	}
}

//Scanner => TLE14
//... => WA
//... => PE

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//873668	04.08.09 13:48	watashi	146 	.JAVA	Accepted	54 ms	1458 kb

