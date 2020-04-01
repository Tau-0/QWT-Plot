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
    FunctionPlot(QwtPlot* _source, QVBoxLayout* _vbox);
    QCheckBox* get_checkbox() const;
    QwtPlotCurve* get_curve() const;
    void process_checkbox();
 protected:
    QwtPlot* source; // Borrow
    QVBoxLayout* vbox; // Borrow
    unique_ptr<QCheckBox> checkbox;
    unique_ptr<QwtPlotCurve> curve;

    void set_checkbox();
};

#endif // FUNCTIONPLOT_H
