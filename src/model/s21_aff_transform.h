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
    AffTransform(obj_t* obj) : obj_t_(obj){};
    ~AffTransform() = default;
    void InitObjStruct(obj_t* obj) { obj_t_ = obj; };
    int Scale(obj_t* obj, double koff);
    int ScaleX(obj_t* obj, double koff);
    int ScaleY(obj_t* obj, double koff);
    int ScaleZ(obj_t* obj, double koff);
    void MoveX(obj_t* obj, double mv);
    void MoveY(obj_t* obj, double mv);
    void MoveZ(obj_t* obj, double mv);
    void TurnX(obj_t* obj, double angle);
    void TurnY(obj_t* obj, double angle);
    void TurnZ(obj_t* obj, double angle);
  private:
    obj_t* obj_t_;
    int res = OK;
    int i = 0;
    double temp_x = 0;
    double temp_y = 0;
    double temp_z = 0;
};
}

#endif  // CPP_S21_3DVIEWER_V2_SRC_MODEL_AFF_TRANSFORMATION_H_