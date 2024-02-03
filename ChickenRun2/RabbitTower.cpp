#include "RabbitTower.h"

RabbitTower::RabbitTower(int level, int dir){
    this->direction = dir;
    this->circle = new Circle(window_width-400, 450, 200);
    char buffer[50];
    sprintf(buffer, "./tower/TowerLV4.png");
    TowerImage = al_load_bitmap(buffer);
    sprintf(buffer, "./tower/BulletLV4.png");
    BulletImage = al_load_bitmap(buffer);
    chickslife = 10000*level;
    Level = level;
    font = al_load_font("./fonts/pirulen.ttf", 24, 0);
    cooltimeimg_lower = al_load_bitmap("./tower/cooltime.png");
    cooltimeimg_upper = al_load_bitmap("./tower/cooltimebutton1.png");
}

RabbitTower::~RabbitTower(){
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

void RabbitTower::Draw(){
    al_draw_bitmap(TowerImage, field_right-400, field_upper+50, 0);

    char buffer[50];
    sprintf(buffer, "HP %d", chickslife);
    al_draw_text(font, al_map_rgb(0, 0, 0), field_right-350, field_upper, ALLEGRO_ALIGN_LEFT, buffer);

    for(unsigned int i=0; i<this->towerbullet_set.size(); i++){
        this->towerbullet_set[i]->Draw();
    }
    al_draw_bitmap(cooltimeimg_lower, window_width-300, window_height-300, 0);
    al_draw_filled_rectangle(window_width-300, window_height-300, window_width, window_height-((float)cooltime/5)*3, al_map_rgba(150, 150, 150, 200));
    al_draw_bitmap(cooltimeimg_upper, window_width-300, window_height-300, 0);

    //al_draw_filled_rectangle(window_width-50, window_height-cooltime*2, window_width, window_height, al_map_rgba((int)255*((float)cooltime/501), 0, 0, 100));
}

void RabbitTower::Attack(){
    if(canAttack){
        Bullet *bullet;
        bullet = new Bullet(field_right-400, field_upper+50, this->bullet_harm_point, this->bullet_velocity, direction, this->BulletImage);
        this->towerbullet_set.push_back(bullet);
        canAttack = false;
        cooltime = 0;
    }
}

void RabbitTower::UpdateAttack(){
    if(cooltime<500) cooltime++;
    if(cooltime==500) canAttack = true;
    this->Attack();
    //printf("%d", towerbullet_set.size());
    for(unsigned int i=0; i < this->towerbullet_set.size(); i++){
        towerbullet_set[i]->Update();
        //printf("%d ", towerbullet_set[i]->getX());
        if(towerbullet_set[i]->getX()<=field_left){
            Bullet *bullet = this->towerbullet_set[i];
            this->towerbullet_set.erase(this->towerbullet_set.begin() + i);
            i--;
            delete bullet;
        }
    }
    //printf("%d", cooltime);

}

bool RabbitTower::isAttacked(){
    this->chickslife -= 500;
    if(this->chickslife<0) return true;
    else return false;
}

bool RabbitTower::isBulletAttack(ChicksTower *chicktower){
    for(unsigned int i=0; i<towerbullet_set.size(); i++){
        if(Circle::isOverlap(towerbullet_set[i]->circle, chicktower->circle)){
            Bullet *bullet = this->towerbullet_set[i];
            this->towerbullet_set.erase(this->towerbullet_set.begin() + i);
            delete bullet;
            if(chicktower->isAttacked()) return true;
        }
    }
    return false;
}
