import java.util.*;
import java.math.*;

public class Cocktail {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		BigInteger a = BigInteger.valueOf(n), s = BigInteger.ZERO;

		for (int i = n - 1; i >= 1; i--) {
			a = a.multiply(BigInteger.valueOf(i));
			s = s.add(a);
		}
		System.out.println(s);
	}
}
/*
id => 4678347
date => 12:20:0516 Dec 2012
user => watashi
pname => Cocktails
lang => Java
status => Accepted
testid => 
time => 0.093
mem => 1 542 KB
pid => 1402
*/
