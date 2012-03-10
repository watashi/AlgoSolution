// SGU222. Little Rooks

/*
222. Little Rooks
time limit per test: 1 sec.
memory limit per test: 65536 KB
input: standard
output: standard



Inspired by a "Little Bishops" problem, Petya now wants to solve problem for rooks.

A rook is a piece used in the game of chess which is played on a board of square grids. A rook can only move horizontally and vertically from its current position and two rooks attack each other if one is on the path of the other.

Given two numbers n and k, your job is to determine the number of ways one can put k rooks on an n × n chessboard so that no two of them are in attacking positions.

Input

The input file contains two integers n (1 ≤ n ≤ 10) and k (0 ≤ k ≤ n2).

Output

Print a line containing the total number of ways one can put the given number of rooks on a chessboard of the given size so that no two of them are in attacking positions.

Sample test(s)

Input

4 4

Output

24


Author:	Andrew Stankevich
Resource:	Little Chess Pieces Series, SPb IFMO 2003-2004 Authumn Training Sessions
Date:	2003-10-01

*/

import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int k = in.nextInt();
		if (k > n) {
			System.out.println(0);
		} else {
			int ans = 1;
			for (int i = 1; i <= k; ++i) {
				ans *= (n + 1 - i);
				ans *= (n + 1 - i);
				ans /= i;
			}
			System.out.println(ans);
		}
	}
}

// ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
// 866746	04.07.09 20:27	watashi	222 	.JAVA	Accepted	19 ms	2218 kb


