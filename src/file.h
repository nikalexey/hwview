#pragma once

#include <string>

class CFile {
public:
  enum class Status { CLOSE, OPEN, ERROR };
public:
  CFile(const std::string& filename);
  ~CFile();

  size_t getSize();
  uint8_t* getData();

private:
  size_t getSizeImpl();

private:
  std::string m_filename;
  int m_fd;
  uint8_t* m_dataPtr;
  size_t m_size;
  Status status;

};
