#include "ChicksTower.h"
#include "Bullet.cpp"

ChicksTower::ChicksTower(int level){

    this->circle = new Circle(200, 200, 100);
    char buffer1[50];
    sprintf(buffer1, "./tower/chicktowerLV%d.png", level);
    TowerImage = al_load_bitmap(buffer1);
    char buffer2[50];
    sprintf(buffer2, "./tower/towerbulletLV%d.png", level);
    BulletImage = al_load_bitmap(buffer2);
    chickslife = 10000*level;
    Level = level;
    font = al_load_font("./fonts/pirulen.ttf", 12, 0);
}

ChicksTower::~ChicksTower(){
    delete circle;

    ///al_destroy_bitmap(img);
    ///al_destroy_bitmap(attack_img);

    al_destroy_bitmap(TowerImage);
    al_destroy_bitmap(BulletImage);
    al_destroy_font(font);

    for(auto&& child: this->towerbullet_set){
        delete child;
    }
    this->towerbullet_set.clear();
}

void ChicksTower::Draw(){
    al_draw_bitmap(TowerImage, 200, 200, 0);

    char buffer[50];
    sprintf(buffer, "HP %d", chickslife);
    al_draw_text(font, al_map_rgb(0, 0, 0), 200, 100, ALLEGRO_ALIGN_LEFT, buffer);

    for(unsigned int i=0; i<this->towerbullet_set.size(); i++){
        this->towerbullet_set[i]->Draw();
    }

    al_draw_filled_rectangle(0, window_height-cooltime*2, 50, window_height, al_map_rgb(255, 0, 0));
}

void ChicksTower::Attack(){
    if(canAttack){
        Bullet *bullet;
        bullet = new Bullet(200, 200, this->bullet_harm_point, this->bullet_velocity, 1, this->BulletImage);
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
        /*if(towerbullet_set[i]->getX()>=window_width){
            Bullet *bullet = this->towerbullet_set[i];
            this->towerbullet_set.erase(this->towerbullet_set.begin() + i);
            i--;
            delete bullet;
        }*/
    }
    //printf("%d", cooltime);
}
