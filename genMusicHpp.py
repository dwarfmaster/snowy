#!/usr/bin/python3

import csv

hpp = open('music.cpp', 'w')
hpp.write("#include \"music.hpp\"\n\nconst unsigned int tempo = ")

with open('music','r') as csvfile:
	reader = csv.reader(csvfile,delimiter='\t')
	i = 0
	for row in reader:
		if row[0] == "TEMPO":
			hpp.write(row[1])
			hpp.write(";\nNote music[] = {\n")
		else:
			hpp.write("\t{")
			hpp.write(row[0])
			hpp.write(",")
			hpp.write(row[1])
			hpp.write(",")
			hpp.write(row[2])
			hpp.write("},\n")
			i+=1
	hpp.write("};\nunsigned int sizeMus = ")
	hpp.write(str(i))
	hpp.write(";\n")

hpp.close()



