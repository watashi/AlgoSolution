// SGU135. Drawing Lines

/*
135. Drawing Lines

time limit per test: 0.50 sec.
memory limit per test: 4096 KB

Little Johnny likes to draw a lot. A few days ago he painted lots of straight lines on his sheet of paper. Then he counted in how many zones the sheet of paper was split by these lines. He noticed that this number is not always the same. For instance, if he draws 2 lines, the sheet of paper could be split into 4, 3 or even 2 (if the lines are identical) zones. Since he is a very curious kid, he would like to know which is the maximum number of zones into which he can split the sheet of paper, if he draws N lines. The sheet of paper is to be considered a very large (=infinite) rectangle.

Input

The input file will contain an integer number: N (0<=N<=65535).

Output

You should output one integer: the maximum number of zones into which the sheet of paper can be split if Johnny draws N lines.

Sample Input #1

0

Sample Output #1

1

Sample Input #2

1

Sample Output #2

2

Author	: Mugurel Ionut Andreica
Resource	: SSU::Online Contester Fall Contest #2
Date	: Fall 2002
*/
import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		long n = in.nextLong();
		System.out.println(1 + n * (n + 1) / 2);
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//865692	30.06.09 06:17	watashi	135 	.JAVA	Accepted	6 ms	1886 kb

