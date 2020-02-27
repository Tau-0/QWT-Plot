#ifndef DATA_H
#define DATA_H

#include <vector>

#include "curvedata.h"
#include "functiontable.h"

using std::vector;

class Data {
private:
    vector<CurveData> curves;
    FunctionTable functions;

public:
    Data();

    const CurveData& get_curve(int i) const;
};

#endif // DATA_H
