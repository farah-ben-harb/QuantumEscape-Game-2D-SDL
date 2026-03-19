#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"ennemi.h"

#define vitesse 7
void InitEnnemi2 (Ennemi *e)
{    int i,j=0;
    char nomFich[60];
    for ( i = 0; i < 8; i++)
    {
        sprintf(nomFich,"image3/%d.png",j);
        e->mvtright2[i]=IMG_Load(nomFich);
	j++;
    }
	j=9;
    for ( i = 0; i < 8; i++)
    {
        sprintf(nomFich,"image3/%d.png",j);
        e->mvtleft2[i]=IMG_Load(nomFich);
	j++;
    }
e->position_ennemi2.x=1200;
e->position_ennemi2.y=380; //300
e->position_ennemi2.w=336;//largeur de l'ennemie
e->position_ennemi2.h=389;//hauteur de l'ennemie
e->fd=0;
e->frame1=e->mvtright2[0];
e->bb2=0;
e->etat_ennemi=0;
for(i=0;i<4;i++)
{
sprintf(nomFich,"fire_bleu/%d.png",i);
e->fire_right[i]=IMG_Load(nomFich);
}
e->pos_fire_right.x=1200;
e->pos_fire_right.y=550;
e->fir=0;
e->fire_rightt=e->fire_right[0];
e->bleu=0;
e->direction=0;
}
void InitEnnemi (Ennemi *e)
{
    int i,j=0;
    char nomFich[60];
    for ( i = 0; i < 8; i++)
    {
        sprintf(nomFich,"image/%d.png",i+1);
        e->mvtright[j]=IMG_Load(nomFich);
	j++;
    }
	j=0;
    for ( i = 8; i < 16; i++)
    {
        sprintf(nomFich,"image/%d.png",i+1);
        e->mvtleft[j]=IMG_Load(nomFich);
	j++;
    }
	j=17;
    for ( i = 0; i < 5; i++)
    {
        sprintf(nomFich,"image/%d.png",j);
        e->dieright[i]=IMG_Load(nomFich);
	j++;
    }
     j=22;
    for ( i = 0; i < 5; i++)
    {
        sprintf(nomFich,"image/%d.png",j);
        e->dieleft[i]=IMG_Load(nomFich);
	j++;
    }


for(i=0;i<4;i++)
{
sprintf(nomFich,"Hell/%d.png",i);
e->fire_right[i]=IMG_Load(nomFich);
e->fire_left[i]=IMG_Load(nomFich);
}
e->pos_fire_right.x=400;
e->pos_fire_right.y=550;
e->pos_fire_left.x=400;
e->pos_fire_left.y=550;
e->fir=0;
e->fil=0;
e->fire_rightt=e->fire_right[0];
e->fire_leftt=e->fire_left[0];

e->position_ennemi.x=1000;
e->position_ennemi.y=550; //300
e->position_ennemi.w=e->mvtright[0]->w;//largeur de l'ennemie
e->position_ennemi.h=e->mvtright[0]->h;//hauteur de l'ennemie
(e->frame)=(e->mvtright[0]);
e->fr=0;
e->diee=e->dieright[0];
e->vie=3;
e->bb=0;
for(i=0;i<3;i++)
{
e->image_vie[i]=IMG_Load("vie/vie.png");
}

e->pos_vie[0].x=10+1000;
e->pos_vie[0].y=35;
e->pos_vie[1].x=90+1000;
e->pos_vie[1].y=35;
e->pos_vie[2].x=170+1000;
e->pos_vie[2].y=35;
e->coin=IMG_Load("images_background/coins.png");
e->position_score.x=10;
e->position_score.y=10;
for(i=0;i<6;i++)
{
sprintf(nomFich,"obstacle/%d.png",i);
e->obstacle[i]=IMG_Load(nomFich);
}
e->pos_obstacle.x=10;
e->pos_obstacle.y=150;
e->pos_obstacle.w=e->obstacle[0]->w;
e->pos_obstacle.h=e->obstacle[0]->h;
e->obs=e->obstacle[0];
e->ob=0;
e->direction=0;
}
void initialiser_star(Ennemi *s)
{char nomFich[60];
int j=0,i;
    for(i=0;i<7;i++)
    {
	sprintf(nomFich,"star/%d.png",i+1);
	s->star[j]=IMG_Load(nomFich);
        j++;
    }
s->pos_star[0].x=1315;
s->pos_star[0].y=145;
s->pos_star[1].x=1415-20;
s->pos_star[1].y=145;
s->pos_star[2].x=1515-40;
s->pos_star[2].y=145;
s->st=s->star[0];
s->fr=0;
s->nbr_etoile=0;
s->next_level[0]=IMG_Load("next/0.jpg");
s->next_level[1]=IMG_Load("next/1.jpg");
s->next_level[2]=IMG_Load("next/2.jpg");
s->next_level[3]=IMG_Load("next/3.jpg");
s->next[0]=IMG_Load("next/next.png");
s->next[1]=IMG_Load("next/next1.png");
s->pos_next.x=685;
s->pos_next.y=575;
s->pos_next.w=s->next[0]->w;
s->pos_next.h=s->next[0]->h;
s->clic=0;
s->motion=0;
s->barre_star=IMG_Load("star/fond.png");
s->pos_barre.x=1300;
s->pos_barre.y=140;
}
void initialiser_coin(Ennemi *c)
{int i;
char nomFich[60];
    for(i=0;i<7;i++)
    {
	sprintf(nomFich,"coins/%d.png",i);
	c->coins[i]=IMG_Load(nomFich);
        
    }
	c->pos_coin[0].x=2000-1400;
	c->pos_coin[0].y=500;
	c->pos_coin[0].w=c->coins[0]->w;
	c->pos_coin[0].h=c->coins[0]->h;

	c->pos_coin[1].x=2050-1400;
	c->pos_coin[1].y=500;
	c->pos_coin[1].w=c->coins[0]->w;
	c->pos_coin[1].h=c->coins[0]->h;

	c->pos_coin[2].x=2100-1400;
	c->pos_coin[2].y=500;
	c->pos_coin[2].w=c->coins[0]->w;
	c->pos_coin[2].h=c->coins[0]->h;
	c->cs[0]=c->coins[0];
	c->cs[1]=c->coins[0];
	c->cs[2]=c->coins[0];
	c->fr=0;
}
void afficher_Entite(Ennemi e,SDL_Surface* screen)
{
switch(e.vie)
{
case 3:
SDL_BlitSurface(e.image_vie[0],NULL,screen,&(e.pos_vie[0]));
SDL_BlitSurface(e.image_vie[1],NULL,screen,&(e.pos_vie[1]));
SDL_BlitSurface(e.image_vie[2],NULL,screen,&(e.pos_vie[2]));
break;
case 2:
SDL_BlitSurface(e.image_vie[0],NULL,screen,&(e.pos_vie[0]));
SDL_BlitSurface(e.image_vie[1],NULL,screen,&(e.pos_vie[1]));
break;
case 1:
SDL_BlitSurface(e.image_vie[0],NULL,screen,&(e.pos_vie[0]));
break;
}
}
void afficher_ennemi(Ennemi e,SDL_Surface* screen)
{
SDL_BlitSurface(e.frame,NULL,screen,&(e.position_ennemi));
}
void afficher_ennemi2(Ennemi e,SDL_Surface* screen)
{
SDL_BlitSurface(e.frame1,NULL,screen,&(e.position_ennemi2));
}
void afficher_ennemi_die(Ennemi e,SDL_Surface* screen)
{
SDL_BlitSurface(e.diee,NULL,screen,&(e.position_ennemi));
}
void afficher_star(Ennemi s ,SDL_Surface* screen)
{SDL_BlitSurface(s.barre_star,NULL,screen,&(s.pos_barre));
switch(s.nbr_etoile)
{
case 1:
SDL_BlitSurface(s.st,NULL,screen,&(s.pos_star[0]));
break;
case 2:
SDL_BlitSurface(s.st,NULL,screen,&(s.pos_star[0]));
SDL_BlitSurface(s.st,NULL,screen,&(s.pos_star[1]));
break;

case 3:
SDL_BlitSurface(s.st,NULL,screen,&(s.pos_star[0]));
SDL_BlitSurface(s.st,NULL,screen,&(s.pos_star[1]));
SDL_BlitSurface(s.st,NULL,screen,&(s.pos_star[2]));
break;
}


}
void afficher_coins(Ennemi c,SDL_Surface* screen)
{
SDL_BlitSurface(c.cs[0],NULL,screen,&(c.pos_coin[0]));
SDL_BlitSurface(c.cs[1],NULL,screen,&(c.pos_coin[1]));
SDL_BlitSurface(c.cs[2],NULL,screen,&(c.pos_coin[2]));
}
void animer_Ennemi_right(Ennemi *e)
{
 	if ((e->fr<0)||(e->fr>6))
    	{
        e->fr=0;
    	}
    	e->fr++;
    	e->frame=e->mvtright[e->fr];
}
void animer_Ennemi_left (Ennemi *e)
{

    if ((e->fr<0)||(e->fr>6))
    {
        e->fr=0;
    }
    e->fr++;
    e->frame=e->mvtleft[e->fr];

}
void animer_Ennemi_right2(Ennemi *e)
{
 	if (e->fr>6)
    	{
        e->fr=0;
    	}
    	e->fr++;
    	e->frame1=e->mvtright2[e->fr];
}
void animer_Ennemi_left2 (Ennemi *e)
{

    if (e->fr>6)
    {
        e->fr=0;
    }
    e->fr++;
    e->frame1=e->mvtleft2[e->fr];

}
void animer_star(Ennemi *s)
{
if(s->fr>5)
{
s->fr=0;
}
s->fr++;
s->st=s->star[s->fr];
}
void animer_coins(Ennemi *c)
{
if(c->fr>5)
{
c->fr=0;
}
c->fr++;
c->cs[0]=c->coins[c->fr];
c->cs[1]=c->coins[c->fr];
c->cs[2]=c->coins[c->fr];
}
void deplacement_aleatoire(Ennemi *e)
{
if (e->position_ennemi.x >1500)//posmax
{
	e->direction=0;
	
}
if(e->position_ennemi.x<500)//posmin
{
	e->direction=1;
	
}
if ((e->direction)==0)
{
e->position_ennemi.x-=6;
}
if((e->direction)==1)
{
e->position_ennemi.x+=6;
}
}
void deplacement_aleatoire2(Ennemi *e)
{
if (e->position_ennemi2.x >1400)//posmax
{
	e->direction=0;
	
}
if(e->position_ennemi2.x<800)//posmin
{
	e->direction=1;
	
}
if ((e->direction)==0)
{
e->position_ennemi2.x-=12;
}
if((e->direction)==1)
{
e->position_ennemi2.x+=12;
}
}
int collisionbb(perso p,Ennemi e )
{
if ( (p.rect.x +p.rect.w < e.position_ennemi.x) || (p.rect.x >e.position_ennemi.x+e.position_ennemi.w) || (p.rect.y > e.position_ennemi.y+e.position_ennemi.h))
return 0; 
else 
return 1;
}
void gestion_vie(Ennemi *e,perso p,int *col)
{
if(collisionbb(p,*e))
{
e->image_vie[*col]=NULL;
(*col)--;
}
if((*col)==-1)
initialiser_perso(&p);
}
void calculer_distance (perso p,Ennemi *e) 
{
  int D ;
if(e->position_ennemi.x>p.rect.x)
  D=e->position_ennemi.x - p.rect.x;
else
D= p.rect.x- e->position_ennemi.x;
 if (D>=1500)
  e->etat_ennemi=0;
 if (D<1500 && D>400)
 e->etat_ennemi=1;
 if (D<=400 && D>=0)
e->etat_ennemi=2;
}
void mise_a_jour(perso p,Ennemi e)
{
switch (e.etat_ennemi)
{
case 0:
 if (e.direction==0)
 animer_Ennemi_right(&e);
if (e.direction==1)
animer_Ennemi_left(&e);
break;
case 1:
deplacement_aleatoire(&e);
break;
case 2:
deplacement_aleatoire(&e);
//attack
}
}
void initialiser_porte(Ennemi *po)
{
int i;
char nomFich[60];
    for(i=0;i<6;i++)
    {
	sprintf(nomFich,"porte/%d.png",i);
	po->porte[i]=IMG_Load(nomFich);
    }
po->pos_porte.x=1200;
po->pos_porte.y=1300;
po->pos_porte.w=po->porte[0]->w;
po->pos_porte.h=po->porte[0]->h;

po->fr=0;
po->portt=po->porte[0];

}
void afficher_porte(Ennemi po,SDL_Surface* screen1)
{
SDL_BlitSurface(po.portt,NULL,screen1,&po.pos_porte);
}
void animer_porte(Ennemi *po)
{
if(po->fr>4)
{
po->fr=0;
}
po->fr++;
po->portt=po->porte[po->fr];
}
int collision_coins(Ennemi c ,perso p)
{
if ( (p.rect.x +p.rect.w < c.pos_coin[0].x) || (p.rect.x >c.pos_coin[0].x+c.pos_coin[0].w) || (p.rect.y > c.pos_coin[0].y+c.pos_coin[0].h) ||(p.rect.h > c.pos_coin[0].y))
return 0; 
else 
return 1;

}
void init_score(Ennemi *e,char score[])
{
SDL_Color couleurBlanche = {255, 255, 255};
e->police = TTF_OpenFont("SF_TransRobotics_Bold.ttf", 35);
e->texte = TTF_RenderText_Blended(e->police,score, couleurBlanche);/* Initialisation du texte*/
        e->position_texte.x = 110;
        e->position_texte.y = 40;
	e->scor=0;
}
void gestion_score(Ennemi *e,char score[])
{
SDL_Color couleurBlanche = {255, 255, 255};
sprintf(score, "%d", e->scor);
SDL_FreeSurface(e->texte);
e->texte = TTF_RenderText_Blended(e->police, score,couleurBlanche);
}

