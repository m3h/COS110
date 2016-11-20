main: linkedList.h circularList.h circularList.cpp ccListTest.o
	g++ -static ccListTest.o -o main

ccListTest.o: ccListTest.cpp
	g++ -c ccListTest.cpp

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



