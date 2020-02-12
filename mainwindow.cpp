#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    vbox = make_unique<QVBoxLayout>();
    ui->box->setLayout(vbox.get());
    plotter = make_unique<Plotter>(get_plotter_source());
}

MainWindow::~MainWindow() {
    delete ui;
}

QwtPlot* MainWindow::get_plotter_source() const {
    return ui->qwtPlot;
}

/* Examples
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

fill_interval(-2, 0, 0.01, -1, "cos(x)");
fill_interval(0.5, 2, 0.01, -1, "cos(x)");
fill_interval(0, 5, 0.01, -1, "sqrt(x)"); */

//void MainWindow::draw_function(double begin, double end, double step,
//                               const string& name, const QColor& color, funcptr_t f) {
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

//    draw_vector(x, y, name, color, f);
//}

//void MainWindow::draw_vector(const vector<double>& x, const vector<double>& y,
//                             const string& name, const QColor& color, funcptr_t f) {
//    setup_curve(name, color, f);
//    curves.back()->curve->setSamples(x.data(), y.data(), min(x.size(), y.size()));
//    ui->qwtPlot->replot();
//}

//void MainWindow::fill_interval(double begin, double end, double step, int id,
//                               const std::string &name) {
//    if (id == -1) {
//        for (const auto& elem : curves) {
//            if (elem->name == name) {
//                id = elem->id;
//                break;
//            }
//        }

//        if (id == -1) {
//            qDebug() << "There is no such curve.";
//            return;
//        }
//    }

//    curves[id]->fillers.emplace_back(make_unique<QwtPlotCurve>());
//    auto& filler = curves[id]->fillers.back();
//    filler->setBrush(*curves[id]->color.get());
//    filler->setLegendAttribute(QwtPlotCurve::LegendShowSymbol, true);

//    int size = abs(end - begin) / step;
//    vector<double> x(size);
//    vector<double> y(size);

//    for (int i = 0; i < size; ++i) {
//        x[i] = begin + i * step;
//        try {
//            y[i] = curves[id]->function(x[i]);
//        } catch (...) {
//            continue;
//        }
//    }

//    filler->setSamples(x.data(), y.data(), size);
//    filler->attach(ui->qwtPlot);
//    ui->qwtPlot->replot();
//}

//void MainWindow::process_checkbox() {
//    ModifiedCheckBox* checkbox = static_cast<ModifiedCheckBox*>(sender());
//    int id = checkbox->id;

//    if (checkbox->isChecked()) {
//        curves[id]->curve->show();
//        for (const auto& filler : curves[id]->fillers) {
//            filler->show();
//        }
//    } else {
//        curves[id]->curve->hide();
//        for (const auto& filler : curves[id]->fillers) {
//            filler->hide();
//        }
//    }

//    ui->qwtPlot->replot();
//}

//void MainWindow::setup_curve(const string& name, const QColor& color, funcptr_t f) {
//    curves.emplace_back(make_unique<CurveWrapper>());
//    auto& elem = curves.back();

//    elem->color = make_unique<QColor>(color.red(), color.green(), color.blue(), elem->alpha);
//    elem->function = f;
//    elem->id = curves.size() - 1;
//    elem->name = name;

//    elem->curve->setTitle(name.data());
//    elem->curve->setRenderHint(QwtPlotItem::RenderAntialiased);
//    elem->curve->setStyle(QwtPlotCurve::Lines);
//    elem->curve->setPen(color);
//    elem->curve->attach(ui->qwtPlot);

//    elem->checkbox->setChecked(true);
//    elem->checkbox->setText(name.data());
//    elem->checkbox->id = curves.back()->id;

//    vbox->addWidget(elem->checkbox.get());
//    connect(elem->checkbox.get(), &QCheckBox::stateChanged, this, &MainWindow::process_checkbox);
//}
