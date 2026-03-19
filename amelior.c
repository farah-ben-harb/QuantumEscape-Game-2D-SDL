#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include"amelior.h"
void initialiser_amelior(amelior *al)
{
al->background2=IMG_Load("image_ameliore/back2.jpg");
al->background=IMG_Load("image_ameliore/background.jpg");
al->bouton[0]=IMG_Load("image_ameliore/player1.png");
al->bouton[1]=IMG_Load("image_ameliore/motion1.png");
al->bouton[2]=IMG_Load("image_ameliore/player2.png");
al->bouton[3]=IMG_Load("image_ameliore/motion2.png");
al->bouton[4]=IMG_Load("image_ameliore/controller.png");
al->bouton[5]=IMG_Load("image_ameliore/motions1.png");
al->bouton[6]=IMG_Load("image_ameliore/keyboard.png");
al->bouton[7]=IMG_Load("image_ameliore/motions2.png");

al->posbackground.x=0;
al->posbackground.y=0;

al->posbouton[0].x=350;
al->posbouton[0].y=600;
al->posbouton[0].w=al->bouton[0]->w;//al->bouton[0]->w
al->posbouton[0].h=al->bouton[0]->h;//al->bouton[0]->h

al->posbouton[1].x=930;
al->posbouton[1].y=600;
al->posbouton[1].w=al->bouton[2]->w;
al->posbouton[1].h=al->bouton[2]->h;

al->posbouton[2].x=950;
al->posbouton[2].y=500;
al->posbouton[2].w=al->bouton[4]->w;
al->posbouton[2].h=al->bouton[4]->h;


al->posbouton[3].x=230;
al->posbouton[3].y=500;
al->posbouton[3].w=al->bouton[6]->w;
al->posbouton[3].h=al->bouton[6]->h;

al->motion=0;
al->choix=0;
al->niveau=0;
}
void afficher_amelior(amelior al,SDL_Surface* screen)
{
SDL_BlitSurface(al.background,NULL,screen,&al.posbackground);
switch(al.motion)
{
case 0:
SDL_BlitSurface(al.bouton[0],NULL,screen,&al.posbouton[0]);
SDL_BlitSurface(al.bouton[2],NULL,screen,&al.posbouton[1]);
break;

case 1:
SDL_BlitSurface(al.bouton[1],NULL,screen,&al.posbouton[0]);
SDL_BlitSurface(al.bouton[2],NULL,screen,&al.posbouton[1]);
break;

case 2:
SDL_BlitSurface(al.bouton[0],NULL,screen,&al.posbouton[0]);
SDL_BlitSurface(al.bouton[3],NULL,screen,&al.posbouton[1]);
break;
}
}
void afficher_amelior2(amelior al,SDL_Surface* screen)
{
SDL_BlitSurface(al.background2,NULL,screen,&al.posbackground2);
switch(al.motion)
{
case 0:
SDL_BlitSurface(al.bouton[4],NULL,screen,&al.posbouton[2]);
SDL_BlitSurface(al.bouton[6],NULL,screen,&al.posbouton[3]);
break;

case 3:
SDL_BlitSurface(al.bouton[5],NULL,screen,&al.posbouton[2]);
SDL_BlitSurface(al.bouton[6],NULL,screen,&al.posbouton[3]);
break;

case 4:
SDL_BlitSurface(al.bouton[4],NULL,screen,&al.posbouton[2]);
SDL_BlitSurface(al.bouton[7],NULL,screen,&al.posbouton[3]);
break;
}
}
void liberer(amelior *al,SDL_Surface* screen)
{int i;
for(i=0;i<4;i++)
{
SDL_FreeSurface(al->bouton[i]);
}
SDL_FreeSurface(al->background);
SDL_FreeSurface(al->background2);
SDL_FreeSurface(screen);
}


