#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

#include <allegro5/allegro_font.h>

#define font_size 12
#define grid_width 40
#define grid_height 40

#define window_width 2400
#define window_height 1000
#define field_width 600
#define field_height 600

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
#include <allegro5/allegro_ttf.h>
#include <vector>
#include <string>
#include "Circle.h"
#include "ChicksTower.h"
#include "RabbitTower.h"


extern int TowerRadius[];
extern char TowerClass[][20];
extern int TowerWidth[];
extern int TowerHeight[];

///keystate
extern bool key_state[];
extern bool key_down;
extern bool mouse_down;
extern int mouse_x, mouse_y;

const int velocity[] = {1, 2, 3, 4, 5};
const int harm[] = {1, 2, 3, 4, 5};

/// enumerate window
typedef enum{MAIN_MENU, INTRODUCTION, SETTINGS, REVIEW, CLOSE,
            PREVIEW, CHARACTER_CHOOSE, CHARACTER_NAMING, ENDING,
            LOADING, MODE_SELECTION, ONE_PLAYER_MODE, TWO_PLAYER_MODE,
            MAP_MENU, STORE, LEVEL1, LEVEL2, LEVEL3
}Windows;

enum {ARCANE = 0, ARCHER, CANON, POISON, STORM};
enum {WOLF = 0, WOLFKNIGHT, DEMONNIJIA, CAVEMAN};

///levels
extern int towerLevel;

#endif // GLOBAL_H_INCLUDED
