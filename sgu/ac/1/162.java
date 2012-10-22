// SGU162. Pyramids 
import java.util.*;

public class Solution {
	static double lawofcos(double a, double b, double c) {
		return Math.acos((a * a + b * b - c * c) / (2 * a * b));
	}

	public static void main() {
		Scanner in = new Scanner(System.in);
		double[] e = new double[6];
		for (int i = 0; i < e.length; ++i) {
			e[i] = in.nextDouble();
		}

		double[] a = new double[3];
		a[0] = lawofcos(e[0], e[1], e[3]);	// BC
		a[1] = lawofcos(e[0], e[2], e[4]);	// BD
		a[2] = lawofcos(e[1], e[2], e[5]);	// CD
		double[] c = new double[2];
		c[0] = Math.cos(a[0]);
		c[1] = Math.cos(a[1]);
		if (c[0] < 0) {	// WA4,WA13,WA23
			c[0] = -c[0];
			c[1] = -c[1];
		}
		
		double l = -Math.acos(-1) / 2, r = Math.acos(-1) / 2, m;	// WA4,WA13,WA23
		for (int i = 0; i < 100; ++i) {
			m = (l + r) / 2;
			if (Math.cos(m) * c[1] >= Math.cos(a[2] - m) * c[0]) {
				l = m;
			} else {
				r = m;
			}
		}
		m = (l + r) / 2;
		m = Math.acos(c[0] / Math.cos(m));

		double ans = Math.abs(e[0] * e[1] * e[2] * Math.sin(a[2]) * Math.sin(m));
		System.out.printf("%.4f\n", ans / 6);
	}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status:  	Time:  	Memory:
//1079006	20.09.10 11:40	watashi	162 	.JAVA	Accepted 	30 ms	0 kb

	// 
	public static void main(String[] args) {		
		Scanner in = new Scanner(System.in);
		double[] e = new double[6];
		for (int i = 0; i < e.length; ++i) {
			e[i] = in.nextDouble();
		}

		double[] a = new double[4];
		a[0] = lawofcos(e[0], e[1], e[3]);
		a[1] = lawofcos(e[0], e[2], e[4]);
		a[2] = lawofcos(e[1], e[2], e[5]);
		a[3] = (a[0] + a[1] + a[2]) / 2;

		double ans = Math.sin(a[3]);
		for (int i = 0; i < 3; ++i) {
			ans *= Math.sin(a[3] - a[i]);
		}
		ans = e[0] * e[1] * e[2] * Math.sqrt(ans);
		System.out.printf("%.4f\n", ans / 3);
	}
// ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status:  	Time:  	Memory:
// 1079013	20.09.10 11:56	watashi	162 	.JAVA	Accepted 	19 ms	0 kb
}

