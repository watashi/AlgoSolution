import java.util.*;
import java.io.*;
import java.security.*;

public class TheUniverseUnravelsTester {
	private final int MIN_N = 100, MAX_N = 2000;
	private final int DIM = 10;
	private final int MIN_COORD = 0, MAX_COORD = 1000;
	private final double MIN_HIDE_PRB = 0.2, MAX_HIDE_PRB = 1.0;

	private final int TIME_LIMIT = 10 * 1000;
	private final double BAD_RETURN_VALUE = -1.0;
	private final int MAX_REPORT_LEN = 100;
	private final int SCORE_MULTIPLIER = 1000;

	private Process proc;
	private OutputStream os;
	private InputStream is;
	private BufferedReader br;
	private PrintWriter pw;

	private class ErrorReader extends Thread {
		private InputStream error;

		public ErrorReader(InputStream is) {
			error = is;
		}

		public void run() {
			try {
				byte[] ch = new byte[50000];
				int read;
				while ((read = error.read(ch)) > 0) {
					String s = new String(ch, 0, read);
					System.out.print(s);
					System.out.flush();
				}
			} catch (Exception e) {
				System.out.println("ERROR: unable to redirect your solution's stderr to tester's stdout.");
				e.printStackTrace();
			}
		}
	}

	private String cut(String s) {
		return (s.length() <= MAX_REPORT_LEN ? s : s.substring(0, MAX_REPORT_LEN) + "...");
	}

