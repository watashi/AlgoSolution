import java.util.*;
import java.io.*;
import java.awt.Graphics2D;
import java.awt.Color;
import java.awt.image.*;
import javax.imageio.*;

public class TwistedGameDrawer {
	int ADD_LEN = 5;
	int BASIC_LEN = 10;

	int[] dx, dy;

	String dumpFile = "res.dmp";
	String resFile = "pic.gif";
	int base;
	int black = 4 * 10000;

	class Instruction {
		int row, col;
		int c1, c2;
		char color;

		public Instruction(String s) throws Exception {
			String[] items = s.split(" ");

			row = Integer.parseInt(items[0]);
			col = Integer.parseInt(items[1]);
			c1 = Integer.parseInt(items[2]);
			c2 = Integer.parseInt(items[3]);

			if (row < 0 || row > 2 * base)
				throw new Exception("row must be between 0 and " + (2 * base)
						+ ", inclusive.");

			if (col < 0 || col > 2 * base)
				throw new Exception("column must be between 0 and "
						+ (2 * base) + ", inclusive.");

			if (c1 < 0 || c1 >= 8)
				throw new Exception(
						"contact1 must be between 0 and 7, inclusive.");

			if (c2 < 0 || c2 >= 8)
				throw new Exception(
						"contact2 must be between 0 and 7, inclusive.");

			if (c1 == c2)
				throw new Exception("contact1 and contact2 must be different.");

			if (!items[4].equals("B") && !items[4].equals("R"))
				throw new Exception("color must be 'R' or 'B'.");

			color = items[4].charAt(0);
		}
	}

	Set<String> takenCells = new HashSet<String>();

	void drawActiveContact(Graphics2D g, int row, int col, int id, int x, int y) {
		int dr = (id / 2 == 0 ? -1 : (id / 2 == 2 ? 1 : 0));
		int dc = (id / 2 == 1 ? 1 : (id / 2 == 3 ? -1 : 0));
		String key = (row + dr) + " " + (col + dc);
		if (takenCells.contains(key))
			return;

		g.setColor(Color.BLUE);
		g.fillRect(x - 2, y - 2, 5, 5);
	}

