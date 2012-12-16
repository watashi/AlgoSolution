import java.util.*;

public class Domino {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		long n = scan.nextLong();
		long s = n * (n + 1) * (n + 2) / 2;

		System.out.println(s);
	}
}
/*
id => 4678355
date => 12:21:5316 Dec 2012
user => watashi
pname => Domino Dots
lang => Java
status => Accepted
testid => 
time => 0.093
mem => 1 434 KB
pid => 1502
*/
