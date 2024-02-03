#include "global.h"

int TowerRadius[] = {80, 80, 70, 110, 150};
char TowerClass[][20] = {"Arcane", "Archer", "Canon", "Poison", "Storm"};
int TowerWidth[] = {72, 66, 72, 59, 45};
int TowerHeight[] = {121, 108, 69, 98, 112};


///keystate
bool key_state[ALLEGRO_KEY_MAX];
bool key_down = false;
int key_num = -1;
bool mouse_down = false;
int mouse_x, mouse_y;

///levels
int towerLevel = 0;
