import java.util.*;
import java.util.regex.*;

public class Main {
    static Pattern labelpat = Pattern.compile("\\[(\\w*)\\]");
    static HashSet<String> done;
    static HashMap<String, String> record;

    static String gao(String label) {
        String content = record.get(label);
        if (!done.contains(record)) {
            boolean needGroup = content.indexOf('|') != -1;
            HashSet<String> set = new HashSet<String>();
            Matcher m = labelpat.matcher(content);
            while (m.find()) {
                set.add(m.group(1));
            }
            for (String s : set) {
                content = content.replaceAll("\\[" + s + "\\]", gao(s));
            }
            if (needGroup) {
                content = "(?:" + content + ")";
            }
            done.add(label);
            record.put(label, content);
        }
        return content;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNextInt()) {
            int n = in.nextInt();
            done = new HashSet<String>(n);
            record = new HashMap<String, String>(n);
            for (int i = 0; i < n; ++i) {
                String[] token = in.next().split(":=");
                record.put(token[0], token[1]);
            }

            Pattern p = Pattern.compile(gao("virus"));
            System.err.println(p.pattern());

            int m = in.nextInt();
            for (int i = 0; i < m; ++i) {
                String line = in.next();
                System.out.println(p.matcher(line).find() ? "YES" : "NO");
            }
            System.out.println();
        }
    }
}

// 2012-09-07 15:55:20 | Accepted | 3440 | Java | 180 | 1282 | watashi | Source
