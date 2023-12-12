#ifndef CPP_S21_3DVIEWER_V2_SRC_VIEW_S21_STRATEHY_RELIZE_H_
#define CPP_S21_3DVIEWER_V2_SRC_VIEW_S21_STRATEHY_RELIZE_H_

#include "s21_strategy.h"

class OrthoStrategy : public ViewerStrategy {
 public:
  void execute(Viewer* viewer) override {
    viewer->ui->widget->SetOrtho();
    viewer->ui->widget->update();
  }
};

class PerspStrategy : public ViewerStrategy {
 public:
  void execute(Viewer* viewer) override {
    viewer->ui->widget->SetPersp();
    viewer->ui->widget->update();
  }
};

class PointsStrategy : public ViewerStrategy {
 public:
  PointsStrategy(int parametr) : parameter_(parametr) {}

  void execute(Viewer* viewer) override {
    if (parameter_ == 1) {
      viewer->ui->widget->points = false;
    } else if (parameter_ == 2) {
      viewer->ui->widget->points = true;
      viewer->ui->widget->smooth = false;
    } else if (parameter_ == 3) {
      viewer->ui->widget->points = true;
      viewer->ui->widget->smooth = true;
    }
    viewer->ui->widget->update();
  }

 private:
  int parameter_;
};

class StippleStrategy : public ViewerStrategy {
 public:
  StippleStrategy(int parametr) : parameter_(parametr) {}

  void execute(Viewer* viewer) override {
    if (parameter_ == 1) {
      viewer->ui->widget->stipple = false;
    } else if (parameter_ == 2) {
      viewer->ui->widget->stipple = true;
    }
    viewer->ui->widget->update();
  }

 private:
  int parameter_;
};

class RotateX : public ViewerStrategy {
 public:
  RotateX(s21::Controller* controller) : controller_obj_(controller) {}

  void execute(Viewer* viewer) override {
    double angle = viewer->ui->lineEdit_6->text().toDouble();
    controller_obj_->RotateObj('x', angle);
    viewer->ui->widget->SetVertexArr(controller_obj_->GetObject().vertexes);
    viewer->ui->widget->update();
  }

 private:
  s21::Controller* controller_obj_;
};

class RotateY : public ViewerStrategy {
 public:
  RotateY(s21::Controller* controller) : controller_obj_(controller) {}

  void execute(Viewer* viewer) override {
    double angle = viewer->ui->lineEdit_6->text().toDouble();
    controller_obj_->RotateObj('y', angle);
    viewer->ui->widget->SetVertexArr(controller_obj_->GetObject().vertexes);
    viewer->ui->widget->update();
  }

 private:
  s21::Controller* controller_obj_;
};

class RotateZ : public ViewerStrategy {
 public:
  RotateZ(s21::Controller* controller) : controller_obj_(controller) {}

  void execute(Viewer* viewer) override {
    double angle = viewer->ui->lineEdit_6->text().toDouble();
    controller_obj_->RotateObj('z', angle);
    viewer->ui->widget->SetVertexArr(controller_obj_->GetObject().vertexes);
    viewer->ui->widget->update();
  }

 private:
  s21::Controller* controller_obj_;
};

class RotateXYZ : public ViewerStrategy {
 public:
  RotateXYZ(s21::Controller* controller) : controller_obj_(controller) {}

  void execute(Viewer* viewer) override {
    double ax = viewer->ui->lineEdit_4->text().toDouble();
    double ay = viewer->ui->lineEdit_5->text().toDouble();
    double az = viewer->ui->lineEdit_6->text().toDouble();
    controller_obj_->RotateObj('x', ax);
    controller_obj_->RotateObj('y', ay);
    controller_obj_->RotateObj('z', az);
    viewer->ui->widget->SetVertexArr(controller_obj_->GetObject().vertexes);
    viewer->ui->widget->update();
  }

 private:
  s21::Controller* controller_obj_;
};

class ScaleX : public ViewerStrategy {
 public:
  ScaleX(s21::Controller* controller) : controller_obj_(controller) {}

  void execute(Viewer* viewer) override {
    double koff = viewer->ui->lineEdit->text().toDouble();
    controller_obj_->ScaleObj('x', koff);
    viewer->ui->widget->SetVertexArr(controller_obj_->GetObject().vertexes);
    viewer->ui->widget->update();
  }

