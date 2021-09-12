CC=clang
EXEC=cpucfg
all:main.o
  $(CC) main.o -o $(EXEC)
main.o:src/main.c
  $(CC) -c src/main.c
