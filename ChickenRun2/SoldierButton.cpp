#include "SoldierButton.h"

SoldierButton::SoldierButton(int lvl){
    for(int i=0; i<5; i++){
        char buffer1[50];
        sprintf(buffer1, "./character/button%d_1.png", i+1);
        buttonimage[i][0] = al_load_bitmap(buffer1);
        char buffer2[50];
        sprintf(buffer2, "./character/button%d_2.png", i+1);
        buttonimage[i][1] = al_load_bitmap(buffer2);
    }
    for(int i=0; i<5; i++){
        char buffer1[50], buffer2[50], buffer3[50];
        sprintf(buffer1, "./character/chickenLV%d_1.png", i+1);
        soldierimage[i][0] = al_load_bitmap(buffer1);
        sprintf(buffer2, "./character/chickenLV%d_2.png", i+1);
        soldierimage[i][1] = al_load_bitmap(buffer2);
        sprintf(buffer3, "./character/chickenLV%d_3.png", i+1);
        soldierimage[i][2] = al_load_bitmap(buffer3);
    }
    this->Level = lvl;
}

SoldierButton::~SoldierButton(){

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

void SoldierButton::Draw(){
    al_draw_bitmap(buttonimage[0][(canAttackLV1? 1:0)], 500, 750, 0);
    al_draw_bitmap(buttonimage[1][(canAttackLV2? 1:0)], 800, 750, 0);
    al_draw_bitmap(buttonimage[2][(canAttackLV3? 1:0)], 1100, 750, 0);
    al_draw_bitmap(buttonimage[3][(canAttackLV4? 1:0)], 1400, 750, 0);
    al_draw_bitmap(buttonimage[4][(canAttackLV5? 1:0)], 1700, 750, 0);

    for(unsigned int i=0; i<this->chickensoldier_set.size(); i++){
        this->chickensoldier_set[i]->Draw();
    }

    /*if(!canAttackLV1){
        al_draw_filled_rectangle(500, 750, 700, 950, al_map_rgba(200, 200, 200, 500));
    }
    if(!canAttackLV2){
        al_draw_filled_rectangle(800, 750, 1000, 950, al_map_rgba(200, 200, 200, 500));
    }
    if(!canAttackLV3){
        al_draw_filled_rectangle(1100, 750, 1300, 950, al_map_rgba(200, 200, 200, 500));
    }
    if(!canAttackLV4){
        al_draw_filled_rectangle(1400, 750, 1600, 950, al_map_rgba(200, 200, 200, 500));
    }
    if(!canAttackLV5){
        al_draw_filled_rectangle(1700, 750, 1900, 950, al_map_rgba(200, 200, 200, 500));
    }
    //printf("%d %d %d %d %d\n", cooltimeLV1, cooltimeLV2, cooltimeLV3, cooltimeLV4, cooltimeLV5);
    /*al_draw_filled_rectangle(500, 950-cooltimeLV1, 700, 950, al_map_rgb((int)255*((float)cooltimeLV1/201), 0, 0));
    al_draw_filled_rectangle(800, 950-cooltimeLV2, 1000, 950, al_map_rgb((int)255*((float)cooltimeLV2/201), 0, 0));
    al_draw_filled_rectangle(1100, 950-cooltimeLV3, 1300, 950, al_map_rgb((int)255*((float)cooltimeLV3/201), 0, 0));
    al_draw_filled_rectangle(1400, 950-cooltimeLV4, 1600, 950, al_map_rgb((int)255*((float)cooltimeLV4/201), 0, 0));
    al_draw_filled_rectangle(1700, 950-cooltimeLV5, 1900, 950, al_map_rgb((int)255*((float)cooltimeLV5/201), 0, 0));*/
}

void SoldierButton::Attack(int lvl){
    if(canAttackLV1 && lvl==1){
        ChickenSoldier *soldier;
        soldier = new ChickenSoldier(200, 200, this->harm_point[0], lvl, RIGHT, this->soldierimage[0][0], this->soldierimage[0][1], this->soldierimage[0][2]);
        this->chickensoldier_set.push_back(soldier);
        canAttackLV1 = false;
        cooltimeLV1 = 0;
    }else if(canAttackLV2 && lvl==2){
        ChickenSoldier *soldier;
        soldier = new ChickenSoldier(200, 200, this->harm_point[1], lvl, RIGHT, this->soldierimage[1][0], this->soldierimage[1][1], this->soldierimage[1][2]);
        this->chickensoldier_set.push_back(soldier);
        canAttackLV2 = false;
        cooltimeLV2 = 0;
    }else if(canAttackLV3 && lvl==3){
        ChickenSoldier *soldier;
        soldier = new ChickenSoldier(200, 200, this->harm_point[2], lvl, RIGHT, this->soldierimage[2][0], this->soldierimage[2][1], this->soldierimage[2][2]);
        this->chickensoldier_set.push_back(soldier);
        canAttackLV3 = false;
        cooltimeLV3 = 0;
    }else if(canAttackLV4 && lvl==4){
        ChickenSoldier *soldier;
        soldier = new ChickenSoldier(200, 200, this->harm_point[3], lvl, RIGHT, this->soldierimage[3][0], this->soldierimage[3][1], this->soldierimage[3][2]);
        this->chickensoldier_set.push_back(soldier);
        canAttackLV4 = false;
        cooltimeLV4 = 0;
    }else if(canAttackLV5 && lvl==5){
        ChickenSoldier *soldier;
        soldier = new ChickenSoldier(200, 200, this->harm_point[4], lvl, RIGHT, this->soldierimage[4][0], this->soldierimage[4][1], this->soldierimage[4][2]);
        this->chickensoldier_set.push_back(soldier);
        canAttackLV5 = false;
        cooltimeLV5 = 0;
    }
}

void SoldierButton::UpdateAttack(){
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
        /*if(towerbullet_set[i]->getX()>=window_width){
            Bullet *bullet = this->towerbullet_set[i];
            this->towerbullet_set.erase(this->towerbullet_set.begin() + i);
            i--;
            delete bullet;
        }*/
    }
    //printf("%d", cooltime);
}
