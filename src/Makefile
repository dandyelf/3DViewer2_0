CC = gcc
CXXFLAGS = -std=c++17 -Wall -Werror -Wextra
GCOV = --coverage
UNIT = model_tests.out
STLIB = s21_viewer.a
OS = $(shell uname -s)
GT_FLAGS = -lgtest_main -lgtest -lm -lstdc++ -pthread -lm -g
BUILD_DIR = 3dviewer
FOLDERS = controller/*.h model/*.cc tests/*.cc view/*.cc

ifeq ($(OS), Darwin)
    LIBS := -lcheck 
	APPLICATION = 3dviewer.app 
	OPEN = open $(APPLICATION)
else
    LIBS := -lgtest -lstdc++ -lcheck_pic -lrt -lpthread -lsubunit -lm -g
	APPLICATION = 3dviewer
	OPEN = ./$(APPLICATION)
endif

all: clean s21_viewer.a tests

install: clean
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && qmake CONFIG+=qtquickcompiler ../view/3dviewer.pro && make
	make open

uninstall:
	rm -rf 3dviewer

clean:
	rm -rf *.o *.a *.gc* *.info build report *dSYM $(UNIT) Archive_3dviewer1.0 *tgz gcov_test

dvi:
	open dvi.html

dist:
	rm -rf Archive_3dviewer1.0/
	mkdir -p Archive_3dviewer1.0/
	mv ./3dviewer/$(APPLICATION) Archive_3dviewer1.0/src/
	tar cvzf Archive_3dviewer1.0.tgz Archive_3dviewer1.0/
	rm -rf Archive_3dviewer1.0/

tests: $(STLIB)
	mkdir -p $(BUILD_DIR)
	$(CC) $(CXXFLAGS) tests/s21_3d_viewer_tests.cc $(STLIB) -o $(BUILD_DIR)/$(UNIT) $(LIBS)
	./$(BUILD_DIR)/$(UNIT)

valgrind: tests
	CK_FORK=no valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(UNIT)

s21_viewer.a: build_s21_viewer

build_s21_viewer:
	$(CC) -c model/s21_parser_obj.cc model/s21_aff_transform.cc
	ar rcs $(STLIB) s21_*.o s21_aff*.o
	ranlib $(STLIB)

unit_tests.o:
	$(CC) $(CXXFLAGS) -c tests/s21_3d_viewer_tests.cc

clang:
	clang-format -style=file:../materials/linters/.clang-format -n ./*.cc $(FOLDERS)
	clang-format -style=file:../materials/linters/.clang-format -i ./*.cc $(FOLDERS)

open:
	cd $(BUILD_DIR) && $(OPEN)

coverage:
	open report/index.html

model_tests:
	mkdir -p $(BUILD_DIR)
	$(CC) $(CXXFLAGS) $(GT_FLAGS) model/*.cc tests/*.cc -o $(BUILD_DIR)/model_tests.out
	./$(BUILD_DIR)/model_tests.out

model_valgrind: model_tests
	CK_FORK=no valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(BUILD_DIR)/model_tests.out

val:
	CK_FORK=no valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(BUILD_DIR)/$(APPLICATION)

gcov_report: $(STLIB) model_tests
	$(CC) $(CXXFLAGS) $(GCOV) -lgtest_main model/*.cc tests/*.cc -o $(UNIT) $(LIBS)
	./$(UNIT)
	gcov model/*.cc tests/*.cc
	lcov -t "tests" -o tests.info -c -d .
	lcov --remove tests.info '/usr/*' --output-file tests_filtered.info
	lcov --remove tests_filtered.info 'tests/*' --output-file tests_final.info 
	genhtml -o report tests_final.info
	open report/index.html


skull:
	mkdir -p $(BUILD_DIR)
	$(CC) -std=c++17 -lstdc++ -Wall -Wextra $(GT_FLAGS) model/*.cc tests/s21_skull_tests.cc -o $(BUILD_DIR)/model_tests.out
	./$(BUILD_DIR)/model_tests.out
	CK_FORK=no valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(BUILD_DIR)/model_tests.out