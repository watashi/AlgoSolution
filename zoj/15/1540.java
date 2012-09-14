// Tire G
// AC A
// Aho-Corasick A

/*
 * WA11
2 5 3
01
0
11
10001
*/

import java.io.*;
import java.math.*;
import java.util.*;

class Censored {
    class Node {
        private BigInteger b;
        private boolean tag;
        private Node fail;
        private Node[] p;

        public Node() {
            tag = false;
            fail = null;
            p = new Node[size];
        }
    }

    private int size;
    private Node root;
    private ArrayList<Node> nodes;
    private HashMap<Character, Integer> map;

    private void add(Node p, String str, int pos) {
        if (pos == str.length()) {
            p.tag = true;
        } else {
            int i = map.get(str.charAt(pos));
            if (p.p[i] == null) {
                p.p[i] = new Node();
                nodes.add(p.p[i]);
            }
            add(p.p[i], str, pos + 1);
        }
    }

    // no dfs, bfs!
    private void build() {
        Node[] q = new Node[nodes.size()];
        int begin, end;
        begin = end = 0;
        root.fail = root;
        for (int i = 0; i < size; ++i) {
            if (root.p[i] != null) {
                root.p[i].fail = root;
                q[end++] = root.p[i];
            } else {
                root.p[i] = root;
            }
        }
        while (begin < end) {
            Node p = q[begin++];
            for (int i = 0; i < size; ++i) {
                if (p.p[i] != null) {
                    p.p[i].fail = p.fail.p[i];
                    q[end++] = p.p[i];
                } else {
                    p.p[i] = p.fail.p[i];
                }
            }
        }
    }

    public Censored(char[] letters, String[] patterns) {
        size = 0;
        map = new HashMap<Character, Integer>(letters.length);
        for (char letter : letters) {
            map.put(letter, size++);
        }
        root = new Node();
        nodes = new ArrayList<Node>();
        nodes.add(root);
        // !!
        for (int i = 0; i < patterns.length; ++i) {
            for (int j = 0; j < i; ++j) {
                if (patterns[i] == null || patterns[j] == null) {
                    continue;
                } else if (patterns[i].indexOf(patterns[j]) != -1) {
                    patterns[i] = null;
                } else if (patterns[j].indexOf(patterns[i]) != -1) {
                    patterns[j] = null;
                }
            }
        }
        //
        for (String pattern : patterns) {
            if (pattern != null) {
                add(root, pattern, 0);
            }
        }
        build();
    }

    public BigInteger solve(int length) {
        for (Node node : nodes) {
            node.b = BigInteger.ZERO;
        }
        root.b = BigInteger.ONE;
        while (--length >= 0) {
            BigInteger[] dp = new BigInteger[nodes.size()];
            for (int i = 0; i < dp.length; ++i) {
                dp[i] = nodes.get(i).b;
                nodes.get(i).b = BigInteger.ZERO;
            }
            for (int i = 0; i < dp.length; ++i) {
                if (nodes.get(i).tag) {
                    continue;
                } else {
                    for (Node node : nodes.get(i).p) {
                        node.b = node.b.add(dp[i]);
                    }
                }
            }
        }
        BigInteger ans = BigInteger.ZERO;
        for (Node node : nodes) {
            if (!node.tag) {
                ans = ans.add(node.b);
            }
        }
        return ans;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        while (in.hasNextInt()) {
            int n = in.nextInt();
            int m = in.nextInt();
            int p = in.nextInt();
            String s = in.next();
            String[] words = new String[p];
            for (int i = 0; i < p; ++i) {
                words[i] = in.next();
            }
            Censored solution = new Censored(s.toCharArray(), words);
            System.out.println(solution.solve(m));
        }
    }
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1820204   2009-04-05 22:29:11     Accepted    1540    Java    0   353     watashi@Zodiac

// 2012-09-07 00:53:06 | Accepted | 1540 | Java | 190 | 10353 | watashi | Source
