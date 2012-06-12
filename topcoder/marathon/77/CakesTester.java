import java.util.*;
import java.io.*;
import java.security.*;

public class CakesTester {
	final int[] dr = { 1, 0, -1, 0 }, dc = { 0, 1, 0, -1 };
	SecureRandom r;

	int nCakes, nEaters, nComps, cakeSize;
	int[][] preferences;
	int[][][][] cakes;

	int[] prefsArg, cakesArg; // the arguments to be passed to the solution
	int[] ret;

	// ----------------------------------------------------------------------------------
	int getRnd(int low, int high) {
		return r.nextInt(high - low + 1) + low;
	}

	// ----------------------------------------------------------------------------------
	void putRose(int r, int c, int cake, int comp, int layer) {
		cakes[cake][r][c][comp] += layer + getRnd(-5, 5);
		cakes[cake][r + 1][c][comp] += layer + getRnd(-5, 5);
		cakes[cake][r][c + 1][comp] += layer + getRnd(-5, 5);
		cakes[cake][r - 1][c][comp] += layer + getRnd(-5, 5);
		cakes[cake][r][c - 1][comp] += layer + getRnd(-5, 5);
	}

	// ----------------------------------------------------------------------------------
	void generate(String seed) {
		try {
			r = SecureRandom.getInstance("SHA1PRNG");
			r.setSeed(Long.parseLong(seed));
			nCakes = getRnd(1, 10);
			nEaters = getRnd(2 * nCakes, 10 * nCakes);
			nComps = getRnd(2, 10);
			if (seed.equals("1")) {
				nCakes = 2;
				nEaters = 4;
				nComps = 4;
			}

			// eaters' preferences
			preferences = new int[nEaters][nComps];
			for (int i = 0; i < nEaters; ++i)
				for (int j = 0; j < nComps; ++j) {
					preferences[i][j] = getRnd(1, 10);
				}

			// cakes themselves
			cakeSize = 2 * getRnd(10, 50);
			if (seed.equals("1")) {
				cakeSize = 20;
			}
			cakes = new int[nCakes][cakeSize][cakeSize][nComps];

			int nBases = nComps / 2, cakeHeight, layerHeight, rimComp;
			for (int i = 0; i < nCakes; ++i) {
				// choose base height and fill it with bases
				cakeHeight = getRnd(200, 250);
				for (int j = 0; j < nBases; ++j) {
					if (j == nBases - 1) {
						layerHeight = cakeHeight;
					} else {
						layerHeight = getRnd(0, cakeHeight);
					}
					if (layerHeight > 0) {
						cakeHeight -= layerHeight;
						// add this layer to the cake with small variations
						for (int r = 0; r < cakeSize; ++r)
							for (int c = 0; c < cakeSize; ++c)
								cakes[i][r][c][j] = Math.max(0, layerHeight
										+ getRnd(-5, 5));
					}
				}

				// add decorations
				rimComp = getRnd(nBases, nComps - 1);
				for (int j = nBases; j < nComps; ++j) {
					if (getRnd(0, 1) == 1) {
						continue;
					}
					layerHeight = getRnd(10, 40);
					if (j == rimComp) {
						// add a rim of random width
						int width = getRnd(2, cakeSize / 6);
						for (int r = 0; r < cakeSize; ++r)
							for (int c = 0; c < cakeSize; ++c) {
								if (Math.min(r, c) < width
										|| Math.max(r, c) >= cakeSize - width)
									cakes[i][r][c][j] = layerHeight
											+ getRnd(-5, 5);
							}
					}
					// place roses
					int nl = getRnd((cakeSize * cakeSize) / 400,
							(cakeSize * cakeSize) / 40);
					for (int l = 0; l < nl; ++l) {
						int r = getRnd(1, cakeSize / 2);
						int c = getRnd(1, cakeSize / 2);
						int kind = getRnd(0, 2);
						if (kind == 0) {
							putRose(r, c, i, j, layerHeight);
							putRose(cakeSize - r - 1, c, i, j, layerHeight);
							putRose(cakeSize - r - 1, cakeSize - c - 1, i, j,
									layerHeight);
							putRose(r, cakeSize - c - 1, i, j, layerHeight);
						} else if (kind == 1) {
							putRose(r, c, i, j, layerHeight);
							putRose(c, r, i, j, layerHeight);
							putRose(cakeSize - r - 1, cakeSize - c - 1, i, j,
									layerHeight);
							putRose(cakeSize - c - 1, cakeSize - r - 1, i, j,
									layerHeight);
						} else {
							putRose(r, cakeSize - c - 1, i, j, layerHeight);
							putRose(c, cakeSize - r - 1, i, j, layerHeight);
							putRose(cakeSize - r - 1, c, i, j, layerHeight);
							putRose(cakeSize - c - 1, r, i, j, layerHeight);
						}
					}
				}
			}

			if (debug) {
				System.out.println("Number of cakes = " + nCakes);
				System.out.println("Number of people = " + nEaters);
				System.out.println("Number of components = " + nComps);
				System.out.println("Cake size = " + cakeSize);
				for (int i = 0; i < nCakes; ++i) {
					System.out.println("Cake " + i);
					for (int j = 0; j < nComps; ++j) {
						System.out.println("Component " + j);
						for (int r = 0; r < cakeSize; ++r) {
							for (int c = 0; c < cakeSize; ++c)
								System.out.print(cakes[i][r][c][j] + " ");
							System.out.println();
						}
					}
				}
			}

		} catch (Exception e) {
			System.err
					.println("An exception occurred while generating the test case.");
			e.printStackTrace();
		}
	}

