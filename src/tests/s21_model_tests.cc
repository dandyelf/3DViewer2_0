#include <iostream>

#include "../model/s21_facade_obj.h"
#include "gtest/gtest.h"

TEST(FacadeTest, GetDataObj) {
  s21::Facade a;
  a.OpenObj("./tests/obj/tetrahedron.obj");
}
