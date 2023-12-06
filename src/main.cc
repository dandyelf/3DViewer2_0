#include <QApplication>

#include "view/s21_viewer.h"
#include "controller/s21_controller_obj.h"
#include "model/s21_facade_obj.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  Viewer view;
  s21::Controller *controller_obj = s21::Controller::getInstance();
  s21::Facade model_facade;
  controller_obj->SetModel(&model_facade);
  view.SetControllerObj(controller_obj);
  view.show();
  return a.exec();
}
