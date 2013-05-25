import javax.swing.*;
import java.awt.*;
import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.security.SecureRandom;
import java.util.Arrays;
import java.util.Random;

class Drawer extends JFrame {
    public static final int EXTRA_WIDTH = 100;
    public static final int EXTRA_HEIGHT = 100;

    class DrawerPanel extends JPanel {
        final Color[] COLORS = new Color[] {
                Color.RED,
                Color.GREEN,
                Color.BLUE,
                Color.MAGENTA,
                Color.DARK_GRAY
        };

        public void paint(Graphics g) {
            g.setColor(Color.GRAY);

            for (int i = 0; i <= N; i++) {
                g.drawLine(40 + i * cellSize, 40, 40 + i * cellSize, 40 + cellSize * N);
                g.drawLine(40, 40 + i * cellSize, 40 + cellSize * N, 40 + i * cellSize);
            }

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    g.setColor(COLORS[board[i][j] - 'a']);
                    g.fillRect(40 + j * cellSize + 1, 40 + i * cellSize + 1, cellSize - 2, cellSize - 2);
                }
            }

            g.setFont(new Font("Arial", Font.BOLD, 12));
            g.setColor(Color.BLACK);
            Graphics2D g2 = (Graphics2D)g;
            g2.drawString("Components: " + compCnt, 40, 20);
        }
    }

    DrawerPanel panel;
    int width, height;

    char[][] board;
    int compCnt;
    int cellSize;
    int N;

    public Drawer(int cellSize, char[][] board, int compCnt) {
        super();

        this.cellSize = cellSize;
        this.board = board;
        this.compCnt = compCnt;
        this.N = board.length;

        panel = new DrawerPanel();
        getContentPane().add(panel);

        width = cellSize * N + EXTRA_WIDTH;
        height = cellSize * N + EXTRA_HEIGHT;

        setSize(width, height);
        setTitle("Visualizer tool for problem StringConnectivity.");

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        setResizable(false);
        setVisible(true);
    }
}

public class StringConnectivityVis {
    public static String execCommand = null;
    public static long seed = 1;
    public static boolean vis = true;
    public static int cellSize = 8;

    public static Process solution;

    public static final int MIN_N = 30;
    public static final int MAX_N = 100;

    public static final int MIN_ALPH = 3;
    public static final int MAX_ALPH = 5;

    public static final int[] DR = new int[] {0, -1, 0, 1};
    public static final int[] DC = new int[] {1, 0, -1, 0};

