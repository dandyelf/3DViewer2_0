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
    ~Object() {
        delete[] vertexes_;
        delete[] polygons_;
    }

    void setCountVertexes(int count) { count_of_vertexes_ = count; }
    void setCountFacets(int count) { count_of_facets_ = count; }
    void clear() {
        delete[] vertexes_;
        delete[] polygons_;
        vertexes_ = nullptr;
        polygons_ = nullptr;
    }
    void allocateVertexes() { vertexes_ = new double[count_of_vertexes_]; }
    void allocatePolygons() { polygons_ = new int[count_of_facets_]; }
    void pushVertex(double value, int index) { vertexes_[index] = value; }
    void pushPolygon(int value, int index) { polygons_[index] = value; }
    double* getVertexes() { return vertexes_; }
    const int* getPolygons() const { return polygons_; }
    int getCountVertexes() const { return count_of_vertexes_; }
    int getCountFacets() const { return count_of_facets_; }

private:
    int count_of_vertexes_ = 0;
    int count_of_facets_ = 0;
    double* vertexes_ = nullptr;
    int* polygons_ = nullptr;
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