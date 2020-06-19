#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui_(new Ui::MainWindow) {
    ui_->setupUi(this);
    main_plotter_ = std::make_unique<Plotter>(get_plotter_source(), get_box_source());
    plotter_data_ = std::make_unique<Data>();
}

MainWindow::~MainWindow() {
    delete ui_;
}

QVBoxLayout* MainWindow::get_box_source() const {
    return ui_->verticalLayout_1;
}

QwtPlot* MainWindow::get_plotter_source() const {
    return ui_->qwtPlot;
}

void MainWindow::run_test() {
    main_plotter_->set_function1(plotter_data_->get_plot1_data());
    main_plotter_->set_function2(plotter_data_->get_plot2_data());
    main_plotter_->set_function_with_intervals1(plotter_data_->get_plot_fwi1_data());
}
