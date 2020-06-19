#include "plotter.h"

Plotter::Plotter(QwtPlot* source, QVBoxLayout* vbox) : source_(source) {
    plot1_ = std::make_unique<FunctionPlot>(vbox);
    plot2_ = std::make_unique<FunctionPlot>(vbox);
    plot_fwi1_ = std::make_unique<FunctionWithIntervalsPlot>(vbox);

    connect(plot1_.get(), &FunctionPlot::plot_changed, this, &Plotter::replot);
    connect(plot2_.get(), &FunctionPlot::plot_changed, this, &Plotter::replot);
    connect(plot_fwi1_.get(), &FunctionPlot::plot_changed, this, &Plotter::replot);

    set_grid();
    set_legend();
    set_magnifier();
    set_panner();
    set_zoomer();
}

void Plotter::set_function1(const FunctionData& function_data) {
    plot1_->set_function_plot(source_, function_data);
}

void Plotter::set_function2(const FunctionData& function_data) {
    plot2_->set_function_plot(source_, function_data);
}

void Plotter::set_function_with_intervals1(const FunctionWithIntervalsData& function_data) {
    plot_fwi1_->set_function_with_intervals_plot(source_, function_data);
    zoomer_->update_base();
}

void Plotter::replot() {
    source_->replot();
}

void Plotter::set_grid() {
    grid_ = std::make_unique<QwtPlotGrid>();
    grid_->enableXMin(true);
    grid_->enableYMin(true);
    grid_->setMajorPen(QPen(Qt::black, 0, Qt::DotLine));
    grid_->setMinorPen(QPen(Qt::gray, 0, Qt::DotLine));
    grid_->attach(source_);
}

void Plotter::set_legend() {
    legend_ = std::make_unique<QwtLegend>();
    source_->insertLegend(legend_.get(), QwtPlot::BottomLegend);
    source_->setCanvasBackground(Qt::white);
    source_->setAxisTitle(QwtPlot::xBottom, "X");
    source_->setAxisTitle(QwtPlot::yLeft, "Y");

}

void Plotter::set_magnifier() {
    magnifier_ = std::make_unique<QwtPlotMagnifier>(source_->canvas());
    magnifier_->setMouseButton(Qt::NoButton);
    magnifier_->setWheelModifiers(Qt::ControlModifier);
}

void Plotter::set_panner() {
    panner_ = std::make_unique<QwtPlotPanner>(source_->canvas());
    panner_->setMouseButton(Qt::MidButton);
}

void Plotter::set_zoomer() {
    zoomer_ = std::make_unique<Zoomer>(source_->canvas());
    zoomer_->setRubberBandPen(QPen(Qt::darkBlue));
    zoomer_->setTrackerPen(QPen(Qt::darkBlue));
    zoomer_->setMousePattern(QwtEventPattern::MouseSelect2, Qt::RightButton, Qt::ControlModifier);
    zoomer_->setMousePattern(QwtEventPattern::MouseSelect3, Qt::RightButton);
}
