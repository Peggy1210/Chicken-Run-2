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

void GameWindow::loadings(){
    al_draw_bitmap(loading[load++%6], 0, 0, 0);
    al_flip_display();
}

void GameWindow::game_init(){
    icon = al_load_bitmap("./icon.png");
    background = al_load_bitmap("./backgrounds/temp.png");
    al_set_display_icon(display, icon);
    printf("%d: set display\n", load);
    loadings();

    al_reserve_samples(3);
    sample = al_load_sample("./music/growl.wav");
    startSound = al_create_sample_instance(sample);
    al_set_sample_instance_playmode(startSound, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(startSound, al_get_default_mixer());
    sample = al_load_sample("./music/BackgroundMusic.ogg");
    backgroundSound = al_create_sample_instance(sample);
    al_set_sample_instance_playmode(backgroundSound, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(backgroundSound, al_get_default_mixer());
    printf("%d: load sample\n", load);
    loadings();
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
    int i;
    char buffer[50];
    for(i=0; i<6; i++){
        sprintf(buffer, "./backgrounds/loading%d.jpg", i+1);
        loading[i] = al_load_bitmap(buffer);
    }
    printf("%d: initialize\n", load);
    loadings();

    font = al_load_ttf_font("./fonts/Caviar_Dreams_Bold.ttf",12,0); // load small font
    Medium_font = al_load_ttf_font("./fonts/Caviar_Dreams_Bold.ttf",24,0); //load medium font
    Large_font = al_load_ttf_font("./fonts/Caviar_Dreams_Bold.ttf",36,0); //load large font
    menufont = al_load_font("./fonts/pirulen.ttf", 50, 0);
    volume_font = al_load_font("./fonts/pirulen.ttf", 70 ,0);
    printf("%d: load font\n", load);
    loadings();

    for(i = 0 ; i < 8 ; i++)
    {
        char distance[50] = {};
        sprintf(distance , "./backgrounds/character choose%d.jpg" ,i+1 );
        character_choose[i]=al_load_bitmap(distance);
    }
    first_player_back = al_load_bitmap( "./backgrounds/first player back.jpg");

    for(i = 0 ; i < 6 ; i++)
    {
        char distance[50] = {};
        sprintf(distance , "./backgrounds/main menu%d.jpg" ,i );
        main_menu[i]=al_load_bitmap(distance);
    }

    for(i = 0 ; i < 3; i++)
    {
        char distance[50] = {};
        sprintf(distance , "./backgrounds/map menu%d.jpg" ,i+1);
        map_menu[i]=al_load_bitmap(distance);
    }
    map_menu_back =  al_load_bitmap( "./backgrounds/map menu back.jpg");
    map_menu_start =  al_load_bitmap( "./backgrounds/map menu start.jpg");
    map_menu_store = al_load_bitmap( "./backgrounds/map menu store.jpg");

    for(i = 0 ; i < 4; i++)
    {
        char distance[50] = {};
        sprintf(distance , "./backgrounds/mode selection%d.jpg" ,i);
        mode_selection[i]=al_load_bitmap(distance);
    }

    for(i = 0 ; i < 4; i++)
    {
        char distance[50] = {};
        sprintf(distance , "./backgrounds/settings%d.jpg" ,i);
        settings[i]=al_load_bitmap(distance);
    }

    starting =  al_load_bitmap( "./backgrounds/starting.jpg");
    win = al_load_bitmap( "./backgrounds/win.jpg");
    lose =  al_load_bitmap( "./backgrounds/lose.jpg");

    first_player_win =  al_load_bitmap( "./backgrounds/1p win.jpg");
    second_player_win =  al_load_bitmap( "./backgrounds/2p win.jpg");

    storebackground = al_load_bitmap("./backgrounds/store.jpeg");
    storebasket = al_load_bitmap("./backgrounds/basket.png");
    for(i=0; i<3; i++){
        sprintf(buffer, "./backgrounds/level%d_background.jpg", i+1);
        levelbackground[i] = al_load_bitmap(buffer);
    }
    for(i=0; i<end_page; i++){
        sprintf(buffer, "./manga/manga%d.png", i+1);
        prev_manga[i] = al_load_bitmap(buffer);
    }
    loadings();
    for(i=0; i<4; i++){
        sprintf(buffer, "./backgrounds/choosing%d.PNG", i+1);
        choosing[i] = al_load_bitmap(buffer);
    }
    for(i=0; i<4; i++){
        sprintf(buffer, "./backgrounds/naming%d.PNG", i+1);
        naming[i] = al_load_bitmap(buffer);
    }
    printf("%d: load bitmap\n", load);
    loadings();

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    printf("%d: register event source\n", load);
    loadings();

    game_init();
}

///start sample, timer
void GameWindow::game_begin(){
    //printf(">>> Start Level[%d]\n", level->getLevel());



    ///printf("draw_running_map\n");
    loadings();
    al_play_sample_instance(startSound);
    ///printf("al_play_sample_instance\n");
    while(al_get_sample_instance_playing(startSound));
    al_play_sample_instance(backgroundSound);
    ///printf("al_play_sample_instance\n");

    al_start_timer(timer);
    ///printf("al_start_timer\n");
    draw_running_map();
    al_flip_display();
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
    switch(window){
    case STARTING:
        window = Starting_update(); break;
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
    case MODE_SELECTION:
        window = Mode_selection_update(); break;
    case ONE_PLAYER_MODE:
        window = One_player_mode_update(); break;
    case TWO_PLAYER_MODE:
        window = Two_player_mode_update(); break;
    case TWO_PLAYER_PLAY:
        window = Two_player_play_update(); break;
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
    mute = false;
    redraw = false;
    // stop sample instance
    al_stop_sample_instance(backgroundSound);
    al_stop_sample_instance(startSound);

    // stop timer
    al_stop_timer(timer);

    flip = 0;
    named = false;
    choosed = false;
    character_num = 1;
    window = STARTING;
    chicklevel = 1;
    done = false;
    manga_done = false;
    printf("%d: game reset\n", load);
    loadings();
}

void GameWindow::game_destroy(){
    game_reset();
    al_destroy_font(font);
    al_destroy_font(Medium_font);
    al_destroy_font(Large_font);
    al_destroy_font(menufont);
    al_destroy_font(volume_font);

    al_destroy_timer(timer);
    al_destroy_sample(sample);
    al_destroy_sample_instance(startSound);
    al_destroy_sample_instance(backgroundSound);

    delete chickstower;
    delete rabbittower;

    al_destroy_bitmap(storebackground);
    al_destroy_bitmap(storebasket);
    al_destroy_bitmap(chicken_img);
    al_destroy_bitmap(rabbit_img);
    al_destroy_bitmap(icon);
    al_destroy_bitmap(background);
    int i;

    for(i=0; i<8; i++) al_destroy_bitmap(character_choose[i]);
    for(i=0; i<6; i++) al_destroy_bitmap(main_menu[i]);
    for(i=0; i<3; i++) al_destroy_bitmap(map_menu[i]);
    for(i=0; i<4; i++) al_destroy_bitmap(mode_selection[i]);
    for(i=0; i<4; i++) al_destroy_bitmap(settings[i]);
    al_destroy_bitmap(starting);
    al_destroy_bitmap(win);
    al_destroy_bitmap(first_player_win);
    al_destroy_bitmap(second_player_win);
    al_destroy_bitmap(lose);
    al_destroy_bitmap(map_menu_back);
    al_destroy_bitmap(map_menu_store);
    al_destroy_bitmap(map_menu_start);
    al_destroy_bitmap(first_player_back);


    for(i=0; i<3; i++) al_destroy_bitmap(levelbackground[i]);
    for(i=0; i<6; i++) al_destroy_bitmap(loading[i]);
    for(i=0; i<4; i++) al_destroy_bitmap(naming[i]);
    for(i=0; i<4; i++) al_destroy_bitmap(choosing[i]);
    for(i=0; i<50; i++) al_destroy_bitmap(prev_manga[i]);

    al_destroy_display(display);
    al_destroy_event_queue(event_queue);

}

int GameWindow::process_event(){
    ///obtain events
    int i;
    int instruction = GAME_CONTINUE;

    al_wait_for_event(event_queue, &event);
    redraw = false;

    if(event.type==ALLEGRO_EVENT_TIMER){
        if(event.timer.source==timer){
            redraw = true;
        }
    }else if(event.type==ALLEGRO_EVENT_DISPLAY_CLOSE || done){
        return GAME_EXIT;
    }else if(event.type==ALLEGRO_EVENT_KEY_DOWN){
        if(window==CHARACTER_NAMING){
            key_num = event.keyboard.keycode;
            key_state[key_num] = true;
            key_down = true;
        }else{
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
                    key_num = event.keyboard.keycode;
                    key_state[key_num] = true;
                    key_down = true;
            }
        }
    }else if(event.type==ALLEGRO_EVENT_KEY_UP){
        key_state[event.keyboard.keycode] = false;
    }else if(event.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
        mouse_down = true;
    }else if(event.type==ALLEGRO_EVENT_MOUSE_BUTTON_UP){
        mouse_down = false;
    }else if(event.type == ALLEGRO_EVENT_MOUSE_AXES){
        mouse_x = event.mouse.x;
        mouse_y = event.mouse.y;
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
    case STARTING:
        starting_draw(); break;
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
    case MODE_SELECTION:
        Mode_selection_draw(); break;
    case ONE_PLAYER_MODE:
        One_player_mode_draw(); break;
    case TWO_PLAYER_MODE:
        Two_player_mode_draw(); break;
    case TWO_PLAYER_PLAY:
        Two_player_play_draw(); break;
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
