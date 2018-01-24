// #include <dlfcn.h>
// #include <iostream>
#include <src/node.h>

extern int node::Start(int, char**);

int main(int argc, char **argv) {
  // dlopen("libc++_shared.so", RTLD_LAZY);

  // std::cout << "start node" << "\n";

  return node::Start(argc, argv);
}
