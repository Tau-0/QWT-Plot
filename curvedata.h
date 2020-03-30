#ifndef CURVEDATA_H
#define CURVEDATA_H

#include <QColor>

#include <string>
#include <tuple>
#include <vector>

#include "functiontable.h"

using std::make_tuple;
using std::string;
using std::tuple;
using std::vector;

class CurveData {
 private:
    friend class Data;
    friend class FunctionData;
    vector<double> X;
    vector<double> Y;
 public:
    CurveData() = default;
    void generate_X(double begin, double end, double step);
    void generate_Y(const vector<double>& _X, FunctionPtr _function);
    const vector<double>& get_X() const;
    const vector<double>& get_Y() const;
};

#endif // CURVEDATA_H
