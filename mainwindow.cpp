#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    setup_curve("f(x)");
    setup_legend();
    setup_grid();
    setup_magnifier();
    setup_panner();
    //setup_zoomer(); TO DO: Fix conflicting controls.

    // Example
//    const int SAMPLE_SIZE = 10000;

//    vector<double> x(SAMPLE_SIZE);
//    vector<double> y(SAMPLE_SIZE);

//    double step = 0.01;

//    for (int i = 0; i < SAMPLE_SIZE; ++i) {
//        x[i] = i * step;
//        y[i] = x[i] * x[i];
//    }

//    draw_vector(x, y);

    funcptr_t f = search_function("e");
    if (f) {
        draw_function(f, -10, 10, 0.001);
    }
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::draw_function(funcptr_t f, double begin, double end, double step) {
    int size = abs(end - begin) / step;
    vector<double> x(size);
    vector<double> y(size);

    for (int i = 0; i < size; ++i) {
        x[i] = begin + i * step;
        try {
            y[i] = f(x[i]);
        } catch (...) {
            continue;
        }
    }

    draw_vector(x, y);
}

void MainWindow::draw_vector(const vector<double>& x, const vector<double>& y) {
    curve->setSamples(x.data(), y.data(), min(x.size(), y.size()));
    ui->qwtPlot->replot();
}

void MainWindow::setup_curve(const string& name) {
    curve = make_unique<QwtPlotCurve>(name.data());
    curve->setRenderHint(QwtPlotItem::RenderAntialiased);
    curve->setPen(QPen(Qt::red));
    curve->setStyle(QwtPlotCurve::Lines);
    curve->attach(ui->qwtPlot);
}

void MainWindow::setup_grid() {
    grid = make_unique<QwtPlotGrid>();
    grid->enableXMin(true);
    grid->enableYMin(true);
    grid->setMajorPen(QPen(Qt::black, 0, Qt::DotLine));
    grid->setMinorPen(QPen(Qt::gray, 0, Qt::DotLine));
    grid->attach(ui->qwtPlot);
}

void MainWindow::setup_legend() {
    legend = make_unique<QwtLegend>();
    ui->qwtPlot->insertLegend(legend.get(), QwtPlot::RightLegend);
    ui->qwtPlot->setCanvasBackground(Qt::white);
    ui->qwtPlot->setAxisTitle(QwtPlot::xBottom, "X");
    ui->qwtPlot->setAxisTitle(QwtPlot::yLeft, "Y");
}

void MainWindow::setup_magnifier() {
    magnifier = make_unique<QwtPlotMagnifier>(ui->qwtPlot->canvas());
    magnifier->setMouseButton(Qt::NoButton);
    magnifier->setWheelModifiers(Qt::ControlModifier);
}

void MainWindow::setup_panner() {
    panner = make_unique<Panner>(ui->qwtPlot->canvas());
}

void MainWindow::setup_zoomer() {
    zoomer = make_unique<QwtPlotZoomer>(ui->qwtPlot->canvas());
    zoomer->setRubberBandPen(QPen(Qt::green));
}

//void MainWindow::fill_interval(funcptr_t f, double begin, double end, double step) {
//    unique_ptr<QwtPlotCurve> filler = make_unique<QwtPlotCurve>();
//    filler->setBrush(Qt::blue);
//    filler->attach(ui->qwtPlot);

//    int size = abs(end - begin) / step;
//    vector<double> x(size);
//    vector<double> y(size);

//    for (int i = 0; i < size; ++i) {
//        x[i] = begin + i * step;
//        try {
//            y[i] = f(x[i]);
//        } catch (...) {
//            continue;
//        }
//    }

//    filler->setSamples(x.data(), y.data(), min(x.size(), y.size()));

//    ui->qwtPlot->replot();
//}
