#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "plotter.h"

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
    Ui::MainWindow* ui_;
    std::unique_ptr<Plotter> main_plotter_;
    std::unique_ptr<Data> plotter_data_;
};

#endif // MAINWINDOW_H
