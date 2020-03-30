#include "functionwithintervalsplot.h"

FunctionWithIntervalsPlot::FunctionWithIntervalsPlot(QwtPlot* _source, QVBoxLayout* _vbox) :
    FunctionPlot(_source, _vbox) {
    connect(checkbox.get(), &QCheckBox::stateChanged, this, &FunctionWithIntervalsPlot::process_checkbox);
}

const vector<unique_ptr<QwtPlotCurve>>& FunctionWithIntervalsPlot::get_fillers() const {
    return fillers;
}

void FunctionWithIntervalsPlot::make_fillers(int n) {
    fillers.reserve(n);
    for (int i = 0; i < n; ++i) {
        fillers.push_back(make_unique<QwtPlotCurve>());
    }
}

void FunctionWithIntervalsPlot::process_checkbox() {
    QCheckBox* checkbox = static_cast<QCheckBox*>(sender());

    if (checkbox->isChecked()) {
        curve->show();
        for (const auto& filler : fillers) {
            filler->show();
        }
    } else {
        curve->hide();
        for (const auto& filler : fillers) {
            filler->hide();
        }
    }

    source->replot();
}
