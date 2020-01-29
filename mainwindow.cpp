#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    vbox = make_unique<QVBoxLayout>();
    ui->box->setLayout(vbox.get());

    setup_legend();
    setup_grid();
    setup_magnifier();
    setup_panner();
    //setup_zoomer(); TO DO: Fix conflicting controls.

    // Examples
    funcptr_t f = search_function("cos");
    if (f) {
        draw_function(-10, 10, 0.001, "cos(x)", Qt::red, f);
    }

    const int SAMPLE_SIZE = 10000;

    vector<double> x(SAMPLE_SIZE);
    vector<double> y(SAMPLE_SIZE);

    double step = 0.01;

    for (int i = 0; i < SAMPLE_SIZE; ++i) {
        x[i] = i * step;
        y[i] = x[i] * x[i];
    }

    draw_vector(x, y, "x^2", Qt::blue);

    f = search_function("sqrt");
    if (f) {
        draw_function(-10, 10, 0.001, "sqrt(x)", Qt::green, f);
    }
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::draw_function(double begin, double end, double step,
                               const string& name, const QColor& color, funcptr_t f) {
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

    draw_vector(x, y, name, color, f);
}

void MainWindow::draw_vector(const vector<double>& x, const vector<double>& y,
                             const string& name, const QColor& color, funcptr_t f) {
    setup_curve(name, color, f);
    curves.back()->curve->setSamples(x.data(), y.data(), min(x.size(), y.size()));
    ui->qwtPlot->replot();
}

void MainWindow::process_checkbox() {
    ModifiedCheckBox* checkbox = static_cast<ModifiedCheckBox*>(sender());
    int id = checkbox->id;

    if (checkbox->isChecked()) {
        curves[id]->curve->show();
    } else {
        curves[id]->curve->hide();
    }

    ui->qwtPlot->replot();
}

void MainWindow::setup_curve(const string& name, const QColor& color, funcptr_t f) {
    curves.emplace_back(make_unique<CurveWrapper>());
    auto& elem = curves.back();

    elem->id = curves.size() - 1;
    elem->curve->setTitle(name.data());
    elem->curve->setRenderHint(QwtPlotItem::RenderAntialiased);
    elem->curve->setStyle(QwtPlotCurve::Lines);
    elem->curve->setPen(color);
    elem->function = f;
    elem->curve->attach(ui->qwtPlot);

    elem->checkbox->setChecked(true);
    elem->checkbox->setText(name.data());
    elem->checkbox->id = curves.back()->id;
    vbox->addWidget(elem->checkbox.get());

    connect(elem->checkbox.get(), &QCheckBox::stateChanged, this, &MainWindow::process_checkbox);
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
    ui->qwtPlot->insertLegend(legend.get(), QwtPlot::BottomLegend);
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
    panner = make_unique<QwtPlotPanner>(ui->qwtPlot->canvas());
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
