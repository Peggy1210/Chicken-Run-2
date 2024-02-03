#include "GameWindow.h"
#include "global.h"

void GameWindow::Main_menu_draw(){

}

void GameWindow::Introduction_draw(){

}

void GameWindow::Settings_draw(){

}

void GameWindow::Review_draw(){

}

void GameWindow::Close_draw(){

}

void GameWindow::Preview_draw(){
    if(flip<prev_page && flip>=0){
        al_draw_bitmap(prev_manga[flip], 0, 0, 0);
        al_draw_filled_rectangle(window_width-200, window_height-200, window_width, window_height-100, al_map_rgba(100, 100, 100, 100));
        al_draw_text(menufont, al_map_rgb(0,0,0), window_width-100, window_height-175, ALLEGRO_ALIGN_CENTER, "skip");
    }
}

void GameWindow::Character_choose_draw(){
    al_draw_bitmap(choosing[character_num],0,0,0);
}

void GameWindow::Character_naming_draw(){
    al_draw_bitmap(naming[character_num],0,0,0);
    al_draw_filled_rounded_rectangle(window_width/2, window_height/2-50, window_width/2+800, window_height/2+50, 10, 10, al_map_rgba(256,256,256,100));
    al_draw_text(menufont, al_map_rgb(255,255,255), window_width/2+400, window_height/2-30, ALLEGRO_ALIGN_CENTER, name);
}

void GameWindow::Ending_draw(){
    if(flip<end_page && flip>=prev_page){
        al_draw_bitmap(prev_manga[flip], 0, 0, 0);
        al_draw_filled_rectangle(window_width-200, window_height-200, window_width, window_height-100, al_map_rgba(100, 100, 100, 100));
        al_draw_text(menufont, al_map_rgb(0,0,0), window_width-100, window_height-175, ALLEGRO_ALIGN_CENTER, "skip");
    }
}

void GameWindow::Mode_selection_draw(){}

void GameWindow::One_player_mode_draw(){

}

void GameWindow::Two_player_mode_draw(){}

void GameWindow::Map_menu_draw(){
}

void GameWindow::Store_draw(){
    al_draw_bitmap(storebackground, 0, 0, 0);
    //if()
    al_draw_bitmap(storebasket, 300, 400, 0);
    al_draw_bitmap(storebasket, 1200, 400, 0);
}

void GameWindow::Level1_draw(){
    al_draw_bitmap(levelbackground[0], 0, 0, 0);
    al_draw_bitmap(chicken_img, 200, 200, 0);
    al_draw_bitmap(rabbit_img, 1800, 200, 0);
    rabbittower->Draw();
    chickstower->Draw();
}
void GameWindow::Level2_draw(){}
void GameWindow::Level3_draw(){}
