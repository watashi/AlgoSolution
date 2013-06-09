#!/usr/bin/python3

import os, sys

if os.getenv('USER') != 'watashi':
  sys.stdin = open('positive.in', 'r')
  sys.stdout = open('positive.out', 'w')

if __name__ == '__main__':
  n = int(input())
  n -= 2 * input().count('-')
  print(max(n, 0))
