#ifndef FUNCTIONDATA_H
#define FUNCTIONDATA_H

#include <QColor>

#include "curvedata.h"

class FunctionData {
 public:
    FunctionData(double begin, double end, double step, FunctionPtr function,
                 const std::string& name, const QColor& color);
    const QColor& get_color() const;
    const CurveData& get_curve_data() const;
    FunctionPtr get_function() const;
    const std::string& get_name() const;
 protected:
    QColor color_;
    CurveData curve_data_;
    FunctionPtr function_;
    std::string name_;
};

#endif // FUNCTIONDATA_H
