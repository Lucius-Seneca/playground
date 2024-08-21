#include <memory>
#include <optional>
#include <vector>

class Node {
 public:
  using NodePtr = std::shared_ptr<Node>;
  using Nodes = std::vector<Node>;
  using NodesSPtr = std::shared_ptr<Nodes>;

  Node() = default;
  Node(int const given_id) : m_id{given_id} {}
  Node(int const given_id, NodesSPtr children) : m_id{given_id}, m_children{std::move(children)} {}
  Node(const Node& node) : m_id{node.id()}, m_children{node.children()} {}                 // copy constructor
  Node(Node&& node) noexcept : m_id{node.id()}, m_children{std::move(node.children())} {}  // move constructor
  auto operator=(Node const& other) -> Node&;                                              // copy assignment
  auto operator=(Node&& other) noexcept -> Node&;                                          // move assignment
  ~Node() = default;                                                                       // destructor

  [[nodiscard]] auto id() const -> int { return m_id; }
  void id(int const given_id) { m_id = given_id; }

  [[nodiscard]] auto children() const -> NodesSPtr { return m_children; }
  void children(NodesSPtr children) { m_children = std::move(children); }

 private:
  int m_id{};
  NodesSPtr m_children{};
};

auto operator<<(std::ostream& out_stream, Node const& node) -> std::ostream&;
