cutgen: cutgen.c
	gcc -D__LINUX__ cutgen.c -o cutgen


check: cutgen cutcheck.c
	gcc cutcheck.c cut-pass.o -o cutcheck
	./cutcheck

cutcheck.c: cut-pass.o
	./cutgen cut-*.c -o cutcheck.c

cut-pass.o: cut-pass.c
	gcc -c cut-pass.c

clean:
	rm -f *.o *~ cutcheck* cutgen

all: check