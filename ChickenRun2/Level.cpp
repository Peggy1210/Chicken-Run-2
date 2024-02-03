#include "Level.h"

Level::Level(int lvl, int chicklvl, int HP){
    char buffer[50];
    this->level = lvl;
    for(int i=0; i<5; i++){
        sprintf(buffer, "./character/button%d_1.png", i+1);
        buttonimage[i][0] = al_load_bitmap(buffer);
        sprintf(buffer, "./character/button%d_2.png", i+1);
        buttonimage[i][1] = al_load_bitmap(buffer);
    }
    for(int i=0; i<5; i++){
        sprintf(buffer, "./character/chickenLV%d_1.png", i+1);
        chicksoldierimage[i][0] = al_load_bitmap(buffer);
        sprintf(buffer, "./character/chickenLV%d_2.png", i+1);
        chicksoldierimage[i][1] = al_load_bitmap(buffer);
        sprintf(buffer, "./character/chickenLV%d_3.png", i+1);
        chicksoldierimage[i][2] = al_load_bitmap(buffer);
    }
    for(int i=0; i<5; i++){
        sprintf(buffer, "./character/rabbitLV%d_1.png", i+1);
        rabbitsoldierimage[i][0] = al_load_bitmap(buffer);
        sprintf(buffer, "./character/rabbitLV%d_2.png", i+1);
        rabbitsoldierimage[i][1] = al_load_bitmap(buffer);
        sprintf(buffer, "./character/rabbitLV%d_3.png", i+1);
        rabbitsoldierimage[i][2] = al_load_bitmap(buffer);
    }
    sprintf(buffer, "LEVEL%d.txt", level);
    file = fopen(buffer, "r");
    fscanf(file, "%s", buffer);
    countTime = atoi(buffer);
    fscanf(file, "%s", buffer);
    soldierLV = atoi(buffer);
    chickstower = new ChicksTower(chicklvl, RIGHT, HP);
    rabbittower = new RabbitTower(lvl, LEFT);
    CoinInc = Coin_Limit;
    font = al_load_font("./fonts/pirulen.ttf", 40, 0);
}

Level::~Level(){
    delete chickstower;
    delete rabbittower;
    al_destroy_font(font);
    for(int i=0; i<5; i++){
        for(int j=0; j<2; j++)
            al_destroy_bitmap(buttonimage[i][j]);
        for(int j=0; j<3; j++){
            al_destroy_bitmap(chicksoldierimage[i][j]);
        }
    }
    for(int i=0; i<5; i++){
        for(int j=0; j<3; j++){
            al_destroy_bitmap(rabbitsoldierimage[i][j]);
        }
    }
    for(auto&& child: this->chickensoldier_set){
        delete child;
    }
    this->chickensoldier_set.clear();
    for(auto&& child: this->rabbitsoldier_set){
        delete child;
    }
    this->rabbitsoldier_set.clear();
}

void Level::Draw(){
    chickstower->Draw();
    rabbittower->Draw();

    char buffer[50];
    sprintf(buffer, "$ %d/%d", CoinInc, Coin_Limit);
    al_draw_text(font, al_map_rgb(100, 100, 100), 2300, 50, ALLEGRO_ALIGN_RIGHT, buffer);

    al_draw_bitmap(buttonimage[0][(canAttackLV1? 1:0)], 500, 750, 0);
    al_draw_bitmap(buttonimage[1][(canAttackLV2? 1:0)], 800, 750, 0);
    al_draw_bitmap(buttonimage[2][(canAttackLV3? 1:0)], 1100, 750, 0);
    al_draw_bitmap(buttonimage[3][(canAttackLV4? 1:0)], 1400, 750, 0);
    al_draw_bitmap(buttonimage[4][(canAttackLV5? 1:0)], 1700, 750, 0);
    for(unsigned int i=0; i<this->chickensoldier_set.size(); i++){
        this->chickensoldier_set[i]->Draw();
    }
    for(unsigned int i=0; i<this->rabbitsoldier_set.size(); i++){
        this->rabbitsoldier_set[i]->Draw();
    }
}

void Level::Attack(){
    chickstower->Attack();
}
void Level::Attack(int atk){
    if(canAttackLV1 && atk==1){
        ChickenSoldier *soldier;
        soldier = new ChickenSoldier(field_left, field_upper+50, this->harm_point[0], atk, RIGHT, this->chicksoldierimage[0][0], this->chicksoldierimage[0][1], this->chicksoldierimage[0][2]);
        this->chickensoldier_set.push_back(soldier);
        canAttackLV1 = false;
        cooltimeLV1 = 0;
        CoinInc -= coinLV1;
    }else if(canAttackLV2 && atk==2){
        ChickenSoldier *soldier;
        soldier = new ChickenSoldier(field_left, field_upper+50, this->harm_point[1], atk, RIGHT, this->chicksoldierimage[1][0], this->chicksoldierimage[1][1], this->chicksoldierimage[1][2]);
        this->chickensoldier_set.push_back(soldier);
        canAttackLV2 = false;
        cooltimeLV2 = 0;
        CoinInc -= coinLV2;
    }else if(canAttackLV3 && atk==3){
        ChickenSoldier *soldier;
        soldier = new ChickenSoldier(field_left, field_upper+50, this->harm_point[2], atk, RIGHT, this->chicksoldierimage[2][0], this->chicksoldierimage[2][1], this->chicksoldierimage[2][2]);
        this->chickensoldier_set.push_back(soldier);
        canAttackLV3 = false;
        cooltimeLV3 = 0;
        CoinInc -= coinLV3;
    }else if(canAttackLV4 && atk==4){
        ChickenSoldier *soldier;
        soldier = new ChickenSoldier(field_left, field_upper+50, this->harm_point[3], atk, RIGHT, this->chicksoldierimage[3][0], this->chicksoldierimage[3][1], this->chicksoldierimage[3][2]);
        this->chickensoldier_set.push_back(soldier);
        canAttackLV4 = false;
        cooltimeLV4 = 0;
        CoinInc -= coinLV4;
    }else if(canAttackLV5 && atk==5){
        ChickenSoldier *soldier;
        soldier = new ChickenSoldier(field_left, field_upper+50, this->harm_point[4], atk, RIGHT, this->chicksoldierimage[4][0], this->chicksoldierimage[4][1], this->chicksoldierimage[4][2]);
        this->chickensoldier_set.push_back(soldier);
        canAttackLV5 = false;
        cooltimeLV5 = 0;
        CoinInc -= coinLV5;
    }
}

