#ifndef PANNER_H
#define PANNER_H

#include <QEvent>
#include <QKeyEvent>
#include <QMouseEvent>

#include<qwt_plot_panner.h>

class Panner: public QwtPlotPanner {
 public:
    Panner(QWidget* parent = nullptr);
    virtual bool eventFilter(QObject* object, QEvent* event);
};

#endif // PANNER_H
