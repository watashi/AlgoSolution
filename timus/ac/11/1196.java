import java.io.*;
import java.util.*;

public class HistoryExam {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String s = in.readLine();
		int n = Integer.parseInt(s), c, t;
		HashSet<Integer> set = new HashSet<Integer>();

		while (n-- > 0) {
			set.add(Integer.parseInt(in.readLine()));
		}
		n = Integer.parseInt(in.readLine());
		c = 0;
		while (n-- > 0) {
			if (set.contains(Integer.parseInt(in.readLine()))) {
				++c;
			}
		}
		System.out.println(c);
	}
}
/*
id => 4678068
date => 03:45:2216 Dec 2012
user => watashi
pname => History Exam
lang => Java
status => Accepted
testid => 
time => 0.39
mem => 5 566 KB
pid => 1196
*/
