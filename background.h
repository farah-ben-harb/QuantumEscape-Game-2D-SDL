#ifndef background_H
#define background_H
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "perso.h"

typedef struct background
{
int x_relative,y_relative,niveau,tap;
SDL_Surface *bg,*mask,*retour[2],*bg2,*bg3,*mask2,*mask3,*story[8];
SDL_Rect pos,pos_retour;
SDL_Rect camera;
Mix_Chunk *sound_level[7];
}background;
void initialiser_backround (background *b);
void afficher_background (SDL_Surface *screen1,background *b);
void afficher_background_n2(SDL_Surface *screen,background *b);
void afficher_background_n3(SDL_Surface *screen,background *b);
void scrolling_right (background *b,perso *p,SDL_Surface *screen);
void scrolling_left (background *b,perso *p,SDL_Surface *screen);
void afficher_story(background b,SDL_Surface *screen);
void afficher_fin(background b,SDL_Surface *screen);
#endif
