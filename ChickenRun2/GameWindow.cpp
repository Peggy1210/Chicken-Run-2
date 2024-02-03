#include "GameWindow.h"
#include "Updates.cpp"
#include "Draws.cpp"
#include <iostream>

#define WHITE al_map_rgb(255, 255, 255)
#define BLACK al_map_rgb(0, 0, 0)
#define ORANGE_LIGHT al_map_rgb(255, 196, 87)
#define ORANGE_DARK al_map_rgb(255, 142, 71)
#define PURPLE al_map_rgb(149, 128, 255)
#define BLUE al_map_rgb(77, 129, 179)

#define min(a, b) ((a) < (b)? (a) : (b))
#define max(a, b) ((a) > (b)? (a) : (b))

void GameWindow::game_init(){
    icon = al_load_bitmap("./icon.png");
    background = al_load_bitmap("./backgrounds/temp.png");

    al_set_display_icon(display, icon);
    al_reserve_samples(3);

    sample = al_load_sample("./music/growl.wav");
    startSound = al_create_sample_instance(sample);
    al_set_sample_instance_playmode(startSound, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(startSound, al_get_default_mixer());

    sample = al_load_sample("./music/BackgroundMusic.ogg");
    backgroundSound = al_create_sample_instance(sample);
    al_set_sample_instance_playmode(backgroundSound, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(backgroundSound, al_get_default_mixer());
}

bool GameWindow::mouse_hover(int startx, int starty, int width, int height){
    if(mouse_x >= startx && mouse_x <= startx + width)
        if(mouse_y >= starty && mouse_y <= starty + height)
            return true;

    return false;
}

void GameWindow::game_play(){
    int msg;

    srand(time(NULL));

    msg = -1;
    game_reset();
    game_begin();

    while(msg != GAME_EXIT){
        msg = game_run();
    }

    show_err_msg(msg);
}

void GameWindow::show_err_msg(int msg){
    if(msg == GAME_TERMINATE)
        fprintf(stderr, "Game Terminated...");
    else
        fprintf(stderr, "unexpected msg: %d", msg);

    game_destroy();
    exit(9);
}

///register event and initialize timer and things needed
GameWindow::GameWindow(){
    if (!al_init())
        show_err_msg(-1);

    printf("Game Initializing...\n");

    display = al_create_display(window_width, window_height);
    event_queue = al_create_event_queue();

    timer = al_create_timer(1.0 / FPS);

    if(display==NULL || event_queue==NULL)
        show_err_msg(-1);

    al_init_primitives_addon();
    al_init_font_addon(); // initialize the font addon
    al_init_ttf_addon(); // initialize the ttf (True Type Font) addon
    al_init_image_addon(); // initialize the image addon
    al_init_acodec_addon(); // initialize acodec addon

    al_install_keyboard(); // install keyboard event
    al_install_mouse();    // install mouse event
    al_install_audio();    // install audio event

    font = al_load_ttf_font("./fonts/Caviar_Dreams_Bold.ttf",12,0); // load small font
    Medium_font = al_load_ttf_font("./fonts/Caviar_Dreams_Bold.ttf",24,0); //load medium font
    Large_font = al_load_ttf_font("./fonts/Caviar_Dreams_Bold.ttf",36,0); //load large font

    for(int i=0; i<10; i++){
        char buffer[50];
        sprintf(buffer, "./backgrounds/manga%d.jpg", i+1);
        manga[i] = al_load_bitmap(buffer);
    }
    for(int i=0; i<3; i++){
        char buffer[50];
        sprintf(buffer, "./backgrounds/loading%d.jpg", i+1);
        loading[i] = al_load_bitmap(buffer);
    }
    storebackground = al_load_bitmap("./backgrounds/store.jpeg");
    storebasket = al_load_bitmap("./backgrounds/basket.png");

    for(int i=0; i<3; i++){
        char buffer[50];
        sprintf(buffer, "./backgrounds/level%d_background.jpg", i+1);
        levelbackground[i] = al_load_bitmap(buffer);
    }

    menufont = al_load_font("./fonts/pirulen.ttf", 20, 0);

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());

    al_register_event_source(event_queue, al_get_timer_event_source(timer));

    game_init();
}

///start sample, timer
void GameWindow::game_begin(){
    //printf(">>> Start Level[%d]\n", level->getLevel());
    draw_running_map();
    ///printf("draw_running_map\n");

    al_play_sample_instance(startSound);
    ///printf("al_play_sample_instance\n");
    while(al_get_sample_instance_playing(startSound));
    al_play_sample_instance(backgroundSound);
    ///printf("al_play_sample_instance\n");

    al_start_timer(timer);
    ///printf("al_start_timer\n");
    ///al_start_timer(monster_pro);
}

///call process_event
int GameWindow::game_run(){
    int error = GAME_CONTINUE;

    if (!al_is_event_queue_empty(event_queue)) {
        error = process_event();
    }
    return error;
}

int GameWindow::game_update(){

    ///
    /*unsigned int i, j;
    std::list<Tower*>::iterator it;

    /*TODO1:*/
    /*Allow towers to detect if monster enters its range*/
    /*Hint: Tower::DetectAttack*/
    /*for(it=towerSet.begin(); it!=towerSet.end(); it++){
        for(i=0; i<monsterSet.size(); i++){
            (*it)->DetectAttack(monsterSet[i]);
        }
    }

    // update every monster
    // check if it is destroyed or reaches end point
    for(i=0; i < monsterSet.size(); i++)
    {
        bool isDestroyed = false, isReachEnd = false;

        /*TODO2:*/
        /*1. For each tower, traverse its attack set*/
        /*2. If the monster collide with any attack, reduce the HP of the monster*/
        /*3. Remember to set isDestroyed to "true" if monster is killed*/
        /*Hint: Tower::TriggerAttack*/
        /*for(it=towerSet.begin(); it!=towerSet.end(); it++){
            isDestroyed = (*it)->TriggerAttack(monsterSet[i]);
            if(isDestroyed) break;
        }

        isReachEnd = monsterSet[i]->Move();

        if(isDestroyed)
        {
            Monster *m = monsterSet[i];

            menu->Change_Coin(m->getWorth());
            menu->Gain_Score(m->getScore());
            monsterSet.erase(monsterSet.begin() + i);
            i--;
            delete m;

        }
        else if(isReachEnd)
        {
            Monster *m = monsterSet[i];

            if(menu->Subtract_HP())
                return GAME_EXIT;

            monsterSet.erase(monsterSet.begin() + i);
            i--;
            delete m;
        }
    }

    /*TODO3:*/
    /*1. Update the attack set of each tower*/
    /*Hint: Tower::UpdateAttack*/
    /*for(it=towerSet.begin(); it!=towerSet.end(); it++){
        (*it)->UpdateAttack();
    }*/
    switch(window){
    case MAIN_MENU:
        window = Main_menu_update(); break;
    case INTRODUCTION:
        window = Introduction_update(); break;
    case SETTINGS:
        window = Settings_update(); break;
    case REVIEW:
        window = Review_update(); break;
    case CLOSE:
        window = Close_update(); break;
    case CHARACTER_CHOOSE:
        window = Character_choose_update(); break;
    case CHARACTER_NAMING:
        window = Character_naming_update(); break;
    case PREVIEW:
        window = Preview_update(); break;
    case ENDING:
        window = Ending_update(); break;
    case LOADING:
        window = Loading_update(); break;
    case MODE_SELECTION:
        window = Mode_selection_update(); break;
    case ONE_PLAYER_MODE:
        window = One_player_mode_update(); break;
    case TWO_PLAYER_MODE:
        window = Two_player_mode_update(); break;
    case MAP_MENU:
        window = Map_menu_update(); break;
    case STORE:
        window = Store_update(); break;
    case LEVEL1:
        window = Level1_update(); break;
    case LEVEL2:
        window = Level2_update(); break;
    case LEVEL3:
        window = Level3_update(); break;
    }

    return GAME_CONTINUE;
}

void GameWindow::game_reset(){
    // reset game and begin
    ///for(auto&& child : towerSet) {
    ///    delete child;
    ///}
    ///towerSet.clear();
    ///monsterSet.clear();


    ///selectedTower = -1;
    ///lastClicked = -1;
    Coin_Inc_Count = 0;
    mute = false;
    redraw = false;

    // stop sample instance
    al_stop_sample_instance(backgroundSound);
    al_stop_sample_instance(startSound);

    // stop timer
    al_stop_timer(timer);
    ///al_stop_timer(monster_pro);

    flip = 0;
    named = false;
    window = STORE;
    chicklevel = 1;
}

void GameWindow::game_destroy(){
    game_reset();

    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_destroy_font(font);
    al_destroy_font(Medium_font);
    al_destroy_font(Large_font);

    al_destroy_timer(timer);
    ///al_destroy_timer(monster_pro);

    ///for(int i=0;i<5; i++)
    ///    al_destroy_bitmap(tower[i]);

    al_destroy_bitmap(icon);
    al_destroy_bitmap(background);

    al_destroy_sample(sample);
    al_destroy_sample_instance(startSound);
    al_destroy_sample_instance(backgroundSound);

    //delete level;
    delete chickstower;
    delete rabbittower;
    //delete chickensoldier;
    ///delete window;
    ///delete menu;

    for(int i=0; i<3; i++)
        al_destroy_bitmap(levelbackground[i]);
    al_destroy_bitmap(storebackground);
    al_destroy_bitmap(storebasket);
    for(int i=0; i<10; i++){
        al_destroy_bitmap(manga[i]);
    }
    for(int i=0; i<3; i++){
        al_destroy_bitmap(loading[i]);
    }
    al_destroy_font(menufont);
}

int GameWindow::process_event(){
    ///obtain events
    int i;
    int instruction = GAME_CONTINUE;

    // offset for pause window
    int offsetX = field_width/2 - 200;
    int offsetY = field_height/2 - 200;

    al_wait_for_event(event_queue, &event);
    redraw = false;

    if(event.type==ALLEGRO_EVENT_TIMER){
        if(event.timer.source==timer){
            redraw = true;

            ///if(Coin_Inc_Count == 0)
            ///    menu->Change_Coin(Coin_Time_Gain);

            ///Coin_Inc_Count = (Coin_Inc_Count + 1) % CoinSpeed;

            ///if(monsterSet.size() == 0 && !al_get_timer_started(monster_pro))
            ///{
            ///    al_stop_timer(timer);
            ///    return GAME_EXIT;
            ///}

        }else{
            ///
            /*if(Monster_Pro_Count == 0) {
                Monster *m = create_monster();

                if(m != NULL)
                    monsterSet.push_back(m);
            }
            Monster_Pro_Count = (Monster_Pro_Count + 1) % level->getMonsterSpeed();*/
        }
    }else if(event.type==ALLEGRO_EVENT_DISPLAY_CLOSE){
        return GAME_EXIT;
    }else if(event.type==ALLEGRO_EVENT_KEY_DOWN){
        switch(event.keyboard.keycode){
            case ALLEGRO_KEY_P:
                /*TODO4: handle pause event here*/
                if(al_get_timer_started(timer))
                    al_stop_timer(timer);
                else
                    al_start_timer(timer);
                break;
            case ALLEGRO_KEY_M:
                mute = !mute;
                if(mute)
                    al_stop_sample_instance(backgroundSound);
                else
                    al_play_sample_instance(backgroundSound);
                break;
            case ALLEGRO_KEY_ESCAPE:
                return GAME_EXIT;
            default:
                key_state[event.keyboard.keycode] = true;
                key_down = true;

        }
    }else if(event.type==ALLEGRO_EVENT_KEY_UP){
        key_state[event.keyboard.keycode] = false;
    }else if(event.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
        mouse_down = true;
        ///
        /*if(event.mouse.button == 1) {
            if(selectedTower != -1 && mouse_hover(0, 0, field_width, field_height)) {
                Tower *t = create_tower(selectedTower);

                if(t == NULL)
                    printf("Wrong place\n");
                else {
                    towerSet.push_back(t);
                    towerSet.sort(compare);
                }
            } else if(selectedTower == -1){
                std::list<Tower*>::iterator it = towerSet.begin();
                if(lastClicked != -1)
                {
                    std::advance(it, lastClicked);
                    (*it)->ToggleClicked();
                }
                for(i=0, it = towerSet.begin(); it != towerSet.end(); it++, i++)
                {
                    Circle *circle = (*it)->getCircle();
                    int t_width = (*it)->getWidth();

                    if(mouse_hover(circle->x - t_width/2, circle->y, t_width, t_width/2))
                    {
                        (*it)->ToggleClicked();
                        lastClicked = i;
                        break;
                    } else {
                        lastClicked = -1;
                    }
                }

            }
            // check if user wants to create some kind of tower
            // if so, show tower image attached to cursor
            selectedTower = menu->MouseIn(mouse_x, mouse_y);

        }*/
    }else if(event.type==ALLEGRO_EVENT_MOUSE_BUTTON_UP){
        mouse_down = false;
    }else if(event.type == ALLEGRO_EVENT_MOUSE_AXES){
        mouse_x = event.mouse.x;
        mouse_y = event.mouse.y;

        //menu->MouseIn(mouse_x, mouse_y);
    }

    if(redraw) {
        // update each object in game
        instruction = game_update();

        // Re-draw map
        draw_running_map();
        redraw = false;
    }

    return instruction;
}

void GameWindow::draw_running_map(){
    switch(window){
    case MAIN_MENU:
        Main_menu_draw(); break;
    case INTRODUCTION:
        Introduction_draw(); break;
    case SETTINGS:
        Settings_draw(); break;
    case REVIEW:
        Review_draw(); break;
    case CLOSE:
        Close_draw(); break;
    case CHARACTER_CHOOSE:
        Character_choose_draw(); break;
    case CHARACTER_NAMING:
        Character_naming_draw(); break;
    case PREVIEW:
        Preview_draw(); break;
    case ENDING:
        Ending_draw(); break;
    case LOADING:
        Loading_draw(); break;
    case MODE_SELECTION:
        Mode_selection_draw(); break;
    case ONE_PLAYER_MODE:
        One_player_mode_draw(); break;
    case TWO_PLAYER_MODE:
        Two_player_mode_draw(); break;
    case MAP_MENU:
        Map_menu_draw(); break;
    case STORE:
        Store_draw(); break;
    case LEVEL1:
        Level1_draw(); break;
    case LEVEL2:
        Level2_draw(); break;
    case LEVEL3:
        Level3_draw(); break;
    }
    al_flip_display();
}
