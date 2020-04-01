#include "plotter.h"

Plotter::Plotter(QwtPlot* _source, QVBoxLayout* _vbox) :
    source(_source), vbox(_vbox), plot1(_source, _vbox), plot2(_source, _vbox), plot_fwi1(_source, _vbox) {
    set_grid();
    set_legend();
    set_magnifier();
    set_panner();
    set_zoomer();
}

void Plotter::set_curve(QwtPlotCurve* curve, const CurveData& curve_data) {
    curve->setRawSamples(curve_data.get_X().data(),
                         curve_data.get_Y().data(),
                         curve_data.get_X().size());
    curve->setRenderHint(QwtPlotItem::RenderAntialiased);
    curve->setStyle(QwtPlotCurve::Lines);
    curve->attach(source);
}

void Plotter::set_filler(QwtPlotCurve* filler, const CurveData& curve_data, const QColor& color) {
    set_curve(filler, curve_data);
    filler->setBrush(color);
    filler->setLegendAttribute(QwtPlotCurve::LegendShowSymbol, true);
}

void Plotter::set_main_curve(QwtPlotCurve* main_curve, const FunctionData& function_data) {
    set_curve(main_curve, function_data.get_main_curve());
    main_curve->setPen(function_data.get_color());
    main_curve->setTitle(function_data.get_name().data());
}

void Plotter::set_function1(const FunctionData& function_data) {
    auto curve = plot1.get_curve();
    plot1.get_checkbox()->setText(function_data.get_name().data());
    set_main_curve(curve, function_data);
    source->replot();
}

void Plotter::set_function2(const FunctionData& function_data) {
    auto curve = plot2.get_curve();
    plot2.get_checkbox()->setText(function_data.get_name().data());
    set_main_curve(curve, function_data);
    source->replot();
}

void Plotter::set_function_with_intervals1(const FunctionData& function_data) {
    auto curve = plot_fwi1.get_curve();
    plot_fwi1.get_checkbox()->setText(function_data.get_name().data());
    plot_fwi1.make_fillers(function_data.get_size());
    set_main_curve(curve, function_data);

    int i = 0;
    QColor alpha_color{function_data.get_color()};
    alpha_color.setAlpha(function_data.get_opacity());
    for (const auto& filler : plot_fwi1.get_fillers()) {
        set_filler(filler.get(), function_data.get_interval(i++), alpha_color);
    }

    source->replot();
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
