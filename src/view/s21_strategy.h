#ifndef CPP_S21_3DVIEWER_V2_SRC_VIEW_S21_STRATEHY_H_
#define CPP_S21_3DVIEWER_V2_SRC_VIEW_S21_STRATEHY_H_

#include "../controller/s21_controller_obj.h"
#include "s21_viewer.h"
#include "ui_s21_viewer.h"

class Viewer;

class ViewerStrategy {
 public:
  virtual void execute(Viewer* viewer) = 0;
  virtual ~ViewerStrategy() {}
};

#endif  // CPP_S21_3DVIEWER_V2_SRC_VIEW_S21_STRATEHY_H_
