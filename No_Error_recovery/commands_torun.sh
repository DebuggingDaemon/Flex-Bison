#!/bin/bash

bison -d -t parser1.y -o parser1.tab.cpp
flex -o lex.yy.cc lexer.l
g++ -o comp parser1.tab.cpp lex.yy.cc symbol_table.cpp
