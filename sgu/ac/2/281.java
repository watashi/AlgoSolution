// SGU281. Championship
/*
281. Championship
Time limit per test: 3 second(s)
Memory limit: 65536 kilobytes
input: standard
output: standard


teams participate in a championship. It consists of two contests; each of the teams participates in both. Each contest has its own rating. Then the final rating is made. If for some () the sets of first teams in both ratings are the same, then this set is the set of the first teams in the final rating. Teams whose relative order cannot be determined using this rule are placed in alphabetical order.

You are given the contests' ratings. Your task is to generate the final rating.

Input
The first line of the input contains an integer (). The two ratings follow. Each of the ratings consists on lines, each of which contains a team's name, being a string of at most 20 lowercase Latin letters and digits.

Output
Output the final rating in the same format as in the input.

Example(s)

sample input

	

sample output

6
spbifmo1
msu1
msu2
permsu
nsu1
nnsu
spbifmo1
msu1
permsu
msu2
nnsu
nsu1

	

spbifmo1
msu1
msu2
permsu
nnsu
nsu1




Novosibirsk SU Contest #2, by Novosibirsk Team #1 
*/
import java.io.*;
import java.util.*;

public class Solution {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(in.readLine());
		HashMap<String, Integer> map = new HashMap<String, Integer>(n);
		for (int i = 0; i < n; ++i) {
			map.put(in.readLine(), i);
		}
		boolean[] tag = new boolean[n];
		String[] str = new String[n];
		int p = 0, c = 0, id;
		for (int i = 0; i < n; ++i) {
			if (tag[i]) {
				++c;
			}
			str[i] = in.readLine();
			id = map.get(str[i]);
			tag[id] = true;
			if (id <= i) {
				++c;
			}
			if (p + c == i + 1) {
				Arrays.sort(str, p, p + c);
				p = i + 1;
				c = 0;
			}
		}
		for (String stri : str) {
			System.out.println(stri);
		}
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//874632	08.08.09 20:50	watashi	281 	.JAVA	Accepted	687 ms	16242 kb
