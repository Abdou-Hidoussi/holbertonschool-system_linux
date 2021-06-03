#!/usr/bin/python3
"""
Locates and replaces the first occurrence of a string in the heap
of a process
"""
from os import close
from sys import argv
import sys


if len(argv) < 4 or int(argv[1]) <= 0 or argv[2] == "" or argv[3] == "":
    print('Usage: {} pid search write'.format(argv[0]))
    sys.exit(1)

pid = argv[1]
string = argv[2]
replace = argv[3]

try:
    maps_file = open('/proc/{}/maps'.format(pid), 'r')
except FileNotFoundError:
    print("pid not found")
    sys.exit(1)
except PermissionError:
    print("{} must be run as Root".format(argv[0]))
    sys.exit(1)

for line in maps_file:
    if line.find("[heap]") != -1:
        mapping = line
        break

addr_start = mapping.split("-")[0]
addr_end = mapping.split("-")[1].split(" ")[0]

try:
    mem_file = open("/proc/{}/mem".format(pid), 'rb+')
except PermissionError:
    print("{} must be run as Root".format(argv[0]))
    maps_file.close()
    sys.exit(1)

mem_file.seek(int(addr_start, 16))
heap = mem_file.read(int(addr_end, 16) - int(addr_start, 16))

try:
    index = heap.index(bytes(string, "ASCII"))
except Exception:
    print("\"{}\" string not found".format(argv[2]))
    sys.exit(1)

mem_file.seek(int(addr_start, 16) + index)
mem_file.write(bytes(replace + "\0", "ASCII"))

print("start address :{}\nend address :{}".format(addr_start, addr_end))
print("old string: {}".format(argv[2]))
print("new string: {}".format(argv[3]))

maps_file.close()
mem_file.close()
