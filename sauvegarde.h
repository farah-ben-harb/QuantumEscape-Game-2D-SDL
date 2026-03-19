#ifndef SAUVEGARDE_H_
#define SAUVEGARDE_H_
#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include "perso.h"
#include"ennemi.h"
#include"chrono.h"
#include "background.h"
typedef struct
{
SDL_Surface* background,*background2,*bouton[6],*boutonr[2],*back,*planet[3];
SDL_Rect posbouton[3],posbackground,posboutonr[2],pos_planet[3];
int choix,motion,niveau;
}sauvegarde;
void initialiser_sauvgarde(sauvegarde *s);
void afficher_sauvgarde(sauvegarde s,SDL_Surface* screen);
void afficher_resume(sauvegarde s,SDL_Surface* screen);
void afficher_enigmes(sauvegarde s,SDL_Surface* screen);
void sauv (perso p,background b,Ennemi e,minimap m, char sauvegarde[],int vrai_compteur,Ennemi e2,Ennemi e3);
void load (perso *p,background *b,Ennemi *e,minimap *m,char sauvegarde[],int *vrai_compteur,Ennemi *e2,Ennemi *e3);
void liberer_sauvgarde(sauvegarde *s);
#endif
