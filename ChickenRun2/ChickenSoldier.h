#ifndef CHICKENSOLDIER_H_INCLUDED
#define CHICKENSOLDIER_H_INCLUDED

#include "global.h"
#include "Object.h"
#include "Circle.h"
//#include "RabbitSoldier.h"
#include "Bullet.h"
class RabbitSoldier;

class ChickenSoldier:public Object{
public:
    ChickenSoldier(int, int, int, int, int, ALLEGRO_BITMAP*, ALLEGRO_BITMAP*, ALLEGRO_BITMAP*);
    virtual ~ChickenSoldier();

    // override virtual function "Object::Draw"
    void Draw();
    void Update();
    bool isAttacked();
    bool Bullet_Attack(RabbitSoldier*);
    //void AttackPoint(RabbitSoldier*);


    ///static float volume;

protected:
    ALLEGRO_BITMAP *soldier_img[3];
    ALLEGRO_BITMAP *bullet_img;
    std::vector<Bullet*> chickbullet_set;

private:
    int soldiervelocity = 8;
    int harm_point = 5;
    int pos_x, pos_y;
    int direction; //positive for moving right, negative for moving left
    int attack_count = 0;
    bool attack = false;
    int Level = -1;
    int soldierlife = 0;
};


#endif // CHICKENSOLDIER_H_INCLUDED
