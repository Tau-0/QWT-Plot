#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QWidget>

#include <qwt_plot.h>

#include <memory>

#include "data.h"
#include "plotter.h"

using std::make_unique;
using std::unique_ptr;

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
 public:
   MainWindow(QWidget* parent = nullptr);
   ~MainWindow();
   void run_test();
 protected:
   QVBoxLayout* get_box_source() const;
   QwtPlot* get_plotter_source() const;
 private:
    Ui::MainWindow* ui;
    unique_ptr<QVBoxLayout> vbox;
    unique_ptr<Plotter> main_plotter;
    unique_ptr<Data> plotter_data;
};

#endif // MAINWINDOW_H
