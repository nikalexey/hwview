#pragma once

#include <string>

class CFile {
  CFile();

public:
  CFile(const std::string& filename);
  ~CFile();

public:
  size_t getSize();
private:
  std::string m_filename;
};
