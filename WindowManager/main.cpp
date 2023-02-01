// 1- create window manager 
// 2- run window manager 

#include <iostream>
#include <glog/logging.h>
#include "window_manager.hpp"

using ::std::unique_ptr;

int main(int argc, char** argv) {

  WindowManager* windowManager = WindowManager::getWindowManager();
  windowManager->Run();

  return EXIT_SUCCESS;
}
