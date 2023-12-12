#include <iostream>

#include "../model/s21_facade_obj.h"
#include "gtest/gtest.h"

TEST(MainTest, Skull) {
  s21::ObjT obj;
  s21::ObjT obj2;
  s21::ParserObj parser;
  const std::string file = "./tests/obj/cubecarcas.obj";
  try {
    parser.StartParser(file, &obj);
  } catch (const std::exception& e) {
    std::cout << e.what() << '\n';
  }
  // EXPECT_EQ(obj.count_of_facets, 9537);
}
