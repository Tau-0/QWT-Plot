#ifndef CURVEDATA_H
#define CURVEDATA_H

#include <QColor>

#include <string>
#include <vector>

#include <functiontable.h>

using std::string;
using std::vector;

class CurveData {
private:
    friend class Data;

    vector<double> X;
    vector<double> Y;

    int alpha = 50;
    QColor color;

    FunctionPtr function = nullptr;
    int id = -1;
    string name;

public:
    CurveData(const QColor& _color, FunctionPtr _function = nullptr,
              int _id = -1, const string& _name = "");

    void generate_X(double begin, double end, double step);
    void generate_Y(const vector<double>& _X, FunctionPtr _function);

    const vector<double>& get_X() const;
    const vector<double>& get_Y() const;
    const QColor& get_color() const;
    FunctionPtr get_function() const;
    int get_id() const;
    const string& get_name() const;
};

#endif // CURVEDATA_H