	// ----------------------------------------------------------------------------------
	void convertToArgs() {
		// converts multidimensional test case params into args to be passed to
		// solution
		prefsArg = new int[nEaters * nComps];
		for (int i = 0; i < nEaters * nComps; ++i) {
			prefsArg[i] = preferences[i / nComps][i % nComps];
		}

		cakesArg = new int[nCakes * cakeSize * cakeSize * nComps];
		for (int i = 0; i < nCakes * cakeSize * cakeSize * nComps; ++i) {
			cakesArg[i] = cakes[i / nComps / cakeSize / cakeSize][(i / nComps / cakeSize)
					% cakeSize][(i / nComps) % cakeSize][i % nComps];
		}
	}

	// ----------------------------------------------------------------------------------
	public double runTest(String seed) {
		try {
			generate(seed);
			convertToArgs();

			int[] ret = split(nCakes, nEaters, nComps, cakeSize, prefsArg,
					cakesArg);

			// add dimension checks in server solution
			if (ret == null) {
				addFatalError("No return to process.");
				return 0;
			}
			if (ret.length != nCakes * cakeSize * cakeSize) {
				addFatalError("Invalid size of return.");
				return 0;
			}

			// validate the return more carefully while keeping track of score
			int[] joy = new int[nEaters], eatersCake = new int[nEaters];
			for (int i = 0; i < nEaters; ++i) {
				eatersCake[i] = -1;
			}

			int i = 0, ind, r, c, comp;
			int[][] currentCake = new int[cakeSize][cakeSize];
			for (ind = 0; ind < nCakes; ++ind) {
				for (r = 0; r < cakeSize; ++r)
					for (c = 0; c < cakeSize; ++c, ++i) {
						if (ret[i] < 0 || ret[i] >= nEaters) {
							// nobody gets this piece, which is ok
							currentCake[r][c] = -1;
							continue;
						}
						// check that this person never had a piece from another
						// cake
						if (eatersCake[ret[i]] > -1
								&& eatersCake[ret[i]] != ind) {
							addFatalError("Person " + ret[i]
									+ " can't get pieces of both cakes "
									+ eatersCake[ret[i]] + " and " + ind + ".");
							return 0;
						}
						eatersCake[ret[i]] = ind;
						currentCake[r][c] = ret[i];
						// accumulate joy (for later)
						for (comp = 0; comp < nComps; ++comp) {
							joy[ret[i]] += cakes[ind][r][c][comp]
									* preferences[ret[i]][comp];
						}
					}
				if (debug) {
					System.out.println("Cake " + ind + " shares:");
					for (r = 0; r < cakeSize; ++r) {
						for (c = 0; c < cakeSize; ++c) {
							System.out.print(currentCake[r][c] + " ");
						}
						System.out.println();
					}
				}
				// check that all parts of this cake which belong to one person
				// are connected
				boolean[] seen = new boolean[nEaters];
				int eater;
				for (r = 0; r < cakeSize; ++r)
					for (c = 0; c < cakeSize; ++c) {
						if (currentCake[r][c] == -1) {
							continue;
						}
						eater = currentCake[r][c];
						// check that this person had no earlier connected piece
						// of this cake
						if (seen[eater]) {
							addFatalError("Person " + eater
									+ " can't get two disjoint pieces of cake "
									+ ind + ".");
							return 0;
						}
						seen[eater] = true;
						// bfs from this cell to mark all connected
						int[] qr = new int[cakeSize * cakeSize], qc = new int[cakeSize
								* cakeSize];
						int qsz = 1, r0, c0;
						qr[0] = r;
						qc[0] = c;
						currentCake[r][c] = -1;
						for (int q = 0; q < qsz; ++q) {
							r0 = qr[q];
							c0 = qc[q];
							for (int k = 0; k < 4; ++k) {
								if (r0 + dr[k] >= 0
										&& r0 + dr[k] < cakeSize
										&& c0 + dc[k] >= 0
										&& c0 + dc[k] < cakeSize
										&& currentCake[r0 + dr[k]][c0 + dc[k]] == eater) {
									qr[qsz] = r0 + dr[k];
									qc[qsz] = c0 + dc[k];
									currentCake[r0 + dr[k]][c0 + dc[k]] = -1;
									qsz++;
								}
							}
						}
					}
			}

			if (debug) {
				System.out.println("Eaters' satisfactions:");
				for (i = 0; i < nEaters; ++i) {
					System.out.println(i + " - " + joy[i]);
				}
			}

			// finally, all validations are complete; produce the score
			Arrays.sort(joy);
			return joy[0];
		} catch (Exception e) {
			System.err
					.println("An exception occurred while trying to get your program's results.");
			e.printStackTrace();
			return 0.0;
		}
	}

