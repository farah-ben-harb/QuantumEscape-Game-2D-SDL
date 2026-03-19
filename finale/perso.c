 /** 
* @file perso.c 
*/ 
#include "perso.h"
#include <math.h>
#define GRAVITY 9
#define vitesse_max 17
#define MAX_JUMP_SPEED 20
//#define MAX_SPEED 17

/** 
* @brief To initialize the perso p . 
* @param p the perso 
* @param url the url of the image  
* @return Nothing 
*/ 


void initialiser_perso (perso *p){
    int i,j;
    char nomFich[60];

    for ( i = 0; i < 10; i++)
    {
        sprintf(nomFich,"per/%d.png",i);
        p->mvtright[i]=IMG_Load(nomFich);
    }
    for ( i = 0; i < 10; i++)
    {
        sprintf(nomFich,"per/%d.png",i+10);
        p->mvtleft[i]=IMG_Load(nomFich);
    }
    for ( i = 0; i < 16; i++)
    {
        sprintf(nomFich,"per/%d.png",i+20);
        p->jumpright[i]=IMG_Load(nomFich);
    }
    for ( i = 0; i < 16; i++)
    {
        sprintf(nomFich,"per/%d.png",i+35);
        p->jumpleft[i]=IMG_Load(nomFich);
    }
    for ( i = 0; i < 11; i++)
    {
        sprintf(nomFich,"per/%d.png",i+50);
        p->runright[i]=IMG_Load(nomFich);
    }
    for ( i = 0; i < 11; i++)
    {
        sprintf(nomFich,"per/%d.png",i+61);
        p->runleft[i]=IMG_Load(nomFich);
    }
     for ( i = 0; i < 16; i++)
    {
        sprintf(nomFich,"per/%d.png",i+70);
        p->dieright[i]=IMG_Load(nomFich);
    }
       for ( i = 0; i < 8; i++)
    {
        sprintf(nomFich,"per/%d.png",i+78);
        p->dieleft[i]=IMG_Load(nomFich);
    }
    for ( i = 0; i < 4; i++)
    {
        sprintf(nomFich,"attack_leila/%d.png",i);
        p->attack[i]=IMG_Load(nomFich);
    }
p->at=p->attack[0];
p->rect.x=40;
p->rect.y=150; //300
p->rect_relative.x=40;
p->rect_relative.y=150; //
p->rect.w=138;
p->rect.h=233;
p->speedX=0;
p->speedY=0;
p->frame=p->mvtright[1];
p->num_image=0;
p->direction=0;
p->vitesse = 0.5;
p->acceleration= 0.05;
p->pos_attack.x=350;
p->pos_attack.y=570;
p->pos_attack.w=p->attack[0]->w;
p->pos_attack.h=p->attack[0]->h;
}

void initialiser_perso2 (perso *p){
    int i,j;
    char nomFich[60];

    for ( i = 0; i < 10; i++)
    {
        sprintf(nomFich,"per2/%d.png",i);
        p->mvtright[i]=IMG_Load(nomFich);
    }
    for ( i = 0; i < 10; i++)
    {
        sprintf(nomFich,"per2/%d.png",i+10);
        p->mvtleft[i]=IMG_Load(nomFich);
    }
    for ( i = 0; i < 16; i++)
    {
        sprintf(nomFich,"per2/%d.png",i+20);
        p->jumpright[i]=IMG_Load(nomFich);
    }
    for ( i = 0; i < 16; i++)
    {
        sprintf(nomFich,"per2/%d.png",i+35);
        p->jumpleft[i]=IMG_Load(nomFich);
    }
    for ( i = 0; i < 11; i++)
    {
        sprintf(nomFich,"per2/%d.png",i+50);
        p->runright[i]=IMG_Load(nomFich);
    }
    for ( i = 0; i < 11; i++)
    {
        sprintf(nomFich,"per2/%d.png",i+61);
        p->runleft[i]=IMG_Load(nomFich);
    }
     for ( i = 0; i < 8; i++)
    {
        sprintf(nomFich,"per/%d.png",i+70);
        p->dieright[i]=IMG_Load(nomFich);
    }
       for ( i = 0; i < 8; i++)
    {
        sprintf(nomFich,"per/%d.png",i+78);
        p->dieleft[i]=IMG_Load(nomFich);
    }
p->rect.x=800;
p->rect.y=0; //300
p->rect_relative.x=150;
p->rect_relative.y=0; //
p->rect.w=138;
p->rect.h=233;
p->speedX=0;
p->speedY=0;
p->frame=p->mvtright[1];
p->num_image=0;
p->direction=0;
p->vitesse = 1;
p->acceleration= 0.1;
    
}

/** 
* @brief To show the perso p. 
* @param scren the screen 
* @param p the perso 
* @return Nothing 
*/ 

void afficher_perso (perso *p,SDL_Surface *screen)
{
  SDL_BlitSurface(p->frame,NULL,screen,&p->rect);
}

