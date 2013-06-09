#!/usr/bin/python2

import os, sys

if os.getenv('USER') != 'watashi':
  sys.stdin = open('positive.in', 'r')
  sys.stdout = open('positive.out', 'w')

if __name__ == '__main__':
  n = input()
  n -= 2 * raw_input().count('-')
  print max(n, 0)
