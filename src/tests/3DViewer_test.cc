#include <stdio.h>
#include <string.h>

#include <cctype>
#include <cmath>
#include <cstring>
#include <string>

#include "../controller/s21_controller_obj.h"
#include <gtest/gtest.h>

namespace s21 {

TEST(MainTest, Cube) {
    s21::ObjT obj;
    s21::ParserObj parser;
    const char *file = "/home/s21/3DViewer2_0/src/tests/obj/Low-Poly-Racing-Car.obj";
    parser.StartPars(file, &obj);
    EXPECT_EQ(obj.count_of_vertexes, 1485);
    EXPECT_EQ(obj.count_of_facets, 2718);
}

TEST(AffTransformTest, MoveX) {
  s21::ObjT obj;
  s21::AffTransform transform;
  obj.count_of_vertexes = 6;
  obj.count_of_facets = 0;
  obj.vertexes = new double[obj.count_of_vertexes];
  obj.vertexes[0] = 1.0;
  obj.vertexes[1] = 2.0;
  obj.vertexes[2] = 3.0;
  obj.vertexes[3] = -1.0;
  obj.vertexes[4] = -2.0;
  obj.vertexes[5] = -3.0;
  transform.MoveX(&obj, 2.0);
  const double* vertexes = obj.vertexes;
  EXPECT_DOUBLE_EQ(vertexes[0], 3.0);
  EXPECT_DOUBLE_EQ(vertexes[1], 2.0);
  EXPECT_DOUBLE_EQ(vertexes[2], 3.0);
  EXPECT_DOUBLE_EQ(vertexes[3], 1.0);
  EXPECT_DOUBLE_EQ(vertexes[4], -2.0);
  EXPECT_DOUBLE_EQ(vertexes[5], -3.0);
  delete[] obj.vertexes;
}

TEST(AffTransformTest, MoveY) {
  s21::ObjT obj;
  s21::AffTransform transform;
  obj.count_of_vertexes = 6;
  obj.count_of_facets = 0;
  obj.vertexes = new double[obj.count_of_vertexes];
  obj.vertexes[0] = 1.0;
  obj.vertexes[1] = 2.0;
  obj.vertexes[2] = 3.0;
  obj.vertexes[3] = -1.0;
  obj.vertexes[4] = -2.0;
  obj.vertexes[5] = -3.0;
  transform.MoveY(&obj, 3.0);
  const double* vertexes = obj.vertexes;
  EXPECT_DOUBLE_EQ(vertexes[0], 1.0);
  EXPECT_DOUBLE_EQ(vertexes[1], 5.0);
  EXPECT_DOUBLE_EQ(vertexes[2], 3.0);
  EXPECT_DOUBLE_EQ(vertexes[3], -1.0);
  EXPECT_DOUBLE_EQ(vertexes[4], 1.0);
  EXPECT_DOUBLE_EQ(vertexes[5], -3.0);
  delete[] obj.vertexes;
}

TEST(AffTransformTest, MoveZ) {
  s21::ObjT obj;
  s21::AffTransform transform;
  obj.count_of_vertexes = 6;
  obj.count_of_facets = 0;
  obj.vertexes = new double[obj.count_of_vertexes];
  obj.vertexes[0] = 1.0;
  obj.vertexes[1] = 2.0;
  obj.vertexes[2] = 3.0;
  obj.vertexes[3] = -1.0;
  obj.vertexes[4] = -2.0;
  obj.vertexes[5] = -3.0;
  transform.MoveZ(&obj, 4.0);
  const double* vertexes = obj.vertexes;
  EXPECT_DOUBLE_EQ(vertexes[0], 1.0);
  EXPECT_DOUBLE_EQ(vertexes[1], 2.0);
  EXPECT_DOUBLE_EQ(vertexes[2], 7.0);
  EXPECT_DOUBLE_EQ(vertexes[3], -1.0);
  EXPECT_DOUBLE_EQ(vertexes[4], -2.0);
  EXPECT_DOUBLE_EQ(vertexes[5], 1.0);
  delete[] obj.vertexes;
}

TEST(AffTransformTest, TurnX) {
  s21::ObjT obj;
  s21::AffTransform transform;
  obj.count_of_vertexes = 6;
  obj.count_of_facets = 0;
  obj.vertexes = new double[obj.count_of_vertexes];
  obj.vertexes[0] = 1.0;
  obj.vertexes[1] = 0.0;
  obj.vertexes[2] = 0.0;
  obj.vertexes[3] = 0.0;
  obj.vertexes[4] = 1.0;
  obj.vertexes[5] = 0.0;
  transform.TurnX(&obj, M_PI / 2.0);
  const double* vertexes = obj.vertexes;
  EXPECT_NEAR(vertexes[0], 1.0, 1e-6);
  EXPECT_NEAR(vertexes[1], 0.0, 1e-6);
  EXPECT_NEAR(vertexes[2], 0.0, 1e-6);
  EXPECT_NEAR(vertexes[3], 0.0, 1e-6);
  EXPECT_NEAR(vertexes[4], 0.99962421685, 1e-6);
  EXPECT_NEAR(vertexes[5], -0.0274121335920, 1e-6);
  delete[] obj.vertexes;
}

TEST(AffTransformTest, TurnY) {
  s21::ObjT obj;
  s21::AffTransform transform;
  obj.count_of_vertexes = 6;
  obj.count_of_facets = 0;
  obj.vertexes = new double[obj.count_of_vertexes];
  obj.vertexes[0] = 1.0;
  obj.vertexes[1] = 0.0;
  obj.vertexes[2] = 0.0;
  obj.vertexes[3] = 0.0;
  obj.vertexes[4] = 0.0;
  obj.vertexes[5] = 1.0;
  transform.TurnY(&obj, M_PI / 2.0);
  const double* vertexes = obj.vertexes;
  EXPECT_NEAR(vertexes[0], 0.999624216859, 1e-6);
  EXPECT_NEAR(vertexes[1], 0.0, 1e-6);
  EXPECT_NEAR(vertexes[2], 0.0274121335920, 1e-6);
  EXPECT_NEAR(vertexes[3], -0.027412133592, 1e-6);
  EXPECT_NEAR(vertexes[4], 0.0, 1e-6);
  EXPECT_NEAR(vertexes[5], 0.9996242168, 1e-6);
  delete[] obj.vertexes;
}

TEST(AffTransformTest, TurnZ) {
  s21::ObjT obj;
  s21::AffTransform transform;
  obj.count_of_vertexes = 6;
  obj.count_of_facets = 0;
  obj.vertexes = new double[obj.count_of_vertexes];
  obj.vertexes[0] = 1.0;
  obj.vertexes[1] = 0.0;
  obj.vertexes[2] = 0.0;
  obj.vertexes[3] = 0.0;
  obj.vertexes[4] = 0.0;
  obj.vertexes[5] = 1.0;
  transform.TurnZ(&obj, M_PI / 2.0);
  const double* vertexes = obj.vertexes;
  EXPECT_NEAR(vertexes[0], 0.999624216, 1e-6);
  EXPECT_NEAR(vertexes[1], -0.02741213, 1e-6);
  EXPECT_NEAR(vertexes[2], 0.0, 1e-6);
  EXPECT_NEAR(vertexes[3], 0.0, 1e-6);
  EXPECT_NEAR(vertexes[4], 0.0, 1e-6);
  EXPECT_NEAR(vertexes[5], 1.0, 1e-6);
  delete[] obj.vertexes;
}

TEST(AffTransformTest, ChangeSize) {
  s21::ObjT obj;
  s21::AffTransform transform;
  obj.count_of_vertexes = 6;
  obj.count_of_facets = 0;
  obj.vertexes = new double[obj.count_of_vertexes];
  obj.vertexes[0] = 1.0;
  obj.vertexes[1] = 2.0;
  obj.vertexes[2] = 3.0;
  obj.vertexes[3] = -1.0;
  obj.vertexes[4] = -2.0;
  obj.vertexes[5] = -3.0;
  transform.Scale(&obj, 2.0);
  const double* vertexes = obj.vertexes;
  EXPECT_DOUBLE_EQ(vertexes[0], 2.0);
  EXPECT_DOUBLE_EQ(vertexes[1], 4.0);
  EXPECT_DOUBLE_EQ(vertexes[2], 6.0);
  EXPECT_DOUBLE_EQ(vertexes[3], -2.0);
  EXPECT_DOUBLE_EQ(vertexes[4], -4.0);
  EXPECT_DOUBLE_EQ(vertexes[5], -6.0);
  delete[] obj.vertexes;
}

}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}