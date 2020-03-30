#include "zoomer.h"

Zoomer::Zoomer(QWidget* _canvas) :  QwtPlotZoomer(_canvas) {
    setTrackerMode(AlwaysOn);
}

QwtText Zoomer::trackerTextF(const QPointF& pos) const {
    QColor background(Qt::white);
    background.setAlpha(200);
    QwtText text = QwtPlotZoomer::trackerTextF(pos);
    text.setBackgroundBrush(QBrush(background));
    return text;
}
