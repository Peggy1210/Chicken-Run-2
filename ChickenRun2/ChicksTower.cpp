#include "ChicksTower.h"
#include "RabbitTower.h"

ChicksTower::ChicksTower(int level, int dir){
    this->direction = dir;
    this->circle = new Circle(400, 450, 200);
    char buffer[50];
    sprintf(buffer, "./tower/TowerLV%d.png", level);
    TowerImage = al_load_bitmap(buffer);
    sprintf(buffer, "./tower/BulletLV%d.png", level);
    BulletImage = al_load_bitmap(buffer);
    chickslife = 10000*level;
    Level = level;
    font = al_load_font("./fonts/pirulen.ttf", 24, 0);

    sprintf(buffer, "./tower/cooltimeLV%d.png", level);
    cooltimeimg_lower = al_load_bitmap(buffer);
    cooltimeimg_upper = al_load_bitmap("./tower/cooltimebutton.png");
}

ChicksTower::~ChicksTower(){
    delete circle;

    ///al_destroy_bitmap(img);
    ///al_destroy_bitmap(attack_img);

    al_destroy_bitmap(TowerImage);
    al_destroy_bitmap(BulletImage);
    al_destroy_font(font);
    al_destroy_bitmap(cooltimeimg_upper);
    al_destroy_bitmap(cooltimeimg_lower);

    for(auto&& child: this->towerbullet_set){
        delete child;
    }
    this->towerbullet_set.clear();
}

void ChicksTower::Draw(){
    al_draw_bitmap(TowerImage, field_left, field_upper+50, 0);

    char buffer[50];
    sprintf(buffer, "HP %d", chickslife);
    al_draw_text(font, al_map_rgb(0, 0, 0), field_left+50, field_upper, ALLEGRO_ALIGN_LEFT, buffer);

    for(unsigned int i=0; i<this->towerbullet_set.size(); i++){
        this->towerbullet_set[i]->Draw();
    }

    al_draw_bitmap(cooltimeimg_lower, 0, window_height-300, 0);
    al_draw_filled_rectangle(0, window_height-300, 300, window_height-((float)cooltime/5)*3, al_map_rgba(150, 150, 150, 200));
    al_draw_bitmap(cooltimeimg_upper, 0, window_height-300, 0);

}

void ChicksTower::Attack(){
    if(canAttack){
        Bullet *bullet;
        bullet = new Bullet(field_left, field_upper+50, this->bullet_harm_point, this->bullet_velocity, direction, this->BulletImage);
        this->towerbullet_set.push_back(bullet);
        canAttack = false;
        cooltime = 0;
    }
}


void ChicksTower::UpdateAttack(){
    if(cooltime<500) cooltime++;
    if(cooltime==500) canAttack = true;
    for(unsigned int i=0; i < this->towerbullet_set.size(); i++){
        towerbullet_set[i]->Update();
        if(towerbullet_set[i]->getX()>=field_right-400){
            Bullet *bullet = this->towerbullet_set[i];
            this->towerbullet_set.erase(this->towerbullet_set.begin() + i);
            i--;
            delete bullet;
        }
    }
    //if(++life_count%100 && chickslife<10000*Level) chickslife += 100;
}

bool ChicksTower::isAttacked(){
    this->chickslife -= 500;
    if(this->chickslife<0) return true;
    else return false;
}

bool ChicksTower::isBulletAttack(RabbitTower *rabbittower){
    for(unsigned int i=0; i<towerbullet_set.size(); i++){
        if(Circle::isOverlap(towerbullet_set[i]->circle, rabbittower->circle)){
            Bullet *bullet = this->towerbullet_set[i];
            this->towerbullet_set.erase(this->towerbullet_set.begin() + i);
            delete bullet;
            if(rabbittower->isAttacked()) return true;
        }
    }
    return false;
}
