#include "background.h"
#include "background2.h"
#include"amelior.h"
#include "perso.h"
#include"ennemi.h"
#include"chrono.h" 
#include"fonctions.h"
#include "enigme.h"
#include "enig.h"
#include"IA2.h"
#include"sauvegarde.h"
#include"minijeu.h"
#include"enigme_statique.h"
#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#define GRAVITY 9.8
#define MAX_JUMP_SPEED 20
#define MAX_SPEED 17

int ground=510; //480

int main()
{
sauvegarde sa;
enigme_sta ens;
SDL_Surface *back2=NULL,*mask1=NULL,*mask2=NULL;
SDL_Surface *win=NULL;
SDL_Surface *loss=NULL;
win=IMG_Load("image_enigme/passed.png");
loss=IMG_Load("image_enigme/fail.png");
background2 b2;
SDL_Surface *back,*mask;
SDL_Surface *passed;
SDL_Surface *failed;
Mix_Chunk *bip;

SDL_Rect position_passed;
SDL_Rect position_failed;
SDL_Rect positionbackground;


char solution,sauvegarde[]="sauvegarde.txt";
char pause;
int r=-1,res,j;
int k,x;
int a=0;
int d=0;

enig en;
amelior al;
Background B;
bouton bt;
SDL_Rect position_loading;
position_loading.x=650;
position_loading.y=760;
int niveau=0,actif=0,clic=0,actif_op=0,clic_op=0,clic_volume=7,tp2=0,ta2=0,i=19,col_coin=0,alea=1;
SDL_Init(SDL_INIT_VIDEO);
SDL_Surface *screen=NULL,*screen1=NULL,*ecran=NULL;
//ecran = SDL_SetVideoMode(1582, 834, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
char temps[20] = "",score[20] = ""; /* Tableau de char suffisamment grand */
SDL_Color couleurNoire = {0, 0, 0}, couleurBlanche = {255, 255, 255};
int tempsActuel = 0, tempsPrecedent = 0, compteur = 0, seconde = 0,vrai_compteur=0,collision=0,in=0;
int redimensionnement=5,continuer=1;
SDL_Rect camera;
minimap m;
text t;
tic ti;
int tempss=0,clic_level=0,col=2;
background b;
Input I,I2;
perso p,p2;
Ennemi e,c,e2,e3;
SDL_Event event;
enigme eg;
int reponse=-1;
Uint32 dt=1,t_prev ; 
SDL_Rect posEnnemi;
Ennemi po;
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
ecran=SDL_SetVideoMode (1582,834,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE | SDL_FULLSCREEN);
screen1=SDL_SetVideoMode (1582,834,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE | SDL_FULLSCREEN);
screen=SDL_SetVideoMode (1582,834,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE | SDL_FULLSCREEN);

//screen1=SDL_SetVideoMode (10000,834,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
SDL_WM_SetCaption("The last shade\t1",NULL);//titre de la fenetre
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{
printf("%s",Mix_GetError());
}
e.direction=1; 
e3.direction=0; 
Mix_Music *music,*music_g;
music=Mix_LoadMUS("music/space.mp3");
music_g=Mix_LoadMUS("music/game.mp3");
Mix_PlayMusic(music,-1);
Mix_VolumeMusic(MIX_MAX_VOLUME/2);
// Ajouter background
    
  back=IMG_Load("back.jpg");
    if(back==NULL)
    {
        printf("Unable to load background: %s\n",SDL_GetError());
        return 1;
    }
    positionbackground.x=0;
    positionbackground.y=0;


// image passed

    passed=IMG_Load("passed.png");
    if(passed==NULL)
    {
        printf("Unable to load passed : %s\n",SDL_GetError());
        return 1;
    }
    
   position_passed.x=0;
   position_passed.y=0;


// image failed

    failed=IMG_Load("failed.png");
    if(failed==NULL)
    {
        printf("Unable to load failed : %s\n",SDL_GetError());
        return 1;
    }
    
   position_failed.x=0;
   position_failed.y=0;
Ennemi s;
minijeu mini;
///////////////////////////********initialisation*******
initialiser_background1(&B);
initialiser_background2(&B);
initialiser_bouton(&bt);
mask=SDL_LoadBMP("tache_background/mask3.bmp");
mask1=SDL_LoadBMP("tache_background/mask2.bmp");
mask2=SDL_LoadBMP("tache_background/mask1.bmp");
init_ttf(&t,temps);
initialiser_minimap(&m);
initialiser_perso (&p);
initialiser_perso2(&p2);
initialiser_input (&I);
initialiser_input2(&I2);
initialiser_backround (&b);
InitEnnemi(&e);
InitEnnemi2(&e2);
init_Ennemi3(&e3);
initialiser_coin(&c);
initialiser_porte(&po);
initialiser_amelior(&al);
init_IA2(&ti);
init_enigme(&en,"fichier.txt");
solution=return_solution("fichier.txt",&en);
initialiser_star(&s);
initialiser_background3(&b2);
init_score(&e,score);
initialiser_sauvgarde(&sa);
init_minijeu(&mini);
init_enigme_statique(&ens);
eg=generer();
///////////////////////////*****initialisation******
i=19;
while (i!=30)
{
SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
SDL_BlitSurface(B.loading,NULL,screen,NULL);
ta2=SDL_GetTicks();
	if(ta2-tp2>=250)
	{
	i++;
	SDL_BlitSurface(bt.image_bouton[i],NULL,screen,&position_loading);
	SDL_Flip(screen);
	tp2=ta2;
	}
}
SDL_EnableKeyRepeat(1,0);
while(continuer)
{SDL_Flip(screen);
	if(niveau==0)
	{
	e.position_score.x=10;
	e.position_score.y=10
;
	e.position_texte.x = 110;
	e.position_texte.y = 40;
	afficher_background1(B,screen);
	afficher_score(e,screen);
	gestion_score(&e,score);
	animer_back(&B);
	if(B.direction==0)
	afficher_left(B,screen);
	else
	afficher_right(B,screen);
	afficher_boutons_back(bt,B,actif,clic,screen);
	deplacement_spaceship(&B);
	while(SDL_PollEvent(&event))
	{
	switch(event.type)
	{
	case SDL_QUIT:
	continuer=0;
	break;
	case SDL_MOUSEMOTION:
	motion_back1(event,bt,&actif);
	break;
	case SDL_MOUSEBUTTONDOWN:
	if(event.button.button == SDL_BUTTON_LEFT)
	{
	if((event.button.x>=bt.position_bouton[0].x)&&(event.button.x<=(bt.position_bouton[0].x+bt.position_bouton[0].w))&&(event.button.y>=bt.position_bouton[0].y)&&(event.button.y<=(bt.position_bouton[0].y+bt.position_bouton[0].h)))
{
clic=1;
niveau=9;
}

if((event.button.x>=bt.position_bouton[2].x)&&(event.button.x<=(bt.position_bouton[2].x+bt.position_bouton[2].w))&&(event.button.y>=bt.position_bouton[2].y)&&(event.button.y<=(bt.position_bouton[2].y+bt.position_bouton[2].h)))
{
clic=2;
niveau=8;
}
if((event.button.x>=bt.position_bouton[4].x)&&(event.button.x<=(bt.position_bouton[4].x+bt.position_bouton[4].w))&&(event.button.y>=bt.position_bouton[4].y)&&(event.button.y<=(bt.position_bouton[4].y+bt.position_bouton[4].h)))
{
clic=3;
niveau=1;
}
if((event.button.x>=bt.position_bouton[6].x)&&(event.button.x<=(bt.position_bouton[6].x+bt.position_bouton[6].w))&&(event.button.y>=bt.position_bouton[6].y)&&(event.button.y<=(bt.position_bouton[6].y+bt.position_bouton[6].h)))
{
clic=4;
continuer=0;
}
if((event.button.x>=bt.position_bouton[8].x)&&(event.button.x<=(bt.position_bouton[8].x+bt.position_bouton[8].w))&&(event.button.y>=bt.position_bouton[8].y)&&(event.button.y<=(bt.position_bouton[8].y+bt.position_bouton[8].h)))
{
clic=5;
B.tap_son++;
if(B.tap_son % 2 ==0)
Mix_ResumeMusic();
else
Mix_PauseMusic();
}
if((event.button.x>=bt.position_bouton[9].x)&&(event.button.x<=(bt.position_bouton[9].x+bt.position_bouton[9].w))&&(event.button.y>=bt.position_bouton[9].y)&&(event.button.y<=(bt.position_bouton[9].y+bt.position_bouton[9].h)))
{
clic=6;
Mix_PauseMusic();
}
if((event.button.x>=B.pos_lampe.x)&&(event.button.x<=(B.pos_lampe.x+B.pos_lampe.w))&&(event.button.y>=B.pos_lampe.y)&&(event.button.y<=(B.pos_lampe.y+B.pos_lampe.h)))
{
niveau=10;
}

	}
	break;
	case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
		case SDLK_e:
		Mix_PlayChannel(-1,bt.effect,0);
		actif=4;
		continuer=0;
		break;
		case SDLK_o:
		Mix_PlayChannel(-1,bt.effect,0);
		actif=3;
		niveau=1;
		break;
		case SDLK_m:
		Mix_PlayChannel(-1,bt.effect,0);
		niveau=8;
		actif=2;
		break;
		case SDLK_s:
		Mix_PlayChannel(-1,bt.effect,0);
		actif=1;
		niveau=9;
		break;
		case SDLK_g:
		Mix_PlayChannel(-1,bt.effect,0);
		niveau=10;
		break;
		}
	}
	}
	}
	
	else if (niveau==1)
	{
	afficher_background2(B,screen);
	afficher_boutons_options(B,bt,actif_op,clic_volume,screen);
	//clic_menu_options(bt,clic_op,&niveau,screen);
	while(SDL_PollEvent(&event))
	{
	switch(event.type)
	{
	case SDL_QUIT:
	continuer=0;
	break;
	case SDL_MOUSEMOTION:
	motion_back2(event,bt,&actif_op);
	
	break;
	case SDL_MOUSEBUTTONDOWN:			if((event.button.x>=bt.position_bouton[10].x)&&(event.button.x<=(bt.position_bouton[10].x+bt.position_bouton[10].w))&&(event.button.y>=bt.position_bouton[10].y)&&(event.button.y<=(bt.position_bouton[10].y+bt.position_bouton[10].h)))
	{
	Mix_PlayChannel(-1,bt.effect,0);
	niveau=0;
	}

  if((event.button.x>=bt.position_bouton[12].x)&&(event.button.x<=(bt.position_bouton[12].x+bt.position_bouton[12].w))&&(event.button.y>=bt.position_bouton[12].y)&&(event.button.y<=(bt.position_bouton[12].y+bt.position_bouton[12].h)))
	{Mix_PlayChannel(-1,bt.effect,0);
	clic_op=2;
	bt.tap_screen++;
	if(bt.tap_screen % 2 ==0)
	screen =SDL_SetVideoMode(1582,834,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN |SDL_HWSURFACE);//Fullscreen
	else
	screen =SDL_SetVideoMode(1582,834,32,SDL_HWSURFACE | SDL_DOUBLEBUF|SDL_HWSURFACE);//Fullscreen
	}
if((event.button.x>=bt.position_bouton[16].x)&&(event.button.x<=(bt.position_bouton[16].x+bt.position_bouton[16].w))&&(event.button.y>=bt.position_bouton[16].y)&&(event.button.y<=(bt.position_bouton[16].y+bt.position_bouton[16].h)))
{
Mix_ResumeMusic();
Mix_PlayChannel(-1,bt.effect,0);
(clic_volume)++;
} if((event.button.x>=bt.position_bouton[17].x)&&(event.button.x<=(bt.position_bouton[17].x+bt.position_bouton[17].w))&&(event.button.y>=bt.position_bouton[17].y)&&(event.button.y<=(bt.position_bouton[17].y+bt.position_bouton[17].h)))
{
Mix_ResumeMusic();
Mix_PlayChannel(-1,bt.effect,0);
clic_volume--;
}
if(clic_volume<1)
clic_volume=1;
else if(clic_volume>11)
clic_volume=12;
	break;
	case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
		case SDLK_h:
		Mix_PlayChannel(-1,bt.effect,0);
		actif_op=1;
		niveau=0;
		break;
		case SDLK_f:
		Mix_PlayChannel(-1,bt.effect,0);
		actif_op=2;
		break;
		}
	}
	}
	}

