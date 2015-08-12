NSMODS = nsscene.o nscomponent.o nsrec.o nsense.o nscwapper.o nsglobal.o
COMPILER = g++

nsense.so : $(NSMODS)
	$(COMPILER) -g --shared -fPIC $^ -o $@ -llua5.2

nsrec.o : src/nsrec.cpp
	$(COMPILER) -g -c -fPIC $^
nscomponent.o : src/nscomponent.cpp
	$(COMPILER) -g -c -fPIC $^
nsscene.o : src/nsscene.cpp
	$(COMPILER) -g -c -fPIC $^
nscwapper.o : src/nscwapper.cpp
	$(COMPILER) -g -c -fPIC $^
nsglobal.o : src/nsglobal.cpp
	$(COMPILER) -g -c -fPIC $^
nsense.o : src/nsense.c
	$(COMPILER) -g -c -fPIC $^
install :
	sudo cp nsense.so /usr/lib/libnsense.so
clean:
	rm *.o test nsense.so
