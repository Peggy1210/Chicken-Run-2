#ifndef MAINWINDOW_H_INCLUDED
#define MAINWINDOW_H_INCLUDED

#include <list>
#include <time.h>
#include "global.h"
#include "Level.h"
#define GAME_INIT -1
#define GAME_SETTING 0
#define GAME_SELECT 1
#define GAME_BEGIN 2
#define GAME_CONTINUE 3
#define GAME_FAIL 4
#define GAME_TERMINATE 5
#define GAME_NEXT_LEVEL 6
#define GAME_EXIT 7

#define tower_cooltime 500

class GameWindow{
public:
    // constructor
    GameWindow();
    // each process of scene
    void game_init();
    void game_reset();
    void game_play();
    void game_begin();

    int game_run();
    int game_update();

    void show_err_msg(int msg);
    void game_destroy();

    // each drawing scene function
    void draw_running_map();

    // process of updated event
    int process_event();
    // detect if mouse hovers over a rectangle
    bool mouse_hover(int, int, int, int);
    // detect if a tower will be constructed on road
    Windows Starting_update();
    Windows Main_menu_update();
    Windows Introduction_update();
    Windows Settings_update();
    Windows Review_update();
    Windows Close_update();
    Windows Preview_update();
    Windows Character_choose_update();
    Windows Character_naming_update();
    Windows Ending_update();
    Windows Mode_selection_update();
    Windows One_player_mode_update();
    Windows Two_player_mode_update();
    Windows Two_player_play_update();
    Windows Map_menu_update();
    Windows Store_update();
    Windows Level1_update();
    Windows Level2_update();
    Windows Level3_update();

    void loadings();

    ///Draw windows
    void Starting_draw();
    void Main_menu_draw();
    void Introduction_draw();
    void Settings_draw();
    void Review_draw();
    void Close_draw();
    void Preview_draw();
    void Character_choose_draw();
    void Character_naming_draw();
    void Ending_draw();
    void Mode_selection_draw();
    void One_player_mode_draw();
    void Two_player_mode_draw();
    void Two_player_play_draw();
    void Map_menu_draw();
    void Store_draw();
    void Level1_draw();
    void Level2_draw();
    void Level3_draw();

public:
    bool initial = true;
    int main_menu_choosing = 0;
    int map_menu_level = 1;
    int mode_selection_choosing = 0;
    int character_selected = 0;
    int character_choosing = 0;
    int settings_choosing = 0;
    int settings_mode = 0;
    int  background_volume = 0;
    int  special_volume = 0;

private:
    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_FONT *font = NULL;
    ALLEGRO_FONT *Medium_font = NULL;
    ALLEGRO_FONT *Large_font = NULL;
    ALLEGRO_FONT *menufont;
    ALLEGRO_FONT *volume_font = NULL;

    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_EVENT event;
    ALLEGRO_TIMER *timer = NULL;

    ALLEGRO_SAMPLE *sample = NULL;
    ALLEGRO_SAMPLE_INSTANCE *startSound = NULL;
    ALLEGRO_SAMPLE_INSTANCE *clearSound = NULL;
    ALLEGRO_SAMPLE_INSTANCE *failSound = NULL;
    ALLEGRO_SAMPLE_INSTANCE *backgroundSound = NULL;

    bool redraw = false;
    bool mute = false;

    //character name
    char name[50] = {};
    int choose = -1;

    Level *level;

    ALLEGRO_BITMAP *icon;
    ALLEGRO_BITMAP *background = NULL;
    ALLEGRO_BITMAP *starting = NULL;
    ALLEGRO_BITMAP *prev_manga[50];
    ALLEGRO_BITMAP *main_menu[6];
    ALLEGRO_BITMAP *mode_selection[4];
    ALLEGRO_BITMAP *character_choose[8];
    ALLEGRO_BITMAP *map_menu[3];
    ALLEGRO_BITMAP *settings[4];
    ALLEGRO_BITMAP *loading[6];
    ALLEGRO_BITMAP *levelbackground[3];
    ALLEGRO_BITMAP *storebackground;
    ALLEGRO_BITMAP *storebasket;
    ALLEGRO_BITMAP *choosing[4];
    ALLEGRO_BITMAP *naming[4];
    ALLEGRO_BITMAP *chicken_img;
    ALLEGRO_BITMAP *rabbit_img;
    ALLEGRO_BITMAP *win_img;
    ALLEGRO_BITMAP *lose_img;
    ALLEGRO_BITMAP *first_player_win;
    ALLEGRO_BITMAP *second_player_win;
    ALLEGRO_BITMAP *first_player_back= NULL;
    ALLEGRO_BITMAP *win= NULL;
    ALLEGRO_BITMAP *lose= NULL;
    ALLEGRO_BITMAP *map_menu_store= NULL;
    ALLEGRO_BITMAP *map_menu_back= NULL;
    ALLEGRO_BITMAP *map_menu_start = NULL;

    int chicklevel = 1;
    int flip = -1;
    int load = 0;
    int character_num = 1;
    bool named = false;
    bool choosed = false;
    bool done = false;
    bool manga_done = false;
    Windows window = PREVIEW;
    int level_coin = 0;
};


#endif // MAINWINDOW_H_INCLUDED
