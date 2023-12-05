#include <iostream>

#include "../controller/s21_controller_obj.h"
#include "gtest/gtest.h"

TEST(ControllerTest, GetDataObj) {
    s21::Controller * controller_obj_ = nullptr;
    controller_obj_ = s21::Controller::getInstance();
    s21::Facade facade;
    const char* file = "/home/s21/3DViewer2_0/src/tests/obj/Low-Poly-Racing-Car.obj";
    controller_obj_->SetModel(&facade);
    controller_obj_->OpenObj(file);
    controller_obj_ = nullptr;
    EXPECT_EQ(controller_obj_, nullptr);   
    // EXPECT_EQ(facade.count_of_vertexes, 1485);
    // EXPECT_EQ(facade.count_of_facets, 2718); 
}

TEST(ControllerTest, GetData) {
    s21::Controller * controller_obj_ = nullptr;
    controller_obj_ = s21::Controller::getInstance();
    s21::Facade facade;
    // const char* file = "obj/Low-Poly-Racing-Car.obj";
    controller_obj_->SetModel(&facade);
    controller_obj_->MoveObj('x', 0.2);
    EXPECT_EQ(controller_obj_, nullptr);    
}