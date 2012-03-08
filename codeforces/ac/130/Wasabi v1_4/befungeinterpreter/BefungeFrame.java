/*
BefungeFrame.java

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

import befungeinterpreter.*;
import javax.swing.filechooser.FileNameExtensionFilter;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;

/** The main class where everything comes together. */
public class BefungeFrame
extends JStatusbarFrame
implements ActionListener, Runnable
{
    //'File' Menu
    private JMenuItem miNew;
    private JMenuItem miLoad;
    private JMenuItem miSave;
    private JMenuItem miSaveAs;
    private JMenuItem miQuit;
    //'Window' Menu
    private JMenuItem miStack;
    //'?' Menu
    private JMenuItem miDocumentation;
    private JMenuItem miAbout;
    
    private BefungeInterpreterGrid befGrid;
    private JSlider slSpeed;
    private JCheckBox cbFullSpeed;
    private JButton btPause;
    private JButton btRunProgram;
    
    private ConsoleComponent console;
    
    private StackFrame fStackFrame;
    private JFileChooser fileChooser;
    private String filename;
    
    //Controlling the Thread in which the BefProgram is run
    private Thread runThread;
    private boolean paused = false;
    private boolean stopped = true;
    
    /** Creates a new instance of BefungeFrame */
    public BefungeFrame() {
        super("Wasabi");
        
        //The Menu Bar
        JMenuBar mb = new JMenuBar();
        //The File-Menu
        JMenu mFile = new JMenu("File");
            mFile.add(miNew = new JMenuItem("New Program", 'N'));
            mFile.addSeparator();
            mFile.add(miLoad = new JMenuItem("Load", 'L'));        
            mFile.add(miSaveAs = new JMenuItem("Save as", 'A'));
            mFile.add(miSave = new JMenuItem("Save", 'S'));
            mFile.addSeparator();
            mFile.add(miQuit = new JMenuItem("Quit", 'Q'));
        mb.add(mFile);
        //The Windows-Menu
        JMenu mWindows = new JMenu("Windows");
            mWindows.add(miStack = new JMenuItem("Stack"));
        mb.add(mWindows);
        //The ?-Menu
        JMenu mHelp = new JMenu("?");
            mHelp.add(miDocumentation = new JMenuItem("Documentation", 'D'));      
            mHelp.addSeparator();
            mHelp.add(miAbout = new JMenuItem("About", 'A'));
        mb.add(mHelp);
        
        miNew.addActionListener(this);
        miLoad.addActionListener(this);
        miSaveAs.addActionListener(this);
        miSave.addActionListener(this);
        miSave.setEnabled(false); //The user has to use "save as" first
        miQuit.addActionListener(this);
        miStack.addActionListener(this);
        miDocumentation.addActionListener(this);
        miAbout.addActionListener(this);
        
        this.setJMenuBar(mb);
        
        //The Design
        Container cp = getContentPane();
            cp.setLayout(new BorderLayout());
            console = new ConsoleComponent();
            cp.add(befGrid = new BefungeInterpreterGrid(console.getOut(), console.getIn(), getStatusbarLabel()), BorderLayout.CENTER);
                JPanel consoleAndCommandPanel = new JPanel(new BorderLayout());
                    JPanel commandPanel = new JPanel(new GridLayout(1, 4, 20, 20));
                    commandPanel.add(slSpeed = new JSlider(JSlider.HORIZONTAL, 1, 5, 3));
                    commandPanel.add(cbFullSpeed = new JCheckBox("Full Speed", false));
                    commandPanel.add(btPause = new JButton("Pause"));        
                    commandPanel.add(btRunProgram = new JButton("Run!"));       
                consoleAndCommandPanel.add(commandPanel, BorderLayout.NORTH);
                consoleAndCommandPanel.add(console, BorderLayout.CENTER);
            cp.add(consoleAndCommandPanel, BorderLayout.SOUTH);
        
        //Changing the Component's settings
        commandPanel.setBorder(BorderFactory.createEtchedBorder());
        slSpeed.setMajorTickSpacing(1);
        slSpeed.setSnapToTicks(true);
        slSpeed.setPaintTicks(true);
        slSpeed.setPaintLabels(true); 
        
        //Preparing the Action
        btRunProgram.addActionListener(this);
        btPause.addActionListener(this);
        
        pack();
        
        //Preparing the optional Stack-Window, it is invisible at the beginning
        fStackFrame = new StackFrame(befGrid.getProgram().getBefungeStack());
        //Initializing the Filechooser (needed for loading and saving
        fileChooser = new JFileChooser(System.getProperty("java.class.path"));
        fileChooser.setFileFilter(new FileNameExtensionFilter("Befunge Program", "bf"));
        filename = null;
        
        this.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
        this.addWindowListener(
                new WindowAdapter() {
                    public void windowClosing(WindowEvent we) {
                        //Asks if the user wants to save first.
                        if (reallyClose()) {
                            fStackFrame.dispose();
                            dispose();
                            System.exit(0);
                        }
                    }
                }
        ); 
        
        this.setVisible(true);
    }
    
    public void actionPerformed(ActionEvent e) {
        //Has a button been pushed?
        if (e.getSource() instanceof JButton) {
            JButton bt = (JButton)e.getSource();
            buttonAction(bt);
        //Was the Menu used?
        } else if (e.getSource() instanceof JMenuItem) {
            JMenuItem mi = (JMenuItem)e.getSource();
            menuAction(mi);
        }
    }
    
    public void buttonAction(JButton bt)
    {
            //Was it the run/stop-Button?
            if (bt == btRunProgram) {
                //Thanks to the Java Definition of the || operator
                //there should never be a Null Exception here
                if (runThread == null || !runThread.isAlive()) {
                    stopped = false;
                    (runThread = new Thread(this)).start();
                    btRunProgram.setText("Stop!");
                } else {
                    stopped = true;
                    paused = false;
                    btPause.setText("Pause");
                }
            } else if (bt == btPause) {
                paused = !paused;
                if (paused) {
                    btPause.setText("Continue");
                    befGrid.repaint();
                } else {
                    btPause.setText("Pause");
                }
            }
    }
    
    /**
     * 
     * @param mi 
     */
    public void menuAction(JMenuItem mi)
    {
            if (!stopped && (mi == miNew || mi == miLoad || mi == miSave)) {
                JOptionPane.showMessageDialog(  this,
                                                "Please stop the running program first.",
                                                "Dangerous operation",
                                                JOptionPane.WARNING_MESSAGE);
                return;
            }

            //New Program
            if (mi == miNew) {
                befGrid.getProgram().clear();
                filename = null;
            //Load File
            } else if (mi == miLoad) {
                if (fileChooser.showOpenDialog(this) == JFileChooser.APPROVE_OPTION) {
                    try {
                        filename = fileChooser.getSelectedFile().getAbsolutePath();
                        befGrid.getProgram().loadFile(filename);
                    } catch (IOException ex) {
                        JOptionPane.showMessageDialog(this, "Error occured while loading.", "Error", JOptionPane.ERROR_MESSAGE);
                    }
                }
            //Save File
            } else if (mi == miSaveAs) {
                if (fileChooser.showSaveDialog(this) == JFileChooser.APPROVE_OPTION) {
                    try {
                        filename = fileChooser.getSelectedFile().getAbsolutePath();
                        filename = filename.toLowerCase().endsWith(".bf") ? filename : filename+".bf";
                        befGrid.getProgram().saveFile(filename);
                    } catch (IOException ex) {
                        JOptionPane.showMessageDialog(this, "Error occured while saving.", "Error", JOptionPane.ERROR_MESSAGE);
                    }
                }
            } else if (mi == miSave) {
                if (filename != null) {
                    try {
                        befGrid.getProgram().saveFile(filename);
                    } catch (IOException e) {
                        JOptionPane.showMessageDialog(this, "Error occured while saving.", "Error", JOptionPane.ERROR_MESSAGE);
                    }
                }
            //Quit Program
            } else if (mi == miQuit) {
                dispatchEvent(new WindowEvent(this, WindowEvent.WINDOW_CLOSING));
            //Open Stack Window
            } else if (mi == miStack) {
                fStackFrame.setLocation(getX()+getWidth(), getY());
                fStackFrame.setSize(200, this.getHeight());
                fStackFrame.setVisible(true);
            //Open Documentation
            } else if (mi == miDocumentation) {
                try {
                    JEditorPane docContent = new JEditorPane();
                     docContent.setContentType("text/html");
                     docContent.setPage(getClass().getResource("WasabiDoc.html"));
                     docContent.setEditable(false);
                    JFrame docWindow = new JFrame("Documentation");
                     docWindow.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
                     docWindow.getContentPane().add(new JScrollPane(docContent));
                     docWindow.setSize(640, 640);
                     docWindow.setVisible(true);
                } catch (IOException ex) {
                    JOptionPane.showMessageDialog(  this,
                                                    "WasabiDoc.html was not found in the Program Directory.",
                                                    "Documentation not found!",
                                                    JOptionPane.ERROR_MESSAGE);
                }
            //Open Aboutbox
            } else if (mi == miAbout) {
                JOptionPane.showMessageDialog(this, "WASABI v1.4\n"
                                                   +"Wasabi 's A Superbly Asinine Befunge Interpreter\n"
                                                   +"(c) 2007 by Maxime Wegesin", "About", JOptionPane.INFORMATION_MESSAGE);
            }
            
            befGrid.repaint();
            //When the file has not been saved yet it has no name (filename == null). Thus
            //you have to use the saveAs Command first
            miSave.setEnabled(filename != null);
    }
    
    public void run()
    {        
        befGrid.lockGrid();
        befGrid.getProgram().reset();
        befGrid.getProgram().saveProgram(); //Save the old program before it modifies itself
        int result = BefungeProgram.PROGRAM_OK;
        boolean ignoreErrors = false;
        boolean ignoreSyntaxErrors = false;
        do {
            if (!paused) {
                //Program execution (Mainly error handling, because the BefungeProgram class can execute itself.
                try {
                    result = befGrid.getProgram().nextStep();
                } catch (SyntaxErrorException e) {
                    if (!ignoreSyntaxErrors) {
                        int resp = JOptionPane.showConfirmDialog(   this,
                                                                    e.getMessage() +
                                                                    "\nIgnore next syntax error(s)?",
                                                                    "Error",
                                                                    JOptionPane.YES_NO_OPTION,
                                                                    JOptionPane.WARNING_MESSAGE);
                        if (resp == JOptionPane.YES_OPTION) {
                            ignoreSyntaxErrors = true;
                        }
                    }
                } catch (ProgramExecutionException e) {
                    if (!ignoreErrors) {
                        int resp = JOptionPane.showConfirmDialog(   this,
                                                                    e.getMessage() +
                                                                    "\nIgnore next error(s)?",
                                                                    "Error",
                                                                    JOptionPane.YES_NO_OPTION,
                                                                    JOptionPane.WARNING_MESSAGE);
                        if (resp == JOptionPane.YES_OPTION) {
                            ignoreErrors = true;
                        }
                    }
                } catch (IOException e) {
                    JOptionPane.showMessageDialog(this, "Error with I/O-operations.", "Error", JOptionPane.ERROR_MESSAGE);
                    stopped = true;
                }
                
                //Slow down and refresh visualization
                try {
                    if (!cbFullSpeed.isSelected()) {
                        befGrid.repaint();
                        if (fStackFrame.isVisible()) {
                            fStackFrame.updateStackFrame();
                        }
                        Thread.sleep(slSpeed.getMaximum()*200 - slSpeed.getValue()*200 + 5);
                    }
                    //The code needs a visual update?
                    if (result == BefungeProgram.CODE_CHANGED) {
                        befGrid.repaint();
                    }
                } catch (InterruptedException e) {
                    //Should never happen
                }
            }
        } while (result != BefungeProgram.PROGRAM_ENDS && !stopped);
        btRunProgram.setText("Run!");
        stopped = true; //The program is stopped now
        try {
            while (console.getIn().read() != -1) {} //Clears the input stream;
            console.getOut().write("\n***Program ends***\n".getBytes());
        } catch (IOException ex) {
            //Nothing...
        }
        befGrid.getProgram().restoreProgram(); //Restores the Program to the state it had before Execution
        befGrid.getProgram().reset();
        befGrid.repaint();
        fStackFrame.updateStackFrame();
        befGrid.unlockGrid(); //Reallow the user to edit the BefungeGrid
    }
    
    /** Asks the user wether he wants to save his program before quitting or not.
     * @returns True if the window can be closed, false if not. */
    private boolean reallyClose() //Got more complicated than I thought
    {
        if (runThread != null && runThread.isAlive()) {
            JOptionPane.showMessageDialog(  this,
                                            "Please stop the running program first",
                                            "Warning", JOptionPane.WARNING_MESSAGE  );
            return false;
        }
        
        if (befGrid.getProgram().changedSinceLastSave()) {
            int result = JOptionPane.showConfirmDialog( this,
                                                        "Do you want to save "+
                                                        (filename == null ? "this program" : "'"+(new File(filename)).getName()+"'") +
                                                        " before closing WASABI?",
                                                        "Closing",
                                                        JOptionPane.YES_NO_CANCEL_OPTION);

            if (result == JOptionPane.YES_OPTION) {
                if (filename == null) {
                    if (fileChooser.showSaveDialog(this) == JFileChooser.APPROVE_OPTION) {
                        filename = fileChooser.getSelectedFile().getAbsolutePath();
                        filename = filename.toLowerCase().endsWith(".bf") ? filename : filename + ".bf";
                    } else {
                        return false;
                    }
                }
                try {
                    befGrid.getProgram().saveFile(filename);
                } catch (IOException e) {
                    JOptionPane.showMessageDialog(this, "Error occured while saving.", "Error", JOptionPane.ERROR_MESSAGE);
                    return false;
                }
            } else if (result == JOptionPane.NO_OPTION) {
                return true;
            } else { //Cancelled
                return false;
            }
        } 
        return true;
    }
    
    public static void main(String[] args) {
        BefungeFrame bf = new BefungeFrame();
        if (args.length >= 1) {
            try {
                bf.befGrid.getProgram().loadFile(args[0]);
            } catch (IOException e) {
                JOptionPane.showMessageDialog(  bf, 
                                                "Error occured while trying to load " + args[0],
                                                "Error", JOptionPane.ERROR_MESSAGE);
            }
        }
    }
}
