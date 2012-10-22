// SGU271. Book Pile
/*
271. Book Pile
time limit per test: 1 sec.
memory limit per test: 65536 KB
input: standard
output: standard



There is a pile of N books on the table. Two types of operations are performed over this pile:
- a book is added to the top of the pile,
- top K books are rotated. If there are less than K books on the table, the whole pile is rotated.
First operation is denoted as ADD(S) where S is the name of the book, and the second operations is denoted as ROTATE.
The maximum number of books is no more than 40000. All book names are non-empty sequences of no more than 3 capital Latin letters. The names of the books can be non-unique.

Input
The first line of input file contains 3 integer numbers N, M, K (0 <= N <= 40000; 0 <= M <= 100000; 0 <= K <= 40000). The following N lines are the names of the books in the pile before performing any operations. The book names are given in order from top book to bottom. Each of the following M lines contains the operation description.

Output
Output the sequence of books names in the pile after performing all operations. First line corresponds to the top book.

Sample test(s)

Input

2 3 2
A
B
ADD(C)
ROTATE
ADD(D)

Output

D
A
C
B
[submit]
[forum]
Author:	Michael R. Mirzayanov
Resource:	ACM ICPC 2004-2005, NEERC, Southern Subregional Contest
Date:	Saratov, October 7, 2004 
*/
import java.io.*;
import java.util.*;

class BookPile {
	final int k;
	boolean rotated;
	LinkedList<String> top, bottom;

	BookPile(int k) {
		this.k = k;
		this.rotated = false;
		top = new LinkedList<String>();
		bottom = new LinkedList<String>();
	}

	void add(String s) {
		if (rotated) {
			top.addLast(s);
		} else {
			top.addFirst(s);
		}
	}

	void rotate() {
		if (rotated) {
			while (top.size() > k) {
				bottom.addFirst(top.pollFirst());
			}
		} else {
			while (top.size() > k) {
				bottom.addFirst(top.pollLast());
			}
		}
		rotated = !rotated;
	}

	void print(PrintStream out) {
		Iterator<String> it = rotated ? top.descendingIterator() : top.listIterator();
		while (it.hasNext()) {
			out.println(it.next());
		}
		for (String str : bottom) {
			out.println(str);
		}
	}
}

public class Solution {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String[] inputs = in.readLine().split(" ");
		int n = Integer.parseInt(inputs[0]);
		int m = Integer.parseInt(inputs[1]);
		int k = Integer.parseInt(inputs[2]);
		BookPile bp = new BookPile(k);
		for (int i = 0; i < n; ++i) {
			bp.top.addLast(in.readLine());
			// bp.add(in.readLine());
		}
		// bp.rotate();	// n > k => WA19
		for (int i = 0; i < m; ++i) {
			String str = in.readLine();
			if (str.charAt(0) == 'A') {
				bp.add(str.substring(4, str.length() - 1));
			} else {
				bp.rotate();
			}
		}
		bp.print(System.out);
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//874700	09.08.09 10:12	watashi	271 	.JAVA	Accepted	301 ms	5258 kb
