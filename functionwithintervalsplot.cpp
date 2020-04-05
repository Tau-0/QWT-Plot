#include "functionwithintervalsplot.h"

FunctionWithIntervalsPlot::FunctionWithIntervalsPlot(QVBoxLayout* vbox) :
    FunctionPlot(vbox) {
    connect(checkbox_.get(), &QCheckBox::stateChanged,
            this, &FunctionWithIntervalsPlot::process_checkbox);
}

const vector<unique_ptr<QwtPlotCurve>>& FunctionWithIntervalsPlot::get_fillers() const {
    return fillers_;
}

void FunctionWithIntervalsPlot::make_fillers(int n) {
    fillers_.reserve(n);
    for (int i = 0; i < n; ++i) {
        fillers_.push_back(make_unique<QwtPlotCurve>());
    }
}

void FunctionWithIntervalsPlot::process_checkbox() {
    QCheckBox* checkbox = static_cast<QCheckBox*>(sender());

    if (checkbox->isChecked()) {
        curve_->show();
        for (const auto& filler : fillers_) {
            filler->show();
        }
    } else {
        curve_->hide();
        for (const auto& filler : fillers_) {
            filler->hide();
        }
    }

    emit plot_changed();
}
