BB = bison
FL = flex
CC = g++

all: comp

parser1.tab.cpp: parser1.y
	$(BB) -d -t parser1.y -o parser1.tab.cpp

lex.yy.cc: lexer.l
	$(FL) -o lex.yy.cc lexer.l

comp: parser1.tab.cpp lex.yy.cc symbol_table.cpp
	$(CC) -o comp parser1.tab.cpp lex.yy.cc symbol_table.cpp
clean:
	rm -f comp
