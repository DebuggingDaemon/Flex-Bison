# Syntax, Lexical & Semantic Analyzer

This repository contains a **Syntax, Lexical, and Semantic Analyzer** implemented in **C++** for a **Java-like mini-language**. The project simulates the front-end of a compiler, processing source code written in a simplified language inspired by Java.

## 📂 Project Structure

This project analyzes code written in a simplified Java-like language. Example features include:

- **Basic variable declarations (`int`, `float`, `string`)**
- **Control structures (`if`, `do-while`, `for`)**
- **Functions with parameters and return types**
- **Simple expressions whith operators**

---

## 🚀 Features

✅ Lexical Analysis - Tokenizes the source code into meaningful units.  
✅ Syntax Analysis - Parses tokens according to the grammar rules (CFG).  
✅ Semantic Analysis - Checks type consistency, undeclared variables, and scoping.  
✅ Error Reporting - Provides user-friendly feedback on syntax and semantic errors.

---

## ⚙️ Technologies
- Tools Used: **Flex, Bison**
- Implementation Language: **C++** (primarily used for the implementation of the symbol-table)
- Tools for the Symbol-Table: Standard Library (`<unordered_set>`)

  ## 💻 Setup & Usage
  1) clone the repository
      - The folder 'No_Error_Recovery' has the version of the parser that stops parsing in the first error (syntax or semantic)
      - The folder 'Error recovery' has the version of the parser that stops parsing in the first semantic error (reporting all syntax errors until this point)
  2) In each of the parser versions run make and then ./comp ''file to analyze'' (replace ''file to analyze'' with your file, you will find some exmaple files in the folders of the repository)    
