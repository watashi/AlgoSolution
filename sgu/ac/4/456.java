// SGU456. Annuity Payment Scheme
import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int s = in.nextInt();
		int m = in.nextInt();
		int p = in.nextInt();
		double l = 0, r = s + s;
		for (int i = 0; i < 100; ++i) {
			double x = (l + r) / 2, y = s;
			for (int j = 0; j < m; ++j) {
				y -= x - y * p / 100;
			}
			if (y > 0) {
				l = x;
			} else {
				r = x;
			}
		}
		System.out.printf("%.6f\n", (l + r) / 2);
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//1137287	05.02.11 23:36	watashi	456 	.JAVA	Accepted 	74 ms	0 kb

