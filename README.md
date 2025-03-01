this is a simple parser for a java-like mini-programming language
i used flex and bison tools and a c++ implemented symbol-table (using an unordered set)
No_Error_Recovery folder contains the version of the parser that stops to the first error (syntax or semantic)
Error_recovery folder contains the version of the parser that displays all syntax errors and the parsing stops to the first semantic error.
