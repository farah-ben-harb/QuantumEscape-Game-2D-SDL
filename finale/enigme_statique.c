#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include"enigme_statique.h"
void init_enigme_statique(enigme_sta *ens)
{
ens->background=SDL_LoadBMP("enig_sta/enig1.bmp");
ens->b1=IMG_Load("enig_sta/1-1.png");
ens->b2=IMG_Load("enig_sta/2-2.png");
ens->b3=IMG_Load("enig_sta/3-3.png");
ens->pos1.x=1300;
ens->pos1.y=80;
ens->pos2.x=1300;
ens->pos2.y=350;
ens->pos3.x=1300;
ens->pos3.y=640;
}
void afficher_enigme_s(enigme_sta ens,SDL_Surface* screen)
{
SDL_BlitSurface(ens.background,NULL,screen,NULL);
SDL_BlitSurface(ens.b1,NULL,screen,&ens.pos1);
SDL_BlitSurface(ens.b2,NULL,screen,&ens.pos2);
SDL_BlitSurface(ens.b3,NULL,screen,&ens.pos3);
}








