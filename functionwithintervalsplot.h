#ifndef FUNCTIONWITHINTERVALSPLOT_H
#define FUNCTIONWITHINTERVALSPLOT_H

#include <vector>

#include "functionplot.h"

using std::vector;

class FunctionWithIntervalsPlot : public FunctionPlot {
private:
    vector<unique_ptr<QwtPlotCurve>> fillers;
public:
    FunctionWithIntervalsPlot(QwtPlot* _source, QVBoxLayout* _vbox);
};

#endif // FUNCTIONWITHINTERVALSPLOT_H
