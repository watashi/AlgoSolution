// sgu510. Distinct Substrings

import java.util.*;

public class Solution {
    static int[] s;

    static {
        s = new int[100];
        for (int i = 1; i < s.length; ++i) {
            s[i] = s[i - 1] + i;
        }
    }

    private static class Node {
        public static final int SIGMA = 26;
        int count = 0;
        Node[] children = new Node[SIGMA];
    }

    private final int n;
    private int c, d;
    private int[] a;
    private Node trie;

    public Solution(int n) {
        this.n = n;
    }

    private void inc(int m) {
        Node p = trie;
        for (int i = m - 1; i >= 0; --i) {
            if (p.children[a[i]] == null) {
                p.children[a[i]] = new Node();
                ++c;
            }
            p = p.children[a[i]];
            ++p.count;
        }
    }

    private void dec(int m) {
        Node p = trie;
        for (int i = m - 1; i >= 0; --i) {
            Node q = p.children[a[i]];
            if (--q.count == 0) {
                p.children[a[i]] = null;
                --c;
            }
            p = q;
        }
    }

    private boolean gao(int m, int x) {
        if (c == n) {
            return true;
        } else if (c > n || c < n >> d - m || n - c > s[d] - s[m]) {
            return false;
        } else {
            for (a[m] = 0; a[m] <= x; ++a[m]) {
                inc(m + 1);
                if (gao(m + 1, Math.max(x, a[m] + 1))) {
                    return true;
                }
                dec(m + 1);
            }
            return false;
        }
    }

    public String solve() {
        for (d = 1; ; ++d) {
            a = new int[d];
            c = 0;
            trie = new Node();
            if (gao(0, 0)) {
                break;
            }
        }
        String ret = "";
        for (int i: a) {
            ret += (char)('a' + i);
        }
        return ret;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        System.out.println(new Solution(n).solve());
    }
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//1325280	24.07.12 03:57	watashi	510 	.JAVA	Accepted 	4 ms	268 kb
