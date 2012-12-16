// Catalan (separated by zeros);
// C(n, floor(n));

import java.math.*;
import java.util.*;

public class Timus1625 {
    private static BigInteger Catalan(int n) {
	BigInteger ret = BigInteger.valueOf(1);
	
	for (int i = 1; i <= n; i++) {
	    ret = ret.multiply(BigInteger.valueOf(n + i));
	    ret = ret.divide(BigInteger.valueOf(i));
	}
	
	return ret.divide(BigInteger.valueOf(n + 1));
    }
    
    public static void main(String[] args) {    
	Scanner scan = new Scanner(System.in);
	int n = scan.nextInt();
	
	for (int i = 0; i < n; i++) {
	    if (i > 0) {
		System.out.println(BigInteger.ZERO);
	    }
	    System.out.println(Catalan(i));
	}
    }
}

//ID	Date	Author	Problem	Language	Judgement result	Test #	Execution time	Memory used
//2201995	23:46:35    17 Aug 2008	watashi	1625	Java	Accepted	0.218	1 806 KB
/*
id => 4678660
date => 15:39:0716 Dec 2012
user => watashi
pname => Hankel Matrix
lang => Java
status => Accepted
testid => 
time => 0.125
mem => 3 894 KB
pid => 1625
*/
