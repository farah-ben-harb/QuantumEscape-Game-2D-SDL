#ifndef ENIG_H_INCLUDED
#define ENIG_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
typedef struct 
{
 
 char question[200];
 char r1[50];
 char r2[50];
 char solution[50];
 
 SDL_Surface *fonds;
 
 SDL_Surface *q;
 SDL_Surface *rep1;
 SDL_Surface *rep2;
 SDL_Surface *s;
 
 SDL_Rect position_fonds;
 SDL_Rect pos_q;
 SDL_Rect pos_rep1;
 SDL_Rect pos_rep2;
 SDL_Rect pos_s;
 

} enig;



void init_enigme(enig *en,char* nom_fich);
char return_solution(char* nom_fich,enig *en);
int  aleatoiree(int n);
int  compter_nombre_de_ligne_fichier(char* nom_fich);
void afficher_enigme(SDL_Surface * screen,char* nom_fich, enig *en);
int  resolution (char* nom_fich,enig *en, SDL_Surface *screen,int *a,int *d,char solution);

void afficher_resultat (SDL_Surface * screen,int r);

#endif//ENIGME_H_INCLUDED
