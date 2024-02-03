#include "GameWindow.h"

Windows GameWindow::Starting_update(){
    if(key_state[ALLEGRO_KEY_ENTER] && key_down){
        key_down = false;
        return PREVIEW;
    }
    return STARTING;
}

Windows GameWindow::Main_menu_update(){
    if(key_state[ALLEGRO_KEY_DOWN] && key_down){
        main_menu_choosing++;
        key_down = false;
    }else if(key_state[ALLEGRO_KEY_UP] && key_down){
        main_menu_choosing--;
        if(main_menu_choosing<0) main_menu_choosing = 0;
        key_down = false;
    }else if(key_state[ALLEGRO_KEY_ENTER]){
        if(main_menu_choosing%6==1){
            main_menu_choosing = 0;
            return MODE_SELECTION;
        }else if(main_menu_choosing%6==2){
            main_menu_choosing = 0;
            return INTRODUCTION;
        }else if(main_menu_choosing%6==3){
            main_menu_choosing = 0;
            return SETTINGS;
        }else if(main_menu_choosing%6==4){
            flip = 0;
            manga_done = true;
            main_menu_choosing = 0;
            return PREVIEW;
        }
        else if(main_menu_choosing%6==5) done = true;
    }
    return MAIN_MENU;
}

Windows GameWindow::Introduction_update(){

}

Windows GameWindow::Settings_update(){
    if(key_state[ALLEGRO_KEY_DOWN] && key_down){
        settings_choosing++;
        key_down = false;
    }else if(key_state[ALLEGRO_KEY_UP] && key_state){
        settings_choosing--;
        if(settings_choosing<0) settings_choosing = 0;
        key_down = false;
    }else if(key_state[ALLEGRO_KEY_ENTER] && key_down){
        settings_mode = 0;
        key_down = false;
    }
    if(settings_mode%3==1 && settings_choosing%4==1 && key_down){
         if(key_state[ALLEGRO_KEY_UP] && key_down){
                background_volume++;
                key_down = false;
            }
    }else if(settings_mode%3==2 && settings_choosing%4==2){
       if(key_state[ALLEGRO_KEY_UP] && key_down){
            special_volume++;
            key_down = false;
        }
    }else if(key_state[ALLEGRO_KEY_ENTER] && settings_choosing%4==3){
        settings_choosing = 0;
        return MAIN_MENU;
    }
    return SETTINGS;
}

Windows GameWindow::Review_update(){}

Windows GameWindow::Close_update(){}

Windows GameWindow::Preview_update(){
    //printf("%d\t", flip);
    if(key_state[ALLEGRO_KEY_DOWN] && key_down){
        key_down = false;
        if(flip<prev_page) flip++;
        if(flip==prev_page && manga_done) return ENDING;
    }else if(key_state[ALLEGRO_KEY_UP] && key_down){
        key_down = false;
        if(flip>0 && flip<prev_page) flip--;
    }else if(key_state[ALLEGRO_KEY_ENTER] && key_down && flip==prev_page){
        key_down = false;
        return CHARACTER_CHOOSE;
    }else if(flip==prev_page && !manga_done){
        al_draw_text(menufont, al_map_rgb(200,200,200), 1200, 500, ALLEGRO_ALIGN_CENTER, "--PRESS ENTER TO CONTINUE--");
        al_flip_display();
    }else if(mouse_down && mouse_x<=window_width && mouse_x>=window_width-200 && mouse_y<=window_height-100 && mouse_y>=window_height-200 && !manga_done){
        mouse_down = false;
        return CHARACTER_CHOOSE;
    }else if(mouse_down && mouse_x<=window_width && mouse_x>=window_width-200 && mouse_y<=window_height-100 && mouse_y>=window_height-200 && manga_done){
        mouse_down = false;
        flip = 0;
        return MAIN_MENU;///
    }else if(mouse_down){
        if(flip<prev_page) flip++;
        mouse_down = false;
    }
    return PREVIEW;
}

Windows GameWindow::Character_choose_update(){
    if(key_down){
        key_down = false;
        if(key_num==ALLEGRO_KEY_RIGHT && character_num<3){
            character_num++;
        }else if(key_num==ALLEGRO_KEY_LEFT && character_num>0){
            character_num--;
        }else if(key_num==ALLEGRO_KEY_ENTER){
            choosed = true;
            char buffer[50];
            sprintf(buffer, "./character/character%d.png", character_num+1);
            chicken_img = al_load_bitmap(buffer);
            rabbit_img = al_load_bitmap("./character/rabbit1.png");
        }
    }
    if(choosed) return CHARACTER_NAMING;
    else return CHARACTER_CHOOSE;
}

