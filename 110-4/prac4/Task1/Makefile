main: main.cpp filter.h filter.cpp backwards.h backwards.cpp titleCase.h titleCase.cpp
	g++ -static -g main.cpp filter.cpp backwards.cpp titleCase.cpp -o main

run: main
	./main

clean:
	rm -vf ./*.o ./*.gch main
