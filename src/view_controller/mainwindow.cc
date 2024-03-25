#include "mainwindow.h"

#include "ui_mainwindow.h"
using namespace my;

MainWindow::MainWindow(MathCalculator *calc, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), model_(calc) {
  ui->setupUi(this);
  this->setFixedSize(1190, 450);

  connect(ui->zero, SIGNAL(clicked()), this, SLOT(buttonClicked()));
  connect(ui->one, SIGNAL(clicked()), this, SLOT(buttonClicked()));
  connect(ui->two, SIGNAL(clicked()), this, SLOT(buttonClicked()));
  connect(ui->three, SIGNAL(clicked()), this, SLOT(buttonClicked()));
  connect(ui->four, SIGNAL(clicked()), this, SLOT(buttonClicked()));
  connect(ui->five, SIGNAL(clicked()), this, SLOT(buttonClicked()));
  connect(ui->six, SIGNAL(clicked()), this, SLOT(buttonClicked()));
  connect(ui->seven, SIGNAL(clicked()), this, SLOT(buttonClicked()));
  connect(ui->eight, SIGNAL(clicked()), this, SLOT(buttonClicked()));
  connect(ui->nine, SIGNAL(clicked()), this, SLOT(buttonClicked()));
  connect(ui->dot, SIGNAL(clicked()), this, SLOT(buttonClicked()));

  connect(ui->x_b, SIGNAL(clicked()), this, SLOT(buttonClicked()));
  connect(ui->add, SIGNAL(clicked()), this, SLOT(buttonClicked()));
  connect(ui->sub, SIGNAL(clicked()), this, SLOT(buttonClicked()));
  connect(ui->mul, SIGNAL(clicked()), this, SLOT(buttonClicked()));
  connect(ui->div, SIGNAL(clicked()), this, SLOT(buttonClicked()));
  connect(ui->pow, SIGNAL(clicked()), this, SLOT(buttonClicked()));
  connect(ui->openBracket, SIGNAL(clicked()), this, SLOT(buttonClicked()));
  connect(ui->closeBracket, SIGNAL(clicked()), this, SLOT(buttonClicked()));

  connect(ui->sin, SIGNAL(clicked()), this, SLOT(functionClicked()));
  connect(ui->cos, SIGNAL(clicked()), this, SLOT(functionClicked()));
  connect(ui->tan, SIGNAL(clicked()), this, SLOT(functionClicked()));
  connect(ui->asin, SIGNAL(clicked()), this, SLOT(functionClicked()));
  connect(ui->acos, SIGNAL(clicked()), this, SLOT(functionClicked()));
  connect(ui->atan, SIGNAL(clicked()), this, SLOT(functionClicked()));
  connect(ui->sqrt, SIGNAL(clicked()), this, SLOT(functionClicked()));
  connect(ui->ln, SIGNAL(clicked()), this, SLOT(functionClicked()));
  connect(ui->mod, SIGNAL(clicked()), this, SLOT(functionClicked()));
  connect(ui->log, SIGNAL(clicked()), this, SLOT(functionClicked()));

  connect(ui->backSpace, SIGNAL(clicked()), this, SLOT(backSpace()));
  connect(ui->del_b, SIGNAL(clicked()), this, SLOT(deleteString()));

  connect(ui->equal, SIGNAL(clicked()), this, SLOT(equalClicked()));
  connect(ui->plot, SIGNAL(clicked()), this, SLOT(drawPlot()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::equalClicked() {
  double result;

  double input_x = ui->input_x->value();
  std::string input = ui->input->text().toStdString();

  try {
    result = model_->Calculate(input, input_x);
    ui->input->setText(QString::number(result, 'g', 15));
  } catch (std::exception &e) {
    ui->input->setText(e.what());
  }
}

void MainWindow::buttonClicked() {
  QPushButton *butt = (QPushButton *)sender();
  QString butt_text = butt->text();
  QString input_text = ui->input->text();
  ui->input->setText(input_text.append(butt_text));
}

void MainWindow::functionClicked() {
  QPushButton *butt = (QPushButton *)sender();
  QString butt_text = butt->text();
  if (butt_text != "mod") {
    butt_text.append('(');
  }
  QString input_text = ui->input->text();
  ui->input->setText(input_text.append(butt_text));
}

void MainWindow::backSpace() {
  QString input = ui->input->text();
  input.chop(1);
  ui->input->setText(input);
}

void MainWindow::deleteString() { ui->input->setText(""); }

void MainWindow::drawPlot() {
  double res_Y;
  h = 0.01;
  xMin = ui->input_x_min->value();
  xMax = ui->input_x_max->value();
  yMin = ui->input_y_min->value();
  yMax = ui->input_y_max->value();

  std::string input = ui->input->text().toStdString();
  for (X = xMin; X <= xMax; X += h) {
    res_Y = model_->Calculate(input, X);
    x.push_back(X);
    y.push_back(res_Y);
  }

  ui->widget->xAxis->setRange(xMin, xMax);
  ui->widget->yAxis->setRange(yMin, yMax);

  ui->widget->clearGraphs();
  ui->widget->addGraph();

  ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);
  ui->widget->graph(0)->setScatterStyle(
      QCPScatterStyle(QCPScatterStyle::ssCircle, 5));

  ui->widget->graph(0)->addData(x, y);

  ui->widget->replot();
  ui->widget->setInteraction(QCP::iRangeZoom, true);
  ui->widget->setInteraction(QCP::iRangeDrag, true);
  x.clear();
  y.clear();
}
