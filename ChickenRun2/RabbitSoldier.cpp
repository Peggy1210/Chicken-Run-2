#include "RabbitSoldier.h"
//#include "ChickenSoldier.h"
///const int Velocity[] = {8, 8, 6, 10, 20};
///const int Harm[] = {5, 7, 15, 3, 5};

RabbitSoldier::RabbitSoldier(int x, int y, int harm_point, int lvl, int dir, ALLEGRO_BITMAP* img1, ALLEGRO_BITMAP* img2, ALLEGRO_BITMAP* img3){
    // initialize the information of attack
    this->direction = dir;
    this->Level = lvl;
    soldierlife = lvl*100;
    char buffer[50];
    if(direction==RIGHT){
        this->circle = new Circle(x+200, y+200, 100);
        this->pos_x = x; this->pos_y = y;
        this->soldiervelocity = velocity[lvl-1];
        this->harm_point = harm[lvl-1];
        this->soldier_img[0] = img1;
        this->soldier_img[1] = img2;
        this->soldier_img[2] = img3;
        sprintf(buffer, "./character/RabbitBulletLV%d.png", Level);
        bullet_img = al_load_bitmap(buffer);
    }else if(direction==LEFT){
        this->circle = new Circle(x+200, y+200, 100);
        this->pos_x = x; this->pos_y = y;
        this->soldiervelocity = velocity[lvl-1];
        this->harm_point = harm[lvl-1];
        this->soldier_img[0] = img1;
        this->soldier_img[1] = img2;
        this->soldier_img[2] = img3;
        sprintf(buffer, "./character/RabbitBulletLV%d.png", Level);
        bullet_img = al_load_bitmap(buffer);
    }

}

RabbitSoldier::~RabbitSoldier(){
    delete circle;
}

void RabbitSoldier::Draw(){
    //printf("%d ", this->pos_x);
    if(attack){
        al_draw_bitmap(this->soldier_img[2], this->pos_x, this->pos_y, 0);
        attack = false;
    }
    else if(((pos_x-200)/soldiervelocity)%(16*soldiervelocity)<8*soldiervelocity) al_draw_bitmap(this->soldier_img[0], this->pos_x, this->pos_y, 0);
    else if(((pos_x-200)/soldiervelocity)%(16*soldiervelocity)<16*soldiervelocity) al_draw_bitmap(this->soldier_img[1], this->pos_x, this->pos_y, 0);
    //al_draw_filled_circle(pos_x, pos_y, circle->r, al_map_rgba(196, 79, 79, 200));
    for(unsigned int i=0; i<this->chickbullet_set.size(); i++){
        this->chickbullet_set[i]->Draw();
    }
}

void RabbitSoldier::Update(){
    this->pos_x += this->soldiervelocity*this->direction;
    circle->x = this->pos_x;
    if(++attack_count%(300/Level)>=200/Level){
        attack = true;
        //printf("%d ", attack_count);
        if(this->attack_count%(300/Level)==200/Level){
            Bullet *bullet;
            bullet = new Bullet(pos_x, pos_y, this->harm_point, 5*this->soldiervelocity, direction, this->bullet_img);
            this->chickbullet_set.push_back(bullet);
        }
    }else attack = false;

    for(unsigned int i=0; i < this->chickbullet_set.size(); i++){
        chickbullet_set[i]->Update();
        if(chickbullet_set[i]->getX()<=field_left){
            Bullet *bullet = this->chickbullet_set[i];
            this->chickbullet_set.erase(this->chickbullet_set.begin() + i);
            i--;
            delete bullet;
        }
    }
}

bool RabbitSoldier::Bullet_Attack(ChickenSoldier *chick){
    for(unsigned int i=0; i<this->chickbullet_set.size(); i++){
        if(Circle::isOverlap(chick->circle, chickbullet_set[i]->circle)){
            Bullet *bullet = this->chickbullet_set[i];
            this->chickbullet_set.erase(this->chickbullet_set.begin() + i);
            delete bullet;
            return true;
        }
    }
    return false;
}

bool RabbitSoldier::isAttacked(){
    this->soldierlife -= 100;
    if(this->soldierlife<=0) return true;
    else return false;
}
