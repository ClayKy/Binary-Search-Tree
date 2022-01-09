#
# Makefile for Binary Search Tree
#
# Homework 3 (fall 2021)
# Purpose: Make compiling/linking easier in hw3 COMP15 assignment
#

CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -std=c++11 


hw3: hw3.o BinarySearchTree.o
	${CXX} -o $@ $^
	
BST_tests: BST_tests.o BinarySearchTree.o
	${CXX} -o $@ $^

%.o: %.cpp $(shell echo *.h)
	${CXX} ${CXXFLAGS} -c $<

clean:
	rm -rf hw3 *.o *.dSYM

provide:
	provide comp15 hw3 hw3.cpp BinarySearchTree.cpp BinarySearchTree.h \
	        README Makefile BST_tests.cpp hw3.out hw3.gt
