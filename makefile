all: Tijolo.o Pilula.o Moeda.o Main.o
	g++ Tijolo.o Pilula.o Moeda.o Main.o -o Pacman.exe
Main.o: Tijolo.h Main.cpp
	g++ -c Main.cpp -o Main.o
Tijolo.o: Tijolo.h Tijolo.cpp
	g++ -c Tijolo.cpp -o Tijolo.o
Pilula.o: Pilula.h Pilula.cpp
	g++ -c Pilula.cpp -o Pilula.o
Moeda.o: Moeda.h Main.cpp
	g++ -c Moeda.cpp -o Moeda.o
clear:
	erase *.o *.exe