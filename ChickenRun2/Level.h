#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include "global.h"
#include "Object.h"
#include "RabbitTower.h"
#include "ChicksTower.h"
#include "ChickenSoldier.h"
#include "RabbitSoldier.h"


// 1 coin every 2 seconds
const int CoinSpeed = FPS * 2;
const int Coin_Limit = 100000;
//boom set
class boom:public Object{
public:
    boom();
    virtual ~boom();
    void Draw();
    void Update();
protected:
    ALLEGRO_BITMAP *img[3];
};
//dead set
//class


class Level{
public:
    Level(int, int);
    ~Level();
    void Attack();
    void RabbitAttack(int lvl);
    void Attack(int);
    void Draw();
    Status UpdateAttack();

protected:
    ALLEGRO_BITMAP *chicksoldierimage[5][3];
    ALLEGRO_BITMAP *rabbitsoldierimage[5][3];
    ALLEGRO_BITMAP *buttonimage[5][2];
    ALLEGRO_FONT *font;
    ChicksTower *chickstower;
    RabbitTower *rabbittower;
    int countTime = 0;
    int soldierLV = 0;
    int soldiercooltime = 0;
    bool soldierAttack = false;
    FILE *file;
    int level = -1;
    int cooltimeLV1 = 0, cooltimeLV2 = 0, cooltimeLV3 = 0, cooltimeLV4 = 0, cooltimeLV5 = 0;
    int coinLV1 = 100, coinLV2 = 150, coinLV3 = 300, coinLV4 = 500, coinLV5 = 1000;
    bool canAttackLV1 = false, canAttackLV2 = false, canAttackLV3 = false, canAttackLV4 = false, canAttackLV5 = false;
    int direction;
    std::vector<ChickenSoldier*> chickensoldier_set;
    std::vector<RabbitSoldier*> rabbitsoldier_set;
    int CoinInc = 0;
    int CoinCount = 0;
    int harm_point[5] = {10, 20, 30, 40, 50};
    int velocity[5] = {1, 2, 3, 4, 5};
    bool win = false;
    bool lose = false;
    bool level_ended = false;
};

#endif // LEVEL_H_INCLUDED
