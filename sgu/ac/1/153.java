// SGU153. Playing with matches 
import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int re = in.nextInt();
		for (int ri = 1; ri <= re; ++ri) {
			int n = in.nextInt() - 1;
			int m = in.nextInt();
			int[] p = new int[m + 1];
			for (int i = 0; i < m; ++i) {
				p[i] = in.nextInt() - 1;
			}
			p[m] = 0;
			
			int[] a = new int[1 << 9];
			int[] b = new int[1 << 9];
			int s = 0x1ff ^ 1, begin, end;
			Arrays.fill(a, -1);
			a[s] = 0;
			b[0] = s;
			while (true) {
				int t = 1;
				for (int pi : p) {
					t &= s >> pi;
				}
				t ^= 1;
				t ^= s << 1;
				t &= 0x1ff;
				if (a[t] == -1) {
					a[t] = a[s] + 1;
					b[a[t]] = t;
					s = t;
				} else {
					begin = a[t];
					end = a[s] + 1;
					break;
				}
			}

			n = (n < begin ? n : begin + (n - begin) % (end - begin));
			System.out.println(((b[n] & 1) == 0 ? "SECOND" : "FIRST") + " PLAYER MUST WIN");
		}
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status:  	Time:  	Memory:
//1079407	21.09.10 08:48	watashi	153 	.JAVA	Accepted 	19 ms	0 kb
