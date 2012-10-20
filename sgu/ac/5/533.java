// SGU533. Dice Tower

import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = -1;
        if (n < 28) {
            if (n == 21) {
                m = 1;
            }
        } else {
            m = n / 14;
            n %= 14;
            if (n < 2 || n > 12) {
                m = -1;
            }
        }
        System.out.println(m);
    }
}

// ID:     Date'n'Time:     Name:       Task: .Ext:   Status:      Time: Memory:
// 1313505 30.06.12 02:05   watashi     533   .JAVA   Accepted     4 ms  272 kb
