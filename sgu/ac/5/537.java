// sgu537. Divisibility

import java.util.*;

public class Solution {
    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static HashMap<Long, ArrayList<Long> > divisors =
        new HashMap<Long, ArrayList<Long> >();

    static ArrayList<Long> getDivisors(long n) {
        if (divisors.get(n) == null) {
            long m = (long)Math.sqrt(n);
            ArrayList<Long> x = new ArrayList<Long>();
            ArrayList<Long> y = new ArrayList<Long>();
            for (long i = 1; i <= m; ++i) {
                if (n % i == 0) {
                    x.add(i);
                    long j = n / i;
                    if (j > i) {
                        y.add(j);
                    }
                }
            }
            Collections.reverse(y);
            x.addAll(y);
            divisors.put(n, x);
        }
        return divisors.get(n);
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int re = in.nextInt();

        for (int ri = 1; ri <= re; ++ri) {
            String s = in.next();
            ArrayList<Long> a = new ArrayList<Long>();
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                long m = 0;
                for (int i = 0; i < s.length(); ++i) {
                    m *= 10;
                    if (s.charAt(i) == ch) {
                        m += 1;
                    }
                }
                if (m > 0) {
                    a.add(m);
                }
            }

            long ans = 0;
            if (a.size() < 10) {
                for (long i: a) {
                    ans = gcd(ans, i);
                }
            } else {
                for (long i: a) {
                    for (long j: a) {
                        if (i > j) {
                            ans = gcd(ans, i - j);
                        }
                    }
                }
            }

            System.out.print("Case " + ri + ":");
            for (long i: getDivisors(ans)) {
                System.out.print(" " + i);
            }
            System.out.println();
        }
    }
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//1323062	19.07.12 00:57	watashi	537 	.JAVA	Accepted 	75 ms	548 kb

