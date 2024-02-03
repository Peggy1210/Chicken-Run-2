#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

#define font_size 12
#define grid_width 40
#define grid_height 40

#define window_width 2400
#define window_height 1000
#define field_left 200
#define field_right 2200
#define field_upper 200
#define field_lower 800

#define prev_page 27
#define end_page 30

#define RIGHT 1
#define LEFT -1

#define Num_TowerType 5
#define Num_MonsterType 4
#define NumOfGrid (field_width / grid_width) * (field_height / grid_height)
#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <vector>
#include <string>

extern int TowerRadius[];
extern char TowerClass[][20];
extern int TowerWidth[];
extern int TowerHeight[];

///keystate
extern bool key_state[];
extern bool key_down;
extern int key_num;
extern bool mouse_down;
extern int mouse_x, mouse_y;

// clock rate
const float FPS = 60;

const int velocity[] = {1, 2, 3, 4, 5};
const int harm[] = {1, 2, 3, 4, 5};

// 1 coin every 2 seconds
const int CoinSpeed = FPS * 2;
const int Coin_Limit = 100000;

typedef enum{WIN, LOSE, GAME_CONTI, LEFT_WIN, RIGHT_WIN}WIN_LOSE;
typedef struct{
    WIN_LOSE win_lose;
    int level_coin;
}Status;

/// enumerate window
typedef enum{STARTING, MAIN_MENU, INTRODUCTION, SETTINGS, CLOSE,
            PREVIEW, CHARACTER_CHOOSE, CHARACTER_NAMING, ENDING,
            MODE_SELECTION, ONE_PLAYER_MODE, TWO_PLAYER_MODE, TWO_PLAYER_PLAY,
            MAP_MENU, STORE, LEVEL
}Windows;

enum {ARCANE = 0, ARCHER, CANON, POISON, STORM};
enum {WOLF = 0, WOLFKNIGHT, DEMONNIJIA, CAVEMAN};

///levels
extern int towerLevel;

#endif // GLOBAL_H_INCLUDED
