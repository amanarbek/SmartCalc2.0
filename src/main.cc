#include <QApplication>

#include "view_controller/mainwindow.h"

using namespace my;

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MathCalculator model;
  MainWindow controller(&model);
  controller.show();
  return a.exec();
}