 private:
  s21::Controller* controller_obj_;
};

class ScaleY : public ViewerStrategy {
 public:
  ScaleY(s21::Controller* controller) : controller_obj_(controller) {}

  void execute(Viewer* viewer) override {
    double koff = viewer->ui->lineEdit_2->text().toDouble();
    controller_obj_->ScaleObj('y', koff);
    viewer->ui->widget->SetVertexArr(controller_obj_->GetObject().vertexes);
    viewer->ui->widget->update();
  }

 private:
  s21::Controller* controller_obj_;
};

class ScaleZ : public ViewerStrategy {
 public:
  ScaleZ(s21::Controller* controller) : controller_obj_(controller) {}

  void execute(Viewer* viewer) override {
    double koff = viewer->ui->lineEdit_3->text().toDouble();
    controller_obj_->ScaleObj('z', koff);
    viewer->ui->widget->SetVertexArr(controller_obj_->GetObject().vertexes);
    viewer->ui->widget->update();
  }

 private:
  s21::Controller* controller_obj_;
};

class ScaleXYZ : public ViewerStrategy {
 public:
  ScaleXYZ(s21::Controller* controller) : controller_obj_(controller) {}

  void execute(Viewer* viewer) override {
    double kx = viewer->ui->lineEdit->text().toDouble();
    double ky = viewer->ui->lineEdit_2->text().toDouble();
    double kz = viewer->ui->lineEdit_3->text().toDouble();
    if (!kx || !ky || !kz) {
      viewer->ui->statusbar->showMessage("FAIL: Коэффициент масштаба равен 0!");
    } else {
      controller_obj_->ScaleObj('x', kx);
      controller_obj_->ScaleObj('y', ky);
      controller_obj_->ScaleObj('z', kz);
      viewer->ui->statusbar->clearMessage();
    }
    viewer->ui->widget->SetVertexArr(controller_obj_->GetObject().vertexes);
    viewer->ui->widget->update();
  }

 private:
  s21::Controller* controller_obj_;
};

class MoveXmin : public ViewerStrategy {
 public:
  MoveXmin(s21::Controller* controller) : controller_obj_(controller) {}

  void execute(Viewer* viewer) override {
    double mv = viewer->ui->lineEdit_11->text().toDouble();
    mv *= -1;
    controller_obj_->MoveObj('x', mv);
    viewer->ui->widget->SetVertexArr(controller_obj_->GetObject().vertexes);
    viewer->ui->widget->update();
  }

 private:
  s21::Controller* controller_obj_;
};

class MoveYmin : public ViewerStrategy {
 public:
  MoveYmin(s21::Controller* controller) : controller_obj_(controller) {}

  void execute(Viewer* viewer) override {
    double mv = viewer->ui->lineEdit_10->text().toDouble();
    mv *= -1;
    controller_obj_->MoveObj('y', mv);
    viewer->ui->widget->SetVertexArr(controller_obj_->GetObject().vertexes);
    viewer->ui->widget->update();
  }

 private:
  s21::Controller* controller_obj_;
};

class MoveZmin : public ViewerStrategy {
 public:
  MoveZmin(s21::Controller* controller) : controller_obj_(controller) {}

  void execute(Viewer* viewer) override {
    double mv = viewer->ui->lineEdit_8->text().toDouble();
    mv *= -1;
    controller_obj_->MoveObj('z', mv);
    viewer->ui->widget->SetVertexArr(controller_obj_->GetObject().vertexes);
    viewer->ui->widget->update();
  }

 private:
  s21::Controller* controller_obj_;
};

class MoveX : public ViewerStrategy {
 public:
  MoveX(s21::Controller* controller) : controller_obj_(controller) {}

  void execute(Viewer* viewer) override {
    double mv = viewer->ui->lineEdit_12->text().toDouble();
    controller_obj_->MoveObj('x', mv);
    viewer->ui->widget->SetVertexArr(controller_obj_->GetObject().vertexes);
    viewer->ui->widget->update();
  }

 private:
  s21::Controller* controller_obj_;
};

class MoveY : public ViewerStrategy {
 public:
  MoveY(s21::Controller* controller) : controller_obj_(controller) {}

  void execute(Viewer* viewer) override {
    double mv = viewer->ui->lineEdit_7->text().toDouble();
    controller_obj_->MoveObj('y', mv);
    viewer->ui->widget->SetVertexArr(controller_obj_->GetObject().vertexes);
    viewer->ui->widget->update();
  }

