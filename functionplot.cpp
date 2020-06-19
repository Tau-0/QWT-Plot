#include "functionplot.h"

FunctionPlot::FunctionPlot(QVBoxLayout* vbox) {
    set_checkbox(vbox);
    qwt_curve_ = std::make_unique<QwtPlotCurve>();
}

QCheckBox* FunctionPlot::get_checkbox() const {
    return checkbox_.get();
}

QwtPlotCurve* FunctionPlot::get_qwt_curve() const {
    return qwt_curve_.get();
}

void FunctionPlot::set_function_plot(QwtPlot* source, const FunctionData& function_data) {
    checkbox_->setText(function_data.get_name().data());
    checkbox_->setChecked(true);
    checkbox_->show();

    qwt_curve_->setPen(function_data.get_color());
    qwt_curve_->setTitle(function_data.get_name().data());
    set_qwt_curve(source, function_data.get_curve_data());
    emit plot_changed();
}

void FunctionPlot::process_checkbox() {
    QCheckBox* checkbox = static_cast<QCheckBox*>(sender());

    if (checkbox->isChecked()) {
        qwt_curve_->show();
    } else {
        qwt_curve_->hide();
    }

    emit plot_changed();
}

void FunctionPlot::set_checkbox(QVBoxLayout* vbox) {
    checkbox_ = std::make_unique<QCheckBox>();
    checkbox_->hide();
    vbox->addWidget(checkbox_.get());
    connect(checkbox_.get(), &QCheckBox::stateChanged, this, &FunctionPlot::process_checkbox);
}

void FunctionPlot::set_qwt_curve(QwtPlot* source, const CurveData& curve_data) {
    qwt_curve_->setRawSamples(curve_data.data_X(), curve_data.data_Y(), curve_data.data_size());
    qwt_curve_->setRenderHint(QwtPlotItem::RenderAntialiased);
    qwt_curve_->setStyle(QwtPlotCurve::Lines);
    qwt_curve_->attach(source);
}
