// SGU296. Sasha vs. Kate
/*
296. Sasha vs. Kate
Time limit per test: 2 second(s)
Memory limit: 65536 kilobytes
input: standard
output: standard


During the regular Mars's World Finals Subregional Programming Contest a boy Sasha lost "Mars" bars of chocolate to a girl Kate. But for two years already Sasha does not hurry to pay his debt. And now Sasha and Kate decided that Sasha will give Kate chocolate bars, where number can be obtained from the number by removing exactly decimal digits. Sasha generously let Kate to choose digits to be removed. Your task is to find out how many bars Sasha will give Kate. Of course Kate will choose digits from the number in such a way that the resulting number would be maximal.

Input
The first line of the input file contains two integer numbers and (). Number is strictly less than the number of digits in . will not have any leading zeros.

Output
Output the unknown .

Example(s)

sample input

	

sample output

1992 2

	

99


sample input

	

sample output

1000 2

	

10
*/
import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String n = in.next();
		int k = in.nextInt();
		int l = n.length() - k;
		StringBuilder buf = new StringBuilder(l);
		for (int i = 0, p = 0; i < l; ++i, ++p) {
			char max = ' ';
			int pos = -1;
			for (int j = 0; j <= k; ++j) {
				if (n.charAt(p + j) > max) {
					max = n.charAt(p + j);
					pos = j;
				}
			}
			buf.append(max);
			k -= pos;
			p += pos;
		}
		System.out.println(buf);
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//873582	04.08.09 07:12	watashi	296 	.JAVA	Accepted	19 ms	2234 kb

