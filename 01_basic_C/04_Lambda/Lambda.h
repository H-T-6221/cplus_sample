#pragma once

#include <stdio.h>
#include <iostream>

struct Monster{
    std::string name;
    int hp;
    int attack;
    int defence;
    int speed;
};

class Pika{
    public:
        Monster monster;
        void input_status();
};

class Nyasu{
    public:
        Monster monster;
        void input_status();
};
