#ifndef DATA_H
#define DATA_H

#include <memory>

#include "functionwithintervalsdata.h"

class Data {
 public:
    Data();
    const FunctionData& get_plot1_data() const;
    const FunctionData& get_plot2_data() const;
    const FunctionWithIntervalsData& get_plot_fwi1_data() const;
 private:
    std::unique_ptr<FunctionData> plot1_data_;
    std::unique_ptr<FunctionData> plot2_data_;
    std::unique_ptr<FunctionWithIntervalsData> plot_fwi1_data_;
    FunctionTable function_table_;
};

#endif // DATA_H
