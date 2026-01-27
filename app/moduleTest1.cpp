#include <iostream>
#include <memory>
#include <ostream>

#include "../graph/include/graph/module.hpp"

auto main() -> int {
  Module::ModulePtr m1 = std::make_shared<Module>("m1");
  Module::ModulePtr m2 = std::make_shared<Module>("m2");
  Module::ModulePtr m3 = std::make_shared<Module>("m3");
  Module::ModulePtr m4 = std::make_shared<Module>("m4");

  Module::Modules liste1 = {m2, m3};
  Module::Modules liste2 = {m4};
  m1->connections(liste1);
  m3->connections(liste2);
  m1->sendImpulse(Impulse::kHigh);
  std::cout << "Niedrige Pulse: " << Module::low_impulse_count << "\nHohe Pulse: " << Module::high_impulse_count
            << std::endl;

  return EXIT_SUCCESS;
}
