#include "TwoPlayer.h"

TwoPlayer::TwoPlayer(){
    char buffer[50];
    for(int i=0; i<5; i++){
        sprintf(buffer, "./character/2p_button%d_1.png", i+1);
        buttonimage[i][0] = al_load_bitmap(buffer);
        sprintf(buffer, "./character/2p_button%d_2.png", i+1);
        buttonimage[i][1] = al_load_bitmap(buffer);
    }
    for(int i=0; i<5; i++){
        sprintf(buffer, "./character/chickenLV%d_1.png", i+1);
        leftimage[i][0] = al_load_bitmap(buffer);
        sprintf(buffer, "./character/chickenLV%d_2.png", i+1);
        leftimage[i][1] = al_load_bitmap(buffer);
        sprintf(buffer, "./character/chickenLV%d_3.png", i+1);
        leftimage[i][2] = al_load_bitmap(buffer);
    }
    for(int i=0; i<5; i++){
        sprintf(buffer, "./character/rightLV%d_1.png", i+1);
        rightimage[i][0] = al_load_bitmap(buffer);
        sprintf(buffer, "./character/rightLV%d_2.png", i+1);
        rightimage[i][1] = al_load_bitmap(buffer);
        sprintf(buffer, "./character/rightLV%d_3.png", i+1);
        rightimage[i][2] = al_load_bitmap(buffer);
    }
    lefttower = new ChicksTower(RIGHT);///
    righttower = new RabbitTower(LEFT);///
    leftCoinInc = rightCoinInc = Coin_Limit;
    font = al_load_font("./fonts/pirulen.ttf", 40, 0);
}

TwoPlayer::~TwoPlayer(){
    delete lefttower;
    delete righttower;
    al_destroy_font(font);
    for(int i=0; i<5; i++){
        for(int j=0; j<2; j++)
            al_destroy_bitmap(buttonimage[i][j]);
        for(int j=0; j<3; j++){
            al_destroy_bitmap(leftimage[i][j]);
        }
    }
    for(int i=0; i<5; i++){
        for(int j=0; j<3; j++){
            al_destroy_bitmap(rightimage[i][j]);
        }
    }
    for(auto&& child: this->leftsoldier_set){
        delete child;
    }
    this->leftsoldier_set.clear();
    for(auto&& child: this->rightsoldier_set){
        delete child;
    }
    this->rightsoldier_set.clear();
}

void TwoPlayer::Draw(){
    lefttower->Draw();
    righttower->Draw();

    char buffer[50];
    sprintf(buffer, "$ %d/%d", leftCoinInc, Coin_Limit);
    al_draw_text(font, al_map_rgb(100, 100, 100), 700, 50, ALLEGRO_ALIGN_RIGHT, buffer);
    sprintf(buffer, "$ %d/%d", rightCoinInc, Coin_Limit);
    al_draw_text(font, al_map_rgb(100, 100, 100), 2300, 50, ALLEGRO_ALIGN_RIGHT, buffer);

    al_draw_bitmap(buttonimage[0][(leftcanAttackLV1? 1:0)], 475, 750, 0);
    al_draw_bitmap(buttonimage[1][(leftcanAttackLV2? 1:0)], 625, 750, 0);
    al_draw_bitmap(buttonimage[2][(leftcanAttackLV3? 1:0)], 775, 750, 0);
    al_draw_bitmap(buttonimage[3][(leftcanAttackLV4? 1:0)], 925, 750, 0);
    al_draw_bitmap(buttonimage[4][(leftcanAttackLV5? 1:0)], 1075, 750, 0);
    al_draw_bitmap(buttonimage[0][(rightcanAttackLV1? 1:0)], 1225, 750, 0);
    al_draw_bitmap(buttonimage[1][(rightcanAttackLV2? 1:0)], 1375, 750, 0);
    al_draw_bitmap(buttonimage[2][(rightcanAttackLV3? 1:0)], 1525, 750, 0);
    al_draw_bitmap(buttonimage[3][(rightcanAttackLV4? 1:0)], 1675, 750, 0);
    al_draw_bitmap(buttonimage[4][(rightcanAttackLV5? 1:0)], 1825, 750, 0);

    for(unsigned int i=0; i<this->leftsoldier_set.size(); i++){
        this->leftsoldier_set[i]->Draw();
    }
    for(unsigned int i=0; i<this->rightsoldier_set.size(); i++){
        this->rightsoldier_set[i]->Draw();
    }
}

