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
#include "data.h"
#include "functiontable.h"
#include "plotter.h"

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
    unique_ptr<Plotter> plotter;
    unique_ptr<Data> data;

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    QwtPlot* get_plotter_source() const;
//    void draw_function(double begin, double end, double step,
//                       const string& name, const QColor& color, funcptr_t f);
//    void draw_vector(const vector<double>& x, const vector<double>& y,
//                     const string& name, const QColor& color = Qt::red, funcptr_t f = NULL);
//    void fill_interval(double begin, double end, double step, int id = -1,
//                       const string& name = "");

//    void process_checkbox();

//    void setup_curve(const string& name, const QColor& color, funcptr_t f = NULL);
};
#endif // MAINWINDOW_H
