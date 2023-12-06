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
  void SetModel(s21::Facade* facade) { facade_ = facade; }
  const s21::ObjT& GetObject() { return facade_->GetObject(); }
  void OpenObj(const char* file_name) { facade_->OpenObj(file_name); }
  void ResetObj() { facade_->ResetObj(); }
  void RotateObj(char axis, double value) { facade_->RotateObj(axis, value); }
  void ScaleObj(char axis, double value) { facade_->ScaleObj(axis, value); }
  void MoveObj(char axis, double value) { facade_->MoveObj(axis, value); }

 private:
  Controller() = default;
  static Controller* controller_;
  s21::Facade* facade_;
};
}  // namespace s21

#endif  // CPP_S21_3DVIEWER_V2_SRC_CONTROLLER_CONTROLLER_OBJ_H_