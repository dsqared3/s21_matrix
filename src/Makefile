CC = gcc
#CFLAGS = -Wall -Wextra -Werror -std=c11 -fsanitize=address -g -fprofile-arcs -ftest-coverage
CFLAGS = -Wall -Wextra -Werror -std=c11
# CFLAGS = -g
CFLAGSGCOV = -fprofile-arcs -ftest-coverage
CFLAGSSANITIZE = -fsanitize=address

LIB = s21_matrix.a
LIB_CFLAGS = -lcheck -lm

ifeq ($(shell uname -s), Darwin)
    # macOS
	LIB = s21_matrix
else ifeq ($(shell cat /etc/os-release | grep "^NAME=" | cut -d= -f2), "Ubuntu")
    # Ubuntu
    LIB_CFLAGS = -lcheck -lsubunit -lm
endif

BASE_FUNC_PATH = .

LIB_SRC = $(wildcard $(BASE_FUNC_PATH)/*.c) 
LIB_OBJ = $(LIB_SRC:.c=.o)

TEST_PATH = unit_test
TEST_SRC = $(wildcard $(TEST_PATH)/*.c)
TEST_OBJ = $(TEST_SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: test

rebuild: clean all

rebuild: clean sanitize

#  s21_matrix.a----------------------------------------------------------------------------------------

s21_matrix.a: clean $(LIB_OBJ)
ifeq ($(shell uname -s), Darwin)
    # macOS
	ar rcs lib$(LIB).a $(LIB_OBJ)
else
	ar rcs $(LIB) $(LIB_OBJ)
endif
	rm -f *.o

#  ----------------------------------------------------------------------------------------------------

clean: clangi
	find . -type f -name "*.o" -o -name "*.a" -o -name "*.gcda" -o -name "*.gcno" -o -name "*.bak" | xargs rm -f
	rm -f $(TEST_PATH)/$(TEST_PATH) a.out debug style-test.log empty tmp make_log log
	rm -rf gcov_report/
	rm -f $(LIB) *.info *.log *.txt

#  TEST------------------------------------------------------------------------------------------------

test: clean s21_matrix.a $(TEST_OBJ)
ifeq ($(shell uname -s), Darwin)
    # macOS
	$(CC) $(CFLAGS) $(TEST_OBJ) -L. -l$(LIB) $(LIB_CFLAGS) -o $(TEST_PATH)/$(TEST_PATH)
else
	$(CC) $(CFLAGS) $(TEST_OBJ) -L. -l:$(LIB) $(LIB_CFLAGS) -o $(TEST_PATH)/$(TEST_PATH)
endif
	./unit_test/unit_test 2>&1 | tee test.log

#  GCOV------------------------------------------------------------------------------------------------

insert_flags_gcov:
	$(eval CFLAGS += $(CFLAGSGCOV))

gcov_report: clean insert_flags_gcov test
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory gcov_report | tee gcov.log 

#  ----------------------------------------------------------------------------------------------------

clangn:
	find . -type f -name "*.c" -o -name "*.h" | xargs clang-format -n

clangi:
	find . -type f -name "*.c" -o -name "*.h" | xargs clang-format -i

.ONESHELL:
valgrind:
	valgrind --tool=memcheck --leak-check=yes -s ./unit_test/unit_test 2>&1 | tee valgrind.log

insert_flags_sanitize:
	$(eval CFLAGS += $(CFLAGSSANITIZE))

.ONESHELL:
sanitize: clean insert_flags_sanitize test

#  debug ------------------------------------------------------------------------------------------------

debug:
	gcc -g *.c
	./a.out


