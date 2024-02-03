#include "RabbitTower.h"
#include "RabbitSoldier.cpp"

RabbitTower::RabbitTower(int level, int dir){
    this->direction = dir;
    this->circle = new Circle(window_width-500, 400, 100);
    char buffer[50];
    sprintf(buffer, "./tower/TowerLV4.png");
    TowerImage = al_load_bitmap(buffer);
    sprintf(buffer, "./tower/BulletLV4.png");
    BulletImage = al_load_bitmap(buffer);
    chickslife = 10000*level;
    Level = level;
    font = al_load_font("./fonts/pirulen.ttf", 24, 0);
    for(int i=0; i<5; i++){
        sprintf(buffer, "./character/rabbitLV%d_1.png", i+1);
        soldierimage[i][0] = al_load_bitmap(buffer);
        sprintf(buffer, "./character/rabbitLV%d_2.png", i+1);
        soldierimage[i][1] = al_load_bitmap(buffer);
        sprintf(buffer, "./character/rabbitLV%d_3.png", i+1);
        soldierimage[i][2] = al_load_bitmap(buffer);
    }
    sprintf(buffer, "LEVEL%d.txt", Level);
    file = fopen(buffer, "r");
    fscanf(file, "%s", buffer);
    countTime = atoi(buffer);
    fscanf(file, "%s", buffer);
    soldierLV = atoi(buffer);
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
    for(int i=0; i<5; i++){
        for(int j=0; j<3; j++){
            al_destroy_bitmap(soldierimage[i][j]);
        }
    }

    for(auto&& child: this->rabbitsoldier_set){
        delete child;
    }
    this->rabbitsoldier_set.clear();
}

void RabbitTower::Draw(){
    al_draw_bitmap(TowerImage, window_width-600, 200, 0);

    char buffer[50];
    sprintf(buffer, "HP %d", chickslife);
    al_draw_text(font, al_map_rgb(0, 0, 0), window_width-500, 100, ALLEGRO_ALIGN_LEFT, buffer);

    for(unsigned int i=0; i<this->towerbullet_set.size(); i++){
        this->towerbullet_set[i]->Draw();
    }

    for(unsigned int i=0; i<this->rabbitsoldier_set.size(); i++){
        this->rabbitsoldier_set[i]->Draw();
    }

    al_draw_bitmap(cooltimeimg_lower, window_width-300, window_height-300, 0);
    al_draw_filled_rectangle(window_width-300, window_height-300, window_width, window_height-((float)cooltime/5)*3, al_map_rgba(150, 150, 150, 200));
    al_draw_bitmap(cooltimeimg_upper, window_width-300, window_height-300, 0);

    //al_draw_filled_rectangle(window_width-50, window_height-cooltime*2, window_width, window_height, al_map_rgba((int)255*((float)cooltime/501), 0, 0, 100));
}

void RabbitTower::Attack(){
    if(canAttack){
        Bullet *bullet;
        bullet = new Bullet(window_width-600, 200, this->bullet_harm_point, this->bullet_velocity, direction, this->BulletImage);
        this->towerbullet_set.push_back(bullet);
        canAttack = false;
        cooltime = 0;
    }
}

void RabbitTower::Attack(int lvl){
    RabbitSoldier *soldier;
    soldier = new RabbitSoldier(window_width-500, 200, this->harm_point[lvl-1], lvl, LEFT, this->soldierimage[lvl-1][0], this->soldierimage[lvl-1][1], this->soldierimage[lvl-1][2]);
    this->rabbitsoldier_set.push_back(soldier);
}

void RabbitTower::UpdateAttack(){
    if(cooltime<500) cooltime++;
    if(cooltime==500) canAttack = true;
    this->Attack();
    for(unsigned int i=0; i < this->towerbullet_set.size(); i++){
        towerbullet_set[i]->Update();
        if(towerbullet_set[i]->getX()>=field_left){
            Bullet *bullet = this->towerbullet_set[i];
            this->towerbullet_set.erase(this->towerbullet_set.begin() + i);
            i--;
            delete bullet;
        }
    }
    //printf("%d", cooltime);
    if(this->soldiercooltime<this->countTime) this->soldiercooltime++;
    else if(this->soldiercooltime==this->countTime){
        printf("%d ", soldierLV);
        this->Attack(soldierLV);
        char buffer[50];
        this->soldiercooltime = 0;
        fscanf(file, "%s", buffer);
        this->countTime = atoi(buffer);
        fscanf(file, "%s", buffer);
        this->soldierLV = atoi(buffer);
    }
    for(unsigned int i=0; i < this->rabbitsoldier_set.size(); i++){
        rabbitsoldier_set[i]->Update();
        if(rabbitsoldier_set[i]->getX()<=field_left){
            RabbitSoldier *soldier = this->rabbitsoldier_set[i];
            this->rabbitsoldier_set.erase(this->rabbitsoldier_set.begin() + i);
            i--;
            delete soldier;
        }
    }
}
