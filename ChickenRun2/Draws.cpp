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
    if(flip<8 && flip>=0)
        al_draw_bitmap(manga[flip], 0, 0, 0);
    al_draw_filled_rectangle(window_width-100, window_height-100, window_width, window_height-50, al_map_rgb(100, 100, 100));
    al_draw_text(menufont, al_map_rgb(0,0,0), window_width-80, window_height-75, 0, "skip");
}

void GameWindow::Character_choose_draw(){

}

void GameWindow::Character_naming_draw(){

}

void GameWindow::Ending_draw(){
    if(flip<12 && flip>=8)
        al_draw_bitmap(manga[flip], 0, 0, 0);
    al_draw_filled_rectangle(window_width-100, window_height-100, window_width, window_height-50, al_map_rgb(100, 100, 100));
    al_draw_text(menufont, al_map_rgb(0,0,0), window_width-80, window_height-75, 0, "skip");
}

void GameWindow::Loading_draw(){

}

void GameWindow::Mode_selection_draw(){}

void GameWindow::One_player_mode_draw(){

}

void GameWindow::Two_player_mode_draw(){}

void GameWindow::Map_menu_draw(){
}

void GameWindow::Store_draw(){}

void GameWindow::Level1_draw(){
    al_draw_bitmap(levelbackground[0], 0, 0, 0);
    chickstower->Draw();
    printf("11");
    soldierbutton->Draw();
}
void GameWindow::Level2_draw(){}
void GameWindow::Level3_draw(){}
