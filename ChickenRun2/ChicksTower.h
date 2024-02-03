#ifndef CHICKSTOWER_H_INCLUDED
#define CHICKSTOWER_H_INCLUDED

#include "global.h"
#include "Object.h"
#include "Circle.h"
#include "Bullet.h"
#include "ChickenSoldier.h"
#include "RabbitTower.h"

class ChicksTower:public Object{
public:
    ChicksTower(int, int);
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
    void Attack(int);

    //void AttackPoint(RabbitTower*);

protected:
    // setting of attack
    std::vector<Bullet*> towerbullet_set;
    std::vector<ChickenSoldier*> chickensoldier_set;
    ALLEGRO_BITMAP *BulletImage;
    ALLEGRO_BITMAP *buttonimage[5][2];
    ALLEGRO_BITMAP *soldierimage[5][3];
    ALLEGRO_BITMAP *cooltimeimg_upper;
    ALLEGRO_BITMAP *cooltimeimg_lower;
    int harm_point[5] = {10, 20, 30, 40, 50};
    int velocity[5] = {1, 2, 3, 4, 5};
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
    int cooltimeLV1 = 0, cooltimeLV2 = 0, cooltimeLV3 = 0, cooltimeLV4 = 0, cooltimeLV5 = 0;
    bool canAttackLV1 = false, canAttackLV2 = false, canAttackLV3 = false, canAttackLV4 = false, canAttackLV5 = false;
    int direction;

    ALLEGRO_FONT *font;
};

#endif // CHICKSTOWER_H_INCLUDED
