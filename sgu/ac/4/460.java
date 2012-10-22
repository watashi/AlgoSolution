// SGU460. Plural Form of Nouns
import java.util.*;

public class Solution {
	public static void main(String[] args) {
		String[] from = new String[]{"ch", "x", "s", "o", "f", "fe", "y", ""};
		String[] to = new String[]{"ches", "xes", "ses", "oes", "ves", "ves", "ies", "s"};
		Scanner in = new Scanner(System.in);
		int re = in.nextInt();
		for (int ri = 1; ri <= re; ++ri) {
			String s = in.next();
			for (int j = 0; j < from.length; ++j) {
				if (s.endsWith(from[j])) {
					System.out.println(s.substring(0, s.length() - from[j].length()) + to[j]);
					break;
				}
			}
		}
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//1137289	05.02.11 23:42	watashi	460 	.JAVA	Accepted 	60 ms	0 kb

