#universalmakefile

5assignment.out: test_list.c list.c
	gcc -o 5assignment.out test_list.c list.c

test_list.o: list.c test_list.c	list.h
	gcc -c test_list.c

list.o: list.h
	gcc -c list.c

clean:
	rm -f *.o *.out
