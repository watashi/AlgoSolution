import java.io.*;

public class Main {
    static final int code = 7;
    static final int[] dx = new int[]{0, 1, 0, -1};
    static final int[] dy = new int[]{1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        while (true) {
            String[] RC = in.readLine().split(" ");
            int R = Integer.parseInt(RC[0]), C = Integer.parseInt(RC[1]);

            if (R == 0 && C == 0) {
                break;
            }

            char[][] encode = new char[R][C];

            for (int i = 0; i < R; ++i) {
                in.read(encode[i], 0, C);
            }
            in.read();
            // in.readLine();

            int x = 0, y = 0, d = 0;
            char[] decode = new char[R * C];

            for (int i = 0; i < decode.length; ++i) {
                decode[i] = (char)(encode[x][y] - code);
                encode[x][y] = 0;
                try {
                    if (encode[x + dx[d]][y + dy[d]] == 0) {
                        throw new Exception();
                    }
                } catch (Exception e) {
                    d = (d + 1) % 4;
                } finally {
                    x += dx[d];
                    y += dy[d];
                }
            }
            System.out.println(new String(decode));
        }
    }
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1749916   2009-01-28 01:57:50     Accepted    3109    Java    0   137     watashi@Zodiac

// 2012-09-07 02:01:49 | Accepted | 3109 | Java | 20 | 268 | watashi | Source
