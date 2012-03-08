#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#       befungee.py
#       
#       Copyright 2010 Curtis (Programble) <programble@gmail.com>
#       
#       This program is free software; you can redistribute it and/or modify
#       it under the terms of the GNU General Public License as published by
#       the Free Software Foundation; either version 2 of the License, or
#       (at your option) any later version.
#       
#       This program is distributed in the hope that it will be useful,
#       but WITHOUT ANY WARRANTY; without even the implied warranty of
#       MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#       GNU General Public License for more details.
#       
#       You should have received a copy of the GNU General Public License
#       along with this program; if not, write to the Free Software
#       Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
#       MA 02110-1301, USA.

import sys

from optparse import OptionParser

import boards

__version__ = "0.2.0"


def main():
    parser = OptionParser(usage="%prog [options] [file]")
    parser.add_option("-m", "--mode", dest="mode", action="store", default="b93", help="Mode to run in")
    parser.add_option("--b93", dest="mode", action="store_const", const="b93", help="Run in Befunge-93 mode (default)")
    parser.add_option("--cb93", dest="mode", action="store_const", const="cb93", help="Run in Concurrent Befunge-93 mode")
    parser.add_option("-d", "--debug", dest="debug", action="store_true", default=False, help="Turn on debugging mode")
    parser.add_option("--delay", dest="debugdelay", action="store", type="int", default=-1, help="Delay in milliseconds between each step in debugging mode, or -1 to wait for input")
    parser.add_option("-w", "--width", "-c", "--columns", dest="width", action="store", type="int", default=80, help="Board width")
    parser.add_option("--height", "-r", "--rows", dest="height", action="store", type="int", default=25, help="Board height")
    parser.add_option("-x", "--x", dest="x", action="store", type="int", default=0, help="Initial X coordinate")
    parser.add_option("-y", "--y", dest="y", action="store", type="int", default=0, help="Initial Y coordinate")
    parser.add_option("--version", dest="version", action="store_true", default=False, help="Show version information and exit")
    (options, args) = parser.parse_args()
    
    if options.version:
        print "befungee", __version__
        return 0
    
    if options.mode == "b93":
        board = boards.Befunge93Board(options.width, options.height, options.debug, options.debugdelay)
        board.pointer.x, board.pointer.y = options.x, options.y
    elif options.mode == "cb93":
        board = boards.ConcurrentBefunge93Board(options.width, options.height, options.debug, options.debugdelay)
        board.pointers[0].x, board.pointers[0].y = options.x, options.y
    else:
        print "Mode not supported"
        return 1
    
    # Default to reading from stdin
    if len(args) == 0:
        args = ["-"]
    
    # Read in file
    if args[0] == "-":
        # Read from stdin
        infile = sys.stdin
    else:
        try:
            infile = open(args[0], 'r')
        except IOError:
            print "Could not open file"
            return 1
    
    x = y = 0
    while True:
        c = infile.read(1)
        if c == '':
            # EOF
            break
        if c == '\n':
            y += 1
            x = 0
            continue
        if x > options.width or y > options.height:
            print "File too large"
            return 1
        board.put(x, y, c)
        x += 1
    
    # Close the file (but don't close stdin!)
    if infile != sys.stdin:
        infile.close()
    
    # Run the program
    while not board.dead():
        try:
            board.step()
        except Exception, ex:
            # Make sure stdout is not redirected
            sys.stdout = sys.__stdout__
            print "Error (%d,%d):" % (board.pointer.x, board.pointer.y), ex
            return 1
    
    return 0

if __name__ == '__main__':
    sys.exit(main())
