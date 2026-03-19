#ifndef AMELIOR_H_
#define AMELIOR_H_
#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
typedef struct
{
SDL_Surface* background,*background2,*bouton[8];
SDL_Rect posbouton[4],posbackground,posbackground2;
int choix,motion,niveau;
}amelior;
void initialiser_amelior(amelior *al);
void afficher_amelior(amelior al,SDL_Surface* screen);
void afficher_amelior2(amelior al,SDL_Surface* screen);
void liberer(amelior *al,SDL_Surface* screen);
#endif
