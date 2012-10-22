// SGU538. Emoticons

import java.io.*;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String s = in.readLine();
        boolean b = false;
        int ans = 0;
        for (char c: s.toCharArray()) {
            if (c == '(') {
                if (b) {
                    ++ans;
                }
                b = true;
            } else if (c == ')') {
                if (!b) {
                    ++ans;
                }
                b = false;
            } else if (b && !(c == ' ' || Character.isLetter(c))) {
                ++ans;
                b = false;
            }
        }
        if (b) {
            ++ans;
        }
        System.out.println(ans);
    }
}

// ID:     Date'n'Time:    Name:       Task: .Ext:   Status:      Time: Memory:
// 1313504 30.06.12 01:54  watashi     538   .JAVA   Accepted     4 ms  196 kb

