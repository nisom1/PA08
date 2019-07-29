CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wunreachable-code -Wvla -Werror
COVFLAGS = -fprofile-arcs -ftest-coverage
GCC = gcc $(CFLAGS) $(COVFLAGS)
OBJS = pa08.o eval.o pile.o 
VALS = valgrind --tool=memcheck --leak-check=full

all: pa08

pa08: pa08.o eval.o pile.o
	$(GCC) pa08.o eval.o pile.o -o pa08

pa08.o: pa08.c
	$(GCC) -c pa08.c -o $@

eval.o: eval.c eval.h
	$(GCC) -c $< -o $@

pile.o: pile.c pile.h
	$(GCC) -c $< -o $@

test: pa08
	./pa08 PA08_inputs/in0
	./pa08 PA08_inputs/in1
	./pa08 PA08_inputs/in2
	./pa08 PA08_inputs/in3
	./pa08 PA08_inputs/in4
	./pa08 PA08_inputs/in5
	./pa08 PA08_inputs/in6
	./pa08 PA08_inputs/in7
	./pa08 PA08_inputs/in8
	./pa08 PA08_inputs/in9
	./pa08 PA08_inputs/in10
	./pa08 PA08_inputs/in11
	./pa08 PA08_inputs/in12
	./pa08 PA08_inputs/in13
	./pa08 PA08_inputs/in14
	./pa08 PA08_inputs/in15
	./pa08 PA08_inputs/in16
	./pa08 PA08_inputs/in17
	./pa08 PA08_inputs/in18
	./pa08 PA08_inputs/test1
	./pa08 PA08_inputs/test2
	./pa08 PA08_inputs/test3
	./pa08 PA08_inputs/test4
	./pa08 PA08_inputs/test5

memory: pa08
	$(VALS) ./pa08 inputs/test1
	$(VALS) ./pa08 inputs/test2
	$(VALS) ./pa08 inputs/test3
	$(VALS) ./pa08 inputs/test4
	$(VALS) ./pa08 inputs/test5

clean:
	rm -f *.o
	rm -f pa08
	rm -f *.gcda *.gcno *.gcov gmon.out
