#include "Bullet.h"

///const int Velocity[] = {8, 8, 6, 10, 20};
///const int Harm[] = {5, 7, 15, 3, 5};

Bullet::Bullet(int x, int y, int harm_point, int velocity, int dir, ALLEGRO_BITMAP* attack_img){

    // initialize the information of attack
    this->circle = new Circle(x, y, 10);
    this->pos_x = x; this->pos_y = y;
    this->attack_velocity = velocity;
    this->harm_point = harm_point;
    this->attack_img = attack_img;
    this->direction = dir;

    // initialize the effect sound of attack
    sample = al_load_sample("./sound/Arrow.wav");
    arrow = al_create_sample_instance(sample);
    al_set_sample_instance_playmode(arrow, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(arrow, al_get_default_mixer());
    al_set_sample_instance_gain(arrow, 0);///Bullet::volume
    al_play_sample_instance(arrow);
}

Bullet::~Bullet(){
    delete circle;
    al_destroy_sample_instance(arrow);
    al_destroy_sample(sample);
}

void Bullet::Draw(){
    //printf("%d ", this->pos_x);
    al_draw_bitmap(this->attack_img, this->pos_x, this->pos_y, 0);
    //al_draw_filled_circle(pos_x, pos_y, circle->r, al_map_rgba(196, 79, 79, 200));
}

void Bullet::Update(){
    this->pos_x += this->attack_velocity*this->direction;
    circle->x = this->pos_x;
}
