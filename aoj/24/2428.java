import java.util.*;
import java.math.*;

public class Main {
    static final BigInteger NEG = BigInteger.valueOf(-1);
    static final BigInteger INF = BigInteger.valueOf(1 << 10);
    static final char[] CHARSET = "01+-*()".toCharArray();

    static int pos;
    static String expr;

    static BigInteger chk(BigInteger x) throws Exception {
        if (x.signum() < 0 || x.compareTo(INF) >= 0) {
            throw new Exception("OVERFLOW");
        } else {
            return x;
        }
    }

    static void eval(Stack<BigInteger> val, Stack<Character> op, String list) throws Exception {
        while (!op.empty() && list.indexOf(op.peek()) != -1) {
            BigInteger rhs = val.pop();
            BigInteger lhs = val.pop();
            switch (op.pop()) {
                case '+':
                    val.push(chk(lhs.add(rhs)));
                    break;
                case '-':
                    val.push(chk(lhs.subtract(rhs)));
                    break;
                case '*':
                    val.push(chk(lhs.multiply(rhs)));
                    break;
            }
        }
    }

    static BigInteger eval(boolean err) throws Exception {
        Stack<BigInteger> val = new Stack<BigInteger>();
        Stack<Character> op = new Stack<Character>();

        while (true) {
            if (expr.charAt(pos) == '(') {
                ++pos;
                val.push(eval(true));
                if (expr.charAt(pos) != ')') {
                    throw new Exception(")");
                } else {
                    ++pos;
                }
            } else {
                int pos0 = pos;
                while (pos < expr.length() && Character.isDigit(expr.charAt(pos))) {
                    ++pos;
                }
                val.push(chk(new BigInteger(expr.substring(pos0, pos), 2)));
            }

            if (pos == expr.length() || expr.charAt(pos) == ')') {
                break;
            } else {
                switch (expr.charAt(pos)) {
                    case '+':
                    case '-':
                        eval(val, op, "+-*");
                        op.push(expr.charAt(pos));
                        break;
                    case '*':
                        eval(val, op, "*");
                        op.push('*');
                        break;
                    default:
                        throw new Exception("<operation>");
                }
                ++pos;
                err = false;
            }
        }

        if (err) {
            throw new Exception("(num)");
        } else {
            eval(val, op, "+-*");
            return val.pop();
        }
    }

    static BigInteger gao(String str) {
        int idx = str.indexOf('.');
        if (idx == -1) {
            pos = 0;
            expr = str;
            try {
                BigInteger ret = eval(false);
                return pos == expr.length() ? ret : NEG;
            } catch (Exception ex) {
                return NEG;
            }
        } else {
            BigInteger ret = NEG;
            for (char ch: CHARSET) {
                ret = ret.max(gao(str.substring(0, idx) + ch + str.substring(idx + 1)));
            }
            return ret;
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {
            String str = in.next();
            System.out.println(gao(str));
        }
    }
}

//Run# 	Author 	Problem 	Status 	Lang 	Time 	Memory 	Code 	Submission Date
//#485974 	watashi 	2428 	: Accepted 	JAVA 	00:21 sec 	13000 KB 	3481 Bytes 	Sun Sep 16 02:03:24

