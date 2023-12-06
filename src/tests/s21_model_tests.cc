#include <iostream>

#include "../model/s21_facade_obj.h"
#include "gtest/gtest.h"

TEST(FacadeTest, GetDataObj) {
  s21::Facade a;
  a.OpenObj("");
  a.RotateObj('y', 0.2);
  a.ScaleObj('x', 0.2);
  a.MoveObj('z', 0.2);
}
