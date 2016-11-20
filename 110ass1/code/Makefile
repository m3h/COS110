main: main.o Spell.h Spell.o Wizard.h Wizard.o Hobbit.h Hobbit.o
	g++ -static --std=c++11 main.o Spell.o Wizard.o Hobbit.o -o main

main.o: main.cpp
	g++ -static --std=c++11 main.cpp -c

Wizard.o: Spell.h Spell.cpp Wizard.h Wizard.cpp
	g++ -static --std=c++11 -c Wizard.cpp

Spell.o: Spell.h Spell.cpp
	g++ -static --std=c++11 -c Spell.cpp

Hobbit.o: Hobbit.h Hobbit.cpp
	g++ -static --std=c++11 -c Hobbit.cpp

run: main
	./main

test: Spell.h Spell.cpp Wizard.h Wizard.cpp Hobbit.h Hobbit.cpp main.cpp
	g++ -static -std=c++11 -g main.cpp Wizard.cpp Hobbit.cpp Spell.cpp -o test

debug: test
	gdb ./test

clean:
	rm -vf ./*.o ./main

rum:
	echo -e "\x1b[35mDon't drink and code!\x1b[0m"