void TwoPlayer::leftAttack(){
    lefttower->Attack();
}
void TwoPlayer::rightAttack(){
    righttower->Attack();
}
void TwoPlayer::leftAttack(int atk){
    if(leftcanAttackLV1 && atk==1){
        ChickenSoldier *soldier;
        soldier = new ChickenSoldier(field_left, field_upper+50, this->harm_point[0], atk, RIGHT, this->leftimage[0][0], this->leftimage[0][1], this->leftimage[0][2]);
        this->leftsoldier_set.push_back(soldier);
        leftcanAttackLV1 = false;
        leftcooltimeLV1 = 0;
        leftCoinInc -= coinLV1;
    }else if(leftcanAttackLV2 && atk==2){
        ChickenSoldier *soldier;
        soldier = new ChickenSoldier(field_left, field_upper+50, this->harm_point[1], atk, RIGHT, this->leftimage[1][0], this->leftimage[1][1], this->leftimage[1][2]);
        this->leftsoldier_set.push_back(soldier);
        leftcanAttackLV2 = false;
        leftcooltimeLV2 = 0;
        leftCoinInc -= coinLV2;
    }else if(leftcanAttackLV3 && atk==3){
        ChickenSoldier *soldier;
        soldier = new ChickenSoldier(field_left, field_upper+50, this->harm_point[2], atk, RIGHT, this->leftimage[2][0], this->leftimage[2][1], this->leftimage[2][2]);
        this->leftsoldier_set.push_back(soldier);
        leftcanAttackLV3 = false;
        leftcooltimeLV3 = 0;
        leftCoinInc -= coinLV3;
    }else if(leftcanAttackLV4 && atk==4){
        ChickenSoldier *soldier;
        soldier = new ChickenSoldier(field_left, field_upper+50, this->harm_point[3], atk, RIGHT, this->leftimage[3][0], this->leftimage[3][1], this->leftimage[3][2]);
        this->leftsoldier_set.push_back(soldier);
        leftcanAttackLV4 = false;
        leftcooltimeLV4 = 0;
        leftCoinInc -= coinLV4;
    }else if(leftcanAttackLV5 && atk==5){
        ChickenSoldier *soldier;
        soldier = new ChickenSoldier(field_left, field_upper+50, this->harm_point[4], atk, RIGHT, this->leftimage[4][0], this->leftimage[4][1], this->leftimage[4][2]);
        this->leftsoldier_set.push_back(soldier);
        leftcanAttackLV5 = false;
        leftcooltimeLV5 = 0;
        leftCoinInc -= coinLV5;
    }
}

void TwoPlayer::rightAttack(int atk){
    if(rightcanAttackLV1 && atk==1){
        RabbitSoldier *soldier;
        soldier = new RabbitSoldier(field_right-200, field_upper+50, this->harm_point[0], atk, LEFT, this->rightimage[0][0], this->rightimage[0][1], this->rightimage[0][2]);
        this->rightsoldier_set.push_back(soldier);
        rightcanAttackLV1 = false;
        rightcooltimeLV1 = 0;
        rightCoinInc -= coinLV1;
    }else if(rightcanAttackLV2 && atk==2){
        RabbitSoldier *soldier;
        soldier = new RabbitSoldier(field_right-200, field_upper+50, this->harm_point[1], atk, LEFT, this->rightimage[1][0], this->rightimage[1][1], this->rightimage[1][2]);
        this->rightsoldier_set.push_back(soldier);
        rightcanAttackLV2 = false;
        rightcooltimeLV2 = 0;
        rightCoinInc -= coinLV2;
    }else if(rightcanAttackLV3 && atk==3){
        RabbitSoldier *soldier;
        soldier = new RabbitSoldier(field_right-200, field_upper+50, this->harm_point[2], atk, LEFT, this->rightimage[2][0], this->rightimage[2][1], this->rightimage[2][2]);
        this->rightsoldier_set.push_back(soldier);
        rightcanAttackLV3 = false;
        rightcooltimeLV3 = 0;
        rightCoinInc -= coinLV3;
    }else if(rightcanAttackLV4 && atk==4){
        RabbitSoldier *soldier;
        soldier = new RabbitSoldier(field_right-200, field_upper+50, this->harm_point[3], atk, LEFT, this->rightimage[3][0], this->rightimage[3][1], this->rightimage[3][2]);
        this->rightsoldier_set.push_back(soldier);
        rightcanAttackLV4 = false;
        rightcooltimeLV4 = 0;
        rightCoinInc -= coinLV4;
    }else if(rightcanAttackLV5 && atk==5){
        RabbitSoldier *soldier;
        soldier = new RabbitSoldier(field_right-200, field_upper+50, this->harm_point[4], atk, LEFT, this->rightimage[4][0], this->rightimage[4][1], this->rightimage[4][2]);
        this->rightsoldier_set.push_back(soldier);
        rightcanAttackLV5 = false;
        rightcooltimeLV5 = 0;
        rightCoinInc -= coinLV5;
    }
}

