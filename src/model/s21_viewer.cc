#include "s21_viewer.h"

namespace s21 {

int ReadFile::ParseNumVertexFacets(const char *filename, obj_t *obj) {
  err = 0;
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    err = 1;
  } else {
    char buffer[255];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
      if (buffer[0] == 'v' && buffer[1] == ' ') {
        obj->count_of_vertexes += 1;
      }
      if (buffer[0] == 'f' && buffer[1] == ' ') {
        obj->count_of_facets += 1;
        CountFacets(buffer, obj);
      }
    }
  }
  obj->facet_elem *= 2;
  fclose(fp);
  return err;
}

void ReadFile::CountFacets(char *buffer, obj_t *obj) {
  i = 2;
  while (buffer[i] != '\0') {
    *tok = strtok(buffer, " ");
    while (tok != NULL) {
      if (*(tok) != 'f' && *(tok) != '\n') {
        obj->facet_elem++;
      }
      tok = strtok(NULL, " ");
    }
    ++i;
  }
}

int ReadFile::InitObjStruct(obj_t *obj) {
  err = 0;
  obj->vertexes = (double *)calloc(obj->count_of_vertexes * 3, sizeof(double));
  if (obj->vertexes == NULL) err = 1;
  obj->polygons = (int *)calloc(obj->facet_elem, sizeof(int));
  if (obj->polygons == NULL) err = 1;
  return err;
}

int ReadFile::ParseFile(const char *filename, obj_t *obj) {
  err = 0;
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    err = 1;
  } else {
    char buffer[255];
    countvertex = 0, v_count = 0, countfacets = 0, cur_index = 0;
    *temp_str, *token, *str1, *str2, *subtoken, *saveptr2;
    temp_f = 0, temp_ind = 0;

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
      if (buffer[0] == 'v' && buffer[1] == ' ') {
        sscanf(buffer + 2, "%lf %lf %lf", &obj->vertexes[countvertex],
               &obj->vertexes[countvertex + 1],
               &obj->vertexes[countvertex + 2]);
        countvertex += 3;
      }

      if (buffer[0] == 'f' && buffer[1] == ' ') {
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
  }
  fclose(fp);
  return err;
}

int ReadFile::StartPars(const char *filename, obj_t *obj) {
  err = 0;
  obj->count_of_vertexes = 0;
  obj->count_of_facets = 0;
  obj->facet_elem = 0;

  err = ParseNumVertexFacets(filename, obj);

  if (!err) {
    err = InitObjStruct(obj);
  }
  if (!err) {
    err = ParseFile(filename, obj);
  }
  return err;
}

}