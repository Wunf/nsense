test : nsscene.o nsrec.o test.o
	g++ -o test nsscene.o nsrec.o test.o
test.o : src/test.c
	g++ -g -c src/test.c
nsrec.o : src/nsrec.cpp src/nsrec.h
	g++ -g -c src/nsrec.cpp
nsscene.o : src/nsscene.cpp src/nsscene.h
	g++ -g -c src/nsscene.cpp
clean:
	rm *.o test
