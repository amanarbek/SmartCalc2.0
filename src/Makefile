#all, install, uninstall, clean, dvi, dist, tests, gcov_report
CC = g++
CC_FLAGS = -Wall -Wextra -Werror -std=c++17 #-pedantic-errors
TEST_FLAGS = -lgtest -lgtest_main -pthread
COVERAGE_FLAGS = -fprofile-arcs -ftest-coverage
SANITIZER_FLAGS = -fsanitize=address
PROJECT_NAME = SmartCalc_v_2_0
SRCS=$(wildcard my*.cc,*/my*.cc)
OBJ_FILES=$(patsubst %.cc,%.o,$(SRCS))
REPORT_DIR = report

all: install

install:
	cmake -S . -B build -G "Unix Makefiles"
	make -C build
	cd ./build && rm -rf CMakeFiles SmartCalc_v_2_0_autogen cmake_install.cmake CMakeCache.txt Makefile
	open build

uninstall:
	rm -rf build

clean:
	rm -rf *.o *.gcno *.gcda *.info *.a $(REPORT_DIR) test run *.dSYM SmartCalc.tar.gz CMakeLists.txt.user

dvi:
	open documentation.html

dist:
	tar -czf SmartCalc.tar.gz main.cc Makefile model view_controller documentation.html CMakeLists.txt
	open .

tests: 
	clear
	$(CC) $(CC_FLAGS) model/*.cc test.cc -o test $(TEST_FLAGS)
	./test

gcov_report:
	clear
	$(CC) $(CC_FLAGS) $(COVERAGE_FLAGS) $(SANITIZER_FLAGS) model/*.cc test.cc -o test $(TEST_FLAGS)
	./test
	lcov -t "$@" -o $@.info -c -d . --no-external --ignore-errors mismatch
	lcov -r $@.info "include" -o $@.info --ignore-errors unused
	genhtml -o ./$(REPORT_DIR) $@.info
	open ./report/index.html

%.o:%.cc
	$(CC) -c $(FLAGS) $< -o $@ -I .

valgrind: tests
	valgrind --leak-check=full \
        	 --show-leak-kinds=all \
         	 --track-origins=yes \
         	 --verbose \
			 ./test

.PHONY:
	all, clean, test, gcov_report, install, uninstall, dvi, dist

clang:
	clang-format -i --style=Google **/*.cc **/*.h 
	clang-format -n --style=Google **/*.cc **/*.h