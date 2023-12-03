#include "s21_parser_obj.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace s21 {

int ParserObj::ParseNumVertexFacets(const char* filename, Object* obj) {
  err = 0;
  FILE* fp = fopen(filename, "r");
  if (fp == NULL) {
    err = 1;
  } else {
    char buffer[255];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
      if (buffer[0] == 'v' && buffer[1] == ' ') {
        obj->setCountVertexes(obj->getCountVertexes() + 1);
      }
      if (buffer[0] == 'f' && buffer[1] == ' ') {
        obj->setCountFacets(obj->getCountFacets() + 1);
        CountFacets(buffer, obj);
      }
    }
  }
  obj->allocatePolygons();
  fclose(fp);
  return err;
}

void ParserObj::CountFacets(char* buffer, Object* obj) {
  i = 2;
  while (buffer[i] != '\0') {
    char* tok = strtok(buffer, " ");
    while (tok != NULL) {
      if (*tok != 'f' && *tok != '\n') {
        obj->pushPolygon(obj->getCountFacets(), obj->getCountFacets() - 1);
      }
      tok = strtok(NULL, " ");
    }
    ++i;
  }
}

int ParserObj::InitObjStruct(Object* obj) {
  err = 0;
  obj->allocateVertexes();
  if (obj->getVertexes() == nullptr) err = 1;
  return err;
}

int ParserObj::ParseFile(const char* filename, Object* obj) {
  err = 0;
  FILE* fp = fopen(filename, "r");
  if (fp == NULL) {
    err = 1;
  } else {
    char buffer[255];
    countvertex = 0, v_count = 0, countfacets = 0, cur_index = 0;
    temp_f = 0, temp_ind = 0;

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
      if (buffer[0] == 'v' && buffer[1] == ' ') {
        sscanf(buffer + 2, "%lf %lf %lf", &obj->getVertexes()[countvertex],
               &obj->getVertexes()[countvertex + 1],
               &obj->getVertexes()[countvertex + 2]);
        countvertex += 3;
      }

      if (buffer[0] == 'f' && buffer[1] == ' ') {
        for (temp_ind = 0, str1 = buffer + 2;; str1 = NULL, temp_ind++) {
          token = strtok_r(str1, " ", &temp_str);
          if (token == NULL) {
            obj->pushPolygon(temp_f, countfacets++);
            break;
          }
          if (!strpbrk(token, "0123456789")) {
            obj->pushPolygon(temp_f, countfacets++);
            break;
          }
          for (str2 = token, v_count = 0;; str2 = NULL, v_count++) {
            subtoken = strtok_r(str2, "/", &saveptr2);
            if (subtoken == NULL) {
              break;
            } else if (v_count == 0) {
              cur_index = atoi(subtoken) - 1;
              obj->pushPolygon(cur_index, countfacets++);
              if (temp_ind == 0) {
                temp_f = cur_index;
              } else {
                obj->pushPolygon(cur_index, countfacets++);
              }
            }
          }
        }
      }
    }
  }
  fclose(fp);
  return err;
}

int ParserObj::StartPars(const char* filename, Object* obj) {
  err = 0;
  obj->setCountVertexes(0);
  obj->setCountFacets(0);

  err = ParseNumVertexFacets(filename, obj);

  if (!err) {
    err = InitObjStruct(obj);
  }
  if (!err) {
    err = ParseFile(filename, obj);
  }
  return err;
}

}  // namespace s21