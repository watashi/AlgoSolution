import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.security.SecureRandom;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

class Cell {
    int r, c;
    public Cell(int r, int c) {
        this.r = r;
        this.c = c;
    }
}

class Board {
    final int[] DR = new int[] {-1, 0, 1, 0};
    final int[] DC = new int[] {0, 1, 0, -1};

    final int[] LL = new int[] {1, 0, 3, 2};
    final int[] RR = new int[] {3, 2, 1, 0};

    int N;
    char[][] what;

    public Board(String[] board) {
        this.N = board.length;
        this.what = new char[N][];
        for (int i=0; i < N; i++) {
            this.what[i] = board[i].toCharArray();
        }
    }

    List<Cell> shootRay(int r, int c, int d) {
        int curR = r;
        int curC = c;
        int curD = d;

        List<Cell> res = new ArrayList<Cell>();
        res.add(new Cell(curR, curC));
        curR += DR[curD];
        curC += DC[curD];

        while (curR >= 0 && curR < N && curC >= 0 && curC < N) {
            if (what[curR][curC] == 'L' || what[curR][curC] == 'R') {
                res.add(new Cell(curR, curC));
                curD = (what[curR][curC] == 'L' ? LL[curD] : RR[curD]);
                what[curR][curC] = (what[curR][curC] == 'L' ? 'l' : 'r');
            }
            curR += DR[curD];
            curC += DC[curD];
        }

        res.add(new Cell(curR, curC));
        return res;
    }

    void cleanCells(List<Cell> ray) {
        for (Cell cell : ray) {
            if (cell.r >= 0 && cell.r < N && cell.c >= 0 && cell.c < N) {
                what[cell.r][cell.c] = '~';
            }
        }
    }
}

class Drawer extends JFrame {
    public static final int EXTRA_WIDTH = 100;
    public static final int EXTRA_HEIGHT = 100;

    public int rayCnt;

    class DrawerPanel extends JPanel {
        public void paint(Graphics g) {
            synchronized (paintMutex) {
                g.setColor(Color.GRAY);

                for (int i = 0; i <= N; i++) {
                    g.drawLine(30 + (i + 1) * cellSize, 30 + cellSize, 30 + (i + 1) * cellSize, 30 + cellSize * (N + 1));
                    g.drawLine(30 + cellSize, 30 + (i + 1) * cellSize, 30 + cellSize * (N + 1), 30 + (i + 1) * cellSize);
                }

                g.setColor(Color.BLACK);
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        if (field.what[i][j] == 'L' || field.what[i][j] == 'l') {
                            g.drawLine(30 + (j + 2) * cellSize, 30 + (i + 1) * cellSize, 30 + (j + 1) * cellSize, 30 + (i + 2) * cellSize);
                        }
                        if (field.what[i][j] == 'R' || field.what[i][j] == 'r') {
                            g.drawLine(30 + (j + 1) * cellSize, 30 + (i + 1) * cellSize, 30 + (j + 2) * cellSize, 30 + (i + 2) * cellSize);
                        }
                    }
                }

                g.setFont(new Font("Arial", Font.BOLD, 12));
                Graphics2D g2 = (Graphics2D)g;
                g2.drawString("Rays: " + rayCnt, 30 + cellSize, 20);

                if (ray != null) {
                    g.setColor(Color.RED);
                    for (int i = 0; i + 1 < ray.size(); i++) {
                        int ySt = 30 + ray.get(i).r * cellSize + cellSize / 2 + cellSize;
                        int xSt = 30 + ray.get(i).c * cellSize + cellSize / 2 + cellSize;
                        int yFn = 30 + ray.get(i+1).r * cellSize + cellSize / 2 + cellSize;
                        int xFn = 30 + ray.get(i+1).c * cellSize + cellSize / 2 + cellSize;

                        g.drawLine(xSt, ySt, xFn, yFn);

                        if (ray.get(i).c < ray.get(i+1).c) {
                            for (int d = 1; d <= arrowSize; d++) {
                                g.drawLine(xFn - d, yFn - d, xFn - d, yFn + d);
                            }
                        }

                        if (ray.get(i).c > ray.get(i+1).c) {
                            for (int d = 1; d <= arrowSize; d++) {
                                g.drawLine(xFn + d, yFn - d, xFn + d, yFn + d);
                            }
                        }

                        if (ray.get(i).r < ray.get(i+1).r) {
                            for (int d = 1; d <= arrowSize; d++) {
                                g.drawLine(xFn - d, yFn - d, xFn + d, yFn - d);
                            }
                        }

                        if (ray.get(i).r > ray.get(i+1).r) {
                            for (int d = 1; d <= arrowSize; d++) {
                                g.drawLine(xFn - d, yFn + d, xFn + d, yFn + d);
                            }
                        }
                    }
                }
            }
        }
    }

    List<Cell> ray = null;
    final Object keyMutex = new Object();
    boolean keyPressed;
    public boolean pauseMode = false;

    class DrawerKeyListener extends KeyAdapter {
        public void keyPressed(KeyEvent e) {
            synchronized (keyMutex) {
                if (e.getKeyChar() == ' ') {
                    pauseMode = !pauseMode;
                }
                keyPressed = true;
                keyMutex.notifyAll();
            }
        }
    }

    public void processPause() {
        synchronized (keyMutex) {
            if (!pauseMode) {
                return;
            }
            keyPressed = false;
            while (!keyPressed) {
                try {
                    keyMutex.wait();
                } catch (InterruptedException e) {
                    // do nothing
                }
            }
        }
    }

    DrawerPanel panel;
    int width, height;

    int N;
    Board field;
    int cellSize, arrowSize;
    
    Object paintMutex;

    public Drawer(int N, Board field, int cellSize, int arrowSize, Object paintMutex) {
        super();

        this.paintMutex = paintMutex;

        this.N = N;
        this.field = field;
        this.cellSize = cellSize;
        this.arrowSize = arrowSize;

        panel = new DrawerPanel();
        getContentPane().add(panel);

        width = cellSize * (N + 2) + EXTRA_WIDTH;
        height = cellSize * (N + 2) + EXTRA_HEIGHT;

        setSize(width, height);
        setTitle("Visualizer tool for problem FragileMirrors");

        addKeyListener(new DrawerKeyListener());
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        setResizable(false);
        setVisible(true);
    }
}

