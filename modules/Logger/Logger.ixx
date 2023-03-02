module;
#define LOGGER_API __declspec(dllexport)

export module Logger;

import<format>;
import<iostream>;
import<string>;

export namespace Logger {

void LOGGER_API Write(std::string_view str);

template <typename... Args>
inline void LOGGER_API Write(std::string_view str, Args... args) {
  const auto toPrint = std::vformat(str, std::make_format_args(args...));
  std::cout << toPrint;
}

}  // namespace Logger
