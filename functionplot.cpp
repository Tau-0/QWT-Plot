#include "functionplot.h"

void FunctionPlot::set_checkbox() {
    checkbox_ = make_unique<QCheckBox>();
    checkbox_->setChecked(true);
    vbox_->addWidget(checkbox_.get());
    connect(checkbox_.get(), &QCheckBox::stateChanged, this, &FunctionPlot::process_checkbox);
}

FunctionPlot::FunctionPlot(QVBoxLayout* vbox) : vbox_(vbox) {
    set_checkbox();
    curve_ = make_unique<QwtPlotCurve>();
}

QCheckBox* FunctionPlot::get_checkbox() const {
    return checkbox_.get();
}

QwtPlotCurve* FunctionPlot::get_curve() const {
    return curve_.get();
}

void FunctionPlot::process_checkbox() {
    QCheckBox* checkbox = static_cast<QCheckBox*>(sender());

    if (checkbox->isChecked()) {
        curve_->show();
    } else {
        curve_->hide();
    }

    emit plot_changed();
}
