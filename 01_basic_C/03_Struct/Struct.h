#pragma once

#include <stdio.h>
#include <iostream>

struct person_info {
    std::string name;
    int age;
    int weight;
    int height;
    std::string job;
};

class Person{
    public:
        person_info p1_info;
        void info_input();
};
