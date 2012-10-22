// SGU357. Remote Control
import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int[] a = new int[]{1, 2, 3, 11, 4, 5, 6, 12, 7, 8, 9, 10, 0};
		boolean[] b = new boolean[13];
		for (int i = 0; i < 13; ++i) {
			b[a[i]] = (in.nextInt() != 0);
		}
		int x = in.nextInt();
		int y = in.nextInt();
		int ans = Integer.MAX_VALUE;

		if (b[11] || x == y) {
			ans = Math.min(ans, (y - x + 100) % 100);
		}
		if (b[12] || x == y) {
			ans = Math.min(ans, (x - y + 100) % 100);
		}

		for (int i = 0; i < 10; ++i) {
			if (b[i]) {
				if (b[11] || i == y) {
					ans = Math.min(ans, 1 + (y - i + 100) % 100);
				}
				if (b[12] || i == y) {
					ans = Math.min(ans, 1 + (i - y + 100) % 100);
				}
			}
		}

		for (int i = 10; i < 100; ++i) {
			if (b[10] && b[i / 10] && b[i % 10]) {
				if (b[11] || i == y) {
					ans = Math.min(ans, 3 + (y - i + 100) % 100);
				}
				if (b[12] || i == y) {
					ans = Math.min(ans, 3 + (i - y + 100) % 100);
				}
			}
		}

		System.out.println(ans == Integer.MAX_VALUE ? -1 : ans);
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status:  	Time:  	Memory:
//1081916	28.09.10 11:46	watashi	357 	.JAVA	Accepted 	19 ms	0 kb

