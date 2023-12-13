#ifndef CPP_S21_3DVIEWER_V2_SRC_MODEL_S21_FACADE_H_
#define CPP_S21_3DVIEWER_V2_SRC_MODEL_S21_FACADE_H_

#include <iostream>
#include <string>
#include "../model/s21_aff_transform.h"
#include "../model/s21_parser_obj.h"

namespace s21 {

// Facade Singleton
class Facade {
public:
    Facade() noexcept = default;
    Facade(const Facade&) = delete;
    Facade(Facade&&) = delete;
    ~Facade() noexcept = default;
    Facade& operator=(const Facade&) = delete;
    Facade& operator=(Facade&&) = delete;

    void OpenObj(const std::string &file_name);
    void ResetObj() noexcept;
    void RotateObj(char axis, double value) noexcept;
    void ScaleObj(char axis, double value) noexcept;
    void MoveObj(char axis, double value) noexcept;

    const s21::ObjT& GetObject() const noexcept { return main_obj_; }

private:
    ObjT main_obj_;
    ObjT rotate_obj_;
    s21::ParserObj parcer_obj_;
};

} // namespace s21

#endif // CPP_S21_3DVIEWER_V2_SRC_MODEL_S21_FACADE_H_
