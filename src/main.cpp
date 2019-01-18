#include <iostream>
#include "file.h"
#include <iomanip>

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << "using: hxview <file>" << std::endl;
    return 1;
  }
  CFile fl(argv[1]);
  uint8_t* data = fl.getData();
  size_t data_size = fl.getSize();
  for (size_t i = 0; i < data_size; ++i) {
    if (i != 0 && i%16 == 0) {
      std::cout << "\n";
    }
    std::cout << std::hex << std::setfill('0') << std::setw(2) << static_cast<int>(data[i]) << " ";
  }
  std::cout << std::endl;
  return 0;
}