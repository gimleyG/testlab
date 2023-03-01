module;

#include <iostream>

module Logger;

namespace Logger {

void Write(std::string_view str) { std::cout << str << std::endl; }

}  // namespace Logger