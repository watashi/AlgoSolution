import java.io.*;
import java.util.*;

public class Main {
    static final int OFFSET = 128;
    static final int MAXLEN = 256;

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int re = Integer.parseInt(in.readLine());
        ArrayList<ArrayList<Integer> > aa = new ArrayList<ArrayList<Integer> >(MAXLEN);

        for (int i = 0; i < MAXLEN; ++i) {
            aa.add(null);
        }
        for (int ri = 1; ri <= re; ++ri) {
            int x = 0, y = 0, s = 0;

            for (int i = 0; i < aa.size(); ++i) {
                aa.set(i, new ArrayList<Integer>());
            }
            for (char c : in.readLine().toCharArray()) {
                switch (c) {
                    case 'U': --y; break;
                    case 'D': ++y; break;
                    case 'L': --x; aa.get(x + OFFSET).add(new Integer(y)); break;
                    case 'R': aa.get(x + OFFSET).add(new Integer(y)); ++x; break;
                }
            }
            for (int i = 0; i < aa.size(); ++i) {
                Collections.sort(aa.get(i));
            }
            for (ArrayList<Integer> a : aa) {
                for (int i = 0; i < a.size(); i += 2) {
                    s += a.get(i + 1) - a.get(i);
                }
            }
            System.out.println("case " + ri + ": " + s);
        }
    }
}

/*
Run ID      Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
1749891     2009-01-28 00:49:26     Accepted    3107    Java    0   378     watashi@Zodiac
*/

// 2012-09-07 02:01:37 | Accepted | 3107 | Java | 30 | 519 | watashi | Source
