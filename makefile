TESTMODS = nsscene.o nscomponent.o nsrec.o test.o

test : $(TESTMODS)
	g++ $^ -o $@ -llua

test.o : src/test.c
	g++ -g -c $^
nsrec.o : src/nsrec.cpp
	g++ -g -c $^
nscomponent.o : src/nscomponent.cpp
	g++ -g -c $^
nsscene.o : src/nsscene.cpp
	g++ -g -c $^
clean:
	rm *.o test
