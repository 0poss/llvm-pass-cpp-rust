#include <iostream>

#include <llvm/Passes/PassBuilder.h>
#include <llvm/Passes/PassPlugin.h>

#include "project-rs.hpp"

using namespace llvm;

PassPluginLibraryInfo getPassPluginInfo() {
  return {LLVM_PLUGIN_API_VERSION, PROJECT_NAME "Pass", LLVM_VERSION_STRING,
          [](PassBuilder &PB) { hello_from_rust(); }};
}

extern "C" LLVM_ATTRIBUTE_WEAK ::llvm::PassPluginLibraryInfo
llvmGetPassPluginInfo() {
  return getPassPluginInfo();
}

extern "C" void hello_from_cpp() {
  std::cout << "hello, world! -- from a C++ function!\n";
}
