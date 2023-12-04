
#ifndef SRC_S21_FACADE_H_
#define SRC_S21_FACADE_H_

// Подключение необходимых заголовочных файлов
#include "../model/s21_aff_transform.h"
#include "../model/s21_parser_obj.h"
namespace s21 {

// Фасад
class Facade {
public:
  void OpenObj(std::string addres){}
  void ResetObj(){}
  void RotateObj(char axes, double value){}
  void ScaleObj(char axes, double value){}
  void MoveObj(char axes, double value){}
  const s21::ObjT& GetObject() {
    const s21::ObjT& ref_obj = rotate_obj_;
    return ref_obj;
  }
private:
  ObjT main_obj_;
  ObjT rotate_obj_;
  s21::ParserObj parcer_obj_;
  s21::AffTransform aff_transform;
};
} // namespace s21

#endif // SRC_S21_FACADE_H_
