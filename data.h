#ifndef DATA_H
#define DATA_H

#include <memory>
#include <vector>

#include "functiontable.h"
#include "functionwithintervalsdata.h"

using std::make_unique;
using std::vector;
using std::unique_ptr;

class Data {
 public:
    Data();
    const FunctionData& get_plot1_data() const;
    const FunctionData& get_plot2_data() const;
    const FunctionWithIntervalsData& get_plot_fwi1_data() const;
 private:
    unique_ptr<FunctionData> plot1_data_;
    unique_ptr<FunctionData> plot2_data_;
    unique_ptr<FunctionWithIntervalsData> plot_fwi1_data_;
    FunctionTable function_table_;
};

#endif // DATA_H
