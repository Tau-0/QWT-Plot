#ifndef FUNCTIONWITHINTERVALSDATA_H
#define FUNCTIONWITHINTERVALSDATA_H

#include "functiondata.h"

class FunctionWithIntervalsData : public FunctionData {
 public:
    FunctionWithIntervalsData(double begin, double end, double step, FunctionPtr function,
                              const std::string& name, const QColor& color);
    void create_interval_data(double begin, double end);
    const CurveData& get_interval_data(size_t i) const;
    size_t get_intervals_data_size() const;
    int get_intervals_opacity() const;
 private:
    vector<CurveData> intervals_data_;
    static constexpr const int k_intervals_opacity_ = 50;
};

#endif // FUNCTIONWITHINTERVALSDATA_H
