// SGU239. Minesweeper
/*
239. Minesweeper
time limit per test: 0.50 sec.
memory limit per test: 4096 KB
input: standard
output: standard



Not so long ago, an International Cell Playing Company (ICPC) decided to organize an Amusing Championship of Minesweeper (ACM). "Minesweeper" is a standard Windows game (you can find it now at Start->Programs->Games->Minesweeper or somewhere like this). The rules of "Minesweeper" are the following: you are to open all the cells of a game field, that don't contain mines, and to mark by flags all the cells, that contain mines. During the game, numbers which are written in the cells help you to solve this task. These numbers appear in the opened cells (it is denied to open a cell with a mine, in this case you will be exploded). A number written in a cell indicates how many mines are situated in 8 neighboring cells (fig.1).



fig. 1


Just for aesthetic reasons "0" is indicated in background color, so you don't see it. In the case of absence of any mines in the cells neighboring with some opened cell, all neighboring cells will be opened automatically (you can see it on the first figure, where only 1 cell was opened by player, and other cells were opened automatically).
Now we can immediately say where the mines are certainly situated (fig. 2).



fig. 2


Very often a following situation takes place. No cell of the first column is opened, while all the cells of second column are opened, and it is guaranteed that second and third columns don't contain mines at all (fig. 3).



fig. 3


In that case the numbers shown in the cells of the second column indicate exactly the number of mines situated in the neighboring cells of the first column. Such situations are very hard for players to solve, and that's why your friend who wants to train for ACM, asked you to write a program that gives him a possibility to check his solutions.
Imagine now, that we are playing Minesweeper on the field, containing N rows and 2 columns. It is guaranteed, that the second column is free of mines and completely opened. The first column is not opened yet, and may contain mines. You are to determine the location of all mines in the first column, when you know all the data of the second column. It is possible to do so if, for example, one of the cells of the second column contains number 3 (fig. 4).



fig. 4


So you can be sure, that all 3 neighboring cells of the first column contain mines. Therefore it is not difficult to find out, which cells are free of mines (fig. 5).



fig. 5


Now, using this information, we can say all about the first column (the remaining cells definitely contain mines). Sometimes it can be impossible to determine surely, where the mines are situated, and where not (fig. 6).



fig. 6


Sometimes the field may be mistaken at all, and there exists no mine distribution that produces such numbers in the second column (fig. 3, pay attention to the upper part of the column). It is not very amazing when you remember who has written this game.
Now you must write a program which, given the data of the second column, outputs how many distributions of the mines in the first column exist, that produce such data in the second column.

Input
The first line of input contains integer N - height of the field (1<=N<=1000). Then N lines follow, each containing an integer ai (0<=ai<=3) - the number, written on the I-th cell of the second column.

Output
You must output the only number - an answer to the problem.

Sample test(s)

Input

Test #1
9
1 1 3 2 1 1 1 2 1

Test #2
2
1 1

Test #3
7
1 2 3 2 2 2 2

Output

Test #1
0

Test #2
2

Test #3
1
[submit]
[forum]
Author:	Antony Popovich
Resource:	Leningrad Regional School Programming Olympiad
Date:	January 9, 2004 
*/
import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; ++i) {
			a[i] = in.nextInt();
		}
		int ans = 0;
		boolean[] b = new boolean[n + 1];
		for (int k = 0; k <= 1; ++k) {
			boolean flag = true;
			int cnt = k;
			b[0] = (k == 1);
			for (int i = 0; flag && i < n; ++i) {
				if (cnt == a[i]) {
					b[i + 1] = false;
				} else if (cnt == a[i] - 1) {
					b[i + 1] = true;
					++cnt;
				} else {
					flag = false;
				}
				if (i > 0 && b[i - 1]) {
					--cnt;
				}
			}
			if (flag && !b[n]) {
				++ans;
			}
		}
		System.out.println(ans);
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//873592	04.08.09 07:45	watashi	239 	.JAVA	Accepted	54 ms	3094 kb

