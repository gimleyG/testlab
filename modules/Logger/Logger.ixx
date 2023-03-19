module;
#define LOGGER_API __declspec(dllexport)

#include <ostream>
#include <string>

export module Logger;

export namespace Log {

enum : uint32_t { WRITE_ALL = 0xFFFFFFFF };

class Level {
 public:
  explicit Level() : m_value{WRITE_ALL} {}
  explicit Level(uint32_t lvl) : m_value{lvl} {}

  bool Has(Level lvl) { return (m_value & lvl.m_value) == lvl.m_value; }

 private:
  uint32_t m_value;
};

class LOGGER_API Writer final {
 public:
  static void Init(std::ostream& destination);

  static void SetLogLevel(Level lvl);

  static void Destroy();

  static void Info(Level lvl, std::string_view str);

  static void Debug(Level lvl, std::string_view str);

  static void Warning(Level lvl, std::string_view str);

  static void Error(Level lvl, std::string_view str);
};

class LOGGER_API WriterHolder final {
 public:
  WriterHolder(std::ostream& destination) { Writer::Init(destination); }
  ~WriterHolder() { Writer::Destroy(); }
};

}  // namespace Log
