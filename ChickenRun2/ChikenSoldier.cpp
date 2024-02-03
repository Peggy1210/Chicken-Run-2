#include "ChickenSoldier.h"

///const int Velocity[] = {8, 8, 6, 10, 20};
///const int Harm[] = {5, 7, 15, 3, 5};

ChickenSoldier::ChickenSoldier(int x, int y, int harm_point, int velocity, int dir, ALLEGRO_BITMAP* img1, ALLEGRO_BITMAP* img2, ALLEGRO_BITMAP* img3){
    // initialize the information of attack
    this->circle = new Circle(x, y, 100);
    this->pos_x = x; this->pos_y = y;
    this->velocity = velocity;
    this->harm_point = harm_point;
    this->soldier_img[0] = img1;
    this->soldier_img[1] = img2;
    this->soldier_img[2] = img3;
    this->direction = dir;
}

ChickenSoldier::~ChickenSoldier(){
    delete circle;
}

void ChickenSoldier::Draw(){
    printf("%d ", this->pos_x);
    al_draw_bitmap(this->soldier_img[0], this->pos_x, this->pos_y, 0);
    //al_draw_filled_circle(pos_x, pos_y, circle->r, al_map_rgba(196, 79, 79, 200));
}

void ChickenSoldier::Update(){
    this->pos_x += this->velocity*this->direction;
    circle->x = this->pos_x;
}
