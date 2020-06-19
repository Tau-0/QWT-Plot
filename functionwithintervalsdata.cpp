#include "functionwithintervalsdata.h"

FunctionWithIntervalsData::FunctionWithIntervalsData(double begin, double end, double step,
                           FunctionPtr function, const std::string& name, const QColor& color) :
    FunctionData(begin, end, step, function, name, color) {
}

void FunctionWithIntervalsData::create_interval_data(double begin, double end) {
    CurveData interval_data;

    for (auto it = curve_data_.get_X().begin(), jt = curve_data_.get_Y().begin();
              it < curve_data_.get_X().end() && jt < curve_data_.get_Y().end(); ++it, ++jt) {
        if (*it < begin) {
            continue;
        } else if (*it > end) {
            break;
        }

        interval_data.add_point(*it, *jt);
    }

    intervals_data_.push_back(std::move(interval_data));
}

const CurveData& FunctionWithIntervalsData::get_interval_data(size_t i) const {
    return intervals_data_[i];
}

size_t FunctionWithIntervalsData::get_intervals_data_size() const {
    return intervals_data_.size();
}

int FunctionWithIntervalsData::get_intervals_opacity() const {
    return k_intervals_opacity_;
}

