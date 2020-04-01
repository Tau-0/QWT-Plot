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
 public:
    FunctionTable();
    FunctionPtr operator[](const FunctionName& name);
    FunctionPtr operator[](FunctionName&& name);
 private:
    map<FunctionName, FunctionPtr> function_map;
};

#endif // FUNCTIONTABLE_H
