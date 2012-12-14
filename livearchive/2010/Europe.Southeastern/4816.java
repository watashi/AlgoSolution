import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while (in.hasNextInt()) {
			int m = in.nextInt();
			int n = in.nextInt();
			BigInteger[] a = new BigInteger[m];
			Arrays.fill(a, BigInteger.ONE);
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					BigInteger b = in.nextBigInteger();
					a[j] = a[j].multiply(b);
				}
			}
			int k = 0;
			for (int i = 0; i < m; ++i) {
				if (a[i].compareTo(a[k]) >= 0) {
					k = i;
				}
			}
			System.out.println(k + 1);
		}
	}
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//910236 	4816 	The Table 	Accepted 	JAVA 	1.680 	2011-10-18 10:36:12
/*
id => 1174361
pid => 4816
pname => The Table
status => Accepted
lang => JAVA
time => 1.048
date => 2012-12-14 18:02:05
*/