	// ------------- tester part
	// ------------------------------------------------------------
	static String exec;
	static Process proc;
	static boolean debug;
	InputStream is;
	OutputStream os;

	// ----------------------------------------------------------------------------------
	int[] split(int nCakes, int nEaters, int nComps, int cakeSize, int[] prefs,
			int[] cakes) throws IOException {
		// pass the params and get the result
		if (exec == null)
			return null;
		int i;
		StringBuffer sb = new StringBuffer();
		sb.append(nCakes).append('\n');
		sb.append(nEaters).append('\n');
		sb.append(nComps).append('\n');
		sb.append(cakeSize).append('\n');

		for (i = 0; i < prefs.length; i++)
			sb.append(prefs[i]).append('\n');
		for (i = 0; i < cakes.length; i++)
			sb.append(cakes[i]).append('\n');
		os.write(sb.toString().getBytes());
		os.flush();

		// MUST get exactly nCakes * cakeSize^2 elements as answer
		BufferedReader br = new BufferedReader(new InputStreamReader(is));
		int[] ret = new int[nCakes * cakeSize * cakeSize];
		for (i = 0; i < nCakes * cakeSize * cakeSize; i++)
			ret[i] = Integer.parseInt(br.readLine());
		return ret;
	}

	// ----------------------------------------------------------------------------------
	public CakesTester(String seed) {
		// interface for runTest
		if (exec != null) {
			try {
				Runtime rt = Runtime.getRuntime();
				proc = rt.exec(exec);
				os = proc.getOutputStream();
				is = proc.getInputStream();
				new ErrorReader(proc.getErrorStream()).start();
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
		System.out.println("Score = " + runTest(seed));
	}

	// ----------------------------------------------------------------------------------
	public static void main(String[] args) {
		String seed = "1";
		for (int i = 0; i < args.length; i++) {
			if (args[i].equals("-seed"))
				seed = args[++i];
			if (args[i].equals("-exec"))
				exec = args[++i];
			if (args[i].equals("-debug"))
				debug = true;
		}
		CakesTester f = new CakesTester(seed);
	}

	// ----------------------------------------------------------------------------------
	void addFatalError(String message) {
		System.out.println(message);
	}
}

class ErrorReader extends Thread {
	InputStream error;

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
		}
	}
}
