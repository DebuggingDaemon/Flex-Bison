#include "symbol_table.h"
#include <cstdio>
#include <iostream>
#define M 0x9E3

Symbol::Symbol(const char* id, int scope){
    this->id=string(id);
    this->scope=scope;
}

bool Symbol::operator ==(const Symbol& smb) const{
	if(smb.id.compare(this->id)==0)
		return (this->scope==smb.scope);
	else
		return false;
}

size_t HashFunc::operator()(const Symbol& t) const{
    size_t sum=0;
    for(size_t j=0; j<t.id.length(); j++){
        sum+=t.id[j];
	}
	size_t x=t.scope*M;
    x+=sum;
	return x|M;
}

Symbol_Table::Symbol_Table(){

}

void Symbol_Table::insert(Symbol &sym){
    this->symTable.insert(sym);
}

void Symbol_Table::erase(Symbol &sym){
    this->symTable.erase(sym);
}

bool Symbol_Table::exists(Symbol &sym){
    for(int i=sym.scope; i>=0; i--){
        Symbol cs(sym.id.c_str(), i);
        if(this->symTable.count(cs)>0)
            return true;
    }
    return false;
}

bool Symbol_Table::exists_in_scope(Symbol& sym){
	return this->symTable.count(sym)>0;
}

void Symbol_Table::erase_in_scope(int cscope){
	auto it=this->symTable.begin();
	while(it!=this->symTable.end()){
		auto current=it;
		it++;
		if((*current).scope==cscope)
			symTable.erase(current);
	}
}

char* Symbol_Table::retrieveType(Symbol& sym){
	for(int i=sym.scope; i>=0; i--){
        Symbol cs(sym.id.c_str(), i);
		auto it=symTable.find(cs);
		if(it!=symTable.end()){
			char* ret;
			asprintf(&ret, "%s", (*it).type.c_str());
			return ret;
		}
    }
    return nullptr;
}

MemberSymbol::MemberSymbol(const char* id, int scope, int cclass): Symbol(id, scope){
	vis=PUBLIC_V;
	class_parent="NIL"+cclass;
}


bool MemberSymbol::operator ==(const MemberSymbol& smb) const{
    if(smb.id.compare(this->id)==0){
		return (this->class_parent.compare(smb.class_parent)==0);

    }
	else
		return false;
}

size_t HashFunc2::operator()(const MemberSymbol& t) const{
    size_t sum1=0;
    size_t sum2=0;
    for(size_t j=0; j<t.id.length(); j++){
        sum1+=t.id[j];
	}
	for(size_t j=0; j<t.class_parent.length(); j++){
		sum2+=t.class_parent[j];
	}
    size_t x=sum1+sum2;
	return x|M;
}


void member_table::insert(MemberSymbol& sym){
	memTable.insert(sym);
}

unordered_set<MemberSymbol, HashFunc>::iterator member_table::exists(MemberSymbol& sym){
	return memTable.find(sym);
}

void member_table::erase(MemberSymbol& sym){
	memTable.erase(sym);
}


