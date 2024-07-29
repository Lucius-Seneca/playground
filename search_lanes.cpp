#include <iostream>
#include <memory>
#include <optional>
#include <sstream>
#include <vector>

class LaneElement {
 public:
  LaneElement() = default;
  LaneElement(int const id) : m_id{id} {}
  LaneElement(int const id, std::vector<LaneElement> const& successors)
      : m_id{id}, m_successors{successors} {}

  LaneElement(LaneElement const& lane_element)
      : m_id{lane_element.id()}, m_successors{lane_element.successors()} {}

  int id() const { return m_id; }
  void id(int const id) { m_id = id; }

  std::vector<LaneElement> successors() const { return m_successors; }
  void successors(std::vector<LaneElement> successors) { m_successors = successors; }

 private:
  int m_id{};
  std::vector<LaneElement> m_successors{};
};

std::ostream& operator<<(std::ostream& os, LaneElement const& lane_element) {
  std::stringstream successors_string{};
  if (lane_element.successors().empty()) {
    successors_string << "Successors: None";
  } else {
    successors_string << "Successors: [";
    for (const auto& successor : lane_element.successors()) {
      successors_string << "(" << successor << ")";
    }
    successors_string << "]";
  }
  return os << "Id: " << lane_element.id() << ", " << successors_string.str();
}

int main() {
  LaneElement lane_element_successor_1(2);
  LaneElement lane_element_successor_2(3, std::vector<LaneElement>{lane_element_successor_1});
  LaneElement lane_element(
      1, std::vector<LaneElement>{lane_element_successor_1, lane_element_successor_2});
  std::cout << lane_element << std::endl;

  return EXIT_SUCCESS;
}