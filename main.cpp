#include <iostream>
#include "fraction/fraction.h"

int main() {
    fraction f1;
    fraction f2;
    std::cin >> f1;
    std::cin >> f2;
    f1 = f2;
    std::cout << f1 << std::endl;
    return 0;
}