import java.io.*;
import java.util.*;

public class Staircase {
	static final int N = 512;

	public static void main(String[] args) {
		long[][] q = new long[N + 1][N + 1];

		q[0][0] = 1L;
		for (int i = 0; i <= N; i++) {
			for (int j = 1; j <= i; j++) {
				q[i][j] += q[i - j][j - 1];
			}
			for (int j = 1; j <= N; j++) {
				q[i][j] += q[i][j - 1];
			}
		}

		Scanner scan = new Scanner(new BufferedInputStream(System.in));

		while (scan.hasNextInt()) {
			int n = scan.nextInt();

			System.out.println(q[n][n] - 1L);
		}
	}
}
/*
id => 4677345
date => 18:02:5215 Dec 2012
user => watashi
pname => Staircases
lang => Java
status => Accepted
testid => 
time => 0.125
mem => 3 518 KB
pid => 1017
*/
