#include "../graph/include/graph/node.hpp"

#include <iostream>

int main() {
  // Generate a graph of structure
  // Node 1              1           n → m : n has child m
  // ├─ Node 2 ─┐      ↙   ↘
  // └─ Node 3  │    2   ←   3
  //    └───────┘
  Node node_2(2);
  const Node::Nodes children_of_node_3{node_2};

  Node node_3(3, std::make_shared<Node::Nodes>(children_of_node_3));
  const Node::Nodes children_of_node_1{node_2, node_3};

  Node node(
      1, std::make_shared<Node::Nodes>(children_of_node_1));
  std::cout << node << std::endl;

  return EXIT_SUCCESS;
}
