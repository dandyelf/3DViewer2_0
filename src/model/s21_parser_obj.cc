#include "s21_parser_obj.h"

namespace s21 {

int ParserObj::ParseNumVertexFacets(const std::string &file_name, ObjT *obj) {
  err_ = 0;
  FILE *fp = fopen(file_name.c_str(), "r");
  if (fp == NULL) {
    err_ = 1;
  } else {
    char buffer[255];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
      if (buffer[0] == 'v' && buffer[1] == ' ') {
        obj->count_of_vertexes++;
      }
      if (buffer[0] == 'f' && buffer[1] == ' ') {
        obj->count_of_facets++;
        CountFacets(buffer, obj);
      }
    }
    fclose(fp);
  }
  obj->facet_elem *= 2;
  return err_;
}

void ParserObj::CountFacets(char *buffer, ObjT *obj) {
  char *tok = strtok(buffer, " ");
  while (tok != NULL) {
    if (*tok != 'f' && *tok != '\n') {
      obj->facet_elem++;
    }
    tok = strtok(NULL, " ");
  }
}

int ParserObj::InitObjStruct(ObjT *obj) {
  err_ = 0;
  obj->vertexes = new double[obj->count_of_vertexes * 3];
  if (obj->vertexes == nullptr) {
    err_ = 1;
    return err_;
  }
  obj->polygons = new int[obj->facet_elem];
  if (obj->polygons == nullptr) {
    delete[] obj->vertexes;  // Release memory allocated for vertexes
    err_ = 1;
    return err_;
  }
  return err_;
}

int ParserObj::ParseFile(const std::string &file_name, ObjT *obj) {
  err_ = 0;
  FILE *fp = fopen(file_name.c_str(), "r");
  if (fp == NULL) {
    err_ = 1;
  } else {
    char buffer[255];

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
      if (buffer[0] == 'v' && buffer[1] == ' ') {
        sscanf(buffer + 2, "%lf %lf %lf", &obj->vertexes[countvertex_],
               &obj->vertexes[countvertex_ + 1],
               &obj->vertexes[countvertex_ + 2]);
        countvertex_ += 3;
      }

      if (buffer[0] == 'f' && buffer[1] == ' ') {
        for (temp_ind_ = 0, str1_ = buffer + 2;; str1_ = NULL, temp_ind_++) {
          token_ = strtok_r(str1_, " ", &temp_str_);
          if (token_ == NULL) {
            obj->polygons[countfacets_++] = temp_f_;
            break;
          }
          if (!strpbrk(token_, "0123456789")) {
            obj->polygons[countfacets_++] = temp_f_;
            break;
          }
          for (str2_ = token_, v_count_ = 0;; str2_ = NULL, v_count_++) {
            subtoken_ = strtok_r(str2_, "/", &saveptr2_);
            if (subtoken_ == NULL) {
              break;
            } else if (v_count_ == 0) {
              cur_index_ = atoi(subtoken_) - 1;
              obj->polygons[countfacets_++] = cur_index_;
              if (temp_ind_ == 0) {
                temp_f_ = cur_index_;
              } else {
                obj->polygons[countfacets_++] = cur_index_;
              }
            }
          }
        }
      }
    }
    fclose(fp);
  }
  return err_;
}

int ParserObj::StartPars(const std::string &file_name, ObjT *obj) {
  err_ = 0;
  obj->count_of_vertexes = 0;
  obj->count_of_facets = 0;
  obj->facet_elem = 0;

  err_ = ParseNumVertexFacets(file_name, obj);

  if (!err_) {
    err_ = InitObjStruct(obj);
  }
  if (!err_) {
    err_ = ParseFile(file_name, obj);
  }
  for(int i = 0; i < obj->facet_elem; i++) {
    if(obj->polygons[i] < 0) {
      obj->polygons[i] = obj->count_of_facets + obj->polygons[i];
    }
  }
  return err_;
}

}  // namespace s21
