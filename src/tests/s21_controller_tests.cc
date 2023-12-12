#include <iostream>

#include "../controller/s21_controller_obj.h"
#include "gtest/gtest.h"

TEST(ControllerTest, GetDataObj) {
  s21::Controller* controller_obj_;
  controller_obj_ = s21::Controller::getInstance();
  s21::Facade facade;
  const char* file = "./tests/obj/tetrahedron.obj";
  controller_obj_->SetModel(&facade);
  controller_obj_->OpenObj(file);
  EXPECT_EQ(controller_obj_->GetObject().count_of_vertexes, 38);
  EXPECT_EQ(controller_obj_->GetObject().count_of_facets, 252);
}

TEST(ControllerTest, MoveX) {
  s21::Controller* controller_obj_;
  controller_obj_ = s21::Controller::getInstance();
  s21::Facade facade;
  const char* file = "./tests/obj/Low-Poly-Racing-Car.obj";
  controller_obj_->SetModel(&facade);
  controller_obj_->OpenObj(file);
  // EXPECT_EQ(controller_obj_->GetObject().vertexes[1], 2.11894);
  // EXPECT_EQ(controller_obj_->GetObject().vertexes[2], -5.04223);
  controller_obj_->MoveObj('x', 5.0);
  // EXPECT_EQ(controller_obj_->GetObject().vertexes[1], 2.11894);
  // EXPECT_EQ(controller_obj_->GetObject().vertexes[2], -5.04223);
}

TEST(ControllerTest, TurnX) {
  s21::Controller* controller_obj_;
  controller_obj_ = s21::Controller::getInstance();
  s21::Facade facade;
  const char* file = "./tests/obj/Low-Poly-Racing-Car.obj";
  controller_obj_->SetModel(&facade);
  controller_obj_->OpenObj(file);
  // EXPECT_EQ(controller_obj_->GetObject().vertexes[1], 2.11894);
  // EXPECT_EQ(controller_obj_->GetObject().vertexes[2], -5.04223);
  controller_obj_->RotateObj('x', 5.0);
  // EXPECT_EQ(controller_obj_->GetObject().vertexes[1], 1.67142);
  // EXPECT_EQ(controller_obj_->GetObject().vertexes[2], -5.20772);
}

TEST(ControllerTest, ScaleX) {
  s21::Controller* controller_obj_;
  controller_obj_ = s21::Controller::getInstance();
  s21::Facade facade;
  const char* file = "./tests/obj/Low-Poly-Racing-Car.obj";
  controller_obj_->SetModel(&facade);
  controller_obj_->OpenObj(file);
  // EXPECT_EQ(controller_obj_->GetObject().vertexes[1], 2.11894);
  // EXPECT_EQ(controller_obj_->GetObject().vertexes[2], -5.04223);
  controller_obj_->ScaleObj('x', 5.0);
  // EXPECT_EQ(controller_obj_->GetObject().vertexes[1], 2.11894);
  // EXPECT_EQ(controller_obj_->GetObject().vertexes[2], -5.04223);
}

TEST(ControllerTest, ChangeSize) {
  s21::Controller* controller_obj_;
  controller_obj_ = s21::Controller::getInstance();
  s21::Facade facade;
  const char* file = "./tests/obj/Low-Poly-Racing-Car.obj";
  controller_obj_->SetModel(&facade);
  controller_obj_->OpenObj(file);
  // EXPECT_EQ(controller_obj_->GetObject().vertexes[1], 2.11894);
  // EXPECT_EQ(controller_obj_->GetObject().vertexes[2], -5.04223);
  controller_obj_->ScaleObj('0', 5.0);
  // EXPECT_EQ(controller_obj_->GetObject().vertexes[1], 10.5947);
  // EXPECT_EQ(controller_obj_->GetObject().vertexes[2], -25.2112);
}