#include "ismls.h"
#include <iostream>

int main() {

  ins::list<int> AL;

  int br;
  std::cout << "size " << sizeof(AL) << std::endl;
  while (std::cin >> br) {
    AL.gurni_ga(br);
  }
  std::cout << "size " << sizeof(AL) << std::endl;
  std::cout << std::string(30, '*') << std::endl;
  std::cout << "Ispis liste" << std::endl;

  ins::list<int>::iterator it, ite;
  it = AL.begin();
  *it = 2222;

  ins::list<int> BL{AL};
  ite = BL.begin();
  *ite = 33333;

  for (it = AL.begin(); it != AL.end(); it++) {
    std::cout << "-->" << *it << std::endl;
  }

  for (ite = BL.begin(); ite != BL.end(); ite++) {
    std::cout << "-->" << *ite << std::endl;
  }
}
