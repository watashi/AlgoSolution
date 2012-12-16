import java.math.*;
import java.util.*;

public class DigitSum {
	private static final BigInteger _36 = BigInteger.valueOf(36L);
	private static final BigInteger _55 = BigInteger.valueOf(55L);

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();

		System.out.println(_55.pow(n - 1).multiply(_36));
	}
}
/*
id => 4678070
date => 03:45:5816 Dec 2012
user => watashi
pname => Sum of Digits of the Sum of Numbers
lang => Java
status => Accepted
testid => 
time => 0.093
mem => 1 542 KB
pid => 1206
*/
