#include <memory>
#include <optional>
#include <sstream>
#include <vector>

class Node {
 public:
  using NodePtr = std::shared_ptr<Node>;
  using Nodes = std::vector<Node>;
  using NodesSPtr = std::shared_ptr<Nodes>;

  Node() = default;
  explicit Node(int const given_id);
  Node(int const given_id, NodesSPtr children);
  Node(const Node& node) = default;                          // copy constructor
  Node(Node&& node) noexcept = default;                      // move constructor
  auto operator=(Node const& other) -> Node& = default;      // copy assignment
  auto operator=(Node&& other) noexcept -> Node& = default;  // move assignment
  ~Node() = default;                                         // destructor

  [[nodiscard]] auto id() const -> int { return m_id; }
  void id(int const given_id) { m_id = given_id; }

  [[nodiscard]] auto children() const -> NodesSPtr { return m_children; }
  void children(NodesSPtr children) { m_children = std::move(children); }

 private:
  int m_id{};
  NodesSPtr m_children{};
};

std::ostream& operator<<(std::ostream& out_stream, Node const& node);
