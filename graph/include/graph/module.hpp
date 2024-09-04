#include <memory>
#include <optional>
#include <string>
#include <utility>
#include <vector>

enum class Impulse { kHigh, kLow };

class Module {
 public:
  using ModulePtr = std::shared_ptr<Module>;
  using Modules = std::vector<ModulePtr>;

  Module(std::string given_id) : m_id{std::move(given_id)} {}
  Module(const Module& node) = default;                  // copy constructor
  Module(Module&& node) noexcept = default;              // move constructor
  Module& operator=(Module const& other) = default;      // copy assignment
  Module& operator=(Module&& other) noexcept = default;  // move assignment
  virtual ~Module() = default;

  [[nodiscard]] auto id() const -> std::string { return m_id; }
  void id(std::string const& given_id) { m_id = given_id; }

  [[nodiscard]] auto connections() const -> Modules { return m_connections; }
  void connections(Modules children) { m_connections = std::move(children); }

  virtual void sendImpulse(const Impulse impulse, [[maybe_unused]] const std::string& module_id = std::string{}) {
    Impulse processed_impulse = impulse;
    if (!m_connections.empty()) {
      for (auto& connection : m_connections) {
        count(processed_impulse);
        connection->sendImpulse(processed_impulse, m_id);
      }
    }
  }

  static void count(Impulse pulse) {
    if (pulse == Impulse::kHigh) {
      high_impulse_count++;
    } else {
      low_impulse_count++;
    }
  }

  // Funktion: Impuls schicken () -> Bearbeite deinen Eingangsimpuls, Eingangsimpuls ändern Connections, Impuls schicken
  // von Connections, Hochzählen

  // Kinder sind spezielle module mit eigener Eingangsimpulsverarbeitung und bei Connectionsmodulen noch die Liste der
  // Eingangspulse ev. map (Name:gespeicherterPulse)

  // Datei - Module Konstruieren
  // Starten 1000 mal

  static int high_impulse_count;
  static int low_impulse_count;

 protected:
  std::string m_id{};
  Impulse m_entry_impulse{};
  Modules m_connections{};
};

int Module::high_impulse_count = 0;
int Module::low_impulse_count = 0;

auto operator<<(std::ostream& out_stream, Module const& module) -> std::ostream&;
