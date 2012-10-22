// sgu486. "Bulls and Cows"
import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        char[] a = in.next().toCharArray();
        char[] b = in.next().toCharArray();
        int x = 0, y = 0;
        for (int i = 0; i < a.length; ++i) {
            if (a[i] == b[i]) {
                ++x;
                a[i] = 'o';
                b[i] = 'x';
            }
        }
        for (int i = 0; i < a.length; ++i) {
            for (int j = 0; j < b.length; ++j) {
                if (a[i] == b[j]) {
                    ++y;
                    a[i] = 'o';
                    b[j] = 'x';
                }
            }
        }
        System.out.println(x + " " + y);
    }
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//1327170	27.07.12 05:23	watashi	486 	.JAVA	Accepted 	4 ms	276 kb

