import java.util.*;
import java.math.*;

public class Main {
	static BigInteger choose(int n, int m) {
		if (m < 0) {
			return BigInteger.ZERO;
		}
		BigInteger ret = BigInteger.ONE;
		for (int i = 0; i < m; ++i) {
			ret = ret.multiply(BigInteger.valueOf(n - i)).divide(BigInteger.valueOf(i + 1));
		}
		return ret;
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int ri = 0;
		while (in.hasNextInt()) {
			int n = in.nextInt();
			if (n == 0) {
				break;
			}
			System.out.print("Case " + ++ri + ": ");
			if (n < 4 || n % 2 != 0) {
				System.out.println(0);
			} else {
				int a = (n + 4) / 2;
				int b = (n - 4) / 2;
				System.out.println(choose(a + 1, b).subtract(choose(a - 1, b - 2)));
			}
		}
	}
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//803455 	4123 	Glenbow Museum 	Accepted 	JAVA 	0.288 	2011-05-19 10:42:05
/*
id => 1174045
pid => 4123
pname => Glenbow Museum
status => Accepted
lang => JAVA
time => 0.309
date => 2012-12-14 17:14:56
*/
