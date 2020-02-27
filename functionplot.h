#ifndef FUNCTIONPLOT_H
#define FUNCTIONPLOT_H

#include <qwt_plot_curve.h>

#include <memory>

#include "modifiedcheckbox.h"

using std::make_unique;
using std::unique_ptr;

class FunctionPlot {
private:
    unique_ptr<ModifiedCheckBox> checkbox;
    unique_ptr<QwtPlotCurve> curve;

public:
    FunctionPlot();

    QwtPlotCurve* get_curve() const {
        return curve.get();
    }
};

#endif // FUNCTIONPLOT_H
