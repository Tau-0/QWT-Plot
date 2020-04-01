#include "functiondata.h"

FunctionData::FunctionData(double begin, double end, double step, FunctionPtr function,
                           const std::string& name, const QColor& color) {
    color_ = color;
    function_ = function;
    name_ = name;
    opacity_ = 50;
    main_curve_.generate(begin, end, step, function);
}

void FunctionData::create_interval(double begin, double end) {
    CurveData interval_curve;

    for (auto it = main_curve_.get_X().begin(), jt = main_curve_.get_Y().begin();
         it < main_curve_.get_X().end() && jt < main_curve_.get_Y().end(); ++it, ++jt) {
        if (*it < begin) {
            continue;
        } else if (*it > end) {
            break;
        }

        interval_curve.add_point(*it, *jt);
    }

    intervals_.push_back(std::move(interval_curve));
}

const QColor& FunctionData::get_color() const {
    return color_;
}

FunctionPtr FunctionData::get_function() const {
    return function_;
}

const CurveData& FunctionData::get_interval(int i) const {
    return intervals_[i];
}

const CurveData& FunctionData::get_main_curve() const {
    return main_curve_;
}

const string& FunctionData::get_name() const {
    return name_;
}

int FunctionData::get_opacity() const {
    return opacity_;
}

int FunctionData::get_size() const {
    return intervals_.size();
}
