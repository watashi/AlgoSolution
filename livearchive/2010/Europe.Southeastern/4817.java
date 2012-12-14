import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
	static boolean flag;
	static int ch = ' ';
	static BigInteger val;
	static final BigInteger LIMIT = BigInteger.TEN.pow(90);
	static final int EOF = -1;
	static final int LPA = 0;
	static final int RPA = 1;
	static final int ADD = 2;
	static final int SUB = 3;
	static final int MUL = 4;
	static final int DIV = 5;
	static final int NUM = 6;

	static int next() throws IOException {
		while (Character.isWhitespace(ch)) {
			ch = System.in.read();
		}
		switch (ch) {
			case -1: ch = ' '; return EOF;
			case '(': ch = ' '; return LPA;
			case ')': ch = ' '; return RPA;
			case '+': ch = ' '; return ADD;
			case '-': ch = ' '; return SUB;
			case '*': ch = ' '; return MUL;
			case '/': ch = ' '; return DIV;
		}
		StringBuilder sb = new StringBuilder();
		while (Character.isDigit(ch)) {
			sb.append((char)ch);
			ch = System.in.read();
		}
		val = new BigInteger(sb.toString());
		return NUM;
	}

	static BigInteger gao() throws IOException {
		int token = next();
		BigInteger ret = null;

		//System.err.println("[" + token + "]" + "(" + val + ")");
		if (token == EOF) {
			System.exit(0);
		} else if (token == NUM) {
			ret = val;
		} else if (token == LPA) {
			BigInteger lhs = gao();
			int op = next();
			BigInteger rhs = gao();
			next(); // RPA
			switch (op) {
				case ADD: ret = lhs.add(rhs); break;
				case SUB: ret = lhs.subtract(rhs); break;
				case MUL: ret = lhs.multiply(rhs); break;
				case DIV:
					if (rhs.signum() == 0) {
						flag = false;
						rhs = BigInteger.ONE;
					}
					ret = lhs.divide(rhs);
					break;
			}
		}
		flag &= ret.compareTo(BigInteger.ZERO) >= 0;
		flag &= ret.compareTo(LIMIT) < 0;

		return ret;
	}

	public static void main(String[] args) throws IOException {
		while (true) {
			flag = true;
			BigInteger ans = gao();
			if (flag) {
				System.out.println(ans);
			} else {
				System.out.println("Error");
			}
		}
	}
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//805862 	4817 	Calculator 	Accepted 	JAVA 	0.160 	2011-05-23 13:57:18
/*
id => 1174241
pid => 4817
pname => Calculator
status => Accepted
lang => JAVA
time => 0.118
date => 2012-12-14 17:43:36
*/