Windows GameWindow::Character_naming_update(){
    if(key_down){
        int L = strlen(name);
        //printf("%d", L);
        key_down = false;
        if(key_num==ALLEGRO_KEY_BACKSPACE){
            int i;
            for(i=0; i<L-1; i++) name[i] = name[i];
            name[i] = '\0';
        }else if(key_num>=ALLEGRO_KEY_A && key_num<=ALLEGRO_KEY_Z){
            if(L<49){
                sprintf(name, "%s%c", name, key_num-ALLEGRO_KEY_A+'A');
            }else {
                al_draw_text(menufont, al_map_rgb(0,0,0), window_width/2, window_height/2+50, ALLEGRO_ALIGN_CENTER, "name is restricted to 50 words");
                al_flip_display();
                al_rest(1);
            }
        }else if(key_num==ALLEGRO_KEY_ENTER && L>0){
            named = true;
        }else if(key_num==ALLEGRO_KEY_ENTER && L<=0){
            al_draw_text(menufont, al_map_rgb(0,0,0), window_width/2, window_height/2+50, ALLEGRO_ALIGN_CENTER, "blank entering");
            al_flip_display();
            al_rest(1);
        }
    }
    if(named) return MAIN_MENU; ///MAIN_MENU
    else return CHARACTER_NAMING;
}

Windows GameWindow::Ending_update(){
    //printf("%d\t", flip);
    if(key_state[ALLEGRO_KEY_DOWN] && key_down){
        key_down = false;
        if(flip<end_page) flip++;
    }else if(key_state[ALLEGRO_KEY_UP] && key_down){
        key_down = false;
        if(flip>=prev_page && flip<end_page) flip--;
        if(flip==prev_page-1 && manga_done) return PREVIEW;
    }else if(key_state[ALLEGRO_KEY_ENTER] && key_down && flip==end_page){
        key_down = false;
        flip = 0;
        return MAIN_MENU;///
    }else if(flip==end_page){
        al_draw_text(menufont, al_map_rgb(200,200,200), 1200, 500, ALLEGRO_ALIGN_CENTER, "--PRESS ENTER TO CONTINUE--");
        al_flip_display();
    }else if(mouse_down && mouse_x<=window_width && mouse_x>=window_width-200 && mouse_y<=window_height-100 && mouse_y>=window_height-200){
        mouse_down = false;
        flip = 0;
        return MAIN_MENU;///
    }else if(mouse_down){
        mouse_down = false;
        if(flip<end_page) flip++;
    }
    return ENDING;
}

Windows GameWindow::Mode_selection_update(){
    if(key_state[ALLEGRO_KEY_DOWN] && key_down){
        mode_selection_choosing++;
        key_down = false;
    }else if(key_state[ALLEGRO_KEY_UP] && key_down){
        if(mode_selection_choosing>0) mode_selection_choosing--;
        key_down = false;
    }else if(key_state[ALLEGRO_KEY_ENTER]){
        if(mode_selection_choosing%4==1){
            mode_selection_choosing = 0;
            return MAP_MENU;
        }else if(mode_selection_choosing%4==2){
            mode_selection_choosing = 0;
            return TWO_PLAYER_MODE;
        }else if(mode_selection_choosing%4==3){
            mode_selection_choosing = 0;
            return MAIN_MENU;
        }
    }
    return MODE_SELECTION;
}

Windows GameWindow::One_player_mode_update(){
    printf("%d", chicklevel);
    al_stop_timer(timer);
    level = new Level(1, this->chicklevel);
    al_start_timer(timer);
    return LEVEL1;
}

Windows GameWindow::Two_player_mode_update(){
    if(key_state[ALLEGRO_KEY_DOWN] && key_down){
        character_choosing++;
        key_down = false;
    }else if(key_state[ALLEGRO_KEY_DOWN] && key_down){
        character_choosing --;
        if(character_choosing<0) character_choosing = 0;
        key_down = false;
    }else if(key_state[ALLEGRO_KEY_ENTER] && key_down){
         character_selected++;
         key_down = false;
    }
    if(character_selected%3==0 && mouse_down && mouse_x<=window_width-2300 && mouse_x>=window_width-2500 && mouse_y<=window_height && mouse_y>=window_height-200) return MODE_SELECTION;
    else if(character_selected%3==2) return TWO_PLAYER_PLAY;
    return TWO_PLAYER_MODE;
}

Windows GameWindow::Two_player_play_update(){
}