else if(niveau==2)
{t_prev=SDL_GetTicks();

//affichage de la background
switch(b.niveau)
{
case 0:
//if(collisionbb(p,e)==1)/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//printf("col\n");
//else
//printf("pas\n");
afficher_background(screen,&b);
calculer_distance(p,&e);
	if(B.direction==0)
	afficher_left(B,screen);
	else
	afficher_right(B,screen);
afficher_minimap(m,screen);//affichage de la minimap1
deplacement_spaceship_niveau(&B);
	if(p.rect_relative.x<8500)
	collision=collisionPP(p,mask);
	switch(collision)
	{
	case 0:
	//printf("pas de collision  \n");
	ground=510;
	
	break;	

	case 1:
	//printf("collision noire \n");
	ground=510;
	break;
	
	case 2:
	//printf("collision jaune \n");
	ground=360;
	//e.scor++;
	//p.speedX=0;
	break;

	case 3:
	printf("collision bleue \n");
	//ground=300;
	//p.speedX=0;
	break;
	
	case 4:
	//printf("collision verte \n");
	ground=220;
	break;
	}
if (collisionbb_attack(p,e)==1)
e.bb=1;
	if(e.bb==0)
	{afficher_ennemi(e,screen);
	switch (e.etat_ennemi)
	{
	case 1:
	if (e.direction==0)
	animer_Ennemi_left(&e);
	if (e.direction==1)
	 animer_Ennemi_right(&e);
	deplacement_aleatoire(&e);
	e.pos_fire_left.x=e.position_ennemi.x ;
	break;
	case 2:
	if(e.direction==0)
	{
	afficher_attack_right(e,screen);
	animer_fire_right(&e);
	e.pos_fire_right.x-=15;
	}
	else if(e.direction==1)
	{
	afficher_attack_left(e,screen);
	animer_fire_left(&e);
	e.pos_fire_left.x+=15;
	}
	//attack
	}
	}
	else if(e.bb==1)
	{afficher_ennemi_die(e,screen);
	SDL_Delay(100);
		if ((e.direction)==0)
		animer_die_right(&e);
		else
		animer_die_left(&e);
	e.fire_rightt=NULL;
	e.fire_leftt=NULL;
	e.pos_fire_right.y=1000;
	e.pos_fire_left.y=1000;
	e.diee=NULL;
	e.frame=NULL;
	m.ennemi=NULL;
	m.position_ennemii.y=-1000;
	e.position_ennemi.x=-1000;
	e.position_ennemi.y=-1000;
	e.scor+=1000;
	e.bb=0;
	}
MAJMinimap(p,e,redimensionnement,&m,camera);
if(p.rect_relative.x>4000)
{
if (collisionbb_attack3(p,e3)==1)
e3.bb3=1;
	if(e3.bb3==0)
	{afficher_ennemi3(e3,screen);
	deplacement_aleatoire3(&e3);
		if ((e3.direction)==0)
		animer_ennemi3_left(&e3);
		else
		animer_ennemi3_right(&e3);	
		
	}	
	else if(e3.bb3==1)
	{
	//SDL_Delay(100);
	e3.frame3=NULL;
	e3.position_ennemi3.x=-1000;
	e3.position_ennemi3.y=-1000;
	m.position_ennemii.x=1000;
	e.scor+=1000;
	e3.bb3=0;
	}
}
if(p.rect_relative.x>6500)
{
	if(collision_obstacle(e,p)==1)
	{
	p.speedX=0;
	p.speedY=0;
	p.acceleration=0;
	e.pos_obstacle.x+=30;
	p.rect.x-=80;
	p.rect_relative.x-=80;
	e.pos_obstacle.x=800;
	niveau=14;
	}	
	else
	{	
	p.acceleration+=0.0001;	
	}

afficher_obstacle(e,screen);
animer_obstacle(&e);
e.pos_obstacle.x+=10;
}
if (p.rect_relative.x >=2500)
{afficher_ennemi2( e2, screen);
calculer_distance2(p,&e2);
if(collisionbb_attack2(p,e2)==1)
e2.bb2++;
if(e2.bb2==0)
	{
if(collisionbb_attac_bleu(p,e2)==1)
{
e2.bleu=1;
animation_die_right(&p);
//printf("%d\n",e2.bleu);
e2.pos_fire_right.x-=200;
if(e.vie==3)
e.vie=2;
else if(e.vie==2)
e.vie=1;
else if(e.vie==1)
e.vie=0;
p.rect.x-=100;
p.rect_relative.x-=100;
}
else 
e2.bleu=0;

	switch(e2.etat_ennemi)
	{
	case 1:
	if (e2.direction==0)
	{
	animer_Ennemi_left2(&e2);
	}
	if (e2.direction==1)
	{
	animer_Ennemi_right2(&e2);	
	}	
	deplacement_aleatoire2(&e2);
	e2.pos_fire_left.x=e2.position_ennemi2.x ;
	e2.pos_fire_right.x=e2.position_ennemi2.x ;
	break;
	case 2:
	if(e2.direction==0)
	{
	afficher_attack_right(e2,screen);
	animer_fire_right(&e2);
	e2.pos_fire_right.x-=15;
	}
	else if(e2.direction==1)
	{
	afficher_attack_right(e2,screen);
	animer_fire_right(&e2);
	e2.pos_fire_right.x+=15;
	}
	break;
	}
	}//if
else if(e2.bb2>=10)
{
	e2.frame1=NULL;
	e2.position_ennemi2.x=-10000;
	e2.position_ennemi2.y=-10000;
	m.position_ennemii.x=1000;
	e.scor+=1000;
	e2.bb2=0;
}
}



break;

case 1:
afficher_background_n2(screen,&b);
	if(B.direction==0)
	afficher_left2(B,screen);
	else
	afficher_right2(B,screen);
afficher_minimap3(m,screen);//affichage de la minimap
deplacement_spaceship_niveau2(&B);
if (collisionbb_attack(p,e)==1)
e.bb=1;
	if(e.bb==0)
	{afficher_ennemi(e,screen);
		if ((e.direction)==0)
		animer_Ennemi_left(&e);
		else
		animer_Ennemi_right(&e);
		
	deplacement_aleatoire(&e);
	}
	else if(e.bb==1)
	{m.ennemi=NULL;afficher_ennemi_die(e,screen);
	SDL_Delay(100);
		if ((e.direction)==0)
		animer_die_right(&e);
		else
		animer_die_left(&e);
	 
	e.diee=NULL;
	e.frame=NULL;
	e.position_ennemi.x=-10000;
	e.position_ennemi.y=-10000;
	e.scor+=1000;
	e.bb=0;
	m.ennemi=NULL;
	}

	MAJMinimap2(p,e,redimensionnement,&m,camera);// mise a jour de la position
	if(p.rect_relative.x<8500)
	collision=collisionPP(p,mask1);
	switch(collision)
	{
	case 0:
	//printf("pas de collision  \n");
	ground=510;
	
	break;	

	case 1:
	//printf("collision noire \n");
	ground=510;
	break;
	
	case 2:
	//printf("collision jaune \n");
	ground=300;
	//e.scor++;
	//p.speedX=0;
	break;

	case 3:
	printf("collision bleue \n");
	//ground=300;
	//p.speedX=0;
	break;
	
	case 4:
	//printf("collision verte \n");
	ground=200;
	break;
	}
if(p.rect_relative.x>3500)
{
	if(collision_obstacle(e,p)==1)
	{
	p.speedX=0;
	p.speedY=0;
	p.acceleration=0;
	e.pos_obstacle.x+=30;
	e.pos_obstacle.x=800;
	niveau=6;
	}	
	else
	{	
	p.acceleration+=0.0001;	
	}
afficher_obstacle(e,screen);
animer_obstacle(&e);
e.pos_obstacle.x+=10;
}

break;

case 2:
afficher_background_n3(screen,&b);
afficher_minimap2(m,screen);//affichage de la minimap
if (collisionbb_attack3(p,e3)==1)
e3.bb3=1;
	if(e3.bb3==0)
	{afficher_ennemi3(e3,screen);
	deplacement_aleatoire3(&e3);
		if ((e3.direction)==0)
		animer_ennemi3_left(&e3);
		else
		animer_ennemi3_right(&e3);	
		
	}	
	else if(e3.bb3==1)
	{
	//SDL_Delay(100);
	e3.frame3=NULL;
	e3.position_ennemi3.x=-10000;
	e3.position_ennemi3.y=-10000;
	m.position_ennemii.x=10000;
	e.scor+=1000;
	e3.bb3=0;
	}
	MAJMinimap3(p,e3,redimensionnement,&m,camera);// mise a jour de la position
	if(p.rect_relative.x<8500)
	collision=collisionPP(p,mask2);
	switch(collision)
	{
	case 0:
	//printf("pas de collision  \n");
	ground=510;
	
	break;	

	case 1:
	//printf("collision noire \n");
	ground=510;
	break;
	
	case 2:
	//printf("collision jaune \n");
	ground=310;
	//e.scor++;
	//p.speedX=0;
	break;

	case 3:
	printf("collision bleue \n");
	break;
	
	case 4:
	//printf("collision verte \n");
	ground=200;
	break;
	}
if(p.rect_relative.x>3500)
{
	if(collision_obstacle(e,p)==1)
	{
	p.speedX=0;
	p.speedY=0;
	p.acceleration=0;
	e.pos_obstacle.x+=30;
	e.pos_obstacle.x=800;
	niveau=7;
	}	
	else
	{	
	p.acceleration+=0.0001;	
	}
afficher_obstacle(e,screen);
animer_obstacle(&e);
e.pos_obstacle.x+=10;
}
if (p.rect_relative.x>=2500)
{afficher_ennemi2(e2,screen);
if (collisionbb_attack2(p,e2)==1)
e2.bb2++;
	if(e2.bb2==0)
	{	
switch (e2.etat_ennemi)
	{
	case 1:
	if (e2.direction==0)
	animer_Ennemi_left2(&e2);
	if (e2.direction==1)
	 animer_Ennemi_right2(&e2);
	deplacement_aleatoire2(&e2);
	e2.pos_fire_left.x=e2.position_ennemi.x;
	break;
	case 2:
	if(e2.direction==0)
	{
	animer_Ennemi_left2(&e2);
	afficher_attack_right(e2,screen);
	animer_fire_right(&e2);
	e2.pos_fire_right.x-=10;
	}
	else if(e2.direction==1)
	{
	animer_Ennemi_right2(&e2);	
	afficher_attack_right(e2,screen);
	animer_fire_right(&e2);
	e2.pos_fire_right.x+=10;
	}
	//attack
	}	
		
	}	
	else if(e2.bb2==10)//////////////////die 
	{
	SDL_Delay(100);
	e2.frame1=NULL;
	m.position_ennemii.y=-1000;
	e2.position_ennemi2.x=-1000;
	e2.position_ennemi2.y=-1000;
	e.scor+=1000;
	e2.bb2=0;
	}

}
break;
}
	SDL_BlitSurface(t.texte, NULL, screen, &(t.position_texte));
	afficher_Entite(e,screen);//affichage de l'entité
	afficher_star(s ,screen);	
	if (b.camera.x<s.pos_star[0].x -s.pos_star[0].w)
	{
	afficher_coins(c,screen);
	if(collision_coins(c ,p)==1)
	{
	e.scor++;
	c.cs[0]=NULL;
	Mix_PlayChannel(-1,bt.effect_coin,0);
	}
	}
	if(p.rect_relative.x>=8500)
	{	
	afficher_porte(po,screen);
	po.pos_porte.y-=15;
	p.rect.x=po.pos_porte.x;
	p.rect.y=po.pos_porte.y;
	}
	if(p.rect_relative.x>=8500 && b.niveau==0 && p.rect.y<=0)
	afficher_fin(b,screen);
	//printf("pos_star.x:%d pos_star.y %d \n",e.pos_star[0].x,e.pos_star[0].y);
	// mise a jour de la position
	chronometre(&tempss,&t,temps,&tempsActuel,&tempsPrecedent,&compteur,&vrai_compteur);
	//if (vrai_compteur==7 )
	//niveau=6;//afficher tic tac toe
	//if(vrai_compteur==100)
	//niveau=7;//afficher enigme avec fichier(amine)
	animer_star(&s);
	//animer_coins(&c);
	animer_porte(&po);
	//if(p.rect_relative.x==c.pos_coin[0].x &&p.rect_relative.y==c.pos_coin[0].y)
	//c.cs=NULL;
if(e.scor>=1000 && e.scor<2000)
s.nbr_etoile=1;
else if  (e.scor>=2000 &&e.scor<3000)
s.nbr_etoile=2;
else if  (e.scor>=3000)
s.nbr_etoile=3;
animer_effet(&m);
	//animer_porte(&po);
if((p.rect.y<=0 && b.niveau==2) ||  (p.rect.y<=0 && b.niveau==1))
{
niveau=12;
}

if ( al.choix==1 )
{ 
if(p.rect_relative.x<8500)
{
afficher_perso (&p,screen);//affichage du personnage
afficher_score(e,screen);
gestion_score(&e,score);
}

while(SDL_PollEvent(&event))
	{

		switch(event.type)
		{
		case SDL_QUIT:
		continuer=0;
		break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
			
				case SDLK_LEFT :
				I.left=1;
                        	p.acceleration+=0.0001;
                        	break;

      				case SDLK_RIGHT :
				I.right=1;
                       		p.acceleration+=0.0001;
	    			break;

			
				case SDLK_UP :
				I.jump=1;
				if(p.rect.y==ground)//collision with ground
				p.speedY = -60;//collision with stairs -1 au lieu de -30
				p.speedX=MAX_JUMP_SPEED;
				break; 

				case SDLK_SPACE :
				I.attack=1; 
				break;
				}	
			break;
			case SDL_MOUSEBUTTONDOWN:
			if((event.button.x>=B.pos_pause.x)&&(event.button.x<=(B.pos_pause.x+B.pos_pause.w))&&(event.button.y>=B.pos_pause.y)&&(event.button.y<=(B.pos_pause.y+B.pos_pause.h)))
{
	niveau=9;
	sa.niveau=0;
}
			break;

		        case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_RIGHT:
				I.right=0;
				p.speedX=0;
				p.acceleration=0;
			break;
			case SDLK_LEFT :
				I.left=0;
				p.speedX=0;
				p.acceleration=0.1;
      		        break;
			case SDLK_UP :
			I.jump=0; 
			p.speedX=0;
			p.acceleration=0.1;
			break;
			case SDLK_SPACE :
			I.attack=0; 
			break;

			}
		break;
		}
	}

