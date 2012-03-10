// SGU361. National Flag
/*
361. National Flag
Time limit per test: 1 second(s)
Memory limit: 65536 kilobytes
input: standard
output: standard


Series of bloody civil wars in Berland finished! After the long-awaited reunion it was decided to create new Berland flag. Berland Heraldic Council proposed following requirements:

1. Berland flag must be a rectangle of N×M cells. Each cell must be painted with blue or red;

2. any 3×2 or 2×3 rectangle of the flag must have exactly two blue cells;

3. blue paint is very expensive, so the number of blue cells should as low as possible.

Write a program that creates Berland flag.

Input
Input file contains two integer numbers N and M (3 ≤ N, M ≤ 200) separated by a space.

Output
Print to the output file N lines with M characters on each line: j-th character on the i-th line must be 0 (zero) if the cell (i, j) painted with read, and "#" if it is blue. If there are several solutions output any of them. Print "No solution" (without quotes) if there is no solution.

Example(s)

sample input

	

sample output

3 3

	

#00 
00# 
0#0

*/
import java.util.*;

public class Solution {
	static final int[][] K = new int[][]{
		new int[]{0, 0, 0},
		new int[]{0, 1, 2},
		new int[]{0, 2, 0}
	};

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		int k = K[n % 3][m % 3];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				System.out.print((i + j) % 3 == k ? '#' : '0');
			}
			System.out.println();
		}
	}
}

// n%3==1 && m%3==1 => WA5
// n%3==1 && m%3==2 || n%3==2 && m%3==1 => WA6
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//875192	11.08.09 14:04	watashi	361 	.JAVA	Accepted	95 ms	3306 kb

