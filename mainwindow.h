#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <qwt_legend.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_intervalcurve.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_zoomer.h>

#include <algorithm>
#include <memory>
#include <string>
#include <vector>

#include "functiontable.h"
#include "panner.h"

using std::make_unique;
using std::min;
using std::string;
using std::unique_ptr;
using std::vector;

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

 private:
    Ui::MainWindow* ui;

    unique_ptr<QwtLegend> legend;
    unique_ptr<QwtPlotCurve> curve;
    unique_ptr<QwtPlotGrid> grid;
    unique_ptr<QwtPlotMagnifier> magnifier;
    unique_ptr<Panner> panner;
    unique_ptr<QwtPlotZoomer> zoomer;

 public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    void draw_function(funcptr_t f, double begin, double end, double step);
    void draw_vector(const vector<double>& x, const vector<double>& y);
    void fill_interval(funcptr_t f, double begin, double end, double step);

    void setup_curve(const string& name);
    void setup_grid();
    void setup_legend();
    void setup_magnifier();
    void setup_panner();
    void setup_zoomer();
};
#endif // MAINWINDOW_H
