#include <memory>
#include <optional>
#include <vector>

class Node {
 public:
  using NodePtr = std::shared_ptr<Node>;
  using Nodes = std::vector<Node>;
  using NodesSPtr = std::shared_ptr<Nodes>;

  Node() = default;
  Node(int const id) : m_id{id} {}
  Node(int const id, NodesSPtr children) : m_id{id}, m_children{std::move(children)} {}

  Node(Node const& node) : m_id{node.id()}, m_children{node.children()} {}

  [[nodiscard]] auto id() const -> int { return m_id; }
  void id(int const id) { m_id = id; }

  [[nodiscard]] auto children() const -> NodesSPtr { return m_children; }
  void children(NodesSPtr children) { m_children = std::move(children); }

 private:
  int m_id{};
  NodesSPtr m_children{};
};

auto operator<<(std::ostream& out_stream, Node const& node) -> std::ostream&;