public class FragileMirrorsVis {
    public static String execCommand = null;
    public static long seed = 1;
    public static boolean vis = true;
    public static int cellSize = 8;
    public static int arrowSize = 2;
    public static int delay = 500;
    public static boolean startPaused = false;

    public static Process solution;

    public static final int MIN_N = 50;
    public static final int MAX_N = 100;

    Object paintMutex = new Object();

    public double runTest() {
        solution = null;

        try {
            solution = Runtime.getRuntime().exec(execCommand);
        } catch (Exception e) {
            System.err.println("ERROR: Unable to execute your solution using the provided command: "
                    + execCommand + ".");
            return -1;
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
        String[] board = new String[N];
        for (int i=0; i < N; i++) {
            StringBuilder sb = new StringBuilder();
            for (int j=0; j < N; j++)
                sb.append(rnd.nextBoolean() ? 'L' : 'R');
            board[i] = sb.toString();
        }

        Board field = new Board(board);
        Drawer drawer = null;

        writer.println(N);
        for (int i=0; i < N; i++) {
            writer.println(board[i]);
        }
        writer.flush();

        int ansLen;
        int[] ans;
        try {
            ansLen = Integer.parseInt(reader.readLine());
            if (ansLen % 2 == 1) {
                System.err.println("ERROR: the length of return value must be even. Your length = " + ansLen + ".");
                return 0.0;
            }
            if (ansLen > 2 * N * N) {
                System.err.println("ERROR: the length of return value must be at most N*N. Your length = " + ansLen + ", N = " + N + ".");
                return 0.0;
            }
            ans = new int[ansLen];
            for (int i=0; i < ansLen; i++) {
                ans[i] = Integer.parseInt(reader.readLine());
            }
        } catch (Exception e) {
            System.err.println("ERROR: unable to parse your return value.");
            e.printStackTrace();
            return 0.0;
        }

        stopSolution();

        if (vis) {
            drawer = new Drawer(N, field, cellSize, arrowSize, paintMutex);
            if (startPaused) {
                drawer.pauseMode = true;
            }
        }

        for (int i = 0; i < ans.length; i += 2) {
            int r = ans[i], c = ans[i+1];
            List<Cell> ray;
            synchronized (paintMutex) {
                if (r == -1 && c >= 0 && c < N) {
                    ray = field.shootRay(r, c, 2);
                } else if (r == N && c >= 0 && c < N) {
                    ray = field.shootRay(r, c, 0);
                } else if (c == -1 && r >= 0 && r < N) {
                    ray = field.shootRay(r, c, 1);
                } else if (c == N && r >= 0 && r < N) {
                    ray = field.shootRay(r, c, 3);
                } else {
                    System.err.println("ERROR: ray " + i + " (0-based) starts at an invalid point (row " + r + ", column " + c + ").");
                    return 0.0;
                }
            }
            if (vis) {
                drawer.rayCnt++;

                drawer.processPause();
                drawer.ray = ray;
                drawer.repaint();
                try {
                    if (!drawer.pauseMode) {
                        Thread.sleep(delay);
                    }
                } catch (Exception e) {
                    // do nothing
                }
                drawer.processPause();
            }

            synchronized (paintMutex) {
                field.cleanCells(ray);
            }

            if (vis) {
                drawer.ray = null;
                drawer.repaint();
                try {
                    if (!drawer.pauseMode) {
                        Thread.sleep(delay);
                    }
                } catch (Exception e) {
                    // do nothing
                }
            }
        }

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (field.what[r][c] != '~') {
                    System.err.println("ERROR: all rays are shot, but cell at (row " + r +", column " + c + ") still contains a mirror.");
                    return 0.0;
                }
            }
        }

        int moves = ans.length / 2;
        return N / (double)moves;
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
            } else if (args[i].equals("-arrow")) {
                arrowSize = Integer.parseInt(args[++i]);
            } else if (args[i].equals("-delay")) {
                delay = Integer.parseInt(args[++i]);
            } else if (args[i].equals("-pause")) {
                startPaused = true;
            } else {
                System.out.println("WARNING: unknown argument " + args[i] + ".");
            }

        if (execCommand == null) {
            System.err.println("ERROR: You did not provide the command to execute your solution." +
                    " Please use -exec <command> for this.");
            System.exit(1);
        }

        FragileMirrorsVis vis = new FragileMirrorsVis();
        try {
            double score = vis.runTest();
            System.out.println("Score  = " + score);
        } catch (RuntimeException e) {
            System.err.println("ERROR: Unexpected error while running your test case.");
            e.printStackTrace();
            FragileMirrorsVis.stopSolution();
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
