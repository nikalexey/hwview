#include <iostream>
#include <signal.h>
#include "CFile.h"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << "using: hwview <file>" << std::endl;
    return 1;
  }
  std::cout << argv[1] << std::endl;

  CFile fl(argv[1]);
  size_t size = fl.getSize();
  std::cout << size << std::endl;

  return 0;
}