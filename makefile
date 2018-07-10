
run: main.o Directory.o FileEdit.o
	g++ main.o Directory.o FileEdit.o -o run

main.o: main.cpp
	g++ -c main.cpp

Directory.o: Directory.cpp Directory.h
	g++ -c Directory.cpp

FileEdit.o: FileEdit.cpp FileEdit.h
	g++ -c FileEdit.cpp

clear:
	rm *.o run
