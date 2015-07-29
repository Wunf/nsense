TESTMODS = nsscene.o nsrec.o test.o

test : $(TESTMODS)
	g++ -o $@ $^

test.o : src/test.c
	g++ -g -c $^
nsrec.o : src/nsrec.cpp
	g++ -g -c $^
nsscene.o : src/nsscene.cpp
	g++ -g -c $^
clean:
	rm *.o test
