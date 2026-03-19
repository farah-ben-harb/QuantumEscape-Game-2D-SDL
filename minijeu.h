#ifndef MINIJEU_H_
#define MINIJEU_H_
#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
typedef struct 
{
SDL_Surface* tab_images[8],*back_mini,*tab_carte[8];
SDL_Rect tab_pos[8];
int clic,matrice[2][4],compteur;
Mix_Chunk *effect,*win;
}minijeu;
void init_minijeu(minijeu *mini);
void afficher_minijeu(minijeu mini,SDL_Surface* screen);
int check(minijeu mini);
void liberer_minijeu(minijeu *mini);

#endif
