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
 public:
    CurveData() = default;
    void add_point(double x, double y);
    void generate(double begin, double end, double step, FunctionPtr function);

    size_t data_size() const;
    const double* data_X() const;
    const double* data_Y() const;
    const vector<double>& get_X() const;
    const vector<double>& get_Y() const;
 private:
    void generate_X(double begin, double end, double step);
    void generate_Y(FunctionPtr function);

    vector<double> X_;
    vector<double> Y_;
};

#endif // CURVEDATA_H
