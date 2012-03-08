/*
PC.java

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

import java.util.*;

/** A class that represents the Program Counter of a Befunge Program. The 
 * Program Counter decides which command will be executed next. */
public class PC 
{
    private int x, y;
    private int dx, dy;
    public static final int UP=0, RIGHT=1, DOWN=2, LEFT=3, RANDOM=4;
    
    private Random rand;
    
    public PC()
    {
        x = y = 0;
        dx = 1; dy = 0;
        rand = new Random();
    }
    
    /** Sets the PC's position, (0, 0) being the upper-left corner of the Befunge Program. 
     * The arguments are not controlled. */
    public void setPos(int newX, int newY) {
        x = newX; y = newY;
    }
    
    /** Moves the PC into the direction specified by setDirection(). */
    public void move() {
        x += dx; y+=dy;
        wrapCoordinates();
    }
    
    /** Moves the PC into the direction opposed to that specified by setDirection(). */
    public void moveBackwards() {
        x -= dx; y-=dy;
        wrapCoordinates();
    }
    
    /** If the coordinates are out of bound they have to be "wrapped" to the other side. */
    private void wrapCoordinates()
    {
        if (x >= BefungeProgram.COLS) {
            x = 0;
        } else if (x < 0) {
            x = BefungeProgram.COLS-1;
        } else if (y >= BefungeProgram.ROWS) {
            y = 0;
        } else if (y < 0) {
            y = BefungeProgram.ROWS-1;
        }        
    }
    
    /** Sets the PC's moving Direction. Valid arguments are<br>
     * PC.UP<br>
     * PC.DOWN<br>
     * PC.LEFT<br>
     * PC.RIGHT<br>
     * PC.RANDOM<br>
     **/
    public void setDirection(int direction)
    throws IllegalArgumentException
    {
        switch (direction) {
            case UP:
                dx = 0; dy = -1;
                break;
                
            case RIGHT:
                dx = 1; dy = 0;
                break;
                
            case DOWN:
                dx = 0; dy = 1;
                break;
                
            case LEFT:
                dx = -1; dy = 0;
                break;
                
            case RANDOM:
                setDirection((new Random()).nextInt(4));
                break;
                
            default:
                throw new IllegalArgumentException("setDirection only accepts PC.LEFT, PC.UP, PC.RIGHT, PC.DOWN or PC.RANDOM");
        }
    }
    
    /** Returns the PC's direction. */
    public int getDirection()
    {
        if (dx == 0) {
            if (dy == 1) return DOWN;
            if (dy == -1) return UP;
        } else {
            if (dx == 1) return RIGHT;
            if (dx == -1) return LEFT;
        }
        return 0;
    }
    
    /** Returns the PC's column, 0 being the leftmost one. */
    public int getX() {
        return x;
    }
    
    /** Returns the PC's row, 0 being the first one from top. */
    public int getY() {
        return y;
    }
}
