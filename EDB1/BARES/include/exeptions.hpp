#ifndef _exeptions_HPP_
#define _exeptions_HPP_

#include <iostream>
#include <exception>

class notValidToken : public exeption {
  virtual const char* what() const throw() {
    return ">>> token not valid.\n";
  };
} notValidToken;

#endif
