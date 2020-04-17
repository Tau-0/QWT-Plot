#include "data.h"

Data::Data() {
    double begin = 0.0;
    double end = 5.0;
    double step = 0.001;

    plot1_data_ = std::make_unique<FunctionData>(begin, end, step,
                                            function_table_["sin"], "sin(x)", Qt::red);
    plot2_data_ = std::make_unique<FunctionData>(begin, end, step,
                                            function_table_["ln"], "ln(x)", Qt::blue);
    plot_fwi1_data_ = std::make_unique<FunctionWithIntervalsData>(begin, end, step,
                                                function_table_["cos"], "cos(x)", Qt::green);

    plot_fwi1_data_->create_interval_data(0, 1);
    plot_fwi1_data_->create_interval_data(0.5, 4);
}

const FunctionData& Data::get_plot1_data() const {
    return *plot1_data_;
}

const FunctionData& Data::get_plot2_data() const {
    return *plot2_data_;
}

const FunctionWithIntervalsData& Data::get_plot_fwi1_data() const {
    return *plot_fwi1_data_;
}
