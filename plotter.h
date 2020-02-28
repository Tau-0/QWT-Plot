#ifndef PLOTTER_H
#define PLOTTER_H

#include <qwt_legend.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_panner.h>

#include "curvedata.h"
#include "functionwithintervalsplot.h"
#include "functiontable.h"
#include "zoomer.h"

using std::make_unique;
using std::unique_ptr;
using std::vector;

class Plotter {
private:
    QwtPlot* source; // Borrow
    QVBoxLayout* vbox; // Borrow

    unique_ptr<QwtPlotGrid> grid;
    unique_ptr<QwtLegend> legend;
    unique_ptr<QwtPlotMagnifier> magnifier;
    unique_ptr<QwtPlotPanner> panner;
    unique_ptr<Zoomer> zoomer;

    FunctionPlot plot1;
    FunctionPlot plot2;
    //FunctionWithIntervalsPlot plot_fwi1;

    void set_curve(QwtPlotCurve* curve, const CurveData& curve_data);
    void set_grid();
    void set_legend();
    void set_magnifier();
    void set_panner();
    void set_zoomer();

public:
    Plotter(QwtPlot* _source, QVBoxLayout* _vbox);

    void set_function1(const CurveData& curve_data);
    void set_function2(const CurveData& curve_data);
    void set_function_with_intervals1();
};

#endif // PLOTTER_H

// LeftButton for the zooming
// MidButton for the panning
// RightButton: zoom out by 1
// Ctrl+RighButton: zoom out to full size
