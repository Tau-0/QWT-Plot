#ifndef ZOOMER_H
#define ZOOMER_H

#include <qwt_plot_zoomer.h>

class Zoomer : public QwtPlotZoomer {
 public:
    Zoomer(QWidget* _canvas);
    QwtText trackerTextF(const QPointF& pos) const;
};

#endif // ZOOMER_H
