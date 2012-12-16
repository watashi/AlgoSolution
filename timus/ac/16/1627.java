import java.math.*;
import java.util.*;

public class Timus1627 {
    static final int[] dx = new int[]{0, 1, 0, -1};
    static final int[] dy = new int[]{1, 0, -1, 0};
    
    private static BigInteger det(int n, int[][] m) {
        if (n <= 0) {
            return new BigInteger("1"); // not ZERO
        }
        
        BigInteger[][] a = new BigInteger[n][n];
        BigInteger num = new BigInteger("1"), den = new BigInteger("1");
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = BigInteger.valueOf(m[i][j]);
            }
        }
        for (int k = 0; k < n; k++) {
            int index = -1;
            
            for (int i = k; i < n; i++) {
                if (!a[i][k].equals(BigInteger.ZERO)) {
                    index = i;
                    break;
                }
            }
            if (index == -1) {
                return new BigInteger("0");
            }
            
            if (index != k) {          
                for (int j = k; j < n; j++) {
                    BigInteger tmp = a[k][j];
                    a[k][j] = a[index][j];
                    a[index][j] = tmp;
                }
            }
            num = num.multiply(a[k][k]);
                        
            for (int i = k + 1; i < n; i++) {
                if (a[i][k].equals(BigInteger.ZERO)) {
                    continue;
                }
                BigInteger lcm = a[k][k].multiply(a[i][k]).divide(a[k][k].gcd(a[i][k]));
                BigInteger x = lcm.divide(a[i][k]);
                BigInteger y = lcm.divide(a[k][k]);
                den = den.multiply(x);
                for (int j = k + 1; j < n; j++) {
                    a[i][j] = a[i][j].multiply(x).subtract(a[k][j].multiply(y));
                }
            }
        }
        
        return num.divide(den).abs();
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt(), m = scan.nextInt(), c;
        int[][] id = new int[n][m];
        String[] s = new String[n];
        
        c = 0;
        for (int i = 0; i < n; i++) {
            s[i] = scan.next();
            for (int j = 0; j < m; j++) {
                if (s[i].charAt(j) == '*') {
                    id[i][j] = -1;
                }
                else {
                    id[i][j] = c++;
                }
            }
        }
        
        int[][] a = new int[c][c];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s[i].charAt(j) == '*') {
                    continue;
                }
                for (int k = 0; k < 4; k++) {
                    try {
                        if (s[i + dx[k]].charAt(j + dy[k]) == '.') {
                            a[id[i][j]][id[i + dx[k]][j + dy[k]]] = -1;
                            ++a[id[i][j]][id[i][j]];
                        }
                    }
                    catch (Exception e) {
                    }
                }
            }
        }        
        System.out.println(det(c - 1, a).mod(BigInteger.valueOf(1000000000)));        
    }
}

//ID	Date	Author	Problem	Language	Judgement result	Test #	Execution time	Memory used
//2203542	04:16:49    19 Aug 2008	watashi	1627	Java	Accepted    	0.812	2 202 KB
/*
id => 4678661
date => 15:39:2816 Dec 2012
user => watashi
pname => Join
lang => Java
status => Accepted
testid => 
time => 0.343
mem => 6 170 KB
pid => 1627
*/
