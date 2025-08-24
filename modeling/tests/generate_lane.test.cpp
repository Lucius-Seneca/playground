#include "../include/modeling/generate_lane.hpp"

#include <gtest/gtest.h>
#include <lanelet2_core/primitives/Lanelet.h>

TEST(GenerateLaneletTest, BasicTest) {
  lanelet::Id id = 1;
  std::vector<lanelet::Point3d> left_bound = {lanelet::Point3d(lanelet::utils::getId(), 0, 0, 0),
                                              lanelet::Point3d(lanelet::utils::getId(), 0, 1, 0)};
  std::vector<lanelet::Point3d> right_bound = {lanelet::Point3d(lanelet::utils::getId(), 1, 0, 0),
                                               lanelet::Point3d(lanelet::utils::getId(), 1, 1, 0)};
  lanelet::AttributeMap attributes;
  attributes["type"] = "road";

  lanelet::Lanelet lanelet = generateLanelet(id, left_bound, right_bound, attributes);

  EXPECT_EQ(lanelet.id(), id);
  EXPECT_EQ(lanelet.leftBound().size(), left_bound.size());
  EXPECT_EQ(lanelet.rightBound().size(), right_bound.size());
  EXPECT_EQ(lanelet.attributes().at("type"), "road");
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
