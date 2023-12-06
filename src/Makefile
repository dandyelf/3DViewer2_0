CC = gcc
CXXFLAGS = -std=c++17 -lstdc++ -Wall -Werror -Wextra
GCOV = --coverage
UNIT = unit_tests
STLIB = s21_viewer.a
OS = $(shell uname -s)
GT_FLAGS = -lgtest_main -lgtest -lm -lstdc++ -pthread -lm -g

#  Project files and directories
BUILD_DIR = build
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
	rm -rf *.o *.a *.gc* *.info build report *dSYM $(UNIT) Archive_3dviewer1.0 *tgz 3dviewer

dvi:
	open dvi.html

dist:
	rm -rf Archive_3dviewer1.0/
	mkdir -p Archive_3dviewer1.0/
	mv ./3dviewer/$(APPLICATION) Archive_3dviewer1.0/src/
	tar cvzf Archive_3dviewer1.0.tgz Archive_3dviewer1.0/
	rm -rf Archive_3dviewer1.0/

tests: $(STLIB)
	$(CC) $(CXXFLAGS) tests/3DViewer_test.cc $(STLIB) -o $(UNIT) $(LIBS)
	./$(UNIT)

valgrind: tests
	CK_FORK=no valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(UNIT)

s21_viewer.a: build_s21_viewer

build_s21_viewer:
	$(CC) -c model/s21_parser_obj.cc model/s21_aff_transform.cc
	ar rcs $(STLIB) s21_*.o s21_aff*.o
	ranlib $(STLIB)

gcov_report: $(STLIB) unit_tests.o
	$(CC) $(CXXFLAGS) $(GCOV) 3DViewer_test.o model/s21_parser_obj.cc model/s21_aff_transform.cc -o $(UNIT) $(LIBS)
	./$(UNIT)
	lcov -t "tests" -o tests.info -c -d .
	genhtml -o report tests.info
	open report/index.html

unit_tests.o:
	$(CC) $(CXXFLAGS) -c tests/3DViewer_test.c

clang:
	clang-format -style=file:../materials/linters/.clang-format -n ./*.cc $(FOLDERS)
	clang-format -style=file:../materials/linters/.clang-format -i ./*.cc $(FOLDERS)

open:
	cd $(BUILD_DIR) && $(OPEN)

coverage:
	open report/index.html

model_tests:
	mkdir -p $(BUILD_DIR)
	$(CC) -std=c++17 -lstdc++ -Wall -Wextra $(GT_FLAGS) model/*.cc tests/s21_model_tests.cc tests/s21_controller_tests.cc -o $(BUILD_DIR)/model_tests.out
	./$(BUILD_DIR)/model_tests.out

model_valgrind: tests
	CK_FORK=no valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(BUILD_DIR)/model_tests.out