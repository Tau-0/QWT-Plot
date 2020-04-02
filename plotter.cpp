#include "plotter.h"

Plotter::Plotter(QwtPlot* source, QVBoxLayout* vbox) :
    source_(source), vbox_(vbox),
    plot1_(source, vbox), plot2_(source, vbox), plot_fwi1_(source, vbox) {
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
    curve->attach(source_);
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
    auto curve = plot1_.get_curve();
    plot1_.get_checkbox()->setText(function_data.get_name().data());
    set_main_curve(curve, function_data);
    source_->replot();
}

void Plotter::set_function2(const FunctionData& function_data) {
    auto curve = plot2_.get_curve();
    plot2_.get_checkbox()->setText(function_data.get_name().data());
    set_main_curve(curve, function_data);
    source_->replot();
}

void Plotter::set_function_with_intervals1(const FunctionData& function_data) {
    auto curve = plot_fwi1_.get_curve();
    plot_fwi1_.get_checkbox()->setText(function_data.get_name().data());
    plot_fwi1_.make_fillers(function_data.get_size());
    set_main_curve(curve, function_data);

    int i = 0;
    QColor alpha_color{function_data.get_color()};
    alpha_color.setAlpha(function_data.get_interval_opacity());
    for (const auto& filler : plot_fwi1_.get_fillers()) {
        set_filler(filler.get(), function_data.get_interval(i++), alpha_color);
    }

    source_->replot();
}

void Plotter::set_grid() {
    grid_ = make_unique<QwtPlotGrid>();
    grid_->enableXMin(true);
    grid_->enableYMin(true);
    grid_->setMajorPen(QPen(Qt::black, 0, Qt::DotLine));
    grid_->setMinorPen(QPen(Qt::gray, 0, Qt::DotLine));
    grid_->attach(source_);
}

void Plotter::set_legend() {
    legend_ = make_unique<QwtLegend>();
    source_->insertLegend(legend_.get(), QwtPlot::BottomLegend);
    source_->setCanvasBackground(Qt::white);
    source_->setAxisTitle(QwtPlot::xBottom, "X");
    source_->setAxisTitle(QwtPlot::yLeft, "Y");

}

void Plotter::set_magnifier() {
    magnifier_ = make_unique<QwtPlotMagnifier>(source_->canvas());
    magnifier_->setMouseButton(Qt::NoButton);
    magnifier_->setWheelModifiers(Qt::ControlModifier);
}

void Plotter::set_panner() {
    panner_ = make_unique<QwtPlotPanner>(source_->canvas());
    panner_->setMouseButton(Qt::MidButton);
}

void Plotter::set_zoomer() {
    zoomer_ = make_unique<Zoomer>(source_->canvas());
    zoomer_->setRubberBandPen(QPen(Qt::darkBlue));
    zoomer_->setTrackerPen(QPen(Qt::darkBlue));
    zoomer_->setMousePattern(QwtEventPattern::MouseSelect2, Qt::RightButton, Qt::ControlModifier);
    zoomer_->setMousePattern(QwtEventPattern::MouseSelect3, Qt::RightButton);
}
