#include "read.h"

int main() {
    ReadFile test;
    std::cout << "start" << std::endl;
    test.read("../test.txt");
    std::cout << test.get() << std::endl;
    std::cout << "end" << std::endl;
}