// 双向搜索

import java.util.*;

abstract class Answer extends Throwable {
}

class Yes extends Answer {
    public String toString() {
        return "YES";
    }
}

class No extends Answer {
    public String toString() {
        return "NO";
    }
}

public class Main {
    static private final int[][] dir = new int[][]{
        new int[]{1, 0},
        new int[]{0, 1},
        new int[]{-1, 0},
        new int[]{0, -1}
    };

    static private int[][] pos = new int[4][2];
    static private boolean[][] map = new boolean[8][8];
    static private HashSet<Integer> set1 = null, set2 = null;

    enum Job {
        mov,
        chk
    }
    static private Job job;

    static private Integer toInteger(int[][] arr) {
        int[] tmp = new int[4];
        for (int i = 0; i < 4; ++i) {
            tmp[i] = (arr[i][0] << 3) + arr[i][1];
        }
        Arrays.sort(tmp);
        int ret = 0;
        for (int i = 0; i < 4; ++i) {
            ret = (ret << 6) + tmp[i];
        }
        return ret;
    }

    static private void dfs(int lv) throws Yes {
        if (job == Job.mov) {
            Integer tmp = toInteger(pos);
            if (!set1.add(tmp)) {
                // return;  // 只有每步做一个set才可以剪枝
            }
        } else if (job == Job.chk) {
            Integer tmp = toInteger(pos);
            if (!set2.add(tmp)) {
                // return;  // 只有每步做一个set才可以剪枝
            } else if (set1.contains(tmp)) {
                System.err.println(lv);
                throw new Yes();
            }
        }

        if (lv == 0) {
            return;
        } else {
            --lv;
        }
        for (int i = 0; i < 4; ++i) {
            final int x = pos[i][0];
            final int y = pos[i][1];
            map[x][y] = false;
            for (int d = 0; d < 4; ++d) {
                try {
                    int xx = x + dir[d][0];
                    int yy = y + dir[d][1];
                    if (map[xx][yy]) {
                        xx += dir[d][0];
                        yy += dir[d][1];
                        if (map[xx][yy]) {
                            throw new ArrayIndexOutOfBoundsException();
                        }
                    }

                    pos[i][0] = xx;
                    pos[i][1] = yy;
                    map[xx][yy] = true;
                    dfs(lv);
                    map[xx][yy] = false;
                } catch(ArrayIndexOutOfBoundsException dump) {
                }
            }
            pos[i][0] = x;
            pos[i][1] = y;
            map[x][y] = true;
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNextInt()) {
            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 8; ++j) {
                    map[i][j] = false;
                }
            }
            for (int i = 0; i < 4; ++i) {
                pos[i][0] = in.nextInt() - 1;
                pos[i][1] = in.nextInt() - 1;
                map[pos[i][0]][pos[i][1]] = true;
            }
            set1 = new HashSet<Integer>();
            try {
                job = Job.mov;
                dfs(4);
            } catch (Answer ans) {
                System.err.println(ans);
            }
            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 8; ++j) {
                    map[i][j] = false;
                }
            }
            for (int i = 0; i < 4; ++i) {
                pos[i][0] = in.nextInt() - 1;
                pos[i][1] = in.nextInt() - 1;
                map[pos[i][0]][pos[i][1]] = true;
            }
            set2 = new HashSet<Integer>();
            try {
                job = Job.chk;
                dfs(4);
                throw new No();
            } catch (Answer ans) {
                System.out.println(ans);
            }
            System.err.println(set1.size() + " " + set2.size());
        }
    }
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1758613   2009-02-06 06:57:10     Accepted    1505    Java    0   2018    watashi@Zodiac

// WA2dea4
// 错误的剪枝

/*
##BUG##
...
*/

// 2012-09-07 00:51:35 | Accepted | 1505 | Java | 510 | 2647 | watashi | Source
