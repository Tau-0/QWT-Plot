#include "plotter.h"

Plotter::Plotter(QwtPlot* _source) : source(_source) {
    set_grid();
    set_legend();
    set_magnifier();
    set_panner();
    set_zoomer();
}

void Plotter::set_curve(QwtPlotCurve* curve, const CurveData& curve_data) {
    curve->setRawSamples(curve_data.get_X().data(), curve_data.get_Y().data(), curve_data.get_X().size());
    curve->setRenderHint(QwtPlotItem::RenderAntialiased);
    curve->setStyle(QwtPlotCurve::Lines);
    curve->setTitle(curve_data.get_name().data());
    curve->setPen(curve_data.get_color());
    curve->attach(source);
    source->replot();
}

void Plotter::set_function1(const CurveData& curve_data) {
    auto curve = plot1.get_curve();
    set_curve(curve, curve_data);
}

void Plotter::set_function2(const CurveData& curve_data) {
    auto curve = plot2.get_curve();
    set_curve(curve, curve_data);
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
    panner->setMouseButton(Qt::MidButton);
}

void Plotter::set_zoomer() {
    zoomer = make_unique<Zoomer>(source->canvas());
    zoomer->setRubberBandPen(QPen(Qt::darkBlue));
    zoomer->setTrackerPen(QPen(Qt::darkBlue));
    zoomer->setMousePattern(QwtEventPattern::MouseSelect2, Qt::RightButton, Qt::ControlModifier);
    zoomer->setMousePattern(QwtEventPattern::MouseSelect3, Qt::RightButton);
}

