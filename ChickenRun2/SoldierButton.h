#ifndef SOLDIERBUTTON_H_INCLUDED
#define SOLDIERBUTTON_H_INCLUDED

#include "global.h"
#include "Object.h"
#include "Circle.h"
#include "ChickenSoldier.h"

class SoldierButton:public Object{
public:
    SoldierButton();
    virtual ~SoldierButton();

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
    std::vector<ChickenSoldier*> chickensoldier_set;
    ALLEGRO_BITMAP *buttonimage[5];
    ALLEGRO_BITMAP *soldierimage[5][3];
    int harm_point[5] = {10, 20, 30, 40, 50};
    int velocity[5] = {10, 20, 30, 40, 50};

    int Level = -1;
    int cooltimeLV1 = 0, cooltimeLV2 = 0, cooltimeLV3 = 0, cooltimeLV4 = 0, cooltimeLV5 = 0;
    bool canAttackLV1 = false, canAttackLV2 = false, canAttackLV3 = false, canAttackLV4 = false, canAttackLV5 = false;
};

#endif // SOLDIERBUTTON_H_INCLUDED
