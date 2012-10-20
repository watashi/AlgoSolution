// SGU428. Rebus

/*
428. Rebus
Time limit per test: 4 second(s)
Memory limit: 262144 kilobytes
input: standard
output: standard


An addition rebus is a puzzle where you get an addition equation, like , and you're asked to replace each letter with a digit (from 0 through 9) in such a way that:

    * Equal letters are replaced with equal digits.
    * Different letters are replaced with different digits.
    * None of the resulting numbers starts with 0, unless the entire number is just 0.
    * The resulting equation holds. 



A proper addition rebus is an addition rebus with exactly one solution. An aligned addition rebus is an addition rebus where all three involved numbers have the same length (number of digits). The above addition rebus is aligned, but isn't proper: and are its two possible different solutions (and there are more).

Find 1000 different proper aligned addition rebuses. Two rebuses are different if there is no one-to-one mapping from the set of 26 English letters on itself that transfers one of those rebuses into another. For example, and are not different, while and are different.

Input
The input file will be empty.

Output
Output any 1000 different proper aligned addition rebuses, one per line. Each rebus may only use capital English letters, symbols ' ' and ' '. Each rebus must be at most 100 characters long.

Example(s)
Note that this example output doesn't contain the required 1000 rebuses, it contains just two.

sample input

	

sample output

 

	

AABC+AABB=DBCB
RRR+TTR=EDT
*/
public class Solution {
	public static void main(String[] args) throws java.io.IOException {
		byte[] a =  "ECBABCDEFGHI   ".getBytes();
		byte[] b = "+ECBBBBBBBBBB   ".getBytes();
		byte[] c = "=IECBCDEFGHIJJJJ\n".getBytes();
		for (int i = 0; i < 10; ++i) {
			a[12] = (byte)(65 + i);
			b[13] = (byte)(74 - i);
			for (int j = 0; j < 10; ++j) {
				a[13] = (byte)(65 + j);
				b[14] = (byte)(74 - j);
				for (int k = 0; k < 10; ++k) {
					a[14] = (byte)(65 + k);
					b[15] = (byte)(74 - k);
					System.out.write(a);
					System.out.write(b);
					System.out.write(c);
				}
			}
		}
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//887053	14.09.09 17:51	watashi	428 	.JAVA	Accepted	0 ms	0 kb


