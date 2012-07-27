// sgu443. Everlasting...?
import java.util.*;

public class Solution {
    static TreeMap<Integer, Integer> primeDivisors(int n) {
        TreeMap<Integer, Integer> ret = new TreeMap<Integer, Integer>();
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                int j = 0;
                do {
                    ++j;
                    n /= i;
                } while (n % i == 0);
                ret.put(i, j);
            }
        }
        if (n > 1) {
            ret.put(n, 1);
        }
        return ret;
    }

    static int keyNumber(int n) {
        TreeMap<Integer, Integer> pd = primeDivisors(n);
        int ret = pd.lastKey() * 2;
        for (int i: pd.keySet()) {
            ret -= i;
        }
        return ret;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        int b = in.nextInt();
        System.out.println(keyNumber(a) > keyNumber(b) ? "a" : "b");
    }
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//1326834	26.07.12 09:35	watashi	443 	.JAVA	Accepted 	20 ms	284 kb

