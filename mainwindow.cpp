#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui_(new Ui::MainWindow) {
    ui_->setupUi(this);
    vbox_ = make_unique<QVBoxLayout>();
    ui_->box->setLayout(vbox_.get());
    main_plotter_ = make_unique<Plotter>(get_plotter_source(), get_box_source());
    plotter_data_ = make_unique<Data>();
}

MainWindow::~MainWindow() {
    delete ui_;
}

QVBoxLayout* MainWindow::get_box_source() const {
    return vbox_.get();
}

QwtPlot* MainWindow::get_plotter_source() const {
    return ui_->qwtPlot;
}

void MainWindow::run_test() {
    main_plotter_->set_function1(plotter_data_->get_plot1_data());
    main_plotter_->set_function2(plotter_data_->get_plot2_data());
    main_plotter_->set_function_with_intervals1(plotter_data_->get_plot_fwi1_data());
}
