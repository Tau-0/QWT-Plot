#include "functiondata.h"

FunctionData::FunctionData(const QColor& _color, FunctionPtr _function,
                           int _id, const std::string& _name) {
    color = _color;
    function = _function;
    id = _id;
    name = _name;
}

void FunctionData::create_interval(double begin, double end) {
    CurveData interval_curve;

    for (auto it = main_curve.X.begin(), jt = main_curve.Y.begin();
         it < main_curve.X.end() && jt < main_curve.Y.end(); ++it, ++jt) {
        if (*it < begin) {
            continue;
        } else if (*it > end) {
            break;
        }

        interval_curve.X.push_back(*it);
        interval_curve.Y.push_back(*jt);
    }

    intervals.push_back(std::move(interval_curve));
}

int FunctionData::get_alpha() const {
    return alpha;
}

const QColor& FunctionData::get_color() const {
    return color;
}

FunctionPtr FunctionData::get_function() const {
    return function;
}

int FunctionData::get_id() const {
    return id;
}

const CurveData& FunctionData::get_interval(int i) const {
    return intervals[i];
}

const CurveData& FunctionData::get_main_curve() const {
    return main_curve;
}

const string& FunctionData::get_name() const {
    return name;
}

int FunctionData::get_size() const {
    return intervals.size();
}
