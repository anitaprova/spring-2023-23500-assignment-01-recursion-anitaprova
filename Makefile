main: main.o
	g++ -o main main.o

main.o: main.cpp knights.o

knights.o: knights.cpp knights.h

clean:
	rm -f main main.o knights.o