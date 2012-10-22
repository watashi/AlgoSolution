// SGU524. Buoys
import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		double[] a = new double[n];
		for (int i = 0; i < n; ++i) {
			a[i] = in.nextDouble();
		}

		double ss = Double.MAX_VALUE;
		double bb = 0, dd = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				double d = (a[j] - a[i]) / (j - i);
				double b = a[i] - d * i;
				double s = 0;
				for (int k = 0; k < n && s < ss; ++k) {
					s += Math.abs(b + d * k - a[k]);
				}
				if (s < ss) {
					ss = s;
					bb = b;
					dd = d;
				}
			}
		}

		System.out.printf("%.10f\n", ss);
		for (int i = 0; i < n; ++i) {
			System.out.printf("%.10f%c", bb + i * dd, i == n - 1 ? '\n' : ' ');
		}
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//1112460	12.11.10 12:20	watashi	524 	.JAVA	Accepted 	391 ms	0 kb

