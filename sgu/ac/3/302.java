// SGU302. BHTML 1.0
/*
302. BHTML 1.0
Time limit per test: 2 second(s)
Memory limit: 65536 kilobytes
input: standard
output: standard


The hypertext markup language BHTML 1.0 has only two paired tags. They are UP /UP and DOWN /DOWN . The UP /UP tag capitalizes all letters inside its body (between an open tag and a close one), and DOWN /DOWN makes all inside the body letters lowercase. You are given the text consisting of latin letters and tags. Your task is to write the text right as it will be shown in the Bernet Explorer browser window. Tags in the text are arranged correctly, i.e. they form correct bracket sequence. If a letter lays inside several tags, its case is defined by the most inner tag.

Input
The input contains the string with the text. The length of the string is a natural number not exceeding . Tags are always written in uppercase.

Output
Write to the output text after the processing.

Example(s)

sample input

	

sample output

Thi<UP>sIs<DOWN>EaSY</DOWN>Pr<UP>O</UP>ble</UP>m 

	

ThiSISeasyPROBLEm
*/
import java.io.*;
import java.util.*;

public class Solution {
	public static void main(String[] args) throws IOException {
		char[] str = new char[4096];
		int len = new InputStreamReader(System.in).read(str);
		Stack<Character> s = new Stack<Character>();
		StringBuilder ans = new StringBuilder(len);
		for (int i = 0; i < len; ++i) {
			if (str[i] == '<') {
				switch (str[i + 1]) {
					case 'U': s.push('U'); break;
					case 'D': s.push('D'); break;
					case '/': s.pop(); break;
				}
				while (str[i] != '>') {
					++i;
				}
			} else if (s.empty()) {
				ans.append(str[i]);
			} else if (s.peek() == 'U') {
				ans.append(Character.toUpperCase(str[i]));
			} else if (s.peek() == 'D') {
				ans.append(Character.toLowerCase(str[i]));
			}
		}
		System.out.print(ans);
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//873605	04.08.09 08:48	watashi	302 	.JAVA	Accepted	0 ms	326 kb

