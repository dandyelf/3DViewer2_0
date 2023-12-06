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
    AffTransform(ObjT* obj) : ObjT_(obj){};
    ~AffTransform() = default;
    void InitObjStruct(ObjT* obj) { ObjT_ = obj; };
    int Scale(ObjT* obj, double koff);
    int ScaleX(ObjT* obj, double koff);
    int ScaleY(ObjT* obj, double koff);
    int ScaleZ(ObjT* obj, double koff);
    void MoveX(ObjT* obj, double mv);
    void MoveY(ObjT* obj, double mv);
    void MoveZ(ObjT* obj, double mv);
    void TurnX(ObjT* obj, double angle);
    void TurnY(ObjT* obj, double angle);
    void TurnZ(ObjT* obj, double angle);
  private:
    ObjT* ObjT_;
    int res = OK;
    int i = 0;
    double temp_x = 0;
    double temp_y = 0;
    double temp_z = 0;
};
}

#endif  // CPP_S21_3DVIEWER_V2_SRC_MODEL_AFF_TRANSFORMATION_H_