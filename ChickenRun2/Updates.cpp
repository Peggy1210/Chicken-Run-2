#include "GameWindow.h"
#include "global.h"
#include "ChicksTower.cpp"
#include "SoldierButton.cpp"

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
    chickstower = new ChicksTower(this->chicklevel);
    soldierbutton = new SoldierButton();
    return LEVEL1;
}

Windows GameWindow::Two_player_mode_update(){}

Windows GameWindow::Map_menu_update(){}

Windows GameWindow::Store_update(){}

Windows GameWindow::Level1_update(){
    int i;
    chickstower->UpdateAttack();
    soldierbutton->UpdateAttack();
    if(key_state[ALLEGRO_KEY_ENTER]){
        key_state[ALLEGRO_KEY_ENTER] = false;
        chickstower->Attack();
    }else if(key_state[ALLEGRO_KEY_1]){
        key_state[ALLEGRO_KEY_1] = false;
        soldierbutton->Attack(1);
    }else if(key_state[ALLEGRO_KEY_2]){
        key_state[ALLEGRO_KEY_2] = false;
        soldierbutton->Attack(2);
    }else if(key_state[ALLEGRO_KEY_3]){
        key_state[ALLEGRO_KEY_3] = false;
        soldierbutton->Attack(3);
    }else if(key_state[ALLEGRO_KEY_4]){
        key_state[ALLEGRO_KEY_4] = false;
        soldierbutton->Attack(4);
    }else if(key_state[ALLEGRO_KEY_5]){
        key_state[ALLEGRO_KEY_5] = false;
        soldierbutton->Attack(5);
    }

    //delete chickstower
    //delete soldierbutton
    return LEVEL1;
}

Windows GameWindow::Level2_update(){}

Windows GameWindow::Level3_update(){}
