test : test.c
	g++ -g $^ -o $@ -lnsense -llua5.2
prepare : 
	sudo cp ../nsense.so /usr/lib/libnsense.so
clean:
	sudo rm test /usr/lib/libnsense.so