	public void processData() {
		BufferedReader br = null;

		try {
			br = new BufferedReader(new FileReader(dumpFile));
		} catch (Exception e) {
			System.out.println("ERROR: Unable to open " + dumpFile
					+ " for reading.");
			System.exit(0);
		}

		List<Instruction> instr = new ArrayList<Instruction>();

		try {
			base = Integer.parseInt(br.readLine());
		} catch (Exception e) {
			System.out
					.println("ERROR: Dump file has improper format (problem in line 0).");
			System.exit(0);
		}

		int linePos = 1;
		List<Instruction> toDraw = new ArrayList<Instruction>();
		while (true) {
			String s = null;
			try {
				s = br.readLine();
			} catch (Exception e) {
				System.out.println("ERROR: Unable to read line " + linePos
						+ " (0-based) from dump file.");
				System.exit(0);
			}
			if (s == null)
				break;
			Instruction x = null;
			try {
				x = new Instruction(s);
			} catch (Exception e) {
				System.out
						.println("ERROR: Line "
								+ linePos
								+ " (0-based) in dump file does not contain a valid drawing instruction.");
				System.out.println("This line contains: \"" + s + "\".");
				System.out.println("The detailed error is: " + e.getMessage());
				System.exit(0);
			}
			linePos++;
			if (x.color == 'B') {
				black--;
				if (black < 0)
					break;
			}
			toDraw.add(x);
		}

		int minRow = 2 * base, maxRow = 0, minCol = 2 * base, maxCol = 0;

		for (Instruction x : toDraw) {
			takenCells.add(x.row + " " + x.col);
			minRow = Math.min(minRow, x.row);
			maxRow = Math.max(maxRow, x.row);
			minCol = Math.min(minCol, x.col);
			maxCol = Math.max(maxCol, x.col);
		}

		BufferedImage bi = new BufferedImage(3 * (maxCol - minCol + 1)
				* BASIC_LEN + 1 + 2 * ADD_LEN, 3 * (maxRow - minRow + 1)
				* BASIC_LEN + 1 + 2 * ADD_LEN, BufferedImage.TYPE_3BYTE_BGR);

		Graphics2D g = bi.createGraphics();

		g.setColor(Color.WHITE);
		g.fillRect(0, 0, bi.getWidth(), bi.getHeight());

		g.setColor(new Color(150, 150, 150));
		for (Instruction di : toDraw) {
			int x = 3 * (di.col - minCol) * BASIC_LEN + ADD_LEN;
			int y = 3 * (di.row - minRow) * BASIC_LEN + ADD_LEN;

			g.drawLine(x, y, x + 3 * BASIC_LEN, y);
			g.drawLine(x + 3 * BASIC_LEN, y, x + 3 * BASIC_LEN, y + 3
					* BASIC_LEN);
			g.drawLine(x + 3 * BASIC_LEN, y + 3 * BASIC_LEN, x, y + 3
					* BASIC_LEN);
			g.drawLine(x, y + 3 * BASIC_LEN, x, y);
		}

		dx = new int[] { BASIC_LEN, 2 * BASIC_LEN, 3 * BASIC_LEN,
				3 * BASIC_LEN, 2 * BASIC_LEN, BASIC_LEN, 0, 0 };
		dy = new int[] { 0, 0, BASIC_LEN, 2 * BASIC_LEN, 3 * BASIC_LEN,
				3 * BASIC_LEN, 2 * BASIC_LEN, BASIC_LEN };

		for (Instruction di : toDraw) {
			if (di.c1 > di.c2) {
				int tmp = di.c1;
				di.c1 = di.c2;
				di.c2 = tmp;
			}
			int baseX = 3 * (di.col - minCol) * BASIC_LEN + ADD_LEN;
			int baseY = 3 * (di.row - minRow) * BASIC_LEN + ADD_LEN;

			int x1 = baseX + dx[di.c1];
			int y1 = baseY + dy[di.c1];
			int x2 = baseX + dx[di.c2];
			int y2 = baseY + dy[di.c2];

			g.setColor(di.color == 'B' ? Color.BLACK : Color.RED);

			if (di.c1 / 2 != di.c2 / 2) {
				g.drawLine(x1, y1, x2, y2);
			} else {
				int midX = -1, midY = -1;
				if (di.c1 / 2 == 0) {
					midX = (x1 + x2) / 2;
					midY = y1 + BASIC_LEN / 3;
				}
				if (di.c1 / 2 == 1) {
					midX = x1 - BASIC_LEN / 3;
					midY = (y1 + y2) / 2;
				}
				if (di.c1 / 2 == 2) {
					midX = (x1 + x2) / 2;
					midY = y1 - BASIC_LEN / 3;
				}
				if (di.c1 / 2 == 3) {
					midX = x1 + BASIC_LEN / 3;
					midY = (y1 + y2) / 2;
				}
				g.drawLine(x1, y1, midX, midY);
				g.drawLine(midX, midY, x2, y2);
			}

			if (di.color == 'R') {
				drawActiveContact(g, di.row, di.col, di.c1, x1, y1);
				drawActiveContact(g, di.row, di.col, di.c2, x2, y2);
			}
		}

		try {
			ImageIO.write(bi, "gif", new File(resFile));
		} catch (Exception e) {
			System.out.println("ERROR: unable to save resulted image to "
					+ resFile + ".");
			System.exit(0);
		}
	}

	public static void printUsage() {
		System.out
				.println("USAGE: java TwistedGameDrawer dump_file res_file [moves_to_draw]");
		System.exit(0);
	}

	public static void main(String[] args) throws Exception {
		TwistedGameDrawer obj = new TwistedGameDrawer();

		for (int i = 0; i < args.length; i++) {
			if (args[i].equals("-dump")) {
				obj.dumpFile = args[++i];
			} else if (args[i].equals("-res")) {
				obj.resFile = args[++i];
			} else if (args[i].equals("-mv")) {
				obj.black = 4 * Integer.parseInt(args[++i]);
			} else if (args[i].equals("-sz")) {
				obj.BASIC_LEN = Integer.parseInt(args[++i]);
			}
		}

		obj.processData();
	}
}