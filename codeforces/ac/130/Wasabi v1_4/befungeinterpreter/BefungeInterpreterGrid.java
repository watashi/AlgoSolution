/*
BefungeInterpreterGrid.java
Created on 8. Juni 2007, 23:02

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

/**
 *
 * @author Maxime
 */
import java.io.*;
import java.awt.*;
import java.awt.event.*;
import java.awt.datatransfer.*;
import javax.swing.*;

/** A component providing a Befunge Editor. Contains an instance of BefungeProgram. */
public final class BefungeInterpreterGrid
extends JComponent
implements ActionListener, ClipboardOwner
{
    private BefungeProgram program;
    private JLabel lbStatus;
    private JPopupMenu pmCopyPaste;
    private JMenuItem miCopy;
    private JMenuItem miCut;
    private JMenuItem miPaste;
    private JMenuItem miReverse;
    private JMenuItem miUndo;
    private boolean undoable;
    private Clipboard clipboard;
    private boolean gridLocked; //Specifies wether the grid should react to events or not
    private int tempX, tempY; //Needed for the selections
    private boolean button1Down; //Specifies wether the left Mouse Button is down or not
    private Rectangle selection; //Needed to hold a selection

    /** Creates a new instance of the BefungeInterpreterGrid.
     * @param out The OutputStream the BefungeProgram will write to.
     * @param in The InputStream the BefungeProgram will get its Data from. */
    public BefungeInterpreterGrid(OutputStream out, InputStream in)  
    {
        this(out, in, null);
    }
    
    /** Creates a new instance of the BefungeInterpreterGrid.
     * @param out The OutputStream the BefungeProgram will write to.
     * @param in The InputStream the BefungeProgram will get its Data from.
     * @param lbStatusbar A label on which some information is printed. */
    public BefungeInterpreterGrid(OutputStream out, InputStream in, JLabel lbStatus) {
        super();
        
        this.lbStatus = lbStatus;
        
        pmCopyPaste = new JPopupMenu();
            pmCopyPaste.add(miCopy = new JMenuItem("Copy"));
            pmCopyPaste.add(miCut = new JMenuItem("Cut"));
            pmCopyPaste.add(miPaste = new JMenuItem("Paste"));
            pmCopyPaste.addSeparator();
            pmCopyPaste.add(miReverse = new JMenuItem("Reverse"));
            pmCopyPaste.addSeparator();
            pmCopyPaste.add(miUndo = new JMenuItem("Undo"));
            
        miCopy.addActionListener(this);
        miCut.addActionListener(this);
        miPaste.addActionListener(this);
        miReverse.addActionListener(this);
        miUndo.addActionListener(this);
        
        undoable = false;
        
        clipboard = getToolkit().getSystemClipboard();
        
        program = new BefungeProgram(out, in);
        selection = new Rectangle(0, 0, 1, 1);
        gridLocked = false;
        
        this.enableEvents(  AWTEvent.MOUSE_EVENT_MASK + 
                            AWTEvent.MOUSE_MOTION_EVENT_MASK + 
                            AWTEvent.KEY_EVENT_MASK );
        addFocusListener(
            new FocusListener() {
                public void focusLost(FocusEvent fe) { repaint(); }
                public void focusGained(FocusEvent fe) { repaint(); }
            }
        );
    }

    public Dimension getPreferredSize()
    {
        return new Dimension(BefungeProgram.COLS*12, BefungeProgram.ROWS*17);
    }
    
    public Dimension getMinimumSize()
    {
        return new Dimension(BefungeProgram.COLS*12, BefungeProgram.ROWS*17);
    }
    
    /** Paints the BefungeGrid. If it has the focus there will be a black rectangle around it. */ 
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        int width = getWidth(); int height = getHeight();
        double cellWidth = (double)width/(double)BefungeProgram.COLS;
        double cellHeight = (double)height/(double)BefungeProgram.ROWS;
        Color oldColor = g.getColor();
        Font oldFont = g.getFont();
        
        if (isOpaque()) {
            //Paint a background
            g.setColor(Color.WHITE);
            g.fillRect(0, 0, width, height);
        }
        
        //Painting the Grid
        g.setColor(Color.LIGHT_GRAY);
        //Vertical lines
        for (int i=1; i<BefungeProgram.COLS; i++) {
            g.drawLine( (int)Math.round(i*cellWidth), 0,
                        (int)Math.round(i*cellWidth), height);
        }
        //Horizontal lines
        for (int i=1; i<BefungeProgram.ROWS; i++) {
            g.drawLine( 0, (int)Math.round(i*cellHeight), 
                        width, (int)Math.round(i*cellHeight));
        }
        
        if (hasFocus()) {
            g.setColor(Color.BLACK);
            g.drawRect(0, 0, getWidth()-1, getHeight()-1);
        }
        
        //Drawing the Characters/Commands
        g.setColor(Color.BLACK);
        g.setFont(new Font("Monospaced", Font.PLAIN, 12));
        for (int i=0; i<BefungeProgram.COLS; i++) {
            for (int j=0; j<BefungeProgram.ROWS; j++) {
                //Calculatin the Data to center the characters
                int charWidth = g.getFontMetrics().charWidth((char)program.getCellAt(i,j));
                int charHeight = g.getFontMetrics().getAscent();
                int x = (int)Math.round((2*i+1)*cellWidth/2 - charWidth/2);
                int y = (int)Math.round((2*j+1)*cellHeight/2 + charHeight/2);
                g.drawString(String.valueOf((char)program.getCellAt(i,j)), x, y);
            }
        }
        
        //Showing which cell the PC is on
        g.setColor(new Color(100, 0, 0));
        g.drawRect( (int)Math.round(program.getPC().getX() * cellWidth),
                    (int)Math.round(program.getPC().getY() * cellHeight),
                    (int)Math.round(cellWidth), (int)Math.round(cellHeight));
        
        //Showing the selection
        if (selection.width != 1 || selection.height != 1) {
            g.setColor(new Color(0, 0, 200));
            g.drawRect( (int)Math.round(selection.x * cellWidth),
                        (int)Math.round(selection.y * cellHeight),
                        (int)Math.round(selection.width * cellWidth),
                        (int)Math.round(selection.height * cellHeight) );
            g.setColor(new Color(0, 0, 200, 50));
            g.fillRect( (int)Math.round(selection.x * cellWidth),
                        (int)Math.round(selection.y * cellHeight),
                        (int)Math.round(selection.width * cellWidth),
                        (int)Math.round(selection.height * cellHeight) );            
        }
        
        g.setColor(oldColor);
        g.setFont(oldFont);
        
        if (lbStatus != null) {
            StringBuffer text;
            text = new StringBuffer(String.format(" X: %02d  Y: %02d", program.getPC().getX(), program.getPC().getY()));
            text.append("          ");
            switch (program.getPC().getDirection()) {
                case PC.DOWN:
                    text.append("v");
                    break;
                    
                case PC.UP:
                    text.append("^");
                    break;
                    
                case PC.LEFT:
                    text.append("<");
                    break;
                    
                case PC.RIGHT:
                    text.append(">");
                    break;
            }
            lbStatus.setText(text.toString());
        }
    }
    
    public void processMouseEvent(MouseEvent me)
    {
        if (!gridLocked) {
            if (me.isPopupTrigger()) {
                miPaste.setEnabled(clipboard.isDataFlavorAvailable(DataFlavor.stringFlavor));
                miReverse.setEnabled(selection.width == 1 || selection.height == 1);
                miUndo.setEnabled(undoable);
                pmCopyPaste.show(this, me.getX(), me.getY());
            }
            
            if (me.getID() == MouseEvent.MOUSE_PRESSED) {
                requestFocus();
                if (me.getButton() == MouseEvent.BUTTON1) {
                    //Replace the PC
                    Point PCPos = pixelToCell(new Point(me.getX(), me.getY()));
                    program.getPC().setPos(PCPos.x, PCPos.y);
                    //Create a rectangle and set its upper-left corner to the cell clicked on.
                    selection.x = tempX = PCPos.x;
                    selection.y = tempY = PCPos.y;
                    selection.width = selection.height = 1;        
                    button1Down = true;
                }
                repaint();            
            } else if (me.getID() == MouseEvent.MOUSE_RELEASED) {
                if (me.getButton() == MouseEvent.BUTTON1) {
                    button1Down = false;
                }
            }
            super.processMouseEvent(me);
        }
    }
    
    public void processMouseMotionEvent(MouseEvent me)
    {
        if (!gridLocked) {
            if (me.getID() == MouseEvent.MOUSE_DRAGGED && button1Down) {
                //get the cell the mouse is over
                Point cell = pixelToCell(new Point(me.getX(), me.getY()));
                selection.width = Math.abs(tempX - cell.x) + 1;
                selection.height = Math.abs(tempY - cell.y) + 1;
                if (cell.x < tempX) {
                    selection.x = cell.x;
                } else {
                    selection.x = tempX;
                }
                if (cell.y < tempY) {
                    selection.y = cell.y;
                } else {
                    selection.y = tempY;
                }
                repaint();
            }                    
        }
        super.processMouseMotionEvent(me);
    }
    
    public void processKeyEvent(KeyEvent ke)
    {
        if (!gridLocked) {
            //Deselect
            selection.width = selection.height = 1;
            if (ke.getID() == KeyEvent.KEY_TYPED) {
                setUndoPoint();
                //The Backspace key will be treated in keyPressed()
                if (ke.getKeyChar() == '\b')
                    return;
                //Zeichen ins Programm schreiben        
                char c = ke.getKeyChar();
                program.setCellAt((byte)c, program.getPC().getX(), program.getPC().getY());

                //If a direction changing command has been typed, the direction is immediately changed
                switch (c) {
                    case '>':
                        program.getPC().setDirection(PC.RIGHT);
                        break;
                    case '<':
                        program.getPC().setDirection(PC.LEFT);
                        break;
                    case '^':
                        program.getPC().setDirection(PC.UP);
                        break;
                    case 'v':
                        program.getPC().setDirection(PC.DOWN);
                        break;
                }
                program.getPC().move();
                repaint();
            } else if (ke.getID() == KeyEvent.KEY_PRESSED) {
                //Mit Cursortasten PC bewegen
                int kc = ke.getKeyCode();
                switch (kc) {                       
                    case KeyEvent.VK_UP:
                        program.getPC().setDirection(PC.UP);
                        program.getPC().move();
                        break;

                    case KeyEvent.VK_DOWN:
                        program.getPC().setDirection(PC.DOWN);
                        program.getPC().move();
                        break;

                   case KeyEvent.VK_LEFT:
                        program.getPC().setDirection(PC.LEFT);
                        program.getPC().move();
                        break;

                    case KeyEvent.VK_RIGHT:
                        program.getPC().setDirection(PC.RIGHT);
                        program.getPC().move();
                        break;

                    case KeyEvent.VK_BACK_SPACE:
                        program.getPC().moveBackwards();
                        program.setCellAt((byte)' ', program.getPC().getX(), program.getPC().getY());
                        break;
                }
                repaint();                
            }
            super.processKeyEvent(ke);
        }
    }
    
    public void lostOwnership(Clipboard c, Transferable cont) {}
    //Actions on the Popupmenu
    public void actionPerformed(ActionEvent ae)
    {
        if (ae.getSource() instanceof JMenuItem) {
            JMenuItem mi = (JMenuItem)ae.getSource();
            StringBuffer sb = new StringBuffer();
            int i, j;
            if (mi == miCopy) {
                for (i=selection.y; i<selection.y+selection.height; i++) {
                    for (j = selection.x; j < selection.x+selection.width; j++) {
                        sb.append((char)program.getCellAt(j, i));
                    }
                    sb.append('\n');
                }
                clipboard.setContents(new StringSelection(new String(sb)), this);
            } else if (mi == miCut) {
                setUndoPoint(); 
                for (i=selection.y; i<selection.y+selection.height; i++) {
                    for (j = selection.x; j < selection.x+selection.width; j++) {
                        sb.append((char)program.getCellAt(j, i));
                        program.setCellAt((byte)' ', j, i);
                    }
                    sb.append('\n');
                }
                clipboard.setContents(new StringSelection(new String(sb)), this);
            } else if (mi == miPaste) {
                setUndoPoint();
                try {
                    Transferable data = clipboard.getContents(this);
                    String s = (String)data.getTransferData(DataFlavor.stringFlavor);
                    int x = program.getPC().getX();
                    int y = program.getPC().getY();
                    for (i=0; i<s.length(); i++) {
                        if (s.charAt(i) == '\n') {
                            y++;
                            x = program.getPC().getX();
                        } else {
                            program.setCellAt( (byte) s.charAt(i), 
                                                x%BefungeProgram.COLS, 
                                                y%BefungeProgram.ROWS   );
                            x++;
                        }
                    }
                } catch (Exception ex) {
                    //Did you say something?
                }
            } else if (mi == miReverse) {
                byte swapVar;
                int x1, y1, x2, y2;
                for (i=0; i<((selection.width == 1) ? (selection.height/2) : (selection.width/2)); i++) {
                    if (selection.width == 1) {
                        x1 = x2 = selection.x;
                        y1 = selection.y+i;
                        y2 = selection.y+selection.height-i-1;
                    } else {
                        y1 = y2 = selection.y;
                        x1 = selection.x+i;
                        x2 = selection.x+selection.width-i-1;
                    }
                    swapVar = (byte)program.getCellAt(x1, y1);
                    program.setCellAt((byte)program.getCellAt(x2, y2), x1, y1);
                    program.setCellAt(swapVar, x2, y2);
                }                
            } else if (mi == miUndo) {
                program.restoreProgram();
                undoable = false;
            }
        }
    }
    
    /** Calculates the column and row of a cell from a given Pixel position. */
    private Point pixelToCell(Point pixelPos)
    {
        double cellWidth = (double)getWidth()/(double)BefungeProgram.COLS;
        double cellHeight = (double)getHeight()/(double)BefungeProgram.ROWS;
        Point result = new Point();
        result.x = (int)Math.floor(pixelPos.x / cellWidth);
        result.y = (int)Math.floor(pixelPos.y / cellHeight);
        if (result.x >= BefungeProgram.COLS) result.x = BefungeProgram.COLS-1;
        if (result.y >= BefungeProgram.ROWS) result.y = BefungeProgram.ROWS-1;
        if (result.x < 0) result.x = 0;
        if (result.y < 0) result.y = 0;
        
        return result;
    }
    
    /** At the next Undo the program will be set to the state it was at the last call of this function. */
    private void setUndoPoint() {
        program.saveProgram();
        undoable = true;
    }
    
    /** Locks the BefungeInterpreterGrid. When the grid is locked, there is no reaction to
     * keyEvents anymore. That means the Content of the BefungeInterpreterGrid cannot be modified
     * by the user. */
    public void lockGrid() {
        selection.width = selection.height = 0;
        gridLocked = true;
    }
    
    /** Unlocks the BefungeInterpreterGrid. */
    public void unlockGrid() {
        gridLocked = false;
    }
    
    public boolean isFocusable()
    {
        return true;
    }    
    
    /** Returns the Befunge Program. */
    public BefungeProgram getProgram()
    {
        return program;
    }
}
