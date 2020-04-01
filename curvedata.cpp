#include "curvedata.h"

void CurveData::add_point(double x, double y) {
    X_.push_back(x);
    Y_.push_back(y);
}

void CurveData::generate(double begin, double end, double step, FunctionPtr function) {
    generate_X(begin, end, step);
    generate_Y(function);
}

const vector<double>& CurveData::get_X() const {
    return X_;
}

const vector<double>& CurveData::get_Y() const {
    return Y_;
}

void CurveData::generate_X(double begin, double end, double step) {
    size_t sample_size = static_cast<size_t>(abs(end - begin) / step);
    X_.reserve(sample_size);

    for (size_t i = 0; i < sample_size; ++i) {
        X_.push_back(i * step);
    }
}

void CurveData::generate_Y(FunctionPtr function) {
    Y_.reserve(X_.size());

    for (const auto& x : X_) {
        Y_.push_back(function(x));
    }
}
