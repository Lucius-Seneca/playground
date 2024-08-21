#include "../include/graph/node.hpp"

#include <gtest/gtest.h>

TEST(NodeTest, Basic) {
  Node node_2(2);

  const Node::Nodes children_of_node_1{node_2};
  Node node_1(1, std::make_shared<Node::Nodes>(children_of_node_1));

  EXPECT_EQ(node_1.children()->front().id(), 2);
}
