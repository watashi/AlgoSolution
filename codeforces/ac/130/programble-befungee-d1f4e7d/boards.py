#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#       boards.py
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

import os
import random
import sys
import time

from StringIO import StringIO

from funge import Pointer

class Befunge93Board:
    """A Befunge-93 board"""
    def __init__(self, width, height, debug=False, debug_delay=-1):
        self.pointer = Pointer()
        self._list = []
        # Fill board with whitespace
        for y in range(height):
            self._list.append([' '] * width)
        self.width = width
        self.height = height
        
        self.debug = debug
        self.debug_delay = debug_delay
        self.debugstream = StringIO()
    
    def get(self, x, y):
        # Return space if out of bounds
        if x >= self.width or y >= self.height or x < 0 or y < 0:
            return ' '
        return self._list[y][x]
    
    def put(self, x, y, value):
        # Ignore if out of bounds
        if x >= self.width or y >= self.height or x < 0 or y < 0:
            return
        self._list[y][x] = value
    
    def step(self):
        if self.debug:
            # Redirect output for debugging
            sys.stdout = self.debugstream
        
        c = self.get(self.pointer.x, self.pointer.y)
        if c == '"':
            self.pointer.stringmode = not self.pointer.stringmode
        elif self.pointer.stringmode:
            self.pointer.stack.push(ord(c))
        elif c in "0123456789":
            self.pointer.stack.push(int(c))
        elif c == '>':
            self.pointer.dx = 1
            self.pointer.dy = 0
        elif c == '<':
            self.pointer.dx = -1
            self.pointer.dy = 0
        elif c == '^':
            self.pointer.dx = 0
            self.pointer.dy = -1
        elif c == 'v':
            self.pointer.dx = 0
            self.pointer.dy = 1
        elif c == '?':
            dir = ['>', 'v', '<', '^'][random.randint(0, 3)]
            if dir == '>':
                self.pointer.dx = 1
                self.pointer.dy = 0
            elif dir == '<':
                self.pointer.dx = -1
                self.pointer.dy = 0
            elif dir == '^':
                self.pointer.dx = 0
                self.pointer.dy = -1
            elif dir == 'v':
                self.pointer.dx = 0
                self.pointer.dy = 1
        elif c == '+':
            self.pointer.stack.push(self.pointer.stack.pop() + self.pointer.stack.pop())
        elif c == '*':
            self.pointer.stack.push(self.pointer.stack.pop() * self.pointer.stack.pop())
        elif c == '-':
            a = self.pointer.stack.pop()
            b = self.pointer.stack.pop()
            self.pointer.stack.push(b - a)
        elif c == '/':
            a = self.pointer.stack.pop()
            b = self.pointer.stack.pop()
            self.pointer.stack.push(b / a)
        elif c == '%':
            a = self.pointer.stack.pop()
            b = self.pointer.stack.pop()
            self.pointer.stack.push(b % a)
        elif c == '!':
            x = self.pointer.stack.pop()
            if x == 0:
                self.pointer.stack.push(1)
            else:
                self.pointer.stack.push(0)
        elif c == '`':
            a = self.pointer.stack.pop()
            b = self.pointer.stack.pop()
            if b > a:
                self.pointer.stack.push(1)
            else:
                self.pointer.stack.push(0)
        elif c == '_':
            x = self.pointer.stack.pop()
            if x == 0:
                self.pointer.dx = 1
                self.pointer.dy = 0
            else:
                self.pointer.dx = -1
                self.pointer.dy = 0
        elif c == '|':
            x = self.pointer.stack.pop()
            if x == 0:
                self.pointer.dx = 0
                self.pointer.dy = 1
            else:
                self.pointer.dx = 0
                self.pointer.dy = -1
        elif c == ':':
            x = self.pointer.stack.pop()
            self.pointer.stack.push(x)
            self.pointer.stack.push(x)
        elif c == '\\':
            a = self.pointer.stack.pop()
            b = self.pointer.stack.pop()
            self.pointer.stack.push(a)
            self.pointer.stack.push(b)
        elif c == '$':
            self.pointer.stack.pop()
        elif c == '.':
            x = self.pointer.stack.pop()
            sys.stdout.write(str(x) + ' ')
        elif c == ',':
            x = self.pointer.stack.pop()
            sys.stdout.write(chr(x))
        elif c == '#':
            self.pointer.move()
        elif c == 'p':
            y = self.pointer.stack.pop()
            x = self.pointer.stack.pop()
            v = self.pointer.stack.pop()
            # Simulate unsigned 8-bit integer
            # Also guarantees value is in ASCII range
            while v > 255:
                v = 255 - v
            while v < 0:
                v += 255
            self.put(x, y, chr(v))
        elif c == 'g':
            y = self.pointer.stack.pop()
            x = self.pointer.stack.pop()
            self.pointer.stack.push(ord(self.get(x, y)))
        elif c == '&':
            x = raw_input()
            try:
                self.pointer.stack.push(int(x))
            except ValueError:
                self.pointer.stack.push(0)
        elif c == '~':
            x = sys.stdin.read(1)
            self.pointer.stack.push(ord(x))
        elif c == '@':
            self.pointer.dx = 0
            self.pointer.dy = 0
        
        # Advance pointer
        self.pointer.move()
        
        # Wrap-around
        if self.pointer.x >= self.width:
            self.pointer.x -= self.width
        elif self.pointer.x <= -1:
            self.pointer.x += self.width
        elif self.pointer.y >= self.height:
            self.pointer.y -= self.height
        elif self.pointer.y <= -1:
            self.pointer.y += self.height
        
        # Print debugging information
        if self.debug:
            # Reset debugging output redirection
            sys.stdout = sys.__stdout__
            # Clear screen
            if os.name == "posix":
                sys.stdout.write("\x1b[H\x1b[2J")
            print "Pointer: x=%d y=%d dx=%d dy=%d stringmode=%s" % (self.pointer.x, self.pointer.y, self.pointer.dx, self.pointer.dy, self.pointer.stringmode)
            print "Board:"
            for y in range(self.height):
                for x in range(self.width):
                    c = self.get(x, y)
                    if x == self.pointer.x and y == self.pointer.y:
                        if os.name == "posix":
                            sys.stdout.write("\033[41m")
                    sys.stdout.write(c)
                    if os.name == "posix":
                        sys.stdout.write("\033[0m")
                sys.stdout.write('\n')
            print "Stack:"
            print self.pointer.stack._list
            print "Output:"
            self.debugstream.seek(0)
            print self.debugstream.read()
            if self.debug_delay == -1:
                sys.stdin.read(1)
            else:
                time.sleep(self.debug_delay / 1000.0)
    def dead(self):
        return self.pointer.dx == 0 and self.pointer.dy == 0

