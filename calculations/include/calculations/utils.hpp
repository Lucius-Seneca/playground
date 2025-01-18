#include <Eigen/Dense>

/// \brief Create a homogeneous transformation matrix from a rotation matrix and a translation vector.
/// \param[in] rotation_part The rotation part of the transformation.
/// \param[in] translation_part The translation part of the transformation.
Eigen::Isometry3d createTransform(const Eigen::Matrix3d& rotation_part, const Eigen::Vector3d& translation_part);
