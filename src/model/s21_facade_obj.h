
#ifndef SRC_S21_FACADE_H_
#define SRC_S21_FACADE_H_

#include <string>
#include "../model/s21_aff_transform.h"
#include "../model/s21_parser_obj.h"
namespace s21 {

// Фасад
class Facade {
public:
  Facade() = default;
  Facade(const Facade&) = delete;
  Facade(Facade&&) = delete;
  ~Facade();
  Facade& operator=(const Facade&) = delete;
  Facade& operator=(Facade&&) = delete;
  void OpenObj(const std::string &file_name);
  void ResetObj();
  void RotateObj(char axis, double value);
  void ScaleObj(char axis, double value);
  void MoveObj(char axis, double value);
  const s21::ObjT& GetObject() {
    const s21::ObjT& ref_obj = main_obj_;
    return ref_obj;
  }
private:
  ObjT main_obj_;
  ObjT rotate_obj_;
  s21::ParserObj parcer_obj_;
};
} // namespace s21

#endif // SRC_S21_FACADE_H_
