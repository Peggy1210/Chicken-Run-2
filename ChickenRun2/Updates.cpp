#include "GameWindow.h"
#include "global.h"
#include "ChicksTower.cpp"
#include "RabbitTower.cpp"

Windows GameWindow::Main_menu_update(){

}

Windows GameWindow::Introduction_update(){

}

Windows GameWindow::Settings_update(){}

Windows GameWindow::Review_update(){}

Windows GameWindow::Close_update(){}

Windows GameWindow::Preview_update(){
    if(key_state[ALLEGRO_KEY_DOWN] && key_down){
        if(flip<8)
            flip++;
        key_down = false;
    }else if(key_state[ALLEGRO_KEY_UP] && key_down){
        if(flip>=0)
            flip--;
        key_down = false;
    }else if(key_state[ALLEGRO_KEY_ENTER] && key_down && flip==8){
        ///inter = MAIN_MENU;
        key_down = false;
    }else if(mouse_down && mouse_x<=window_width && mouse_x>=window_width-100 && mouse_y<=window_height-50 && mouse_y>=window_height-100){
        ///inter = MAIN_MENU;
        mouse_down = false;
    }else if(mouse_down){
        if(flip<8)
            flip++;
        mouse_down = false;
    }else if(flip==8){
        flip = 0;
        return LOADING;
    }
    return PREVIEW;
}

Windows GameWindow::Character_choose_update(){}

Windows GameWindow::Character_naming_update(){}

Windows GameWindow::Ending_update(){

}

Windows GameWindow::Loading_update(){
    int i;
    al_stop_timer(timer);
    for(i=0; i<6; i++){
        al_draw_bitmap(loading[i%3], 0, 0, 0);
        al_flip_display();
        al_rest(1);
    }
    al_start_timer(timer);
    return PREVIEW;
}

Windows GameWindow::Mode_selection_update(){}

Windows GameWindow::One_player_mode_update(){
    printf("%d", chicklevel);
    chickstower = new ChicksTower(this->chicklevel, RIGHT);
    rabbittower = new RabbitTower(this->chicklevel, LEFT);
    //chickensoldier = new SoldierButton(this->chicklevel);
    //rabbitsoldier = new ComputerSoldier(this->chicklevel);
    return LEVEL1;
}

Windows GameWindow::Two_player_mode_update(){}

Windows GameWindow::Map_menu_update(){}

Windows GameWindow::Store_update(){}

Windows GameWindow::Level1_update(){
    if(key_state[ALLEGRO_KEY_ENTER]){
        key_state[ALLEGRO_KEY_ENTER] = false;
        chickstower->Attack();
    }else if(key_state[ALLEGRO_KEY_1]){
        key_state[ALLEGRO_KEY_1] = false;
        chickstower->Attack(1);
    }else if(key_state[ALLEGRO_KEY_2]){
        key_state[ALLEGRO_KEY_2] = false;
        chickstower->Attack(2);
    }else if(key_state[ALLEGRO_KEY_3]){
        key_state[ALLEGRO_KEY_3] = false;
        chickstower->Attack(3);
    }else if(key_state[ALLEGRO_KEY_4]){
        key_state[ALLEGRO_KEY_4] = false;
        chickstower->Attack(4);
    }else if(key_state[ALLEGRO_KEY_5]){
        key_state[ALLEGRO_KEY_5] = false;
        chickstower->Attack(5);
    }
    if(mouse_down && mouse_x>=500 && mouse_x<=700 && mouse_y>=750 && mouse_y<=950){
        mouse_down = false;
        chickstower->Attack(1);
    }else if(mouse_down && mouse_x>=800 && mouse_x<=1000 && mouse_y>=750 && mouse_y<=950){
        mouse_down = false;
        chickstower->Attack(2);
    }else if(mouse_down && mouse_x>=1100 && mouse_x<=1300 && mouse_y>=750 && mouse_y<=950){
        mouse_down = false;
        chickstower->Attack(3);
    }else if(mouse_down && mouse_x>=1400 && mouse_x<=1600 && mouse_y>=750 && mouse_y<=950){
        mouse_down = false;
        chickstower->Attack(4);
    }else if(mouse_down && mouse_x>=1700 && mouse_x<=1900 && mouse_y>=750 && mouse_y<=950){
        mouse_down = false;
        chickstower->Attack(5);
    }else if(mouse_down && ((mouse_x*mouse_x)+(mouse_y-window_height)*(mouse_y-window_height)<=300*300)){
        mouse_down = false;
        chickstower->Attack();
    }
    chickstower->UpdateAttack();
    //chickensoldier->UpdateAttack();
    rabbittower->UpdateAttack();
    //rabbitsoldier->UpdateAttack();



    //delete chickstower
    //delete chickensoldier
    return LEVEL1;
}

Windows GameWindow::Level2_update(){}

Windows GameWindow::Level3_update(){}
