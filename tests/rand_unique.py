#!/usr/bin/env python3
import sys, random

if len(sys.argv) != 4:
    print("Usage: rand_unique.py N MIN MAX")
    sys.exit(1)

N = int(sys.argv[1])
MIN = int(sys.argv[2])
MAX = int(sys.argv[3])

if MIN < -2147483648 or MAX > 2147483647:
    print("Error: values must be in int32 range")
    sys.exit(1)
if N > (MAX - MIN + 1):
    print("Error: not enough unique numbers in the range")
    sys.exit(1)

numbers = random.sample(range(MIN, MAX + 1), N)
print(" ".join(map(str, numbers)))
