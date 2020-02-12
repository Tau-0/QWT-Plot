#ifndef DATA_H
#define DATA_H

#include <memory>
#include <vector>

#include <curvewrapper.h>

using std::unique_ptr;
using std::vector;

class Data {
private:
    vector<unique_ptr<CurveWrapper>> curves;

public:
    Data();
};

#endif // DATA_H
