#include <string>
#include <unordered_set>
#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H
using namespace std;

enum Visibility{PUBLIC_V, PRIVATE_V};

class Symbol{
public:
    string type;
    string id;
    int scope;
    Symbol(const char* id, int scope);
    bool operator ==(const Symbol& smb) const;
};

class HashFunc{
public:
    size_t operator()(const Symbol& t) const;
};


class Symbol_Table{
public:
    unordered_set<Symbol, HashFunc> symTable;
    Symbol_Table();
    void insert(Symbol& sym);
    void erase(Symbol& sym);
    bool exists(Symbol& sym);
    bool exists_in_scope(Symbol& sym);
    void erase_in_scope(int cscope);
    char* retrieveType(Symbol& sym);
};





class MemberSymbol: public Symbol{
public:
    string class_parent;
    Visibility vis;
    MemberSymbol(const char* id, int scope, int cclass);
    bool operator ==(const MemberSymbol& smb) const;
};

class HashFunc2{
public:
     size_t operator()(const MemberSymbol& t) const;
};

class member_table{
public:
     unordered_set<MemberSymbol, HashFunc2> memTable;
     void insert(MemberSymbol& sym);
     void erase(MemberSymbol& sym);
     unordered_set<MemberSymbol, HashFunc>::iterator exists(MemberSymbol& sym);
};

#endif // SYMBOL_TABLE_H