void Level::RabbitAttack(int lvl){
    RabbitSoldier *soldier;
    soldier = new RabbitSoldier(field_right-400, field_upper+50, this->harm_point[lvl-1], lvl, LEFT, this->rabbitsoldierimage[lvl-1][0], this->rabbitsoldierimage[lvl-1][1], this->rabbitsoldierimage[lvl-1][2]);
    this->rabbitsoldier_set.push_back(soldier);
}

Status Level::UpdateAttack(){
    Status status;
    if(CoinInc<Coin_Limit){
        CoinCount++;
        if(CoinCount/CoinSpeed==1){
            CoinInc += 10;
            CoinCount = 0;
        }
    }
    status.win_lose = GAME_CONTI;
    status.level_coin = CoinInc;

    chickstower->UpdateAttack();
    rabbittower->UpdateAttack();

    if(cooltimeLV1<200) cooltimeLV1++;
    else if(cooltimeLV1==200 && CoinInc>=coinLV1) canAttackLV1 = true;
    if(cooltimeLV2<200) cooltimeLV2++;
    else if(cooltimeLV2==200 && CoinInc>=coinLV2) canAttackLV2 = true;
    if(cooltimeLV3<200) cooltimeLV3++;
    else if(cooltimeLV3==200 && CoinInc>=coinLV3) canAttackLV3 = true;
    if(cooltimeLV4<200) cooltimeLV4++;
    else if(cooltimeLV4==200 && CoinInc>=coinLV4) canAttackLV4 = true;
    if(cooltimeLV5<200) cooltimeLV5++;
    else if(cooltimeLV5==200 && CoinInc>=coinLV5) canAttackLV5 = true;

    ///check if the chick is attacked
    for(unsigned int i=0; i<this->chickensoldier_set.size(); i++){
        for(unsigned int j=0; j<this->rabbitsoldier_set.size(); j++){
            if(rabbitsoldier_set[j]->Bullet_Attack(chickensoldier_set[i])){
                //printf("overlaped");
                if(chickensoldier_set[i]->isAttacked()){
                    ChickenSoldier *soldier = this->chickensoldier_set[i];
                    this->chickensoldier_set.erase(this->chickensoldier_set.begin() + i);
                    i--;
                    delete soldier;
                }
                break;
            }
        }
    }
    ///check if the rabbit is attacked
    for(unsigned int i=0; i<this->rabbitsoldier_set.size(); i++){
        for(unsigned int j=0; j<this->chickensoldier_set.size(); j++){
            if(chickensoldier_set[j]->Bullet_Attack(rabbitsoldier_set[i])){
                //printf("overlaped");
                if(rabbitsoldier_set[i]->isAttacked()){
                    RabbitSoldier *soldier = this->rabbitsoldier_set[i];
                    this->rabbitsoldier_set.erase(this->rabbitsoldier_set.begin() + i);
                    i--;
                    delete soldier;
                }
                break;
            }
        }
    }

    ///check if the chick tower is attacking rabbit tower
    if(chickstower->isBulletAttack(rabbittower)) status.win_lose = WIN;
    ///check if the rabbit tower is attacking chick tower
    if(rabbittower->isBulletAttack(chickstower)) status.win_lose = LOSE;

    ///send rabbit soldier
    if(this->soldiercooltime<this->countTime && !level_ended) this->soldiercooltime++;
    else if(this->soldiercooltime==this->countTime && !level_ended){
        //printf("%d ", soldierLV);
        this->RabbitAttack(soldierLV);
        char buffer[50];
        this->soldiercooltime = 0;
        if(fscanf(file, "%s", buffer)!=EOF) this->countTime = atoi(buffer);
        else level_ended = true;
        if(fscanf(file, "%s", buffer)!=EOF) this->soldierLV = atoi(buffer);
    }

    ///update chicks
    for(unsigned int i=0; i<this->chickensoldier_set.size(); i++){
        chickensoldier_set[i]->Update();
        //check if the chick reach the end and attack the tower
        if(chickensoldier_set[i]->getX()>=field_right-400){

            ChickenSoldier *soldier = this->chickensoldier_set[i];
            this->chickensoldier_set.erase(this->chickensoldier_set.begin() + i);
            i--;
            delete soldier;
            if(rabbittower->isAttacked()) status.win_lose = WIN;
        }
    }
    ///update rabbits
    for(unsigned int i=0; i < this->rabbitsoldier_set.size(); i++){
        rabbitsoldier_set[i]->Update();
        if(rabbitsoldier_set[i]->getX()<=field_left){
            RabbitSoldier *soldier = this->rabbitsoldier_set[i];
            this->rabbitsoldier_set.erase(this->rabbitsoldier_set.begin() + i);
            i--;
            delete soldier;
            if(chickstower->isAttacked()) status.win_lose = LOSE;
        }
    }

    return status;
}

