/*
ConsoleComponent.java

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

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;

class QueueInputStream
extends InputStream
{
    class QueueElement
    {
        public QueueElement(int value, QueueElement next)
        {
            this.value = value;
            this.next = next;
        }
        public QueueElement next;
        public int value;
    }
    
    private QueueElement first = null;
    private QueueElement last = null;
    
    public synchronized void enqueue(int b)
    {
        if (first == null) {
            first = last = new QueueElement(b, null);
        } else {
            last = last.next = new QueueElement(b, null);
        }
    }
    
    public synchronized int read()
    {
        if (first == null) {
            return -1;
        }
        int res = first.value;
        first = first.next;
        return res;
    }
}

class JTextAreaOutputStream
extends OutputStream
{                    
    private JTextArea ta;
    
    public JTextAreaOutputStream(JTextArea ta)
    {
        this.ta = ta;
    }
    
    public void write(int b) {
        ta.append(String.valueOf((char)b));
        if (b == '\n') ta.setCaretPosition(ta.getText().length());
    }
    
    //I only override this one, because there is no need to throw
    //IOExceptions
    public void write(byte[] b) {
        for (int i=0; i<b.length; i++) {
            write(b[i]);
        }
    }
    
    public void clear() {
        ta.setText("");
    }
}

/** This class provides a Console, i.e. a component which is able to read and display text. */
public class ConsoleComponent
extends JPanel
implements ActionListener, KeyListener
{
    private JTextArea taOutput;
    private JTextField tfInput;
    private JButton btOk;
    private JButton btClear;
    
    private QueueInputStream in;
    private JTextAreaOutputStream out;
    
    /** Creates a new instance of ConsoleWindow */
    public ConsoleComponent() {
        //Design
        setLayout(new BorderLayout());
        add(    new JScrollPane(    taOutput = new JTextArea(),
                                    JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED,
                                    JScrollPane.HORIZONTAL_SCROLLBAR_NEVER  ), 
                BorderLayout.CENTER);
        
            JPanel p = new JPanel();
            p.setLayout(new BorderLayout());
            p.add(tfInput = new JTextField(), BorderLayout.CENTER);          
                JPanel p2 = new JPanel(new GridLayout(1, 2));
                p2.add(btOk = new JButton("Ok"));
                p2.add(btClear = new JButton("Clear"));   
            p.add(p2, BorderLayout.EAST);
        add(p, BorderLayout.SOUTH);
        
        //Component Settings
        taOutput.setLineWrap(true);
        taOutput.setFont(new Font("monospaced", Font.PLAIN, 12));
        taOutput.setDoubleBuffered(true);
        taOutput.setEditable(false);
        
        //Event Listeners
        btClear.addActionListener(this);
        btOk.addActionListener(this);
        tfInput.addKeyListener(this);
        
        in = new QueueInputStream();
        out = new JTextAreaOutputStream(taOutput);
    }

    public void keyReleased(KeyEvent ke) {}
    public void keyTyped(KeyEvent ke) {}
        
    public void keyPressed(KeyEvent ke)
    {
        if (ke.getKeyCode() == KeyEvent.VK_ENTER) {
            actionPerformed(new ActionEvent(btOk, ActionEvent.ACTION_PERFORMED, btOk.getText()));
        }
    }
    
    public void actionPerformed(ActionEvent ae)
    {
        if (ae.getSource() == btOk) {
            int i;
            out.write(tfInput.getText().getBytes());
            out.write('\n');
            char[] temp = tfInput.getText().toCharArray();
            for (i=0; i<temp.length; i++) {
                in.enqueue(temp[i]);
            }
            in.enqueue('\n');
            tfInput.setText("");
        } else if (ae.getSource() == btClear) {
            out.clear();
        }
    }
    
    public Dimension getPreferredSize()
    {
        return new Dimension(300, 200);
    }
    
    /** Returns an OutputStream. Everything written to that stream appears immediately on the Outputbox
     * of the console. */
    public OutputStream getOut()
    {
        return out;
    }
    
    /** Returns an Inputstream. Allows you to read the user's entries. */
    public InputStream getIn()
    {
        return in;
    }
}
