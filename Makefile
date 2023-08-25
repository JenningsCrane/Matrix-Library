CC = gcc -g -Wall -Werror -Wextra -pedantic -std=c11
GCOVFLAGS = -fprofile-arcs -ftest-coverage

OS = $(shell uname)
ifeq ($(OS), Linux)
 CHECK_FLAGS = -lcheck -pthread -lrt -lm -lsubunit
else
 CHECK_FLAGS = -lcheck -lm -lpthread -fprofile-arcs -ftest-coverage 
endif

all: matrix.a 

matrix.a:
	$(CC) -c matrix.c *.h
	ar rcs libmatrix.a *.o
	rm -rf *.o
	cp libmatrix.a matrix.a

test: matrix.a
	$(CC) matrix.a tests/tests.c $(CHECK_FLAGS) -o test -L. -lmatrix
	./test

clang:
	clang-format -style=Google -n *.c *.h tests/tests.c


gcov_report: matrix.a
	$(CC) $(GCOVFLAGS) tests/tests.c matrix.c $(CHECK_FLAGS) -o test -L. -lmatrix
	./test
	gcov tests/tests.c
	lcov -t "test" -o test.info -c -d .
	genhtml -o report/ test.info
	rm -rf *.o *.gcno *.gcda 
	open ./report/index.html

leaks: test
	CK_FORK=no leaks --atExit -- ./test

valgrind: test
	CK_FORK=no valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./test

clean:
	rm -rf *.o *.gcno *.gcda *.a *.info report test *.out
	rm -rf out *.gch *.gcov *.dSYM
