import java.awt.*;
import java.awt.geom.*;
import java.awt.event.*;
import java.awt.image.*;
import java.io.*;
import java.util.*;
import java.security.*;
import javax.swing.*;
import javax.imageio.*;

public class TwistedGameTester {
	final int dr[] = { -1, 0, 1, 0 }, dc[] = { 0, 1, 0, -1 };
	int nTiles;
	HashMap<Integer, int[]> placedTiles;
	// i - index of placement, second index is record:
	// 0 - the actual placement,
	// 1 - the place of the active tile it's adjacent to,
	// 2 - the side of the active tile it's adjacent to
	int[] validPlacements;
	int tileIndex;
	Chain[] chains;
	int row, col, rot; // current move params
	String errorMessage;
	SecureRandom rnd;

	class Chain {
		public int chainLength;
		// active contacts are the ones to be filled with the next tile (they
		// point beyond the chain)
		public int[][] activeContacts;
		public boolean looped;

		public Chain() {
			chainLength = 0;
			looped = false;
		}

		public Chain(int contactPlace, int contactIndex) {
			chainLength = 0;
			looped = false;
			activeContacts = new int[2][2];

			activeContacts[0][0] = contactPlace;
			activeContacts[0][1] = contactIndex;

			activeContacts[1][0] = adjacentPlace(contactPlace, contactIndex / 2);
			activeContacts[1][1] = matchingContact(contactIndex);

			// and extend both contacts
			extend(0);
			extend(1);
		}

		public void extend(int end) {
			if (looped) {
				return;
			}
			// knowing that the state of the board changed, try to extend the
			// chain from the given end
			while (true) {
				// check whether there is a tile placed at the next cell of this
				// contact
				if (!placedTiles.containsKey(activeContacts[end][0])) {
					break;
				}

				if (dump) {
					dmp.print(placeToString(activeContacts[end][0]) + " "
							+ activeContacts[end][1] + " ");
				}
				// replace this contact with the one it's connected to
				activeContacts[end][1] = connectedContact(
						placedTiles.get(activeContacts[end][0]),
						activeContacts[end][1]);
				// length is incremented when the wire connection is used
				++chainLength;
				if (dump) {
					dmp.println(activeContacts[end][1] + " R");
				}

				// check whether the chain looped - connected to its other
				// active contact
				if (activeContacts[end][0] == activeContacts[1 - end][0]
						&& activeContacts[end][1] == activeContacts[1 - end][1]) {
					looped = true;
					break;
				}

				int dir = activeContacts[end][1] / 2;
				int nextPlace = adjacentPlace(activeContacts[end][0], dir);
				activeContacts[end][0] = nextPlace;
				activeContacts[end][1] = matchingContact(activeContacts[end][1]);
			}
		}
	}

	// ----------------------------------------------------------------------------------
	int[] generateRandomTile() {
		// a random permutation of 0..7
		int[] permutation = new int[8];
		int i, j, tmp;
		for (i = 0; i < 8; ++i) {
			permutation[i] = i;
		}
		for (i = 0; i < 7; ++i) {
			j = rnd.nextInt(8 - i) + i;
			if (i != j) {
				tmp = permutation[i];
				permutation[i] = permutation[j];
				permutation[j] = tmp;
			}
		}
		return permutation;
	}

	// ----------------------------------------------------------------------------------
	int[] rotateTile(int[] tile, int rotation) {
		int[] rotatedTile = new int[8];
		for (int i = 0; i < 8; ++i) {
			rotatedTile[i] = (tile[i] + 2 * rotation) % 8;
		}
		return rotatedTile;
	}

	// ----------------------------------------------------------------------------------
	int cellPlace(int row, int col) {
		return row * (2 * nTiles + 1) + col;
	}

	// ----------------------------------------------------------------------------------
	int adjacentPlace(int place, int dir) {
		return place + dr[dir] * (2 * nTiles + 1) + dc[dir];
	}

	// ----------------------------------------------------------------------------------
	int matchingContact(int contactIndex) {
		// if two tiles are adjacent, what's the index of the matching contact
		if (contactIndex < 2 || contactIndex == 4 || contactIndex == 5) {
			return 5 - contactIndex;
		}
		return 9 - contactIndex;
	}

	// ----------------------------------------------------------------------------------
	int connectedContact(int[] tile, int contactIndex) {
		// given the tile description, return the contact connected to the given
		// one
		for (int i = 0; i < 8; ++i) {
			if (tile[i] == contactIndex) {
				return tile[i + 1 - 2 * (i % 2)];
			}
		}
		return -1;
	}

