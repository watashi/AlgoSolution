// SGU104. Little shop of flowers 
/*
104. Little shop of flowers

time limit per test: 0.50 sec.
memory limit per test: 4096 KB

PROBLEM

You want to arrange the window of your flower shop in a most pleasant way. You have F bunches of flowers, each being of a different kind, and at least as many vases ordered in a row. The vases are glued onto the shelf and are numbered consecutively 1 through V, where V is the number of vases, from left to right so that the vase 1 is the leftmost, and the vase V is the rightmost vase. The bunches are moveable and are uniquely identified by integers between 1 and F. These id-numbers have a significance: They determine the required order of appearance of the flower bunches in the row of vases so that the bunch i must be in a vase to the left of the vase containing bunch j whenever i < j. Suppose, for example, you have bunch of azaleas (id-number=1), a bunch of begonias (id-number=2) and a bunch of carnations (id-number=3). Now, all the bunches must be put into the vases keeping their id-numbers in order. The bunch of azaleas must be in a vase to the left of begonias, and the bunch of begonias must be in a vase to the left of carnations. If there are more vases than bunches of flowers then the excess will be left empty. A vase can hold only one bunch of flowers.

Each vase has a distinct characteristic (just like flowers do). Hence, putting a bunch of flowers in a vase results in a certain aesthetic value, expressed by an integer. The aesthetic values are presented in a table as shown below. Leaving a vase empty has an aesthetic value of 0.

  	  	

V A S E S
  	  	

1
	

2
	

3
	

4
	

5

Bunches
	

1 (azaleas)
	

7
	

23
	

-5
	

-24
	

16

2 (begonias)
	

5
	

21
	

-4
	

10
	

23

3 (carnations)
	

-21
	

5
	

-4
	

-20
	

20

 

According to the table, azaleas, for example, would look great in vase 2, but they would look awful in vase 4.

To achieve the most pleasant effect you have to maximize the sum of aesthetic values for the arrangement while keeping the required ordering of the flowers. If more than one arrangement has the maximal sum value, any one of them will be acceptable. You have to produce exactly one arrangement.

ASSUMPTIONS

    * 1 ≤ F ≤ 100 where F is the number of the bunches of flowers. The bunches are numbered 1 through F.

    * F ≤ V ≤ 100 where V is the number of vases.

    * -50 £ Aij £ 50 where Aij is the aesthetic value obtained by putting the flower bunch i into the vase j.

Input

    * The first line contains two numbers: F, V.

    * The following F lines: Each of these lines contains V integers, so that Aij is given as the j’th number on the (i+1)’st line of the input file.

Output

    * The first line will contain the sum of aesthetic values for your arrangement. 

# The second line must present the arrangement as a list of F numbers, so that the k’th number on this line identifies the vase in which the bunch k is put.

Sample Input

3 5 
7 23 -5 -24 16
5 21 -4 10 23
-21 5 -4 -20 20

Sample Output

53 
2 4 5
*/

import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int f = in.nextInt();
		int v = in.nextInt();
		int[][] dp = new int[f][v];
		int[][] pd = new int[f][v];
		for (int j = 0; j < v; ++j) {
			dp[0][j] = in.nextInt();
			pd[0][j] = -1;
		}
		for (int i = 1; i < f; ++i) {
			for (int j = 0; j < v; ++j) {
				dp[i][j] = Integer.MIN_VALUE;
				for (int k = 0; k < j; ++k) {
					if (dp[i - 1][k] > dp[i][j]) {
						dp[i][j] = dp[i - 1][k];
						pd[i][j] = k;
					}
				}
				int a = in.nextInt();
				if (dp[i][j] != Integer.MIN_VALUE) {
					dp[i][j] += a;
				}
			}
		}
		int k = 0;
		for (int j = 0; j < v; ++j) {
			if (dp[f - 1][j] > dp[f - 1][k]) {
				k = j;
			}
		}
		System.out.println(dp[f - 1][k]);
		Stack<Integer> s = new Stack<Integer>();
		for (int i = f - 1; i >= 0; --i) {
			s.push(k + 1);
			k = pd[i][k];
		}
		while (!s.isEmpty()) {
			System.out.print(s.pop());
			if (s.isEmpty()) {
				System.out.println();
			} else {
				System.out.print(' ');
			}
		}
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//866774	04.07.09 22:17	watashi	104 	.JAVA	Accepted	103 ms	3262 kb