p.acceleration+=0.001;
 if (I.right==1)
{
	p.speedX+=p.acceleration;
	animation_right(&p);
	if (I.jump==0) mouvementright (&p,dt);
	 else if (I.jump==1) jumpright (&p);
scrolling_right (&b,&p,screen);
}
else if (I.left==1 )
{
	p.speedX+=p.acceleration;
	animation_left(&p);
	if (I.jump==0)  mouvementleft (&p,dt);
	else if (I.jump==1) jumpleft (&p);
		scrolling_left (&b,&p,screen);

}
else if(I.attack==1)
{
afficher_attack(p,screen);
animer_attack(&p);
p.pos_attack.x+=40;
}

else if (I.attack==0)
{
p.pos_attack.x=p.rect.x;
p.pos_attack.y=p.rect.y;
//p.pos_attack.x=40;
p.at=NULL;
}
p.speedY+=GRAVITY;
 p.rect.y += p.speedY;
 p.rect_relative.y += p.speedY;
 if(p.rect.y >= ground)
 	 {
 		 p.rect.y= ground;
		 p.rect_relative.y= ground;
 		 p.speedY = 0;
}
afficher_pause(B,screen);

}
else if  (al.choix==2 )
{

        afficher_perso2 (&p2,screen);
while(SDL_PollEvent(&event))
	{

		switch(event.type)
		{
		case SDL_QUIT:
		// (*action)=0;
			continuer=0;
		break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{

			case SDLK_q :
                                I2.left=1;
                                p2.acceleration-=0.01;
			break ;

		case SDLK_d :
		I2.right=1;
                p2.acceleration+=0.005;
		break;
                        
			case SDLK_z : 
                                I2.jump=1;
				if(p2.rect.y==ground)//collision with ground
                                p2.speedY = -60;
			 //collision with stairs -1 au lieu de -30
		                p2.speedX=MAX_JUMP_SPEED;
			break; 


			}
		        break;
		        case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
                        case SDLK_d:
		        I2.right=0;
			break;

                        case SDLK_q :
			I2.left=0;
      		        break;

                        case SDLK_z :
			I2.jump=0; 
			break;
                        
			}
		break;
		}
	}
