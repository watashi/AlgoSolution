// SGU201. Non Absorbing DFA
/*
201. Non Absorbing DFA
time limit per test: 2 sec.
memory limit per test: 65536 KB
input: standard
output: standard



In the theory of compilers and languages finite state machines, also known as finite automata are widely used. Deterministic finite automation (DFA) is an ordered set <Σ, U, s, T, φ> where Σ is the finite set called input alphabet, U is the finite set of states, s from U is the initial state, T subset of U is the set of terminal states and φ : U × Σ → U is the transition function.

The input of the automation is the string α over Σ. Initially the automation is in state s. Each step it reads the first character c of the input string and changes its state to φ(u, c) where u is the current state. After that the first character of the input string is removed and the step repeats. If when its input string is empty the automation is in the terminal state, it is said that it accepts the initial string α, in the other case it rejects it.

In some cases to simplify the automation the concept of nonabsorbing edges is introduced. That is, in addition to φ the function χ : U × Σ → {0, 1} is introduced and when making a transition from some state u with some character c, the leading character is removed from the input string only if χ(u, c) = 0. If χ(u, c) = 1, the input string is kept intact and next transition is performed with the new state and the same character.

It is said that such automation accepts some string α if after a number of steps it transits to the terminal state and the input string becomes empty.

Your task is given the DFA with nonabsorbing edges to compute the number of strings of the given length N that it accepts.

Input

The first line of the input file contains Σ — a subset of the English alphabet, several different small letters. Next line contains K = | U | — the number of states of the automation (1 ≤ K ≤ 1000). Let states be numbered from 1 to K. Next line contains S (1 ≤ S ≤ K) — the initial state, followed by L = | T | — the number of terminal states and then L different integer numbers ranging from 1 to K — the numbers of terminal states.

Next K lines contain | Σ | integer numbers each and define φ. Next K lines define χ in a similar way. The last line of the input file contains N (1 ≤ N ≤ 60).

Output

Output the only number — the number of different strings of length N over Σ that the given DFA accepts.

In the given example the two strings accepted by the automation are ``aaa'' and ``abb''.

Sample test(s)

Input

ab
2
1 1 2
2 1
1 2
0 1
0 0
3

Output

2

[submit]
[forum]
Author:	Andrew Stankevich
Resource:	Petrozavodsk Summer Trainings 2003
Date:	2003-08-23 
*/
import java.math.*;
import java.util.*;

class DFA {
	private int z, k, s;
	private int[] t;
	private int[][] e;

	private int dfs(int p, int[] e, int[] f, boolean[] g) {
		if (e[p] == -1) {
		} else if (g[p]) {
			e[p] = f[p];
		} else {
			e[p] = -1;
			e[p] = dfs(f[p], e, f, g);
		}
		return e[p];
	}

	public DFA(char[] z, int k, int s, int[] t, int[][] f, boolean[][] g) {
		this.z = z.length;
		this.k = k;
		this.s = s;
		this.t = t.clone();
		e = new int[z.length][k];
		for (int i = 0; i < z.length; ++i) {
			Arrays.fill(e[i], -2);
			for (int j = 0; j < k; ++j) {
				if (e[i][j] == -2) {
					dfs(j, e[i], f[i], g[i]);
				}
			}
		}
	}

	public BigInteger count(int n) {
		BigInteger[] prev = new BigInteger[k];
		Arrays.fill(prev, BigInteger.ZERO);
		prev[s] = BigInteger.ONE;
		while (n-- > 0) {
			BigInteger[] next = new BigInteger[k];
			Arrays.fill(next, BigInteger.ZERO);
			for (int i = 0; i < k; ++i) {
				if (prev[i].signum() <= 0) {
					continue;
				}
				for (int j = 0; j < z; ++j) {
					if (e[j][i] < 0) {
						continue;
					}
					next[e[j][i]] = next[e[j][i]].add(prev[i]);
				}
			}
			prev = next;
		}
		BigInteger ans = BigInteger.ZERO;
		for (int term : t) {
			ans = ans.add(prev[term]);
		}
		return ans;
	}
}

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String z = in.next();
		int k = in.nextInt();
		int s = in.nextInt() - 1;
		int l = in.nextInt();
		int[] t = new int[l];
		for (int i = 0; i < l; ++i) {
			t[i] = in.nextInt() - 1;
		}
		int[][] f = new int[z.length()][k];
		for (int i = 0; i < k; ++i) {
			for (int j = 0; j < z.length(); ++j) {
				f[j][i] = in.nextInt() - 1;
			}
		}
		boolean[][] g = new boolean[z.length()][k];
		for (int i = 0; i < k; ++i) {
			for (int j = 0; j < z.length(); ++j) {
				g[j][i] = (in.nextInt() == 0);
			}
		}
		DFA dfa = new DFA(z.toCharArray(), k, s, t, f, g);
		int n = in.nextInt();
		System.out.println(dfa.count(n));
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//873766	04.08.09 20:11	watashi	201 	.JAVA	Accepted	622 ms	9990 kb

