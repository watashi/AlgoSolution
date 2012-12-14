import java.util.*;
import java.math.*;

public class Main {
	static BigInteger TWO = BigInteger.valueOf(2);
	static BigInteger FIV = BigInteger.valueOf(5);
	static BigInteger MOD = BigInteger.TEN.pow(100);
	static BigInteger[] two;
	static BigInteger[] fiv;
	static BigInteger[] big;
	static BigInteger[] inv;

	static {
		int n = 10086;
		two = new BigInteger[n];
		fiv = new BigInteger[n];
		big = new BigInteger[n];
		inv = new BigInteger[n];
		two[0] = fiv[0] = BigInteger.ONE;
		big[0] = BigInteger.ZERO;
		for (int i = 1; i < n; ++i) {
			two[i] = two[i - 1].multiply(TWO).mod(MOD);
			fiv[i] = fiv[i - 1].multiply(FIV).mod(MOD);
			big[i] = BigInteger.valueOf(i);
			if (i % 2 != 0 && i % 5 != 0) {
				inv[i] = big[i].modInverse(MOD);
			}
		}
	}

	BigInteger s, t;
	int n, c2, c5;

	int gao(int m, int d) {
		while (m % 2 == 0) {
			m /= 2;
			c2 += d;
		}
		while (m % 5 == 0) {
			m /= 5;
			c5 += d;
		}
		return m;
	}

	Main(int an) {
		n = an;
		c2 = c5 = 0;
		s = t = BigInteger.ONE;
		for (int i = 1; i + i <= n; ++i) {
			int m;
			m = gao(n - i - i + 2, 1);
			t = t.multiply(big[m]).mod(MOD);
			m = gao(n - i - i + 1, 1);
			t = t.multiply(big[m]).mod(MOD);
			m = gao(i, -1);
			t = t.multiply(inv[m]).mod(MOD);
			m = gao(i + 1, -1);
			t = t.multiply(inv[m]).mod(MOD);
			s = s.add(t.multiply(two[c2]).mod(MOD).multiply(fiv[c5]).mod(MOD));
		}
		s = s.mod(MOD);
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while (in.hasNextInt()) {
			int n = in.nextInt();
			Main m = new Main(n);
			System.out.println(m.s);
		}
	}
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//798501 	5028 	Delta Wave 	Accepted 	JAVA 	1.228 	2011-05-13 09:44:58

/*
id => 1174261
pid => 5028
pname => Delta Wave
status => Accepted
lang => JAVA
time => 1.202
date => 2012-12-14 17:46:18
*/
