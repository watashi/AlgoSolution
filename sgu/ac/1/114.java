// SGU114. Telecasting station
/*
114. Telecasting station

time limit per test: 0.50 sec.
memory limit per test: 4096 KB

Every city in Berland is situated on Ox axis. The government of the country decided to build new telecasting station. After many experiments Berland scientists came to a conclusion that in any city citizens displeasure is equal to product of citizens amount in it by distance between city and TV-station. Find such point on Ox axis for station so that sum of displeasures of all cities is minimal.

Input

Input begins from line with integer positive number N (0<N<15000) – amount of cities in Berland. Following N pairs (X, P) describes cities (0<X, P<50000), where X is a coordinate of city and P is an amount of citizens. All numbers separated by whitespace(s).

Output

Write the best position for TV-station with accuracy 10-5.

Sample Input

4
1 3
2 1
5 2
6 2

Sample Output

3.00000

Author	: Michael R. Mirzayanov
Resource	: PhTL #1 Training Contests
Date	: Fall 2001
*/

/*
// Memory Limit Exceeded on test 14
import java.util.*;

class Pair<
		T extends Comparable<T>,
		U extends Comparable<U> >
		implements Comparable<Pair<T, U> > {
	public T first;
	public U second;
	public Pair() {
		first = null;
		second = null;
	}
	public Pair(T first, U second) {
		this.first = first;
		this.second = second;
	}
	public int compareTo(Pair<T, U> p) {
		if (first.compareTo(p.first) != 0) {
			return first.compareTo(p.first);
		} else {
			return second.compareTo(p.second);
		}
	}
}

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int sp = 0;
		
		ArrayList<Pair<Double, Integer> > xp = new ArrayList<Pair<Double, Integer> >(n);
		for (int i = 0; i < n; ++i) {
			double x = in.nextDouble();
			int p = in.nextInt();
			sp += p;
			xp.add(new Pair<Double, Integer>(x, p));
		}
		Collections.sort(xp);
		for (Pair<Double, Integer> xpi : xp) {
			sp -= xpi.second << 1;
			if (sp <= 0) {
				System.out.println(xpi.first);
				break;
			}
		}
	}
}
*/

import java.util.*;

class Pair implements Comparable<Pair> {
	public double first;
	public int second;
	public Pair() {
		first = 0;
		second = 0;
	}
	public Pair(double first, int second) {
		this.first = first;
		this.second = second;
	}
	public int compareTo(Pair p) {
		if (first != p.first) {
			return first < p.first ? -1 : 1;
		} else if (second != p.second) {
			return second < p.second ? -1 : 1;
		} else {
			return 0;
		}
	}
}

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int sp = 0;
		
		ArrayList<Pair> xp = new ArrayList<Pair>(n);
		for (int i = 0; i < n; ++i) {
			double x = in.nextDouble();
			int p = in.nextInt();
			sp += p;
			xp.add(new Pair(x, p));
		}
		Collections.sort(xp);
		for (Pair xpi : xp) {
			sp -= xpi.second << 1;
			if (sp <= 0) {
				System.out.println(xpi.first);
				break;
			}
		}
	}
}

// 4096 kb orz-_-b

//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//866739	04.07.09 20:12	watashi	114 	.JAVA	Accepted	417 ms	4094 kb


