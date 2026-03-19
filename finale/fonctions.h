#ifndef FONCTIONS_H_
#define FONCTIONS_H_
#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include"ennemi.h"
typedef struct
{
SDL_Surface *image,*back_op,*loading,*niveau[15],*level,*retour,*pause,*menu[11],*m,*spaceship[4],*lampe,*title;
SDL_Rect positionEcran,position_back_op,position_loading,position_niveau[3],pos_retour,pos_pause,pos_spaceship,pos_spaceship2,pos_lampe,pos_title/*,position_level2,position_level3*/;
int motion,fr,direction,premiere_fois[3],tap_son;
}Background;

typedef struct
{
SDL_Surface *image_bouton[33];
SDL_Surface *coins;
SDL_Rect position_coins;
SDL_Rect position_bouton[33];
Mix_Chunk *effect,*effect_coin,*win,*fail,*sound_level[7];
int tap_screen;
}bouton;
void initialiser_background1(Background *B);
void afficher_retour(Background B,SDL_Surface* screen);
void afficher_levels(Background B,SDL_Surface* screen,Ennemi s);
void afficher_pause(Background B,SDL_Surface* screen);
void afficher_background1(Background B,SDL_Surface* screen);
void initialiser_background2(Background *B);
void afficher_background2(Background B,SDL_Surface* screen);
void afficher_pause(Background B,SDL_Surface* screen);
void initialiser_bouton(bouton *bt);
void motion_back1(SDL_Event event,bouton bt,int *actif);
void afficher_boutons_back(bouton bt, Background B,int actif,int clic,SDL_Surface* screen);
void motion_back2(SDL_Event event,bouton bt,int *actif_op);
void afficher_boutons_options(Background B,bouton bt,int actif_op,int clic_volume,SDL_Surface* screen);
void clic_menu_background(Background B,bouton bt, int clic,int *niveau,int *continuer);
void clic_son(bouton bt, int clic,SDL_Surface* screen);
void clic_menu_options(bouton bt,int clic_op,int *niveau,SDL_Surface* screen);
void modif_volume(bouton bt,int clic_volume,SDL_Surface* screen);
void animer_back(Background *B);
void afficher_right(Background B,SDL_Surface* screen);
void afficher_left(Background B,SDL_Surface* screen);
void afficher_right2(Background B,SDL_Surface* screen);
void afficher_left2(Background B,SDL_Surface* screen);
void deplacement_spaceship_niveau(Background *B);
void deplacement_spaceship(Background *B);
void deplacement_spaceship_niveau2(Background *B);
#endif
