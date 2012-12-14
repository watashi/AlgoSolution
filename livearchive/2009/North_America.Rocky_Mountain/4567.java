import java.util.*;
import java.math.*;

public class Main {
	static BigInteger[] extGcd(BigInteger a, BigInteger b) {
		if (b.signum() == 0) {
			return new BigInteger[]{a, BigInteger.ONE, BigInteger.ZERO};
		} else {
			BigInteger[] g = extGcd(b, a.mod(b));
			return new BigInteger[]{g[0], g[2], g[1].subtract(a.divide(b).multiply(g[2]))};
		}
	}

	static BigInteger[] modLinear(BigInteger[] u, BigInteger[] v) throws Exception {
		BigInteger[] g = extGcd(u[1], v[1]);
		BigInteger z = u[0].subtract(v[0]);
		if (z.mod(g[0]).signum() != 0) {
			throw new Exception("No Solution");
		} else {
		//	z = g[1].multiply(z.divide(g[0]));
			z = g[2].multiply(z.divide(g[0]));
			BigInteger[] ret = new BigInteger[]{
				v[0].add(v[1].multiply(z)),
				u[1].divide(g[0]).multiply(v[1])
			};
			ret[0] = ret[0].mod(ret[1]);
			return ret;
		}
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n;
		while (in.hasNextInt() && (n = in.nextInt()) != 0) {
			int[] p = new int[n];
			int[] q = new int[n];
			for (int i = 0; i < n; ++i) {
				p[i] = in.nextInt() - 1;
			}
			for (int i = 0; i < n; ++i) {
				q[i] = in.nextInt() - 1;
			}

			try {
				for (int i = 0; i < n; ++i) {
					if (p[q[i]] != q[p[i]]) {
						throw new Exception("Impossible");
					}
				}
				BigInteger[] w = new BigInteger[]{BigInteger.ZERO, BigInteger.ONE};
				for (int i = 0; i < n; ++i) {
					if (p[i] == -1) {
						continue;
					}
					BigInteger[] ww = new BigInteger[2];
					int j = i, k = 0;
//					System.err.print("[" + q[i] + "]");
					do {
//						System.err.print("->" + j);
						if (j == q[i]) {
							ww[0] = BigInteger.valueOf(k);
						}
						int jj = p[j];
						p[j] = -1;
						j = jj;
						++k;
					} while (j != i);
//					System.err.println();
					ww[1] = BigInteger.valueOf(k);
//					System.err.println("\t" + ww[0] + " " + ww[1]);
					w = modLinear(w, ww);
//					System.err.println(w[0] + " " + w[1]);
				}
				System.out.println(w[0]);
			} catch (Exception ex) {
				System.out.println(-1);
			}
		}
	}
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//805861 	4567 	Shuffling 	Accepted 	JAVA 	1.288 	2011-05-23 13:54:55
/*
id => 1174239
pid => 4567
pname => Shuffling
status => Accepted
lang => JAVA
time => 1.376
date => 2012-12-14 17:43:20
*/
