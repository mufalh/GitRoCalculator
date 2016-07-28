cutgen: cutgen.c
	gcc -D__LINUX__ cutgen.c -o cutgen

check: cutgen cutcheck.c cut-pass.o
	gcc cutcheck.c cut-pass.o -o cutcheck
	./cutcheck

cutcheck.c: cutgen cut-pass.o
	./cutgen cut-pass.c -o cutcheck.c

cut-pass.o: cut-pass.c
	gcc -c cut-pass.c

clean:
	rm -f *.o *~ cutcheck* cutgen

all: check
