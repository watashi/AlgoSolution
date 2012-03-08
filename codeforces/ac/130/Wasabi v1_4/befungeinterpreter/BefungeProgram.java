/*
BefungeProgram.java
Created on 9. Juni 2007, 00:21

Copyright (c) 2007 Maxime Wegesin

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.*/

package befungeinterpreter;

import java.io.*;
import java.util.*;

/** This Exception is thrown when a unsupported command is encountered during the execution. */
class SyntaxErrorException
extends Exception
{
    public SyntaxErrorException(char c, int col, int row)
    {
        super("Unsupported Command : \'"+String.valueOf(c)+"\' at ("+col+", "+row+").");
    }
}

/** This Exception can be thrown for the Following reasons:<br><br>
 * Division by zero<br>
 * Invalid put/get coordinates<br>
 */
class ProgramExecutionException
extends Exception
{
    public ProgramExecutionException(String s, int col, int row) {
        super(s + " at (" + col + ", " + row + ").");
    }
}

/** This class represents a Befungeprogram and is able to execute it step by step.
 * There are some minor differences to the original Language Specifications:<br>
 * <li>The stack can hold Java long values (64 bit) instead of C signed longs
 * (usually 32 bit).</li>
 * When saving or loading a file, however, the cells are converted to <b>char</b>.</li>
 * <li>The &-Command reads a supplemental character. However this should not cause
 * any problems. Usually it will be the end-of-line sign it reads, or a whitespace
 * between two numbers.</li>
 * Nontheless every program that runs on Chris Pressey's original interpreter should also
 * work in this one.
 */
public class BefungeProgram 
{
    /** The number of columns and rows a Befunge Program has. */
    public static final int COLS = 80, ROWS = 25;
    private byte[][] program;
    private byte[][] oldProgram; //Needed because the programcode can change during the execution
    private boolean changedSinceLastSave;
    private PC pc;
    private BefungeStack stack;
    private PrintStream out;
    private InputStream in;
    
    private boolean stringmode;
    
    /** Creates a new instance of BefungeProgram.
     * @param out The Writer where the output is written into. */
    public BefungeProgram(OutputStream out, InputStream in) {
        program = new byte[COLS][ROWS];
        oldProgram = new byte[COLS][ROWS];
        clear();
        for (int i=0; i<COLS; i++) {
            for (int j=0; j<ROWS; j++) {
                oldProgram[i][j] = ' ';
            }
        }
        changedSinceLastSave = false;
        pc = new PC();
        stack = new BefungeStack();
        this.out = new PrintStream(out);
        this.in = in;
        stringmode = false;
    }
    
    /** Returns the character or the command in the given column and row.
     * 0, 0 refers to the upper-left command. */
    public long getCellAt(int col, int row) {
        return program[col][row];
    }
    
    /** Changes the character or the command in the given column and row.
     * 0, 0 refers to the upper-left command. */
    public void setCellAt(byte c, int col, int row) {
        program[col][row] = c;
        changedSinceLastSave = true;
    }
    
