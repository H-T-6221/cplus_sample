#include "Lambda.h"

void Pika::input_status() {
    monster.name = "pikachu";
    monster.hp = 35;
    monster.attack = 55;
    monster.defence = 40;
    monster.speed = 90;
}

void Nyasu::input_status() {
    monster.name = "nyaasu";
    monster.hp = 40;
    monster.attack = 45;
    monster.defence = 35;
    monster.speed = 90;
}

int main () {
    Pika monst1;
    Nyasu monst2;

    monst1.input_status();
    monst2.input_status();

    auto battle = [](Monster *mon1, Monster *mon2) {
        int damage = 0;

        damage = mon1->attack - mon2->defence;
        if (damage < 0) {
            damage = 1;
        }
        std::cout << "damage: " << damage << std::endl;

        mon2->hp = mon2->hp - damage;
        if (mon2->hp < 0 ) {
            mon2->hp = 0;
        }
        std::cout << "残りHP: " << mon2->hp << std::endl;
    };

    std::cout << "start" << std::endl;
    while (monst1.monster.hp != 0 && monst2.monster.hp !=0) {
        if (monst1.monster.speed >= monst2.monster.speed) {
            std::cout << "a pattern" << std::endl;
            battle(&monst1.monster, &monst2.monster);
        } else {
            std::cout << "b pattern" << std::endl;
            battle(&monst2.monster, &monst1.monster);
        }
    }

    std::cout << "end" << std::endl;

}
