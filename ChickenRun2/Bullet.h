#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED

#include "Object.h"
#include "Circle.h"

class Bullet:public Object{
public:
    Bullet(int, int, int, int, int, ALLEGRO_BITMAP*);
    virtual ~Bullet();

    // override virtual function "Object::Draw"
    void Draw();
    void Update();
    int getHarmPoint() { return harm_point; }

    ///static float volume;

protected:
    ALLEGRO_BITMAP *attack_img;
    ALLEGRO_SAMPLE *sample;
    ALLEGRO_SAMPLE_INSTANCE *arrow = NULL;

private:
    int attack_velocity = 8;
    int harm_point = 5;
    int pos_x, pos_y;
    int direction; //positive for moving right, negative for moving left
};



#endif // BULLET_H_INCLUDED
