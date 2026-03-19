#ifndef ENIGME_STATIQUE_H_
#define ENIGME_STATIQUE_H_
#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
typedef struct
{
SDL_Surface* background,*b1,*b2,*b3;
SDL_Rect pos1,pos2,pos3;
}enigme_sta;
void init_enigme_statique(enigme_sta *ens);
void afficher_enigme_s(enigme_sta ens,SDL_Surface* screen);
#endif
