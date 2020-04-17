#ifndef FUNCTIONTABLE_H
#define FUNCTIONTABLE_H

#include <cmath>
#include <map>
#include <string>

using FunctionSignature = double(double);
using FunctionPtr = FunctionSignature*;
using FunctionName = std::string;

class FunctionTable {
 public:
    FunctionTable();
    FunctionPtr operator[](const FunctionName& name);
    FunctionPtr operator[](FunctionName&& name);
 private:
    std::map<FunctionName, FunctionPtr> function_map_;
};

#endif // FUNCTIONTABLE_H
