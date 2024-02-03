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
    al_draw_bitmap(chicktower[chicklevel], 100, 100, 0);
    //draw bullet
    /*game*/
    //draw image
    /*al_draw_bitmap(background3, 0, 0, 0);
    int i;
    if(stage1==0){//bee
        if(bee.life>0){
            if(bee.x%20) al_draw_bitmap(bee.image_path1, bee.x, bee.y, 0);
            else al_draw_bitmap(bee.image_path2, bee.x, bee.y, 0);
            al_draw_textf(font, al_map_rgb(255,255,255), bee.x+100, bee.y+150, 0, "HP %i", bee.life);
            //bullet
            for(i=0; i<count_bullet; i++){
                if(bullet[i].life) al_draw_filled_circle(bullet[i].x, bullet[i].y, 5, al_map_rgb(64,64,64));
            }
        }else stage1 = 1;
    }else if(stage1==1){//queen bee
        if(queen.life>0){
            if(queen.x%20) al_draw_bitmap(queen.image_path1, queen.x, queen.y, 0);
            else al_draw_bitmap(queen.image_path2, queen.x, queen.y, 0);
            al_draw_textf(font, al_map_rgb(255,255,255), queen.x+100, queen.y+150, 0, "HP %i", queen.life);
            for(i=0; i<count_bullet; i++){
                if(bullet[i].life) al_draw_filled_circle(bullet[i].x, bullet[i].y, 5, al_map_rgb(64,64,64));
            }
        }else stage1 = WIN;
    }else if(stage1==WIN){
        al_draw_bitmap(win, 0, 0, 0);
        al_flip_display();
        al_rest(3);
        mapunlock = 1;
        window = 2;
        map_menu_done = 0;
        return;
    }else if(stage1==LOSE){
        al_draw_bitmap(lose, 0, 0, 0);
        al_flip_display();
        al_rest(3);
        window = 2;
        map_menu_done = 0;
        return;
    }
    //shoot
    for(i=0; i<count_corn; i++){
        if(corn[i].life){
            al_draw_filled_circle(corn[i].x, corn[i].y, 3, al_map_rgb(255,235,0));
            if(gift_state==1 && gift_timer>0) al_draw_filled_circle(corn[i].x+10, corn[i].y, 3, al_map_rgb(255,235,0));
            if(gift_state==2 && gift_timer>0){
                al_draw_filled_circle(corn[i].x-100, corn[i].y, 2, al_map_rgb(255,255,255));
                al_draw_filled_circle(corn[i].x+125, corn[i].y, 2, al_map_rgb(255,255,255));
            }
        }
    }
    //gift
    for(i=0; i<count_gift; i++){
        if(gift[i].life) al_draw_bitmap(gift0, gift[i].x, gift[i].y, 0);
    }
    //life
    al_draw_textf(font, al_map_rgb(255,255,255), 110, 570, 0, "HP: %i", chick.life);
    if(chick.life/20==5) al_draw_bitmap(life5, 0, 570, 0);
    else if(chick.life/20==4) al_draw_bitmap(life4, 0, 570, 0);
    else if(chick.life/20==3) al_draw_bitmap(life3, 0, 570, 0);
    else if(chick.life/20==2) al_draw_bitmap(life2, 0, 570, 0);
    else if(chick.life/20==1) al_draw_bitmap(life1, 0, 570, 0);
    else al_draw_bitmap(life0, 0, 570, 0);
    //move chick
    if(key_state[ALLEGRO_KEY_RIGHT] || key_state[ALLEGRO_KEY_LEFT] || key_state[ALLEGRO_KEY_DOWN] || key_state[ALLEGRO_KEY_UP]){
        al_draw_bitmap(chick.image_path1, chick.x, chick.y, 0);
        if(gift_state==2 && gift_timer>0) al_draw_bitmap(friend1, chick.x-50, chick.y, 0);
    }else{
        al_draw_bitmap(chick.image_path2, chick.x, chick.y, 0);
        if(gift_state==2 && gift_timer>0) al_draw_bitmap(friend2, chick.x-50, chick.y, 0);
    }*/
}
void GameWindow::Level2_draw(){}
void GameWindow::Level3_draw(){}
