#include <gtest/gtest.h>

#include <Eigen/Dense>

#include "../include/calculations/utils.hpp"

TEST(TransformTest, Basic) {
  const Eigen::Matrix3d rotation_part = Eigen::Matrix3d::Identity();
  const Eigen::Vector3d translation_part = Eigen::Vector3d::Zero();

  const Eigen::Isometry3d transform = createTransform(rotation_part, translation_part);

  EXPECT_EQ(transform.matrix(), Eigen::Isometry3d::Identity().matrix());
}
