#ifndef Ennemi_H
#define Ennemi_H
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"perso.h"
#include"background.h"
typedef struct 
{
  SDL_Surface *mvtright[8],*mvtleft[8],*image_vie[3],*star[7],*coins[7],*porte[6],*dieright[5],*dieleft[5],*diee,*mvtright2[8],*mvtleft2[8],*mvtright3[8],*mvtleft3[8],*next_level[4];/*!< Surface. */
  SDL_Rect position_ennemi,position_ennemi2,position_ennemi3,pos_vie[3],pos_star[3],pos_coin[3],pos_porte,pos_next,pos_obstacle,pos_fire_right,pos_fire_left;/*!< Rectangle*/ 
  float speedX,speedY;
  SDL_Surface* frame,*st,*cs[3],*portt,*frame1,*frame3,*dieright3[5],*dieleft3[5],*next[2],*obs,*obstacle[6],*fire_right[4],*fire_left[4],*fire_rightt,*fire_leftt;/*!< Surface. */
  int direction;
  int fr,bb,fd,bb2,fd3,bb3,nbr_etoile,ob,fir,fil,bleu;
  int vie,motion,clic;
int etat_ennemi,scor;
SDL_Surface* barre_star;
SDL_Surface* texte,*coin;
TTF_Font *police;
SDL_Rect position_texte,position_score,pos_barre;
}Ennemi;
void InitEnnemi (Ennemi *e);
void InitEnnemi2 (Ennemi *e);
void initialiser_coin(Ennemi *c);
void afficher_Entite(Ennemi e,SDL_Surface* screen);
void afficher_ennemi(Ennemi e,SDL_Surface* screen);
void afficher_ennemi2(Ennemi e,SDL_Surface* screen);
void afficher_ennemi_die(Ennemi e,SDL_Surface* screen);
void afficher_coins(Ennemi c,SDL_Surface* screen);
void animer_Ennemi_right (Ennemi *e);
void animer_Ennemi_left (Ennemi *e);
void animer_Ennemi_right2(Ennemi *e);
void animer_Ennemi_left2 (Ennemi *e);
void animer_star(Ennemi *s);
void animer_coins(Ennemi *c);
void deplacement_aleatoire(Ennemi *e);
int collisionbb(perso p,Ennemi e);
void deplacement_aleatoire2(Ennemi *e);
void gestion_vie(Ennemi *e,perso p,int *col);
void calculer_distance (perso p,Ennemi *e);
void mise_a_jour(perso p , Ennemi e);
void initialiser_porte(Ennemi *po);
void afficher_porte(Ennemi po,SDL_Surface* screen1);
void animer_porte(Ennemi *po);
int collision_coins(Ennemi c ,perso p);
int collision_obstacle(Ennemi e ,perso p);
void initialiser_star(Ennemi *s);
void afficher_star(Ennemi s ,SDL_Surface* screen);
void init_score(Ennemi *e,char score[]);
void gestion_score(Ennemi *e,char score[]);
int collisionbb_attack(perso p,Ennemi e);
void animer_die_right(Ennemi *e);
void animer_die_left(Ennemi *e);
void init_Ennemi3(Ennemi*e);
void afficher_ennemi3(Ennemi e,SDL_Surface* screen);
void animer_ennemi3_right(Ennemi *e);
void animer_ennemi3_left(Ennemi *e);
void deplacement_aleatoire3(Ennemi *e);
int collisionbb_attack3(perso p,Ennemi e);
int collisionbb_attack2(perso p,Ennemi e);
void afficher_score(Ennemi e,SDL_Surface* screen);
void afficher_next_level(Ennemi e,SDL_Surface* screen);
void afficher_next(Ennemi e,SDL_Surface* screen);
void afficher_obstacle(Ennemi e,SDL_Surface* screen);
void animer_obstacle(Ennemi *e);
void animer_fire_right(Ennemi *e);
void animer_fire_left(Ennemi *e);
void afficher_attack_right(Ennemi e,SDL_Surface* screen);
void afficher_attack_left(Ennemi e,SDL_Surface* screen);
void calculer_distance2(perso p,Ennemi *e) ;
int collisionbb_attac_bleu(perso p,Ennemi e);
void liberer_ennemi(Ennemi *e, Ennemi *s,Ennemi *c);

#endif
