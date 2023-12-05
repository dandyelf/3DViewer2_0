#include <stdio.h>
#include <string.h>

#include <cctype>
#include <cmath>
#include <cstring>
#include <string>

#include "../model/s21_aff_transform.h"
#include "../model/s21_parser_obj.h"
#include <gtest/gtest.h>

namespace s21 {

TEST(MainTest, Cube) {
  s21::ObjT obj;
  s21::ParserObj parser;
  s21::AffTransform transform;
  parser.StartPars("obj/Low-Poly-Racing-Car.obj", &obj);
  s21::Controller::getInstance()->setData(&obj, &parser, &transform);
  EXPECT_EQ(obj.getCountFacets(), 18);
  EXPECT_EQ(obj.getCountVertexes(), 8);
}

TEST(MainTest, EmptyCube) {
  s21::ObjT obj;
  s21::ParserObj parser;
  s21::AffTransform transform;
  parser.StartPars("obj/Low-Poly-Racing-Car.obj", &obj);
  s21::Controller::getInstance()->setData(&obj, &parser, &transform);
  EXPECT_EQ(obj.getCountFacets(), 0);
  EXPECT_EQ(obj.getCountVertexes(), 0);
}

TEST(AffTransformTest, MoveX) {
  s21::ObjT obj;
  s21::AffTransform transform;
  transform.MoveX(&obj, 2.0);
  obj.setCountVertexes(6);
  obj.setCountFacets(0);
  obj.allocateVertexes();
  obj.pushVertex(1.0, 0);
  obj.pushVertex(2.0, 1);
  obj.pushVertex(3.0, 2);
  obj.pushVertex(-1.0, 3);
  obj.pushVertex(-2.0, 4);
  obj.pushVertex(-3.0, 5);

  const auto* vertexes = obj.getVertexes();
  EXPECT_DOUBLE_EQ(vertexes[0], 3.0);
  EXPECT_DOUBLE_EQ(vertexes[1], 2.0);
  EXPECT_DOUBLE_EQ(vertexes[2], 3.0);
  EXPECT_DOUBLE_EQ(vertexes[3], 1.0);
  EXPECT_DOUBLE_EQ(vertexes[4], -2.0);
  EXPECT_DOUBLE_EQ(vertexes[5], -3.0);
}

TEST(AffTransformTest, MoveZ) {
  s21::ObjT obj;
  s21::AffTransform transform;
  transform.MoveZ(&obj, 2.0);
  obj.setCountVertexes(6);
  obj.setCountFacets(0);
  obj.allocateVertexes();
  obj.pushVertex(1.0, 0);
  obj.pushVertex(2.0, 1);
  obj.pushVertex(3.0, 2);
  obj.pushVertex(-1.0, 3);
  obj.pushVertex(-2.0, 4);
  obj.pushVertex(-3.0, 5);

  const auto* vertexes = obj.getVertexes();
  EXPECT_DOUBLE_EQ(vertexes[0], 3.0);
  EXPECT_DOUBLE_EQ(vertexes[1], 2.0);
  EXPECT_DOUBLE_EQ(vertexes[2], 3.0);
  EXPECT_DOUBLE_EQ(vertexes[3], 1.0);
  EXPECT_DOUBLE_EQ(vertexes[4], -2.0);
  EXPECT_DOUBLE_EQ(vertexes[5], -3.0);
}

TEST(AffTransformTest, TurnX) {
  s21::ObjT obj;
  s21::AffTransform transform;
  transform.TurnX(&obj, 2.0);
  obj.setCountVertexes(6);
  obj.setCountFacets(0);
  obj.allocateVertexes();
  obj.pushVertex(1.0, 0);
  obj.pushVertex(0.0, 1);
  obj.pushVertex(0.0, 2);
  obj.pushVertex(0.0, 3);
  obj.pushVertex(1.0, 4);
  obj.pushVertex(0.0, 5);

  const auto* vertexes = obj.getVertexes();
  EXPECT_NEAR(vertexes[0], 1.0, 1e-6);
  EXPECT_NEAR(vertexes[1], 0.0, 1e-6);
  EXPECT_NEAR(vertexes[2], 0.0, 1e-6);
  EXPECT_NEAR(vertexes[3], 0.0, 1e-6);
  EXPECT_NEAR(vertexes[4], 0.0, 1e-6);
  EXPECT_NEAR(vertexes[5], -1.0, 1e-6);
}

TEST(AffTransformTest, TurnY) {
  s21::ObjT obj;
  s21::AffTransform transform;
  transform.TurnY(&obj, 2.0);
  obj.setCountVertexes(6);
  obj.setCountFacets(0);
  obj.allocateVertexes();
  obj.pushVertex(1.0, 0);
  obj.pushVertex(0.0, 1);
  obj.pushVertex(0.0, 2);
  obj.pushVertex(0.0, 3);
  obj.pushVertex(0.0, 4);
  obj.pushVertex(1.0, 5);

  const auto* vertexes = obj.getVertexes();
  EXPECT_NEAR(vertexes[0], 0.0, 1e-6);
  EXPECT_NEAR(vertexes[1], 0.0, 1e-6);
  EXPECT_NEAR(vertexes[2], -1.0, 1e-6);
  EXPECT_NEAR(vertexes[3], 1.0, 1e-6);
  EXPECT_NEAR(vertexes[4], 0.0, 1e-6);
  EXPECT_NEAR(vertexes[5], 0.0, 1e-6);
}

TEST(AffTransformTest, TurnZ) {
  s21::ObjT obj;
  s21::AffTransform transform;
  transform.TurnZ(&obj, 2.0);
  obj.setCountVertexes(6);
  obj.setCountFacets(0);
  obj.allocateVertexes();
  obj.pushVertex(1.0, 0);
  obj.pushVertex(0.0, 1);
  obj.pushVertex(0.0, 2);
  obj.pushVertex(0.0, 3);
  obj.pushVertex(1.0, 4);
  obj.pushVertex(0.0, 5);

  const auto* vertexes = obj.getVertexes();
  EXPECT_NEAR(vertexes[0], 0.0, 1e-6);
  EXPECT_NEAR(vertexes[1], -1.0, 1e-6);
  EXPECT_NEAR(vertexes[2], 0.0, 1e-6);
  EXPECT_NEAR(vertexes[3], 1.0, 1e-6);
  EXPECT_NEAR(vertexes[4], 0.0, 1e-6);
  EXPECT_NEAR(vertexes[5], 0.0, 1e-6);
}

TEST(AffTransformTest, ChangeSize) {
  s21::ObjT obj;
  s21::AffTransform transform;
  transform.Scale(&obj, 2.0);
  obj.setCountVertexes(6);
  obj.setCountFacets(0);
  obj.allocateVertexes();
  obj.pushVertex(1.0, 0);
  obj.pushVertex(2.0, 1);
  obj.pushVertex(3.0, 2);
  obj.pushVertex(-1.0, 3);
  obj.pushVertex(-2.0, 4);
  obj.pushVertex(-3.0, 5);

  const auto* vertexes = obj.getVertexes();
  EXPECT_DOUBLE_EQ(vertexes[0], 2.0);
  EXPECT_DOUBLE_EQ(vertexes[1], 4.0);
  EXPECT_DOUBLE_EQ(vertexes[2], 6.0);
  EXPECT_DOUBLE_EQ(vertexes[3], -2.0);
  EXPECT_DOUBLE_EQ(vertexes[4], -4.0);
  EXPECT_DOUBLE_EQ(vertexes[5], -6.0);
}

}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}