

#ifndef perso_H_INCLUDED
#define perso_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

/** 
* @struct perso 
* @brief struct for perso
*/ 

typedef struct perso
{

SDL_Surface *personnage; /*!< Surface. */ 
SDL_Rect rect,rect_relative; /*!< Rectangle*/ 
SDL_Surface *mvtright[10]; /*!< Surface. */ 
SDL_Surface *mvtleft[10]; /*!< Surface. */ 
SDL_Surface *jumpright[15]; /*!< Surface. */ 
SDL_Surface *jumpleft[15]; /*!< Surface. */ 
//SDL_Surface *jumpright[15];
SDL_Surface *runright[11]; /*!< Surface. */ 
SDL_Surface *runleft[11]; /*!< Surface. */ 
SDL_Surface *dieright[16],*dieleft[8]; /*!< Surface. */ 
SDL_Surface *frame; /*!< Surface. */ 
SDL_Surface *attack[4],*at;
float speedX,speedY;
int num_image;
int vitesse ;
int direction ; 
float acceleration ; 
SDL_Rect pos_attack;
}perso;


typedef struct Input
{
 int left,right,jump,acction,down,attack;

} Input;

void initialiser_input (Input *I);
void initialiser_input2 (Input *I2);
void initialiser_perso (perso *p);
void initialiser_perso2(perso *p2);
void afficher_perso (perso *p,SDL_Surface *screen);
void afficher_perso2 (perso *p2,SDL_Surface *screen);
void animation_right (perso *p);
void animation_left (perso *p);
void animation_stable (perso *p);
void mouvementright (perso *p,Uint32 dt);
void mouvementleft (perso *p,Uint32 dt);
void jumpright (perso *p);
void jumpleft (perso *p);
void animer_attack(perso *p);
void afficher_attack(perso p,SDL_Surface* screen);
void animation_die_right(perso *p);
void animation_die_left(perso *p);
 #endif
