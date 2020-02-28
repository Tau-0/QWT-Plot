#include "functionplot.h"

void FunctionPlot::set_checkbox() {
    checkbox = make_unique<QCheckBox>();
    checkbox->setChecked(true);
    vbox->addWidget(checkbox.get());
    connect(checkbox.get(), &QCheckBox::stateChanged, this, &FunctionPlot::process_checkbox);
}

FunctionPlot::FunctionPlot(QwtPlot* _source, QVBoxLayout* _vbox) : source(_source), vbox(_vbox) {
    set_checkbox();
    curve = make_unique<QwtPlotCurve>();
}

QCheckBox* FunctionPlot::get_checkbox() const {
    return checkbox.get();
}

QwtPlotCurve* FunctionPlot::get_curve() const {
    return curve.get();
}

void FunctionPlot::process_checkbox() {
    QCheckBox* checkbox = static_cast<QCheckBox*>(sender());

    if (checkbox->isChecked()) {
        curve->show();
    } else {
        curve->hide();
    }

    source->replot();
}
