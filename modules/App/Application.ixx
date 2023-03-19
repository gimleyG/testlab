module;

#include <format>
#include <iostream>

export module Application;

import Logger;

namespace Details {

Log::WriterHolder logWriter(std::cout);

}  // namespace Details

export namespace Application {

void Main(int argc, char** argv) {
  Log::Writer::Info(Log::Level{}, "App started");
  Log::Writer::Debug(Log::Level{}, std::format("Current time is {} ", "22:48"));
}

}  // namespace Application
