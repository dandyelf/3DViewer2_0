#include <iostream>

#include "../model/s21_facade_obj.h"
#include "gtest/gtest.h"

TEST(MainTest, Skull) {
  s21::ObjT obj;
  s21::ObjT obj2;
  s21::ParserObj parser;
  // const std::string file =
  // "/home/dandy/projects/3DViewer2_0/src/tests/obj/skull.obj";
  const std::string file =
      "/home/leftrana/projects/3DViewer2_0/src/tests/obj/cubecarcas.obj";
  try {
    parser.StartParser(file, &obj);
  } catch (const std::exception& e) {
    std::cout << e.what() << '\n';
  }
  // EXPECT_EQ(obj.count_of_facets, 9537);
  // delete [] obj.vertexes;
  // delete [] obj.polygons;
}
