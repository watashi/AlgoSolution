// SGU127. Telephone directory
/*
127. Telephone directory

time limit per test: 0.50 sec.
memory limit per test: 4096 KB

CIA has decided to create a special telephone directory for its agents. The first 2 pages of the directory contain the name of the directory and instructions for agents, telephone number records begin on the third page. Each record takes exactly one line and consists of 2 parts: the phone number and the location of the phone. The phone number is 4 digits long. Phone numbers cannot start with digits 0 and 8. Each page of the telephone directory can contain not more then K lines. Phone numbers should be sorted in increasing order. For the first phone number with a new first digit, the corresponding record should be on a new page of the phone directory. You are to write a program, that calculates the minimal number P pages in the directory. For this purpose, CIA gives you the list of numbers containing N records, but since the information is confidential, without the phones locations.

Input

The first line contains a natural number K (0 < K < 255) - the maximum number of lines that one page can contain. The second line contains a natural N (0 < N < 8000) - number of phone numbers supplied. Each of following N lines contains a number consisting of 4 digits - phone numbers in any order, and it is known, that numbers in this list cannot repeat.

Output

First line should contain a natural number P - the number of pages in the telephone directory.

Sample Input

5
10
1234
5678
1345
1456
1678
1111
5555
6789
6666
5000

Sample Output

5

Author	: Alex Y. Suslov, Victor G. Samoilov, Natalia L. Andreeva
Resource	: 5th Southern Subregional Contest. Saratov 2002
Date	: 2002-10-10
*/

import java.io.*;

public class Solution {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int k = Integer.parseInt(in.readLine());
		int n = Integer.parseInt(in.readLine());
		int a[] = new int[10];
		for (int i = 0; i < n; ++i) {
			++a[Character.digit(in.readLine().charAt(0), 10)];
		}
		int ans = 2;
		for (int i : a) {
			ans += (i + k - 1) / k;
		}
		System.out.println(ans);
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//866714	04.07.09 18:33	watashi	127 	.JAVA	Accepted	0 ms	962 kb


