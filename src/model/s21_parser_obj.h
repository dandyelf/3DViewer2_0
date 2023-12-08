#ifndef CPP_S21_3DVIEWER_V2_SRC_MODEL_S21_PARSER_OBJ_H_
#define CPP_S21_3DVIEWER_V2_SRC_MODEL_S21_PARSER_OBJ_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <string>
namespace s21 {

typedef struct ObjT{
  int count_of_vertexes{};
  double* vertexes{};
  int count_of_facets{};
  int* polygons{};
  int facet_elem{};
  friend class Facade;
} ObjT;

class ParserObj {
public:
    ParserObj() = default;
    ParserObj(const ParserObj&) = delete;
    ParserObj(ParserObj&&) = delete;
    ~ParserObj() = default;

    int ParseNumVertexFacets(const std::string &file_name, ObjT* obj);
    int InitObjStruct(ObjT* obj);
    int ParseFile(const std::string &file_name, ObjT* obj);
    int StartPars(const std::string &file_name, ObjT* obj);
    void CountFacets(char* buffer, ObjT* obj);

private:
    int err_ = 0;
    int countvertex_ = 0, v_count_ = 0, countfacets_ = 0, cur_index_ = 0;
    char *temp_str_, *token_, *str1_, *str2_, *subtoken_, *saveptr2_, *tok_;
    int temp_f_ = 0, temp_ind_ = 0;
};

}  // namespace s21

#endif // CPP_S21_3DVIEWER_V2_SRC_MODEL_S21_PARSER_OBJ_H_
