// SGU249. Matrix
/*
249. Matrix
time limit per test: 2 sec.
memory limit per test: 65536 KB
input: standard
output: standard



It is necessary to arrange numbers from 0 to 2^(N+M)-1 in the matrix with 2^N rows and 2^M columns. Moreover, numbers occupying two adjacent cells must differ only in single bit in binary notation. Cells are adjacent if they have common side. Matrix is cyclic, i.e. for each row the leftmost and rightmost matrix cells are considered to be adjacent (the topmost and the bottommost matrix cells are also adjacent).

Input
The first line of input contains two integers N and M (0<N,M; N+M<=20).

Output
Output file must contain the required matrix in a form of 2^N lines of 2^M integers each.

Sample test(s)

Input

1 1

Output

0 2
1 3
[submit]
[forum]
Author:	Antony Popovich
Resource:	Petrozavodsk Summer Training Sessions 2004
Date:	August 25, 2004 
*/
// [algo] gray 
/*
从全0串开始，第一个串为全0串；如果当前串有偶数个位为1，则下一个串为将当前串最低位反转所得；如果当前串有奇数个位为1，则找出当前串中为1的最低位，将该位的高一位反转即可得到下一个串；循环以上步骤直至n位二进制串溢出。
*/
/**************************************************************************/
/*   gray[n] = n ^ (n >> 1)                                               */
/**************************************************************************/
import java.util.*;

public class Solution {
	// [module] gray
	public static int[] getGray(int n) {
		int[] ret = new int[1 << n];
		int x = 0;
		for (int i = 0; i < ret.length; i += 2) {
			ret[i] = x;
			ret[i ^ 1] = x ^ 1;
			x ^= 1;
			x ^= (x ^ (x - 1)) + 1;
		}
		return ret;
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		int[] r = getGray(n);
		int[] c = getGray(m);
		StringBuilder buf = new StringBuilder();
		for (int a : r) {
			for (int b : c) {
				buf.append((a << m) ^ b);
				buf.append(' ');
			}
			buf.setCharAt(buf.length() - 1, '\n');
		}
		System.out.print(buf);
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//873643	04.08.09 11:07	watashi	249 	.JAVA	Accepted	417 ms	39838 kb
