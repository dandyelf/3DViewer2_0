#ifndef CPP_S21_3DVIEWER_V2_SRC_MODEL_VIEWER_H_
#define CPP_S21_3DVIEWER_V2_SRC_MODEL_VIEWER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

namespace s21 {

class Object {
public:
    Object() = default;
    Object(const Object&) = delete;
    Object(Object&&) = delete;
    ~Object() = default;

    void setCountVertex(int count) { count_of_vertexes_ = count; }
    void setCountPoligons(int count) { count_of_facets_ = count; }
    void clear() {
        vertexes_.clear();
        polygons_.clear();
    }
    void pushVetrexesPoint(double x, double y, double z) {
        vertexes_.push_back(x);
        vertexes_.push_back(y);
        vertexes_.push_back(z);
    }
    void pushPoligonsPoint(int num) { polygons_.push_back(num); }
    const std::vector<double>& getVertexes() const { return vertexes_; }
    const std::vector<int>& getPolygons() const { return polygons_; }
    int getCountVertexes() const { return count_of_vertexes_; }
    int getCountFacets() const { return count_of_facets_; }

private:
    int count_of_vertexes_ = 0;
    int count_of_facets_ = 0;
    std::vector<double> vertexes_;
    std::vector<int> polygons_;
};

class ParserObj {
public:
    ParserObj() = default;
    ParserObj(const ParserObj&) = delete;
    ParserObj(ParserObj&&) = delete;
    ~ParserObj() = default;

    int ParseNumVertexFacets(const char* filename, Object* obj);
    int InitObjStruct(Object* obj);
    int ParseFile(const char* filename, Object* obj);
    int StartPars(const char* filename, Object* obj);
    void CountFacets(char* buffer, Object* obj);

private:
    int err = 0;
    int i = 0;
    int countvertex = 0, v_count = 0, countfacets = 0, cur_index = 0;
    char *temp_str, *token, *str1, *str2, *subtoken, *saveptr2, *tok;
    int temp_f = 0, temp_ind = 0;
};

}  // namespace s21

#endif // CPP_S21_3DVIEWER_V2_SRC_MODEL_VIEWER_H_