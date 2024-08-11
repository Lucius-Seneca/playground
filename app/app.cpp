#include "../graph/include/graph/node.hpp"

#include <iostream>

int main() {
  Node node_successor_1(2);
  const Node::Nodes successor{node_successor_1};
  Node node_successor_2(3, std::make_shared<Node::Nodes>(successor));
  const Node::Nodes successors{node_successor_1, node_successor_2};
  Node node(
      1, std::make_shared<Node::Nodes>(successors));
  std::cout << node << std::endl;

  return EXIT_SUCCESS;
}
