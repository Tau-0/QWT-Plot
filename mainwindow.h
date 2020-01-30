#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCheckBox>
#include <QColor>
#include <QMainWindow>
#include <QVBoxLayout>

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

#include "curvewrapper.h"
#include "functiontable.h"

using std::make_unique;
using std::min;
using std::string;
using std::to_string;
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
    unique_ptr<QVBoxLayout> vbox;

    vector<unique_ptr<CurveWrapper>> curves;
    unique_ptr<QwtPlotGrid> grid;
    unique_ptr<QwtLegend> legend;
    unique_ptr<QwtPlotMagnifier> magnifier;
    unique_ptr<QwtPlotPanner> panner;
    unique_ptr<QwtPlotZoomer> zoomer;

 public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    void draw_function(double begin, double end, double step,
                       const string& name, const QColor& color, funcptr_t f);
    void draw_vector(const vector<double>& x, const vector<double>& y,
                     const string& name, const QColor& color = Qt::red, funcptr_t f = NULL);
    void fill_interval(double begin, double end, double step, int id = -1,
                       const string& name = "");

    void process_checkbox();

    void setup_curve(const string& name, const QColor& color, funcptr_t f = NULL);
    void setup_grid();
    void setup_legend();
    void setup_magnifier();
    void setup_panner();
    void setup_zoomer();
};
#endif // MAINWINDOW_H
