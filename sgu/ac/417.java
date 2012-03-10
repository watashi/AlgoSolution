// SGU417. Heavy Disc
/*
417. Heavy Disc
Time limit per test: 2 second(s)
Memory limit: 262144 kilobytes
input: standard
output: standard


Consider a heavy disc on the plane, centered at with radius , with the origin strictly outside it. The density of the disc is given by formula



What is the mass of the disc?

Input
The input file contains three integer numbers , , (, , ).

Output
Output one real number — the mass of the disc. Your answer will be considered correct if it is within relative error of the exact answer.

Example(s)

sample input

	

sample output

3 4 2

	

40.449586576894895
*/
import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		double x = in.nextDouble();
		double y = in.nextDouble();
		double r = in.nextDouble();
		System.out.println(Math.PI * r * r * Math.log(x * x + y * y));
	}
}

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//887057	14.09.09 17:58	watashi	417 	.JAVA	Accepted	56 ms	0 kb


