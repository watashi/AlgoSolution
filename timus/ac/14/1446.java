import java.io.*;
import java.util.*;

public class SortHat {
	private static void disp(String str, ArrayList<String> arr) {
		System.out.println(str + ":");
		for (String s: arr) {
			System.out.println(s);
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(in.readLine());
		String s;
		ArrayList<String> S = new ArrayList<String>();
		ArrayList<String> H = new ArrayList<String>();
		ArrayList<String> G = new ArrayList<String>();
		ArrayList<String> R = new ArrayList<String>();

		for (int i = 0; i < n; i++) {
			s = in.readLine();
			switch (in.readLine().charAt(0)) {
				case 'S': S.add(s); break;
				case 'H': H.add(s); break;
				case 'G': G.add(s); break;
				case 'R': R.add(s); break;
			}
		}
		disp("Slytherin", S);
		System.out.println();
		disp("Hufflepuff", H);
		System.out.println();
		disp("Gryffindor", G);
		System.out.println();
		disp("Ravenclaw", R);
	}
}
/*
id => 4678351
date => 12:20:4716 Dec 2012
user => watashi
pname => Sorting Hat
lang => Java
status => Accepted
testid => 
time => 0.125
mem => 1 250 KB
pid => 1446
*/
