import java.util.*;

public class Copying {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		long n = scan.nextLong(), k = scan.nextLong(), c = 1, t = 0;

		while (c < n && c < k) {
			c *= 2;
			++t;
		}
		if (c < n) {
			t += (n - c + k - 1) / k;
		}
		System.out.println(t);
	}
}
/*
id => 4678063
date => 03:43:5116 Dec 2012
user => watashi
pname => Copying
lang => Java
status => Accepted
testid => 
time => 0.093
mem => 1 438 KB
pid => 1131
*/
