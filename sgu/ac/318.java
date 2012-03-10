// SGU318. Grants
/*
318. Grants
Time limit per test: 2 second(s)
Memory limit: 65536 kilobytes
input: standard
output: standard


Berland City Central School has a lot of computers connected to the network. The network has a number of shared network resources and a number of users willing to access these resources. There are N resources numbered 1, 2,..., N and M users numbered 1, 2,..., M.

Let the user i require an access to the finite set of the resources Si = {ri1, ri2,... }. System administrator needs to grant each user each resource he or she wishes. The solution he chose is to use user groups.

User group is an object that allows to link users and resources. Each user group is associated with an arbitrary number of users and resources. Let Ug = {uj1, uj2,... } be the finite set of users associated with the group g. Let Rg = {rk1, rk2,... } be the finite set of resources associated with the same group g.

The system administrator should obey the following rules while creating the user groups:

    * No two different user groups can have common resources, i.e. each resource can belong to at most one user group.
    * A user has an access to a resource if this user belongs to the user group containing this resource.
    * Each user should have access to all resources he or she wishes, but to no any other resource.
    * A user can belong to any number of user groups. 



Your task is to help the system administrator to create the user groups in such a way that the rules above are satisfied and the number of user groups is minimal.

Input
The first line of the input contains two integer numbers N and M (1 ≤ N, M≤ 100). Each of the following M lines contains the description of Si. Each description consists of the size of Si (non-negative integer not exceeding N) followed by the items of Si (different positive integers not exceeding N). Numbers in each line are separated by one or several spaces.

Output
Write the minimal number of the user groups required to the output.

Example(s)

sample input

	

sample output

5 2
2 1 3
3 3 4 5

	

3




Note
You need at least three user groups to grant desired access privileges to each user. For example, first group may contain first user and first object. Second group may contain both users and third object. Third group may contain second user and fourth and fifth objects.
*/
import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		boolean[][] b = new boolean[n][m];
		for (int i = 0; i < m; ++i) {
			int l = in.nextInt();
			for (int j = 0; j < l; ++j) {
				b[in.nextInt() - 1][i] = true;
			}
		}
		boolean[] e = new boolean[m];
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (b[i] != null && !Arrays.equals(b[i], e)) {
				++ans;
				for (int j = i + 1; j < n; ++j) {
					if (Arrays.equals(b[i], b[j])) {
						b[j] = null;
					}
				}
			}
		}
		System.out.println(ans);
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//875268	11.08.09 18:21	watashi	318 	.JAVA	Accepted	35 ms	3090 kb

