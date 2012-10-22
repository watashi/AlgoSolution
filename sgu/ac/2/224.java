// SGU224. Little Queens
/*
224. Little Queens
time limit per test: 2 sec.
memory limit per test: 65536 KB
input: standard
output: standard



Well, you might have heard about a curious boy Petya who likes to learn the number of ways one can put k identical chess pieces on a chessboard of size n× n so that no two of them are in the attacking positions. He have solved the problems for bishops, rooks and kings. Recently he has met Farmer John and told him about that.

Impressed FJ has decided to teach his cows to play chess. The first question Bessie asked on the first lesson was: "What about the number of ways one can put k queens on a chessboard of size n × n, so that no two of them are in the attacking positions?"

The queen can move diagonally, horizonatally and vertically, thus combining the properties of a bishop and a rook. Two queens are in the attacking positions if they are on the path of each other.

Input

The input file contains two integers n (1 ≤ n ≤ 10) and k (0 ≤ k ≤ n2).

Output

Print a line containing the total number of ways one can put the given number of queens on a chessboard of the given size so that no two of them are in attacking positions.

Sample test(s)

Input

Test #1

3 2

Test #2

4 4

Output

Test #1

8

Test #2

2
[submit]
[forum]
Author:	Andrew Stankevich
Resource:	Little Chess Pieces Series, SPb IFMO 2003-2004 Authumn Training Sessions
Date:	2003-10-08 
*/

/*
procedure test(row,ld,rd:longint);
var
      pos,p:longint;
begin

{ 1}  if row<>upperlim then
{ 2}  begin
{ 3}     pos:=upperlim and not (row or ld or rd);
{ 4}     while pos<>0 do
{ 5}     begin
{ 6}        p:=pos and -pos;
{ 7}        pos:=pos-p;
{ 8}        test(row+p,(ld+p)shl 1,(rd+p)shr 1);
{ 9}     end;
{10}  end
{11}  else inc(sum);

end;
*/

import java.util.*;

public class Solution {
	final int n, k;
	boolean[] c, x, y;
	int ans;

	public Solution(int n, int k) {
		this.n = n;
		this.k = k;
	}

	void gao(int i, int k) {
		if (k == 0) {
			++ans;
		} else if (i > 0) {
			--i;
			for (int j = 0; j < n; ++j) {
				if (!c[j] && !x[i + j] && !y[i + n - 1 - j]) {
					c[j] = x[i + j] = y[i + n - 1 - j] = true;
					gao(i, k - 1);
					c[j] = x[i + j] = y[i + n - 1 - j] = false;
				}
			}
			gao(i, k);
		}
	}

	public String toString() {
		ans = 0;
		c = new boolean[n];
		x = new boolean[2 * n - 1];
		y = new boolean[2 * n - 1];
		gao(n, k);
		return "" + ans;
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int k = in.nextInt();
		Solution sol = new Solution(n, k);
		System.out.println(sol);
	}
}

// 可用DancingLink?

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//874620	08.08.09 20:32	watashi	224 	.JAVA	Accepted	647 ms	2102 kb


