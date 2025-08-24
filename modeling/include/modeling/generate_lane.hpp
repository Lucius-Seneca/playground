#include <lanelet2_core/primitives/Lanelet.h>

#include <vector>

lanelet::Id k_current_lanelet_id = 0;

lanelet::Id getNextLaneletId() { return k_current_lanelet_id++; }

lanelet::Lanelet generateLanelet(const lanelet::Id id, const std::vector<lanelet::Point3d>& left_bound,
                                 const std::vector<lanelet::Point3d>& right_bound,
                                 const lanelet::AttributeMap& attributes);
