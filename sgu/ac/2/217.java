// SGU217. Two Cylinders

/*
217. Two Cylinders
time limit per test: 2 sec.
memory limit per test: 65536 KB
input: standard
output: standard



In this problem your task is very simple.

Consider two infinite cylinders in three-dimensional space, of radii R1 and R2 respectively, located in such a way that their axes intersect and are perpendicular.

Your task is to find the volume of their intersection.

Input

Input file contains two real numbers R1 and R2 (1 ≤ R1, R2 ≤ 100);

Output

Output the volume of the intersection of the cylinders. Your answer must be accurate up to 10-4.

Sample test(s)

Input

1 1

Output

5.3333
[submit]
[forum]
Author:	Andrew Stankevich
Resource:	Petrozavodsk Summer Trainings 2003
Date:	2003-08-30 
*/
import java.util.*;

public class Solution {
	static final long N = 1L << 20;	// 2^15~2^18 -> WA12

	static double solve(double a, double b) {
		double aa = a * a, bb = b * b;
		double s = a / N, ss = s * s, xx;
		double sum = Math.sqrt(aa * bb);
		for (long i = 2; i < N; i += 2) {
			xx = i * i * ss;
			sum += 2 * Math.sqrt((aa - xx) * (bb - xx));
		}
		for (long i = 1; i < N; i += 2) {
			xx = i * i * ss;
			sum += 4 * Math.sqrt((aa - xx) * (bb - xx));
		}
		return 8 * (sum * s / 3);
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		double r1 = in.nextDouble();
		double r2 = in.nextDouble();
		System.out.println(solve(Math.min(r1, r2), Math.max(r1, r2)));
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//887024	14.09.09 17:15	watashi	217 	.JAVA	Accepted	107 ms	0 kb


