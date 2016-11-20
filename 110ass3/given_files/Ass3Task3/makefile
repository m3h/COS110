main: linkedList.h doubleList.h dListTest.o
	g++ -static dListTest.o  -o main

dListTest.o: dListTest.cpp
	g++ -c dListTest.cpp

clean:
	rm *.o main

run: main
	./main

main2: linkedList.h main.o
	g++ -static main.o -o main2

main.o: main.cpp
	g++ -c main.cpp

run2: main2
	./main2


