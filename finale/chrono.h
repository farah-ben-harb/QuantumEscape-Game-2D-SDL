#ifndef CHRONO_H_INCLUDED
#define CHRONO_H_INCLUDED
/** 
* @struct minimap 
* @brief struct for minimap 
*/ 

#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include"ennemi.h"
typedef struct
{
SDL_Surface *image_minimap,*minimap2,*minimap3,*bonhomme,*ennemi,*fire[15],*png;/*!< Surface. */
SDL_Rect position_bonhomme,position_minimap,position_ennemii,pos_effet;/*!< Rectangle*/
int fr;
}minimap;
typedef struct 
{
SDL_Surface* texte;
TTF_Font *police;
SDL_Rect position_texte;
}text;
void initialiser_minimap(minimap *m);
void MAJMinimap( perso p,Ennemi e, int redimensionnement,minimap *m,SDL_Rect camera);
void MAJMinimap2( perso p,Ennemi e, int redimensionnement,minimap *m,SDL_Rect camera);
void MAJMinimap3( perso p,Ennemi e, int redimensionnement,minimap *m,SDL_Rect camera);
void afficher_minimap (minimap m, SDL_Surface *ecran);
void afficher_minimap2 (minimap m, SDL_Surface *ecran);
void afficher_minimap3 (minimap m, SDL_Surface *ecran);
void Liberer (minimap *m, text *t);
void init_ttf(text *t,char temps[]);
void chronometre(int *tempss,text *t,char temps[],int *tempsActuel,int *tempsPrecedent,int *compteur,int *vrai_compteur);
SDL_Color GetPixel (SDL_Surface *pSurface , int x , int y);
int collisionPP(perso p,SDL_Surface *mask);
void animer_effet(minimap *m);
#endif
