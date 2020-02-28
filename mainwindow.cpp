#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    vbox = make_unique<QVBoxLayout>();
    ui->box->setLayout(vbox.get());
    main_plotter = make_unique<Plotter>(get_plotter_source(), get_box_source());
    plotter_data = make_unique<Data>();
}

MainWindow::~MainWindow() {
    delete ui;
}

QVBoxLayout* MainWindow::get_box_source() const {
    return vbox.get();
}

QwtPlot* MainWindow::get_plotter_source() const {
    return ui->qwtPlot;
}

void MainWindow::run_test() {
    main_plotter->set_function1(plotter_data->get_curve(0));
    main_plotter->set_function2(plotter_data->get_curve(1));
}
