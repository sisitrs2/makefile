
run: Directory.o FileEdit.o main.o
	g++ Directory.o FileEdit.o main.o -o run

Directory.o: Directory.cpp Directory.h
	g++ -c Directory.cpp

FileEdit.o: FileEdit.cpp FileEdit.h
	g++ -c FileEdit.cpp

main.o: main.cpp 
	g++ -c main.cpp

clear:
	rm *.o run
