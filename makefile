CC=clang++
CFLAGS= -g -Wall
EXEC=cpucfg

$(EXEC):main.o
	$(CC) obj/main.o $(CFLAGS) -o $(EXEC) 
main.o:src/main.cpp
	$(CC) -c src/main.cpp -o obj/main.o
clean:
	rm obj/*.o
