#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "perso.h"

typedef struct background2
{
SDL_Surface *bg,*mask;
SDL_Rect pos,BgPos;
SDL_Rect camera,camera2;
}background2;
void initialiser_background3 (background2 *b);
void afficher_background3 (SDL_Surface *screen,background2 *b);
void scrolling_right2 (background2 *b,perso *p,SDL_Surface *screen,Input I,Input I2);
void scrolling_left2 (background2 *b,perso *p,SDL_Surface *screen,Input I,Input I2);

