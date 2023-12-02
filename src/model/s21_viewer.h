#ifndef CPP_S21_3DVIEWER_V2_SRC_MODEL_VIEWER_H_
#define CPP_S21_3DVIEWER_V2_SRC_MODEL_VIEWER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
namespace s21 {
typedef struct {
  int count_of_vertexes;
  double* vertexes;
  int count_of_facets;
  int* polygons;
  int facet_elem;
} obj_t;

class ReadFile {
  public:
    ReadFile() = default;
    ReadFile(const ReadFile&) = delete;
    ReadFile(ReadFile&&) = delete;
    ~ReadFile() = default;
    int ParseNumVertexFacets(const char* filename, obj_t* obj);
    int InitObjStruct(obj_t* obj);
    int ParseFile(const char* filename, obj_t* obj);
    int StartPars(const char* filename, obj_t* obj);
    void CountFacets(char* buffer, obj_t* obj);

  private:
    int err = 0;
    int i = 0;
    int countvertex = 0, v_count = 0, countfacets = 0, cur_index = 0;
    char *temp_str, *token, *str1, *str2, *subtoken, *saveptr2, *tok;
    int temp_f = 0, temp_ind = 0;

};
}
#endif // CPP_S21_3DVIEWER_V2_SRC_MODEL_VIEWER_H_
