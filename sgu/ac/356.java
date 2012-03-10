// SGU356. Extrasensory Perception
/*
356. Extrasensory Perception
Time limit per test: 2 second(s)
Memory limit: 65536 kilobytes
input: standard
output: standard


His Royal Highness the King of Berland Berl XV has just decapitated his magician for being politically incorrect. It is a truth universally acknowledged that every king in the possession of a good fortune is in a want of a decent sorcerer. Heralds all over the country have spread the news about the coming Berland-wide wizard competition that is to end up with the announcement of the winner's name. The winner is to join the royal retinue as His Royal Highness' Counselor.

Magician Resool graduated from Bexford University ten years ago and since that time he has been chased by misfortunes and disasters. His wife, an accomplished, still pretty looking lady, believes her husband can do much better than just grumbling about the unfair life. She suggests that he should try his magic powers at the competition and reminds him of his famous trick. The gist of the trick is to see through people's souls.

After two weeks of training Resool makes himself enter the Great Hall of Berland Palace and demonstrate his exceptional abilities. His Royal Highness the King of Berland Berl XV gives him an assignment: N men and N women are presented, and the fact is known that they form N married couples; Resool is to identify a wife for every husband. After the magician casts a spell, burns some magic herbs, and performs ritual dance he still fails to answer correctly. He only manages to guess K married couples out of N. But The King is full of sympathy for the magician and can't just let the magician go away jobless and sorrowful. So, he hires him as a yard-keeper. Now Resool has a lot of free time on his new job and wants to calculate the chances he had at the competition. He wants to know the probability of guessing correctly exactly K married couples when given N men, N women, and a fact that they form N married couples. This will definitely help him during the competition next time.

Input
Input file contains two integers K and N (1 ≤ N ≤ 100; 0 ≤ K ≤ N) separated by a space.

Output
Print the required probability to the output file. If the answer is zero, simply print "0" (without quotes). Otherwise print the answer in a form of irreducible fraction "A/B" (without quotes), where A and B are positive integers without leading zeroes. See examples below for the format of output.

Example(s)

sample input

	

sample output

2 5

	

1/6


sample input

	

sample output

9 10

	

0
*/
import java.math.*;
import java.util.*;

public class Solution {	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int k = in.nextInt();
		int n = in.nextInt();
		BigInteger num = k == n ? BigInteger.ONE : BigInteger.ZERO;
		BigInteger den = BigInteger.ONE;
		BigInteger tmp = BigInteger.valueOf((n - k) % 2 == 0 ? 1 : -1);
		for (int i = n - k; i >= 2; --i) {
			num = num.add(tmp);
			tmp = tmp.multiply(BigInteger.valueOf(-i));
		}
		for (int i = 2; i <= k; ++i) {
			den = den.multiply(BigInteger.valueOf(i));
		}
		for (int i = 2; i <= n - k; ++i) {
			den = den.multiply(BigInteger.valueOf(i));
		}
		if (num.signum() == 0) {
			System.out.println("0");
		} else {
			tmp = num.gcd(den);
			System.out.println(num.divide(tmp) + "/" + den.divide(tmp));
		}
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//874967	10.08.09 17:29	watashi	356 	.JAVA	Accepted	35 ms	2402 kb
//874965	10.08.09 17:27	watashi	356 	.JAVA	Presentation Error on test 9	5 ms	2306 kb
