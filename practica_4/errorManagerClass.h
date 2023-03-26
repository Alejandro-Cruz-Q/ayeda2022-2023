#ifndef ERRORMANAGERCLASS_H
#define ERRORMANAGERCLASS_H

#include <string>
#include <iostream>

class Exception_d {
 public:
  Exception_d(std::string file_name, std::string error_description, int error_line, int error_code) : file_name_(file_name), error_description_(error_description), error_line_(error_line), error_code_(error_code) {}
  ~Exception_d() {}
  std::string GetFileName() const {return file_name_;}
  std::string GetErrorDescription() const {return error_description_;}
  int GetErrorLine() const {return error_line_;}
  int GetErrorCode() const {return error_code_;}
 private:
  std::string file_name_;
  std::string error_description_;
  int error_line_;
  int error_code_;
};

std::ostream& operator<<(std::ostream &os, Exception_d const &exeption) {
  os << exeption.GetFileName() << " " << exeption.GetErrorLine() << ": " << exeption.GetErrorDescription() << ". Error code (" << exeption.GetErrorCode() << ")";
  return os;
}

#endif

