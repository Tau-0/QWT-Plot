#include "data.h"

Data::Data() {
    double begin = 0.0;
    double end = 5.0;
    double step = 0.001;

    plot1_data = make_unique<FunctionData>(begin, end, step, functions["sin"], "sin(x)", Qt::red);
    plot2_data = make_unique<FunctionData>(begin, end, step, functions["ln"], "ln(x)", Qt::blue);
    plot_fwi1_data = make_unique<FunctionData>(begin, end, step, functions["cos"], "cos(x)", Qt::green);

    plot_fwi1_data->create_interval(0, 1);
    plot_fwi1_data->create_interval(0.5, 4);
}

const FunctionData& Data::get_plot1_data() const {
    return *plot1_data;
}

const FunctionData& Data::get_plot2_data() const {
    return *plot2_data;
}

const FunctionData& Data::get_plot_fwi1_data() const {
    return *plot_fwi1_data;
}
