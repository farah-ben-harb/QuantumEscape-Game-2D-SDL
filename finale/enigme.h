#ifndef  ALEATOIRE_H_INCLUDED 
#define ALEATOIRE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <time.h>

typedef struct 
{
    char question[50];
    char reponse1[50],reponse2[50],reponse3[50];
    int solution;
}enigme;

enigme generer();
void afficherEnigme(enigme *e, SDL_Surface * screen);


 #endif
