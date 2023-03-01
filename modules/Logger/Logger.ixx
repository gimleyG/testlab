module;

#include <string>

#define LOGGER_API __declspec(dllexport)

export module Logger;

export namespace Logger {

void LOGGER_API Write(std::string_view str);

}  // namespace Logger
