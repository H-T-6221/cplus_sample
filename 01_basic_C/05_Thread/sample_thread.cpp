#include <stdio.h>
#include <iostream>
#include <thread>

void ThreadFunc(int num) {
  std::cout << "ThreadFunc " << num << std::endl;
}

int main() {
  std::thread th1(ThreadFunc, 1);
  
  auto func = [](std::string msg) {
    std::cout << "thread message : " << msg << std::endl;
  };

  std::thread th2(func, "Hellow, World!");
  std::cout << "th2 id : " << th2.get_id() << std::endl;

  th1.join();
  th2.join();

  return 0;
}
