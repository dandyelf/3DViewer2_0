#include <gtest/gtest.h>

#include "../controller/s21_controller_obj.h"

namespace s21 {

TEST(MainTest, Cube) {
  s21::ObjT obj;
  s21::ParserObj parser;
  const std::string file = "./tests/obj/Low-Poly-Racing-Car.obj";
  parser.StartParser(file, &obj);
  EXPECT_EQ(obj.count_of_vertexes, 1485);
  EXPECT_EQ(obj.count_of_facets, 10608);
}

TEST(AffTransformTest, MoveX) {
  s21::ObjT obj;
  s21::AffTransform transform(&obj);
  obj.count_of_vertexes = 2;
  obj.count_of_facets = 0;
  obj.vertexes = new double[obj.count_of_vertexes * 3];
  obj.vertexes[0] = 1.0;
  obj.vertexes[1] = 2.0;
  obj.vertexes[2] = 3.0;
  obj.vertexes[3] = -1.0;
  obj.vertexes[4] = -2.0;
  obj.vertexes[5] = -3.0;
  transform.MoveX(2.0);
  const auto* vertexes = obj.vertexes;
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
  s21::AffTransform transform(&obj);
  obj.count_of_vertexes = 2;
  obj.count_of_facets = 0;
  obj.vertexes = new double[obj.count_of_vertexes * 3];
  obj.vertexes[0] = 1.0;
  obj.vertexes[1] = 2.0;
  obj.vertexes[2] = 3.0;
  obj.vertexes[3] = -1.0;
  obj.vertexes[4] = -2.0;
  obj.vertexes[5] = -3.0;
  transform.MoveY(3.0);
  const auto* vertexes = obj.vertexes;
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
  s21::AffTransform transform(&obj);
  obj.count_of_vertexes = 2;
  obj.count_of_facets = 0;
  obj.vertexes = new double[obj.count_of_vertexes * 3];
  obj.vertexes[0] = 1.0;
  obj.vertexes[1] = 2.0;
  obj.vertexes[2] = 3.0;
  obj.vertexes[3] = -1.0;
  obj.vertexes[4] = -2.0;
  obj.vertexes[5] = -3.0;
  transform.MoveZ(4.0);
  const auto* vertexes = obj.vertexes;
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
  s21::AffTransform transform(&obj);
  obj.count_of_vertexes = 2;
  obj.count_of_facets = 0;
  obj.vertexes = new double[obj.count_of_vertexes * 3];
  obj.vertexes[0] = 1.0;
  obj.vertexes[1] = 0.0;
  obj.vertexes[2] = 0.0;
  obj.vertexes[3] = 0.0;
  obj.vertexes[4] = 1.0;
  obj.vertexes[5] = 0.0;
  transform.TurnX(M_PI / 2.0);
  const auto* vertexes = obj.vertexes;
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
  s21::AffTransform transform(&obj);
  obj.count_of_vertexes = 2;
  obj.count_of_facets = 0;
  obj.vertexes = new double[obj.count_of_vertexes * 3];
  obj.vertexes[0] = 1.0;
  obj.vertexes[1] = 0.0;
  obj.vertexes[2] = 0.0;
  obj.vertexes[3] = 0.0;
  obj.vertexes[4] = 0.0;
  obj.vertexes[5] = 1.0;
  transform.TurnY(M_PI / 2.0);
  const auto* vertexes = obj.vertexes;
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
  s21::AffTransform transform(&obj);
  obj.count_of_vertexes = 2;
  obj.count_of_facets = 0;
  obj.vertexes = new double[obj.count_of_vertexes * 3];
  obj.vertexes[0] = 1.0;
  obj.vertexes[1] = 0.0;
  obj.vertexes[2] = 0.0;
  obj.vertexes[3] = 0.0;
  obj.vertexes[4] = 0.0;
  obj.vertexes[5] = 1.0;
  transform.TurnZ(M_PI / 2.0);
  const auto* vertexes = obj.vertexes;
  EXPECT_NEAR(vertexes[0], 0.999624216, 1e-6);
  EXPECT_NEAR(vertexes[1], -0.02741213, 1e-6);
  EXPECT_NEAR(vertexes[2], 0.0, 1e-6);
  EXPECT_NEAR(vertexes[3], 0.0, 1e-6);
  EXPECT_NEAR(vertexes[4], 0.0, 1e-6);
  EXPECT_NEAR(vertexes[5], 1.0, 1e-6);
  delete[] obj.vertexes;
}

TEST(AffTransformTest, ScaleX) {
  s21::ObjT obj;
  s21::AffTransform transform(&obj);
  obj.count_of_vertexes = 2;
  obj.count_of_facets = 0;
  obj.vertexes = new double[obj.count_of_vertexes * 3];
  obj.vertexes[0] = 1.0;
  obj.vertexes[1] = 0.0;
  obj.vertexes[2] = 0.0;
  obj.vertexes[3] = 0.0;
  obj.vertexes[4] = 0.0;
  obj.vertexes[5] = 1.0;
  transform.ScaleX(M_PI / 2.0);
  const auto* vertexes = obj.vertexes;
  EXPECT_NEAR(vertexes[0], 1.570796326, 1e-6);
  EXPECT_NEAR(vertexes[1], 0.0, 1e-6);
  EXPECT_NEAR(vertexes[2], 0.0, 1e-6);
  EXPECT_NEAR(vertexes[3], 0.0, 1e-6);
  EXPECT_NEAR(vertexes[4], 0.0, 1e-6);
  EXPECT_NEAR(vertexes[5], 1.0, 1e-6);
  delete[] obj.vertexes;
}

TEST(AffTransformTest, ScaleY) {
  s21::ObjT obj;
  s21::AffTransform transform(&obj);
  obj.count_of_vertexes = 2;
  obj.count_of_facets = 0;
  obj.vertexes = new double[obj.count_of_vertexes * 3];
  obj.vertexes[0] = 1.0;
  obj.vertexes[1] = 0.0;
  obj.vertexes[2] = 0.0;
  obj.vertexes[3] = 0.0;
  obj.vertexes[4] = 0.0;
  obj.vertexes[5] = 1.0;
  transform.ScaleY(M_PI / 2.0);
  const auto* vertexes = obj.vertexes;
  EXPECT_NEAR(vertexes[0], 1.0, 1e-6);
  EXPECT_NEAR(vertexes[1], 0.0, 1e-6);
  EXPECT_NEAR(vertexes[2], 0.0, 1e-6);
  EXPECT_NEAR(vertexes[3], 0.0, 1e-6);
  EXPECT_NEAR(vertexes[4], 0.0, 1e-6);
  EXPECT_NEAR(vertexes[5], 1.0, 1e-6);
  delete[] obj.vertexes;
}

TEST(AffTransformTest, ScaleZ) {
  s21::ObjT obj;
  s21::AffTransform transform(&obj);
  obj.count_of_vertexes = 3;
  obj.count_of_facets = 0;
  obj.vertexes = new double[obj.count_of_vertexes * 3];
  obj.vertexes[0] = 1.0;
  obj.vertexes[1] = 0.0;
  obj.vertexes[2] = 0.0;
  obj.vertexes[3] = 0.0;
  obj.vertexes[4] = 0.0;
  obj.vertexes[5] = 1.0;
  transform.ScaleZ(M_PI / 2.0);
  const auto* vertexes = obj.vertexes;
  EXPECT_NEAR(vertexes[0], 1, 1e-6);
  EXPECT_NEAR(vertexes[1], 0, 1e-6);
  EXPECT_NEAR(vertexes[2], 0.0, 1e-6);
  EXPECT_NEAR(vertexes[3], 0.0, 1e-6);
  EXPECT_NEAR(vertexes[4], 0.0, 1e-6);
  EXPECT_NEAR(vertexes[5], 1.570796326, 1e-6);
  delete[] obj.vertexes;
}

TEST(AffTransformTest, ChangeSize) {
  s21::ObjT obj;
  s21::AffTransform transform(&obj);
  obj.count_of_vertexes = 2;
  obj.count_of_facets = 0;
  obj.vertexes = new double[obj.count_of_vertexes * 3];
  obj.vertexes[0] = 1.0;
  obj.vertexes[1] = 2.0;
  obj.vertexes[2] = 3.0;
  obj.vertexes[3] = -1.0;
  obj.vertexes[4] = -2.0;
  obj.vertexes[5] = -3.0;
  transform.Scale(2.0);
  const auto* vertexes = obj.vertexes;
  EXPECT_DOUBLE_EQ(vertexes[0], 2.0);
  EXPECT_DOUBLE_EQ(vertexes[1], 4.0);
  EXPECT_DOUBLE_EQ(vertexes[2], 6.0);
  EXPECT_DOUBLE_EQ(vertexes[3], -2.0);
  EXPECT_DOUBLE_EQ(vertexes[4], -4.0);
  EXPECT_DOUBLE_EQ(vertexes[5], -6.0);
  delete[] obj.vertexes;
}

}  // namespace s21

// int main(int argc, char* argv[]) {
//   testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
// }