p2.acceleration-=0.001;



// 2eme perso 
if (I2.right==1)
{
	p2.speedX+=1;
	animation_right(&p2);
	if (I2.jump==0) mouvementright (&p2,dt);
	 else if (I2.jump==1) jumpright (&p2);
scrolling_right (&b,&p2,screen);
}
else if (I2.left==1 )
{
	p2.speedX+=p2.vitesse;
	animation_left(&p2);
	if (I2.jump==0)  mouvementleft (&p2,dt);
	else if (I2.jump==1) jumpleft (&p2);
	scrolling_left (&b,&p2,screen);

}

p2.speedY+=GRAVITY;
 p2.rect.y += p2.speedY;
 p2.rect_relative.y += p2.speedY;
 if(p2.rect.y >= ground)
 	 {
 		 p2.rect.y= ground;
		 p2.rect_relative.y= ground;
 		 p2.speedY = 0;
	 }
}				

dt=SDL_GetTicks()-t_prev;
}
camera.x=b.camera.x;//chargement de la position du camera pour x et y
camera.y=b.camera.y;

if(niveau==3)
{
music=NULL;
Mix_PlayMusic(music_g,-1);
B.pos_spaceship.y=200;

	afficher_levels(B,screen,s);
	afficher_retour(B,screen);
	while(SDL_PollEvent(&event))
	{
	switch(event.type)
	{
	case SDL_QUIT:
	continuer=0;
	break;
	case SDL_MOUSEMOTION:
		if((event.motion.x>=B.position_niveau[0].x) && (event.motion.x<=(B.position_niveau[0].x+B.position_niveau[0].w))&&(event.motion.y>=B.position_niveau[0].y)&&(event.motion.y<=(B.position_niveau[0].y+B.position_niveau[0].h)))
{
B.motion=1;
}
else if((event.motion.x>=B.position_niveau[1].x) && (event.motion.x<=(B.position_niveau[1].x+B.position_niveau[1].w))&&(event.motion.y>=B.position_niveau[1].y)&&(event.motion.y<=(B.position_niveau[1].y+B.position_niveau[1].h)))
{
B.motion=2;
}
else if((event.motion.x>=B.position_niveau[2].x) && (event.motion.x<=(B.position_niveau[2].x+B.position_niveau[2].w))&&(event.motion.y>=B.position_niveau[2].y)&&(event.motion.y<=(B.position_niveau[2].y+B.position_niveau[2].h)))
{
B.motion=3;
}
else B.motion=0;

	break;
	case SDL_MOUSEBUTTONDOWN:
	if((event.button.x>=B.position_niveau[0].x) && (event.button.x<=(B.position_niveau[0].x+B.position_niveau[0].w))&&(event.button.y>=B.position_niveau[0].y)&&(event.button.y<=(B.position_niveau[0].y+B.position_niveau[0].h)))
{
if(B.premiere_fois[0]==0)
{
tempsActuel=0;tempsPrecedent=0;compteur=0;vrai_compteur=0;
init_ttf(&t,temps);
initialiser_minimap(&m);
initialiser_perso (&p);
initialiser_perso2(&p2);
initialiser_input (&I);
initialiser_input2(&I2);
initialiser_backround (&b);
InitEnnemi(&e);
InitEnnemi2(&e2);
init_Ennemi3(&e3);
initialiser_coin(&c);
initialiser_porte(&po);
initialiser_star(&s);
}
B.premiere_fois[0]++;
niveau=11;
b.niveau=2;
b.tap=0;
Mix_PlayChannel(-1,bt.effect,0);

}
else if((event.button.x>=B.position_niveau[1].x) && (event.button.x<=(B.position_niveau[1].x+B.position_niveau[1].w))&&(event.button.y>=B.position_niveau[1].y)&&(event.button.y<=(B.position_niveau[1].y+B.position_niveau[1].h)))
{
if(B.premiere_fois[1]==0)
{
tempsActuel=0;tempsPrecedent=0;compteur=0;vrai_compteur=0;
init_ttf(&t,temps);
initialiser_minimap(&m);
initialiser_perso (&p);
initialiser_perso2(&p2);
initialiser_input (&I);
initialiser_input2(&I2);
initialiser_backround (&b);
InitEnnemi(&e);
InitEnnemi2(&e2);
init_Ennemi3(&e3);
initialiser_coin(&c);
initialiser_porte(&po);
initialiser_star(&s);
}
B.premiere_fois[1]++;
niveau=11;
b.niveau=1;
b.tap=4;
Mix_PlayChannel(-1,bt.effect,0);
}
else if((event.button.x>=B.position_niveau[2].x) && (event.button.x<=(B.position_niveau[2].x+B.position_niveau[2].w))&&(event.button.y>=B.position_niveau[2].y)&&(event.button.y<=(B.position_niveau[2].y+B.position_niveau[2].h)))
{
if(B.premiere_fois[2]==0)
{
tempsActuel=0;tempsPrecedent=0;compteur=0;vrai_compteur=0;
init_ttf(&t,temps);
initialiser_minimap(&m);
initialiser_perso (&p);
initialiser_perso2(&p2);
initialiser_input (&I);
initialiser_input2(&I2);
initialiser_backround (&b);
InitEnnemi(&e);
InitEnnemi2(&e2);
init_Ennemi3(&e3);
initialiser_coin(&c);
initialiser_porte(&po);
initialiser_star(&s);
}
B.premiere_fois[2]++;
niveau=11;
b.niveau=0;
b.tap=7;
Mix_PlayChannel(-1,bt.effect,0);
}
else if((event.button.x>=B.pos_retour.x)&&(event.button.x<=(B.pos_retour.x+B.pos_retour.w))&&(event.button.y>=B.pos_retour.y)&&(event.button.y<=(B.pos_retour.y+B.pos_retour.h)))
{
	niveau=5;
	al.niveau=1;
}
	break;
	}

	}
}
if(niveau==4)
{
afficherEnigme(&eg,screen1);
    while(SDL_PollEvent(&event))
	{

		switch(event.type)
		{
		case SDL_QUIT:

			continuer=0;
		break;
        case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			
			case SDLK_a :
				if (eg.solution==1)
                {
                     reponse=1;
                    printf("vrai");
						e.scor+=200;
                    ////////////////
                }
                else {
                    reponse=0;
			e.scor-=200;
                    printf("faux");
                }
                
      		break;
            case SDLK_z :
                if (eg.solution==2)
                {
                    printf("vrai");
			e.scor+=200;
                    reponse=1;
                }
                else {
                    printf("faux");
			e.scor-=200;
                    reponse=0;
                }
            break;
            case SDLK_e:
                if (eg.solution==3)
                {
                    printf("vrai");
		    e.scor+=200;
                    reponse=1;
                }
                else {
                   reponse=0;
			e.scor-=200;
                    printf("faux");
                }
            break;
            }
        break;
        case SDL_MOUSEBUTTONDOWN:
            if (event.motion.x >= 250 && event.motion.x <= 520 && event.motion.y >= 570 && event.motion.y <= 650)
            {
                if (eg.solution==1)
                {
                    printf("vrai");
                    reponse=1;
                }
                else {
                    reponse=0;
                }
            }
            if (event.motion.x >= 650 && event.motion.x <= 920 && event.motion.y >= 570 && event.motion.y <= 650)
            {
                if (eg.solution==2)
                {
			
                    reponse=1;
                }
                else {
                    reponse=0;
                }
            }
            if (event.motion.x >= 950 && event.motion.x <= 1220 && event.motion.y >= 570 && event.motion.y <= 650)
            {
                if (eg.solution==3)
                {
                    reponse=1;
                }
                else {
                    printf("faux");
                    reponse=0;
                }
            }
            break;
        }
    }


