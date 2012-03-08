/*
StackFrame.java
Created on 24. Juli 2007, 18:59

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
import java.util.Iterator;

/**
 * This class provides a little Window to show a Befunge Stack's content.
 * You have to specify the Befunge Stack in the constructor. Then all you
 * need to do is to call updateStackFrame() to get the current Stack content 
 * into the Frame.
 * @author Maxime
 */
public class StackFrame
extends JFrame
{ 
    private JTextArea ta;
    private BefungeStack stack;
    
    /** Creates a new instance of StackFrame */
    public StackFrame(BefungeStack stack)
    {
        super("Stack");
        setDefaultCloseOperation(JFrame.HIDE_ON_CLOSE);
        this.stack = stack;
        Container cp = getContentPane();
            cp.setLayout(new BorderLayout());
            cp.add(new JScrollPane(ta = new JTextArea()), BorderLayout.CENTER);
        ta.setEditable(false);
    }
    
    /** Prints the current content of the stack. */
    public void updateStackFrame()
    {
        StringBuffer res = new StringBuffer();
        Iterator it = stack.iterator();
        int counter = 0;
        while (it.hasNext()) {
            long l = ((Long)it.next()).longValue();
            res.append(++counter + ".\t" + l);
            if (l>=33 && l<=126) {  //If the stackElement is a printable character...
                res.append(" - '"+(char)l+"'");  //...it will be printed
            }
            res.append('\n');
        }
        if (counter == 0) {
            ta.setText("Stack is empty.");
        } else {
            ta.setText(new String(res));
        }
    }

}
