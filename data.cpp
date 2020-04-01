#include "data.h"

Data::Data() {
    double begin = 0.0;
    double end = 5.0;
    double step = 0.001;

    curves.emplace_back(begin, end, step, functions["sin"], "sin(x)", Qt::red);
    curves.emplace_back(begin, end, step, functions["ln"], "ln(x)", Qt::blue);
    curves.emplace_back(begin, end, step, functions["cos"], "cos(x)", Qt::green);

    curves[2].create_interval(0, 1);
    curves[2].create_interval(3, 4);
}

const FunctionData& Data::get_curve(int i) const {
    return curves[i];
}
