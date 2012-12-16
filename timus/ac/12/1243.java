import java.io.*;
import java.math.*;

public class Divorce {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BigInteger n = new BigInteger(in.readLine());

		System.out.println(n.mod(BigInteger.valueOf(7)));
	}
}
/*
id => 4678075
date => 03:47:2616 Dec 2012
user => watashi
pname => Divorce of the Seven Dwarfs
lang => Java
status => Accepted
testid => 
time => 0.078
mem => 478 KB
pid => 1243
*/
