#include "../include/modeling/generate_lane.hpp"

#include <lanelet2_core/primitives/Lanelet.h>

#include <vector>

lanelet::Lanelet generateLanelet(const lanelet::Id id, const std::vector<lanelet::Point3d>& left_bound,
                                 const std::vector<lanelet::Point3d>& right_bound,
                                 const lanelet::AttributeMap& attributes) {
  lanelet::LineString3d left_ls(getNextLaneletId(), left_bound);
  lanelet::LineString3d right_ls(getNextLaneletId(), right_bound);

  return lanelet::Lanelet(id, left_ls, right_ls, attributes);
}
