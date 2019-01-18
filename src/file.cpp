//
// Created by anikiforov on 17.01.19.
//

#include "file.h"
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>


CFile::CFile(const std::string& filename)
  : m_filename(filename)
  , status(Status::CLOSE) {
  m_fd = open(filename.c_str(), O_RDONLY, 0);
  if (m_fd <= 0) {
    status = Status::ERROR;
    return;
  }
  m_size = getSizeImpl();

  m_dataPtr = (uint8_t*)mmap(nullptr, getSize(), PROT_READ, MAP_PRIVATE, m_fd, 0);
  if(m_dataPtr == MAP_FAILED) {
    status = Status::ERROR;
    return;
  }
  status = Status::OPEN;
}

CFile::~CFile() {
  if (status == Status::OPEN) {
    munmap(m_dataPtr, getSize());
  }
  if (m_fd > 0) {
    close(m_fd);
  }
}

size_t CFile::getSize() {
  return m_size;
}

uint8_t* CFile::getData() {
  if (status != Status::OPEN) {
    return nullptr;
  }
  return m_dataPtr;
}

size_t CFile::getSizeImpl() {
  struct stat st;
  if(fstat(m_fd, &st) < 0) {
    status = Status::ERROR;
  }

  return (size_t)st.st_size;
}