    public double runTest() {
        solution = null;

        try {
            solution = Runtime.getRuntime().exec(execCommand);
        } catch (Exception e) {
            System.err.println("ERROR: Unable to execute your solution using the provided command: "
                    + execCommand + ".");
            System.exit(1);
        }

        BufferedReader reader = new BufferedReader(new InputStreamReader(solution.getInputStream()));
        PrintWriter writer = new PrintWriter(solution.getOutputStream());
        new ErrorStreamRedirector(solution.getErrorStream()).start();

        Random rnd = null;
        try {
            rnd = SecureRandom.getInstance("SHA1PRNG");
        } catch (Exception e) {
            System.err.println("ERROR: unable to generate test case.");
            System.exit(1);
        }

        rnd.setSeed(seed);

        int N = rnd.nextInt(MAX_N - MIN_N + 1) + MIN_N;
        int alph = rnd.nextInt(MAX_ALPH - MIN_ALPH + 1) + MIN_ALPH;

        StringBuilder sb = new StringBuilder();
        for (int i=0; i <  N * N; i++) {
            sb.append((char)((int)'a' + rnd.nextInt(alph)));
        }

        String S = sb.toString();

        writer.println(S);
        writer.flush();

        int[] ans = new int[N * N + 1];

        for (int i = 0; i <= N * N; i++) {
            try {
                ans[i] = Integer.parseInt(reader.readLine());
            } catch (Exception e) {
                System.err.println("ERROR: unable to parse element " + i + " of your return value.");
                e.printStackTrace();
                return 0.0;
            }
        }

        stopSolution();

        char[][] board = new char[N][N];
        for (int i = 0; i < N; i++) {
            Arrays.fill(board[i], ' ');
        }

        int curR = ans[0], curC = ans[1];
        for (int i = 0; i < N * N; i++) {
            if (curR < 0 || curR >= N || curC < 0 || curC >= N) {
                System.err.println("ERROR: The " + i + "-th (0-based) cell (" + curR + ", " + curC + ") in your solution is outside the board.");
                return 0.0;
            }
            if (board[curR][curC] != ' ') {
                System.err.println("ERROR: The " + i + "-th (0-based) cell (" + curR + ", " + curC + ") in your solution is already not empty.");
                return 0.0;
            }

            board[curR][curC] = S.charAt(i);

            if (i + 1 < N * N) {
                if (ans[i + 2] < 0 || ans[i + 2] > 3) {
                    System.err.println("ERROR: Element " + (i + 2) + " (0-based) must be in 0..3. In your return value it is " + ans[i + 2] + ".");
                    return 0.0;
                }
                curR += DR[ans[i + 2]];
                curC += DC[ans[i + 2]];
            }
        }

        int[][] compId = new int[N][N];
        int compCnt = 0;

        for (int i=0; i < compId.length; i++) {
            Arrays.fill(compId[i], -1);
        }

        int[] qR = new int[N * N];
        int[] qC = new int[N * N];
        int qBeg = 0, qEnd = 0;
        for (int i=0; i < N; i++)
            for (int j=0; j < N; j++)
                if (compId[i][j] == -1) {
                    qR[qBeg] = i;
                    qC[qBeg++] = j;
                    compId[i][j] = compCnt;

                    while (qEnd < qBeg) {
                        curR = qR[qEnd];
                        curC = qC[qEnd++];

                        for (int t=0; t < 4; t++)
                            if (curR + DR[t] >= 0 && curR + DR[t] < N && curC + DC[t] >= 0 && curC + DC[t] < N &&
                                board[curR][curC] == board[curR + DR[t]][curC + DC[t]] &&
                                compId[curR + DR[t]][curC + DC[t]] == -1) {
                                qR[qBeg] =  curR + DR[t];
                                qC[qBeg++] = curC + DC[t];
                                compId[curR + DR[t]][curC + DC[t]] = compCnt;
                            }
                    }

                    compCnt++;
                }

        if (vis) {
            new Drawer(cellSize, board, compCnt);
        }

        return compCnt;
    }

    public static void stopSolution() {
        if (solution != null) {
            try {
                solution.destroy();
            } catch (Exception e) {
                // do nothing
            }
        }
    }

    public static void main(String[] args) {
        for (int i = 0; i < args.length; i++)
            if (args[i].equals("-exec")) {
                execCommand = args[++i];
            } else if (args[i].equals("-seed")) {
                seed = Long.parseLong(args[++i]);
            } else if (args[i].equals("-novis")) {
                vis = false;
            } else if (args[i].equals("-sz")) {
                cellSize = Integer.parseInt(args[++i]);
            }  else {
                System.out.println("WARNING: unknown argument " + args[i] + ".");
            }

        if (execCommand == null) {
            System.err.println("ERROR: You did not provide the command to execute your solution." +
                    " Please use -exec <command> for this.");
            System.exit(1);
        }

        StringConnectivityVis vis = new StringConnectivityVis();
        try {
            double score = vis.runTest();
            System.out.println("Score  = " + score);
        } catch (RuntimeException e) {
            System.err.println("ERROR: Unexpected error while running your test case.");
            e.printStackTrace();
            StringConnectivityVis.stopSolution();
        }
    }
}

class ErrorStreamRedirector extends Thread {
    public BufferedReader reader;

    public ErrorStreamRedirector(InputStream is) {
        reader = new BufferedReader(new InputStreamReader(is));
    }

    public void run() {
        while (true) {
            String s;
            try {
                s = reader.readLine();
            } catch (Exception e) {
                // e.printStackTrace();
                return;
            }
            if (s == null) {
                break;
            }
            System.out.println(s);
        }
    }
}