class ConcurrentBefunge93Board(Befunge93Board):
    """A Concurrent Befunge-93 board"""
    def __init__(self, width, height, debug=False, debug_delay=-1):
        Befunge93Board.__init__(self, width, height, debug, debug_delay)
        self.pointers = [Pointer()]
    
    def step(self):
        if self.debug:
            # Redirect output for debugging
            sys.stdout = self.debugstream
        
        for pointer in [p for p in self.pointers if not (p.dx == 0 and p.dy == 0)]:
            c = self.get(pointer.x, pointer.y)
            if c == '"':
                pointer.stringmode = not pointer.stringmode
            elif pointer.stringmode:
                pointer.stack.push(ord(c))
            elif c in "0123456789":
                pointer.stack.push(int(c))
            elif c == '>':
                pointer.dx = 1
                pointer.dy = 0
            elif c == '<':
                pointer.dx = -1
                pointer.dy = 0
            elif c == '^':
                pointer.dx = 0
                pointer.dy = -1
            elif c == 'v':
                pointer.dx = 0
                pointer.dy = 1
            elif c == '?':
                dir = ['>', 'v', '<', '^'][random.randint(0, 3)]
                if dir == '>':
                    pointer.dx = 1
                    pointer.dy = 0
                elif dir == '<':
                    pointer.dx = -1
                    pointer.dy = 0
                elif dir == '^':
                    pointer.dx = 0
                    pointer.dy = -1
                elif dir == 'v':
                    pointer.dx = 0
                    pointer.dy = 1
            elif c == '+':
                pointer.stack.push(pointer.stack.pop() + pointer.stack.pop())
            elif c == '*':
                pointer.stack.push(pointer.stack.pop() * pointer.stack.pop())
            elif c == '-':
                a = pointer.stack.pop()
                b = pointer.stack.pop()
                pointer.stack.push(b - a)
            elif c == '/':
                a = pointer.stack.pop()
                b = pointer.stack.pop()
                pointer.stack.push(b / a)
            elif c == '%':
                a = pointer.stack.pop()
                b = pointer.stack.pop()
                pointer.stack.push(b % a)
            elif c == '!':
                x = pointer.stack.pop()
                if x == 0:
                    pointer.stack.push(1)
                else:
                    pointer.stack.push(0)
            elif c == '`':
                a = pointer.stack.pop()
                b = pointer.stack.pop()
                if b > a:
                    pointer.stack.push(1)
                else:
                    pointer.stack.push(0)
            elif c == '_':
                x = pointer.stack.pop()
                if x == 0:
                    pointer.dx = 1
                    pointer.dy = 0
                else:
                    pointer.dx = -1
                    pointer.dy = 0
            elif c == '|':
                x = pointer.stack.pop()
                if x == 0:
                    pointer.dx = 0
                    pointer.dy = 1
                else:
                    pointer.dx = 0
                    pointer.dy = -1
            elif c == ':':
                x = pointer.stack.pop()
                pointer.stack.push(x)
                pointer.stack.push(x)
            elif c == '\\':
                a = pointer.stack.pop()
                b = pointer.stack.pop()
                pointer.stack.push(a)
                pointer.stack.push(b)
            elif c == '$':
                pointer.stack.pop()
            elif c == '.':
                x = pointer.stack.pop()
                sys.stdout.write(str(x) + ' ')
            elif c == ',':
                x = pointer.stack.pop()
                sys.stdout.write(chr(x))
            elif c == '#':
                pointer.move()
            elif c == 'p':
                y = pointer.stack.pop()
                x = pointer.stack.pop()
                v = pointer.stack.pop()
                # Simulate unsigned 8-bit integer
                # Also guarantees value is in ASCII range
                while v > 255:
                    v = 255 - v
                while v < 0:
                    v += 255
                self.put(x, y, chr(v))
            elif c == 'g':
                y = pointer.stack.pop()
                x = pointer.stack.pop()
                pointer.stack.push(ord(self.get(x, y)))
            elif c == '&':
                x = raw_input()
                try:
                    pointer.stack.push(int(x))
                except ValueError:
                    pointer.stack.push(0)
            elif c == '~':
                x = sys.stdin.read(1)
                pointer.stack.push(ord(x))
            elif c == 't':
                new = Pointer()
                new.x = pointer.x
                new.y = pointer.y
                new.dx = pointer.dx * -1
                new.dy = pointer.dy * -1
                for x in pointer.stack._list:
                    new.stack._list.append(x)
                new.move()
                self.pointers.append(new)
            elif c == '@':
                pointer.dx = 0
                pointer.dy = 0
            
            # Advance pointer
            pointer.move()
            
            # Wrap-around
            if pointer.x >= self.width:
                pointer.x -= self.width
            elif pointer.x <= -1:
                pointer.x += self.width
            elif pointer.y >= self.height:
                pointer.y -= self.height
            elif pointer.y <= -1:
                pointer.y += self.height
        
        # Print debugging information
        if self.debug:
            # Reset debugging output redirection
            sys.stdout = sys.__stdout__
            # Clear screen
            if os.name == "posix":
                sys.stdout.write("\x1b[H\x1b[2J")
            for i, pointer in zip(range(len(self.pointers)), self.pointers):
                color = 31 + i % 6
                if os.name == "posix":
                    sys.stdout.write("\033[%dm" % color)
                print "Pointer %d: x=%d y=%d dx=%d dy=%d stringmode=%s" % (i, pointer.x, pointer.y, pointer.dx, pointer.dy, pointer.stringmode)
                if os.name == "posix":
                    sys.stdout.write("\033[0m")
            print "Board:"
            for y in range(self.height):
                for x in range(self.width):
                    c = self.get(x, y)
                    for i, pointer in zip(range(len(self.pointers)), self.pointers):
                        if x == pointer.x and y == pointer.y:
                            if os.name == "posix":
                                color = 41 + i % 6
                                sys.stdout.write("\033[%dm" % color)
                    sys.stdout.write(c)
                    if os.name == "posix":
                        sys.stdout.write("\033[0m")
                sys.stdout.write('\n')
            #print self.pointer.stack._list
            for i, pointer in zip(range(len(self.pointers)), self.pointers):
                color = 31 + i % 6
                if os.name == "posix":
                    sys.stdout.write("\033[%dm" % color)
                print "Stack %d:" % i, pointer.stack._list
                if os.name == "posix":
                    sys.stdout.write("\033[0m")
            print "Output:"
            self.debugstream.seek(0)
            print self.debugstream.read()
            if self.debug_delay == -1:
                sys.stdin.read(1)
            else:
                time.sleep(self.debug_delay / 1000.0)
    
    def dead(self):
        for pointer in self.pointers:
            if not (pointer.dx == 0 and pointer.dy == 0):
                return False
        return True
