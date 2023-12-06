#include "s21_parser_obj.h"

namespace s21 {

int ParserObj::ParseNumVertexFacets(const std::string &file_name, ObjT *obj) {
  err = 0;
  FILE *fp = fopen(file_name.c_str(), "r");
  if (fp == NULL) {
    err = 1;
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
  return err;
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
  err = 0;
  obj->vertexes = new double[obj->count_of_vertexes * 3];
  if (obj->vertexes == nullptr) {
    err = 1;
    return err;
  }
  obj->polygons = new int[obj->facet_elem];
  if (obj->polygons == nullptr) {
    delete[] obj->vertexes;  // Release memory allocated for vertexes
    err = 1;
    return err;
  }
  return err;
}



int ParserObj::ParseFile(const std::string &file_name, ObjT *obj) {
  err = 0;
  FILE *fp = fopen(file_name.c_str(), "r");
  if (fp == NULL) {
    err = 1;
  } else {
    char buffer[255];
    int countvertex = 0, v_count = 0, countfacets = 0, cur_index = 0;
    int temp_f = 0, temp_ind = 0;

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
      if (buffer[0] == 'v' && buffer[1] == ' ')  {
        sscanf(buffer + 2, "%lf %lf %lf", &obj->vertexes[countvertex],
               &obj->vertexes[countvertex + 1],
               &obj->vertexes[countvertex + 2]);
        countvertex += 3;
      }

      if (buffer[0] == 'f' && buffer[1] == ' ')  {
        for (temp_ind = 0, str1 = buffer + 2;; str1 = NULL, temp_ind++) {
          token = strtok_r(str1, " ", &temp_str);
          if (token == NULL) {
            obj->polygons[countfacets++] = temp_f;
            break;
          }
          if (!strpbrk(token, "0123456789")) {
            obj->polygons[countfacets++] = temp_f;
            break;
          }
          for (str2 = token, v_count = 0;; str2 = NULL, v_count++) {
            subtoken = strtok_r(str2, "/", &saveptr2);
            if (subtoken == NULL) {
              break;
            } else if (v_count == 0) {
              cur_index = atoi(subtoken) - 1;
              obj->polygons[countfacets++] = cur_index;
              if (temp_ind == 0) {
                temp_f = cur_index;
              } else {
                obj->polygons[countfacets++] = cur_index;
              }
            }
          }
        }
      }
    }
    fclose(fp);
  }
  return err;
}

int ParserObj::StartPars(const std::string &file_name, ObjT *obj) {
  err = 0;
  obj->count_of_vertexes = 0;
  obj->count_of_facets = 0;
  obj->facet_elem = 0;

  err = ParseNumVertexFacets(file_name, obj);

  if (!err) {
    err = InitObjStruct(obj);
  }
  if (!err) {
    err = ParseFile(file_name, obj);
  }
  return err;
}

}  // namespace s21