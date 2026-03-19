#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include"IA2.h"
#include<time.h>
void init_IA2(tic *ti)
{
int i,j;
for(i=0;i<9;i++)
{
ti->matrice_suivi[i]=0;
}
for(i=0;i<9;i++)
{
ti->x[i]=IMG_Load("tic_tac_toe/X.png");
ti->o[i]=IMG_Load("tic_tac_toe/O.png");
}
ti->failed=IMG_Load("tic_tac_toe/failed.jpg");
ti->win=IMG_Load("tic_tac_toe/win.jpg");
ti->back=IMG_Load("tic_tac_toe/IA2.jpg");
ti->pos_back.x=0;
ti->pos_back.y=0;
ti->pos[0].x=550;
ti->pos[0].y=230;
ti->pos[0].w=145;
ti->pos[0].h=145;

ti->pos[1].x=700;
ti->pos[1].y=230;
ti->pos[1].w=145;
ti->pos[1].h=145;

ti->pos[2].x=870;
ti->pos[2].y=230;
ti->pos[2].w=145;
ti->pos[2].h=145;

ti->pos[3].x=550;
ti->pos[3].y=370;
ti->pos[3].w=87;
ti->pos[3].h=89;

ti->pos[4].x=700;
ti->pos[4].y=360;
ti->pos[4].w=87;
ti->pos[4].h=89;

ti->pos[5].x=870;
ti->pos[5].y=360;
ti->pos[5].w=87;
ti->pos[5].h=89;

ti->pos[6].x=550;
ti->pos[6].y=510;
ti->pos[6].w=87;
ti->pos[6].h=89;

ti->pos[7].x=700;
ti->pos[7].y=510;
ti->pos[7].w=87;
ti->pos[7].h=89;

ti->pos[8].x=870;
ti->pos[8].y=510;
ti->pos[8].w=87;
ti->pos[8].h=89;

ti->whoplay=0;
ti->whowin=0;
ti->nbr=0;
ti->compteur=0;
}
void afficher_tic(tic ti,SDL_Surface* ecran)
{
SDL_BlitSurface(ti.back,NULL,ecran,NULL);
}
int aleatoire()
{
 int alea;
     srand(time(NULL));
     alea=1+rand()%9;
     return alea;
}
int machine(tic *ti,int alea)
{
while(ti->matrice_suivi[alea]==1 || ti->matrice_suivi[alea]==-1)
{
alea++;
//if(alea==10)
//alea=0;
}
return alea;
}
void afficher_joueur(tic ti,SDL_Surface* ecran)
{int i;
for (i=0;i<9;i++)
if(ti.matrice_suivi[i]==1)
SDL_BlitSurface(ti.x[i],NULL,ecran,&(ti.pos[i]));
}
void afficher_machine(SDL_Surface* ecran,tic ti)
{
int i;
for(i=0;i<9;i++)
{
if(ti.matrice_suivi[i]==-1)
SDL_BlitSurface(ti.o[i],NULL,ecran,&(ti.pos[i]));
}

}
void evaluer(tic *ti)
{
int i;
if(ti->matrice_suivi[0]==1 && ti->matrice_suivi[1]==1 && ti->matrice_suivi[2]==1)
{
ti->whowin=1;
}
if(ti->matrice_suivi[3]==1 && ti->matrice_suivi[4]==1 && ti->matrice_suivi[5]==1)
{
ti->whowin=1;
}
if(ti->matrice_suivi[6]==1 && ti->matrice_suivi[7]==1 && ti->matrice_suivi[8]==1)
{
ti->whowin=1;
}
if(ti->matrice_suivi[0]==1 && ti->matrice_suivi[4]==1 && ti->matrice_suivi[8]==1)
{
ti->whowin=1;
}
if(ti->matrice_suivi[2]==1 && ti->matrice_suivi[4]==1 && ti->matrice_suivi[6]==1)
{
ti->whowin=1;
}
if(ti->matrice_suivi[0]==1 && ti->matrice_suivi[3]==1 && ti->matrice_suivi[6]==1)
{
ti->whowin=1;
}
if(ti->matrice_suivi[1]==1 && ti->matrice_suivi[4]==1 && ti->matrice_suivi[7]==1)
{
ti->whowin=1;
}
if(ti->matrice_suivi[2]==1 && ti->matrice_suivi[5]==1 && ti->matrice_suivi[8]==1)
{
ti->whowin=1;
}

if(ti->matrice_suivi[0]==-1 && ti->matrice_suivi[1]==-1 && ti->matrice_suivi[2]==-1)
{
ti->whowin=-1;
}
if(ti->matrice_suivi[3]==-1 && ti->matrice_suivi[4]==-1 && ti->matrice_suivi[5]==-1)
{
ti->whowin=-1;
}
if(ti->matrice_suivi[6]==-1 && ti->matrice_suivi[7]==-1 && ti->matrice_suivi[8]==-1)
{
ti->whowin=-1;
}
if(ti->matrice_suivi[0]==-1 && ti->matrice_suivi[4]==-1 && ti->matrice_suivi[8]==-1)
{
ti->whowin=-1;
}
if(ti->matrice_suivi[2]==-1 && ti->matrice_suivi[4]==-1 && ti->matrice_suivi[6]==-1)
{
ti->whowin=-1;
}
if(ti->matrice_suivi[0]==-1 && ti->matrice_suivi[3]==-1 && ti->matrice_suivi[6]==-1)
{
ti->whowin=-1;
}
if(ti->matrice_suivi[1]==-1 && ti->matrice_suivi[4]==-1 && ti->matrice_suivi[7]==-1)
{
ti->whowin=-1;
}
if(ti->matrice_suivi[2]==-1 && ti->matrice_suivi[5]==-1 && ti->matrice_suivi[8]==-1)
{
ti->whowin=-1;
}


}
void Defense(tic *ti)
{

if(ti->matrice_suivi[0]==1 && ti->matrice_suivi[1]==1)
ti->matrice_suivi[2]=-1;
if(ti->matrice_suivi[0]==1 && ti->matrice_suivi[4]==1)
ti->matrice_suivi[8]=-1;
if(ti->matrice_suivi[0]==1 && ti->matrice_suivi[3]==1)
ti->matrice_suivi[6]=-1;
if(ti->matrice_suivi[0]==1 && ti->matrice_suivi[8]==1)
ti->matrice_suivi[4]=-1;

if(ti->matrice_suivi[1]==1 && ti->matrice_suivi[2]==1)
ti->matrice_suivi[0]=-1;
if(ti->matrice_suivi[1]==1 && ti->matrice_suivi[4]==1)
ti->matrice_suivi[7]=-1;
if(ti->matrice_suivi[1]==1 && ti->matrice_suivi[7]==1)
ti->matrice_suivi[4]=-1;

if(ti->matrice_suivi[2]==1 && ti->matrice_suivi[4]==1)
ti->matrice_suivi[6]=-1;
if(ti->matrice_suivi[2]==1 && ti->matrice_suivi[5]==1)
ti->matrice_suivi[8]=-1;
if(ti->matrice_suivi[2]==1 && ti->matrice_suivi[8]==1)
ti->matrice_suivi[5]=-1;

if(ti->matrice_suivi[3]==1 && ti->matrice_suivi[4]==1)
ti->matrice_suivi[5]=-1;
if(ti->matrice_suivi[3]==1 && ti->matrice_suivi[6]==1)
ti->matrice_suivi[0]=-1;

if(ti->matrice_suivi[4]==1 && ti->matrice_suivi[7]==1)
ti->matrice_suivi[1]=-1;
if(ti->matrice_suivi[4]==1 && ti->matrice_suivi[5]==1)
ti->matrice_suivi[3]=-1;
if(ti->matrice_suivi[4]==1 && ti->matrice_suivi[3]==1)
ti->matrice_suivi[5]=-1;
if(ti->matrice_suivi[4]==1 && ti->matrice_suivi[8]==1)
ti->matrice_suivi[0]=-1;
if(ti->matrice_suivi[4]==1 && ti->matrice_suivi[6]==1)
ti->matrice_suivi[2]=-1;

if(ti->matrice_suivi[5]==1 && ti->matrice_suivi[8]==1)
ti->matrice_suivi[2]=-1;
if(ti->matrice_suivi[5]==1 && ti->matrice_suivi[3]==1)
ti->matrice_suivi[4]=-1;

if(ti->matrice_suivi[6]==1 && ti->matrice_suivi[7]==1)
ti->matrice_suivi[8]=-1;
if(ti->matrice_suivi[6]==1 && ti->matrice_suivi[2]==1)
ti->matrice_suivi[4]=-1;

}
void attack(tic *ti)
{
if(ti->matrice_suivi[0]==-1 && ti->matrice_suivi[1]==-1)
ti->matrice_suivi[2]=-1;
if(ti->matrice_suivi[0]==-1 && ti->matrice_suivi[4]==-1)
ti->matrice_suivi[8]=-1;
if(ti->matrice_suivi[0]==-1 && ti->matrice_suivi[3]==-1)
ti->matrice_suivi[6]=-1;
if(ti->matrice_suivi[0]==-1 && ti->matrice_suivi[8]==-1)
ti->matrice_suivi[4]=-1;

if(ti->matrice_suivi[1]==-1 && ti->matrice_suivi[2]==-1)
ti->matrice_suivi[0]=-1;
if(ti->matrice_suivi[1]==-1 && ti->matrice_suivi[4]==-1)
ti->matrice_suivi[7]=-1;
if(ti->matrice_suivi[1]==-1 && ti->matrice_suivi[7]==-1)
ti->matrice_suivi[4]=-1;

if(ti->matrice_suivi[2]==-1 && ti->matrice_suivi[4]==-1)
ti->matrice_suivi[6]=-1;
if(ti->matrice_suivi[2]==-1 && ti->matrice_suivi[5]==-1)
ti->matrice_suivi[8]=-1;
if(ti->matrice_suivi[2]==-1 && ti->matrice_suivi[8]==-1)
ti->matrice_suivi[5]=-1;

if(ti->matrice_suivi[3]==-1 && ti->matrice_suivi[4]==-1)
ti->matrice_suivi[5]=-1;
if(ti->matrice_suivi[3]==-1 && ti->matrice_suivi[6]==-1)
ti->matrice_suivi[0]=-1;

if(ti->matrice_suivi[4]==-1 && ti->matrice_suivi[7]==-1)
ti->matrice_suivi[1]=-1;
if(ti->matrice_suivi[4]==-1 && ti->matrice_suivi[5]==-1)
ti->matrice_suivi[3]=-1;
if(ti->matrice_suivi[4]==-1 && ti->matrice_suivi[3]==-1)
ti->matrice_suivi[5]=-1;
if(ti->matrice_suivi[4]==-1 && ti->matrice_suivi[8]==-1)
ti->matrice_suivi[0]=-1;
if(ti->matrice_suivi[4]==-1 && ti->matrice_suivi[6]==-1)
ti->matrice_suivi[2]=-1;

if(ti->matrice_suivi[5]==-1 && ti->matrice_suivi[8]==-1)
ti->matrice_suivi[2]=-1;
if(ti->matrice_suivi[5]==-1 && ti->matrice_suivi[3]==-1)
ti->matrice_suivi[4]=-1;

if(ti->matrice_suivi[6]==-1 && ti->matrice_suivi[7]==-1)
ti->matrice_suivi[8]=-1;
if(ti->matrice_suivi[6]==-1 && ti->matrice_suivi[2]==-1)
ti->matrice_suivi[4]=-1;
}
void nbr_cases_remplis(tic *ti)
{int i;
for(i=0;i<9;i++)
{
if(ti->matrice_suivi[i]==1 || ti->matrice_suivi[i]==-1)
(ti->nbr)++;
}
}
int gameover(tic ti,SDL_Surface* ecran)
{
switch(ti.whowin)
{
case 1:
SDL_BlitSurface(ti.win,NULL,ecran,NULL);
return 3;
//score++
break;
case -1:
SDL_BlitSurface(ti.failed,NULL,ecran,NULL);
return 3;
//score--
break;
/*if(ti.nbr==9)
{
SDL_Delay(1000);
continuer=0;
}*/
/*case 2:
SDL_BlitSurface(ti.null,NULL,ecran,NULL);
break;*/
}

}

























