CC = gcc
FLAGS = -Wall -Werror -Wextra -std=c++17
GCOV = --coverage
UNIT = unit_tests
STLIB = s21_viewer.a
OS = $(shell uname -s)
FOLDERS = controller/*.h model/*.cc tests/*.cc view/*.cc

ifeq ($(OS), Darwin)
    LIBS := -lcheck 
	APPLICATION = 3dviewer.app 
	OPEN = open $(APPLICATION)
else
    LIBS := -lstdc++ -lcheck_pic -lrt -lpthread -lsubunit -lm -g
	APPLICATION = 3dviewer
	OPEN = ./$(APPLICATION)
endif

all: clean s21_viewer.a test

install:
	make clean
	mkdir 3dviewer
	cd src && qmake && make && make clean && rm Makefile && cd ../ && mv src/$(APPLICATION) ./3dviewer

uninstall:
	rm -rf 3dviewer

clean:
	rm -rf *.o *.a *.gc* *.info test report *dSYM $(UNIT) Archive_3dviewer1.0 *tgz 3dviewer

dvi:
	open dvi.html

dist:
	rm -rf Archive_3dviewer1.0/
	mkdir -p Archive_3dviewer1.0/
	mv ./3dviewer/$(APPLICATION) Archive_3dviewer1.0/src/
	tar cvzf Archive_3dviewer1.0.tgz Archive_3dviewer1.0/
	rm -rf Archive_3dviewer1.0/

tests: $(STLIB)
	$(CC) $(FLAGS) tests/3DViewer_test.cc $(STLIB) -o $(UNIT) $(LIBS)
	./$(UNIT)

s21_viewer.a: build_s21_viewer

build_s21_viewer:
	$(CC) -c model/s21_viewer.cc model/s21_aff_transform.cc
	ar rcs $(STLIB) s21_*.o s21_aff*.o
	ranlib $(STLIB)

gcov_report: $(STLIB) unit_tests.o
	$(CC) $(FLAGS) $(GCOV) 3DViewer_test.o model/s21_viewer.cc model/s21_aff_transform.cc -o $(UNIT) $(LIBS)
	./$(UNIT)
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	open report/index.html

unit_tests.o:
	$(CC) $(FLAGS) -c tests/3DViewer_test.c

clang:
	clang-format -style=file:../materials/linters/.clang-format -n ./*.cc $(FOLDERS)
	clang-format -style=file:../materials/linters/.clang-format -i ./*.cc $(FOLDERS)

open:
	cd 3dviewer && $(OPEN)

coverage:
	open report/index.html
