// SGU133. Border
/*
133. Border

time limit per test: 0.50 sec.
memory limit per test: 4096 KB

Along the border between states A and B there are N defence outposts. For every outpost k, the interval [Ak,Bk] which is guarded by it is known. Because of financial reasons, the president of country A decided that some of the outposts should be abandoned. In fact, all the redundant outposts will be abandoned. An outpost i is redundant if there exists some outpost j such that Aj<Ai and Bi<Bj. Your task is to find the number of redundant outposts.

Input

The first line of the input will contain the integer number N (1<=N<=16 000). N lines will follow, each of them containing 2 integers: Ak and Bk (0<= Ak < Bk <= 2 000 000 000), separated by blanks. All the numbers Ak will be different. All the numbers Bk will be different.

Output

You should print the number of redundant outposts.

Sample Input

5
0 10
2 9
3 8
1 15
6 11

Sample Output

3

Author	: Mugurel Ionut Andreica
Resource	: SSU::Online Contester Fall Contest #2
Date	: Fall 2002

*/

import java.io.*;
import java.util.*;

public class Solution {
	public static void main(String[] args) {
		// Scanner in = new Scanner(new BufferedInputStream(System.in));	// 260 ms > 248 ms
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		long[] ab = new long[n];
		for (int i = 0; i < n; ++i) {
			long a = in.nextLong();
			long b = in.nextLong();
			ab[i] = (a << 32) ^ b;
		}
		Arrays.sort(ab);
		int cura = -1, maxb = -1;
		int ans = 0;
		for (long abi : ab) {
			int a = (int)(abi >> 32);
			int b = (int)(abi & 0xFFFFFFFF);
			if (a > cura && b < maxb) {
				++ans;
			}
			cura = Math.max(cura, a);
			maxb = Math.max(maxb, b);
		}
		System.out.println(ans);
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//866720	04.07.09 18:57	watashi	133 	.JAVA	Accepted	260 ms	3330 kb
//866721	04.07.09 18:58	watashi	133 	.JAVA	Accepted	248 ms	3326 kb