if (reponse!=-1)
{
if (reponse==1)
{
Mix_PlayChannel(-1,bt.win,0);
e.scor+=200;
niveau=2;
}
else  
{ 
Mix_PlayChannel(-1,bt.fail,0);
e.scor-=-200;
niveau=2;
animation_die_right(&p);
}
}


}
/////////////// choix du joueur
if(niveau==9)
{
if(sa.niveau==0)
{
afficher_sauvgarde(sa,screen);
	while(SDL_PollEvent(&event))
	{
	switch(event.type)
	{
	case SDL_QUIT:
	continuer=0;
	break;
	case SDL_MOUSEMOTION:
if ((event.motion.x>=sa.posbouton[0].x) && (event.motion.x<=(sa.posbouton[0].x + sa.posbouton[0].w))&&(event.motion.y>=sa.posbouton[0].y)&&(event.motion.y<=(sa.posbouton[0].y+sa.posbouton[0].h)))
sa.motion=1;
else if ((event.motion.x>=sa.posbouton[1].x) && (event.motion.x<=(sa.posbouton[1].x + sa.posbouton[1].w))&&(event.motion.y>=sa.posbouton[1].y)&&(event.motion.y<=(sa.posbouton[1].y+sa.posbouton[1].h)))
sa.motion=2;
else if ((event.motion.x>=sa.posbouton[2].x) && (event.motion.x<=(sa.posbouton[2].x + sa.posbouton[2].w))&&(event.motion.y>=sa.posbouton[2].y)&&(event.motion.y<=(sa.posbouton[2].y+sa.posbouton[2].h)))
sa.motion=3;
else sa.motion=0;
	break;

	case SDL_MOUSEBUTTONDOWN:
if ((event.button.x>=sa.posbouton[0].x) && (event.button.x<=(sa.posbouton[0].x + sa.posbouton[0].w))&&(event.button.y>=sa.posbouton[0].y)&&(event.button.y<=(sa.posbouton[0].y+sa.posbouton[0].h)))
{
//chunk
//niveau
	niveau=0;
	//sa.niveau=0;
printf("1\n");
}
else if ((event.button.x>=sa.posbouton[1].x) && (event.button.x<=(sa.posbouton[1].x + sa.posbouton[1].w))&&(event.button.y>=sa.posbouton[1].y)&&(event.button.y<=(sa.posbouton[1].y+sa.posbouton[1].h)))
{
	niveau=3;
	sauv (p,b,e,m,sauvegarde,vrai_compteur,e2,e3);
printf("2\n");
//niveau
}
else if ((event.button.x>=sa.posbouton[2].x) && (event.button.x<=(sa.posbouton[1].x + sa.posbouton[2].w))&&(event.button.y>=sa.posbouton[2].y)&&(event.button.y<=(sa.posbouton[2].y+sa.posbouton[2].h)))
{
	niveau=1;
printf("3\n");
//niveau
}
	break;
	}
	}
}
else if (sa.niveau==1)
{
afficher_resume(sa,screen);
	while(SDL_PollEvent(&event))
	{
	switch(event.type)
	{
	case SDL_QUIT:
	continuer=0;
	break;
case SDL_MOUSEBUTTONDOWN:
if ((event.button.x>=sa.posboutonr[0].x) && (event.button.x<=(sa.posboutonr[0].x + sa.posboutonr[0].w))&&(event.button.y>=sa.posboutonr[0].y)&&(event.button.y<=(sa.posboutonr[0].y+sa.posboutonr[0].h)))
{
//chunk
//niveau
printf("1\n");
load (&p,&b,&e,&m,sauvegarde,&vrai_compteur,&e2,&e3);
niveau=2;
}
else if ((event.button.x>=sa.posboutonr[1].x) && (event.button.x<=(sa.posboutonr[1].x + sa.posboutonr[1].w))&&(event.button.y>=sa.posboutonr[1].y)&&(event.button.y<=(sa.posboutonr[1].y+sa.posboutonr[1].h)))
{
printf("2\n");
niveau=5;
//niveau
}

	break;
	}
	}
}
}
if(niveau==5)
{
if(al.niveau==0)
{afficher_amelior(al,screen);
	afficher_retour(B,screen);

	while(SDL_PollEvent(&event))
	{
	switch(event.type)
	{
	case SDL_QUIT:
	continuer=0;
	break;
	case SDL_MOUSEMOTION:
if ((event.motion.x>=al.posbouton[0].x) && (event.motion.x<=(al.posbouton[0].x + al.posbouton[0].w))&&(event.motion.y>=al.posbouton[0].y)&&(event.motion.y<=(al.posbouton[0].y+al.posbouton[0].h)))
al.motion=1;
else if ((event.motion.x>=al.posbouton[1].x) && (event.motion.x<=(al.posbouton[1].x + al.posbouton[1].w))&&(event.motion.y>=al.posbouton[1].y)&&(event.motion.y<=(al.posbouton[1].y+al.posbouton[1].h)))
al.motion=2;
else al.motion=0;
	break;

	case SDL_MOUSEBUTTONDOWN:
if ((event.button.x>=al.posbouton[0].x) && (event.button.x<=(al.posbouton[0].x + al.posbouton[0].w))&&(event.button.y>=al.posbouton[0].y)&&(event.button.y<=(al.posbouton[0].y+al.posbouton[0].h)))
{
al.choix=1;
al.niveau=1;
}
else if ((event.button.x>=al.posbouton[1].x) && (event.button.x<=(al.posbouton[1].x + al.posbouton[1].w))&&(event.button.y>=al.posbouton[1].y)&&(event.button.y<=(al.posbouton[1].y+al.posbouton[1].h)))
{
al.choix=2;
al.niveau=1;
}
else if((event.button.x>=B.pos_retour.x)&&(event.button.x<=(B.pos_retour.x+B.pos_retour.w))&&(event.button.y>=B.pos_retour.y)&&(event.button.y<=(B.pos_retour.y+B.pos_retour.h)))
{
	niveau=0;
	if(niveau<=0)
	niveau=0;
}
	break;
	}
	}
}
else if(al.niveau==1)
{
SDL_BlitSurface(al.background2,NULL,screen,NULL);
afficher_amelior2(al,screen);
afficher_retour(B,screen);
	while(SDL_PollEvent(&event))
	{
	switch(event.type)
	{
	case SDL_QUIT:
	continuer=0;
	break;
	case SDL_MOUSEMOTION:
if ((event.motion.x>=al.posbouton[2].x) && (event.motion.x<=(al.posbouton[2].x + al.posbouton[2].w))&&(event.motion.y>=al.posbouton[2].y)&&(event.motion.y<=(al.posbouton[2].y+al.posbouton[2].h)))
al.motion=3;
else al.motion=0;
if ((event.motion.x>=al.posbouton[3].x) && (event.motion.x<=(al.posbouton[3].x + al.posbouton[3].w))&&(event.motion.y>=al.posbouton[3].y)&&(event.motion.y<=(al.posbouton[3].y+al.posbouton[3].h)))
al.motion=4;
	break;

	case SDL_MOUSEBUTTONDOWN:
if ((event.button.x>=al.posbouton[2].x) && (event.button.x<=(al.posbouton[2].x + al.posbouton[2].w))&&(event.button.y>=al.posbouton[2].y)&&(event.button.y<=(al.posbouton[2].y+al.posbouton[2].h)))
niveau=3;
else if ((event.button.x>=al.posbouton[3].x) && (event.button.x<=(al.posbouton[3].x + al.posbouton[3].w))&&(event.button.y>=al.posbouton[3].y)&&(event.button.y<=(al.posbouton[3].y+al.posbouton[3].h)))
niveau=3;
else if((event.button.x>=B.pos_retour.x)&&(event.button.x<=(B.pos_retour.x+B.pos_retour.w))&&(event.button.y>=B.pos_retour.y)&&(event.button.y<=(B.pos_retour.y+B.pos_retour.h)))
{
	al.niveau=0;
	if(niveau<=0)
	niveau=0;
}
	break;
	}
	}
}
/////////////// choix du joueur
}
if(niveau==6)
{SDL_Flip(ecran);
afficher_tic(ti,ecran);
afficher_joueur(ti,ecran);
afficher_machine(ecran,ti);
nbr_cases_remplis(&ti);
evaluer(&ti);
//if(ti.nbr>=9)
//niveau=2;
if (gameover(ti,ecran)==3)
{
niveau=2;
p.rect.x-=30;
p.rect_relative.x-=30;
}
while(SDL_PollEvent(&event))
	{
        	switch(event.type)
        	{
        	    case SDL_QUIT:
        	        continuer = 0;
        	        break;
		
	if(ti.whoplay==0)
		{
		   case SDL_MOUSEBUTTONDOWN:
if((event.button.x>=ti.pos[0].x)&&(event.button.x<=(ti.pos[0].x+ti.pos[0].w))&&(event.button.y>=ti.pos[0].y)&&(event.button.y<=(ti.pos[0].y+ti.pos[0].h)))
{
ti.matrice_suivi[0]=1;
ti.whoplay=1;
ti.compteur++;
}
if((event.button.x>=ti.pos[1].x)&&(event.button.x<=(ti.pos[1].x+ti.pos[1].w))&&(event.button.y>=ti.pos[1].y)&&(event.button.y<=(ti.pos[1].y+ti.pos[1].h)))
{
ti.matrice_suivi[1]=1;
ti.whoplay=1;
ti.compteur++;
}
if((event.button.x>=ti.pos[2].x)&&(event.button.x<=(ti.pos[2].x+ti.pos[2].w))&&(event.button.y>=ti.pos[2].y)&&(event.button.y<=(ti.pos[2].y+ti.pos[2].h)))
{
ti.matrice_suivi[2]=1;
ti.whoplay=1;
ti.compteur++;
}
if((event.button.x>=ti.pos[3].x)&&(event.button.x<=(ti.pos[3].x+ti.pos[3].w))&&(event.button.y>=ti.pos[3].y)&&(event.button.y<=(ti.pos[3].y+ti.pos[3].h)))
{
ti.matrice_suivi[3]=1;
ti.whoplay=1;
ti.compteur++;
}
if((event.button.x>=ti.pos[4].x)&&(event.button.x<=(ti.pos[4].x+ti.pos[4].w))&&(event.button.y>=ti.pos[4].y)&&(event.button.y<=(ti.pos[4].y+ti.pos[4].h)))
{
ti.matrice_suivi[4]=1;
ti.whoplay=1;
ti.compteur++;
}
if((event.button.x>=ti.pos[5].x)&&(event.button.x<=(ti.pos[5].x+ti.pos[5].w))&&(event.button.y>=ti.pos[5].y)&&(event.button.y<=(ti.pos[5].y+ti.pos[5].h)))
{
ti.matrice_suivi[5]=1;
ti.whoplay=1;
ti.compteur++;
}
if((event.button.x>=ti.pos[6].x)&&(event.button.x<=(ti.pos[6].x+ti.pos[6].w))&&(event.button.y>=ti.pos[6].y)&&(event.button.y<=(ti.pos[6].y+ti.pos[6].h)))
{
ti.matrice_suivi[6]=1;
ti.whoplay=1;
ti.compteur++;
}
if((event.button.x>=ti.pos[7].x)&&(event.button.x<=(ti.pos[7].x+ti.pos[7].w))&&(event.button.y>=ti.pos[7].y)&&(event.button.y<=(ti.pos[7].y+ti.pos[7].h)))
{
ti.matrice_suivi[7]=1;
ti.whoplay=1;
ti.compteur++;
}
if((event.button.x>=ti.pos[8].x)&&(event.button.x<=(ti.pos[8].x+ti.pos[8].w))&&(event.button.y>=ti.pos[8].y)&&(event.button.y<=(ti.pos[8].y+ti.pos[8].h)))
{
ti.matrice_suivi[8]=1;
ti.whoplay=1;
ti.compteur++;
}
		   break;		
		}
	   }
	}
if(ti.whoplay==1)
{attack(&ti);
if(ti.compteur<=1 || ti.compteur>=8 )
{			
                        alea=aleatoire();  
			alea=machine(&ti,alea);
			ti.matrice_suivi[alea]=-1;
			ti.whoplay=0;
}
else 
{

Defense(&ti);
SDL_Delay(500);
ti.whoplay=0;
}
			
			
			


}
}	
if (niveau==7)
{
SDL_BlitSurface(back,NULL,screen1,&positionbackground);

afficher_enigme(screen1,"fichier.txt",&en);
while(SDL_PollEvent(&event))
{switch(event.type)
  {


case SDL_QUIT:
  {niveau=3;
break;}

case SDL_KEYDOWN:
{
  
if(event.key.keysym.sym==SDLK_ESCAPE)
{niveau=3;
break;
}}


          case SDL_MOUSEBUTTONDOWN:
             {
              a=event.button.x;
              d=event.button.y ;

              r=resolution ("fichier.txt",&en,screen,&a,&d,solution);
              
           break;
             }


         case SDL_MOUSEBUTTONUP:
             {
              a=event.button.x;
              d=event.button.y ;

              r=resolution ("fichier.txt",&en,screen,&a,&d,solution);
              
         break;
             }

}

if(r==0)
 
{
 Mix_PlayChannel(1, bt.win,0);
SDL_BlitSurface(passed,&positionbackground,screen,&position_passed);
e.scor+=10;
//SDL_Delay(200);
niveau=2;
}


else if (r==1)

{
Mix_PlayChannel(1, bip,0);
SDL_BlitSurface(passed,&positionbackground,screen,&position_passed);
e.scor-=10;
SDL_Delay(200);
niveau=2;

}


SDL_Flip(screen1);

}
}
if(niveau==8)
{
	
while(SDL_PollEvent(&event))
	{

		switch(event.type)
		{
		case SDL_QUIT:
		// (*action)=0;
			continuer=0;
		break;
		case SDL_MOUSEBUTTONDOWN:
		if((event.button.x>=B.pos_retour.x)&&(event.button.x<=(B.pos_retour.x+B.pos_retour.w))&&(event.button.y>=B.pos_retour.y)&&(event.button.y<=(B.pos_retour.y+B.pos_retour.h)))
		{
			niveau=0;
		}
		break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			/*	case SDLK_ESCAPE:

				pause(screen,&next,nb_stage,action);
				read_volume (&vm,&vsfx);
				Mix_VolumeMusic(vm);
			Mix_PlayMusic(musique, -1);
				break;
			case SDLK_RIGHT:
				I.right=1;

			break; */
			case SDLK_LEFT :
				I.left=1;
				p.acceleration-=0.01;
			break;
      			case SDLK_RIGHT :
				I.right=1;
				p.acceleration+=0.005;
			break;
			case SDLK_UP :
				I.jump=1;
				if(p.rect.y==ground)
				p.speedY = -60;
				p.speedX=MAX_JUMP_SPEED;
			break; 
			/*case SDLK_DOWN :
				I.down=1;
				    p.yvelocity =  1;
			break;*/
			
		        case SDLK_d:
                    		I2.right = 1;
				p2.acceleration-=0.01;
                    //scrolling_right(&b, 10, screen, I);
                    	break;
                	case SDLK_q:
                    		I2.left = 1;
				p2.acceleration+=0.005;
                    //scrolling_left(&b, 10, screen, I);
                    	break;
			case SDLK_z:
				I2.jump = 1;
				if(p2.rect.y==ground)
				p2.speedY = -60;
				p2.speedX=MAX_JUMP_SPEED;
			break;
			}
		break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_RIGHT:
				I.right=0;
			break;
			case SDLK_LEFT :
				I.left=0;
      			break;
			case SDLK_SPACE :
			I.jump=0; 

			break;
			//case SDLK_DOWN :
			//	I.down=0;
			//	if( p.yvelocity > 0 )
			//			p.yvelocity = 0;
		//	break;
			case SDLK_d:
                    		I2.right = 0;
                    //scrolling_right(&b, 10, screen, I);
                    	break;
                	case SDLK_q:
                    		I2.left = 0;
                    //scrolling_left(&b, 10, screen, I);
                    	break;
			case SDLK_z:
				I2.jump=0;
			break;
                	}
		break;
		}
	}