    public static final int CODE_CHANGED = 0;
    public static final int NEW_OUTPUTS = 1;
    public static final int WAITS_FOR_INPUT = 2;
    public static final int PROGRAM_ENDS = 3;
    public static final int PROGRAM_OK = 4;
    /** Does the next step in interpreting the Befunge program.
     * @return  BefungeProgram.CODE_CHANGED if the code has been changed due to a 'p' comand.
     *          BefungeProgram.NEW_OUTPUTS if outputs have been effectuated.
     *          BefungeProgram.WAITS_FOR_INPUT if Inputs are demanded before continuing.
     *          BefungeProgram.PROGRAM_ENDS if the Programs end has ben encountered.
     *          BefungeProgram.PROGRAM_OK if none of the previous things is true.
     */
    public int nextStep()
    throws SyntaxErrorException, ProgramExecutionException, IOException
    {
        char ch = (char)getCellAt(pc.getX(), pc.getY());
        if (stringmode) {
            if (ch == '"') {
                stringmode = false;
            } else {
                stack.push((long)ch);
            }
        } else { 
            long v1, v2, v3; //Helping variables for complicated stack operations
            int c; //For the Input Commands (&, ~)
            switch (ch) {
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    stack.push(Character.digit(ch, 10));
                    break;
                //Addition
                case '+':
                    stack.push(stack.pop()+stack.pop());
                    break;
                //Subtraction   
                case '-':
                    stack.push(-stack.pop()+stack.pop());
                    break;
                //Multiplication
                case '*':
                    stack.push(stack.pop()*stack.pop());
                    break;
                //Division
                case '/':
                    v2 = stack.pop();
                    if (v2 == 0) 
                        throw new ProgramExecutionException("Division by zero", pc.getX(), pc.getY());
                    stack.push(stack.pop()/v2);
                    break;
                //Modulo
                case '%':
                    v2 = stack.pop();
                    stack.push(stack.pop()%v2);
                    break;
                //Not
                case '!':
                    v1 = stack.pop();
                    if (v1 == 0) {
                        stack.push(1);
                    } else {
                        stack.push(0);
                    }
                    break;
                //Greater
                case '`':
                    v2 = stack.pop();
                    if (stack.pop() > v2) {
                        stack.push(1);
                    } else {
                        stack.push(0);
                    }
                    break;
                //Right
                case '>':
                    pc.setDirection(PC.RIGHT);
                    break;
                //LEFT
                case '<':
                    pc.setDirection(PC.LEFT);
                    break;
                //UP
                case '^':
                    pc.setDirection(PC.UP);
                    break;
                //Down
                case 'v':
                    pc.setDirection(PC.DOWN);
                    break;
                //Random
                case '?':
                    pc.setDirection(PC.RANDOM);
                    break;
                //Horiz. if
                case '_':
                    if (stack.pop() == 0) {
                        pc.setDirection(PC.RIGHT);
                    } else {
                        pc.setDirection(PC.LEFT);
                    }
                    break; 
                //Vert. if
                case '|':
                    if (stack.pop() == 0) {
                        pc.setDirection(PC.DOWN);
                    } else {
                        pc.setDirection(PC.UP);
                    }
                    break;
                //Stringmode    
                case '"':
                    stringmode = true;
                    break;
                //Duplicate
                case ':':
                    v1 = stack.pop();
                    stack.push(v1);
                    stack.push(v1);
                    break;
                //Swap    
                case '\\':
                    v2 = stack.pop();
                    v1 = stack.pop();
                    stack.push(v2);
                    stack.push(v1);
                    break;
                //Pop
                case '$':
                    stack.pop();
                    break;
                //Print numbers
                case '.':
                    out.print(stack.pop() + " ");
                    out.flush();
                    pc.move();
                    return NEW_OUTPUTS;
                //Print characters
                case ',':
                    out.print((char)(stack.pop()%256));
                    out.flush();
                    pc.move();
                    return NEW_OUTPUTS;
                //Bridge
                case '#':
                    pc.move();
                    break;
                //Get
                case 'g':
                    v2 = stack.pop();
                    v1 = stack.pop();
                    if (v1 < 0 || v1 >= COLS || v2 < 0 || v2 >= ROWS) {
                        stack.push(0);
                        throw new ProgramExecutionException("Illegal Coordinates for 'g' Instruction", pc.getX(), pc.getY());
                    }
                    stack.push(getCellAt((int)v1, (int)v2));
                    break;
                //Put
                case 'p':
                    v3 = stack.pop();
                    v2 = stack.pop();
                    v1 = stack.pop();
                    if (v2 < 0 || v2 >= COLS || v3 < 0 || v3 >= ROWS)
                        throw new ProgramExecutionException("Illegal Coordinates for 'p' Instruction", pc.getX(), pc.getY());
                    setCellAt((byte)v1, (int)v2, (int)v3);
                    pc.move();
                    return CODE_CHANGED;
                //Value Input
                case '&':
                    //First ignore every character which is not a digit
                    do {
                        c = in.read();
                        if (c == -1) {
                            return WAITS_FOR_INPUT;
                        }
                    } while (!Character.isDigit((char)c));
                    long result = 0;
                    while (Character.isDigit((char)c)) {
                        result *= 10;
                        result += Character.digit((char)c, 10);
                        c = in.read();
                    } 
                    stack.push(result);
                    break;
                //Character Input
                case '~':
                    c = in.read();
                    if (c == -1) {
                        return WAITS_FOR_INPUT;
                    }
                    stack.push((long)c);
                    break;
                //Null-Command
                case ' ':
                    break;
                //End
                case '@':
                    return PROGRAM_ENDS;
                //Unknown Command   
                default:
                    pc.move();
                    throw new SyntaxErrorException(ch, pc.getX(), pc.getY());
            }
        }
        pc.move();
        return PROGRAM_OK;
    }
    
    /** Restarts the program, i.e. puts the Program Counter (PC) into the
     * upper-left corner, pointing to the right and clears the stack. Should
     * be called before starting a program. Then you use nextStep() to
     * execute it. */
    public void reset() {
        stack.clear();
        stringmode = false;
        pc.setPos(0, 0);
        pc.setDirection(PC.RIGHT);
    }
    
    /** Clears the program, i.e. sets every cell to ' '. */
    public void clear() {
        for (int i=0; i<COLS; i++) {
            for (int j=0; j<ROWS; j++) {
                setCellAt((byte)' ', i, j);
            }
        }    
    }
    
    /** Loads a Befungefile from a textfile. The Textfile should contain
     * a linefeed only as Carriage return. */
    public void loadFile(String file)
    throws IOException
    {
        int col=0, row=0;
        int c;
        clear();
        FileReader lf =    new FileReader(file);
        while ((c = lf.read()) != -1) {
            if ((char)c == 10) {
                col = 0; row++;
            } else {
                if (col < 0 || col >= COLS || row < 0 || row >= ROWS) {
                    throw new IOException("Unsupported file format.");
                } else {
                    setCellAt((byte)c, col, row);
                    col++;
                }
            }
        }
        lf.close();
        changedSinceLastSave = false;
    }
    
    /** Saves a Befunge Program on the hard drive. */
    public void saveFile(String file)
    throws IOException
    {
        FileWriter fw = new FileWriter(file);
        //Save each cell
        for (int row=0; row<ROWS; row++) {
            for (int col=0; col<COLS; col++) {
                fw.write((char)getCellAt(col, row));
            }
            fw.write(10); //LineFeed
        }
        fw.close();
        changedSinceLastSave = false;
    }
    
    /** Returns wether setCellAt() ha been called after the last call of
     * saveFile(). */
    public boolean changedSinceLastSave()
    {
        return changedSinceLastSave;
    }
    
    /** Creates a copy of the current Program. The Program can be
     * restored to the state it was when calling this method, by a
     * a call to restoreProgram(). */
    public  void saveProgram()
    {
        for (int i=0; i<program.length; i++) {
            System.arraycopy(program[i], 0, oldProgram[i], 0, program[i].length);
        }
    }
    
    /** Restores the program to the state it was at the last call
     * of saveProgram. */
    public void restoreProgram()
    {
        for (int i=0; i<program.length; i++) {
            System.arraycopy(oldProgram[i], 0, program[i], 0, program[i].length);
        }       
    }
    
    /** Returns the Program Counter. */
    public PC getPC() {
        return pc;
    }
    
    public BefungeStack getBefungeStack()
    {
        return stack;
    }
}
