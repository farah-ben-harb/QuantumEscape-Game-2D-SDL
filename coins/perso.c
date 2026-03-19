 /** 
* @file perso.c 
*/ 
#include "perso.h"
#include <math.h>
#define GRAVITY 9.8
#define vitesse_max 17
#define MAX_JUMP_SPEED 20
#define MAX_SPEED 17

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
    for ( i = 0; i < 9; i++)
    {
        sprintf(nomFich,"per/%d.png",i+71);
        p->die[i]=IMG_Load(nomFich);
    }
p->rect.x=0;
p->rect.y=150; //300
p->rect_relative.x=0;
p->rect_relative.y=150; //
p->rect.w=138;
p->rect.h=233;
p->speedX=0;
p->speedY=0;
p->frame=p->mvtright[0];
p->num_image=0;
p->direction=0;
p->vitesse = 0.25;
p->acceleration= 0.01;
    


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
    for ( i = 0; i < 9; i++)
    {
        sprintf(nomFich,"per2/%d.png",i+71);
        p->die[i]=IMG_Load(nomFich);
    }
p->rect.x=0;
p->rect.y=150; //300
p->rect_relative.x=0;
p->rect_relative.y=150; //
p->rect.w=138;
p->rect.h=233;
p->speedX=0;
p->speedY=0;
p->frame=p->mvtright[0];
p->num_image=0;
p->direction=0;
p->vitesse = 1;
p->acceleration= 0.01;
    
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
    if ((p->num_image<0)||(p->num_image>9))
    {
        p->num_image=0;
    }
    p->num_image++;
    p->frame=p->mvtright[p->num_image];
}
 else   
{
    if (p->num_image < 0 || p->num_image > 8) p->num_image=0;
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
    if ((p->num_image<0)||(p->num_image>9))
    {
        p->num_image=0;
    }
    p->num_image++;
    p->frame=p->mvtleft[p->num_image];
    
}else{
    if (p->num_image < 0 || p->num_image > 7) p->num_image=0;
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
p->rect.x += (p->vitesse) *dt;

}


/** 
* @brief To move  the perso to the left . 
* @param p the perso
* @return Nothing 
*/ 


void dep_left(perso *p,Uint32 dt)
{
p->rect.x -= (p->vitesse) *dt;

}


/** 
* @brief To movement the perso to the right . 
* @param p the perso
* @return Nothing 
*/ 


void mouvementright (perso *p,Uint32 dt)////////// acceleration
{
p->vitesse+=p->acceleration*dt;
p->rect.x+=0.5*(p->acceleration)*dt*dt+((p->vitesse)*dt) ; 
//p->rect.x+=p->vitesse*dt deplacement constant (vitesse=1)
}

/** 
* @brief To movement the perso to the left . 
* @param p the perso
* @return Nothing 
*/ 


void mouvementleft (perso *p)
{
  
if (p->speedX=MAX_SPEED)
	p->speedX=MAX_SPEED;
if (p->rect.x<350)
{

p->rect.x-=p->speedX;
p->rect_relative.x-=p->speedX;
}
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
if (p->rect.x<350)
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
}
void initialiser_input2 (Input *I2)
{
I2->left=0;
I2->right=0;
I2->down=0;
I2->jump=0;
I2->acction=0;
}



