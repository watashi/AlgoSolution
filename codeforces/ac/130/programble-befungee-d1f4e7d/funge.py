#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#       funge.py
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

class Stack:
    """A basic LIFO stack"""
    def __init__(self):
        self._list = []
    
    def push(self, item):
        """Push an item onto the top of the stack"""
        self._list = [item] + self._list
    
    def pop(self):
        """Remove and return the top item on the stack"""
        if len(self) == 0:
            return 0
        item = self._list[0]
        self._list = self._list[1:]
        return item
    
    def peek(self):
        """Return the top item on the stack without removing it"""
        if len(self) == 0:
            return 0
        return self._list[0]
    
    def __len__(self):
        """Return the number of items on the stack"""
        return len(self._list)

class Pointer:
    """A Befunge pointer"""
    def __init__(self):
        self.x = 0
        self.y = 0
        self.dx = 1
        self.dy = 0
        self.stack = Stack()
        self.stringmode = False
    def move(self):
        self.x += self.dx
        self.y += self.dy

