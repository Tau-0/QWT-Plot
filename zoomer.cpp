#include "zoomer.h"

Zoomer::Zoomer(QWidget* canvas) : QwtPlotZoomer(canvas) {
    setTrackerMode(AlwaysOn);
}

QwtText Zoomer::trackerTextF(const QPointF& position) const {
    QColor background(Qt::white);
    background.setAlpha(k_default_background_alpha_);
    QwtText text = QwtPlotZoomer::trackerTextF(position);
    text.setBackgroundBrush(QBrush(background));
    return text;
}

void Zoomer::update_base() {
    setZoomBase(scaleRect());
}
