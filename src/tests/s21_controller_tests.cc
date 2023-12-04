#include <iostream>

#include "../controller/s21_controller_obj.h"
#include "gtest/gtest.h"

TEST(ControllerTest, GetDataObj) {
    s21::Controller * controller_obj_;
    controller_obj_ = s21::Controller::getInstance();
    
    EXPECT_EQ(controller_obj_, nullptr);    
}