	// ----------------------------------------------------------------------------------
	boolean isValidMove() {
		if (rot < 0 || rot > 3) {
			errorMessage = "ROT must be between 0 and 3, inclusive.";
			return false;
		}
		int movePlace = cellPlace(row, col);
		if (placedTiles.containsKey(movePlace)) {
			errorMessage = "Placed tiles must not overlap.";
			return false;
		}
		for (int i = 0; i < 4; ++i) {
			if (validPlacements[i] == movePlace) {
				return true;
			}
		}
		errorMessage = "Invalid tile position.";
		return false;
	}

	// ----------------------------------------------------------------------------------
	boolean isValidReturn(String move) {
		// must be formatted as "ROW COL ROT"
		errorMessage = "";
		if (move.equals("GIVE UP")) {
			return true;
		}
		try {
			String[] sp = move.split(" ");
			if (sp.length != 3) {
				errorMessage = "Your return must be formatted as \"ROW COL ROT\".";
				return false;
			}
			row = Integer.parseInt(sp[0]);
			col = Integer.parseInt(sp[1]);
			rot = Integer.parseInt(sp[2]);
		} catch (Exception e) {
			errorMessage = "Your return must be formatted as \"ROW COL ROT\".";
			return false;
		}
		return isValidMove();
	}

	// ----------------------------------------------------------------------------------
	public double runTest(String seed) {
		try {
			rnd = SecureRandom.getInstance("SHA1PRNG");
			rnd.setSeed(Long.parseLong(seed));

			nTiles = 10000;
			if (seed.equals("1")) {
				nTiles = 10;
			}
			if (seed.equals("2")) {
				nTiles = 100;
			}
			if (seed.equals("3")) {
				nTiles = 1000;
			}
			placedTiles = new HashMap<Integer, int[]>();
			int[] tilePlace = new int[nTiles];
			if (dump) {
				dmp.println(nTiles);
			}

			// place first tile ourselves, pass it to solution but ignore the
			// return
			tileIndex = 0;
			int[] tile = generateRandomTile();
			init(nTiles, tile);
			row = nTiles;
			col = nTiles;
			tilePlace[tileIndex] = cellPlace(row, col);
			placedTiles.put(tilePlace[tileIndex], tile);
			dumpTile(tilePlace[tileIndex], tile);

			// with only one tile placed, there are no active contacts yet,
			// and all placements adjacent to the first tile are valid
			validPlacements = new int[4];
			for (int i = 0; i < 4; ++i) {
				validPlacements[i] = cellPlace(row + dr[i], col + dc[i]);
			}

			// let the solution place second tile
			++tileIndex;
			tile = generateRandomTile();
			String move = placeTile(tile);
			if (move.equals("GIVE UP")) {
				addFatalError("You gave up. Tile index = " + 1 + " (0-based).");
				return 0;
			}

			if (!isValidReturn(move)) {
				addFatalError(errorMessage + " Tile index = " + tileIndex
						+ " (0-based).");
				return 0;
			}
			tilePlace[tileIndex] = cellPlace(row, col);
			placedTiles.put(tilePlace[tileIndex], rotateTile(tile, rot));
			dumpTile(tilePlace[tileIndex], rotateTile(tile, rot));

			// figure out what the active wires and contacts are going to be
			// detect which side of the tiles is common
			int i, j;
			for (i = 0; i < 4; ++i) {
				if (validPlacements[i] == tilePlace[tileIndex]) {
					break;
				}
			}

			// the contacts on this side are: side * 2 (+1) for first tile
			chains = new Chain[2];
			for (j = 0; j < 2; ++j) {
				chains[j] = new Chain(tilePlace[0], i * 2 + j);
			}

			for (++tileIndex; tileIndex < nTiles; ++tileIndex) {
				// check if there is a possible move
				if (chains[0].looped && chains[1].looped) {
					addFatalError("No possible moves for tile index = "
							+ tileIndex + " (0-based).");
					addFatalError("Chain 0 = " + chains[0].chainLength);
					addFatalError("Chain 1 = " + chains[1].chainLength);
					return Math.max(chains[0].chainLength,
							chains[1].chainLength);
				}

				// update valid placements
				for (i = 0; i < 4; ++i) {
					if (chains[i / 2].looped) {
						validPlacements[i] = -1;
					} else {
						validPlacements[i] = chains[i / 2].activeContacts[i % 2][0];
					}
				}
				tile = generateRandomTile();
				move = placeTile(tile);
				if (move.equals("GIVE UP")) {
					addFatalError("You gave up. Tile index = " + tileIndex
							+ " (0-based).");
					addFatalError("Chain 0 = " + chains[0].chainLength);
					addFatalError("Chain 1 = " + chains[1].chainLength);
					return Math.max(chains[0].chainLength,
							chains[1].chainLength);
				}

				if (!isValidReturn(move)) {
					addFatalError(errorMessage + " Tile index = " + tileIndex
							+ " (0-based).");
					addFatalError("Chain 0 = " + chains[0].chainLength);
					addFatalError("Chain 1 = " + chains[1].chainLength);
					return Math.max(chains[0].chainLength,
							chains[1].chainLength);
				}

				tilePlace[tileIndex] = cellPlace(row, col);
				placedTiles.put(tilePlace[tileIndex], rotateTile(tile, rot));
				dumpTile(tilePlace[tileIndex], rotateTile(tile, rot));

				// and extend chains taking into account the new tile
				for (i = 0; i < 4; ++i) {
					chains[i / 2].extend(i % 2);
				}
			}
			addFatalError("Chain 0 = " + chains[0].chainLength);
			addFatalError("Chain 1 = " + chains[1].chainLength);
			return Math.max(chains[0].chainLength, chains[1].chainLength);
		} catch (Exception e) {
			System.err
					.println("An exception occurred while trying to get your program's results.");
			e.printStackTrace();
			return 0;
		}
	}