 private:
  s21::Controller* controller_obj_;
};

class MoveZ : public ViewerStrategy {
 public:
  MoveZ(s21::Controller* controller) : controller_obj_(controller) {}

  void execute(Viewer* viewer) override {
    double mv = viewer->ui->lineEdit_9->text().toDouble();
    controller_obj_->MoveObj('z', mv);
    viewer->ui->widget->SetVertexArr(controller_obj_->GetObject().vertexes);
    viewer->ui->widget->update();
  }

 private:
  s21::Controller* controller_obj_;
};

class MoveXYZ : public ViewerStrategy {
 public:
  MoveXYZ(s21::Controller* controller) : controller_obj_(controller) {}

  void execute(Viewer* viewer) override {
    double mv_xpos = viewer->ui->lineEdit_12->text().toDouble();
    double mv_xneg = viewer->ui->lineEdit_11->text().toDouble();
    double mv_ypos = viewer->ui->lineEdit_7->text().toDouble();
    double mv_yneg = viewer->ui->lineEdit_10->text().toDouble();
    double mv_zpos = viewer->ui->lineEdit_9->text().toDouble();
    double mv_zneg = viewer->ui->lineEdit_8->text().toDouble();
    mv_xneg *= -1;
    mv_yneg *= -1;
    mv_zneg *= -1;
    controller_obj_->MoveObj('x', mv_xpos);
    controller_obj_->MoveObj('x', mv_xneg);
    controller_obj_->MoveObj('y', mv_ypos);
    controller_obj_->MoveObj('y', mv_yneg);
    controller_obj_->MoveObj('z', mv_zpos);
    controller_obj_->MoveObj('z', mv_zneg);
    viewer->ui->widget->SetVertexArr(controller_obj_->GetObject().vertexes);
    viewer->ui->widget->update();
  }

 private:
  s21::Controller* controller_obj_;
};

class HorizontalScroll_dot : public ViewerStrategy {
 public:
  HorizontalScroll_dot(char parametr, int value)
      : parameter_(parametr), value_(value) {}

  void execute(Viewer* viewer) override {
    if (parameter_ == 'b') {
      viewer->ui->widget->dot_b_ = (double)value_ / 100.0;
    } else if (parameter_ == 'g') {
      viewer->ui->widget->dot_g_ = (double)value_ / 100.0;
    } else if (parameter_ == 'w') {
      viewer->ui->widget->dot_width = value_;
    } else if (parameter_ == 'r') {
      viewer->ui->widget->dot_r_ = (double)value_ / 100.0;
    }
    viewer->ui->widget->update();
  }

 private:
  char parameter_;
  int value_;
};

class HorizontalScroll_line : public ViewerStrategy {
 public:
  HorizontalScroll_line(char parametr, int value)
      : parameter_(parametr), value_(value) {}

  void execute(Viewer* viewer) override {
    if (parameter_ == 'b') {
      viewer->ui->widget->line_b_ = ((double)value_) / 100.0;
    } else if (parameter_ == 'g') {
      viewer->ui->widget->line_g_ = ((double)value_) / 100.0;
    } else if (parameter_ == 'w') {
      viewer->ui->widget->line_width = (double)value_;
      ;
    } else if (parameter_ == 'r') {
      viewer->ui->widget->line_r_ = ((double)value_) / 100.0;
    }
    viewer->ui->widget->update();
  }

 private:
  char parameter_;
  int value_;
};

class HorizontalScroll_fon : public ViewerStrategy {
 public:
  HorizontalScroll_fon(char parametr, int value)
      : parameter_(parametr), value_(value) {}

  void execute(Viewer* viewer) override {
    if (parameter_ == 'b') {
      viewer->ui->widget->fon_b_ = ((double)value_) / 100.0;
    } else if (parameter_ == 'g') {
      viewer->ui->widget->fon_g_ = ((double)value_) / 100.0;
    } else if (parameter_ == 'r') {
      viewer->ui->widget->fon_r_ = ((double)value_) / 100.0;
    }
    viewer->ui->widget->update();
  }

 private:
  char parameter_;
  int value_;
};

#endif  // CPP_S21_3DVIEWER_V2_SRC_VIEW_S21_STRATEHY_RELIZE_H_
