#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

#include "model/MathCalculator.h"

using namespace my;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(MathCalculator *calc, QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void buttonClicked();
  void functionClicked();
  void backSpace();
  void deleteString();

  void drawPlot();
  void equalClicked();

 private:
  MathCalculator *model_;
  Ui::MainWindow *ui;
  double xMin, xMax, yMin, yMax, h, X;
  int N;
  QVector<double> x, y;
};
#endif  // MAINWINDOW_H
