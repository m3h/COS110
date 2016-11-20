rain.out: arrayUtilities.o  rainfall.cpp
	g++ -g -std=c++11 arrayUtilities.o  rainfall.cpp -o rain.out


arrayUtilities.o: arrayUtilities.cpp arrayUtilities.cpp
	g++ -g -std=c++11 -c arrayUtilities.cpp

run: rain.out
	./rain.out

debug: rain.out
	gdb ./rain.out
