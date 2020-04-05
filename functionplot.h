#ifndef FUNCTIONPLOT_H
#define FUNCTIONPLOT_H

#include <QCheckBox>
#include <QObject>
#include <QVBoxLayout>

#include <qwt_plot.h>
#include <qwt_plot_curve.h>

#include <memory>

using std::make_unique;
using std::unique_ptr;

class FunctionPlot : public QObject {
    Q_OBJECT
 public:
    FunctionPlot(QVBoxLayout* vbox);
    QCheckBox* get_checkbox() const;
    QwtPlotCurve* get_curve() const;
    void process_checkbox();
 signals:
    void plot_changed();
 protected:
    QVBoxLayout* vbox_; // Borrow
    unique_ptr<QCheckBox> checkbox_;
    unique_ptr<QwtPlotCurve> curve_;

    void set_checkbox();
};

#endif // FUNCTIONPLOT_H
