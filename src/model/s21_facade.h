
#ifndef SRC_S21_FACADE_H_
#define SRC_S21_FACADE_H_

// Подключение необходимых заголовочных файлов
#include "../model/s21_aff_transform.h"
#include "../model/s21_parser_obj.h"
namespace s21 {

// Фасад
class Facade {
public:
  void OpenObj(){}
private:
  s21::obj_t main_obj_;
  s21::obj_t ratate_obj_;
  s21::ParserObj parcer_obj_;
  s21::AffTransform aff_transform;
};
} // namespace s21

#endif // SRC_S21_FACADE_H_
