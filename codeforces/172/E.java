import java.io.*;
import java.util.*;

public class E {
    static class Node {
        final String tag;
        ArrayList<Node> children;

        Node(String tag) {
            this.tag = tag;
            this.children = new ArrayList<Node>();
        }

        void add(Node child) {
            children.add(child);
        }
    }

    static Node parseXML(String s) {
        ArrayList<String> tags = new ArrayList<String>();
        while (!s.isEmpty()) {
            int p = s.indexOf('>');
            String t = s.substring(1, p);
            s = s.substring(p + 1);
            if (t.startsWith("/")) {
                tags.add("-");
            } else if (t.endsWith("/")) {
                tags.add(t.substring(0, t.length() - 1));
                tags.add("-");
            } else {
                tags.add(t);
            }
        }

        Stack<Node> stack = new Stack<Node>();
        stack.push(new Node("-"));
        for (String tag: tags) {
            if (tag.equals("-")) {
                Node t = stack.pop();
                stack.peek().add(t);
            } else {
                stack.push(new Node(tag));
            }
        }
        return stack.pop();
    }

    static int query(Node p, String[] path, int pos) {
        int ret = 0;
        if (path[pos].equals(p.tag)) {
            if (pos == path.length - 1) {
                ++ret;
            } else {
                ++pos;
            }
        }
        for (Node child: p.children) {
            ret += query(child, path, pos);
        }
        return ret;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        Node xml = parseXML(in.readLine());
        int n = Integer.parseInt(in.readLine());
        for (int i = 0; i < n; ++i) {
            String[] path = in.readLine().split(" ");
            System.out.println(query(xml, path, 0));
        }
    }
}

