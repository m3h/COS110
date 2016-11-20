main: main.cpp Adventurer.h Adventurer.cpp
	g++ -static -std=c++11 main.cpp Adventurer.cpp -o main

mainc: mainc.cpp Adventurer.h Adventurer.cpp
	g++ -static -std=c++11 mainc.cpp Adventurer.cpp -o mainc

debug.out: main.cpp Adventurer.h Adventurer.cpp
	g++ -std=c++11 -g main.cpp Adventurer.cpp -o debug.out

vdebug.out: main.cpp Adventurer.h Adventurer.cpp
	g++ -std=c++11 -v main.cpp Adventurer.cpp -o vdebug.out

vdebug: vdebug.out
	valgrind -v --leak-check=full --show-leak-kinds=all ./vdebug.out

debug: debug.out
	gdb ./debug.out

runc: mainc
	./mainc

run: main
	./main
