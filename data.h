#ifndef DATA_H
#define DATA_H

#include <vector>

#include "functiondata.h"
#include "functiontable.h"

using std::vector;

class Data {
 private:
    vector<FunctionData> curves;
    FunctionTable functions;
 public:
    Data();
    const FunctionData& get_curve(int i) const;
};

#endif // DATA_H
