#include <iostream>
#include <vector>
#include <string>
#include <boost/multiprecision/cpp_int.hpp>
#include <emscripten/bind.h>

struct ObjFib {
  std::string sequence;
  std::string nFib;
};

ObjFib getFibonacciSequence(int n){
  boost::multiprecision::cpp_int beforeOne = 0;
  boost::multiprecision::cpp_int beforeTwo = 1;
  std::string sequeceToReturn = "0 • 1";

  for(int i = 2; i <= n; i++){
    boost::multiprecision::cpp_int newFibonacci = beforeOne + beforeTwo;
    sequeceToReturn += " • " + boost::lexical_cast<std::string>(newFibonacci);
    beforeOne = beforeTwo;
    beforeTwo = newFibonacci;
  }
  
  ObjFib objToReturn;
  objToReturn.sequence = n == 0 ? "0" : sequeceToReturn;
  objToReturn.nFib = n == 0 ? "0" : boost::lexical_cast<std::string>(beforeTwo);

  return objToReturn;
}


EMSCRIPTEN_BINDINGS(my_module) {
  emscripten::value_object<ObjFib>("ObjFib")
    .field("sequence", &ObjFib::sequence)
    .field("nFib", &ObjFib::nFib);

  emscripten::function("getFibonacciSequence", &getFibonacciSequence);
}