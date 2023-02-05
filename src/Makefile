# Common
SYS = $(shell uname)
CC = gcc
DEBUG_FLAGS =#-g -fsanitize=adress # dont work with gcov and verter faild with him
FLAGS = -c -Wall -Wextra -Werror $(DEBUG_FLAGS) -std=c11
LEAKS = nothing

# Library
LIB_SRC = lib/
SRCS =  $(LIB_SRC)$(wildcard s21_*.c)
OBJ_LIB_NAME = lib_obj
OBJS = $(addprefix $(OBJ_LIB_NAME)/, $(SRCS:.c=.o))

LIB_NAME = s21_string.a
LIB_FLAGS = -lcheck -lm -lpthread

# Testing
OBJ_TEST_NAME = test/test_obj
TEST_SRC = test_s21_string.c
TEST_OBJ = $(addprefix $(OBJ_TEST_NAME)/, $(TEST_SRC:.c=.o))


TEST_FLAGS_GCOV = --coverage
REPORT_NAME = gcov_result
GCOV_INFO = gcov_result.info

ifeq ($(SYS), Darwin) # Проверяем ОС
	LIB_FLAGS = -lcheck
	LEAKS = leaks --atExit -- test
else
	LIB_FLAGS = -lcheck -lsubunit -pthread -lrt -lm
	LEAKS = CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./test
endif

all: clean s21_string.a test gcov_report

s21_string.a: clean
	mkdir -p $(OBJ_LIB_NAME)
	$(CC) $(FLAGS) $(SRCS) -o $(OBJS)
	ar rc $(LIB_NAME) $(OBJS)
	ranlib $(LIB_NAME)

clean:
	rm -rf lib_obj ./*.o ./*.a ./a.out gcov_test *.html *.css ./GcovReport ./*.gcno ./*.gcda ./*.info ./math_o ./*.dSYM ./CPPLINT* test

test: s21_string.a
	$(CC) $(FLAGS) $(TEST_FLAGS_GCOV) $(TEST_SRC) $(SRCS) $(LIB_NAME) $(LIB_FLAGS) -o gcov_test $(shell pkg-config --libs --cflags check)
	chmod +x *
	./gcov_test

gcov_report: s21_string.a
	lcov -t "gcov_test" -o gcov_test.info --no-external -c -d . # -t отвечает за имя теста https://stackoverflow.com/questions/837639/is-there-a-way-to-focus-lcov-code-coverage-reports-to-just-one-or-two-directorie
	genhtml -o report/ gcov_test.info # генерирует html страницу
	open ./report/index.html

check: test
	cppcheck --enable=all --suppress=missingIncludeSystem --inconclusive --check-config *.c *.h
	cp ../materials/linters/CPPLINT.cfg .
	python3 ../materials/linters/cpplint.py --extension=c *.c *.h *.c
	rm -rf CPPLINT.cfg
	cp ../materials/linters/.clang-format .
	clang-format -style=google -i *.c *.h
	clang-format -style=google -n *.c *.h
	rm -rf .clang-format
	make test
