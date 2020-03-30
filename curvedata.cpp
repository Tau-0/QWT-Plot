#include "curvedata.h"

void CurveData::generate_X(double begin, double end, double step) {
    size_t sample_size = static_cast<size_t>(abs(end - begin) / step);
    X.reserve(sample_size);

    for (size_t i = 0; i < sample_size; ++i) {
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
