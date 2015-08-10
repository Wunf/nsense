test : test.c
	g++ -g -L.. $^ -o $@ -lnsense -llua
prepare : 
	sudo cp ../nsense.so /usr/lib/libnsense.so
clean:
	sudo rm test /usr/lib/libnsense.so
