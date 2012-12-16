import java.math.*;
import java.util.*;

public class Timus1620 {
    public static void main (String[] args) {
	Scanner scan = new Scanner(System.in);
	int n, m, k;
	
	n = scan.nextInt();
	m = scan.nextInt();
	k = scan.nextInt();
	
	// [1] p = p / n  * (p - 1) + (1 - p / n) * (p + 1)
	// def pk = x / n ^ k;  x[k + 1] = n ^ (k + 1) + n * x - 2 * x
	// [2] Amid = n / 2; D = (n - 2) ^ k; Am - Am-1 = D;
	
	BigInteger num = new BigInteger(m + ""), den = new BigInteger(1 + ""), gcd;
	
	for (int i = 0; i < k; i++) {
	    den = den.multiply(new BigInteger(n + ""));
	    num = num.multiply(new BigInteger(n - 2 + ""));
	    num = num.add(den);
	}
	gcd = den.gcd(num);
	
	System.out.print(num.divide(gcd));
	System.out.print('/');
	System.out.print(den.divide(gcd));
	System.out.println();
    }
}

//ID	Date	Author	Problem	Language	Judgement result	Test #	Execution time	Memory used
//2201988	23:28:50    17 Aug 2008	watashi	1620	Java	Accepted	0.625	1 950 KB
/*
id => 4678658
date => 15:38:4716 Dec 2012
user => watashi
pname => Clever House
lang => Java
status => Accepted
testid => 
time => 0.312
mem => 5 798 KB
pid => 1620
*/
