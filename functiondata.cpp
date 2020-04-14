#include "functiondata.h"

FunctionData::FunctionData(double begin, double end, double step,
                           FunctionPtr function, const std::string& name, const QColor& color) :
    color_(color), function_(function), name_(name) {
    curve_data_.generate(begin, end, step, function);
}

const QColor& FunctionData::get_color() const {
    return color_;
}

const CurveData& FunctionData::get_curve_data() const {
    return curve_data_;
}

FunctionPtr FunctionData::get_function() const {
    return function_;
}

const string& FunctionData::get_name() const {
    return name_;
}

