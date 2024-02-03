#ifndef BOOM_H_INCLUDED
#define BOOM_H_INCLUDED

#include "global.h"
#include "Object.h"
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

#endif // BOOM_H_INCLUDED