	private double runTest(String seed) {
		SecureRandom rnd;
		try {
			rnd = SecureRandom.getInstance("SHA1PRNG");
			rnd.setSeed(Long.parseLong(seed));
		} catch (NumberFormatException e) {
			System.out.println("ERROR: the value of seed must be a signed 64-bit integer.");
			return BAD_RETURN_VALUE;
		} catch (Exception e) {
			System.out.println("ERROR: unexpected error during test case generation.");
			e.printStackTrace();
			return BAD_RETURN_VALUE;
		}

		int N = rnd.nextInt(MAX_N - MIN_N + 1) + MIN_N;

		int[][] X = new int[N][DIM];
		for (int i=0; i < N; i++)
			for (int j=0; j < DIM; j++)
				X[i][j] = rnd.nextInt(MAX_COORD - MIN_COORD + 1) + MIN_COORD;

		double[] p = new double[N];
		for (int i=0; i < N; i++)
			p[i] = rnd.nextDouble() * (MAX_HIDE_PRB - MIN_HIDE_PRB) + MIN_HIDE_PRB;

		String[] coords = new String[N];
		for (int i=0; i < N; i++) {
			StringBuilder sb = new StringBuilder();
			for (int j=0; j < DIM; j++) {
				sb.append(rnd.nextDouble() < p[i] ? "-1" : "" + X[i][j]);
				if (j + 1 < DIM) sb.append(" ");
			}
			coords[i] = sb.toString();
		}

		int[][] dist = new int[N][N];
		for (int i=0; i < N; i++) {
			for (int j=i+1; j < N; j++)
				for (int k=0; k < DIM; k++)
					dist[i][j] += (X[i][k] - X[j][k]) * (X[i][k] - X[j][k]);

			for (int j=0; j < i; j++)
				dist[i][j] = dist[j][i];
		}

		int[] minDist = new int[N];
		int[] maxDist = new int[N];

		Arrays.fill(minDist, Integer.MAX_VALUE);

		for (int i=0; i < N; i++)
			for (int j=0; j < N; j++) {
				if (i != j) minDist[i] = Math.min(minDist[i], dist[i][j]);
				maxDist[i] = Math.max(maxDist[i], dist[i][j]);
			}

		String[] ranks = new String[N];
		for (int i=0; i < N; i++) {
			int[] sortedDist = dist[i].clone();
			Arrays.sort(sortedDist);
			StringBuilder sb = new StringBuilder();
			for (int j=0; j < N; j++) {
				int pos = Arrays.binarySearch(sortedDist, dist[i][j]);
				while (pos > 0 && sortedDist[pos - 1] == sortedDist[pos]) pos--;
				sb.append("" + pos);
				if (j + 1 < N) sb.append(" ");
			}
			ranks[i] = sb.toString();
		}

		try {
	 		pw.println(coords.length);
			for (String elm : coords)
				pw.println(elm);

			pw.println(ranks.length);
			for (String elm : ranks)
				pw.println(elm);

			pw.println(minDist.length);
			for (int elm : minDist)
				pw.println(elm);

			pw.println(maxDist.length);
			for (int elm : maxDist)
				pw.println(elm);

			pw.flush();
		} catch (Exception e) {
			System.out.println("ERROR: Failed to pass input data to your solution's stdin.");
			e.printStackTrace();
			return BAD_RETURN_VALUE;
		}

		String[] res;
		try {
			int len = Integer.parseInt(br.readLine());
			res = new String[len];
			for (int i=0; i < len; i++)
				res[i] = br.readLine();
		} catch (Exception e) {
			System.out.println("ERROR: Failed to read your solution's return value from its stdout.");
			e.printStackTrace();
			return BAD_RETURN_VALUE;
		}

		if (res.length != N) {
			System.out.println("ERROR: Your return must contain " + N + " elements, but it contains " + res.length + " instead.");
			return BAD_RETURN_VALUE;
		}

		int[][] PX = new int[N][DIM];
		for (int i=0; i < N; i++) {
			String[] items = res[i].split(" ");
			if (items.length != DIM) {
				System.out.println("ERROR: Element " + i + " of your return is not formatted properly. It contains \"" + cut(res[i]) + "\".");
				return BAD_RETURN_VALUE;
			}
			for (int j=0; j < DIM; j++) {
				try {
					PX[i][j] = Integer.parseInt(items[j]);
				} catch (Exception e) {
					System.out.println("ERROR: Element " + i + " of your return is not formatted properly. It contains \"" + cut(res[i]) + "\".");
					return BAD_RETURN_VALUE;
				}
				if (PX[i][j] < MIN_COORD || PX[i][j] > MAX_COORD) {
					System.out.println("ERROR: Coordinate " + j + " in element " + i + " of your return is not in " + MIN_COORD + ".." + MAX_COORD + "." +
							"Contents of this element: \"" + cut(res[i]) + "\".");
					return BAD_RETURN_VALUE;
				}
			}
		}

		double score = 0.0;
		for (int i=0; i < N; i++) {
			double dst = 0.0;
			for (int j=0; j < DIM; j++)
				dst += (X[i][j] - PX[i][j]) * (X[i][j] - PX[i][j]);
			score += Math.sqrt(dst);
		}

		return score / N;
	}

	public TheUniverseUnravelsTester(String seed, String exec) {
		try {
			Runtime rt = Runtime.getRuntime();
			proc = rt.exec(exec);
			os = proc.getOutputStream();
			is = proc.getInputStream();
			br = new BufferedReader(new InputStreamReader(is));
			pw = new PrintWriter(os);
			new ErrorReader(proc.getErrorStream()).start();
		} catch (Exception e) {
			System.out.println("ERROR: unable to launch your solution.");
			e.printStackTrace();
		}
		
		System.out.println("Score = " + runTest(seed));
		
		if (proc != null) {
			try {
				proc.destroy();
			} catch (Exception e) {
				System.out.println("ERROR: unable to destroy your solution's process. You may need to kill it manually.");
				e.printStackTrace();
			}
		}
	}

	public static void main(String[] args) {
		String seed = "1";
		String exec = null;
		for (int i = 0; i < args.length; i++) {
			if (args[i].equals("-seed")) {
				seed = args[++i];
			} else if (args[i].equals("-exec")) {
				exec = args[++i];
			}
		}

		if (exec == null) {
			System.out.println("ERROR: no solution to launch. Use -exec option to provide the command line to launch your solution.");
			System.exit(0);
		}

		TheUniverseUnravelsTester tester = new TheUniverseUnravelsTester(seed, exec);
	}
}