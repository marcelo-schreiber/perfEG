#!/bin/python
from random import randint
from os import system

equationsFile = open("sistemas.dat", "r")

# reading the data from the file
file_data = equationsFile.read()

# splitting the file data into lines
equations = file_data.split("\n\n")
random_equation = equations[randint(0, len(equations) - 1)]

system(f"echo \"{random_equation}\" > tmp.txt")
system(f"likwid-perfctr -C 3 -g FLOPS_DP -m ./perfEG < tmp.txt > results.log")
system("rm tmp.txt")

equationsFile.close()