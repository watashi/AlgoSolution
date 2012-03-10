// SGU119. Magic Pairs

import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int a0 = in.nextInt() % n;
		int b0 = in.nextInt() % n;
		int a = 0, b = 0, c = 0;
		ArrayList<ArrayList<Integer> > ans = new ArrayList<ArrayList<Integer> >(n);
		
		for (int i = 0; i < n; ++i) {
			ans.add(new ArrayList<Integer>());
		}
		do {
			ans.get(a).add(b);
			a += a0;
			if (a >= n) {
				a -= n;
			}
			b += b0;
			if (b >= n) {
				b -= n;
			}
			++c;
		} while (!(a == 0 && b == 0));
		System.out.println(c);
		for (int i = 0; i < ans.size(); ++i) {
			Collections.sort(ans.get(i));
			for (int j : ans.get(i)) {
				System.out.println(i + " " + j);
			}
		}
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status:  	Time:  	Memory:
//1041716	13.07.10 06:42	watashi	119 	.JAVA	Accepted 	187 ms	0 kb

