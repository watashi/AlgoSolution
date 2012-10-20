// SGU203. Hyperhuffman
/*
203. Hyperhuffman
time limit per test: 2 sec.
memory limit per test: 65536 KB
input: standard
output: standard



You might have heard about Huffman encoding — that is the coding system that minimizes the expected length of the text if the codes for characters are required to consist of an integral number of bits.

Let us recall codes assignment process in Huffman encoding. First the Huffman tree is constructed. Let the alphabet consist of N characters, i-th of which occurs Pi times in the input text. Initially all characters are considered to be active nodes of the future tree, i-th being marked with Pi. On each step take two active nodes with smallest marks, create the new node, mark it with the sum of the considered nodes and make them the children of the new node. Then remove the two nodes that now have parent from the set of active nodes and make the new node active. This process is repeated until only one active node exists, it is made the root of the tree.

Note that the characters of the alphabet are represented by the leaves of the tree. For each leaf node the length of its code in the Huffman encoding is the length of the path from the root to the node. The code itself can be constrcuted the following way: for each internal node consider two edges from it to its children. Assign 0 to one of them and 1 to another. The code of the character is then the sequence of 0s and 1s passed on the way from the root to the leaf node representing this character.

In this problem you are asked to detect the length of the text after it being encoded with Huffman method. Since the length of the code for the character depends only on the number of occurences of this character, the text itself is not given — only the number of occurences of each character. Characters are given from most rare to most frequent.

Note that the alphabet used for the text is quite huge — it may contain up to 500 000 characters.


Input
The first line of the input file contains N — the number of different characters used in the text (2 ≤ N ≤ 500,000). The second line contains N integer numbers Pi — the number of occurences of each character (1 ≤ Pi ≤ 109, Pi ≤ Pi + 1 for all valid i).

Output
Output the length of the text after encoding it using Huffman method, in bits.

Sample test(s)

Input

3
1 1 4

Output

8
[submit]
[forum]
Author:	Andrew Stankevich
Resource:	Petrozavodsk Summer Trainings 2003
Date:	2003-08-23 
*/
import java.io.*;

// [module] PriorityQueue
class PriorityQueue {
	int n;
	long[] a;

	public PriorityQueue(int capacity) {
		n = 1;
		a = new long[capacity + 1];
	}

	public void add(long v) {
		int p = n++, q;
		while (p > 1) {
			q = p >> 1;
			if (a[q] <= v) {
				break;
			} else {
				a[p] = a[q];
				p = q;
			}
		}
		a[p] = v;
	}

	public long poll() {
		long ret = a[1], v = a[--n];
		int p = 1, l, r;
		while (true) {
			l = p << 1;
			r = l ^ 1;
			if (l >= n) {
				break;
			} else if (r == n || a[l] <= a[r]) {
				if (v <= a[l]) {
					break;
				} else {
					a[p] = a[l];
					p = l;
				}
			} else {
				if (v <= a[r]) {
					break;
				} else {
					a[p] = a[r];
					p = r;
				}
			}
		}
		a[p] = v;
		return ret;
	}
}

public class Solution {
	static int nextInt() throws IOException {
		int ch = -1;
		do {
			ch = System.in.read();
		} while (!Character.isDigit(ch));
		int ret = 0;
		while (Character.isDigit(ch)) {
			ret *= 10;
			ret += Character.digit(ch, 10);
			ch = System.in.read();
		}
		return ret;
	}

	public static void main(String[] args) throws IOException {
		int n = nextInt();
//		PriorityQueue<Long> pq = new PriorityQueue<Long>(n);	// TLE18
		PriorityQueue pq = new PriorityQueue(n);
		for (int i = 0; i < n; ++i) {
			pq.add((long)nextInt());
		}
		long ans = 0;
		for (int i = 1; i < n; ++i) {
			long tmp = 0;
			tmp += pq.poll();
			tmp += pq.poll();
			ans += tmp;
			pq.add(tmp);
		}
		System.out.println(ans);
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//873779	04.08.09 20:52	watashi	203 	.JAVA	Accepted	840 ms	4190 kb

