#ifndef CHICKSTOWER_H_INCLUDED
#define CHICKSTOWER_H_INCLUDED

#include "global.h"
#include "Object.h"
#include "Circle.h"
#include "Bullet.h"
#include "SoldierButton.h"
#include <vector>

class ChicksTower:public Object{
public:
    ChicksTower(int);
    virtual ~ChicksTower();

    // override virtual function "Object::Draw"
    void Draw();
    //void resetAttackCounter(){ attack_counter = 0; }
    //void ToggleClicked(){ isClicked = !isClickd; }

    // update whole attack set
    // if any attack goes out of the range of tower, delete it
    void UpdateAttack();
    // detect if tower needs to attack some monster
    void Attack();

    ///virtual int getWidth(){ return 40; }
    ///virtual int getHeight(){ return 40; }

    // show selected tower image on cursor position
    ///static void SelectedTower(int, int, int);

protected:
    // setting of attack
    std::vector<Bullet*> towerbullet_set;
    ALLEGRO_BITMAP *BulletImage;
    int chickslife = 0;
    int bullet_harm_point = 5;
    int bullet_velocity = 10;

    // information of tower
    ///bool isClicked = false;
    ALLEGRO_BITMAP *TowerImage;
    int Level = -1;
    int cooltime = 0;
    bool canAttack = false;



    ALLEGRO_FONT *font;
};

#endif // CHICKSTOWER_H_INCLUDED
