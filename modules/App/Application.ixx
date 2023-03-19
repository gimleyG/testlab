module;

#include <format>
#include <iostream>

export module Application;

import Logger;

namespace Details {

Log::Writer logWriter(std::cout);

}

export namespace Application {

void Main(int argc, char** argv) {
  using namespace Details;
  logWriter.Info(Log::Level{}, "App started");
  logWriter.Debug(Log::Level{}, std::format("Current time is {} ", "22:48"));
}

}  // namespace Application
