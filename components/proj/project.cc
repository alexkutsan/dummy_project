#include "project.h"
#include <dlfcn.h>
#include "shared_lib/ishared_lib.h"
#include "utils/logger.h"

namespace dev {

CREATE_LOGGERPTR("Main");

template <typename T>
T GetFuncFromLib(void* dl_handle, const std::string& function_name) {
  T exported_func =
      reinterpret_cast<T>(dlsym(dl_handle, function_name.c_str()));
  char* error_string = dlerror();
  if (nullptr != error_string) {
    LOG_WITH_LEVEL(LogLevel::ERROR, "Failed to export symbols : ");
    return nullptr;
  }
  return exported_func;
}

int Project::run() {
  LOG_WITH_LEVEL(LogLevel::DEBUG, "Hello");
  LOG_WITH_LEVEL(LogLevel::ERROR, "Hello");
  auto library = dlopen("libSharedLib.so", RTLD_LAZY);
  if (!library) {
    LOG_WITH_LEVEL(LogLevel::FATAL, "SharedLib.so not opened");
    exit(1);
  };
  LOG_WITH_LEVEL(LogLevel::INFO, "SharedLib.so opened");
  typedef ISharedLib* (*Create)();
  Create create_plugin = GetFuncFromLib<Create>(library, "Create");
  LOG_WITH_LEVEL(LogLevel::INFO, "Create func found");
  auto lib_class = create_plugin();
  LOG_WITH_LEVEL(LogLevel::INFO, "class created");
  lib_class->library_function();
  return 0;
}

}  // namespace dev
