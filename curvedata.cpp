#include "curvedata.h"

CurveData::CurveData(const QColor& _color, FunctionPtr _function,
                     int _id, const std::string& _name) {
    color = _color;
    function = _function;
    id = _id;
    name = _name;
}

void CurveData::generate_X(double begin, double end, double step) {
    int sample_size = abs(end - begin) / step;

    X.reserve(sample_size);

    for (int i = 0; i < sample_size; ++i) {
        X.push_back(i * step);
    }
}

void CurveData::generate_Y(const vector<double>& _X, FunctionPtr _function) {
    Y.reserve(_X.size());

    for (const auto& x : _X) {
        Y.push_back(_function(x));
    }
}

const vector<double>& CurveData::get_X() const {
    return X;
}

const vector<double>& CurveData::get_Y() const {
    return Y;
}

const QColor& CurveData::get_color() const {
    return color;
}

FunctionPtr CurveData::get_function() const {
    return function;
}

int CurveData::get_id() const {
    return id;
}

const string& CurveData::get_name() const {
    return name;
}
