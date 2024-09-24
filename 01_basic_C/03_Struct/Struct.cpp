#include "Struct.h"

void Person::info_input() {
    p1_info.name = "ando";
    p1_info.age = 30;
    p1_info.weight = 68;
    p1_info.height = 175;
    p1_info.job = "engineer";
}

int main() {
    Person person;
    person.info_input();

    std::cout << person.p1_info.name << std::endl;
    std::cout << person.p1_info.age << std::endl;
    std::cout << person.p1_info.weight << std::endl;
    std::cout << person.p1_info.height << std::endl;
    std::cout << person.p1_info.job << std::endl;
}
