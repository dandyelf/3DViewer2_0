#include <iostream>

#include "../controller/s21_controller_obj.h"
#include "gtest/gtest.h"

TEST(ControllerTest, GetDataObj) {
    s21::Controller * controller_obj_ = nullptr;
    controller_obj_ = s21::Controller::getInstance();
    s21::Facade facade;
    controller_obj_->SetModel(&facade);
    controller_obj_->OpenObj("obj/Low-Poly-Racing-Car.obj");
    EXPECT_EQ(controller_obj_, nullptr);    
}
