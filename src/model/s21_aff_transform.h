#ifndef CPP_S21_3DVIEWER_V2_SRC_MODEL_S21_AFF_TRANSFORMATION_H_
#define CPP_S21_3DVIEWER_V2_SRC_MODEL_S21_AFF_TRANSFORMATION_H_

#include <cmath>

#include "s21_parser_obj.h"

namespace s21 {
#define RAD_TO_GRAD 0.01745329251994

typedef enum RESULT {
  OK,
  ERR_ZERO,  // масштаб с коэффициентом 0
} RESULT;

class AffTransform {
 public:
  AffTransform() = default;
  AffTransform(const AffTransform&) = delete;
  AffTransform(AffTransform&&) = delete;
  AffTransform(ObjT* obj) : obj_t_(obj){};
  ~AffTransform() = default;
  void InitObjStruct(ObjT* obj) { obj_t_ = obj; };
  int Scale(double koff);
  int ScaleX(double koff);
  int ScaleY(double koff);
  int ScaleZ(double koff);
  void MoveX(double mv);
  void MoveY(double mv);
  void MoveZ(double mv);
  void TurnX(double angle);
  void TurnY(double angle);
  void TurnZ(double angle);
  void clear();

 private:
  ObjT* obj_t_;
  int res_ = OK;
  double temp_x_ = 0;
  double temp_y_ = 0;
  double temp_z_ = 0;
};
}  // namespace s21

#endif  // CPP_S21_3DVIEWER_V2_SRC_MODEL_S21_AFF_TRANSFORMATION_H_
