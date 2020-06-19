#ifndef PLOTTER_H
#define PLOTTER_H

#include <qwt_legend.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_panner.h>

#include "data.h"
#include "functionwithintervalsplot.h"
#include "zoomer.h"

class Plotter : public QObject {
 public:
    Plotter(QwtPlot* source, QVBoxLayout* vbox);
    void set_function1(const FunctionData& function_data);
    void set_function2(const FunctionData& function_data);
    void set_function_with_intervals1(const FunctionWithIntervalsData& function_data);
 public slots:
    void replot();
 private:
    void set_grid();
    void set_legend();
    void set_magnifier();
    void set_panner();
    void set_zoomer();

    QwtPlot* source_; // Borrow
    std::unique_ptr<QwtPlotGrid> grid_;
    std::unique_ptr<QwtLegend> legend_;
    std::unique_ptr<QwtPlotMagnifier> magnifier_;
    std::unique_ptr<QwtPlotPanner> panner_;
    std::unique_ptr<Zoomer> zoomer_;

    std::unique_ptr<FunctionPlot> plot1_;
    std::unique_ptr<FunctionPlot> plot2_;
    std::unique_ptr<FunctionWithIntervalsPlot> plot_fwi1_;
};

#endif // PLOTTER_H

// LeftButton for the zooming
// MidButton for the panning
// RightButton: zoom out by 1
// Ctrl+RighButton: zoom out to full size
