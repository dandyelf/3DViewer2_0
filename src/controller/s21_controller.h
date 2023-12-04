#ifndef CPP_S21_3DVIEWER_V2_SRC_CONTROLLER_CONTROLLER_H_
#define CPP_S21_3DVIEWER_V2_SRC_CONTROLLER_CONTROLLER_H_

#include <string>
#include "../model/s21_parser_obj.h"
#include "../model/s21_aff_transform.h"
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
  void setData(s21::obj_t* mod, ParserObj* parser, AffTransform* transform) {
    model_ = mod;
    parser_ = parser;
    transform_ = transform;
  }
  void setFilepath(const std::string & filepath) {
    parser_->StartPars(filepath.c_str(), model_);
    if (parser_->ParseNumVertexFacets(filepath.c_str(), model_) == 0) {
      transform_->InitObjStruct(model_);
      correct_ = true;
    } else {
      correct_ = false;
    }
  }
  obj_t GetObject() const { return model_; }
  void MoveX(double x) { transform_->MoveX(model_, x); };
  void MoveY(double y) { transform_->MoveY(model_, y); };
  void MoveZ(double z) { transform_->MoveZ(model_, z); };
  void TurnX(double rotate) { transform_->TurnX(model_, rotate); };
  void TurnY(double rotate) { transform_->TurnY(model_, rotate); };
  void TurnZ(double rotate) { transform_->TurnZ(model_, rotate); };
  void Scale(double size) { transform_->Scale(model_, size); };
  bool getCorrect() { return correct_; };
  int getCountVertexes() { return model_->getCountVertexes(); };
  int getCountLines() { return model_->getCountFacets(); };
 private:
  Controller() = default;
  static Controller* controller_;

  s21::obj_t model_ = std::nullptr_t;
  ParserObj* parser_ = nullptr;
  AffTransform* transform_ = nullptr;
  bool correct_ = false;
  s21::Facade facade_;
};
}  // namespace s21

#endif  // CPP_S21_3DVIEWER_V2_SRC_CONTROLLER_CONTROLLER_H_
