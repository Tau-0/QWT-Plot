#ifndef ZOOMER_H
#define ZOOMER_H

#include <qwt_plot_zoomer.h>

class Zoomer : public QwtPlotZoomer {
 public:
    Zoomer(QWidget* canvas);
    QwtText trackerTextF(const QPointF& position) const;
 private:
    static constexpr const int k_default_background_alpha_ = 200;
};

#endif // ZOOMER_H
