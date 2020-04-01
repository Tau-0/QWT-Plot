#ifndef DATA_H
#define DATA_H

#include <vector>

#include "functiondata.h"
#include "functiontable.h"

using std::vector;

class Data {
 public:
    Data();
    const FunctionData& get_curve(int i) const;
 private:
    vector<FunctionData> curves;
    FunctionTable functions;
};

#endif // DATA_H
