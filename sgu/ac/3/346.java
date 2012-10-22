// SGU346. Snooker
/*
346. Snooker
Time limit per test: 2 second(s)
Memory limit: 65536 kilobytes
input: standard
output: standard


Snooker is a cue sport that is played on a large (12 ft * 6 ft, 3.6 m * 1.8 m) baize-covered table with pockets in each of the four corners and in the middle of each of the long side cushions. It is played using a cue, one white ball (the cue ball), 15 red balls (worth 1 point each) and 6 balls of different colours (worth 2-7 points each). [Wikipedia, the free encyclopedia]

Snooker is played by two players or two teams. The main rule in snooker is to alternate potting reds and colours — that's how yellow, green, brown, blue, pink and black balls are called. They cost from 2 to 7 points each in this particular order. Alternating means that after potting a red ball, the player has to pot any colour ball and vice versa. If the player has potted any colour ball and there are still some reds or he has potted last red by the previous shot, this potted colour ball is put back on the table. If there are no reds and a colour was out back for the last time, the player has to pot all colours in the increasing order of their cost. If there is at least one red ball ath the table, the player can start his break (a sequence of continuously potted balls) only with the red ball. These rules will be enough for this problem.

For example, let's consider two reds on the table. The player may pot them in order like "red - black - red - pink - yellow - green - brown - blue - pink - black" which is correct break, but "red - red" or "red - black - pink" is not correct.

Professional players always estimate "score on the table" — maximal score one can achieve by correctly potting all the balls on the table. Obviously, this can be done by alternating reds with black, because black is the most expensive colour ball. Your task is to find this maximal score.

Input
The first line of the input file contains 7 numbers, representing the number of the balls of each color in a particular order: red, yellow, green, brown, blue, pink and black. The number of all balls except red will be from 0 to 1, the number of red balls will be from 0 to 15. The second line contains one word: "RED" if the last potted ball was red, "COLOUR" if the last potted ball was colour, and "NONE" if the next shot will be the first in the player's brake. You may assume that if there is at least one red ball, there are all colours. Also you may assume that if there are no reds, colours have been potted in the correct order.

Output
Write to the output file the desired maximum score.

Example(s)

sample input

	

sample output

2 1 1 1 1 1 1
COLOUR

	

43


sample input

	

sample output

2 1 1 1 1 1 1
RED

	

50


sample input

	

sample output

0 0 0 1 1 1 1
NONE

	

22


sample input

	

sample output

0 1 1 1 1 1 1
RED

	

34




Note
"Red - black - red - black - yellow - green - brown - blue - pink - black" costs 1 + 7 + 1 + 7 + 2 + 3 + 4 + 5 + 6 + 7 = 43 points.

"Black - red - black - red - black - yellow - green - brown - blue - pink - black" costs 7 + 1 + 7 + 1 + 7 + 2 + 3 + 4 + 5 + 6 + 7 = 50 points.

According to the rules, player has to pot brown ball next, so "brown - blue - pink - black" costs 4 + 5 + 6 + 7 = 22 points.

"Black - yellow - green - brown - blue - pink - black" costs 7 + 2 + 3 + 4 + 5 + 6 + 7 = 34 points.
*/
import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int[] a = new int[7];
		for (int i = 0; i < 7; ++i) {
			a[i] = in.nextInt();
		}
		int s = 0;
		if (in.next().charAt(0) == 'R') {
			s += 7;
		}
		s += a[0] * 8;
		for (int i = 1; i < 7; ++i) {
			s += a[i] * (i + 1);
		}
		System.out.println(s);
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//887536	16.09.09 09:06	watashi	346 	.JAVA	Accepted	44 ms	0 kb

