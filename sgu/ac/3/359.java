// SGU359. Pointers
/*
359. Pointers
Time limit per test: 1 second(s)
Memory limit: 65536 kilobytes
input: standard
output: standard


Pete learns dynamic pointers. In informatics tutorial he read about pointers in Pascal. Pointer is a special variable, containing address of some location in RAM. That location can contain value of a certain type. Pete declared four pointers pointing to memory cells with integer values in a following manner:

var a, b, c, d : ^integer;

Than he allocated memory with instruction new:

new(a); new(b); new(c); new(d);

and assigned zero values to memory cells, pointed by these pointers:

a^:=0; b^:=0; c^:=0; d^:=0;

# Please note that a^ means accessing location of memory, pointed by the pointer. Notation a (without symbol "^") means accessing to the pointer itself. Pete uses four types of operators in his program: pointer^:=constant, e.g. a^:=5. This operator puts value constant into the memory area pointed by pointer (compare fig. 1 and fig. 2);
# pointer1^:=pointer2^, e.g. c^:=a^. This operator puts value from the memory area pointed by pointer2 to the memory area pointed by pointer1 (compare fig. 2 and fig. 3);
# pointer1:=pointer2, e.g. b:=c. After execution of this operator pointer1 will point to the same memory area as pointer2 (compare fig. 3 and fig. 4);
# writeln(pointer^), e.g. writeln(b^). Prints value from the memory area pointed by pointer^ (operator writeln(b^) will print 5 in our example).



Pete use digits 0 to 9 as constants, and letters a, b, c or d as pointer variables.

Input
The first line of the input file contains integer number N (1 ≤ N ≤ 30). N lines follow. Each of the following lines contains exactly one operator of one of four described types. Each operator finished with symbol ";" (semicolon). Input file contains no blanks. You may assume that before executing of this program pointers a, b, c, d were declared, the memory was allocated for them, and memory areas pointed by them were filled with 0.

Output
Print to the output file numbers that will be printed by Pete's program.

Example(s)

sample input

	

sample output

10 
writeln(a^); 
a^:=7; 
b^:=a^; 
writeln(b^); 
c:=a; 
c^:=5; 
writeln(a^); 
a:=b; 
writeln(a^); 
a^:=a^; 

	

0 
7 
5 
7 


sample input

	

sample output

3 
a:=b; 
b^:=3; 
writeln(a^); 

	

3

*/
import java.util.*;

public class Solution {
	public static void main(String[] args) {
		int[] p = new int[4];
		for (int i = 0; i < 4; ++i) {
			p[i] = i;
		}
		int[] v = new int[4];

		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		for (int i = 0; i < n; ++i) {
			String op = in.next();
			if (op.charAt(0) == 'w') {
				System.out.println(v[p[op.charAt(8) - 'a']]);
			} else if (op.charAt(1) == ':') {
				p[op.charAt(0) - 'a'] = p[op.charAt(3) - 'a'];
			} else if (Character.isLowerCase(op.charAt(4))) {
				v[p[op.charAt(0) - 'a']] = v[p[op.charAt(4) - 'a']];
			} else {
				v[p[op.charAt(0) - 'a']] = Integer.parseInt(op.substring(4, op.length() - 1));
			}
		}
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//874945	10.08.09 15:46	watashi	359 	.JAVA	Accepted	25 ms	2078 kb

