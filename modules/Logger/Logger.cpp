module;

#include <iostream>
#include <mutex>
#include <optional>

module Logger;

namespace Log {
namespace {
class WriterImpl {
 public:
  WriterImpl(std::ostream& dst) : m_dest{dst} {}
  std::ostream& Dst() { return m_dest; }

  void ChangeLevel(Level lvl) { m_currentLevel = lvl; }

  void Write(Level lvl, std::string_view str) {
    if (!m_currentLevel.Has(lvl)) {
      return;
    }
    m_dest << str << std::endl;
  }

 private:
  std::ostream& m_dest;
  Level m_currentLevel;
};

using Lock = std::lock_guard<std::mutex>;
std::mutex writerSync;
std::optional<WriterImpl> writerImpl;

#define LOCK_N_CHECK             \
  const Lock l(writerSync);      \
  if (!writerImpl.has_value()) { \
    return;                      \
  }

}  // namespace

void Writer::Init(std::ostream& destination) {
  const Lock l(writerSync);
  if (writerImpl.has_value()) {
    return;
  }
  writerImpl.emplace(destination);
}

void Writer::SetLogLevel(Level lvl) {
  LOCK_N_CHECK;
  writerImpl->ChangeLevel(lvl);
}

void Writer::Destroy() {
  LOCK_N_CHECK;
  writerImpl.reset();
}

void Writer::Info(Level lvl, std::string_view str) {
  LOCK_N_CHECK;
  writerImpl->Write(lvl, str);
}

void Writer::Debug(Level lvl, std::string_view str) {
  LOCK_N_CHECK;
  writerImpl->Write(lvl, str);
}

void Writer::Warning(Level lvl, std::string_view str) {
  LOCK_N_CHECK;
  writerImpl->Write(lvl, str);
}

void Writer::Error(Level lvl, std::string_view str) {
  LOCK_N_CHECK;
  writerImpl->Write(lvl, str);
}

}  // namespace Log