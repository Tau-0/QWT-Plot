// For tests.

#ifndef FUNCTIONTABLE_H
#define FUNCTIONTABLE_H

#include <cmath>
#include <string>

using std::string;

typedef double (*funcptr_t)(double);

struct FT;

funcptr_t search_function(const string& name);

#endif // FUNCTIONTABLE_H