p.acceleration-=0.001;

if (I.right==1)
{
	p.speedX+=1;
	animation_right(&p);
	if (I.jump==0) mouvementright (&p,dt);
	 else if (I.jump==1) jumpright (&p);
scrolling_right2 (&b2,&p,screen,I,I2);
}
else if (I.left==1 )
{
	p.speedX+=1;
	animation_left(&p);
	if (I.jump==0)  mouvementleft (&p,dt);
	else if (I.jump==1) jumpleft (&p);
scrolling_left2 (&b2,&p,screen,I,I2);
}
p2.acceleration-=0.001;
if (I2.right==1)
{
	p2.speedX+=1;
	animation_right(&p2);
	if (I2.jump==0) mouvementright (&p2,dt);
	 else if (I2.jump==1) jumpright (&p2);
scrolling_right2 (&b2,&p2,screen,I,I2);
}
else if (I2.left==1 )
{
	p2.speedX+=1;
	animation_left(&p2);
	if (I2.jump==0)  mouvementleft (&p2,dt);
	else if (I2.jump==1) jumpleft (&p2);
scrolling_left2 (&b2,&p2,screen,I,I2);
}
/*else if (I.left==0 && I.down==0 && I.jump==0 && I.right==0 )
{
	animation_stable(&p);
}*/
p.speedY+=GRAVITY;
 p.rect.y += p.speedY;
 p.rect_relative.y += p.speedY;
 if(p.rect.y >= ground)
 	 {
 		 p.rect.y= ground;
		 p.rect_relative.y= ground;
 		 p.speedY = 0;
	}
