#include "s21_scene.h"

#include <QtMath>

#include "QMouseEvent"

Scene::Scene(QWidget *parent) : QOpenGLWidget(parent) {
  fon_r_ = 1, fon_g_ = 1, fon_b_ = 1;
  perspective = true;
  stipple = false;
  points = true;
}

void Scene::initializeGL() { glEnable(GL_DEPTH_TEST); }

void Scene::resizeGL(int w, int h) { glViewport(0, 0, w, h); }

void Scene::paintGL() {
  glClearColor(fon_r_, fon_g_, fon_b_, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if (perspective)
    glFrustum(-1, 1, -1, 1, 1 / (2 * tan((60.0 * M_PI / 180) / 2)), 6);
  else
    glOrtho(-1, 1, -1, 1, 1, 3);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glTranslatef(0, 0, -2);
  glRotatef(xRot_, 1, 0, 0);
  glRotatef(yRot_, 0, 1, 0);

  draw();
}

void Scene::SetOrtho() {
  perspective = false;
  update();
}
void Scene::SetPersp() {
  perspective = true;
  update();
}
void Scene::Set() { data_loaded_ = 1; }
void Scene::SetVertexArr(double *arr) { vertex_arr_ = arr; }
void Scene::SetFacetsArr(int *arr) { facets_arr_ = arr; }
void Scene::SetLines(int lines) { lines_ = lines; }
void Scene::mousePressEvent(QMouseEvent *e) { mPos_ = e->pos(); }

void Scene::mouseMoveEvent(QMouseEvent *e) {
  xRot_ = 1 / M_PI * (e->pos().y() - mPos_.y());
  yRot_ = 1 / M_PI * (e->pos().x() - mPos_.x());
  update();
}

void Scene::draw() {
  if (data_loaded_) {
    if (smooth) {
      glEnable(GL_POINT_SMOOTH);
    }
    glVertexPointer(3, GL_DOUBLE, 0, vertex_arr_);
    glEnableClientState(GL_VERTEX_ARRAY);
    glColor3f(line_r_, line_g_, line_b_);
    if (stipple) {
      glLineStipple(2, 0x3333);
      glEnable(GL_LINE_STIPPLE);
    } else {
      glDisable(GL_LINE_STIPPLE);
    }
    glLineWidth(line_width);
    glDrawElements(GL_LINES, lines_, GL_UNSIGNED_INT, facets_arr_);
    glPointSize(dot_width);
    glColor3f(dot_r_, dot_g_, dot_b_);
    if (points) {
      glDrawElements(GL_POINTS, lines_, GL_UNSIGNED_INT, facets_arr_);
    }
    glDisableClientState(GL_VERTEX_ARRAY);
    if (stipple) glDisable(GL_LINE_STIPPLE);
    if (smooth) glDisable(GL_POINT_SMOOTH);
  }

  //    glDrawArrays(GL_TRIANGLES, 1, 12);  //  Данный вариант рисует
  //    закрашенные треугольники. glEnableClientState(GL_INDEX_ARRAY);
}
