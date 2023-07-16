#include <iostream>
#include <vector>
#include <string>
#include <boost/multiprecision/cpp_int.hpp>
#include <emscripten/bind.h>

using namespace emscripten;

std::string getFibonacciSequence(int n){
  std::vector<boost::multiprecision::cpp_int> sequence = {0, 1};
  std::string sequeceToReturn = "0 • 1";

  for(int i = 2; i <= n; i++){
    boost::multiprecision::cpp_int newFibonacci = sequence[i - 1] + sequence[i - 2];
    sequence.push_back(newFibonacci);
    sequeceToReturn += " • " + boost::lexical_cast<std::string>(newFibonacci);
  }
  
  std::cout << "fibonnaci: " << sequence[n] << std::endl;

  if(n == 0){
    return "0";
  } else {
    return sequeceToReturn;
  }
}

EMSCRIPTEN_BINDINGS(my_module) {
  function("getFibonacciSequence", &getFibonacciSequence);
}