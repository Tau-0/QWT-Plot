#ifndef FUNCTIONWITHINTERVALSPLOT_H
#define FUNCTIONWITHINTERVALSPLOT_H

#include <vector>

#include "functionplot.h"
#include "functionwithintervalsdata.h"

using std::vector;

class FunctionWithIntervalsPlot : public FunctionPlot {
 public:
    FunctionWithIntervalsPlot(QVBoxLayout* vbox);
    const vector<unique_ptr<QwtPlotCurve>>& get_qwt_intervals() const;
    void set_function_with_intervals_plot(QwtPlot* source,
                                          const FunctionWithIntervalsData& function_data);
 private:
    void process_checkbox();
    void resize_qwt_intervals(size_t n);
    void set_qwt_interval(size_t i, QwtPlot* source,
                          const CurveData& interval_data, const QColor& color);
    void set_qwt_intervals(QwtPlot* source, const FunctionWithIntervalsData& function_data);

    vector<unique_ptr<QwtPlotCurve>> qwt_intervals_;
};

#endif // FUNCTIONWITHINTERVALSPLOT_H
