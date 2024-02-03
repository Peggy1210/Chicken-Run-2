#include "ChicksTower.h"
#include "Bullet.cpp"
#include "ChikenSoldier.cpp"

ChicksTower::ChicksTower(int level, int dir){
    this->direction = dir;
    this->circle = new Circle(200, 400, 100);
    char buffer[50];
    sprintf(buffer, "./tower/TowerLV%d.png", level);
    TowerImage = al_load_bitmap(buffer);
    sprintf(buffer, "./tower/BulletLV%d.png", level);
    BulletImage = al_load_bitmap(buffer);
    chickslife = 10000*level;
    Level = level;
    font = al_load_font("./fonts/pirulen.ttf", 24, 0);
    for(int i=0; i<5; i++){
        sprintf(buffer, "./character/button%d_1.png", i+1);
        buttonimage[i][0] = al_load_bitmap(buffer);
        sprintf(buffer, "./character/button%d_2.png", i+1);
        buttonimage[i][1] = al_load_bitmap(buffer);
    }
    for(int i=0; i<5; i++){
        sprintf(buffer, "./character/chickenLV%d_1.png", i+1);
        soldierimage[i][0] = al_load_bitmap(buffer);
        sprintf(buffer, "./character/chickenLV%d_2.png", i+1);
        soldierimage[i][1] = al_load_bitmap(buffer);
        sprintf(buffer, "./character/chickenLV%d_3.png", i+1);
        soldierimage[i][2] = al_load_bitmap(buffer);
    }
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
    for(int i=0; i<5; i++){
        for(int j=0; j<2; j++)
            al_destroy_bitmap(buttonimage[i][j]);
        for(int j=0; j<3; j++){
            al_destroy_bitmap(soldierimage[i][j]);
        }
    }

    for(auto&& child: this->chickensoldier_set){
        delete child;
    }
    this->chickensoldier_set.clear();
}

void ChicksTower::Draw(){
    al_draw_bitmap(TowerImage, field_left, field_upper, 0);

    al_draw_bitmap(buttonimage[0][(canAttackLV1? 1:0)], 500, 750, 0);
    al_draw_bitmap(buttonimage[1][(canAttackLV2? 1:0)], 800, 750, 0);
    al_draw_bitmap(buttonimage[2][(canAttackLV3? 1:0)], 1100, 750, 0);
    al_draw_bitmap(buttonimage[3][(canAttackLV4? 1:0)], 1400, 750, 0);
    al_draw_bitmap(buttonimage[4][(canAttackLV5? 1:0)], 1700, 750, 0);

    for(unsigned int i=0; i<this->chickensoldier_set.size(); i++){
        this->chickensoldier_set[i]->Draw();
    }

    char buffer[50];
    sprintf(buffer, "HP %d", chickslife);
    al_draw_text(font, al_map_rgb(0, 0, 0), field_left, field_upper, ALLEGRO_ALIGN_LEFT, buffer);

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
        bullet = new Bullet(field_left, field_upper, this->bullet_harm_point, this->bullet_velocity, direction, this->BulletImage);
        this->towerbullet_set.push_back(bullet);
        canAttack = false;
        cooltime = 0;
    }
}

void ChicksTower::Attack(int lvl){
    if(canAttackLV1 && lvl==1){
        ChickenSoldier *soldier;
        soldier = new ChickenSoldier(field_left, field_upper, this->harm_point[0], lvl, RIGHT, this->soldierimage[0][0], this->soldierimage[0][1], this->soldierimage[0][2]);
        this->chickensoldier_set.push_back(soldier);
        canAttackLV1 = false;
        cooltimeLV1 = 0;
    }else if(canAttackLV2 && lvl==2){
        ChickenSoldier *soldier;
        soldier = new ChickenSoldier(field_left, field_upper, this->harm_point[1], lvl, RIGHT, this->soldierimage[1][0], this->soldierimage[1][1], this->soldierimage[1][2]);
        this->chickensoldier_set.push_back(soldier);
        canAttackLV2 = false;
        cooltimeLV2 = 0;
    }else if(canAttackLV3 && lvl==3){
        ChickenSoldier *soldier;
        soldier = new ChickenSoldier(field_left, field_upper, this->harm_point[2], lvl, RIGHT, this->soldierimage[2][0], this->soldierimage[2][1], this->soldierimage[2][2]);
        this->chickensoldier_set.push_back(soldier);
        canAttackLV3 = false;
        cooltimeLV3 = 0;
    }else if(canAttackLV4 && lvl==4){
        ChickenSoldier *soldier;
        soldier = new ChickenSoldier(field_left, field_upper, this->harm_point[3], lvl, RIGHT, this->soldierimage[3][0], this->soldierimage[3][1], this->soldierimage[3][2]);
        this->chickensoldier_set.push_back(soldier);
        canAttackLV4 = false;
        cooltimeLV4 = 0;
    }else if(canAttackLV5 && lvl==5){
        ChickenSoldier *soldier;
        soldier = new ChickenSoldier(field_left, field_upper, this->harm_point[4], lvl, RIGHT, this->soldierimage[4][0], this->soldierimage[4][1], this->soldierimage[4][2]);
        this->chickensoldier_set.push_back(soldier);
        canAttackLV5 = false;
        cooltimeLV5 = 0;
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
    if(++life_count%100 && chickslife<10000*Level) chickslife += 100;
    if(cooltimeLV1<200) cooltimeLV1++;
    else if(cooltimeLV1==200) canAttackLV1 = true;
    if(cooltimeLV2<200) cooltimeLV2++;
    else if(cooltimeLV2==200) canAttackLV2 = true;
    if(cooltimeLV3<200) cooltimeLV3++;
    else if(cooltimeLV3==200) canAttackLV3 = true;
    if(cooltimeLV4<200) cooltimeLV4++;
    else if(cooltimeLV4==200) canAttackLV4 = true;
    if(cooltimeLV5<200) cooltimeLV5++;
    else if(cooltimeLV5==200) canAttackLV5 = true;

    for(unsigned int i=0; i < this->chickensoldier_set.size(); i++){
        chickensoldier_set[i]->Update();
        if(chickensoldier_set[i]->getX()>=field_right-400){
            ChickenSoldier *soldier = this->chickensoldier_set[i];
            this->chickensoldier_set.erase(this->chickensoldier_set.begin() + i);
            i--;
            delete soldier;
        }
    }
}
/*
void ChicksTower::AttackPoint(RabbitTower* tower){
        for(unsigned int i=0; i < this->chickensoldier_set.size(); i++){
            for(auto child: tower->rabbitsoldier_set){
                //chickensoldier_set[i]->AttackPoint(child);
        }
}
*/
