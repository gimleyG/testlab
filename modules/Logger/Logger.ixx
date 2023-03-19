module;
#define LOGGER_API __declspec(dllexport)

export module Logger;

import<ostream>;
import<string>;

export namespace Log {

enum : uint32_t { WRITE_ALL = 0xFFFFFFFF };

class Level {
 public:
  explicit Level() : m_level{WRITE_ALL} {}
  explicit Level(uint32_t lvl) : m_level{lvl} {}

  bool Has(uint32_t flags) { return (m_level & flags) == flags; }

 private:
  uint32_t m_level;
};

class LOGGER_API Writer final {
 public:
  explicit Writer(std::ostream& destination);
  ~Writer() noexcept;

  void Info(Level lvl, std::string_view str);

  void Debug(Level lvl, std::string_view str);

  void Warning(Level lvl, std::string_view str);

  void Error(Level lvl, std::string_view str);

 private:
  class Impl;
  Impl* m_impl;
};

}  // namespace Log
