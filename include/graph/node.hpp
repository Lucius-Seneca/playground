#include <memory>
#include <optional>
#include <vector>

class Node {
 public:
  Node() = default;
  Node(int const id) : m_id{id} {}
  Node(int const id, std::vector<Node> const& children)
      : m_id{id}, m_children{children} {}

  Node(Node const& node)
      : m_id{node.id()}, m_children{node.children()} {}

  int id() const { return m_id; }
  void id(int const id) { m_id = id; }

  std::vector<Node> children() const { return m_children; }
  void children(std::vector<Node> children) { m_children = children; }

 private:
  int m_id{};
  std::vector<Node> m_children{};
};

std::ostream& operator<<(std::ostream& os, Node const& node);
