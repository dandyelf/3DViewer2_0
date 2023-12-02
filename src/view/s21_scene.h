#ifndef CPP_S21_3DVIEWER_V2_SRC_VIEW_SCENE_H
#define CPP_S21_3DVIEWER_V2_SRC_VIEW_SCENE_H

#define GL_SILENCE_DEPRECATION

#include <QByteArray>
#include <QOpenGLWidget>

class Scene : public QOpenGLWidget {
  Q_OBJECT
 public:
  Scene(QWidget *parent = nullptr);

  void Set();
  void SetOrtho();
  void SetPersp();

  void SetVertexArr(double *);
  void SetFacetsArr(int *);
  void SetLines(int);

  double fon_r_{}, fon_g_{}, fon_b_{};
  double line_r_{}, line_g_{}, line_b_{};
  double dot_r_{}, dot_g_{}, dot_b_{};

  bool stipple, points, smooth, perspective;
  double line_width;
  double dot_width;

 private:
  void InitializeGL() override;
  void ResizeGL(int w, int h) override;
  void PaintGL() override;

  int data_loaded_{};
  int lines_{};

  float xRot_{}, yRot_{}, zRot_{};
  QPoint mPos_{};

  double *vertex_arr_ = nullptr;
  int *facets_arr_ = nullptr;

  void MousePressEvent(QMouseEvent *) override;
  void MouseMoveEvent(QMouseEvent *) override;

  void Draw();
};

#endif // CPP_S21_3DVIEWER_V2_SRC_VIEW_SCENE_H