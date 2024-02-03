#ifndef RABBITTOWER_H_INCLUDED
#define RABBITTOWER_H_INCLUDED

#include "global.h"
#include "Object.h"
#include "Circle.h"
#include "Bullet.h"
#include "RabbitSoldier.h"

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
    void Attack(int);

    ///virtual int getWidth(){ return 40; }
    ///virtual int getHeight(){ return 40; }

    // show selected tower image on cursor position
    ///static void SelectedTower(int, int, int);
std::vector<RabbitSoldier*> rabbitsoldier_set;std::vector<Bullet*> towerbullet_set;
protected:
    // setting of attack


    //std::vector<RabbitSoldier*> soldier_set;
    ALLEGRO_BITMAP *BulletImage;
    ALLEGRO_BITMAP *soldierimage[5][3];
    FILE *file;
    int countTime = 0;
    int soldierLV = 0;
    int harm_point[5] = {10, 20, 30, 40, 50};
    int velocity[5] = {1, 2, 3, 4, 5};
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
    int soldiercooltime = 0;
    bool soldierAttack = false;
    ALLEGRO_FONT *font;
};

#endif // RABBITTOWER_H_INCLUDED
