#include "../include/graph/node.hpp"

#include <iostream>
#include <memory>
#include <optional>
#include <sstream>
#include <vector>

auto operator<<(std::ostream& out_stream, Node const& node) -> std::ostream& {
  std::stringstream children_string{};
  if (node.children() == nullptr || node.children()->empty()) {
    children_string << "Children: None";
  } else {
    children_string << "Children: [";
    for (const auto& successor : *(node.children())) {
      children_string << "(" << successor << ")";
    }
    children_string << "]";
  }
  return out_stream << "Id: " << node.id() << ", " << children_string.str();
}
