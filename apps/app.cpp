#include "../include/node.hpp"

#include <iostream>

int main() {
  Node node_successor_1(2);
  Node node_successor_2(3, std::vector<Node>{node_successor_1});
  Node node(
      1, std::vector<Node>{node_successor_1, node_successor_2});
  std::cout << node << std::endl;

  return EXIT_SUCCESS;
}
