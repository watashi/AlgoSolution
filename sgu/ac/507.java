// sgu507. Treediff
import java.io.*;
import java.util.*;

public class Solution {
    static int nextInt() throws IOException {
        int ch = -1;
        do {
            ch = System.in.read();
        } while (Character.isWhitespace(ch));
        boolean negative = (ch == '-');
        if (negative) {
            ch = System.in.read();
        }
        int ret = 0;
        while (Character.isDigit(ch)) {
            ret *= 10;
            ret += Character.digit(ch, 10);
            ch = System.in.read();
        }
        return negative ? -ret : ret;
    }

    static class Node {
        Node p = null;
        int d = 0, x = Integer.MAX_VALUE;
        TreeSet<Integer> ts = new TreeSet<Integer>();
    }

    public static void main(String[] args) throws IOException {
        int n = nextInt();
        int m = nextInt();
        Node[] v = new Node[n];
        for (int i = 0; i < n; ++i) {
            v[i] = new Node();
        }
        for (int i = 1; i < n; ++i) {
            int p = nextInt() - 1;
            v[i].p = v[p];
            ++v[p].d;
        }

        Stack<Node> q = new Stack<Node>();
        for (int i = n - m; i < n; ++i) {
            int x = nextInt();
            v[i].ts.add(x);
            q.add(v[i]);
        }

        while (!q.isEmpty()) {
            Node c = q.pop();
            if (c.p != null) {
                Node p = c.p;
                if (--p.d == 0) {
                    q.push(p);
                }

                TreeSet<Integer> a, b;
                if (p.ts.size() > c.ts.size()) {
                    a = p.ts;
                    b = c.ts;
                } else {
                    a = c.ts;
                    b = p.ts;
                }

                p.x = Math.min(p.x, c.x);
                for (int i: b) {
                    if (p.x == 0) {
                        break;
                    } else {
                        Integer j;
                        j = a.floor(i);
                        if (j != null) {
                            p.x = Math.min(p.x, i - j);
                        }
                        j = a.ceiling(i);
                        if (j != null) {
                            p.x = Math.min(p.x, j - i);
                        }
                    }
                }
                if (p.x == 0) {
                    p.ts.clear();
                } else {
                    a.addAll(b);
                    p.ts = a;
                }
            }
        }

        for (int i = 0; i < n - m; ++i) {
            if (i > 0) {
                System.out.print(' ');
            }
            System.out.print(v[i].x);
        }
        System.out.println();
    }
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//1326831	26.07.12 09:16	watashi	507 	.JAVA	Accepted 	129 ms	584 kb

