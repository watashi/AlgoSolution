// SGU405. Totalizator
/*
405. Totalizator
Time limit per test: 2 second(s)
Memory limit: 65536 kilobytes
input: standard
output: standard
Some time ago Vasya was cleaning up the garret. After the hours of hard work he suddenly found the notes of the totalizator, which his grandfather had organised during the XII Berland football championship. It followed from the notes that each participant of the totalizator made his prediction about the result of every match (the result of the match is an ordered pair of numbers  — number of goals scored by the first team and number of goals scored by the second team). Each prediction is such pair of numbers too. Every participant got score for the every prediction he made by the following rules:

    * if he guesses the winner (or a tie), his score is inscreased by 2.
    * if he guesses the difference between the number of goals scored by the first and the second team, his score is inscreased by 3.
    * if he guesses the number of goals scored by the first team, his score is increased by 1.
    * if he guesses the number of goals scored by the second team, his score is increased by 1. 

So, if the participant guesses the exact result of the match, he gets 7 points. Or, for example, if he guesses only the winner and the difference, he scores 5 points. Unfortunately, the list with the results of the totalizator was lost. But Vasya wants to know how many scores each totalizator participant got. Help him to find the scores.
Input
The first line contains two integer numbers and (, ) — the number of participants and the number of games. After it blocks of lines follow. Each block corresponds to one match. The first line of each block contains two integer numbers () — numbers of goals scored by the first and the second team. Other lines of each block contain predictions of all participants in the same format, the -th line is a prediction of the -th participant.
Output
Output numbers separated by spaces — scores of participants. The -th number should be the score of the -th participant. Participants are numbered from to as their predictions are given in the input.
Example(s)

sample input

	

sample output

1 2
3 2
2 1
0 2
0 0

	

6


sample input

	

sample output

2 3
4 3
2 2
2 0
0 0
1 1
1 0
5 0
3 0
2 0

	

8 6

*/
import java.util.*;

public class Solution {
	static int sign(int x) {
		if (x > 0) {
			return 1;
		} else if (x < 0) {
			return -1;
		} else {
			return 0;
		}
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		int[] s = new int[n];
		for (int i = 0; i < m; ++i) {
			int a = in.nextInt();
			int b = in.nextInt();
			for (int j = 0; j < n; ++j) {
				int aa = in.nextInt();
				int bb = in.nextInt();
				if (sign(aa - bb) == sign(a - b)) {
					s[j] += 2;
				}
				if (aa - bb == a - b) {
					s[j] += 3;
				}
				if (aa == a) {
					++s[j];
				}
				if (bb == b) {
					++s[j];
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			System.out.print(s[i]);
			System.out.print(i == n - 1 ? '\n' : ' ');
		}
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//873635	04.08.09 10:18	watashi	405 	.JAVA	Accepted	127 ms	3226 kb
