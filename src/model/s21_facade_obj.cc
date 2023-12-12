#include "s21_facade_obj.h"

namespace s21 {

void Facade::OpenObj(const std::string& file_name) {
  ObjT tmp;
  try {
    parcer_obj_.StartParser(file_name, &tmp);
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
    throw;
  }
  main_obj_ = std::move(tmp);
  rotate_obj_ = main_obj_;
  rotate_obj_.vertexes = rotate_obj_.vertex_vector.data();
  rotate_obj_.polygons = rotate_obj_.polygon_vector.data();
}

void Facade::ResetObj() {
  main_obj_ = rotate_obj_;
  main_obj_.vertexes = main_obj_.vertex_vector.data();
  main_obj_.polygons = main_obj_.polygon_vector.data();
}

void Facade::RotateObj(char axis, double value) {
  s21::AffTransform aff_transform(&main_obj_);
  if (axis == 'x') aff_transform.TurnX(value);
  if (axis == 'y') aff_transform.TurnY(value);
  if (axis == 'z') aff_transform.TurnZ(value);
}

void Facade::ScaleObj(char axis, double value) {
  s21::AffTransform aff_transform(&main_obj_);
  if (axis == '0') aff_transform.Scale(value);
  if (axis == 'x') aff_transform.ScaleX(value);
  if (axis == 'y') aff_transform.ScaleY(value);
  if (axis == 'z') aff_transform.ScaleZ(value);
}

void Facade::MoveObj(char axis, double value) {
  s21::AffTransform aff_transform(&main_obj_);
  if (axis == 'x') aff_transform.MoveX(value);
  if (axis == 'y') aff_transform.MoveY(value);
  if (axis == 'z') aff_transform.MoveZ(value);
}

}  // namespace s21