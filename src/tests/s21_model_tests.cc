#include <iostream>

#include "../model/s21_facade.h"
#include "gtest/gtest.h"

TEST(FacadeTest, GetDataObj) {
    s21::Facade a;
    a.OpenObj();
}
