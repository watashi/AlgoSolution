// SGU403. Scientific Problem
/*
403. Scientific Problem
Time limit per test: 2 second(s)
Memory limit: 65536 kilobytes
input: standard
output: standard


Once upon a time Professor Idioticideasinventor was travelling by train. Watching cheerless landscape outside the window, he decided to invent the theme of his new scientific work. All of a sudden a brilliant idea struck him: to develop an effective algorithm finding an integer number, which is times less than the sum of all its integer positive predecessors, where number is given. As far as he has no computer in the train, you have to solve this difficult problem.

Input
The first line of the input file contains an integer number ().

Output
Output an integer number — the answer to the problem.

Example(s)

sample input

	

sample output

1

	

3


sample input

	

sample output

2

	

5
*/
import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		System.out.println(2 * n + 1);
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//873626	04.08.09 09:42	watashi	403 	.JAVA	Accepted	6 ms	2218 kb
