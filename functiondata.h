#ifndef FUNCTIONDATA_H
#define FUNCTIONDATA_H

#include <memory>

#include "curvedata.h"

class FunctionData {
 public:
    FunctionData(double begin, double end, double step, FunctionPtr function,
                 const std::string& name, const QColor& color);
    void create_interval(double begin, double end);

    const QColor& get_color() const;
    FunctionPtr get_function() const;
    const CurveData& get_interval(int i) const;
    int get_interval_opacity() const;
    const CurveData& get_main_curve() const;
    const string& get_name() const;
    int get_size() const;
 private:
    CurveData main_curve_;
    vector<CurveData> intervals_;

    QColor color_;
    int interval_opacity_;

    FunctionPtr function_;
    string name_;
};

#endif // FUNCTIONDATA_H
