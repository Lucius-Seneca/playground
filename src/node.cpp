#include "../include/node.hpp"

#include <iostream>
#include <memory>
#include <optional>
#include <sstream>
#include <vector>

std::ostream& operator<<(std::ostream& os, Node const& node) {
  std::stringstream children_string{};
  if (node.children().empty()) {
    children_string << "Children: None";
  } else {
    children_string << "Children: [";
    for (const auto& successor : node.children()) {
      children_string << "(" << successor << ")";
    }
    children_string << "]";
  }
  return os << "Id: " << node.id() << ", " << children_string.str();
}
