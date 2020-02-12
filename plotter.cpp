#include "plotter.h"

Plotter::Plotter(QwtPlot* _source) : source(_source) {
    set_grid();
    set_legend();
    set_magnifier();
    set_panner();
    set_zoomer();
}

void Plotter::set_grid() {
    grid = make_unique<QwtPlotGrid>();
    grid->enableXMin(true);
    grid->enableYMin(true);
    grid->setMajorPen(QPen(Qt::black, 0, Qt::DotLine));
    grid->setMinorPen(QPen(Qt::gray, 0, Qt::DotLine));
    grid->attach(source);
}

void Plotter::set_legend() {
    legend = make_unique<QwtLegend>();
    source->insertLegend(legend.get(), QwtPlot::BottomLegend);
    source->setCanvasBackground(Qt::white);
    source->setAxisTitle(QwtPlot::xBottom, "X");
    source->setAxisTitle(QwtPlot::yLeft, "Y");

}

void Plotter::set_magnifier() {
    magnifier = make_unique<QwtPlotMagnifier>(source->canvas());
    magnifier->setMouseButton(Qt::NoButton);
    magnifier->setWheelModifiers(Qt::ControlModifier);
}

void Plotter::set_panner() {
    panner = make_unique<QwtPlotPanner>(source->canvas());
}

void Plotter::set_zoomer() {
    zoomer = make_unique<QwtPlotZoomer>(source->canvas());
    zoomer->setRubberBandPen(QPen(Qt::green));
}

