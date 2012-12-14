import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int re = Integer.parseInt(in.readLine());
		for (int ri = 1; ri <= re; ++ri) {
			String str = in.readLine();
			StringBuilder sb = new StringBuilder(str.length());
			for (int i = 0; i < str.length(); ++i) {
				if (str.charAt(i) != 's'
						|| i + 1 == str.length()
						|| !Character.isLetter(str.charAt(i + 1))
						|| str.charAt(i + 1) == 'f'
						|| str.charAt(i + 1) == 'b'
						|| str.charAt(i + 1) == 'k') {
					sb.append(str.charAt(i));
				} else {
					sb.append("[longs]");
				}
			}
			str = sb.toString();
			str = str.replaceAll("A[Ee]", "[AE]")
				.replaceAll("O[Ee]", "[OE]")
				.replaceAll("ae", "[ae]")
				.replaceAll("oe", "[oe]")
				.replaceAll("ct", "[ct]")
				.replaceAll("ff", "[ff]")
				.replaceAll("fi", "[fi]")
				.replaceAll("fl", "[fl]")
				.replaceAll("\\[ff\\]i", "[ffi]")
				.replaceAll("\\[ff\\]l", "[ffl]")
				.replaceAll("\\[longs\\]\\[longs\\]\\[longs\\]", "[longs]s[longs]")
				.replaceAll("\\[longs\\]\\[longs\\]i", "[longssi]")
				.replaceAll("\\[longs\\]\\[longs\\]", "[longss]")
				.replaceAll("\\[longs\\]i", "[longsi]")
				.replaceAll("\\[longs\\]h", "[longsh]")
				.replaceAll("\\[longs\\]l", "[longsl]")
				.replaceAll("\\[longs\\]t", "[longst]");
			System.out.println(str);
		}
	}
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//881218 	4879 	Old Fafhioned Typefetting 	Accepted 	JAVA 	0.332 	2011-09-13 13:41:22
/*
id => 1174159
pid => 4879
pname => Old Fafhioned Typefetting
status => Accepted
lang => JAVA
time => 0.215
date => 2012-12-14 17:31:27
*/
