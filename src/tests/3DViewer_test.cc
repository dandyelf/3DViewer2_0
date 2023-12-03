#include <stdio.h>
#include <string.h>

#include <cctype>
#include <cmath>
#include <cstring>
#include <string>

#include "../controller/s21_controller.h"
#include <gtest/gtest.h>

namespace s21 {

TEST(MainTest, Cube) {
  s21::Object obj;
  s21::ParserObj parser;
  s21::AffTransform transform;
  parser.setObj("tests/cube.txt", &obj);
  s21::Controller::getInstance()->setData(&obj, &parser, &transform);
  EXPECT_EQ(obj.getCountLines(), 18);
  EXPECT_EQ(obj.getCountVertexes(), 8);
}

TEST(MainTest, EmptyCube) {
  s21::Object obj;
  s21::ParserObj parser;
  s21::AffTransform transform;
  parser.setObj("tests/empty_cube.txt", &obj);
  s21::Controller::getInstance()->setData(&obj, &parser, &transform);
  EXPECT_EQ(obj.getCountLines(), 0);
  EXPECT_EQ(obj.getCountVertexes(), 0);
}

TEST(AffTransformTest, MoveX) {
  s21::Object obj;
  s21::AffTransform transform(&obj);
  obj.pushVetrexesPoint(1.0, 2.0, 3.0);
  obj.pushVetrexesPoint(-1.0, -2.0, -3.0);
  transform.MoveX(2.0);
  const auto& vertexes = obj.getPoints()->vertexes_;
  EXPECT_DOUBLE_EQ(vertexes[0], 3.0);
  EXPECT_DOUBLE_EQ(vertexes[1], 2.0);
  EXPECT_DOUBLE_EQ(vertexes[2], 3.0);
  EXPECT_DOUBLE_EQ(vertexes[3], 1.0);
  EXPECT_DOUBLE_EQ(vertexes[4], -2.0);
  EXPECT_DOUBLE_EQ(vertexes[5], -3.0);
}

TEST(AffTransformTest, MoveY) {
  s21::Object obj;
  s21::AffTransform transform(&obj);
  obj.pushVetrexesPoint(1.0, 2.0, 3.0);
  obj.pushVetrexesPoint(-1.0, -2.0, -3.0);
  transform.MoveY(3.0);
  const auto& vertexes = obj.getPoints()->vertexes_;
  EXPECT_DOUBLE_EQ(vertexes[0], 1.0);
  EXPECT_DOUBLE_EQ(vertexes[1], 5.0);
  EXPECT_DOUBLE_EQ(vertexes[2], 3.0);
  EXPECT_DOUBLE_EQ(vertexes[3], -1.0);
  EXPECT_DOUBLE_EQ(vertexes[4], 1.0);
  EXPECT_DOUBLE_EQ(vertexes[5], -3.0);
}

TEST(AffTransformTest, MoveZ) {
  s21::Object obj;
  s21::AffTransform transform(&obj);
  obj.pushVetrexesPoint(1.0, 2.0, 3.0);
  obj.pushVetrexesPoint(-1.0, -2.0, -3.0);
  transform.MoveZ(4.0);
  const auto& vertexes = obj.getPoints()->vertexes_;
  EXPECT_DOUBLE_EQ(vertexes[0], 1.0);
  EXPECT_DOUBLE_EQ(vertexes[1], 2.0);
  EXPECT_DOUBLE_EQ(vertexes[2], 7.0);
  EXPECT_DOUBLE_EQ(vertexes[3], -1.0);
  EXPECT_DOUBLE_EQ(vertexes[4], -2.0);
  EXPECT_DOUBLE_EQ(vertexes[5], 1.0);
}

TEST(AffTransformTest, RotationX) {
  s21::Object obj;
  s21::AffTransform transform(&obj);
  obj.pushVetrexesPoint(1.0, 0.0, 0.0);
  obj.pushVetrexesPoint(0.0, 1.0, 0.0);
  transform.rotationX(M_PI / 2.0);
  const auto& vertexes = obj.getPoints()->vertexes_;
  EXPECT_NEAR(vertexes[0], 1.0, 1e-6);
  EXPECT_NEAR(vertexes[1], 0.0, 1e-6);
  EXPECT_NEAR(vertexes[2], 0.0, 1e-6);
  EXPECT_NEAR(vertexes[3], 0.0, 1e-6);
  EXPECT_NEAR(vertexes[4], 0.0, 1e-6);
  EXPECT_NEAR(vertexes[5], -1.0, 1e-6);
}

TEST(AffTransformTest, RotationY) {
  s21::Object obj;
  s21::AffTransform transform(&obj);
  obj.pushVetrexesPoint(1.0, 0.0, 0.0);
  obj.pushVetrexesPoint(0.0, 0.0, 1.0);
  transform.rotationY(M_PI / 2.0);
  const auto& vertexes = obj.getPoints()->vertexes_;
  EXPECT_NEAR(vertexes[0], 0.0, 1e-6);
  EXPECT_NEAR(vertexes[1], 0.0, 1e-6);
  EXPECT_NEAR(vertexes[2], -1.0, 1e-6);
  EXPECT_NEAR(vertexes[3], 1.0, 1e-6);
  EXPECT_NEAR(vertexes[4], 0.0, 1e-6);
  EXPECT_NEAR(vertexes[5], 0.0, 1e-6);
}

TEST(AffTransformTest, RotationZ) {
  s21::Object obj;
  s21::AffTransform transform(&obj);
  obj.pushVetrexesPoint(1.0, 0.0, 0.0);
  obj.pushVetrexesPoint(0.0, 1.0, 0.0);
  transform.rotationZ(M_PI / 2.0);
  const auto& vertexes = obj.getPoints()->vertexes_;
  EXPECT_NEAR(vertexes[0], 0.0, 1e-6);
  EXPECT_NEAR(vertexes[1], -1.0, 1e-6);
  EXPECT_NEAR(vertexes[2], 0.0, 1e-6);
  EXPECT_NEAR(vertexes[3], 1.0, 1e-6);
  EXPECT_NEAR(vertexes[4], 0.0, 1e-6);
  EXPECT_NEAR(vertexes[5], 0.0, 1e-6);
}

TEST(AffTransformTest, ChangeSize) {
  s21::Object obj;
  s21::AffTransform transform(&obj);
  obj.pushVetrexesPoint(1.0, 2.0, 3.0);
  obj.pushVetrexesPoint(-1.0, -2.0, -3.0);
  transform.changeSize(2.0);
  const auto& vertexes = obj.getPoints()->vertexes_;
  EXPECT_DOUBLE_EQ(vertexes[0], 2.0);
  EXPECT_DOUBLE_EQ(vertexes[1], 4.0);
  EXPECT_DOUBLE_EQ(vertexes[2], 6.0);
  EXPECT_DOUBLE_EQ(vertexes[3], -2.0);
  EXPECT_DOUBLE_EQ(vertexes[4], -4.0);
  EXPECT_DOUBLE_EQ(vertexes[5], -6.0);
}

TEST(AffTransformTest, Normalization) {
  s21::Object obj;

  obj.pushVetrexesPoint(1.0, 2.0, 3.0);
  obj.pushVetrexesPoint(2.0, 3.0, 4.0);
  obj.pushVetrexesPoint(3.0, 4.0, 5.0);

  obj.normalization();

  const auto& vertexes = obj.getPoints()->vertexes_;
  const std::vector<double> vertexes_test = {1.0, 2.0, 3.0,2.0, 3.0, 4.0,3.0, 4.0, 5.0};

  double expectedCentrX = (1.0 + 3.0) / 2.0;
  double expectedCentrY = (2.0 + 4.0) / 2.0;
  double expectedCentrZ = (3.0 + 5.0) / 2.0;

  double expectedMax = std::max((3.0 - 1.0), (4.0 - 2.0));
  expectedMax = std::max(expectedMax, (5.0 - 3.0));

  for (std::size_t i = 0; i < vertexes.size(); i += 3) {
    double normalizedX = (vertexes_test[i] - expectedCentrX) / expectedMax;
    double normalizedY = (vertexes_test[i + 1] - expectedCentrY) / expectedMax;
    double normalizedZ = (vertexes_test[i + 2] - expectedCentrZ) / expectedMax;
    EXPECT_NEAR(normalizedX, vertexes[i], 1e-6);
    EXPECT_NEAR(normalizedY, vertexes[i + 1], 1e-6);
    EXPECT_NEAR(normalizedZ, vertexes[i + 2], 1e-6);
  }
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

}