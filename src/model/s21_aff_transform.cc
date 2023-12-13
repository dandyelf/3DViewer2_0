#include "s21_aff_transform.h"

namespace s21 {

void AffTransform::clear() noexcept {
  temp_x_ = temp_y_ = temp_z_ = 0;
  res_ = OK;
}

int AffTransform::Scale(double koff) noexcept {
  if (koff != 0.0) {
    for (int i = 0; i < obj_t_->count_of_vertexes * 3; i++) {
      obj_t_->vertexes[i] *= koff;
    }
  } else {
    res_ = ERR_ZERO;
  }
  return res_;
}

int AffTransform::ScaleX(double koff) noexcept {
  if (koff != 0.0) {
    for (int i = 0; i < obj_t_->count_of_vertexes * 3; i += 3) {
      obj_t_->vertexes[i] *= koff;
    }
  } else {
    res_ = ERR_ZERO;
  }
  return res_;
}

int AffTransform::ScaleY(double koff) noexcept {
  if (koff != 0.0) {
    for (int i = 1; i < obj_t_->count_of_vertexes * 3; i += 3) {
      obj_t_->vertexes[i] *= koff;
    }
  } else {
    res_ = ERR_ZERO;
  }
  return res_;
}

int AffTransform::ScaleZ(double koff) noexcept {
  if (koff != 0.0) {
    for (int i = 2; i < obj_t_->count_of_vertexes * 3; i += 3) {
      obj_t_->vertexes[i] *= koff;
    }
  } else {
    res_ = ERR_ZERO;
  }
  return res_;
}

void AffTransform::MoveX(double mv) noexcept {
  if (mv != 0.0) {
    for (int i = 0; i < obj_t_->count_of_vertexes * 3; i += 3) {
      obj_t_->vertexes[i] += mv;
    }
  }
}

void AffTransform::MoveY(double mv) noexcept {
  if (mv != 0.0) {
    for (int i = 1; i < obj_t_->count_of_vertexes * 3; i += 3) {
      obj_t_->vertexes[i] += mv;
    }
  }
}

void AffTransform::MoveZ(double mv) noexcept {
  if (mv != 0.0) {
    for (int i = 2; i < obj_t_->count_of_vertexes * 3; i += 3) {
      obj_t_->vertexes[i] += mv;
    }
  }
}

void AffTransform::TurnX(double angle) noexcept {
  if (angle != 0.0) {
    angle *= RAD_TO_GRAD;
    for (int i = 0; i < obj_t_->count_of_vertexes * 3; i += 3) {
      temp_y_ = obj_t_->vertexes[i + 1];
      temp_z_ = obj_t_->vertexes[i + 2];
      obj_t_->vertexes[i + 1] = temp_y_ * cos(angle) + temp_z_ * sin(angle);
      obj_t_->vertexes[i + 2] = -temp_y_ * sin(angle) + temp_z_ * cos(angle);
    }
  }
}

void AffTransform::TurnY(double angle) noexcept {
  if (angle != 0.0) {
    angle *= -RAD_TO_GRAD;
    for (int i = 0; i < obj_t_->count_of_vertexes * 3; i += 3) {
      temp_x_ = obj_t_->vertexes[i];
      temp_z_ = obj_t_->vertexes[i + 2];
      obj_t_->vertexes[i] = temp_x_ * cos(angle) + temp_z_ * sin(angle);
      obj_t_->vertexes[i + 2] = -temp_x_ * sin(angle) + temp_z_ * cos(angle);
    }
  }
}

void AffTransform::TurnZ(double angle) noexcept {
  if (angle != 0.0) {
    angle *= RAD_TO_GRAD;
    for (int i = 0; i < obj_t_->count_of_vertexes * 3; i += 3) {
      temp_x_ = obj_t_->vertexes[i];
      temp_y_ = obj_t_->vertexes[i + 1];
      obj_t_->vertexes[i] = temp_x_ * cos(angle) + temp_y_ * sin(angle);
      obj_t_->vertexes[i + 1] = -temp_x_ * sin(angle) + temp_y_ * cos(angle);
    }
  }
}

}  // namespace s21
