import java.math.*;
import java.util.*;

public class Main {
    static ArrayList<BigInteger> ans;

    static {
        ans = new ArrayList<BigInteger>();
        for (int i = 0; i < 502; ++i) {
            ans.add(BigInteger.ZERO);
        }
    }

    static void fill(int n, boolean[] mark) {
        for (int i = 1; i + i <= n; ++i) {
            if (mark[i] && mark[n - i]) {
                return;
            }
        }
        for (int i = 1; i + i <= n; ++i) {
            if (mark[n - i]) {
                mark[i] = true;
                fill(i, mark);
                return;
            }
        }
        for (int i = 2; i <= n; i += 2) {
            if (i == n || mark[n - i]) {
                mark[i] = true;
                if (!mark[i / 2]) {
                    mark[i / 2] = true;
                    fill(i / 2, mark);
                }
                return;
            }
        }
    }

    static ArrayList<BigInteger> slide(BigInteger n, int m) {
        ArrayList<Integer> ds = new ArrayList<Integer>();
        ArrayList<Integer> ws = new ArrayList<Integer>();
        for (int i = 0; i < n.bitLength(); i += m) {
            int w = 0;
            while (!n.testBit(i)) {
                ++i;
                ++w;
            }
            if (w > 0) {
                ds.add(0);
                ws.add(w);
            }
            int x = 0;
            for (int j = 0; j < m; ++j) {
                if (n.testBit(i + j)) {
                    x ^= 1 << j;
                }
            }
            ds.add(x);
            ws.add(m);
        }
        Collections.reverse(ds);
        Collections.reverse(ws);

        boolean[] mark = new boolean[1 << m];
        mark[1] = true;
        for (int x: ds) {
            mark[x] = true;
        }
        for (int i = 2; i < (1 << m); ++i) {
            if (mark[i]) {
                fill(i, mark);
            }
        }

        HashSet<BigInteger> ret = new HashSet<BigInteger>();
        for (int i = 1; i < (1 << m); ++i) {
            if (mark[i]) {
                ret.add(BigInteger.valueOf(i));
            }
        }

        BigInteger cur = BigInteger.valueOf(ds.get(0));
        ret.add(cur);
        for (int i = 1; i < ds.size(); ++i) {
            for (int j = 0; j < ws.get(i); ++j) {
                cur = cur.shiftLeft(1);
                ret.add(cur);
            }
            if (ds.get(i) != 0) {
                cur = cur.add(BigInteger.valueOf(ds.get(i)));
                ret.add(cur);
            }
        }

        return new ArrayList<BigInteger>(ret);
    }

    static ArrayList<BigInteger> gao(BigInteger n, int m) {
        ArrayList<BigInteger> ret = new ArrayList<BigInteger>(ans.size());
        ret.add(n);
        while (ret.size() < ans.size() && n.compareTo(TWO) > 0) {
            int k = -1;
            for (int i = m - 1; i >= 0; --i) {
                BigInteger r = n.mod(TODO[i][0]);
                if (r.signum() == 0) {
                    k = i;
                    break;
                } else if (r.compareTo(TWO) <= 0) {
                    k = Math.max(k, i);
                }
            }
            BigInteger r = n.mod(TODO[k][0]);
            if (r.signum() > 0) {
                n = n.subtract(r);
                ret.add(n);
            }
            n = n.divide(TODO[k][0]);
            for (int j = 1; j < TODO[k].length; ++j) {
                ret.add(n.multiply(TODO[k][j]));
            }
        }
        if (n.equals(TWO)) {
            ret.add(BigInteger.ONE);
        }
        return ret;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        BigInteger n = in.nextBigInteger();
        for (int w = 1; w < 12; ++w) {
            ArrayList<BigInteger> tmp = slide(n, w);
            if (tmp.size() < ans.size()) {
                ans = tmp;
            }
        }
        for (int m = TODO.length; m > 0; m -= TODO.length) {
            ArrayList<BigInteger> tmp = gao(n, m);
            if (tmp.size() < ans.size()) {
                ans = tmp;
            }
        }

        HashMap<BigInteger, Integer> h = new HashMap<BigInteger, Integer>();
        Collections.sort(ans);
        for (int i = 0; i < ans.size(); ++i) {
            h.put(ans.get(i), i);
        }

        System.out.println(ans.size() - 1);
        for (int i = 1; i < ans.size(); ++i) {
            for (int j = 0; ; ++j) {
                Integer k = h.get(ans.get(i).subtract(ans.get(j)));
                if (k != null) {
                    System.out.println(j + " " + k);
                    break;
                }
            }
        }
    }

