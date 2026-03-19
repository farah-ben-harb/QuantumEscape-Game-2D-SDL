#ifndef IA2_H_INCLUDED
#define IA2_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
typedef struct 
{
int matrice_suivi[9],whoplay,whowin,nbr,compteur;
SDL_Surface* x[9],*o[9],*win,*back,*failed;
SDL_Rect pos[9],pos_back;
}tic;
void init_IA2(tic *ti);
void afficher_tic(tic ti,SDL_Surface* ecran);
int aleatoire();
int machine(tic *ti,int alea);
void afficher_joueur(tic ti,SDL_Surface* ecran);
void afficher_machine(SDL_Surface* ecran,tic ti);
void evaluer(tic *ti);
void Defense(tic *ti);
void attack(tic *ti);
void nbr_cases_remplis(tic *ti);
int gameover(tic ti,SDL_Surface* ecran);
#endif
