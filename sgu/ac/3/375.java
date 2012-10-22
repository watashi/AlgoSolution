// SGU375. Amplifiers
/*
375. Amplifiers
Time limit per test: 6 second(s)
Memory limit: 65536 kilobytes
input: standard
output: standard


Scientist Shurik needs voltage that is N times more that the standard voltage in the wall outlet for power supply for his time machine. The standard voltage is equal to one Bervolt. Shurik decided to use voltage amplifiers. In the nearby shop he found the amplifiers of two types, the first type creates voltage 2X-1 Bervolt from X Bervolt, the second one creates voltage 2X+1 Bervolt from X Bervolt. The number of amplifiers in the shop is unlimited. Shurik wants to build a sequence of amplifiers from the outlet to the time machine. Of course he wants to minimize the number of amplifiers. Help him.

Input
A single integer 1 ≤ N≤ 2·109.

Output
If it is possible to make such scheme, output in the first line the minimal possible number of amplifiers. The second line in this case is to contain the sequence of amplifiers from the outlet to the time machine. Use number 1 for the first-type amplifiers and number 2 for second-type amplifiers.

If there is no solution, output "

No solution

" (without quotes).

Example(s)

sample input

	

sample output

5

	

2
2 1

*/

import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		if (n % 2 == 0) {
			System.out.println("No solution");
		} else {
			String nb = Integer.toBinaryString(n);
			String ans = nb.substring(0, nb.length() - 1);
			System.out.println(ans.length());
			boolean blank = false;
			for (char ch : ans.toCharArray()) {
				if (blank) {
					System.out.print(' ');
				} else {
					blank = true;
				}
				System.out.print((char)(ch + 1));
			}
			System.out.println();
		}
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//874939	10.08.09 14:13	watashi	375 	.JAVA	Accepted	25 ms	2054 kb

