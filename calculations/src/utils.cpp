#include "../include/calculations/utils.hpp"

#include <Eigen/Dense>

Eigen::Isometry3d createTransform(const Eigen::Matrix3d& rotation_part, const Eigen::Vector3d& translation_part) {
  Eigen::Isometry3d transform = Eigen::Isometry3d::Identity();
  transform.linear() = rotation_part;
  transform.translation() = translation_part;
  return transform;
}
