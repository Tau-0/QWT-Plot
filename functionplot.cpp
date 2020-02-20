#include "functionplot.h"

FunctionPlot::FunctionPlot() {
    checkbox = make_unique<ModifiedCheckBox>();
    curve = make_unique<QwtPlotCurve>();
}
