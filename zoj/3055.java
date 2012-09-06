import java.io.*;

public class Main {
    static int ch;

    static int nextInt() throws IOException {
        int ret = 0;
        do {
            ch = System.in.read();
        } while (Character.isWhitespace(ch));
        while (Character.isDigit(ch)) {
            ret *= 10;
            ret += Character.digit(ch, 10);
            ch = System.in.read();
        }
        return ret;
    }

    static int n, m, k, p, q;
    static boolean[][] mark = new boolean[16][16];
    static int[][] map = new int[16][16];
    static int[] tmp = new int[16];
    static int[] a = new int[128], b = new int[128], c = new int[128];
    static int[] s = new int[1 << 20];

    static void print() {
        System.err.println();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                System.err.print(map[i][j] + " ");
            }
            System.err.println();
        }
    }

    static void fill() {
        for (int j = 0; j < m; ++j) {
            for (int i = n - 1; i >= 0; --i) {
                if (map[i][j] == 0) {
                    map[i][j] = s[p++];
                }
            }
        }
        // print();
    }

    static void down() {
        for (int j = 0; j < m; ++j) {
            int k = n - 1;
            for (int i = n - 1; i >= 0; --i) {
                if (map[i][j] > 0) {
                    map[k--][j] = map[i][j];
                } else if (map[i][j] < 0) {
                    mark[i][j] = true;
                }
            }
            for (int i = k; i >= 0; --i) {
                map[i][j] = 0;
            }
        }
        // print();
    }

    static boolean check () {
        boolean ret = false;
        for (int i = 0; i < n; ++i) {
            int k = 1;
            for (int j = 1; j <= m; ++j) {
                if (map[i][j] != 0 && Math.abs(map[i][j]) == Math.abs(map[i][j - 1])) {
                    ++k;
                } else {
                    if (k >= 3) {
                        ret = true;
                        for (int l = 1; l <= k; ++l) {
                            map[i][j - l] = -Math.abs(map[i][j - l]);
                        }
                    }
                    k = 1;
                }
            }
        }
        for (int j = 0; j < m; ++j) {
            int k = 1;
            for (int i = 1; i <= n; ++i) {
                if (map[i][j] != 0 && Math.abs(map[i][j]) == Math.abs(map[i - 1][j])) {
                    ++k;
                } else {
                    if (k >= 3) {
                        ret = true;
                        for (int l = 1; l <= k; ++l) {
                            map[i - l][j] = -Math.abs(map[i - l][j]);
                        }
                    }
                    k = 1;
                }
            }
        }
        // print();
        return ret;
    }

    static void gao(int a, int b, int c) {
        // print();
        if (a == 1) {
            for (int i = 0; i < m; ++i) {
                tmp[i] = map[b][i];
            }
            for (int i = 0; i < m; ++i) {
                map[b][i] = tmp[(i + c) % m];
            }
        } else if (a == 2) {
            for (int i = 0; i < n; ++i) {
                tmp[i] = map[i][b];
            }
            for (int i = 0; i < n; ++i) {
                map[i][b] = tmp[(i + c) % n];
            }
        }
        // print();
        if (check()) {
            do {
                // do {
                down();
                // } while (check());
                fill();
            } while (check());
        }/* else if (a == 1) {
            for (int i = 0; i < m; ++i) {
                map[b][i] = tmp[i];
            }
        } else if (a == 2) {
            for (int i = 0; i < n; ++i) {
                map[i][b] = tmp[i];
            }
        }*/
    }

    public static void main(String[] args) throws IOException {
        int re = nextInt();
        for (int ri = 1; ri <= re; ++ri) {
            n = nextInt();
            m = nextInt();
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    map[i][j] = nextInt();
                    mark[i][j] = false;
                }
            }
            for (int i = 0; i < n; ++i) {
                map[i][m] = 0;
            }
            for (int j = 0; j < m; ++j) {
                map[n][j] = 0;
            }
            k = nextInt();
            for (int i = 0; i < k; ++i) {
                a[i] = nextInt();
                b[i] = nextInt() - 1;
                c[i] = nextInt();
            }
            p = 0;
            for (int i = 0; ; ++i) {
                s[i] = nextInt();
                if (s[i] == 0) {
                    break;
                }
            }
            for (int i = 0; i < k; ++i) {
                gao(a[i], b[i], c[i]);
            }
            // print();
            q = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (mark[i][j]) {
                        ++q;
                    }
                }
            }
            System.out.println(q);
        }
    }
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1806135   2009-03-27 05:34:13     Accepted    3055    Java    0   4254    watashi@Zodiac

// 2012-09-07 01:58:58 | Accepted | 3055 | Java | 230 | 4320 | watashi | Source
