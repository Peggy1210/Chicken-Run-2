#ifndef TWOPLAYER_H_INCLUDED
#define TWOPLAYER_H_INCLUDED

#include "global.h"
#include "Object.h"
#include "RabbitTower.h"
#include "ChicksTower.h"
#include "ChickenSoldier.h"
#include "RabbitSoldier.h"
#include "boom.h"

class TwoPlayer{
public:
    TwoPlayer();
    ~TwoPlayer();
    void leftAttack();
    void rightAttack();
    void leftAttack(int);
    void rightAttack(int);
    void Draw();
    Status UpdateAttack();

protected:
    ALLEGRO_BITMAP *leftimage[5][3];
    ALLEGRO_BITMAP *rightimage[5][3];
    std::vector<ChickenSoldier*> leftsoldier_set;
    std::vector<RabbitSoldier*> rightsoldier_set;
    ALLEGRO_BITMAP *buttonimage[5][2];
    ALLEGRO_FONT *font;
    ChicksTower *lefttower;
    RabbitTower *righttower;
    int level = -1;
    int leftcooltimeLV1 = 0, leftcooltimeLV2 = 0, leftcooltimeLV3 = 0, leftcooltimeLV4 = 0, leftcooltimeLV5 = 0;
    int rightcooltimeLV1 = 0, rightcooltimeLV2 = 0, rightcooltimeLV3 = 0, rightcooltimeLV4 = 0, rightcooltimeLV5 = 0;
    int coinLV1 = 100, coinLV2 = 150, coinLV3 = 300, coinLV4 = 500, coinLV5 = 1000;
    bool leftcanAttackLV1 = false, leftcanAttackLV2 = false, leftcanAttackLV3 = false, leftcanAttackLV4 = false, leftcanAttackLV5 = false;
    bool rightcanAttackLV1 = false, rightcanAttackLV2 = false, rightcanAttackLV3 = false, rightcanAttackLV4 = false, rightcanAttackLV5 = false;
    int direction;
    int leftCoinInc = 0;
    int rightCoinInc = 0;
    int leftCoinCount = 0;
    int rightCoinCount = 0;
    int harm_point[5] = {10, 20, 30, 40, 50};
    int velocity[5] = {1, 2, 3, 4, 5};
    bool level_ended = false;
};

#endif // TWOPLAYER_H_INCLUDED
