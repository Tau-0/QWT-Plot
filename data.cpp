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

    double interval_1_begin = 0;
    double interval_1_end = 1;
    double interval_2_begin = 0.5;
    double interval_2_end = 4;
    plot_fwi1_data_->create_interval_data(interval_1_begin, interval_1_end);
    plot_fwi1_data_->create_interval_data(interval_2_begin, interval_2_end);
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
