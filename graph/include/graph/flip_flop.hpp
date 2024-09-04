#include "module.hpp"

#pragma once

class FlipFlop : public Module {
 public:
  FlipFlop(std::string given_id) : Module(std::move(given_id)) {}

  void sendImpulse(const Impulse impulse, [[maybe_unused]] const std::string& module_id = std::string{}) override {
    if (impulse == Impulse::kLow) {
      Impulse processed_impulse{};
      if (m_status) {
        processed_impulse = Impulse::kLow;
      } else {
        processed_impulse = Impulse::kHigh;
      }
      m_status = !m_status;
      if (!m_connections.empty()) {
        for (auto& connection : m_connections) {
          count(processed_impulse);
          connection->sendImpulse(processed_impulse, m_id);
        }
      }
    }
  }

 private:
  bool m_status{false};
};
