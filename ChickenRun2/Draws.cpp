#include "GameWindow.h"

void GameWindow::Starting_draw(){
    al_draw_bitmap(starting , 0 , 0 , 0);
}

void GameWindow::Main_menu_draw(){
    if(main_menu_choosing==0) al_draw_bitmap(main_menu[0], 0, 0, 0);
    else if(main_menu_choosing==1) al_draw_bitmap(main_menu[1], 0, 0, 0);
    else if(main_menu_choosing==2) al_draw_bitmap(main_menu[2], 0, 0, 0);
    else if(main_menu_choosing==3) al_draw_bitmap(main_menu[3], 0, 0, 0);
    else if(main_menu_choosing==4) al_draw_bitmap(main_menu[4], 0, 0, 0);
    else if(main_menu_choosing==5) al_draw_bitmap(main_menu[5], 0, 0, 0);

   al_draw_textf(Medium_font, al_map_rgb(0,0,0),window_width-110 , window_height-70 ,ALLEGRO_ALIGN_CENTER,"%d",corn);
}

void GameWindow::Introduction_draw(){
    if(introduction_page) al_draw_bitmap(introduction[introduction_page] , 0 , 0 ,0);
}

void GameWindow::Settings_draw(){
    if(settings_choosing%4==0) al_draw_bitmap(settings[0], 0, 0, 0);
    else if(settings_choosing%4==1) al_draw_bitmap(settings[1], 0, 0, 0);
    else if(settings_choosing%4==2) al_draw_bitmap(settings[2], 0, 0, 0);
    else if(settings_choosing%4==3) al_draw_bitmap(settings[3], 0, 0, 0);

    if(background_volume%2==0) al_draw_text(volume_font, al_map_rgb(0,0,0), window_width-1000, window_height-700, ALLEGRO_ALIGN_CENTER, "ON");
    else al_draw_text(volume_font, al_map_rgb(0,0,0), window_width-1000, window_height-700, ALLEGRO_ALIGN_CENTER, "OFF");
    if(special_volume%2==0) al_draw_text(volume_font, al_map_rgb(0,0,0), window_width-1400, window_height-432, ALLEGRO_ALIGN_CENTER, "ON");
    else al_draw_text(volume_font, al_map_rgb(0,0,0), window_width-1400, window_height-432, ALLEGRO_ALIGN_CENTER, "OFF");
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

void GameWindow::Mode_selection_draw(){
    if(mode_selection_choosing%4==0) al_draw_bitmap(mode_selection[0], 0, 0, 0);
    else if(mode_selection_choosing%4==1) al_draw_bitmap(mode_selection[1], 0, 0, 0);
    else if(mode_selection_choosing%4==2) al_draw_bitmap(mode_selection[2], 0, 0, 0);
    else if(mode_selection_choosing%4==3) al_draw_bitmap(mode_selection[3], 0, 0, 0);
}

void GameWindow::One_player_mode_draw(){
    printf("11");
}

void GameWindow::Two_player_mode_draw(){
    if(character_selected % 3 == 1){
        if(character_choosing % 5 == 0) al_draw_bitmap(character_choose[0] , 0 , 0 , 0);
        else if(character_choosing % 5 == 1) al_draw_bitmap(character_choose[1] , 0 , 0 , 0);
        else if(character_choosing % 5 == 2) al_draw_bitmap(character_choose[2] , 0 , 0 , 0);
        else if(character_choosing % 5 == 3) al_draw_bitmap(character_choose[3] , 0 , 0 , 0);

        if(mouse_x<=window_width - 2300 && mouse_x>=window_width-2500 && mouse_y<=window_height && mouse_y>=window_height-200)
            al_draw_bitmap(first_player_back , 0 , 0 , 0);
    }
    if(character_selected % 3 == 2){
        if(character_choosing % 5 == 0) al_draw_bitmap(character_choose[4] , 0 , 0 , 0);
        else if(character_choosing % 5 == 1) al_draw_bitmap(character_choose[5] , 0 , 0 , 0);
        else if(character_choosing % 5 == 2) al_draw_bitmap(character_choose[6] , 0 , 0 , 0);
        else if(character_choosing % 5 == 3) al_draw_bitmap(character_choose[7] , 0 , 0 , 0);
    }
}

void GameWindow::Two_player_play_draw(){
    al_draw_bitmap(levelbackground[0], 0, 0, 0);
    al_draw_bitmap(left_img, 300, 150, 0);///
    al_draw_bitmap(right_img, window_width-500, 150, 0);///
    twoplayer->Draw();
}

void GameWindow::Map_menu_draw(){
    if(map_level==1) al_draw_bitmap(map_menu[0], 0, 0, 0);
    else if(map_level==2&& map_menu_level == 1)al_draw_bitmap(map_menu[1], 0, 0, 0);
    else if(map_level ==3&& map_menu_level == 1) al_draw_bitmap(map_menu[2] , 0 , 0 , 0);
    else if(map_level==2&& map_menu_level == 2)al_draw_bitmap(map_menu[3], 0, 0, 0);
    else if(map_level==3&& map_menu_level == 2)al_draw_bitmap(map_menu[4], 0, 0, 0);
    else if(map_level==3&&map_menu_level==3)al_draw_bitmap(map_menu[5], 0, 0, 0);

    if(mouse_x<=window_width-200 && mouse_x>=window_width-300 && mouse_y<=window_height-320 && mouse_y>=window_height-420) al_draw_bitmap(map_menu_store, 2016, 528, 0);
    else if(mouse_x<=window_width-180 && mouse_x>=window_width-640 && mouse_y<=window_height-220 && mouse_y>=window_height-300) al_draw_bitmap(map_menu_start, 1732, 550, 0);
    else if(mouse_x<=window_width-2350 && mouse_x>=window_width-2500 && mouse_y<=window_height && mouse_y>=window_height-160) al_draw_bitmap(map_menu_back, 0, 828, 0);

    al_draw_textf(Medium_font, al_map_rgb(0,0,0),window_width-110 , window_height-70 ,ALLEGRO_ALIGN_CENTER ,"%d" ,corn );
}

void GameWindow::Store_draw(){
    al_draw_bitmap(storebackground, 0, 0, 0);
    if(chicklevel<=2) al_draw_bitmap(tower_img[chicklevel], 550, 300, 0);
    else al_draw_bitmap(tower_img[2], 550, 300, 0);
    al_draw_bitmap(HP_plus, 1400, 300, 0);
    al_draw_bitmap(storebasket, 300, 400, 0);
    al_draw_bitmap(storebasket, 1200, 400, 0);
    if(chicklevel==3) al_draw_bitmap(soldout, 550, 300, 0);
    al_draw_bitmap(return_img, 0, window_height-200, 0);
}

void GameWindow::Level_draw(){
    al_draw_bitmap(levelbackground[playLevel-1], 0, 0, 0);
    al_draw_bitmap(chicken_img, 300, 150, 0);
    al_draw_bitmap(rabbit_img, window_width-500, 150, 0);
    level->Draw();
}
