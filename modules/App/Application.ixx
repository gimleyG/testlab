module;

#include <format>
#include <iostream>
#include <string>

export module Application;

import Logger;

export namespace Application {

void Main(int argc, char** argv) {
  Logger::Write("App started");
  Logger::Write("Current time is {} ", "22:48");
}

}  // namespace Application
