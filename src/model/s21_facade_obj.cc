#include "s21_facade_obj.h"

namespace s21 {

void Facade::OpenObj(const char *file_name) {
    parcer_obj_.StartPars(file_name, &main_obj_);
}

void Facade::ResetObj() {
    // ??????????????????
}

void Facade::RotateObj(char axis, double value) {
    if (axis == 'x')
        aff_transform.TurnX(&main_obj_, value);
    if (axis == 'y')
        aff_transform.TurnY(&main_obj_, value);
    if (axis == 'z')
        aff_transform.TurnZ(&main_obj_, value);
}

void Facade::ScaleObj(char axis, double value) {
    if (axis == '0')
        aff_transform.Scale(&main_obj_, value);
    if (axis == 'x')
        aff_transform.ScaleX(&main_obj_, value);
    if (axis == 'y')
        aff_transform.ScaleY(&main_obj_, value);
    if (axis == 'z')
        aff_transform.ScaleZ(&main_obj_, value);
}

void Facade::MoveObj(char axis, double value) {
    if (axis == 'x')
        aff_transform.MoveX(&main_obj_, value);
    if (axis == 'y')
        aff_transform.MoveY(&main_obj_, value);
    if (axis == 'z')
        aff_transform.MoveZ(&main_obj_, value);
}

} // namespace s21