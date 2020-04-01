#ifndef FUNCTIONWITHINTERVALSPLOT_H
#define FUNCTIONWITHINTERVALSPLOT_H

#include <vector>

#include "functionplot.h"

using std::vector;

class FunctionWithIntervalsPlot : public FunctionPlot {
 public:
   FunctionWithIntervalsPlot(QwtPlot* _source, QVBoxLayout* _vbox);
   const vector<unique_ptr<QwtPlotCurve>>& get_fillers() const;
   void make_fillers(int n);
   void process_checkbox();
 private:
    vector<unique_ptr<QwtPlotCurve>> fillers;
};

#endif // FUNCTIONWITHINTERVALSPLOT_H
