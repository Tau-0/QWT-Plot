#include "functionwithintervalsplot.h"

FunctionWithIntervalsPlot::FunctionWithIntervalsPlot(QVBoxLayout* vbox) :
    FunctionPlot(vbox) {
    connect(checkbox_.get(), &QCheckBox::stateChanged,
            this, &FunctionWithIntervalsPlot::process_checkbox);
}

const std::vector<std::unique_ptr<QwtPlotCurve>>& FunctionWithIntervalsPlot::get_qwt_intervals() const {
    return qwt_intervals_;
}

void FunctionWithIntervalsPlot::set_function_with_intervals_plot(QwtPlot* source,
        const FunctionWithIntervalsData& function_data) {
    set_qwt_intervals(source, function_data);
    set_function_plot(source, function_data);
}

void FunctionWithIntervalsPlot::process_checkbox() {
    QCheckBox* checkbox = static_cast<QCheckBox*>(sender());

    if (checkbox->isChecked()) {
        qwt_curve_->show();
        for (const auto& qwt_interval : qwt_intervals_) {
            qwt_interval->show();
        }
    } else {
        qwt_curve_->hide();
        for (const auto& qwt_interval : qwt_intervals_) {
            qwt_interval->hide();
        }
    }

    emit plot_changed();
}

void FunctionWithIntervalsPlot::resize_qwt_intervals(size_t n) {
    qwt_intervals_.reserve(n);
    for (size_t i = 0; i < n; ++i) {
        qwt_intervals_.push_back(std::make_unique<QwtPlotCurve>());
    }
}

void FunctionWithIntervalsPlot::set_qwt_interval(size_t i, QwtPlot* source,
                                        const CurveData& interval_data, const QColor& color) {
    qwt_intervals_[i]->setRawSamples(interval_data.data_X(), interval_data.data_Y(),
                                     interval_data.data_size());
    qwt_intervals_[i]->setBrush(color);
    qwt_intervals_[i]->setItemAttribute(QwtPlotItem::Legend, false);
    qwt_intervals_[i]->attach(source);
}

void FunctionWithIntervalsPlot::set_qwt_intervals(QwtPlot* source, const FunctionWithIntervalsData& function_data) {
    size_t n = function_data.get_intervals_data_size();
    QColor alpha_color{function_data.get_color()};
    alpha_color.setAlpha(function_data.get_intervals_opacity());
    resize_qwt_intervals(n);
    for (size_t i = 0; i < n; ++i) {
        set_qwt_interval(i, source, function_data.get_interval_data(i), alpha_color);
    }
}
