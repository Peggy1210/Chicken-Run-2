#include "ComputerSoldier.h"

ComputerSoldier::ComputerSoldier(int lvl){
    for(int i=0; i<5; i++){
        char buffer1[50], buffer2[50], buffer3[50];
        sprintf(buffer1, "./character/rabbitLV%d_1.png", i+1);
        soldierimage[i][0] = al_load_bitmap(buffer1);
        sprintf(buffer2, "./character/rabbitLV%d_2.png", i+1);
        soldierimage[i][1] = al_load_bitmap(buffer2);
        sprintf(buffer3, "./character/rabbitLV%d_3.png", i+1);
        soldierimage[i][2] = al_load_bitmap(buffer3);
    }
    this->Level = lvl;

    char buffer[50];
    sprintf(buffer, "LEVEL%d.txt", Level);
    file = fopen(buffer, "r");
    fscanf(file, "%s", buffer);
    countTime = atoi(buffer);
    fscanf(file, "%s", buffer);
    soldierLV = atoi(buffer);
}

ComputerSoldier::~ComputerSoldier(){

    for(int i=0; i<5; i++){
        for(int j=0; j<3; j++){
            al_destroy_bitmap(soldierimage[i][j]);
        }
    }

    for(auto&& child: this->soldier_set){
        delete child;
    }
    this->soldier_set.clear();
}

void ComputerSoldier::Draw(){

    for(unsigned int i=0; i<this->soldier_set.size(); i++){
        this->soldier_set[i]->Draw();
    }
}

void ComputerSoldier::Attack(int lvl){
    if(lvl==1){
        RabbitSoldier *soldier;
        soldier = new RabbitSoldier(window_width-500, 200, this->harm_point[0], lvl, LEFT, this->soldierimage[0][0], this->soldierimage[0][1], this->soldierimage[0][2]);
        this->soldier_set.push_back(soldier);
    }else if(lvl==2){
        RabbitSoldier *soldier;
        soldier = new RabbitSoldier(window_width-500, 200, this->harm_point[1], lvl, LEFT, this->soldierimage[1][0], this->soldierimage[1][1], this->soldierimage[1][2]);
        this->soldier_set.push_back(soldier);
    }else if(lvl==3){
        RabbitSoldier *soldier;
        soldier = new RabbitSoldier(window_width-500, 200, this->harm_point[2], lvl, LEFT, this->soldierimage[2][0], this->soldierimage[2][1], this->soldierimage[2][2]);
        this->soldier_set.push_back(soldier);
    }else if(lvl==4){
        RabbitSoldier *soldier;
        soldier = new RabbitSoldier(window_width-500, 200, this->harm_point[3], lvl, LEFT, this->soldierimage[3][0], this->soldierimage[3][1], this->soldierimage[3][2]);
        this->soldier_set.push_back(soldier);
    }else if(lvl==5){
        RabbitSoldier *soldier;
        soldier = new RabbitSoldier(window_width-500, 200, this->harm_point[4], lvl, LEFT, this->soldierimage[4][0], this->soldierimage[4][1], this->soldierimage[4][2]);
        this->soldier_set.push_back(soldier);
    }
}

void ComputerSoldier::UpdateAttack(){
    if(this->soldier_cooltime<this->countTime) this->soldier_cooltime++;
    else if(this->soldier_cooltime==this->countTime){
        printf("%d ", soldierLV);
        this->Attack(soldierLV);
        char buffer[50];
        this->soldier_cooltime = 0;
        fscanf(file, "%s", buffer);
        this->countTime = atoi(buffer);
        fscanf(file, "%s", buffer);
        this->soldierLV = atoi(buffer);
    }
    /*for(auto child:Soldier->chickensoldier_set){
            for(auto bullet:soldier_set[i]->chickbullet_set){
                if(circle::isOverlap(child->circle, bullet->circle)){
                    Bullet *tmp = bullet;
                    Soldier->chickbullet_set.erase(Soldier->chickbullet_set.begin() + i);
                    i--;
                    delete tmp;
                }
            }
        }*/

    for(unsigned int i=0; i < this->soldier_set.size(); i++){

        soldier_set[i]->Update();
        /*if(towerbullet_set[i]->getX()>=window_width){
            Bullet *bullet = this->towerbullet_set[i];
            this->towerbullet_set.erase(this->towerbullet_set.begin() + i);
            i--;
            delete bullet;
        }*/
    }
    //printf("%d", soldier_cooltime);
}
