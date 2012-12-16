import java.util.*;

public class Sum {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = 2 * scan.nextInt();
		int m = (int)Math.sqrt(n);
		int p = 0;

		for (int i = 1; i <= m; i++) {
			if ((n % i == 0) && (n / i - i + 1) % 2 == 0) {
				p = i;
			}
		}
		System.out.println((n / p - p + 1) / 2 + " " + p);
	}
}
/*
id => 4677354
date => 18:05:0315 Dec 2012
user => watashi
pname => Sum of Sequential Numbers
lang => Java
status => Accepted
testid => 
time => 0.093
mem => 1 450 KB
pid => 1120
*/
