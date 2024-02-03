#include "GameWindow.h"
#include "global.h"

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

}

Windows GameWindow::Two_player_mode_update(){}

Windows GameWindow::Map_menu_update(){}

Windows GameWindow::Store_update(){}

Windows GameWindow::Level1_update(){
    int i;
    //bullet
    /*bullet_ctrl++;
    //update enemy position
    if(stage1==0){
        if(bee.life>0){
            if(bee.x>250) dirx = false;
            else if(bee.x<-50) dirx = true;
            if(dirx) bee.x+=2;
            else bee.x-=2;
            if(bullet_ctrl%30==0){
                count_bullet++;
                bullet[count_bullet].life = 1;
                bullet[count_bullet].x = bee.x+100;
                bullet[count_bullet].y = bee.y+100;
            }
            for(i=0; i<count_bullet; i++){
                if(bullet[i].x<WIDTH && bullet[i].x>0 && bullet[i].y<HEIGHT && bullet[i].y>0 && bullet[i].life){
                    if(bullet[i].x<chick.x+150 && bullet[i].x>chick.x+50 && bullet[i].y>chick.y+60 && bullet[i].y<chick.y+100){
                        bullet[i].life = 0;
                        chick.life -= 5;
                    }else bullet[i].y += 3;
                }else bullet[i].life = 0;
            }
        }
    }else if(stage1==1){
        if(queen.life>0){
            if(queen.x>250) dirx = false;
            else if(queen.x<-50) dirx = true;
            if(dirx) queen.x += 4;
            else queen.x -= 4;
            if(bullet_ctrl%20==0){
                count_bullet++;
                bullet[count_bullet].life = 1;
                bullet[count_bullet].x = queen.x+150;
                bullet[count_bullet].y = queen.y+150;
            }
            for(i=0; i<count_bullet; i++){
                if(bullet[i].x<WIDTH && bullet[i].x>0 && bullet[i].y<HEIGHT && bullet[i].y>0 && bullet[i].life){
                    if(bullet[i].x<chick.x+150 && bullet[i].x>chick.x+50 && bullet[i].y>chick.y+60 && bullet[i].y<chick.y+100){
                        bullet[i].life = 0;
                        chick.life -= 10;
                    }else bullet[i].y += 4;
                }else bullet[i].life = 0;
            }
        }else stage1 = WIN;
    }
    //shoot
    if(key_state[ALLEGRO_KEY_SPACE] && pause){
            count_corn++;
            corn[count_corn].life = 1;
            corn[count_corn].x = chick.x+100;
            corn[count_corn].y = chick.y+100;
            pause = false;
    }
    for(i=0; i<count_corn; i++){
        if(corn[i].x<WIDTH && corn[i].x>0 && corn[i].y<HEIGHT && corn[i].y>0 && corn[i].life){
            if(stage1==0){
                if(corn[i].x<bee.x+150 && corn[i].x>bee.x+50 && corn[i].y>bee.y && corn[i].y<bee.y+150){
                    corn[i].life = 0;
                    bee.life -= 100;
                    if(gift_state==1) bee.life -= 10;
                    if(gift_state==2) bee.life -= 10;
                }
            }else if(stage1==1){
                if(corn[i].x<queen.x+150 && corn[i].x>queen.x+50 && corn[i].y>queen.y && corn[i].y<queen.y+150){
                    corn[i].life = 0;
                    queen.life -= 5;
                    if(gift_state==1) queen.life -= 5;
                    if(gift_state==2) queen.life -= 10;
                }
            }
            corn[i].y -= 3;
        }else{
            corn[i].life = 0;
        }
    }
    //gift
    if(bullet_ctrl%150==0){
        count_gift++;
        gift[count_gift].life = 1;
        gift[count_gift].x = rand()%300;
        gift[count_gift].y = 0;
    }
    for(i=0; i<count_gift; i++){
        if(gift[i].x<WIDTH && gift[i].x>0 && gift[i].y<HEIGHT && gift[i].y>=0 && gift[i].life){
            if(gift[i].x<chick.x+150 && gift[i].x>chick.x-50 && gift[i].y>chick.y-20 && gift[i].y<chick.y){
                gift[i].life = 0;
                gift_state = i%3;
                gift_timer = 300;
            }else gift[i].y += 2;
        }else gift[i].life = 0;
    }
    if(gift_state==3 && gift_timer==100) chick.life += 20;
    gift_timer--;
    if(gift_timer==0) gift_state = 0;
    //update chick position
    int vx, vy;
    vx = vy = 0;
    if(key_state[ALLEGRO_KEY_UP] && chick.y>=-100) vy -= 2;
    if(key_state[ALLEGRO_KEY_DOWN] && chick.y<=HEIGHT-200) vy += 2;
    if(key_state[ALLEGRO_KEY_LEFT] && chick.x>=-100) vx -= 2;
    if(key_state[ALLEGRO_KEY_RIGHT] && chick.x<=WIDTH-100) vx += 2;
    chick.x += vx*(vy ? 0.71f : 1);
    chick.y += vy*(vx ? 0.71f : 1);
    if(chick.life<0) stage1 = LOSE;*/
}

Windows GameWindow::Level2_update(){}

Windows GameWindow::Level3_update(){}
