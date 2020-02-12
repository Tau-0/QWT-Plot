#ifndef CURVEWRAPPER_H
#define CURVEWRAPPER_H

#include <QCheckBox>
#include <QColor>

#include <qwt_plot_curve.h>

#include <memory>
#include <vector>

#include "functiontable.h"
#include "modifiedcheckbox.h"

using std::make_unique;
using std::vector;
using std::unique_ptr;

class CurveWrapper {
private:
    unique_ptr<ModifiedCheckBox> checkbox;
    unique_ptr<QwtPlotCurve> curve;
    vector<unique_ptr<QwtPlotCurve>> fillers;

    int alpha = 50;
    unique_ptr<QColor> color;

    FunctionPtr function;
    int id;
    string name;

public:
    CurveWrapper();
};

#endif // CURVEWRAPPER_H
