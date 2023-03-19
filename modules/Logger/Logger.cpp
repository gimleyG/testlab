module;

module Logger;

namespace Log {
class Writer::Impl {
 public:
  Impl(std::ostream& dst) : m_dest{dst} {}
  std::ostream& Dst() { return m_dest; }

  Impl& operator<<(std::string_view str) {
    m_dest << str << std::endl;
    return *this;
  }

 public:
  std::ostream& m_dest;
};

Writer::Writer(std::ostream& destination) : m_impl{new Impl(destination)} {}
Writer::~Writer() {
  if (m_impl) {
    delete m_impl;
  }
}

void Writer::Info(Level lvl, std::string_view str) { *m_impl << str; }

void Writer::Debug(Level lvl, std::string_view str) { *m_impl << str; }

void Writer::Warning(Level lvl, std::string_view str) { *m_impl << str; }

void Writer::Error(Level lvl, std::string_view str) { *m_impl << str; }

}  // namespace Log