#include "s21_facade_obj.h"

namespace s21 {

void Facade::OpenObj(const std::string &file_name) {
    parcer_obj_.StartPars(file_name, &main_obj_);
}

void Facade::ResetObj() {
    // ??????????????????
}

void Facade::RotateObj(char axis, double value) {
    s21::AffTransform aff_transform(&main_obj_);
    if (axis == 'x')
        aff_transform.TurnX(value);
    if (axis == 'y')
        aff_transform.TurnY(value);
    if (axis == 'z')
        aff_transform.TurnZ(value);
}

void Facade::ScaleObj(char axis, double value) {
     s21::AffTransform aff_transform(&main_obj_);
    if (axis == '0')
        aff_transform.Scale(value);
    if (axis == 'x')
        aff_transform.ScaleX(value);
    if (axis == 'y')
        aff_transform.ScaleY(value);
    if (axis == 'z')
        aff_transform.ScaleZ(value);
}

void Facade::MoveObj(char axis, double value) {
     s21::AffTransform aff_transform(&main_obj_);
    if (axis == 'x')
        aff_transform.MoveX(value);
    if (axis == 'y')
        aff_transform.MoveY(value);
    if (axis == 'z')
        aff_transform.MoveZ(value);
}

} // namespace s21