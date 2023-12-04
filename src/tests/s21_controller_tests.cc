#include <iostream>

#include "../controller/s21_controller_obj.h"
#include "gtest/gtest.h"

TEST(ControllerTest, GetDataObj) {
    s21::Controller * controller_obj_;
    controller_obj_ = s21::Controller::getInstance();
    int count_vertex = controller_obj_->GetObject().getCountVertexes();
    EXPECT_EQ(count_vertex, 0);
    int count_facets = controller_obj_->GetObject().getCountFacets();
    EXPECT_EQ(count_facets, 0);
    auto polygons = controller_obj_->GetObject().getPolygons();
    EXPECT_EQ(polygons, nullptr);    
}
