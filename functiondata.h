#ifndef FUNCTIONDATA_H
#define FUNCTIONDATA_H

#include "curvedata.h"

class FunctionData {
 private:
    friend class Data;
    CurveData main_curve;
    vector<CurveData> intervals;

    int alpha = 50;
    QColor color;

    FunctionPtr function = nullptr;
    int id = -1;
    string name;
 public:
    FunctionData(const QColor& _color, FunctionPtr _function,
                 int _id, const std::string& _name);
    void create_interval(double begin, double end);

    int get_alpha() const;
    const QColor& get_color() const;
    FunctionPtr get_function() const;
    int get_id() const;
    const CurveData& get_interval(int i) const;
    const CurveData& get_main_curve() const;
    const string& get_name() const;
    int get_size() const;
};

#endif // FUNCTIONDATA_H
