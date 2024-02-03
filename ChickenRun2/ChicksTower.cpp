#include "ChicksTower.h"

ChicksTower::ChicksTower(int level){
    this->circle = new Circle(200, 200, 100);
}

ChicksTower::~ChicksTower(){
    delete circle;

    ///al_destroy_bitmap(img);
    ///al_destroy_bitmap(attack_img);

    for(auto&& child : this->attack_set){
        delete child;
    }
    this->attack_set.clear();
}

void ChicksTower::Draw(){
    /*int draw_x = circle->x - (TowerWidth[this->type]/2);
    int draw_y = circle->y - (TowerHeight[this->type] - (TowerWidth[this->type]/2));


    al_draw_bitmap(img, draw_x, draw_y, 0);

    for(unsigned int i=0; i<this->attack_set.size(); i++)
        this->attack_set[i]->Draw();

    if(isClicked){
        al_draw_filled_circle(circle->x, circle->y, circle->r, al_map_rgba(196, 79, 79, 200));
        al_draw_filled_circle(circle->x, circle->y, 2, al_map_rgb(0, 0, 0));
    }*/
}

/*bool ChicksTower::DetectAttack(Monster *monster){
    bool willAttack = false;
    Attack *attack;

    if(Circle::isOverlap(this->circle, monster->getCircle()))
    {
        if(attack_counter == 0)
        {
            attack = new Attack(
                this->circle,
                monster->getCircle(),
                this->attack_harm_point,
                this->attack_velocity,
                this->attack_img
            );

            this->attack_set.push_back(attack);
            willAttack = true;
        }

        attack_counter = (attack_counter + 1) % attack_frequency;
    }

    return willAttack;
}*/

bool ChicksTower::TriggerAttack(Monster *monster){
    bool isDestroyed = false;

    for(unsigned int i = 0; i < this->attack_set.size(); i++)
    {
        if(Circle::isOverlap(attack_set[i]->getCircle(), monster->getCircle()))
        {
            /*TODO5:*/
            /*1. Reduce the monster HP by the harm point*/
            /*2. Erase and delete the attack from attack set*/
            /*3. Return true if the monster's HP is reduced to zero*/
            if(monster->Subtract_HP(attack_set[i]->getHarmPoint())){
                return true;
            }
        }
    }
    return false;
}

void ChicksTower::UpdateAttack(){
    for(unsigned int i=0; i < this->attack_set.size(); i++){
        if(!Circle::isOverlap(this->attack_set[i]->getCircle(), this->circle)){
            Attack *attack = this->attack_set[i];
            this->attack_set.erase(this->attack_set.begin() + i);
            i--;
            delete attack;
        }
    }
}
