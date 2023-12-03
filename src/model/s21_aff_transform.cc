#include "s21_aff_transform.h"

namespace s21 {

int AffTransform::Scale(Object* obj, double koff) {
  int res = 0;
  if (koff != 0.0) {
    for (int i = 0; i < obj->getCountVertexes() * 3; i++) {
      obj->pushVertex(obj->getVertexes()[i] * koff, i);
    }
  } else {
    res = ERR_ZERO;
  }
  return res;
}

int AffTransform::ScaleX(Object* obj, double koff) {
  int res = 0;
  if (koff != 0.0) {
    for (int i = 0; i < obj->getCountVertexes() * 3; i += 3) {
      obj->pushVertex(obj->getVertexes()[i] * koff, i);
    }
  } else {
    res = ERR_ZERO;
  }
  return res;
}

int AffTransform::ScaleY(Object* obj, double koff) {
  int res = 0;
  if (koff != 0.0) {
    for (int i = 1; i < obj->getCountVertexes() * 3; i += 3) {
      obj->pushVertex(obj->getVertexes()[i] * koff, i);
    }
  } else {
    res = ERR_ZERO;
  }
  return res;
}

int AffTransform::ScaleZ(Object* obj, double koff) {
  int res = 0;
  if (koff != 0.0) {
    for (int i = 2; i < obj->getCountVertexes() * 3; i += 3) {
      obj->pushVertex(obj->getVertexes()[i] * koff, i);
    }
  } else {
    res = ERR_ZERO;
  }
  return res;
}

void AffTransform::MoveX(Object* obj, double mv) {
  if (mv != 0.0) {
    for (int i = 0; i < obj->getCountVertexes() * 3; i += 3) {
      obj->pushVertex(obj->getVertexes()[i] + mv, i);
    }
  }
}

void AffTransform::MoveY(Object* obj, double mv) {
  if (mv != 0.0) {
    for (int i = 1; i < obj->getCountVertexes() * 3; i += 3) {
      obj->pushVertex(obj->getVertexes()[i] + mv, i);
    }
  }
}

void AffTransform::MoveZ(Object* obj, double mv) {
  if (mv != 0.0) {
    for (int i = 2; i < obj->getCountVertexes() * 3; i += 3) {
      obj->pushVertex(obj->getVertexes()[i] + mv, i);
    }
  }
}

void AffTransform::TurnX(Object* obj, double angle) {
  if (angle != 0.0) {
    angle *= RAD_TO_GRAD;
    for (int i = 0; i < obj->getCountVertexes() * 3; i += 3) {
      double temp_y = obj->getVertexes()[i + 1];
      double temp_z = obj->getVertexes()[i + 2];
      obj->pushVertex(temp_y * cos(angle) + temp_z * sin(angle), i + 1);
      obj->pushVertex(-temp_y * sin(angle) + temp_z * cos(angle), i + 2);
    }
  }
}

void AffTransform::TurnY(Object* obj, double angle) {
  if (angle != 0.0) {
    angle *= -RAD_TO_GRAD;
    for (int i = 0; i < obj->getCountVertexes() * 3; i += 3) {
      double temp_x = obj->getVertexes()[i];
      double temp_z = obj->getVertexes()[i + 2];
      obj->pushVertex(temp_x * cos(angle) + temp_z * sin(angle), i);
      obj->pushVertex(-temp_x * sin(angle) + temp_z * cos(angle), i + 2);
    }
  }
}

void AffTransform::TurnZ(Object* obj, double angle) {
  if (angle != 0.0) {
    angle *= RAD_TO_GRAD;
    for (int i = 0; i < obj->getCountVertexes() * 3; i += 3) {
      double temp_x = obj->getVertexes()[i];
      double temp_y = obj->getVertexes()[i + 1];
      obj->pushVertex(temp_x * cos(angle) + temp_y * sin(angle), i);
      obj->pushVertex(-temp_x * sin(angle) + temp_y * cos(angle), i + 1);
    }
  }
}

}  // namespace s21
