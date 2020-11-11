CC = g++
FLAGS = -std=c++17 -Wall -g
object_files = Converter.o Interface.o main.o

all: compile clean

compile: ${object_files}
	${CC} ${object_files} -o decbinhex

main.o: main.cpp
	${CC} ${FLAGS} -c main.cpp

Converter.o: Converter.cpp Converter.h
	${CC} ${FLAGS} -c Converter.cpp Converter.h

Interface.o: Interface.cpp Interface.h
	${CC} ${FLAGS} -c Interface.cpp Interface.h

clean:
	rm *.o rm *.gch