Status TwoPlayer::UpdateAttack(){
    Status status;
    if(leftCoinInc<Coin_Limit){
        leftCoinCount++;
        if(leftCoinCount/CoinSpeed==1){
            leftCoinInc += 10;
            leftCoinCount = 0;
        }
    }
    if(rightCoinInc<Coin_Limit){
        rightCoinCount++;
        if(rightCoinCount/CoinSpeed==1){
            rightCoinInc += 10;
            rightCoinCount = 0;
        }
    }

    status.win_lose = GAME_CONTI;
    //status.level_coin = CoinInc;

    lefttower->UpdateAttack();
    righttower->UpdateAttack();

    if(leftcooltimeLV1<200) leftcooltimeLV1++;
    else if(leftcooltimeLV1==200 && leftCoinInc>=coinLV1) leftcanAttackLV1 = true;
    if(leftcooltimeLV2<200) leftcooltimeLV2++;
    else if(leftcooltimeLV2==200 && leftCoinInc>=coinLV2) leftcanAttackLV2 = true;
    if(leftcooltimeLV3<200) leftcooltimeLV3++;
    else if(leftcooltimeLV3==200 && leftCoinInc>=coinLV3) leftcanAttackLV3 = true;
    if(leftcooltimeLV4<200) leftcooltimeLV4++;
    else if(leftcooltimeLV4==200 && leftCoinInc>=coinLV4) leftcanAttackLV4 = true;
    if(leftcooltimeLV5<200) leftcooltimeLV5++;
    else if(leftcooltimeLV5==200 && leftCoinInc>=coinLV5) leftcanAttackLV5 = true;
    if(rightcooltimeLV1<200) rightcooltimeLV1++;
    else if(rightcooltimeLV1==200 && rightCoinInc>=coinLV1) rightcanAttackLV1 = true;
    if(rightcooltimeLV2<200) rightcooltimeLV2++;
    else if(rightcooltimeLV2==200 && rightCoinInc>=coinLV2) rightcanAttackLV2 = true;
    if(rightcooltimeLV3<200) rightcooltimeLV3++;
    else if(rightcooltimeLV3==200 && rightCoinInc>=coinLV3) rightcanAttackLV3 = true;
    if(rightcooltimeLV4<200) rightcooltimeLV4++;
    else if(rightcooltimeLV4==200 && rightCoinInc>=coinLV4) rightcanAttackLV4 = true;
    if(rightcooltimeLV5<200) rightcooltimeLV5++;
    else if(rightcooltimeLV5==200 && rightCoinInc>=coinLV5) rightcanAttackLV5 = true;

    ///check if the chick is attacked
    for(unsigned int i=0; i<this->leftsoldier_set.size(); i++){
        for(unsigned int j=0; j<this->rightsoldier_set.size(); j++){
            if(rightsoldier_set[j]->Bullet_Attack(leftsoldier_set[i])){
                //printf("overlaped");
                if(leftsoldier_set[i]->isAttacked()){
                    ChickenSoldier *soldier = this->leftsoldier_set[i];
                    this->leftsoldier_set.erase(this->leftsoldier_set.begin() + i);
                    i--;
                    delete soldier;
                }
                break;
            }
        }
    }
    ///check if the rabbit is attacked
    for(unsigned int i=0; i<this->rightsoldier_set.size(); i++){
        for(unsigned int j=0; j<this->leftsoldier_set.size(); j++){
            if(leftsoldier_set[j]->Bullet_Attack(rightsoldier_set[i])){
                //printf("overlaped");
                if(rightsoldier_set[i]->isAttacked()){
                    RabbitSoldier *soldier = this->rightsoldier_set[i];
                    this->rightsoldier_set.erase(this->rightsoldier_set.begin() + i);
                    i--;
                    delete soldier;
                }
                break;
            }
        }
    }

    ///check if the chick tower is attacking rabbit tower
    if(lefttower->isBulletAttack(righttower)) status.win_lose = RIGHT_WIN;
    ///check if the rabbit tower is attacking chick tower
    if(righttower->isBulletAttack(lefttower)) status.win_lose = LEFT_WIN;

    ///update chicks
    for(unsigned int i=0; i<this->leftsoldier_set.size(); i++){
        leftsoldier_set[i]->Update();
        //check if the chick reach the end and attack the tower
        if(leftsoldier_set[i]->getX()>=field_right-400){
            ChickenSoldier *soldier = this->leftsoldier_set[i];
            this->leftsoldier_set.erase(this->leftsoldier_set.begin() + i);
            i--;
            delete soldier;
            if(righttower->isAttacked()) status.win_lose = LEFT_WIN;
        }
    }
    ///update rabbits
    for(unsigned int i=0; i < this->rightsoldier_set.size(); i++){
        rightsoldier_set[i]->Update();
        if(rightsoldier_set[i]->getX()<=field_left){
            RabbitSoldier *soldier = this->rightsoldier_set[i];
            this->rightsoldier_set.erase(this->rightsoldier_set.begin() + i);
            i--;
            delete soldier;
            if(lefttower->isAttacked()) status.win_lose = RIGHT_WIN;
        }
    }

    return status;
}
