/*
BefungeStack.java

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

/** A class that represents the stack Befunge is using. */
public class BefungeStack
{
    class StackElement
    {
        public long value;
        public StackElement next;
        
        public StackElement(long value, StackElement next)
        {
            this.value = value;
            this.next = next;
        }
    }
    
    private StackElement head;
    
    public BefungeStack()
    {
        head = null;
    }
    
    /** Removes the stack's top value and returns it. Returns 0 if the stack is empty. */
    public long pop()
    {
        if (head != null) {
            long result = head.value;
            head = head.next;
            return result;
        } else {
            return 0;
        }
    }
    
    /** Clears the stack. */
    public void clear()
    {
        head = null;
    }
    
    /** Pushs a new long value on top of the stack. */
    public void push(long i)
    {
        head = new StackElement(i, head);
    }

    /** The iterator allows to traverse the stack. The Iterators next() method
     * returns new Long() values.*/
    public Iterator iterator()
    {
        return  
            new Iterator()
            {
                private StackElement el = head;

                public boolean hasNext()
                {
                    return (el != null);
                }

                public Object next()
                {
                    long result = el.value;
                    el = el.next;
                    return new Long(result);
                } 
                
                public void remove() {
                    //Impossible
                }
            }
        ;
    }
}
