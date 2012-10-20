// SGU362. Robot-Annihilator
/*
362. Robot-Annihilator
Time limit per test: 1 second(s)
Memory limit: 65536 kilobytes
input: standard
output: standard


Old factory in Berland is in accident condition. Danger of its demolition forced government to shut down the factory, destroy it completely, and build new modern factory in this area. For the safety of people destruction of the factory will be performed by specially constructed . On the map the factory has the shape of rectangle N ×M, i. e. N rows of M buildings. Robot-annihilator has infinite amount of bombs. Each bomb completely destroys exactly one building. The robot runs using very simple algorithm: if the robot located at building (i, j) (i. e. building in row i in column j), it puts the bomb in this building and goes to the next building. As soon as robot leaves building (i, j), the bomb in that building explodes. Robot selects next building from the four neighbors: (i + 1, j), (i, j - 1), (i - 1, j), (i, j + 1); some of these buildings may not exist, because robot may stay at the boundary of factory. Robot chooses first existed non-exploded building out of that list. After that, the same procedure repeats. If all neighboring buildings are destroyed, robot doesn't move and explodes with the building. Task of your program is to make full report about robot's actions, given its initial position (is, js).

Input
The first line of the input file contains two integer numbers N, M (1 ≤ N ≤ 10; 1 ≤ M ≤ 10). The second line of the input file contains coordinates (is, js) of the initial robot position (1 ≤ is ≤ N, 1 ≤ js ≤ M).

Output
Print sequence of robot's moves. Each move describes by one capital Latin letter: "D" (moving down), "L" (left), "U" (up), "R" (right). If the robot is located at the point (i, j), down direction corresponds to the point (i + 1, j), left - (i, j - 1), up - (i - 1, j), right - (i, j + 1). There should be no extra spaces or characters, so the output file contains only characters "D", "L", "U" and "R".

Example(s)

sample input

	

sample output

3 3
1 2

	

DDLUU

*/
import java.util.*;

public class Solution {
	static final int[] dx = new int[]{1, 0, -1, 0};
	static final int[] dy = new int[]{0, -1, 0, 1};
	static final char[] dz = new char[]{'D', 'L', 'U', 'R'};

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		int x = in.nextInt() - 1;
		int y = in.nextInt() - 1;
		boolean[][] b = new boolean[n][m];
		while (true) {
			b[x][y] = true;
			int d = -1;
			for (int i = 0; d == -1 && i < 4; ++i) {
				try {
					if (!b[x + dx[i]][y + dy[i]]) {
						d = i;
					}
				} catch (ArrayIndexOutOfBoundsException e) {
				}
			}
			if (d == -1) {
				break;
			} else {
				System.out.print(dz[d]);
				x += dx[d];
				y += dy[d];
			}
		}
		System.out.println();
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//874943	10.08.09 15:05	watashi	362 	.JAVA	Accepted	35 ms	2158 kb