int collisionbb_attack(perso p,Ennemi e)
{
if ( (p.pos_attack.x +p.pos_attack.w < e.position_ennemi.x) || (p.pos_attack.x >e.position_ennemi.x+e.position_ennemi.w) /*|| (p.pos_attack.h<e.position_ennemi.y)*/ || (p.pos_attack.y > e.position_ennemi.y+e.position_ennemi.h))
return 0;
else 
return 1;
}
void animer_die_right(Ennemi *e)
{
   if (e->fd>8)
    {
        e->fd=0;
    }
    e->fd++;
    e->diee=e->dieright[e->fd];
}
void animer_die_left(Ennemi *e)
{
    if (e->fd>8)
    {
        e->fd=0;
    }
    e->fd++;
    e->diee=e->dieleft[e->fd];
}

void liberer_ennemi(Ennemi *e, Ennemi *s,Ennemi *c)
{
int i;
for(i=0;i<8;i++)
{
SDL_FreeSurface(e->mvtright[i]);
SDL_FreeSurface(e->mvtleft[i]);
}
for(i=0;i<7;i++)
{
SDL_FreeSurface(s->star[i]);
SDL_FreeSurface(c->coins[i]);
}
for (i=0;i<5;i++)
{
SDL_FreeSurface(e->dieright[i]);
SDL_FreeSurface(e->dieleft[i]);
}
}
void init_Ennemi3(Ennemi*e)
{
    int i,j=0;
    char nomFich[60];
    for ( i = 0; i < 8; i++)
    {
        sprintf(nomFich,"Ennemi2/%d.png",i+1);
        e->mvtright3[j]=IMG_Load(nomFich);
	j++;
    }
	j=0;
    for ( i = 14; i < 23; i++)
    {
        sprintf(nomFich,"Ennemi2/%d.png",i+1);
        e->mvtleft3[j]=IMG_Load(nomFich);
	j++;
    }
	j=10;
    for ( i = 0; i < 5; i++)
    {
        sprintf(nomFich,"Ennemi2/%d.png",j);
        e->dieright3[i]=IMG_Load(nomFich);
	j++;
    }
     j=23;
    for ( i = 0; i < 5; i++)
    {
        sprintf(nomFich,"Ennemi2/%d.png",j);
        e->dieleft3[i]=IMG_Load(nomFich);
	j++;
    }
e->frame3=e->mvtright3[0];
e->position_ennemi3.x=800;
e->position_ennemi3.y=550;
e->fd3=0;
e->bb3=0;
e->direction=1;
}
void afficher_ennemi3(Ennemi e,SDL_Surface* screen)
{
SDL_BlitSurface(e.frame3,NULL,screen,&(e.position_ennemi3));
}
void animer_ennemi3_right(Ennemi *e)
{
if (e->fd3>5)
    	{
        e->fd3=0;
    	}
    	e->fd3++;
    	e->frame3=e->mvtright3[e->fd3];
}
void animer_ennemi3_left(Ennemi *e)
{
if (e->fd3>5)
    	{
        e->fd3=0;
    	}
    	e->fd3++;
    	e->frame3=e->mvtleft3[e->fd3];
}
void deplacement_aleatoire3(Ennemi *e)
{
if (e->position_ennemi3.x >1400)//posmax
{
	e->direction=0;
	
}
if(e->position_ennemi3.x<400)//posmin
{
	e->direction=1;
	
}
if ((e->direction)==0)
{
e->position_ennemi3.x-=12;
}
if((e->direction)==1)
{
e->position_ennemi3.x+=12;
}
}
int collisionbb_attack3(perso p,Ennemi e)
{
if ( (p.pos_attack.x +p.pos_attack.w < e.position_ennemi3.x) || (p.pos_attack.x >e.position_ennemi3.x+e.position_ennemi3.w) /*|| (p.pos_attack.h<e.position_ennemi.y)*/ || (p.pos_attack.y > e.position_ennemi3.y+e.position_ennemi3.h))
return 0; 
else 
return 1;
}
int collisionbb_attack2(perso p,Ennemi e)
{
if ( (p.pos_attack.x +p.pos_attack.w < e.position_ennemi2.x) || (p.pos_attack.x >e.position_ennemi2.x+e.position_ennemi2.w) /*|| (p.pos_attack.h<e.position_ennemi.y)*/ || (p.pos_attack.y > e.position_ennemi2.y+e.position_ennemi2.h))
return 0; 
else 
return 1;
}