p2.speedY+=GRAVITY;
 p2.rect.y += p2.speedY;
 p2.rect_relative.y += p2.speedY;
 if(p2.rect.y >= ground)
	{
		p2.rect.y=ground;
		p2.rect_relative.y=ground;
		p2.speedY=0;
	}
    //SDL_BlitSurface(back,NULL,screen,NULL);
camera.x=b.camera.x;
camera.y=b.camera.y;

	//SDL_BlitSurface(masque,&b.camera,screen,NULL);
	afficher_background3(screen,&b2);
	afficher_retour(B,screen);
	afficher_perso (&p,screen);
	afficher_perso2 (&p2,screen);
	//afficher(m,screen);//affichage de la minimap
	//MAJMinimap(p/*,posEnnemi*/,redimensionnement,&m,camera);// mise a jour de la position
	chronometre(&tempss,&t,temps,&tempsActuel,&tempsPrecedent,&compteur,&vrai_compteur);
	//SDL_BlitSurface(t.texte, NULL, screen, &(t.position_texte));
	
	//collision=collisionPP(p,masque);
	SDL_Flip(screen);
	SDL_Delay(16);
}
if (niveau==10)
{
afficher_minijeu(mini,screen);
afficher_retour(B,screen);
if(mini.compteur==8)
{
Mix_PlayChannel(-1,mini.win,0);
e.scor+=500;
mini.compteur=0;
}
while(SDL_PollEvent(&event))
	{
	switch(event.type)
	{
	case SDL_QUIT:
	continuer=0;
	break;

	case SDL_MOUSEBUTTONDOWN:
if((event.button.x>=B.pos_retour.x)&&(event.button.x<=(B.pos_retour.x+B.pos_retour.w))&&(event.button.y>=B.pos_retour.y)&&(event.button.y<=(B.pos_retour.y+B.pos_retour.h)))
{
	if(b.niveau==-1)
	niveau=0;
	else
	niveau=2;
}
if ((event.button.x>=mini.tab_pos[0].x) && (event.button.x<=(mini.tab_pos[0].x + mini.tab_pos[0].w))&&(event.button.y>=mini.tab_pos[0].y)&&(event.button.y<=(mini.tab_pos[0].y+mini.tab_pos[0].h)))
{
//chunk
//niveau
mini.clic=0;
mini.matrice[0][0]=1;
printf("1\n");
Mix_PlayChannel(-1,mini.effect,0);
mini.compteur++;
}
else if((event.button.x>=mini.tab_pos[1].x) && (event.button.x<=(mini.tab_pos[1].x + mini.tab_pos[1].w))&&(event.button.y>=mini.tab_pos[1].y)&&(event.button.y<=(mini.tab_pos[1].y+mini.tab_pos[1].h)))
{
mini.clic=1;
mini.matrice[0][1]=1;
printf("2\n");
Mix_PlayChannel(-1,mini.effect,0);
mini.compteur++;
}
else if ((event.button.x>=mini.tab_pos[2].x) && (event.button.x<=(mini.tab_pos[2].x + mini.tab_pos[2].w))&&(event.button.y>=mini.tab_pos[2].y)&&(event.button.y<=(mini.tab_pos[2].y+mini.tab_pos[2].h)))
{
mini.clic=2;
mini.matrice[0][2]=1;
printf("3\n");
Mix_PlayChannel(-1,mini.effect,0);
mini.compteur++;
//niveau
}
else if ((event.button.x>=mini.tab_pos[3].x) && (event.button.x<=(mini.tab_pos[3].x + mini.tab_pos[3].w))&&(event.button.y>=mini.tab_pos[3].y)&&(event.button.y<=(mini.tab_pos[3].y+mini.tab_pos[3].h)))
{
mini.clic=3;
mini.matrice[0][3]=1;
printf("4\n");
Mix_PlayChannel(-1,mini.effect,0);
mini.compteur++;
//niveau
}
else if ((event.button.x>=mini.tab_pos[4].x) && (event.button.x<=(mini.tab_pos[4].x + mini.tab_pos[4].w))&&(event.button.y>=mini.tab_pos[4].y)&&(event.button.y<=(mini.tab_pos[4].y+mini.tab_pos[4].h)))
{
mini.clic=4;
mini.matrice[1][0]=1;
printf("5\n");
Mix_PlayChannel(-1,mini.effect,0);
mini.compteur++;
//niveau
}
else if ((event.button.x>=mini.tab_pos[5].x) && (event.button.x<=(mini.tab_pos[5].x + mini.tab_pos[5].w))&&(event.button.y>=mini.tab_pos[5].y)&&(event.button.y<=(mini.tab_pos[5].y+mini.tab_pos[5].h)))
{
mini.clic=5;
mini.matrice[1][1]=1;
printf("6\n");
Mix_PlayChannel(-1,mini.effect,0);
mini.compteur++;
//niveau
}
else if ((event.button.x>=mini.tab_pos[6].x) && (event.button.x<=(mini.tab_pos[6].x + mini.tab_pos[6].w))&&(event.button.y>=mini.tab_pos[6].y)&&(event.button.y<=(mini.tab_pos[6].y+mini.tab_pos[6].h)))
{
mini.clic=6;
mini.matrice[1][2]=1;
printf("7\n");
Mix_PlayChannel(-1,mini.effect,0);
mini.compteur++;
//niveau
}
else if ((event.button.x>=mini.tab_pos[7].x) && (event.button.x<=(mini.tab_pos[7].x + mini.tab_pos[7].w))&&(event.button.y>=mini.tab_pos[7].y)&&(event.button.y<=(mini.tab_pos[7].y+mini.tab_pos[7].h)))
{
mini.clic=7;
mini.matrice[1][3]=1;
printf("8\n");
Mix_PlayChannel(-1,mini.effect,0);
mini.compteur++;
//niveau
}
else 
{
mini.clic=-1;
for(i=0;i<2;i++)
{
for(j=0;j<4;j++)
{
mini.matrice[i][j]=-1;
}
}
mini.compteur=0;
}
	break;
	}
	}
}
if(niveau==11)
{
e.position_score.x=1300;
e.position_score.y=35;
e.position_texte.x = 1400;
e.position_texte.y = 60;
afficher_story(b,screen);
while(SDL_PollEvent(&event))
	{

		switch(event.type)
		{
		case SDL_QUIT:
			continuer=0;
		break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_SPACE:
			b.tap++;
			break;
			}
		break;
		}
	}
