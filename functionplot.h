#ifndef FUNCTIONPLOT_H
#define FUNCTIONPLOT_H

#include <QCheckBox>
#include <QObject>
#include <QVBoxLayout>

#include <qwt_plot.h>
#include <qwt_plot_curve.h>

#include <memory>

#include "functiondata.h"

using std::make_unique;
using std::unique_ptr;

class FunctionPlot : public QObject {
    Q_OBJECT
 public:
    FunctionPlot(QVBoxLayout* vbox);
    QCheckBox* get_checkbox() const;
    QwtPlotCurve* get_qwt_curve() const;
    void set_function_plot(QwtPlot* source, const FunctionData& function_data);
 signals:
    void plot_changed();
 protected:
    void process_checkbox();
    void set_checkbox(QVBoxLayout* vbox);
    void set_qwt_curve(QwtPlot* source, const CurveData& curve_data);

    unique_ptr<QCheckBox> checkbox_;
    unique_ptr<QwtPlotCurve> qwt_curve_;
};

#endif // FUNCTIONPLOT_H
