#ifndef CURVEWRAPPER_H
#define CURVEWRAPPER_H

#include <QCheckBox>

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
    funcptr_t function;
    int id;

    CurveWrapper();
};

#endif // CURVEWRAPPER_H
