#ifndef FUNCTIONTABLE_H
#define FUNCTIONTABLE_H

#include <cmath>
#include <map>
#include <string>

using std::map;
using std::string;

using FunctionSignature = double(double);
using FunctionPtr = FunctionSignature*;
using FunctionName = string;

class FunctionTable {
private:
    map<FunctionName, FunctionPtr> function_map;

public:
    FunctionTable();

    FunctionPtr operator[](const FunctionName& name);
    FunctionPtr operator[](FunctionName&& name);
};


#endif // FUNCTIONTABLE_H