Windows GameWindow::Map_menu_update(){
    if(mouse_down && mouse_x<=window_width -200&& mouse_x>=window_width-400 && mouse_y<=window_height-300 && mouse_y>=window_height-430) return STORE;
    else if(mouse_down && mouse_x<=window_width-180 && mouse_x>=window_width-640 && mouse_y<=window_height-220 && mouse_y>=window_height-300) return ONE_PLAYER_MODE;
    else if(mouse_down && mouse_x<=window_width-2250 && mouse_x>=window_width-2500 && mouse_y<=window_height && mouse_y>=window_height-160) return MODE_SELECTION;
    return MAP_MENU;
}

Windows GameWindow::Store_update(){
    if(key_state[ALLEGRO_KEY_ENTER]){
        key_state[ALLEGRO_KEY_ENTER] = false;
    }else if(key_state[ALLEGRO_KEY_LEFT]){
        key_state[ALLEGRO_KEY_LEFT] = false;
    }else if(key_state[ALLEGRO_KEY_RIGHT]){
        key_state[ALLEGRO_KEY_RIGHT] = false;
    }
    if(mouse_down && mouse_x>=400 && mouse_x<=1000 && mouse_y>=200 && mouse_y<=800){
        mouse_down = false;
    }else if(mouse_down && mouse_x>=1400 && mouse_x<=2000 && mouse_y>=200 && mouse_y<=800){
        mouse_down = false;
    }
    return STORE;
}

Windows GameWindow::Level1_update(){
    Status status = level->UpdateAttack();
    if(key_state[ALLEGRO_KEY_ENTER]){
        key_state[ALLEGRO_KEY_ENTER] = false;
        level->Attack();
    }else if(key_state[ALLEGRO_KEY_1]){
        key_state[ALLEGRO_KEY_1] = false;
        level->Attack(1);
    }else if(key_state[ALLEGRO_KEY_2]){
        key_state[ALLEGRO_KEY_2] = false;
        level->Attack(2);
    }else if(key_state[ALLEGRO_KEY_3]){
        key_state[ALLEGRO_KEY_3] = false;
        level->Attack(3);
    }else if(key_state[ALLEGRO_KEY_4]){
        key_state[ALLEGRO_KEY_4] = false;
        level->Attack(4);
    }else if(key_state[ALLEGRO_KEY_5]){
        key_state[ALLEGRO_KEY_5] = false;
        level->Attack(5);
    }
    if(mouse_down && mouse_x>=500 && mouse_x<=700 && mouse_y>=750 && mouse_y<=950){
        mouse_down = false;
        level->Attack(1);
    }else if(mouse_down && mouse_x>=800 && mouse_x<=1000 && mouse_y>=750 && mouse_y<=950){
        mouse_down = false;
        level->Attack(2);
    }else if(mouse_down && mouse_x>=1100 && mouse_x<=1300 && mouse_y>=750 && mouse_y<=950){
        mouse_down = false;
        level->Attack(3);
    }else if(mouse_down && mouse_x>=1400 && mouse_x<=1600 && mouse_y>=750 && mouse_y<=950){
        mouse_down = false;
        level->Attack(4);
    }else if(mouse_down && mouse_x>=1700 && mouse_x<=1900 && mouse_y>=750 && mouse_y<=950){
        mouse_down = false;
        level->Attack(5);
    }else if(mouse_down && ((mouse_x*mouse_x)+(mouse_y-window_height)*(mouse_y-window_height)<=300*300)){
        mouse_down = false;
        level->Attack();
    }

    if(status.win_lose==WIN){
        al_draw_bitmap(win_img, 0, 0, 0);
        char buffer[50];
        sprintf(buffer, "%d", status.level_coin);
        al_draw_text(menufont, al_map_rgb(255, 255, 255), window_width/2, window_height/2, ALLEGRO_ALIGN_CENTER, buffer);
        al_flip_display();
        al_rest(3);
        return MAP_MENU;///
    }else if(status.win_lose==LOSE){
        al_draw_bitmap(lose_img, 0, 0, 0);
        char buffer[50];
        sprintf(buffer, "%d", status.level_coin);
        al_draw_text(menufont, al_map_rgb(255, 255, 255), window_width/2, window_height/2, ALLEGRO_ALIGN_CENTER, buffer);
        al_flip_display();
        al_rest(3);
        return MAP_MENU;///
    }else if(status.win_lose==GAME_CONTI) return LEVEL1;
}

Windows GameWindow::Level2_update(){}

Windows GameWindow::Level3_update(){}
