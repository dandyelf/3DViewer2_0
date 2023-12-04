#ifndef CPP_S21_3DVIEWER_V2_SRC_CONTROLLER_CONTROLLER_OBJ_H_
#define CPP_S21_3DVIEWER_V2_SRC_CONTROLLER_CONTROLLER_OBJ_H_

#include "../model/s21_facade_obj.h"

namespace s21 {
class Controller {
 public:
  Controller(const Controller&) = delete;
  Controller(Controller&&) = delete;
  ~Controller() = default;
  Controller& operator=(const Controller&) = delete;
  Controller& operator=(Controller&&) = delete;
  static Controller* getInstance() {
    static Controller controller;
    return &controller;
  }
  const s21::Object& GetObject() {
    return facade_.GetObject();
  }
  void OpenObj(std::string addres){facade_.OpenObj(addres);}
  void ResetObj(){facade_.ResetObj();}
  void RotateObj(char vector, double value){facade_.RotateObj(vector, value);}
  void ScaleObj(char vector, double value){facade_.ScaleObj(vector, value);}
  void MoveObj(char vector, double value){facade_.MoveObj(vector, value);}
 private:
  Controller() = default;
  static Controller* controller_;
  s21::Facade facade_;
};
}  // namespace s21

#endif  // CPP_S21_3DVIEWER_V2_SRC_CONTROLLER_CONTROLLER_OBJ_H_