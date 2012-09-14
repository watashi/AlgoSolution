import java.util.*;

class Die {
    int x, y, t, s, e;
    public Die() {
    }
    public Die(int x, int y, int t, int s, int e) {
        this.x = x;
        this.y = y;
        this.t = t;
        this.s = s;
        this.e = e;
    }
    public Die roll(int d) {
        switch (d) {
            case 0: /*(1,0)*/   return new Die(x + 1, y, 5 - s, t, e);
            case 1: /*(0,1)*/   return new Die(x, y + 1, 5 - e, s, t);
            case 2: /*(-1,0)*/  return new Die(x - 1, y, s, 5 - t, e);
            case 3: /*(0,-1)*/  return new Die(x, y - 1, e, s, 5 - t);
            default: return null;
        }
    }
    public boolean equals(Die d) {
        return x == d.x && y == d.y && t == d.t && s == d.s && e == d.e;
    }
    public int hashCode() {
        return (s * 6 + e) * 10000 + x * 100 + y;
    }
    public String toString() {
        return "(" + x + ", " + y + ")" + (t + 1) + "" + (s + 1) + "" + (e + 1);
    }
}

public class Main {
    static final int[] dx = new int[]{1, 0, -1, 0};
    static final int[] dy = new int[]{0, 1, 0, -1};

    static boolean[] mark = new boolean[36 * 100 * 100];
    static Die[] queue = new Die[24 * 100 * 100];

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNextInt()) {
            int n = in.nextInt();
            int m = in.nextInt();
            String[] map = new String[n];
            for (int i = 0; i < n; ++i) {
                map[i] = in.next();
            }
            Die start = new Die(), target = new Die();
            start.x = in.nextInt(); start.y = in.nextInt();
            target.x = in.nextInt(); target.y = in.nextInt();
            start.t = in.nextInt() - 1; in.nextInt();
            in.nextInt(); start.s = in.nextInt() - 1;
            in.nextInt(); start.e = in.nextInt() - 1;
            target.t = in.nextInt() - 1; in.nextInt();
            in.nextInt(); target.s = in.nextInt() - 1;
            in.nextInt(); target.e = in.nextInt() - 1;
            int begin = 0, end = 1, dist = 0;
            if (start.equals(target)) {
                end = -1;
            }
            Arrays.fill(mark, false);
            mark[start.hashCode()] = true;
            queue[0] = start;
    bfs:
            while (begin < end) {
                int mid = end;
                ++dist;
                while (begin < mid) {
                    Die cur = queue[begin++];
                    // System.err.println(cur);
                    for (int d = 0; d < 4; ++d) {
                        Die tmp = cur.roll(d);
                        if (tmp.equals(target)) {
                            end = -1;
                            break bfs;
                        }
                        try {
                            if (map[tmp.x].charAt(tmp.y) == '.' && !mark[tmp.hashCode()]) {
                                mark[tmp.hashCode()] = true;
                                queue[end++] = tmp;
                            }
                        } catch (IndexOutOfBoundsException e) {
                        }
                    }
                }
            }
            if (end != -1) {
                dist = -1;
            }
            System.out.println(dist);
        }
    }
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1806121   2009-03-27 01:36:46     Accepted    3059    Java    0   7888    watashi@Zodiac

/*
 * ZOJ BUG
 */

// 2012-09-07 01:59:11 | Accepted | 3059 | Java | 490 | 18716 | watashi | Source
