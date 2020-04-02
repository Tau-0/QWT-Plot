#ifndef DATA_H
#define DATA_H

#include <memory>
#include <vector>

#include "functiondata.h"
#include "functiontable.h"

using std::make_unique;
using std::vector;
using std::unique_ptr;

class Data {
 public:
    Data();
    const FunctionData& get_plot1_data() const;
    const FunctionData& get_plot2_data() const;
    const FunctionData& get_plot_fwi1_data() const;
 private:
    unique_ptr<FunctionData> plot1_data;
    unique_ptr<FunctionData> plot2_data;
    unique_ptr<FunctionData> plot_fwi1_data;
    FunctionTable functions;
};

#endif // DATA_H
