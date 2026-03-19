#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include"minijeu.h"
void init_minijeu(minijeu *mini)
{
int i,j;
char nomFich[60];
mini->back_mini=IMG_Load("mini_jeu/back_mini.jpg");
for(i=0;i<8;i++)
{
sprintf(nomFich,"mini_jeu/%d.png",i);
mini->tab_images[i]=IMG_Load(nomFich);
mini->tab_carte[i]=IMG_Load("mini_jeu/8.png");
mini->tab_pos[i].w=mini->tab_images[i]->w;
mini->tab_pos[i].h=mini->tab_images[i]->h;
}
for(i=0;i<4;i++)
{
mini->tab_pos[i].y=100;
}
for(i=4;i<8;i++)
{
mini->tab_pos[i].y=400;
}
mini->tab_pos[0].x=300;
mini->tab_pos[1].x=550;
mini->tab_pos[2].x=800;
mini->tab_pos[3].x=1050;
mini->tab_pos[4].x=300;
mini->tab_pos[5].x=550;
mini->tab_pos[6].x=800;
mini->tab_pos[7].x=1050;

mini->clic=-1;
mini->effect=Mix_LoadWAV("mini_jeu/Bip.wav");
mini->win=Mix_LoadWAV("mini_jeu/Space_Tone.wav");
for(i=0;i<2;i++)
{
for(j=0;j<4;j++)
{
mini->matrice[i][j]=-1;
mini->compteur=0;
}
}
}
void afficher_minijeu(minijeu mini,SDL_Surface* screen)
{int i;
SDL_BlitSurface(mini.back_mini,NULL,screen,NULL);
switch(mini.clic)
{
case -1:
for(i=0;i<8;i++)
{
SDL_BlitSurface(mini.tab_carte[i],NULL,screen,&(mini.tab_pos[i]));
}
break;

case 0:
for(i=0;i<8;i++)
{
SDL_BlitSurface(mini.tab_carte[i],NULL,screen,&(mini.tab_pos[i]));
}
SDL_BlitSurface(mini.tab_images[0],NULL,screen,&(mini.tab_pos[0]));

break;

case 1:
for(i=0;i<8;i++)
{
SDL_BlitSurface(mini.tab_carte[i],NULL,screen,&(mini.tab_pos[i]));
}
SDL_BlitSurface(mini.tab_images[1],NULL,screen,&(mini.tab_pos[1]));

break;

case 2:
for(i=0;i<8;i++)
{
SDL_BlitSurface(mini.tab_carte[i],NULL,screen,&(mini.tab_pos[i]));
}
SDL_BlitSurface(mini.tab_images[2],NULL,screen,&(mini.tab_pos[2]));

break;

case 3:
for(i=0;i<8;i++)
{
SDL_BlitSurface(mini.tab_carte[i],NULL,screen,&(mini.tab_pos[i]));
}
SDL_BlitSurface(mini.tab_images[3],NULL,screen,&(mini.tab_pos[3]));

break;

case 4:
for(i=0;i<8;i++)
{
SDL_BlitSurface(mini.tab_carte[i],NULL,screen,&(mini.tab_pos[i]));
}
SDL_BlitSurface(mini.tab_images[4],NULL,screen,&(mini.tab_pos[4]));

break;

case 5:
for(i=0;i<8;i++)
{
SDL_BlitSurface(mini.tab_carte[i],NULL,screen,&(mini.tab_pos[i]));
}
SDL_BlitSurface(mini.tab_images[5],NULL,screen,&(mini.tab_pos[5]));

break;

case 6:
for(i=0;i<8;i++)
{
SDL_BlitSurface(mini.tab_carte[i],NULL,screen,&(mini.tab_pos[i]));
}
SDL_BlitSurface(mini.tab_images[6],NULL,screen,&(mini.tab_pos[6]));

break;

case 7:
for(i=0;i<8;i++)
{
SDL_BlitSurface(mini.tab_carte[i],NULL,screen,&(mini.tab_pos[i]));
}
SDL_BlitSurface(mini.tab_images[7],NULL,screen,&(mini.tab_pos[7]));
break;

}
if(mini.matrice[0][1]==1 && mini.matrice[1][1]==1)
{
SDL_BlitSurface(mini.tab_images[5],NULL,screen,&(mini.tab_pos[5]));
SDL_BlitSurface(mini.tab_images[1],NULL,screen,&(mini.tab_pos[1]));
}
if(mini.matrice[0][3]==1 && mini.matrice[1][2]==1)
{
SDL_BlitSurface(mini.tab_images[3],NULL,screen,&(mini.tab_pos[3]));
SDL_BlitSurface(mini.tab_images[6],NULL,screen,&(mini.tab_pos[6]));
}
if(mini.matrice[0][0]==1 && mini.matrice[0][2]==1)
{
SDL_BlitSurface(mini.tab_images[0],NULL,screen,&(mini.tab_pos[0]));
SDL_BlitSurface(mini.tab_images[2],NULL,screen,&(mini.tab_pos[2]));
}
if(mini.matrice[1][0]==1 && mini.matrice[1][3]==1)
{
SDL_BlitSurface(mini.tab_images[4],NULL,screen,&(mini.tab_pos[4]));
SDL_BlitSurface(mini.tab_images[7],NULL,screen,&(mini.tab_pos[7]));
}
}
int check(minijeu mini)
{
int i,j,compteur=0;
for(i=0;i<2;i++)
{
for(j=0;j<4;j++)
{
if(mini.matrice[i][j]==1)
{
compteur++;
printf("comteur=%d\n",compteur);
}
else compteur=0;
if(compteur==7)
return 1;
else 
return 0;
}
}
}





