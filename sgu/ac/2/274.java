// SGU274. Spam-filter
/*
274. Spam-filter
time limit per test: 1 sec.
memory limit per test: 65536 KB
input: standard
output: standard



After tremendous last-year success not yet well-known, but already grown-up company H&H decided to create a new software masterpiece -- a world-leading spam-filter.
Due to Your poor last year -- a world-leading spam-filter. Due to your poor last year project performance, you are given a small and boring task again.
Your task is to write a simple email-validator.

Valid email address can be described as follows:

<letter> ::= a|b|...|z|A|B|...|Z

<symbol> ::= <letter>|0|1|...|9|_|-

<word> ::= <symbol>|<symbol><word>

<prefix> ::= <word>|<prefix>.<word>

<domain> ::= <letter><letter>|<letter><letter><letter>

<suffix> ::= <prefix>.<domain>

<address> ::= <prefix>@<suffix>


Input
The first line of the input file contains integer number N (1 <= N <= 100) -- the number of email addresses to be checked. Each of the following N lines contains one email address. Email address is the non-empty sequence of characters with ASCII codes from 32 to 255 no more then 100 characters long.

Output
For each address from the input write a separate line with the word YES, if the email address is valid and NO if it is not.

Sample test(s)

Input

3
abc@abc
abc@abc.abc
_@-.ru

Output

NO
YES
YES
[submit]
[forum]
Author:	Ilya V. Elterman
Resource:	ACM ICPC 2004-2005, NEERC, Southern Subregional Contest
Date:	Saratov, October 7, 2004 
*/
import java.io.*;
import java.util.*;

public class Solution {
	static boolean isLetter(char ch) {
		return 'a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z';
	}

	static boolean isSymbol(char ch) {
		return isLetter(ch) || '0' <= ch && ch <= '9' || ch == '_' || ch == '-';
	}

	static boolean isWord(String str) {
//		System.err.println("word?\t" + str);
		if (str.length() == 0) {
			return false;
		}
		for (char ch : str.toCharArray()) {
			if (!isSymbol(ch)) {
				return false;
			}
		}
		return true;
	}

	static boolean isPrefix(String str) {
//		System.err.println("prefix?\t" + str);
//	!!	Trailing empty strings are therefore not included in the resulting array. 
//	!!	-> WA2
		if (str.endsWith(".")) {
			return false;
		}
		String[] words = str.split("[.]");
/*		if (words.length == 0) {
			return false;
		}
*/		for (String word : words) {
			if (!isWord(word)) {
				return false;
			}
		}
		return true;
	}

	static boolean isDomain(String str) {
//		System.err.println("domain?\t" + str);
		if (str.length() < 2 || str.length() > 3) {
			return false;
		}
		for (char ch : str.toCharArray()) {
			if (!isLetter(ch)) {
				return false;
			}
		}
		return true;
	}

	static boolean isSuffix(String str) {
//		System.err.println("suffix?\t" + str);
		int p = str.lastIndexOf('.');
		return p != -1 && isPrefix(str.substring(0, p)) && isDomain(str.substring(p + 1));
	}

	static boolean isAddress(String str) {
		int p = str.indexOf('@');
		return p != -1 && isPrefix(str.substring(0, p)) && isSuffix(str.substring(p + 1));
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(in.readLine());
		for (int i = 0; i < n; ++i) {
			String str = in.readLine();
			System.out.println(isAddress(str) ? "YES" : "NO");
		}
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//886976	14.09.09 15:38	watashi	274 	.JAVA	Accepted	69 ms	0 kb

