// SGU424. Beautiful graph
/*
424. Beautiful graph
Time limit per test: 4 second(s)
Memory limit: 262144 kilobytes
input: standard
output: standard


Misha is currently interested in undirected graphs that contain no two simple cycles sharing exactly one edge and contains no loops. Let's call them beautiful graphs. He wants to find the maximal beatiful graph, that is the beautiful graph that contains the most edges among all beautiful graphs with at most vertices. But Misha is going to leave on vacation, so he asked you to help him with this problem.

Input
The input file contains a single integer () — the maximum number of vertices your graph can contain.

Output
Output the number of vertices () and the number of edges of your graph to the first line of the output file, separated with a space. Then output lines with two integer numbers each, again separated with a space. The two numbers should be the numbers of the vertices connected by the corresponding edge. The vertices of the graph are numbered from to . You can output edges in any order. If there are several maximal graphs, output any.

Example(s)

sample input

	

sample output

1

	

1 0


sample input

	

sample output

2

	

2 1
1 2


sample input

	

sample output

3

	

3 3
1 2
2 3
1 3

*/

/*
import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = (n - 1) + (n - 1) / 2;
		System.out.println(n + " " + m);
		for (int i = 2; i <= n; ++i) {
			System.out.println("1 " + i);
			if (i % 2 != 0) {
				System.out.println((i - 1) + " " + i);
			}
		}
	}
}
// WA6
*/

// *exactly* one edge!!

import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		if (n == 1) {
			System.out.println("1 0");
		} else if (n == 2) {
			System.out.println("2 1\n1 2");
		} else if (n == 3) {
			System.out.println("3 3\n1 2\n2 3\n1 3");
		} else {
			int m = 2 * (n - 2);
			System.out.println(n + " " + m);
			for (int i = 3; i <= n; ++i) {
				System.out.println(i + " 1\n2 " + i);
			}
		}
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//874719	09.08.09 11:17	watashi	424 	.JAVA	Accepted	7 ms	2090 kb

