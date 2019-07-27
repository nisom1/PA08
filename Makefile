CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wunreachable-code -Wvla -Werror
COVFLAGS = -fprofile-arcs -ftest-coverage
GCC = gcc $(CFLAGS) $(COVFLAGS)
OBJS = pa08.o eval.o stack.o 
VALS = valgrind --tool=memcheck --leak-check=full

all: $(OBJS)
	$(GCC) $(OBJS) -o $@

pa08.0: pa08.c
	$(GCC) $(OBJS) -o $@

eval.o: eval.c eval.h
	$(GCC) -c $< -o $@

stack.o: stack.c stack.h
	$(GCC) -c $< -o $@

memory: pa08
	$(VALS) ./pa08 inputs/test1
	$(VALS) ./pa08 inputs/test2
	$(VALS) ./pa08 inputs/test3
	$(VALS) ./pa08 inputs/test4
	$(VALS) ./pa08 inputs/test5

clean:
	rm -f *.o
	rm -f pa07
	rm -f *.gcda *.gcno *.gcov gmon.out
