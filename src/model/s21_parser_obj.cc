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
  if(obj->polygons != nullptr) {
    delete [] obj->polygons;
  }
  if(obj->vertexes != nullptr) {
    delete [] obj->vertexes;
  }
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
    countvertex_ = 0, v_count_ = 0, countfacets_ = 0, cur_index_ = 0;
    temp_f_ = 0, temp_ind_ = 0;
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
          if (!strpbrk(token_, "-0123456789")) {
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
    obj->facet_elem = countfacets_;
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
  if (!err_) {
    for(int i = 0; i < obj->facet_elem; i++) {
      if(obj->polygons[i] < 0) {
        obj->polygons[i] = obj->count_of_facets + obj->polygons[i];
      }
    }
  }
  return err_;
}

void ParserObj::StartParser(const std::string &file_name, ObjT *obj) {
  obj_ = obj;
  file_.open(file_name);
  fp_ = fopen(file_name.c_str(), "r");
  if(!file_.is_open() || fp_ == NULL) {
    throw std::runtime_error("File fail");
  }
  obj->count_of_vertexes = 0;
  obj->count_of_facets = 0;
  obj->facet_elem = 0;
  ParsObj();
  if(obj_->vertex_vector.size() < 3 || obj_->polygon_vector.size() < 1) {
    fclose(fp_);
    throw std::runtime_error("Empty of fail file");
  }
  fclose(fp_);
  obj_->count_of_vertexes =  obj_->vertex_vector.size() / 3;
  obj_->count_of_facets = obj_->polygon_vector.size() / 3;
  obj_->facet_elem = obj_->polygon_vector.size();
  for (auto& value : obj_->polygon_vector) {
    if(value < 1) value += obj_->count_of_vertexes-1;
  }
  obj_->polygons = obj_->polygon_vector.data();
  obj_->vertexes = obj_->vertex_vector.data();
}

void ParserObj::ParsObj() {
  while (1) {
    char lineHeader[128];
    // read the first word of the line
    int res = fscanf(fp_, "%s", lineHeader);
    if (res == EOF) break;  // EOF = End Of File. Quit the loop.
    if (strcmp(lineHeader, "v") == 0) {
      VertexLineCheck();
    }
    if (strcmp(lineHeader, "f") == 0) {
      FacetLineCheck();
    }
  }
}

void ParserObj::VertexLineCheck() {
  ParsLineVertex();
}

void ParserObj::ParsLineVertex() {
  double x, y, z;
  int matches = fscanf(fp_, "%lf %lf %lf\n", &x, &y, &z);
  if(matches == 3) {
    obj_->vertex_vector.push_back(x);
    obj_->vertex_vector.push_back(y);
    obj_->vertex_vector.push_back(z);
  } else {
    fp_++;
  }
}

void ParserObj::FacetLineCheck() {
  std::string tmp = LineCreator("1234567890-/ ");
  // std::cout << lineHeader << tmp << "Parse: " << std::endl;
  ParsLineFacet(tmp);
}

std::string ParserObj::LineCreator(const std::string &dictionary){
  std::string tmp;
  char get = fgetc(fp_);
  while(dictionary.find(get) != std::string::npos && get != EOF) {
    tmp.push_back(get);
    get = fgetc(fp_);
  }
  return tmp;
}

void ParserObj::ParsLineFacet(std::string &str) {
  std::vector<std::string> tmp_vec;
  std::size_t i{};
  while(i < str.size()) {
  if(str[i] == ' ') {
    i++;
    continue;
  }
  std::string tmp;
  for(; i < str.size() && str[i] != ' '; i++) {
    tmp.push_back(str[i]);
  }
  tmp_vec.push_back(tmp);
  i++;
  }
  if(tmp_vec.size() > 2) {
    tmp_vec.push_back(tmp_vec[0]);
    for (const auto& str : tmp_vec) {
      int a = std::stoi(str);
      if(a > 0) {
        obj_->polygon_vector.push_back(a-1);
      }
      obj_->polygon_vector.push_back(a);
    }
  }
  // std::cout << std::endl;
}

}  // namespace s21
