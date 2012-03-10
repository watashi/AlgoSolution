// SGU208. Toral Tickets
/*
208. Toral Tickets
time limit per test: 2 sec.
memory limit per test: 65536 KB
input: standard
output: standard



On the planet Eisiem passenger tickets for the new mean of transportation are planned to have the form of tores.

Each tore is made of a single rectangular black rubber sheet containing N × M squares. Several squares are marked with white, thus encoding the ticket's source and destination.

When the passenger buys the ticket, the ticket booking machine takes the rubber sheet, marks some squares to identify the route of the passenger, and then provides it to the passenger. The passenger next must glue the ticket.

The ticket must be clued the following way. First two its sides of greater length are glued together, forming a cylinder. Next cylinder base circles, each of which has the length equal to the length of the short side of the original rubber sheet, are glued together. They must be glued in such a way, that the cells, sides of which are glued, first belonged to the same row of the sheet. Note that the inner and the outer part of the sheet can be distinguished.

The resulting tore is the valid ticket.

Note that if the original sheet is square, there are two topologically different ways to make a tore out of a rubber sheet.

Ticket material is so perfect and gluing quality is so fine, that no one is able to find the seam, and this leads to some problems. First, the same tore can be obtained using different sheets. More of that, the same sheet can lead to tores that look a bit different.

Now the transport companies of Eisiem wonder, how many different routes they can organize, so that the following conditions are satisfied:


    * tickets for different routes are represented by different tores;
    * if some rubber sheet was marked to make the tore for some route, it cannot be used to make the tore for another route.



Help them to calculate the number of routes they can organize.

Input
The first line of the input file contains N and M (1 ≤ N, M ≤ 20).

Output
Output the number of routes Eisiem transport companies can organize.

Sample test(s)

Input

Test #1

2 2

Test #2

2 3

Output

Test #1

6

Test #2

13
[submit]
[forum]
Author:	Andrew Stankevich
Resource:	Petrozavodsk Summer Trainings 2003
Date:	2003-08-23

*/
import java.math.*;
import java.util.*;

public class Solution {
	private static BigInteger TWO = BigInteger.valueOf(2);
	private static boolean[] mark = new boolean[512];
	public static int cyclic(int[] p) {
		int ret = 0;
		Arrays.fill(mark, 0, p.length, false);
		for (int i = 0; i < p.length; ++i) {
			if (!mark[i]) {
				++ret;
				for (int j = i; !mark[j]; j = p[j]) {
					mark[j] = true;
				}
			}
		}
		return ret;
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		int nm = n * m;
		int[][] p;
		if (n == m) {
			p = new int[4][nm];
		} else {
			p = new int[2][nm];
		}
		BigInteger num = BigInteger.ZERO;
		int den = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				for (int k = 0; k < nm; ++k) {
					int x = ((k / m) + i) % n;
					int y = ((k % m) + j) % m;
					p[0][k] = x * m + y;
					p[1][k] = (n - 1 - x) * m + (m - 1 - y);
					if (n == m) {
						p[2][k] = y * m + (m - 1 - x);
						p[3][k] = (n - 1 - y) * m + x;
					}
				}
				for (int[] pp : p) {
					num = num.add(TWO.pow(cyclic(pp)));
					++den;
				}
			}
		}
		num = num.divide(BigInteger.valueOf(den));
		System.out.println(num);
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//887917	16.09.09 22:51	watashi	208 	.JAVA	Accepted	82 ms	0 kb

