// Th + 归纳法

import java.math.*;
import java.util.*;

public class StoneGame {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		BigInteger n = new BigInteger(scan.next());
		int m = n.mod(BigInteger.valueOf(3)).intValue();

		if (m != 0) {
			System.out.println("1\n" + m);
		}
		else {
			System.out.println("2");
		}
	}
}
/*
id => 4678067
date => 03:45:0516 Dec 2012
user => watashi
pname => Stone Game
lang => Java
status => Accepted
testid => 
time => 0.093
mem => 1 490 KB
pid => 1180
*/
