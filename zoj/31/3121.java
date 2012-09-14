import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        while (in.hasNextInt()) {
            int n = in.nextInt();
            String[] s = new String[n];

            for (int i = 0; i < s.length; ++i) {
                s[i] = in.next();
            }

            int l = s[0].length();
            char[] c = new char[n * l];
            int m;

            m = n * l;
            for (int i = 0; i < l; ++i) {
                for (int j = 0; j < n; ++j) {
                    c[--m] = s[j].charAt(i);
                    if (c[m] == '_') {
                        c[m] = ' ';
                    } else if (c[m] == '\\') {
                        c[m] = '\n';
                    }
                }
            }
            m = n * l;
            while (m > 0 && c[m - 1] == ' ') {
                --m;
            }

            System.out.println(new String(c, 0, m) + "\n");
        }
    }
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1749898   2009-01-28 01:12:28     Accepted    3121    Java    0   182     watashi@Zodiac

// 2012-09-07 02:02:14 | Accepted | 3121 | Java | 40 | 252 | watashi | Source
