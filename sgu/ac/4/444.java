// sgu444. Headstrong Student
import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int x = in.nextInt();
        int y = in.nextInt();
        int[] r = new int[y];
        Arrays.fill(r, -1);
        x %= y;
        for (int i = 0; ; ++i) {
            if (x == 0) {
                System.out.println(i + " " + 0);
                break;
            } else if (r[x] != -1) {
                System.out.println(r[x] + " " + (i - r[x]));
                break;
            } else {
                r[x] = i;
                x = x * 10 % y;
            }
        }
    }
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//1326836	26.07.12 09:43	watashi	444 	.JAVA	Accepted 	12 ms	292 kb

