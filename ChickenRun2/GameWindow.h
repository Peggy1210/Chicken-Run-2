#ifndef MAINWINDOW_H_INCLUDED
#define MAINWINDOW_H_INCLUDED

#include <list>
#include <time.h>
#include "global.h"
#include "Circle.h"
#include "ChicksTower.h"
#include "RabbitTower.h"

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

// clock rate
const float FPS = 60;

// total number of level
const int LevelNum = 4;

// 1 coin every 2 seconds
const int CoinSpeed = FPS * 2;
const int Coin_Time_Gain = 1;

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
    Windows Map_menu_update();
    Windows Store_update();
    Windows Level1_update();
    Windows Level2_update();
    Windows Level3_update();

    void loadings();

    ///Draw windows
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
    void Map_menu_draw();
    void Store_draw();
    void Level1_draw();
    void Level2_draw();
    void Level3_draw();

public:
    bool initial = true;

private:
    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_FONT *font = NULL;
    ALLEGRO_FONT *Medium_font = NULL;
    ALLEGRO_FONT *Large_font = NULL;
    ALLEGRO_FONT *menufont;

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

    ALLEGRO_BITMAP *icon;
    ALLEGRO_BITMAP *background = NULL;
    ALLEGRO_BITMAP *prev_manga[50];
    ALLEGRO_BITMAP *loading[3];
    ALLEGRO_BITMAP *levelbackground[3];
    ALLEGRO_BITMAP *storebackground;
    ALLEGRO_BITMAP *storebasket;
    ALLEGRO_BITMAP *choosing[4];
    ALLEGRO_BITMAP *naming[4];
    ALLEGRO_BITMAP *chicken_img;
    ALLEGRO_BITMAP *rabbit_img;

    ChicksTower *chickstower;
    RabbitTower *rabbittower;
    int chicklevel = 1;
    int flip = -1;
    int load = 0;
    int character_num = 1;
    bool named = false;
    bool choosed = false;
    bool done = false;
    bool manga_done = false;
    Windows window = PREVIEW;
};


#endif // MAINWINDOW_H_INCLUDED
