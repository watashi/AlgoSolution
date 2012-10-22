// SGU188. Factory guard
/*
188. Factory guard
time limit per test: 0.50 sec.
memory limit per test: 4096 KB
input: standard input
output: standard output



The fence around the strategically important Berland pistachio factory has a circle form. N soldiers were posted to guard the factory according to the new government program "Pistachio protection in industry and life" (decree 1731 of 10/10/2003). Each soldier moves along the outer side of the fence at a constant speed (clockwise or counter-clockwise). The fence perimeter is 1000 meters long. The initial position of each soldier Li (the distance from the entrance checkpoint round the circle clockwise) is known, 0<=Li<=999, all Li are different integers. The speed of each soldier is Vi meters per minute (-100<=Vi<=100, Vi<>0, Vi is integer). Note: if a soldier's speed is negative, then he moves in the counter-clockwise direction, and in the clockwise direction in the opposite case.
If a soldier meets another soldier on his way, he immediately asks him a password "Have you a spare cigarette?", and getting a "No" answer he keeps on moving. Note, the term "meet" means the moment of time, when the two soldiers are at one and the same point with the opposite velocities. Since the soldiers serve for over a year they have learned to say the password and the answer so quickly, that if a soldier meets several soldiers at once, he manages both to ask each soldier for a password and to answer him.
Your task is to find out how many times each soldier asks a password during the period of T minutes from the initial moment of time (inclusive).

Input
The first line contains two natural numbers N and T (1<=N<=20; 1<=T<=50). The second line contains integer numbers L1, L2, ..., LN, and the third line contains V1, V2, ..., VN. Numbers in each line are separated by one or more spaces.

Output
Output N numbers B1, B2, ..., BN separated by a space, where Bi is the number of questions asked by the i-th soldier.

Sample test(s)

Input

3 2
0 1 2
1 -1 -2

Output

2 1 1
[submit]
[forum]
Author:	Michael R. Mirzayanov
Resource:	ACM International Collegiate Programming Contest 2003-2004
North-Eastern European Region, Southern Subregion
Date:	2003 October, 9 
*/
import java.util.*;

public class Solution {
	static int gao(int d, int s) {
		if (s < 0) {
			return gao(-d, -s);
		} else if (d < 0) {
			return gao(1000 + d, s);
		} else {
			return (s + 1000 - d) / 1000;
		}
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int t = in.nextInt();
		int[] l = new int[n];
		for (int i = 0; i < l.length; ++i) {
			l[i] = in.nextInt();
		}
		int[] v = new int[n];
		for (int i = 0; i < v.length; ++i) {
			v[i] = in.nextInt();
		}

		int[] b = new int[n];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				if (v[i] * v[j] < 0) {
					int bij = gao(l[i] - l[j], (v[j] - v[i]) * t);
					b[i] += bij;
					b[j] += bij;
				}
			}
		}
		for (int i = 0; i < b.length; ++i) {
			System.out.print(b[i]);
			System.out.print(i == b.length - 1 ? '\n' : ' ');
		}
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//873648	04.08.09 11:22	watashi	188 	.JAVA	Accepted	19 ms	2262 kb

