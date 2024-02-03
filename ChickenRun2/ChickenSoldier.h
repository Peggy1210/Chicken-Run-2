#ifndef CHICKENSOLDIER_H_INCLUDED
#define CHICKENSOLDIER_H_INCLUDED

#include "Object.h"
#include "Circle.h"

class ChickenSoldier:public Object{
public:
    ChickenSoldier(int, int, int, int, int, ALLEGRO_BITMAP*, ALLEGRO_BITMAP*, ALLEGRO_BITMAP*);
    virtual ~ChickenSoldier();

    // override virtual function "Object::Draw"
    void Draw();
    void Update();
    int getHarmPoint() { return harm_point; }

    ///static float volume;

protected:
    ALLEGRO_BITMAP *soldier_img[3];

private:
    int velocity = 8;
    int harm_point = 5;
    int pos_x, pos_y;
    int direction; //positive for moving right, negative for moving left
};


#endif // CHICKENSOLDIER_H_INCLUDED
