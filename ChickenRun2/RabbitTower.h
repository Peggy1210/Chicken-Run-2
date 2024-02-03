#ifndef RABBITTOWER_H_INCLUDED
#define RABBITTOWER_H_INCLUDED

#include "global.h"
#include "Object.h"
#include "Circle.h"
#include "Bullet.h"
#include "ChicksTower.h"

//#include "ChicksTower.h"

class RabbitTower:public Object{
public:
    RabbitTower(int, int);
    virtual ~RabbitTower();

    // override virtual function "Object::Draw"
    void Draw();
    //void resetAttackCounter(){ attack_counter = 0; }
    //void ToggleClicked(){ isClicked = !isClickd; }

    // update whole attack set
    // if any attack goes out of the range of tower, delete it
    void UpdateAttack();
    // detect if tower needs to attack some monster
    void Attack();
    //void Bullet_Attack(ChicksTower*);

    bool isAttacked();
    bool isBulletAttack(ChicksTower*);
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
    ALLEGRO_BITMAP *cooltimeimg_upper;
    ALLEGRO_BITMAP *cooltimeimg_lower;

    // information of tower
    ///bool isClicked = false;
    ALLEGRO_BITMAP *TowerImage;
    int Level = -1;
    int cooltime = 0;
    bool canAttack = false;
    int direction = 0;
    ALLEGRO_FONT *font;
};

#endif // RABBITTOWER_H_INCLUDED
