import java.util.*;

public class Timus1619 {
    public static void main(String[] args) {
	Scanner scan = new Scanner(System.in);
	int n, k, m;
	
	n = scan.nextInt();
	while (n-- > 0) {
	    k = scan.nextInt();
	    m = scan.nextInt();
	    if (k < m) {
		System.out.println("0");
	    }
	    else {
		// C(k + m, m) - C(k + m, m - 1)
		System.out.println(1.0 - m / (k + 1.0));
	    }
	}
    }
}

//ID	Date	Author	Problem	Language	Judgement result	Test #	Execution time	Memory used
//2201961	22:56:22    17 Aug 2008	watashi	1619	Java	Accepted	0.281	1 834 KB
/*
id => 4678655
date => 15:38:3016 Dec 2012
user => watashi
pname => Big Brother
lang => Java
status => Accepted
testid => 
time => 0.14
mem => 5 578 KB
pid => 1619
*/