	// ------------- visualization part
	// -----------------------------------------------------
	static String exec, dumpFile;
	static boolean dump;
	static Process proc;
	InputStream is;
	OutputStream os;
	PrintWriter dmp;
	BufferedReader br;

	// ----------------------------------------------------------------------------------
	int init(int nTiles, int[] firstTile) throws IOException {
		StringBuffer sb = new StringBuffer();
		sb.append(nTiles + "\n");
		sb.append(tileToString(firstTile)).append('\n');
		os.write(sb.toString().getBytes());
		os.flush();
		return 0;
	}

	// ----------------------------------------------------------------------------------
	String placeTile(int[] tile) throws IOException {
		StringBuffer sb = new StringBuffer();
		sb.append(tileToString(tile)).append('\n');
		os.write(sb.toString().getBytes());
		os.flush();
		return br.readLine();
	}

	// ----------------------------------------------------------------------------------
	public TwistedGameTester(String seed) {
		try {
			// interface for runTest
			if (exec != null) {
				try {
					Runtime rt = Runtime.getRuntime();
					proc = rt.exec(exec);
					os = proc.getOutputStream();
					is = proc.getInputStream();
					br = new BufferedReader(new InputStreamReader(is));
					new ErrorReader(proc.getErrorStream()).start();
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
			if (dumpFile != null) {
				try {
					dmp = new PrintWriter(new FileWriter(dumpFile));
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
			System.out.println("Score = " + runTest(seed));
			if (proc != null)
				try {
					proc.destroy();
				} catch (Exception e) {
					e.printStackTrace();
				}
			if (dumpFile != null)
				try {
					dmp.close();
				} catch (Exception e) {
					e.printStackTrace();
				}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	// ----------------------------------------------------------------------------------
	public static void main(String[] args) {
		String seed = "1";
		dump = false;
		for (int i = 0; i < args.length; i++) {
			if (args[i].equals("-seed")) {
				seed = args[++i];
			} else if (args[i].equals("-exec")) {
				exec = args[++i];
			} else if (args[i].equals("-dump")) {
				dump = true;
				dumpFile = args[++i];
			}
		}
		TwistedGameTester tg = new TwistedGameTester(seed);
	}

	// ----------------------------------------------------------------------------------
	String tileToString(int[] tile) {
		StringBuilder sb = new StringBuilder();
		sb.append(tile[0]);
		for (int i = 1; i < 8; ++i) {
			sb.append(" ");
			sb.append(tile[i]);
		}
		return sb.toString();
	}

	// ----------------------------------------------------------------------------------
	String placeToString(int place) {
		return (place / (2 * nTiles + 1)) + " " + (place % (2 * nTiles + 1));
	}

	// ----------------------------------------------------------------------------------
	void dumpTile(int place, int[] tile) {
		if (dump) {
			for (int i = 0; i < 4; ++i) {
				dmp.println(placeToString(place) + " " + tile[2 * i] + " "
						+ tile[2 * i + 1] + " B");
			}
		}
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