void afficher_score(Ennemi e,SDL_Surface* screen)
{
SDL_BlitSurface(e.coin,NULL,screen,&e.position_score);
SDL_BlitSurface(e.texte, NULL, screen, &(e.position_texte));
}
void afficher_next_level(Ennemi e,SDL_Surface* screen)
{
switch(e.nbr_etoile)
{
case 0:
SDL_BlitSurface(e.next_level[0],NULL,screen,NULL);
break;
case 1:
SDL_BlitSurface(e.next_level[1],NULL,screen,NULL);
break;
case 2:
SDL_BlitSurface(e.next_level[2],NULL,screen,NULL);
break;
case 3:
SDL_BlitSurface(e.next_level[3],NULL,screen,NULL);
break;

}
}
void afficher_next(Ennemi e,SDL_Surface* screen)
{
switch(e.motion)
{
case 0:
SDL_BlitSurface(e.next[0],NULL,screen,&e.pos_next);
break;
case 1:
SDL_BlitSurface(e.next[1],NULL,screen,&e.pos_next);
break;
}
}
void afficher_obstacle(Ennemi e,SDL_Surface* screen)
{
SDL_BlitSurface(e.obs,NULL,screen,&(e.pos_obstacle));
}
void animer_obstacle(Ennemi *e)
{
if(e->ob>4)
{
e->ob=0;
}
e->ob++;
e->obs=e->obstacle[e->ob];
}
int collision_obstacle(Ennemi e ,perso p)
{
if ( (p.rect.x +p.rect.w < e.pos_obstacle.x) || (p.rect.x >e.pos_obstacle.x+e.pos_obstacle.w))
return 0; 
else 
return 1;
}
void animer_fire_right(Ennemi *e)
{
 	if (e->fir>2)
    	{
        e->fir=0;
    	}
    	e->fir++;
    	e->fire_rightt=e->fire_right[e->fir];
}
void animer_fire_left(Ennemi *e)
{
 	if (e->fil>2)
    	{
        e->fil=0;
    	}
    	e->fil++;
    	e->fire_leftt=e->fire_left[e->fil];
}
void afficher_attack_right(Ennemi e,SDL_Surface* screen)
{
SDL_BlitSurface(e.fire_rightt,NULL,screen,&(e.pos_fire_right));
}
void afficher_attack_left(Ennemi e,SDL_Surface* screen)
{
SDL_BlitSurface(e.fire_leftt,NULL,screen,&(e.pos_fire_left));
}
void calculer_distance2(perso p,Ennemi *e) 
{
  int D ;
if(e->position_ennemi2.x>p.rect.x)
  D=e->position_ennemi2.x - p.rect.x;
else
D= p.rect.x- e->position_ennemi2.x;
 if (D>=1500)
  e->etat_ennemi=0;
 if (D<1500 && D>700)
 e->etat_ennemi=1;
 if (D<=700 && D>=0)
e->etat_ennemi=2;
}
int collisionbb_attac_bleu(perso p,Ennemi e)
{
if ( (p.rect.x +p.rect.w <e.pos_fire_right.x ) || (p.rect.x >e.pos_fire_right.x+p.rect.w) || (p.rect.y > e.pos_fire_right.y+e.pos_fire_right.h))
return 0; 
else 
return 1;
}


