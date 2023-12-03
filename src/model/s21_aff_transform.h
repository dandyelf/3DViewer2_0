#ifndef CPP_S21_3DVIEWER_V2_SRC_MODEL_AFF_TRANSFORMATION_H_
#define CPP_S21_3DVIEWER_V2_SRC_MODEL_AFF_TRANSFORMATION_H_

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
    AffTransform(Object* obj) : object_(obj){};
    ~AffTransform() = default;
    void InitObjStruct(Object* obj) { object_ = obj; };
    int Scale(Object* obj, double koff);
    int ScaleX(Object* obj, double koff);
    int ScaleY(Object* obj, double koff);
    int ScaleZ(Object* obj, double koff);
    void MoveX(Object* obj, double mv);
    void MoveY(Object* obj, double mv);
    void MoveZ(Object* obj, double mv);
    void TurnX(Object* obj, double angle);
    void TurnY(Object* obj, double angle);
    void TurnZ(Object* obj, double angle);
  private:
    Object* object_;
    int res = OK;
    int i = 0;
    double temp_x = 0;
    double temp_y = 0;
    double temp_z = 0;
};
}

#endif  // CPP_S21_3DVIEWER_V2_SRC_MODEL_AFF_TRANSFORMATION_H_