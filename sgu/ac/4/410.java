// SGU410. Galaxy in danger
/*
410. Galaxy in danger
Time limit per test: 2 second(s)
Memory limit: 65536 kilobytes
input: standard
output: standard


Many years has already passed since the Logos galaxy was attacked by crazy space creatures, called mistkafers. With extreme efforts brave defenders of the galaxy managed to defeat the main forces of the opponent. The remaining enemies have been isolated on different planets.

Now the Government of a galaxy has a very difficult problem — to get rid from mistkafers in a galaxy as soon as possible. Namely to take them far beyond the galaxy and to dump them into a black hole. To cope with this problem, the Government needs help of winged pferds which can fly through black holes.

By a strange coincidence, there is exactly pferds available for the Government. Pferds can fly only all together, and each of them can transport to a black hole only one mistkafer per day. Thus, every day pferds take mistkafers and transport them into a black hole. And every pferd is so logical and consecutive, that will take mistkafers from the same planet every time, and will not fly to a black hole without mistkafer. Therefore, if there is no mistkafers left on some planet, pferds cannot take them out further.

In order to prevent such situations, in the morning of each day the Government can send scientists to some of the planets. These scientists can clone mistkarefs (no matter how they do it, but after cloning the number of mistkafers on the planet is doubled). The cloning of mistkafers on one planet takes exactly one day, so that day pferds do not take off.

Find out the minimal number of days which is required to get rid of mistkafers.

Input
In the first line of the input file the amount of planets () is given. The second line contains natural numbers, each of them means the number of mistkafers on a corresponding planet. The quantity of mistkafers on each planet does not exceed one billion.

Output
On the first line of the output file print one number  — the answer to the problem. In case the number of days does not exceed one thousand, in the following lines output the description of days in the chronological order. If on the -th day there was a flight of the pferds, output on ()-th line a phrase "flying mission" (without quotes), otherwise output a phrase "science mission to the planet " (without quotes), where  — is the number of a planet on which the cloning was made.

Example(s)

sample input

	

sample output

2
1 2

	

3
science mission to the planet 1
flying mission
flying mission


sample input

	

sample output

2
2 1025

	

1035
*/
import java.io.*;

public class Solution {
	static int nextInt() throws IOException {
		int ch = -1;
		do {
			ch = System.in.read();
		} while (!Character.isDigit(ch));
		int ret = 0;
		while (Character.isDigit(ch)) {
			ret *= 10;
			ret += Character.digit(ch, 10);
			ch = System.in.read();
		}
		return ret;
	}

	public static void main(String[] args) throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		int b = 0;
		for (int i = 0; i < n; ++i) {
			a[i] = nextInt();
			b = Math.max(b, a[i]);
		}
		int c = b;
		for (int i = 0; i < n; ++i) {
			int t = a[i];
			while (t < b) {
				t <<= 1;
				++c;
			}
		}
		System.out.println(c);
		if (c > 1000) {
			System.exit(0);
		}
		for (int i = 0; i < n; ++i) {
			while ((a[i] << 1) <= b) {
				a[i] <<= 1;
				System.out.println("science mission to the planet " + (i + 1));
			}
		}
		while (b > 0) {
			--b;
			System.out.println("flying mission");
			for (int i = 0; i < n; ++i) {
				--a[i];
				if (b > 0 && (a[i] << 1) == b) {
					a[i] <<= 1;
					System.out.println("science mission to the planet " + (i + 1));
				}
			}
		}
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//887905	16.09.09 22:23	watashi	410 	.JAVA	Accepted	144 ms	0 kb


