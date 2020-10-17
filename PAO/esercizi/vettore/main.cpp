#include "vettore.h"

int main() {
  Vettore v1, v2(3), v3(5);
  v1 = v2 + v3;
  v2.append(v2);
  v3.append(v1);
  std::cout << v1 << std::endl;
  std::cout << v2 << std::endl;
  std::cout << v3 << std::endl;
}