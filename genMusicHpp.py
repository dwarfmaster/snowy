#!/usr/bin/python3

import csv

hpp = open('music.hpp', 'w')
hpp.write("#ifndef DEF_MUSIC\n#define DEF_MUSIC\n\nenum Notes{DO,RE,MI,FA,SOL,LA,SI,NO};\nconst unsigned int tempo =")

with open('music','r') as csvfile:
	reader = csv.reader(csvfile,delimiter='\t')
	for row in reader:
		if row[0] == "TEMPO":
			hpp.write(row[1])
			hpp.write("\nstruct Note { Notes note; unsigned int duration; float repeat; };\nNote music = {\n")
		else:
			hpp.write("\t{")
			hpp.write(row[0])
			hpp.write(",")
			hpp.write(row[1])
			hpp.write(",")
			hpp.write(row[2])
			hpp.write("},\n")
	hpp.write("}")

hpp.write("\n\n#endif")
hpp.close()



