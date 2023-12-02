#include "s21_aff_transform.h"

namespace s21 {

int Viewer::Scale(obj_t *obj, double koff) {
  if (koff != 0.0) {
    for (i = 0; i < obj->count_of_vertexes * 3; i++) {
      obj->vertexes[i] *= koff;
    }
  } else {
    res = ERR_ZERO;
  }
  return res;
}

int Viewer::ScaleX(obj_t *obj, double koff) {
  if (koff != 0.0) {
    for (i = 0; i < obj->count_of_vertexes * 3; i += 3) {
      obj->vertexes[i] *= koff;
    }
  } else {
    res = ERR_ZERO;
  }
  return res;
}

int Viewer::ScaleY(obj_t *obj, double koff) {
  if (koff != 0.0) {
    for (i = 1; i < obj->count_of_vertexes * 3; i += 3) {
      obj->vertexes[i] *= koff;
    }
  } else {
    res = ERR_ZERO;
  }
  return res;
}

int Viewer::ScaleZ(obj_t *obj, double koff) {
  if (koff != 0.0) {
    for (i = 2; i < obj->count_of_vertexes * 3; i += 3) {
      obj->vertexes[i] *= koff;
    }
  } else {
    res = ERR_ZERO;
  }
  return res;
}

void Viewer::MoveX(obj_t *obj, double mv) {
  if (mv != 0.0) {
    for (i = 0; i < obj->count_of_vertexes * 3; i += 3) {
      obj->vertexes[i] += mv;
    }
  }
}

void Viewer::MoveY(obj_t *obj, double mv) {
  if (mv != 0.0) {
    for (i = 1; i < obj->count_of_vertexes * 3; i += 3) {
      obj->vertexes[i] += mv;
    }
  }
}

void Viewer::MoveZ(obj_t *obj, double mv) {
  if (mv != 0.0) {
    for (i = 2; i < obj->count_of_vertexes * 3; i += 3) {
      obj->vertexes[i] += mv;
    }
  }
}

// void shift_dot(obj_t* obj, dot_t dot) {
//   for (int i = 0; i < obj->count_of_vertexes * 3; i += 3) {
//     obj->vertexes[i] += dot.delta_x;
//     obj->vertexes[i + 1] += dot.delta_y;
//     obj->vertexes[i + 2] += dot.delta_z;
//   }
// }

void Viewer::TurnX(obj_t *obj, double angle) {
  if (angle != 0.0) {
    angle *= RAD_TO_GRAD;
    for (i = 0; i < obj->count_of_vertexes * 3; i += 3) {
      temp_y = obj->vertexes[i + 1];
      temp_z = obj->vertexes[i + 2];
      obj->vertexes[i + 1] = temp_y * cos(angle) + temp_z * sin(angle);
      obj->vertexes[i + 2] = -temp_y * sin(angle) + temp_z * cos(angle);
    }
  }
}

void Viewer::TurnY(obj_t *obj, double angle) {
  if (angle != 0.0) {
    angle *= -RAD_TO_GRAD;
    for (i = 0; i < obj->count_of_vertexes * 3; i += 3) {
      temp_x = obj->vertexes[i];
      temp_z = obj->vertexes[i + 2];
      obj->vertexes[i] = temp_x * cos(angle) + temp_z * sin(angle);
      obj->vertexes[i + 2] = -temp_x * sin(angle) + temp_z * cos(angle);
    }
  }
}

void Viewer::TurnZ(obj_t *obj, double angle) {
  if (angle != 0.0) {
    angle *= RAD_TO_GRAD;
    for (i = 0; i < obj->count_of_vertexes * 3; i += 3) {
      temp_x = obj->vertexes[i];
      temp_y = obj->vertexes[i + 1];
      obj->vertexes[i] = temp_x * cos(angle) + temp_y * sin(angle);
      obj->vertexes[i + 1] = -temp_x * sin(angle) + temp_y * cos(angle);
    }
  }
}

}
