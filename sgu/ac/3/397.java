// SGU397. Text Editor
/*
397. Text Editor
Time limit per test: 8 second(s)
Memory limit: 65536 kilobytes
input: standard
output: standard


The simplest text editor "Open Word" allows to create and edit only one word. The editor processes keys 'a' -- 'z', and also 'L' (to the left) and 'R' (to the right). After starting his work the editor immediately creates an empty word and sets its cursor to the left-most position. When one of keys 'a' -- 'z' is pressed, the text editor inserts corresponding symbol just after the cursor. After that a cursor moves one position to the right in such a way that it is placed just after new symbol. When key 'L' or 'R' is pressed, the cursor moves one position to the left or to the right respectively. If the cursor can't be moved because it is placed at the left-most or right-most position the command is ignored. Developers of "Open Word" didn't think about the effectiveness so the editor is working slowly if a lot of keys have been pressed.

Your task is to write a program that can process a sequence of key pressings emulating this editor and output result string.

Input
The input file contains one string which consists of symbols ' ' -- ' ', ' ' and ' '. The string length is not less than 1 and doesn't exceed .

Output
Write a required string to the output file.

Example(s)

sample input

	

sample output

abLcd

	

acdb


sample input

	

sample output

icpLLLLLacmRRRRRRRRRRRRc

	

acmicpc
*/

import java.io.*;

class TextEditor {
	int[] l, r;
	byte[] v;
	int m, p;

	public TextEditor(int c) {
		l = new int[c + 1];
		r = new int[c + 1];
		v = new byte[c + 1];
		l[0] = r[0] = 0;
		m = p = 0;
	}

	void moveLeft() {
		if (l[p] != 0) {
			p = l[p];
		}
	}

	void moveRight() {
		if (p != 0) {
			p = r[p];
		}
	}

	void insert(byte b) {
		++m;
		r[l[p]] = m;
		l[m] = l[p];
		l[p] = m;
		r[m] = p;
		v[m] = b;
	}

	public void process(byte b) {
		switch (b) {
			case 'L': moveLeft(); break;
			case 'R': moveRight(); break;
			default: insert(b); break;
		}
	}

	public String toString() {
		byte[] ret = new byte[m];
		for (int i = r[0], j = 0; i != 0; i = r[i], ++j) {
			ret[j] = v[i];
		}
		return new String(ret);
	}
}

public class Solution {
	public static void main(String[] args) throws IOException {
		byte[] input = new byte[1 << 20];
		int len = System.in.read(input);
		TextEditor te = new TextEditor(len);
		for (byte b : input) {
			if (Character.isWhitespace(b)) {
				break;
			} else {
				te.process(b);
			}
		}
		System.out.println(te);
	}
}
//ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
//874737	09.08.09 12:59	watashi	397 	.JAVA	Accepted	194 ms	16294 kb