void afficher_perso2 (perso *p2,SDL_Surface *screen)
{
  SDL_BlitSurface(p2->frame,NULL,screen,&p2->rect);
}


/** 
* @brief To animate the perso to the right . 
* @param p the perso
* @return Nothing 
*/ 


void animation_right (perso *p){ 
if (p->direction==0)
{
    if (p->num_image>8)
    {
        p->num_image=0;
    }
    p->num_image++;
    p->frame=p->mvtright[p->num_image];
}
 else   
{
    if ( p->num_image > 8) p->num_image=0;
    p->num_image++;
    p->frame=p->runright[p->num_image];

}
}


/** 
* @brief To animate the perso to the left . 
* @param p the perso
* @return Nothing 
*/ 


void animation_left (perso *p){
if (p->speedX<7)
{
    if (p->num_image>8)
    {
        p->num_image=0;
    }
    p->num_image++;
    p->frame=p->mvtleft[p->num_image];
    
}else{
    if ( p->num_image > 7) p->num_image=0;
    p->num_image++;
    p->frame=p->runleft[p->num_image];
}

}

//fontion dep avec vitesse constante 


/** 
* @brief To move the perso to the right . 
* @param p the perso
* @return Nothing 
*/ 


void dep_right(perso *p,Uint32 dt)
{
/*if(p->speedX>=10)
p->speedX==10;*/
p->rect.x += (p->speedX) *dt;

}


/** 
* @brief To move  the perso to the left . 
* @param p the perso
* @return Nothing 
*/ 


void dep_left(perso *p,Uint32 dt)
{
/*if(p->speedX==10)
p->speedX==10;*/
p->rect.x -= (p->speedX) *dt;

}


/** 
* @brief To movement the perso to the right . 
* @param p the perso
* @return Nothing 
*/ 


void mouvementright (perso *p,Uint32 dt)////////// acceleration
{
p->speedX+=p->acceleration*dt;
if(p->acceleration==15)
p->acceleration==15;
if (p->rect.x<250)
{
p->rect.x+=0.5*(p->acceleration)*dt*dt+((p->speedX)*dt) ; 
p->rect_relative.x+=0.5*(p->acceleration)*dt*dt+((p->speedX)*dt) ;
}
//p->rect.x+=p->vitesse*dt deplacement constant (vitesse=1)
}

/** 
* @brief To movement the perso to the left . 
* @param p the perso
* @return Nothing 
*/ 


void mouvementleft (perso *p,Uint32 dt)
{
 p->vitesse-=p->acceleration*dt;
if(p->acceleration>=15)
p->acceleration==15;
if(p->speedX==10)
p->speedX==10;
if (p->rect.x<250)
{
p->rect.x-=0.5*(p->acceleration)*dt*dt+((p->speedX)*dt) ; 
p->rect_relative.x-=0.5*(p->acceleration)*dt*dt+((p->speedX)*dt) ;
} 
/*if (p->speedX=MAX_SPEED)
	p->speedX=MAX_SPEED;
if (p->rect.x<350)
{*/
//}
}

/** 
* @brief To jump the perso to the right . 
* @param p the perso
* @return Nothing 
*/ 
 


void jumpright (perso *p)
{

if (p->speedX>=MAX_JUMP_SPEED)
	p->speedX=MAX_JUMP_SPEED;
if (p->rect.x<250)
{
  p->speedX+=5;
p->rect.x+=p->speedX;
p->rect_relative.x+=p->speedX;
}
}


/** 
* @brief To jump the perso to the left . 
* @param p the perso
* @return Nothing 
*/ 


void jumpleft (perso *p)
{
if (p->speedX>=MAX_JUMP_SPEED)
	p->speedX=MAX_JUMP_SPEED;
if (p->rect.x>0){
p->rect.x-=p->speedX;
p->rect_relative.x-=p->speedX;
}
}

/** 
* @brief To initialize the input i . 
* @param i the input 
* @param url the url of the image  
* @return Nothing 
*/ 


void initialiser_input (Input *I)
{
I->left=0;
I->right=0;
I->down=0;
I->jump=0;
I->acction=0;
I->attack=0;
}
void initialiser_input2 (Input *I2)
{
I2->left=0;
I2->right=0;
I2->down=0;
I2->jump=0;
I2->acction=0;
}
void animer_attack(perso *p)
{
    if (p->num_image>3)
    {
        p->num_image=0;
    }
    p->num_image++;
    p->at=p->attack[p->num_image];
}

void afficher_attack(perso p,SDL_Surface *screen)
{
SDL_BlitSurface(p.attack[p.num_image],NULL,screen,&p.pos_attack);
//
}
void animation_die_right (perso *p)
  
{
   if (p->num_image>7)
    {
        p->num_image=0;
    }
    p->num_image++;
    p->frame=p->dieright[p->num_image];
}
void animation_die_left (perso *p)
  
{
   if (p->num_image>7)
    {
        p->num_image=0;
    }
    p->num_image++;
    p->frame=p->dieleft[p->num_image];
}

