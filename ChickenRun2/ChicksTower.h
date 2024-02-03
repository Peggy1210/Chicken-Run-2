#ifndef CHICKSTOWER_H_INCLUDED
#define CHICKSTOWER_H_INCLUDED

#include "global.h"
#include "Object.h"
#include "Circle.h"
#include "Bullet.h"
class RabbitTower;

class ChicksTower:public Object{
public:
    ChicksTower(int);
    ChicksTower(int, int, int);
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
    bool isAttacked();
    bool isBulletAttack(RabbitTower*);
    //void AttackPoint(RabbitTower*);

protected:
    // setting of attack
    std::vector<Bullet*> towerbullet_set;
    ALLEGRO_BITMAP *BulletImage;
    ALLEGRO_BITMAP *cooltimeimg_upper;
    ALLEGRO_BITMAP *cooltimeimg_lower;
    int chickslife = 0;
    int life_count = 0;
    int bullet_harm_point = 5;
    int bullet_velocity = 10;

    // information of tower
    ///bool isClicked = false;
    ALLEGRO_BITMAP *TowerImage;
    int Level = -1;
    int cooltime = 0;
    bool canAttack = false;
    ALLEGRO_FONT *font;
    int direction = 0;
};

#endif // CHICKSTOWER_H_INCLUDED
