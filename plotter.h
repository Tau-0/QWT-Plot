#ifndef PLOTTER_H
#define PLOTTER_H

#include <qwt_legend.h>
#include <qwt_plot.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_zoomer.h>

#include <memory>

using std::make_unique;
using std::unique_ptr;

class Plotter {
private:
    QwtPlot* source; // Borrow

    unique_ptr<QwtPlotGrid> grid;
    unique_ptr<QwtLegend> legend;
    unique_ptr<QwtPlotMagnifier> magnifier;
    unique_ptr<QwtPlotPanner> panner;
    unique_ptr<QwtPlotZoomer> zoomer;

    void set_grid();
    void set_legend();
    void set_magnifier();
    void set_panner();
    void set_zoomer();

public:
    Plotter(QwtPlot* _source);
};

#endif // PLOTTER_H