    static final BigInteger TWO = BigInteger.valueOf(2);

    static final BigInteger[][] TODO = {
{BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(15), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(23), BigInteger.valueOf(13), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(27), BigInteger.valueOf(18), BigInteger.valueOf(9), BigInteger.valueOf(6), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(30), BigInteger.valueOf(15), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(31), BigInteger.valueOf(17), BigInteger.valueOf(14), BigInteger.valueOf(7), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(39), BigInteger.valueOf(26), BigInteger.valueOf(13), BigInteger.valueOf(8), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(43), BigInteger.valueOf(23), BigInteger.valueOf(20), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(45), BigInteger.valueOf(30), BigInteger.valueOf(15), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(46), BigInteger.valueOf(23), BigInteger.valueOf(13), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(47), BigInteger.valueOf(27), BigInteger.valueOf(20), BigInteger.valueOf(10), BigInteger.valueOf(7), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(51), BigInteger.valueOf(27), BigInteger.valueOf(24), BigInteger.valueOf(12), BigInteger.valueOf(6), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(54), BigInteger.valueOf(27), BigInteger.valueOf(18), BigInteger.valueOf(9), BigInteger.valueOf(6), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(55), BigInteger.valueOf(33), BigInteger.valueOf(22), BigInteger.valueOf(11), BigInteger.valueOf(7), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(59), BigInteger.valueOf(31), BigInteger.valueOf(28), BigInteger.valueOf(14), BigInteger.valueOf(7), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(60), BigInteger.valueOf(30), BigInteger.valueOf(15), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(61), BigInteger.valueOf(33), BigInteger.valueOf(28), BigInteger.valueOf(14), BigInteger.valueOf(7), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(62), BigInteger.valueOf(31), BigInteger.valueOf(17), BigInteger.valueOf(14), BigInteger.valueOf(7), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(63), BigInteger.valueOf(42), BigInteger.valueOf(21), BigInteger.valueOf(14), BigInteger.valueOf(7), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(75), BigInteger.valueOf(50), BigInteger.valueOf(25), BigInteger.valueOf(15), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(77), BigInteger.valueOf(41), BigInteger.valueOf(36), BigInteger.valueOf(18), BigInteger.valueOf(9), BigInteger.valueOf(5), BigInteger.valueOf(4), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(78), BigInteger.valueOf(39), BigInteger.valueOf(26), BigInteger.valueOf(13), BigInteger.valueOf(8), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(79), BigInteger.valueOf(43), BigInteger.valueOf(36), BigInteger.valueOf(18), BigInteger.valueOf(9), BigInteger.valueOf(7), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(83), BigInteger.valueOf(43), BigInteger.valueOf(40), BigInteger.valueOf(20), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(85), BigInteger.valueOf(45), BigInteger.valueOf(40), BigInteger.valueOf(20), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(86), BigInteger.valueOf(43), BigInteger.valueOf(23), BigInteger.valueOf(20), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(87), BigInteger.valueOf(47), BigInteger.valueOf(40), BigInteger.valueOf(20), BigInteger.valueOf(10), BigInteger.valueOf(7), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(90), BigInteger.valueOf(45), BigInteger.valueOf(30), BigInteger.valueOf(15), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(91), BigInteger.valueOf(47), BigInteger.valueOf(44), BigInteger.valueOf(22), BigInteger.valueOf(11), BigInteger.valueOf(7), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(92), BigInteger.valueOf(46), BigInteger.valueOf(23), BigInteger.valueOf(13), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(93), BigInteger.valueOf(62), BigInteger.valueOf(31), BigInteger.valueOf(17), BigInteger.valueOf(14), BigInteger.valueOf(7), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(94), BigInteger.valueOf(47), BigInteger.valueOf(27), BigInteger.valueOf(20), BigInteger.valueOf(10), BigInteger.valueOf(7), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(95), BigInteger.valueOf(51), BigInteger.valueOf(44), BigInteger.valueOf(22), BigInteger.valueOf(11), BigInteger.valueOf(7), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(99), BigInteger.valueOf(51), BigInteger.valueOf(48), BigInteger.valueOf(24), BigInteger.valueOf(12), BigInteger.valueOf(6), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(102), BigInteger.valueOf(51), BigInteger.valueOf(27), BigInteger.valueOf(24), BigInteger.valueOf(12), BigInteger.valueOf(6), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(103), BigInteger.valueOf(55), BigInteger.valueOf(48), BigInteger.valueOf(24), BigInteger.valueOf(12), BigInteger.valueOf(7), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(107), BigInteger.valueOf(55), BigInteger.valueOf(52), BigInteger.valueOf(26), BigInteger.valueOf(13), BigInteger.valueOf(8), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(108), BigInteger.valueOf(54), BigInteger.valueOf(27), BigInteger.valueOf(18), BigInteger.valueOf(9), BigInteger.valueOf(6), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(109), BigInteger.valueOf(57), BigInteger.valueOf(52), BigInteger.valueOf(26), BigInteger.valueOf(13), BigInteger.valueOf(8), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(110), BigInteger.valueOf(55), BigInteger.valueOf(33), BigInteger.valueOf(22), BigInteger.valueOf(11), BigInteger.valueOf(7), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(111), BigInteger.valueOf(74), BigInteger.valueOf(37), BigInteger.valueOf(21), BigInteger.valueOf(16), BigInteger.valueOf(8), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(115), BigInteger.valueOf(59), BigInteger.valueOf(56), BigInteger.valueOf(28), BigInteger.valueOf(14), BigInteger.valueOf(7), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(117), BigInteger.valueOf(61), BigInteger.valueOf(56), BigInteger.valueOf(28), BigInteger.valueOf(14), BigInteger.valueOf(7), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(118), BigInteger.valueOf(59), BigInteger.valueOf(31), BigInteger.valueOf(28), BigInteger.valueOf(14), BigInteger.valueOf(7), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(119), BigInteger.valueOf(63), BigInteger.valueOf(56), BigInteger.valueOf(28), BigInteger.valueOf(14), BigInteger.valueOf(7), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(120), BigInteger.valueOf(60), BigInteger.valueOf(30), BigInteger.valueOf(15), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(121), BigInteger.valueOf(61), BigInteger.valueOf(60), BigInteger.valueOf(30), BigInteger.valueOf(15), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(122), BigInteger.valueOf(61), BigInteger.valueOf(33), BigInteger.valueOf(28), BigInteger.valueOf(14), BigInteger.valueOf(7), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(123), BigInteger.valueOf(63), BigInteger.valueOf(60), BigInteger.valueOf(30), BigInteger.valueOf(15), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(124), BigInteger.valueOf(62), BigInteger.valueOf(31), BigInteger.valueOf(17), BigInteger.valueOf(14), BigInteger.valueOf(7), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(125), BigInteger.valueOf(75), BigInteger.valueOf(50), BigInteger.valueOf(25), BigInteger.valueOf(15), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(126), BigInteger.valueOf(63), BigInteger.valueOf(42), BigInteger.valueOf(21), BigInteger.valueOf(14), BigInteger.valueOf(7), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(127), BigInteger.valueOf(67), BigInteger.valueOf(60), BigInteger.valueOf(30), BigInteger.valueOf(15), BigInteger.valueOf(8), BigInteger.valueOf(7), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(135), BigInteger.valueOf(90), BigInteger.valueOf(45), BigInteger.valueOf(30), BigInteger.valueOf(15), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(143), BigInteger.valueOf(75), BigInteger.valueOf(68), BigInteger.valueOf(34), BigInteger.valueOf(17), BigInteger.valueOf(10), BigInteger.valueOf(7), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(147), BigInteger.valueOf(75), BigInteger.valueOf(72), BigInteger.valueOf(36), BigInteger.valueOf(18), BigInteger.valueOf(9), BigInteger.valueOf(6), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(149), BigInteger.valueOf(77), BigInteger.valueOf(72), BigInteger.valueOf(36), BigInteger.valueOf(18), BigInteger.valueOf(9), BigInteger.valueOf(5), BigInteger.valueOf(4), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(150), BigInteger.valueOf(75), BigInteger.valueOf(50), BigInteger.valueOf(25), BigInteger.valueOf(15), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(151), BigInteger.valueOf(79), BigInteger.valueOf(72), BigInteger.valueOf(36), BigInteger.valueOf(18), BigInteger.valueOf(9), BigInteger.valueOf(7), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(153), BigInteger.valueOf(81), BigInteger.valueOf(72), BigInteger.valueOf(36), BigInteger.valueOf(18), BigInteger.valueOf(9), BigInteger.valueOf(6), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(154), BigInteger.valueOf(77), BigInteger.valueOf(41), BigInteger.valueOf(36), BigInteger.valueOf(18), BigInteger.valueOf(9), BigInteger.valueOf(5), BigInteger.valueOf(4), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(155), BigInteger.valueOf(83), BigInteger.valueOf(72), BigInteger.valueOf(36), BigInteger.valueOf(18), BigInteger.valueOf(11), BigInteger.valueOf(7), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(156), BigInteger.valueOf(78), BigInteger.valueOf(39), BigInteger.valueOf(26), BigInteger.valueOf(13), BigInteger.valueOf(8), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(157), BigInteger.valueOf(81), BigInteger.valueOf(76), BigInteger.valueOf(38), BigInteger.valueOf(19), BigInteger.valueOf(12), BigInteger.valueOf(7), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(158), BigInteger.valueOf(79), BigInteger.valueOf(43), BigInteger.valueOf(36), BigInteger.valueOf(18), BigInteger.valueOf(9), BigInteger.valueOf(7), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(159), BigInteger.valueOf(89), BigInteger.valueOf(70), BigInteger.valueOf(35), BigInteger.valueOf(19), BigInteger.valueOf(16), BigInteger.valueOf(8), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(163), BigInteger.valueOf(83), BigInteger.valueOf(80), BigInteger.valueOf(40), BigInteger.valueOf(20), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(165), BigInteger.valueOf(85), BigInteger.valueOf(80), BigInteger.valueOf(40), BigInteger.valueOf(20), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(166), BigInteger.valueOf(83), BigInteger.valueOf(43), BigInteger.valueOf(40), BigInteger.valueOf(20), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(167), BigInteger.valueOf(87), BigInteger.valueOf(80), BigInteger.valueOf(40), BigInteger.valueOf(20), BigInteger.valueOf(10), BigInteger.valueOf(7), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(170), BigInteger.valueOf(85), BigInteger.valueOf(45), BigInteger.valueOf(40), BigInteger.valueOf(20), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(171), BigInteger.valueOf(87), BigInteger.valueOf(84), BigInteger.valueOf(42), BigInteger.valueOf(21), BigInteger.valueOf(14), BigInteger.valueOf(7), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(172), BigInteger.valueOf(86), BigInteger.valueOf(43), BigInteger.valueOf(23), BigInteger.valueOf(20), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(173), BigInteger.valueOf(89), BigInteger.valueOf(84), BigInteger.valueOf(42), BigInteger.valueOf(21), BigInteger.valueOf(14), BigInteger.valueOf(7), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(174), BigInteger.valueOf(87), BigInteger.valueOf(47), BigInteger.valueOf(40), BigInteger.valueOf(20), BigInteger.valueOf(10), BigInteger.valueOf(7), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(175), BigInteger.valueOf(105), BigInteger.valueOf(70), BigInteger.valueOf(35), BigInteger.valueOf(21), BigInteger.valueOf(14), BigInteger.valueOf(7), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(179), BigInteger.valueOf(91), BigInteger.valueOf(88), BigInteger.valueOf(44), BigInteger.valueOf(22), BigInteger.valueOf(11), BigInteger.valueOf(7), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(180), BigInteger.valueOf(90), BigInteger.valueOf(45), BigInteger.valueOf(30), BigInteger.valueOf(15), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(181), BigInteger.valueOf(93), BigInteger.valueOf(88), BigInteger.valueOf(44), BigInteger.valueOf(22), BigInteger.valueOf(11), BigInteger.valueOf(6), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(182), BigInteger.valueOf(91), BigInteger.valueOf(47), BigInteger.valueOf(44), BigInteger.valueOf(22), BigInteger.valueOf(11), BigInteger.valueOf(7), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(183), BigInteger.valueOf(95), BigInteger.valueOf(88), BigInteger.valueOf(44), BigInteger.valueOf(22), BigInteger.valueOf(11), BigInteger.valueOf(7), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(184), BigInteger.valueOf(92), BigInteger.valueOf(46), BigInteger.valueOf(23), BigInteger.valueOf(13), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(185), BigInteger.valueOf(111), BigInteger.valueOf(74), BigInteger.valueOf(37), BigInteger.valueOf(21), BigInteger.valueOf(16), BigInteger.valueOf(8), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(186), BigInteger.valueOf(93), BigInteger.valueOf(62), BigInteger.valueOf(31), BigInteger.valueOf(17), BigInteger.valueOf(14), BigInteger.valueOf(7), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(187), BigInteger.valueOf(99), BigInteger.valueOf(88), BigInteger.valueOf(44), BigInteger.valueOf(22), BigInteger.valueOf(11), BigInteger.valueOf(7), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(188), BigInteger.valueOf(94), BigInteger.valueOf(47), BigInteger.valueOf(27), BigInteger.valueOf(20), BigInteger.valueOf(10), BigInteger.valueOf(7), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(189), BigInteger.valueOf(126), BigInteger.valueOf(63), BigInteger.valueOf(42), BigInteger.valueOf(21), BigInteger.valueOf(14), BigInteger.valueOf(7), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(190), BigInteger.valueOf(95), BigInteger.valueOf(51), BigInteger.valueOf(44), BigInteger.valueOf(22), BigInteger.valueOf(11), BigInteger.valueOf(7), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(195), BigInteger.valueOf(99), BigInteger.valueOf(96), BigInteger.valueOf(48), BigInteger.valueOf(24), BigInteger.valueOf(12), BigInteger.valueOf(6), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(198), BigInteger.valueOf(99), BigInteger.valueOf(51), BigInteger.valueOf(48), BigInteger.valueOf(24), BigInteger.valueOf(12), BigInteger.valueOf(6), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(199), BigInteger.valueOf(103), BigInteger.valueOf(96), BigInteger.valueOf(48), BigInteger.valueOf(24), BigInteger.valueOf(12), BigInteger.valueOf(7), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(203), BigInteger.valueOf(103), BigInteger.valueOf(100), BigInteger.valueOf(50), BigInteger.valueOf(25), BigInteger.valueOf(15), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(204), BigInteger.valueOf(102), BigInteger.valueOf(51), BigInteger.valueOf(27), BigInteger.valueOf(24), BigInteger.valueOf(12), BigInteger.valueOf(6), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(205), BigInteger.valueOf(105), BigInteger.valueOf(100), BigInteger.valueOf(50), BigInteger.valueOf(25), BigInteger.valueOf(15), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(206), BigInteger.valueOf(103), BigInteger.valueOf(55), BigInteger.valueOf(48), BigInteger.valueOf(24), BigInteger.valueOf(12), BigInteger.valueOf(7), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(207), BigInteger.valueOf(138), BigInteger.valueOf(69), BigInteger.valueOf(37), BigInteger.valueOf(32), BigInteger.valueOf(16), BigInteger.valueOf(8), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(211), BigInteger.valueOf(107), BigInteger.valueOf(104), BigInteger.valueOf(52), BigInteger.valueOf(26), BigInteger.valueOf(13), BigInteger.valueOf(8), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(213), BigInteger.valueOf(109), BigInteger.valueOf(104), BigInteger.valueOf(52), BigInteger.valueOf(26), BigInteger.valueOf(13), BigInteger.valueOf(8), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(214), BigInteger.valueOf(107), BigInteger.valueOf(55), BigInteger.valueOf(52), BigInteger.valueOf(26), BigInteger.valueOf(13), BigInteger.valueOf(8), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(215), BigInteger.valueOf(115), BigInteger.valueOf(100), BigInteger.valueOf(50), BigInteger.valueOf(25), BigInteger.valueOf(15), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(216), BigInteger.valueOf(108), BigInteger.valueOf(54), BigInteger.valueOf(27), BigInteger.valueOf(18), BigInteger.valueOf(9), BigInteger.valueOf(6), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(217), BigInteger.valueOf(109), BigInteger.valueOf(108), BigInteger.valueOf(54), BigInteger.valueOf(27), BigInteger.valueOf(18), BigInteger.valueOf(9), BigInteger.valueOf(6), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(218), BigInteger.valueOf(109), BigInteger.valueOf(57), BigInteger.valueOf(52), BigInteger.valueOf(26), BigInteger.valueOf(13), BigInteger.valueOf(8), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(219), BigInteger.valueOf(111), BigInteger.valueOf(108), BigInteger.valueOf(54), BigInteger.valueOf(27), BigInteger.valueOf(18), BigInteger.valueOf(9), BigInteger.valueOf(6), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(220), BigInteger.valueOf(110), BigInteger.valueOf(55), BigInteger.valueOf(33), BigInteger.valueOf(22), BigInteger.valueOf(11), BigInteger.valueOf(7), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(221), BigInteger.valueOf(117), BigInteger.valueOf(104), BigInteger.valueOf(52), BigInteger.valueOf(26), BigInteger.valueOf(13), BigInteger.valueOf(8), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(222), BigInteger.valueOf(111), BigInteger.valueOf(74), BigInteger.valueOf(37), BigInteger.valueOf(21), BigInteger.valueOf(16), BigInteger.valueOf(8), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(227), BigInteger.valueOf(115), BigInteger.valueOf(112), BigInteger.valueOf(56), BigInteger.valueOf(28), BigInteger.valueOf(14), BigInteger.valueOf(7), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(229), BigInteger.valueOf(117), BigInteger.valueOf(112), BigInteger.valueOf(56), BigInteger.valueOf(28), BigInteger.valueOf(14), BigInteger.valueOf(7), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(230), BigInteger.valueOf(115), BigInteger.valueOf(59), BigInteger.valueOf(56), BigInteger.valueOf(28), BigInteger.valueOf(14), BigInteger.valueOf(7), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(231), BigInteger.valueOf(119), BigInteger.valueOf(112), BigInteger.valueOf(56), BigInteger.valueOf(28), BigInteger.valueOf(14), BigInteger.valueOf(7), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(233), BigInteger.valueOf(121), BigInteger.valueOf(112), BigInteger.valueOf(56), BigInteger.valueOf(28), BigInteger.valueOf(14), BigInteger.valueOf(9), BigInteger.valueOf(5), BigInteger.valueOf(4), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(234), BigInteger.valueOf(117), BigInteger.valueOf(61), BigInteger.valueOf(56), BigInteger.valueOf(28), BigInteger.valueOf(14), BigInteger.valueOf(7), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(236), BigInteger.valueOf(118), BigInteger.valueOf(59), BigInteger.valueOf(31), BigInteger.valueOf(28), BigInteger.valueOf(14), BigInteger.valueOf(7), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(238), BigInteger.valueOf(119), BigInteger.valueOf(63), BigInteger.valueOf(56), BigInteger.valueOf(28), BigInteger.valueOf(14), BigInteger.valueOf(7), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(240), BigInteger.valueOf(120), BigInteger.valueOf(60), BigInteger.valueOf(30), BigInteger.valueOf(15), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(241), BigInteger.valueOf(121), BigInteger.valueOf(120), BigInteger.valueOf(60), BigInteger.valueOf(30), BigInteger.valueOf(15), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(242), BigInteger.valueOf(121), BigInteger.valueOf(61), BigInteger.valueOf(60), BigInteger.valueOf(30), BigInteger.valueOf(15), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(243), BigInteger.valueOf(123), BigInteger.valueOf(120), BigInteger.valueOf(60), BigInteger.valueOf(30), BigInteger.valueOf(15), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(244), BigInteger.valueOf(122), BigInteger.valueOf(61), BigInteger.valueOf(33), BigInteger.valueOf(28), BigInteger.valueOf(14), BigInteger.valueOf(7), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(245), BigInteger.valueOf(125), BigInteger.valueOf(120), BigInteger.valueOf(60), BigInteger.valueOf(30), BigInteger.valueOf(15), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(246), BigInteger.valueOf(123), BigInteger.valueOf(63), BigInteger.valueOf(60), BigInteger.valueOf(30), BigInteger.valueOf(15), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(248), BigInteger.valueOf(124), BigInteger.valueOf(62), BigInteger.valueOf(31), BigInteger.valueOf(17), BigInteger.valueOf(14), BigInteger.valueOf(7), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(249), BigInteger.valueOf(166), BigInteger.valueOf(83), BigInteger.valueOf(43), BigInteger.valueOf(40), BigInteger.valueOf(20), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(250), BigInteger.valueOf(125), BigInteger.valueOf(75), BigInteger.valueOf(50), BigInteger.valueOf(25), BigInteger.valueOf(15), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(252), BigInteger.valueOf(126), BigInteger.valueOf(63), BigInteger.valueOf(42), BigInteger.valueOf(21), BigInteger.valueOf(14), BigInteger.valueOf(7), BigInteger.valueOf(4), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(255), BigInteger.valueOf(135), BigInteger.valueOf(120), BigInteger.valueOf(60), BigInteger.valueOf(30), BigInteger.valueOf(15), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(270), BigInteger.valueOf(135), BigInteger.valueOf(90), BigInteger.valueOf(45), BigInteger.valueOf(30), BigInteger.valueOf(15), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(281), BigInteger.valueOf(145), BigInteger.valueOf(136), BigInteger.valueOf(68), BigInteger.valueOf(34), BigInteger.valueOf(17), BigInteger.valueOf(9), BigInteger.valueOf(8), BigInteger.valueOf(4), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(291), BigInteger.valueOf(147), BigInteger.valueOf(144), BigInteger.valueOf(72), BigInteger.valueOf(36), BigInteger.valueOf(18), BigInteger.valueOf(9), BigInteger.valueOf(6), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(293), BigInteger.valueOf(149), BigInteger.valueOf(144), BigInteger.valueOf(72), BigInteger.valueOf(36), BigInteger.valueOf(18), BigInteger.valueOf(9), BigInteger.valueOf(5), BigInteger.valueOf(4), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(294), BigInteger.valueOf(147), BigInteger.valueOf(75), BigInteger.valueOf(72), BigInteger.valueOf(36), BigInteger.valueOf(18), BigInteger.valueOf(9), BigInteger.valueOf(6), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(297), BigInteger.valueOf(153), BigInteger.valueOf(144), BigInteger.valueOf(72), BigInteger.valueOf(36), BigInteger.valueOf(18), BigInteger.valueOf(9), BigInteger.valueOf(6), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(298), BigInteger.valueOf(149), BigInteger.valueOf(77), BigInteger.valueOf(72), BigInteger.valueOf(36), BigInteger.valueOf(18), BigInteger.valueOf(9), BigInteger.valueOf(5), BigInteger.valueOf(4), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(300), BigInteger.valueOf(150), BigInteger.valueOf(75), BigInteger.valueOf(50), BigInteger.valueOf(25), BigInteger.valueOf(15), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(306), BigInteger.valueOf(153), BigInteger.valueOf(81), BigInteger.valueOf(72), BigInteger.valueOf(36), BigInteger.valueOf(18), BigInteger.valueOf(9), BigInteger.valueOf(6), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(308), BigInteger.valueOf(154), BigInteger.valueOf(77), BigInteger.valueOf(41), BigInteger.valueOf(36), BigInteger.valueOf(18), BigInteger.valueOf(9), BigInteger.valueOf(5), BigInteger.valueOf(4), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(312), BigInteger.valueOf(156), BigInteger.valueOf(78), BigInteger.valueOf(39), BigInteger.valueOf(26), BigInteger.valueOf(13), BigInteger.valueOf(8), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(323), BigInteger.valueOf(163), BigInteger.valueOf(160), BigInteger.valueOf(80), BigInteger.valueOf(40), BigInteger.valueOf(20), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(325), BigInteger.valueOf(165), BigInteger.valueOf(160), BigInteger.valueOf(80), BigInteger.valueOf(40), BigInteger.valueOf(20), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(326), BigInteger.valueOf(163), BigInteger.valueOf(83), BigInteger.valueOf(80), BigInteger.valueOf(40), BigInteger.valueOf(20), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(330), BigInteger.valueOf(165), BigInteger.valueOf(85), BigInteger.valueOf(80), BigInteger.valueOf(40), BigInteger.valueOf(20), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(332), BigInteger.valueOf(166), BigInteger.valueOf(83), BigInteger.valueOf(43), BigInteger.valueOf(40), BigInteger.valueOf(20), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(340), BigInteger.valueOf(170), BigInteger.valueOf(85), BigInteger.valueOf(45), BigInteger.valueOf(40), BigInteger.valueOf(20), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(344), BigInteger.valueOf(172), BigInteger.valueOf(86), BigInteger.valueOf(43), BigInteger.valueOf(23), BigInteger.valueOf(20), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(360), BigInteger.valueOf(180), BigInteger.valueOf(90), BigInteger.valueOf(45), BigInteger.valueOf(30), BigInteger.valueOf(15), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(368), BigInteger.valueOf(184), BigInteger.valueOf(92), BigInteger.valueOf(46), BigInteger.valueOf(23), BigInteger.valueOf(13), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(387), BigInteger.valueOf(195), BigInteger.valueOf(192), BigInteger.valueOf(96), BigInteger.valueOf(48), BigInteger.valueOf(24), BigInteger.valueOf(12), BigInteger.valueOf(6), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(390), BigInteger.valueOf(195), BigInteger.valueOf(99), BigInteger.valueOf(96), BigInteger.valueOf(48), BigInteger.valueOf(24), BigInteger.valueOf(12), BigInteger.valueOf(6), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(396), BigInteger.valueOf(198), BigInteger.valueOf(99), BigInteger.valueOf(51), BigInteger.valueOf(48), BigInteger.valueOf(24), BigInteger.valueOf(12), BigInteger.valueOf(6), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(408), BigInteger.valueOf(204), BigInteger.valueOf(102), BigInteger.valueOf(51), BigInteger.valueOf(27), BigInteger.valueOf(24), BigInteger.valueOf(12), BigInteger.valueOf(6), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(432), BigInteger.valueOf(216), BigInteger.valueOf(108), BigInteger.valueOf(54), BigInteger.valueOf(27), BigInteger.valueOf(18), BigInteger.valueOf(9), BigInteger.valueOf(6), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
{BigInteger.valueOf(480), BigInteger.valueOf(240), BigInteger.valueOf(120), BigInteger.valueOf(60), BigInteger.valueOf(30), BigInteger.valueOf(15), BigInteger.valueOf(10), BigInteger.valueOf(5), BigInteger.valueOf(3), BigInteger.valueOf(2), BigInteger.valueOf(1)},
    };
}
