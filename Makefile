NSMODS = nsscene.o nscomponent.o nsrec.o nsense.o nscwapper.o
COMPILER = g++

nsense.so : $(NSMODS)
	$(COMPILER) -g --shared -fPIC $^ -o $@ -llua5.1

nsrec.o : src/nsrec.cpp
	$(COMPILER) -g -c -fPIC $^
nscomponent.o : src/nscomponent.cpp
	$(COMPILER) -g -c -fPIC $^
nsscene.o : src/nsscene.cpp
	$(COMPILER) -g -c -fPIC $^
nscwapper.o : src/nscwapper.cpp
	$(COMPILER) -g -c -fPIC $^
nsense.o : src/nsense.c
	$(COMPILER) -g -c -fPIC $^
clean:
	rm *.o test nsense.so
