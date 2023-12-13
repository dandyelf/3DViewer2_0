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
  int Scale(double koff) noexcept;
  int ScaleX(double koff) noexcept;
  int ScaleY(double koff) noexcept;
  int ScaleZ(double koff) noexcept;
  void MoveX(double mv) noexcept;
  void MoveY(double mv) noexcept;
  void MoveZ(double mv) noexcept;
  void TurnX(double angle) noexcept;
  void TurnY(double angle) noexcept;
  void TurnZ(double angle) noexcept;
  void clear() noexcept;

 private:
  ObjT* obj_t_;
  int res_ = OK;
  double temp_x_ = 0;
  double temp_y_ = 0;
  double temp_z_ = 0;
};
}  // namespace s21

#endif  // CPP_S21_3DVIEWER_V2_SRC_MODEL_S21_AFF_TRANSFORMATION_H_
