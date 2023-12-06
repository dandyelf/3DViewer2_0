#ifndef CPP_S21_3DVIEWER_V2_SRC_MODEL_VIEWER_H_
#define CPP_S21_3DVIEWER_V2_SRC_MODEL_VIEWER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <string>
namespace s21 {

typedef struct {
  int count_of_vertexes{};
  double* vertexes{};
  int count_of_facets{};
  int* polygons{};
  int facet_elem{};
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
    int err = 0;
    int i = 0;
    int countvertex = 0, v_count = 0, countfacets = 0, cur_index = 0;
    char *temp_str, *token, *str1, *str2, *subtoken, *saveptr2, *tok;
    int temp_f = 0, temp_ind = 0;
};

}  // namespace s21

#endif // CPP_S21_3DVIEWER_V2_SRC_MODEL_VIEWER_H_