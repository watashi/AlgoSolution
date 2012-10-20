// SGU297. Fair-play
/*
297. Fair-play
Time limit per test: 2 second(s)
Memory limit: 65535 kilobytes
input: standard
output: standard


Once after the regular working week a group of friends gathered and went to the best local pub. After the party they decided to divide the total bill in equal parts. It is not always possible to divide the total sum ( rub.) to parts without the remainder. So each of the friends pays the integer amount of rubles and the remainder from the division of by is paid only by some of them by adding one additional ruble. Using this scheme the maximum difference between any of two friends is not more then rub. After the first pub they decided to continue their tour and visited all pubs in the city. Visiting each pub they followed the same strategy of paying their bills. As the result the maximum difference for any of two friends between total sums they paid should be minimal. Obviously the value will not be more then rub. Your task is to find the number of friends who paid rub more then the others.

Input
The first line of the input contains two integer numbers () and (). Each of the following lines contains the total bill in the -th pub — integer number (, for all from to ).

Output
Write to the output the only number .

Example(s)

sample input

	

sample output

3 2
200
100

	

0


sample input

	

sample output

7 3
1
4
5

	

3
*/
import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		int s = 0;
		for (int i = 0; i < m; ++i) {
			s += in.nextInt();
		}
		System.out.println(s % n);
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//873586	04.08.09 07:19	watashi	297 	.JAVA	Accepted	30 ms	2310 kb
