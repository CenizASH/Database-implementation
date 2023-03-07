out: main.o table.o
	clang table.o main.o -o out

main.o: main.c
	clang -c main.c

table.o: table.c table.h
	clang -c table.c

clean:
	rm *.o out