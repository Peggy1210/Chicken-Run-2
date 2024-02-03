#ifndef CHICKSTOWER_H_INCLUDED
#define CHICKSTOWER_H_INCLUDED

#include "global.h"
#include "object.h"
#include "circle.h"
#include <vector>

class ChicksTower: public Object{
public:
    ChicksTower();
    virtual ~ChicksTower();

    // override virtual function "Object::Draw"
    void Draw();
    void resetAttackCounter(){ attack_counter = 0; }
    void ToggleClicked(){ isClicked = !isClickd; }

    // update whole attack set
    // if any attack goes out of the range of tower, delete it
    void UpdateAttack();
    // detect if tower needs to attack some monster
    bool DetectAttack(Monster*);
    // process if some of attack in set touches monster
    bool TriggerAttack(Monster*);

    virtual int getWidth(){ return 40; }
    virtual int getHeight(){ return 40; }

    // show selected tower image on cursor position
    ///static void SelectedTower(int, int, int);

protected:
    // setting of attack
    int attack_frequency = 20;
    int attack_counter = 0;
    int attack_harm_point = 5;
    int attack_velocity = 10;
    ALLEGRO_BITMAP *attack_img;
    std::vector<Attack*> attack_set;

    // information of tower
    int type;
    bool isClicked = false;
    ALLEGRO_BITMAP *img;

};

#endif // CHICKSTOWER_H_INCLUDED
