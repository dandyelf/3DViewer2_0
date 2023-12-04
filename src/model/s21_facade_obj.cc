#include "s21_facade_obj.h"


namespace s21 {
void Facade::OpenObj(const std::string &file_name) {
    parcer_obj_.StartPars(file_name, &main_obj_);
}
} // namespace s21