#ifndef COMPUTERSOLDIER_H_INCLUDED
#define COMPUTERSOLDIER_H_INCLUDED

#include "global.h"
#include "Object.h"
#include "Circle.h"
#include "RabbitSoldier.h"
#include <string>

class ComputerSoldier:public Object{
public:
    ComputerSoldier(int);
    virtual ~ComputerSoldier();

    // override virtual function "Object::Draw"
    void Draw();
    //void resetAttackCounter(){ attack_counter = 0; }
    //void ToggleClicked(){ isClicked = !isClickd; }

    // update whole attack set
    // if any attack goes out of the range of tower, delete it
    void UpdateAttack();
    // detect if tower needs to attack some monster
    void Attack(int);

    ///virtual int getWidth(){ return 40; }
    ///virtual int getHeight(){ return 40; }

    // show selected tower image on cursor position
    ///static void SelectedTower(int, int, int);

protected:
    std::vector<RabbitSoldier*> soldier_set;
    ALLEGRO_BITMAP *soldierimage[5][3];
    int harm_point[5] = {10, 20, 30, 40, 50};
    int velocity[5] = {1, 2, 3, 4, 5};
    FILE *file;
    int countTime = 0;
    int soldierLV = 0;

    int Level = -1;
    int soldier_cooltime = 0;
    //bool soldierAttack = false;
};

#endif // COMPUTERSOLDIER_H_INCLUDED
