// SGU398. Friends of Friends
/*
398. Friends of Friends
Time limit per test: 2 second(s)
Memory limit: 65536 kilobytes
input: standard
output: standard


Social networks are very popular now. They use different types of relationships to organize individual users in a network. In this problem friendship is used as a method to connect users. For each user you are given the list of his friends. Consider friendship as a symmetric relation, so if user is a friend of user then is a friend of .

A friend of a friend for is such a user that is not a friend of , but there is such that is a friend of and is a friend of . Obviously .

Your task is to find the list of friends of friends for the given user .

Input
The first line of the input contains integer numbers and (, ), where is the total number of users and is user to be processed. Users in the input are specified by their numbers, integers between and inclusive. The following lines describe friends list of each user. The -th line contains integer () — number of friends of the -th user. After it there are distinct integers between and — friends of the -th user. The list doesn't contain . It is guaranteed that if user is a friend of user then is a friend of .

Output
You should output the number of friends of friends of in the first line. Second line should contain friends of friends of printed in the increasing order.

Example(s)

sample input

	

sample output

4 2
1 2
2 1 3
2 4 2
1 3

	

1
4


sample input

	

sample output

4 1
3 4 3 2
3 1 3 4
3 1 2 4
3 1 2 3

	

0
*/
import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int x = in.nextInt() - 1;
		boolean[][] f = new boolean[n][n];
		for (int i = 0; i < n; ++i) {
			int k = in.nextInt();
			for (int j = 0; j < k; ++j) {
				int y = in.nextInt() - 1;
				f[i][y] = true;
			}
		}
		ArrayList<Integer> ans = new ArrayList<Integer>();
		for (int i = 0; i < n; ++i) {
			if (i == x || f[x][i]) {
				continue;
			}
			boolean flag = false;
			for (int j = 0; !flag && j < n; ++j) {
				if (f[x][j] && f[i][j]) {
					flag = true;
					break;
				}
			}
			if (flag) {
				ans.add(i);
			}
		}
		System.out.println(ans.size());
		boolean blank = false;
		for (int ansi : ans) {
			if (blank) {
				System.out.print(' ');
			} else {
				blank = true;
			}
			System.out.print(ansi + 1);
		}
		System.out.println();
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//874741	09.08.09 13:07	watashi	398 	.JAVA	Accepted	60 ms	3070 kb

