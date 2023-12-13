#ifndef CPP_S21_3DVIEWER_V2_SRC_MODEL_S21_PARSER_OBJ_H_
#define CPP_S21_3DVIEWER_V2_SRC_MODEL_S21_PARSER_OBJ_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <string>
#include <fstream> 
namespace s21 {

typedef struct ObjT{
  int count_of_vertexes{};
  double* vertexes{};
  int count_of_facets{};
  int* polygons{};
  int facet_elem{};
  std::vector<int> polygon_vector{};
  std::vector<double> vertex_vector{};
  friend class Facade;
} ObjT;

class ParserObj {
public:
    ParserObj() noexcept = default;
    ParserObj(const ParserObj&) = delete;
    ParserObj(ParserObj&&) noexcept = delete;
    ~ParserObj() noexcept = default;
    void StartParser(const std::string& file_name, ObjT* obj);
    void ParsObj() noexcept;
    void VertexLineCheck() noexcept;
    void ParsLineVertex() noexcept;
    void FacetLineCheck() noexcept;
    std::string LineCreator(const std::string& dictionary) const noexcept;
    void ParsLineFacet(std::string& str) noexcept;
    void SortInsert(const std::vector<int>& in) noexcept;
    void PutOutVector(int a) noexcept;
private:
    ObjT *obj_;
    FILE *fp_;
};

}  // namespace s21

#endif // CPP_S21_3DVIEWER_V2_SRC_MODEL_S21_PARSER_OBJ_H_
