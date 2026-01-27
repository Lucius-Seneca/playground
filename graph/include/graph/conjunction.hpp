#include <unordered_map>

#include "module.hpp"

#pragma once

class Conjunction : public Module {
 public:
  Conjunction(std::string given_id) : Module(std::move(given_id)) {}

  void addInput(const std::string& module_id) { m_inputs.insert({module_id, Impulse::kLow}); }

  void sendImpulse(const Impulse impulse, const std::string& module_id = std::string{}) override {
    m_inputs.at(module_id) = impulse;
    Impulse processed_impulse{Impulse::kLow};
    for (const auto& id_and_impulse : m_inputs) {
      if (id_and_impulse.second == Impulse::kLow) {
        processed_impulse = Impulse::kHigh;
      }
    }
    if (!m_connections.empty()) {
      for (auto& connection : m_connections) {
        count(processed_impulse);
        connection->sendImpulse(processed_impulse, m_id);
      }
    }
  }
  // Ungeklärt: Wie initialisiert man die Eingangsverbindungen
  // Schlange statt Rekursion bei sendImpulse
  // Testen

 private:
  std::unordered_map<std::string, Impulse> m_inputs{};
};
