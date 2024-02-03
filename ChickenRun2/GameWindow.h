#ifndef MAINWINDOW_H_INCLUDED
#define MAINWINDOW_H_INCLUDED

#include <list>
#include <time.h>
#include "global.h"

#define GAME_INIT -1
#define GAME_SETTING 0
#define GAME_SELECT 1
#define GAME_BEGIN 2
#define GAME_CONTINUE 3
#define GAME_FAIL 4
#define GAME_TERMINATE 5
#define GAME_NEXT_LEVEL 6
#define GAME_EXIT 7

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
    ///bool isOnRoad();

    ///Tower* create_tower(int);
    ///Monster* create_monster();

    ///Window updates
    Windows Main_menu_update();
    Windows Introduction_update();
    Windows Settings_update();
    Windows Review_update();
    Windows Close_update();
    Windows Preview_update();
    Windows Character_choose_update();
    Windows Character_naming_update();
    Windows Ending_update();
    Windows Loading_update();
    Windows Mode_selection_update();
    Windows One_player_mode_update();
    Windows Two_player_mode_update();
    Windows Map_menu_update();
    Windows Store_update();
    Windows Level1_update();
    Windows Level2_update();
    Windows Level3_update();

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
    void Loading_draw();
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
    ALLEGRO_BITMAP *icon;
    ///ALLEGRO_BITMAP *tower[Num_TowerType];
    ALLEGRO_BITMAP *background = NULL;

    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_FONT *font = NULL;
    ALLEGRO_FONT *Medium_font = NULL;
    ALLEGRO_FONT *Large_font = NULL;

    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_EVENT event;
    ALLEGRO_TIMER *timer = NULL;
    ///ALLEGRO_TIMER *monster_pro = NULL;

    ALLEGRO_SAMPLE *sample = NULL;
    ALLEGRO_SAMPLE_INSTANCE *startSound = NULL;
    ALLEGRO_SAMPLE_INSTANCE *clearSound = NULL;
    ALLEGRO_SAMPLE_INSTANCE *failSound = NULL;
    ALLEGRO_SAMPLE_INSTANCE *backgroundSound = NULL;

    //LEVEL *level = NULL;
    ///Window *window = NULL;
    ///Menu *menu = NULL;

    ///std::vector<Monster*> monsterSet;
    ///std::list<Tower*> towerSet;

    ///int Monster_Pro_Count = 0;
    int Coin_Inc_Count = 0;
    int selectedTower = -1, lastClicked = -1;

    bool redraw = false;
    bool mute = false;


    ///character name
    char name[10] = {};
    int choose = -1;

    ALLEGRO_FONT *menufont;
    Windows window = PREVIEW;
    ALLEGRO_BITMAP *manga[10];
    ALLEGRO_BITMAP *loading[3];
    ALLEGRO_BITMAP *levelbackground[3];
    ALLEGRO_BITMAP *storebackground;
    ALLEGRO_BITMAP *storebasket;
    int chicklevel = 1;
    //std::vector<*ChickSoldier> chicksoldier_set;
    ChicksTower *chickstower;
    RabbitTower *rabbittower;
    //SoldierButton *chickensoldier;
    //ComputerSoldier *rabbitsoldier;
    /*ALLEGRO_BITMAP *character[4][5];*/
    int flip = -1;
    bool named = false;
    bool done = false;
};


#endif // MAINWINDOW_H_INCLUDED
