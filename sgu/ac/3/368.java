// SGU368. Tests
/*
368. Tests
Time limit per test: 4 second(s)
Memory limit: 65536 kilobytes
input: standard
output: standard


It is soon the exam time for entrants at Berland State University, in short BerSU. As usual, for every subject, instead of passing an entry exam, one can present the results of the centralized test on that subject. Knowing that, Peter had passed the tests for all of the M subjects in advance.

The selection committees of each of the N BerSU faculties have published the rules for automatic conversion of test results into exam grades, as well as the sum of the grades necessary to enter study for each of the S specialties. Peter is not very confident in his test results, so he made an application for every possible specialty of each of the BerSU faculties. Now, he is curious and wants to know which of his applications were accepted.

Input
In the first line of input file there are two integers N and M (1 ≤ N ≤ 100, 1 ≤ M ≤ 100) — the number of faculties and the number of subjects for which Peter passed the tests, respectively. Next line contains M integers B1, B2,..., BM (0 ≤ Bi ≤ 100); here, Bi is Peter's score for i-th subject. After that come N blocks for description of the faculties.

The first line of a block contains the name of the faculty; it can contain just uppercase and lowercase Latin letters and spaces and is no longer than 100 characters. The second line contains K — the number of exams one should pass in order to enter study for any specialty on that faculty, and after that K integers — the numbers of the subjects at these exams. The third line contains K triplets of numbers X1 < Y1 < Z1 X2 < Y2 < Z2... XK < YK < ZK; here, Xi, Yi and Zi have the following meaning. Suppose Peter has a score of T for the respective subject. If T < Xi, Peter gets a "2" for it; if the Xi ≤ T < Yi, he gets a "3"; if Yi ≤ T < Zi, a "4"; and finally, if Zi ≤ T, Peter gets a "5".

After these three lines of a block, there comes a line with a single integer S on it (1 ≤ S ≤ 100). Next are S sub-blocks describing specialties. Each of the blocks consists of two lines. First of them contains the name of the specialty. Second line contains a single integer — the sum of grades necessary to pass the exam. In order for Peter's application to be accepted, he should have the sum of grades no less than this number.

The names of faculties and specialties can contain just uppercase and lowercase Latin letters and spaces, can't start or end with a space and have length between 1 and 100 characters, inclusive.

Output
For each Peter's application that got accepted, output the names of the faculty and the specialty on a single line, separated by a single space. Lines can be output in any order.

If all Peter's applications were rejected, output the word "Army" on the first line of the input file.

Example(s)

sample input

	

sample output

2 3
98 87 90
Computer Science and IT
3 1 2 3
90 95 99 80 90 100 91 93 95
2
Computer Security
15
Applied Math and Informatics
14
Mathematics and Mechanics
3 1 2 3
70 80 90 80 85 90 65 76 90
2
Applied Math and Informatics
13
Applied Math in Agriculture
5

	

Mathematics and Mechanics Applied Math and Informatics
Mathematics and Mechanics Applied Math in Agriculture


sample input

	

sample output

1 3
98 87 90
Computer Science and IT
3 1 2 3
90 95 99 80 90 100 91 93 95
1
Computer Security
15

	

Army

*/
import java.io.*;

public class Solution {
	public static void main(String[] args) throws IOException {
		boolean army = true;
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String[] snm = in.readLine().split(" ");
		int n = Integer.parseInt(snm[0]), m = Integer.parseInt(snm[1]);
		String[] sb = in.readLine().split(" ");
		int[] b = new int[m];
		for (int i = 0; i < b.length; ++i) {
			b[i] = Integer.parseInt(sb[i]);
		}
		for (int i = 0; i < n; ++i) {
			String faculty = in.readLine();
			String[] sk = in.readLine().split(" ");
			int k = Integer.parseInt(sk[0]);
			String[] sxyz = in.readLine().split(" ");
			int grade = 0;
			for (int j = 0; j < k; ++j) {
				int t = Integer.parseInt(sk[j + 1]) - 1;
				if (b[t] < Integer.parseInt(sxyz[j * 3])) {
					grade += 2;
				} else if (b[t] < Integer.parseInt(sxyz[j * 3 + 1])) {
					grade += 3;
				} else if (b[t] < Integer.parseInt(sxyz[j * 3 + 2])) {
					grade += 4;
				} else {
					grade += 5;
				}
			}
			int s = Integer.parseInt(in.readLine());
			for (int j = 0; j < s; ++j) {
				String specialty = in.readLine();
				if (grade >= Integer.parseInt(in.readLine())) {
					army = false;
					System.out.println(faculty + " " + specialty);
				}
			}
		}
		if (army) {
			System.out.println("Army");
		}
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//887223	15.09.09 09:47	watashi	368 	.JAVA	Accepted	282 ms	0 kb


