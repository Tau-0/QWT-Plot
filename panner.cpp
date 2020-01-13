#include "panner.h"

Panner::Panner(QWidget* parent): QwtPlotPanner(parent) {}

bool Panner::eventFilter(QObject* object, QEvent* event) {
    if (!object || object != parentWidget()) {
        return false;
    }

    QMouseEvent* mouse = static_cast<QMouseEvent*>(event);

    if (event->type() == QEvent::MouseButtonPress) {
        widgetMousePressEvent(mouse);
    } else if (event->type() == QEvent::MouseMove) {
        widgetMouseMoveEvent(mouse);
        widgetMouseReleaseEvent(mouse);
        setMouseButton(mouse->button(), mouse->modifiers());
        widgetMousePressEvent(mouse);
    } else if (event->type() == QEvent::MouseButtonRelease) {
        widgetMouseReleaseEvent(mouse);
        grab();
    } else if (event->type() == QEvent::Paint && isVisible()) {
        return true;
    }

    return false;
}
