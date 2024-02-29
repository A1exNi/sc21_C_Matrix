CC = gcc -Wall -Werror -Wextra -std=c11 -pedantic
GCOVFLAGS = -fprofile-arcs -ftest-coverage
SOURSES = s21_*.c
SOURSES_TEST = test_*.c
OBJECT = $(patsubst %*.c, %*.o,  ${SOURSES})
OS := $(shell uname -s)

ifeq ($(OS), Linux)
 CC += -D OS_LINUX
 TEST_FLAGS =-lpthread -lcheck -pthread -lrt -lsubunit -lm
endif
ifeq ($(OS), Darwin)
 CC += -D OS_MAC
 TEST_FLAGS =-lcheck
endif

all: clean s21_matrix.a

s21_matrix.a: $(SOURSES)
	$(CC) -c $(SOURSES)
	@ar rcs s21_matrix.a $(OBJECT)

test: rebuild $(SOURSES_TEST)
	$(CC) $(SOURSES_TEST) s21_matrix.a $(TEST_FLAGS) -o test

gcov_report: rebuild
	@gcc $(GCOVFLAGS) $(SOURSES_TEST) $(SOURSES) $(TEST_FLAGS) -o GcovReport
	@./GcovReport
	@lcov -t "GcovReport" -o GcovReport.info -c -d .
	@genhtml -o report GcovReport.info
	@open ./report/index-sort-f.html
	@rm -rf ./*.gcno ./*.gcda ./GcovReport.*

clean:
	@rm -rf ./*.o ./*.a ./a.out ./GcovReport ./*.gcno ./*.gcda ./report ./*.info ./matrix_o ./*.dSYM ./unit-test ./CPPLINT* ./test

valgrind_test:
	CK_FORK=no valgrind --tool=memcheck --leak-check=yes ./test

leaks_test:
	CK_FORK=no leaks -atExit -- ./test

clang_test:
	clang-format -n *.c *.h

rebuild: all
