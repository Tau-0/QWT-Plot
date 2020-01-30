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

struct CurveWrapper {
    unique_ptr<ModifiedCheckBox> checkbox;
    unique_ptr<QwtPlotCurve> curve;
    vector<unique_ptr<QwtPlotCurve>> fillers;

    int alpha = 50;
    unique_ptr<QColor> color;

    funcptr_t function;
    int id;
    string name;

    CurveWrapper();
};

#endif // CURVEWRAPPER_H
