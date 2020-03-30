#include "data.h"

Data::Data() {
    curves.emplace_back(Qt::red, functions["sin"], 0, "sin(x)");
    curves.emplace_back(Qt::blue, functions["ln"], 1, "ln(x)");
    curves.emplace_back(Qt::green, functions["cos"], 2, "cos(x)");

    curves[0].main_curve.generate_X(0, 5, 0.001);
    curves[0].main_curve.generate_Y(curves[0].main_curve.X, functions["sin"]);

    curves[1].main_curve.generate_X(0, 5, 0.001);
    curves[1].main_curve.generate_Y(curves[1].main_curve.X, functions["ln"]);

    curves[2].main_curve.generate_X(0, 5, 0.001);
    curves[2].main_curve.generate_Y(curves[2].main_curve.X, functions["cos"]);
    curves[2].create_interval(0, 1);
    curves[2].create_interval(3, 4);
}

const FunctionData& Data::get_curve(int i) const {
    return curves[i];
}
