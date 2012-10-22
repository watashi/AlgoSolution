// SGU109. Magic of David Copperfield II
/*
109. Magic of David Copperfield II

time limit per test: 0.50 sec.
memory limit per test: 4096 KB

The well-known magician David Copperfield loves lo show the following trick: a square with N rows and N columns of different pictures appears on a TV screen, Let us number all the pictures in the following order:

1	2	...	N
...	...	...	...
N*(N-1)+1	N*(N-1)+2	...	N*N

Each member of the audience is asked to put a finger on the upper left picture (i.e., picture number one) and The Magic begins: the magician tells the audience to move the finger K1 times through the pictures (each move is a shift of the finger to the adjacent picture up, down, left or right provided that there is a picture to move to), then with a slight movement of his hand he removes some of the pictures with an exclamation "You are not there!", and ... it is true - your finger is not pointing to any of the pictures removed. Then again, he tells the audience to make K2 moves, and so on. At the end he removes all the pictures but one and smiling triumphantly declares, "I've caught you" (applause).

Just now, David is trying to repeat this trick. Unfortunately, he had-a hard day before, and you know how hard to conjure with a headache. You have to write a program that will help David to make his trick.

Input

The input file contains a single integer number N (1<N<101).

Output

Your program should write the following lines with numbers to the output file:
K1 X1,1 X1,2 ... X1,m1
K2 X2,1 X2,2 ... X2,m2
...
Ke Xe,1 Xe,2 ... Xe,me
where Ki is a number of moves the audience should make on the i-th turn (N<=Ki<300). All Ki, should be different (i.e. Ki<>Kj when i<>j). Xi,1 Xi,2 ... Xi,mi are the numbers of the pictures David should remove after the audience will make Ki moves (the number of the pictures removed is arbitrary, but each picture should be listed only once, and at least one picture should be removed on each turn).
A description of the every next turn should begin with a new line. All numbers on each line should be separated by one or more spaces. After e iterations, all pictures except one should be removed.

Sample Input

3

Sample Output

3 1 3 7 9
5 2 4 6 8

*/
import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		if (n == 2) {
			System.out.println("3 1");
			System.out.println("5 2 3");
		} else {
			System.out.print(n);
			for (int i = 0; i < n; ++i) {
				for (int j = Math.max(0, n + 1 - i); j < n; ++j) {
					System.out.print(" " + (i * n + j + 1));
				}
			}
			System.out.println();
			for (int k = 0; k < n; ++k) {
				System.out.print(((n + 1) / 2 + k) * 2 + 1);
				for (int i = Math.max(0, 1 - k); i < Math.min(n, n + 1 - k); ++i) {
					System.out.print(" " + (i * n + (n - k - i) + 1));
				}
				System.out.println();
			}
		} 
	}
}

// ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
// 867995	09.07.09 14:19	watashi	109 	.JAVA	Accepted	103 ms	3446 kb