/*switch(b.tap)
{
case 0:
Mix_PlayChannel(-1,b.sound_level[0],0);
break;

case 1:

Mix_PlayChannel(-1,b.sound_level[1],0);
break;

case 2:

Mix_PlayChannel(-1,b.sound_level[2],0);
break;

case 4:

Mix_PlayChannel(-1,b.sound_level[3],0);
break;

case 5:

Mix_PlayChannel(-1,b.sound_level[4],0);
break;
case 7:
Mix_PlayChannel(-1,b.sound_level[5],0);
break;
case 8:
Mix_PlayChannel(-1,b.sound_level[6],0);
break;
}*/
if (b.tap==3 || b.tap==6 || b.tap==9)
niveau=2;

}
if(niveau==12)
{
afficher_next_level( s,screen);
afficher_next(s,screen);
while(SDL_PollEvent(&event))
	{
	switch(event.type)
	{
	case SDL_QUIT:
	continuer=0;
	break;

	case SDL_MOUSEMOTION:
	if ((event.motion.x>=s.pos_next.x) && (event.motion.x<=(s.pos_next.x + s.pos_next.w))&&(event.motion.y>=s.pos_next.y)&&(event.motion.y<=(s.pos_next.y+s.pos_next.h)))
	s.motion=1;
	else 
	s.motion=0;
	break;	

	case SDL_MOUSEBUTTONDOWN:
	if ((event.button.x>=s.pos_next.x) && (event.button.x<=(s.pos_next.x + s.pos_next.w))&&(event.button.y>=s.pos_next.y)&&(event.button.y<=(s.pos_next.y+s.pos_next.h)))
	{
	s.clic=1;	
if(b.niveau==2 )
{
tempsActuel=0;tempsPrecedent=0;compteur=0;vrai_compteur=0;
init_ttf(&t,temps);
initialiser_minimap(&m);
initialiser_perso (&p);
initialiser_perso2(&p2);
initialiser_input (&I);
initialiser_input2(&I2);
initialiser_backround (&b);
InitEnnemi(&e);
InitEnnemi2(&e2);
init_Ennemi3(&e3);
initialiser_coin(&c);
initialiser_porte(&po);
initialiser_star(&s);
niveau=11;
b.niveau=1;
b.tap=4;
}
else if(b.niveau==1 )
{
tempsActuel=0;tempsPrecedent=0;compteur=0;vrai_compteur=0;
init_ttf(&t,temps);
initialiser_minimap(&m);
initialiser_perso (&p);
initialiser_perso2(&p2);
initialiser_input (&I);
initialiser_input2(&I2);
initialiser_backround (&b);
InitEnnemi(&e);
InitEnnemi2(&e2);
init_Ennemi3(&e3);
initialiser_coin(&c);
initialiser_porte(&po);
initialiser_star(&s);
niveau=11;
b.niveau=0;
b.tap=7;

}
	}	
	break;



	}
	}

}
if (niveau==13)
{
SDL_Flip(screen);
afficher_enigme_s(ens,screen);

while(SDL_PollEvent(&event))
	{
	switch(event.type)
	{
	case SDL_QUIT:
	continuer=0;
	break;
		case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
		case SDLK_a:
		Mix_PlayChannel(-1,bt.win,0);	
		e.scor+=200;
		p.rect.x-=50;
		p.rect_relative.x-=20;
		if(e.vie<2)
		e.vie++;
		niveau=2;
		break;
		case SDLK_b:
		Mix_PlayChannel(-1,bt.fail,0);
		e.scor-=200;
		p.rect.x-=50;
		p.rect_relative.x-=50;
		niveau=2;
		animer_die_right(&e);
		e.vie--;
		break;
		case SDLK_c:
		Mix_PlayChannel(-1,bt.fail,0);
		e.scor-=200;
		p.rect.x-=50;
		p.rect_relative.x-=50;
		niveau=2;
		animer_die_right(&e);
		e.vie--;
		break;
		}
	}
	}
}
if (niveau==14)
{
//SDL_Flip(screen);
afficher_enigmes(sa,screen);
while(SDL_PollEvent(&event))
	{
	switch(event.type)
	{
	case SDL_QUIT:
	continuer=0;
	break;
	case SDL_MOUSEBUTTONDOWN:
	if ((event.button.x>=sa.pos_planet[0].x) && (event.button.x<=(sa.pos_planet[0].x + sa.pos_planet[0].w))&&(event.button.y>=sa.pos_planet[0].y)&&(event.button.y<=(sa.pos_planet[0].y+sa.pos_planet[0].h)))	
	{
	Mix_PlayChannel(-1,bt.effect,0);
	niveau=4;
	}
	else 	if ((event.button.x>=sa.pos_planet[1].x) && (event.button.x<=(sa.pos_planet[1].x + sa.pos_planet[1].w))&&(event.button.y>=sa.pos_planet[1].y)&&(event.button.y<=(sa.pos_planet[1].y+sa.pos_planet[1].h)))	
	{
	Mix_PlayChannel(-1,bt.effect,0);
	niveau=10;
	}
	else if ((event.button.x>=sa.pos_planet[2].x) && (event.button.x<=(sa.pos_planet[2].x + sa.pos_planet[2].w))&&(event.button.y>=sa.pos_planet[2].y)&&(event.button.y<=(sa.pos_planet[2].y+sa.pos_planet[2].h)))	
	{

	niveau=13;
	}
	else 
	niveau=2;
	break;
	}
	}
}
	SDL_Delay(30);
}
	TTF_CloseFont(t.police);
	TTF_Quit();
////////////////////////////////// liberationnnnnnnnnnnnnnn

	SDL_FreeSurface(screen);
	SDL_FreeSurface(screen1);
	SDL_FreeSurface(ecran);	
	//Liberer(&B,&b,&m,&t,&p,&bt,screen);
liberer_ennemi(&e,&s,&c);
Liberer (&m,&t);
//liberer_sauvgarde(&s);
Mix_FreeChunk(bt.effect);
Mix_FreeMusic(music);
Mix_FreeMusic(music_g);

////////////////////////////////////////////////////liberation
SDL_Quit();
return 0;

}
