#include "data.h"

Data::Data() {
    curves.emplace_back(Qt::red, functions["sin"], 0, "sin(x)");
    curves.emplace_back(Qt::blue, functions["ln"], 0, "ln(x)");

    curves[0].generate_X(0, 5, 0.001);
    curves[0].generate_Y(curves[0].X, functions["sin"]);

    curves[1].generate_X(0, 5, 0.001);
    curves[1].generate_Y(curves[1].X, functions["ln"]);
}

const CurveData& Data::get_curve(int i) const {
    return curves[i];
}
