#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include"fonctions.h"
void initialiser_background1(Background *B)
{char nomFich[60];
int i,j=0;
    for ( i =0; i < 18; i++)
    {
        sprintf(nomFich,"images_background/%d.png",i);
        B->menu[i]=IMG_Load(nomFich);
	
    }
	B->m=B->menu[0];
	B->fr=0;
	B->positionEcran.x=0;
	B->positionEcran.y=0;
	B->level=SDL_LoadBMP("level/level.bmp");
	B->niveau[0]=IMG_Load("level/1.png");
	B->niveau[1]=IMG_Load("level/2.png");
	B->niveau[2]=IMG_Load("level/3.png");
	B->niveau[3]=IMG_Load("level/4.png");
	B->niveau[4]=IMG_Load("level/5.png");
	B->niveau[5]=IMG_Load("level/6.png");
	j=6;
    	for ( i =0; i < 9; i++)
   	  {
          sprintf(nomFich,"star_level/%d.png",i);
          B->niveau[j]=IMG_Load(nomFich);
	  j++;
	  }
	B->retour=IMG_Load("images_options/retour.png");
	B->loading=IMG_Load("images_background/space_adventure.jpg");
	B->position_loading.x=0;
	B->position_loading.y=0;
	B->position_niveau[0].x=70;
	B->position_niveau[0].y=470;
	B->position_niveau[0].w=B->niveau[0]->w;
	B->position_niveau[0].h=B->niveau[0]->h;
	B->image=SDL_LoadBMP("images_background/back.bmp");
	B->position_niveau[1].x=715;
	B->position_niveau[1].y=410;
	B->position_niveau[1].w=B->niveau[1]->w;
	B->position_niveau[1].h=B->niveau[1]->h;

	B->position_niveau[2].x=1380;
	B->position_niveau[2].y=250;
	B->position_niveau[2].w=B->niveau[2]->w;
	B->position_niveau[2].h=B->niveau[2]->h;
	B->pos_retour.x=10;
	B->pos_retour.y=200;
	B->pos_retour.w=B->retour->w;
	B->pos_retour.h=B->retour->h;
        B->motion=0;
	B->pause=IMG_Load("mini_jeu/pause.png");
	B->pos_pause.x=10;
	B->pos_pause.y=200;
	B->pos_pause.w=B->pause->w;
	B->pos_pause.h=B->pause->h;

	B->spaceship[0]=IMG_Load("menu/D.png");
	B->spaceship[1]=IMG_Load("menu/G.png");
	B->spaceship[2]=IMG_Load("spaceship/D.png");
	B->spaceship[3]=IMG_Load("spaceship/G.png");
	B->pos_spaceship.x=10;
	B->pos_spaceship.y=500;
	B->pos_spaceship2.x=10;
	B->pos_spaceship2.y=-100;
	B->direction=1;
	B->lampe=IMG_Load("mini_jeu/lampe.png");
	B->pos_lampe.x=10;
	B->pos_lampe.y=500;
	B->pos_lampe.w=B->lampe->w;
	B->pos_lampe.h=B->lampe->h;
	for(i=0;i<3;i++)
	B->premiere_fois[i]=0;
	B->title=IMG_Load("images_background/title.png");
	B->pos_title.x=470;
	B->pos_title.y=5;
	
}
void afficher_retour(Background B,SDL_Surface* screen)
{
SDL_BlitSurface(B.retour,NULL,screen,&(B.pos_retour));
}
void afficher_pause(Background B,SDL_Surface* screen)
{
SDL_BlitSurface(B.pause,NULL,screen,&(B.pos_pause));
}
void afficher_levels(Background B,SDL_Surface* screen,Ennemi s)
{
SDL_BlitSurface(B.level,NULL,screen,&(B.positionEcran));
switch(B.motion)
{
case 0:
SDL_BlitSurface(B.niveau[0],NULL,screen,&(B.position_niveau[0]));
SDL_BlitSurface(B.niveau[2],NULL,screen,&(B.position_niveau[1]));
SDL_BlitSurface(B.niveau[4],NULL,screen,&(B.position_niveau[2]));
break;
case 1:
SDL_BlitSurface(B.niveau[1],NULL,screen,&(B.position_niveau[0]));
SDL_BlitSurface(B.niveau[2],NULL,screen,&(B.position_niveau[1]));
SDL_BlitSurface(B.niveau[4],NULL,screen,&(B.position_niveau[2]));
break;

case 2:
SDL_BlitSurface(B.niveau[0],NULL,screen,&(B.position_niveau[0]));
SDL_BlitSurface(B.niveau[3],NULL,screen,&(B.position_niveau[1]));
SDL_BlitSurface(B.niveau[4],NULL,screen,&(B.position_niveau[2]));
break;

case 3:
SDL_BlitSurface(B.niveau[0],NULL,screen,&(B.position_niveau[0]));
SDL_BlitSurface(B.niveau[2],NULL,screen,&(B.position_niveau[1]));
SDL_BlitSurface(B.niveau[5],NULL,screen,&(B.position_niveau[2]));
break;
switch(s.nbr_etoile)
{
case 1:
SDL_BlitSurface(B.niveau[6],NULL,screen,&(B.position_niveau[0]));
SDL_BlitSurface(B.niveau[9],NULL,screen,&(B.position_niveau[1]));
SDL_BlitSurface(B.niveau[12],NULL,screen,&(B.position_niveau[2]));
break;

case 2:
SDL_BlitSurface(B.niveau[7],NULL,screen,&(B.position_niveau[0]));
SDL_BlitSurface(B.niveau[10],NULL,screen,&(B.position_niveau[1]));
SDL_BlitSurface(B.niveau[13],NULL,screen,&(B.position_niveau[2]));
break;

case 3:
SDL_BlitSurface(B.niveau[8],NULL,screen,&(B.position_niveau[0]));
SDL_BlitSurface(B.niveau[11],NULL,screen,&(B.position_niveau[1]));
SDL_BlitSurface(B.niveau[14],NULL,screen,&(B.position_niveau[2]));
break;
}
}
}
void initialiser_background2(Background *B)
{
	B->back_op=NULL;
	B->back_op=IMG_Load("images_options/options1.jpg");
	B->position_back_op.x=0;
	B->position_back_op.y=0;
	B->tap_son=0;
}
void afficher_background1(Background B,SDL_Surface* screen)
{
SDL_BlitSurface(B.m,NULL,screen,&B.position_back_op);
SDL_BlitSurface(B.title,NULL,screen,&B.pos_title);
}
void afficher_background2(Background B,SDL_Surface* screen)
{
SDL_BlitSurface(B.back_op,NULL,screen,&(B.position_back_op));
}
void initialiser_bouton(bouton *bt)
{
int i;
bt-> coins=NULL;
for (i=0;i<31;i++)
{
bt->image_bouton[i]=NULL;
}
bt-> image_bouton[0]=IMG_Load("images_background/start.png"); 
bt-> image_bouton[1]=IMG_Load("images_background/start1.png"); 
bt-> image_bouton[2]=IMG_Load("images_background/multiplayer.png");
bt-> image_bouton[3]=IMG_Load("images_background/multiplayer1.png");
bt-> image_bouton[4]=IMG_Load("images_background/options.png");
bt-> image_bouton[5]=IMG_Load("images_background/options1.png");
bt-> image_bouton[6]=IMG_Load("images_background/exit.png");
bt-> image_bouton[7]=IMG_Load("images_background/exit1.png");
bt-> image_bouton[8]=IMG_Load("images_background/son.png");
bt-> image_bouton[9]=IMG_Load("images_background/son1.png");
bt-> image_bouton[10]=IMG_Load("images_options/home.png");
bt-> image_bouton[11]=IMG_Load("images_options/home1.png");
bt-> image_bouton[12]=IMG_Load("images_options/fscreen2.png");
bt-> image_bouton[13]=IMG_Load("images_options/fscreen1.png");
bt-> image_bouton[14]=IMG_Load("images_options/fscreen.png");
bt-> image_bouton[15]=IMG_Load("images_options/splus.png");
bt-> image_bouton[16]=IMG_Load("images_options/splus1.png");
bt-> image_bouton[17]=IMG_Load("images_options/smoins.png");
bt-> image_bouton[18]=IMG_Load("images_options/smoins1.png");
bt-> image_bouton[19]=IMG_Load("images_options/sound1.png");
bt-> image_bouton[20]=IMG_Load("images_options/sound2.png");
bt-> image_bouton[21]=IMG_Load("images_options/sound3.png");
bt-> image_bouton[22]=IMG_Load("images_options/sound4.png");
bt-> image_bouton[23]=IMG_Load("images_options/sound5.png");
bt-> image_bouton[24]=IMG_Load("images_options/sound6.png");
bt-> image_bouton[25]=IMG_Load("images_options/sound7.png");
bt-> image_bouton[26]=IMG_Load("images_options/sound8.png");
bt-> image_bouton[27]=IMG_Load("images_options/sound9.png");
bt-> image_bouton[28]=IMG_Load("images_options/sound10.png");
bt-> image_bouton[29]=IMG_Load("images_options/sound11.png");
bt-> image_bouton[30]=IMG_Load("images_options/sound12.png");
bt-> position_coins.x=120;
bt-> position_coins.y=2;
bt->position_bouton[0].x=630;
bt->position_bouton[0].y=150;
bt-> position_bouton[0].w=bt->image_bouton[0]->w;
bt-> position_bouton[0].h=bt->image_bouton[0]->h;
bt->position_bouton[1].x=630;
bt->position_bouton[1].y=150;
bt->position_bouton[2].x=630;
bt->position_bouton[2].y=320;
bt-> position_bouton[2].w=bt->image_bouton[2]->w;
bt-> position_bouton[2].h=bt->image_bouton[2]->h;
bt->position_bouton[3].x=580;
bt->position_bouton[3].y=320;
bt->position_bouton[4].x=630;
bt->position_bouton[4].y=490;
bt-> position_bouton[4].w=bt->image_bouton[4]->w;
bt-> position_bouton[4].h=bt->image_bouton[4]->h;
bt->position_bouton[5].x=630;
bt->position_bouton[5].y=490;
bt->position_bouton[6].x=630;
bt->position_bouton[6].y=660;
bt-> position_bouton[6].w=bt->image_bouton[6]->w;
bt-> position_bouton[6].h=bt->image_bouton[6]->h;
bt->position_bouton[7].x=630;
bt->position_bouton[7].y=490;
bt->position_bouton[8].x=1460;
bt->position_bouton[8].y=10;
bt-> position_bouton[8].w=bt->image_bouton[8]->w;
bt-> position_bouton[8].h=bt->image_bouton[8]->h;
bt->position_bouton[9].x=1500;
bt->position_bouton[9].y=200;
bt-> position_bouton[9].w=bt->image_bouton[9]->w;
bt-> position_bouton[9].h=bt->image_bouton[9]->h;
bt->position_bouton[10].x=560;
bt->position_bouton[10].y=290;
bt-> position_bouton[10].w=bt->image_bouton[10]->w;
bt-> position_bouton[10].h=bt->image_bouton[10]->h;
bt->position_bouton[11].x=560;
bt->position_bouton[11].y=290;
bt-> position_bouton[11].w=bt->image_bouton[11]->w;
bt-> position_bouton[11].h=bt->image_bouton[11]->h;
bt->position_bouton[12].x=560;
bt->position_bouton[12].y=420;
bt-> position_bouton[12].w=bt->image_bouton[12]->w;
bt-> position_bouton[12].h=bt->image_bouton[12]->h;
bt->position_bouton[13].x=560;
bt->position_bouton[13].y=420;
bt-> position_bouton[13].w=bt->image_bouton[13]->w;
bt-> position_bouton[13].h=bt->image_bouton[13]->h;
bt->position_bouton[14].x=560;
bt->position_bouton[14].y=420;
bt-> position_bouton[14].w=bt->image_bouton[14]->w;
bt-> position_bouton[14].h=bt->image_bouton[14]->h;
bt->position_bouton[15].x=910;
bt->position_bouton[15].y=660;
bt-> position_bouton[15].w=bt->image_bouton[15]->w;
bt-> position_bouton[15].h=bt->image_bouton[15]->h;
bt->position_bouton[16].x=910;
bt->position_bouton[16].y=660;
bt-> position_bouton[16].w=bt->image_bouton[16]->w;
bt-> position_bouton[16].h=bt->image_bouton[16]->h;
bt->position_bouton[17].x=530;
bt->position_bouton[17].y=660;
bt-> position_bouton[17].w=bt->image_bouton[17]->w;
bt-> position_bouton[17].h=bt->image_bouton[17]->h;
bt->position_bouton[18].x=530;
bt->position_bouton[18].y=660;
bt-> position_bouton[18].w=bt->image_bouton[18]->w;
bt-> position_bouton[18].h=bt->image_bouton[18]->h;
bt->position_bouton[19].x=630;
bt->position_bouton[19].y=671.383;
bt->position_bouton[20].x=630;
bt->position_bouton[20].y=671.383;
bt->position_bouton[21].x=630;
bt->position_bouton[21].y=671.383;
bt->position_bouton[22].x=630;
bt->position_bouton[22].y=671.383;
bt->position_bouton[23].x=630;
bt->position_bouton[23].y=671.383;
bt->position_bouton[24].x=630;
bt->position_bouton[24].y=671.383;
bt->position_bouton[25].x=630;
bt->position_bouton[25].y=671.383;
bt->position_bouton[26].x=630;
bt->position_bouton[26].y=671.383;
bt->position_bouton[27].x=630;
bt->position_bouton[27].y=671.383;
bt->position_bouton[28].x=630;
bt->position_bouton[28].y=671.383;
bt->position_bouton[29].x=630;
bt->position_bouton[29].y=671.383;
bt->position_bouton[30].x=630;
bt->position_bouton[30].y=671.383;
bt->effect=Mix_LoadWAV("music/clic.wav");
bt->effect_coin=Mix_LoadWAV("music/Coin_Mario_Bros.wav");
bt->win=Mix_LoadWAV("music/win.wav");
bt->fail=Mix_LoadWAV("music/fail.wav");
bt->tap_screen=0;
}
void motion_back1(SDL_Event event,bouton bt,int *actif )
{
if ((event.motion.x>=bt.position_bouton[0].x) && (event.motion.x<=(bt.position_bouton[0].x + bt.position_bouton[0].w))&&(event.motion.y>=bt.position_bouton[0].y)&&(event.motion.y<=(bt.position_bouton[0].y+bt.position_bouton[0].h)))
{
*actif=1;
}
else
*actif=0;
if ((event.motion.x>=bt.position_bouton[2].x) && (event.motion.x<=(bt.position_bouton[2].x + bt.position_bouton[2].w))&&(event.motion.y>=bt.position_bouton[2].y)&&(event.motion.y<=(bt.position_bouton[2].y+bt.position_bouton[2].h)))
{
*actif=2;
}

if ((event.motion.x>=bt.position_bouton[4].x) && (event.motion.x<=(bt.position_bouton[4].x + bt.position_bouton[4].w))&&(event.motion.y>=bt.position_bouton[4].y)&&(event.motion.y<=(bt.position_bouton[4].y+bt.position_bouton[4].h)))
{
*actif=3;
}


if ((event.motion.x>=bt.position_bouton[6].x) && (event.motion.x<=(bt.position_bouton[6].x + bt.position_bouton[6].w))&&(event.motion.y>=bt.position_bouton[6].y)&&(event.motion.y<=(bt.position_bouton[6].y+bt.position_bouton[6].h)))
{
*actif=4;
}

}
void afficher_boutons_back(bouton bt, Background B,int actif,int clic,SDL_Surface* screen)
{
SDL_BlitSurface(B.lampe,NULL,screen,&(B.pos_lampe));
switch (actif)
{
case 0:
SDL_BlitSurface(bt.image_bouton[0],NULL,screen,&(bt.position_bouton[0]));
SDL_BlitSurface(bt.image_bouton[2],NULL,screen,&(bt.position_bouton[2]));
SDL_BlitSurface(bt.image_bouton[4],NULL,screen,&(bt.position_bouton[4]));
SDL_BlitSurface(bt.image_bouton[6],NULL,screen,&(bt.position_bouton[6]));
if(B.tap_son % 2 ==0)
SDL_BlitSurface(bt.image_bouton[8],NULL,screen,&(bt.position_bouton[8]));
else
SDL_BlitSurface(bt.image_bouton[9],NULL,screen,&(bt.position_bouton[8]));
SDL_BlitSurface(bt.coins,NULL,screen,&(bt.position_coins));
break;
case 1:
SDL_BlitSurface(bt.image_bouton[1],NULL,screen,&(bt.position_bouton[0]));
SDL_BlitSurface(bt.image_bouton[2],NULL,screen,&(bt.position_bouton[2]));
SDL_BlitSurface(bt.image_bouton[4],NULL,screen,&(bt.position_bouton[4]));
SDL_BlitSurface(bt.image_bouton[6],NULL,screen,&(bt.position_bouton[6]));
if(B.tap_son % 2 ==0)
SDL_BlitSurface(bt.image_bouton[8],NULL,screen,&(bt.position_bouton[8]));
else
SDL_BlitSurface(bt.image_bouton[9],NULL,screen,&(bt.position_bouton[8]));
SDL_BlitSurface(bt.coins,NULL,screen,&(bt.position_coins));
break;
case 2:
SDL_BlitSurface(bt.image_bouton[0],NULL,screen,&(bt.position_bouton[0]));
SDL_BlitSurface(bt.image_bouton[3],NULL,screen,&(bt.position_bouton[2]));
SDL_BlitSurface(bt.image_bouton[4],NULL,screen,&(bt.position_bouton[4]));
SDL_BlitSurface(bt.image_bouton[6],NULL,screen,&(bt.position_bouton[6]));
if(B.tap_son % 2 ==0)
SDL_BlitSurface(bt.image_bouton[8],NULL,screen,&(bt.position_bouton[8]));
else
SDL_BlitSurface(bt.image_bouton[9],NULL,screen,&(bt.position_bouton[8]));
SDL_BlitSurface(bt.coins,NULL,screen,&(bt.position_coins));
break;
case 3:
SDL_BlitSurface(bt.image_bouton[0],NULL,screen,&(bt.position_bouton[0]));
SDL_BlitSurface(bt.image_bouton[2],NULL,screen,&(bt.position_bouton[2]));
SDL_BlitSurface(bt.image_bouton[5],NULL,screen,&(bt.position_bouton[4]));
SDL_BlitSurface(bt.image_bouton[6],NULL,screen,&(bt.position_bouton[6]));
if(B.tap_son % 2 ==0)
SDL_BlitSurface(bt.image_bouton[8],NULL,screen,&(bt.position_bouton[8]));
else
SDL_BlitSurface(bt.image_bouton[9],NULL,screen,&(bt.position_bouton[8]));
SDL_BlitSurface(bt.coins,NULL,screen,&(bt.position_coins));
break;
case 4:
SDL_BlitSurface(bt.image_bouton[0],NULL,screen,&(bt.position_bouton[0]));
SDL_BlitSurface(bt.image_bouton[2],NULL,screen,&(bt.position_bouton[2]));
SDL_BlitSurface(bt.image_bouton[4],NULL,screen,&(bt.position_bouton[4]));
SDL_BlitSurface(bt.image_bouton[7],NULL,screen,&(bt.position_bouton[6]));
if(B.tap_son % 2 ==0)
SDL_BlitSurface(bt.image_bouton[8],NULL,screen,&(bt.position_bouton[8]));
else
SDL_BlitSurface(bt.image_bouton[9],NULL,screen,&(bt.position_bouton[8]));
SDL_BlitSurface(bt.coins,NULL,screen,&(bt.position_coins));
break;
}
}
void motion_back2(SDL_Event event,bouton bt, int *actif_op)
{
if((event.motion.x>=bt.position_bouton[10].x)&&(event.motion.x<=(bt.position_bouton[10].x+bt.position_bouton[10].w))&&(event.motion.y>=bt.position_bouton[10].y)&&(event.motion.y<=(bt.position_bouton[10].y+bt.position_bouton[10].h)))
{
*actif_op=1;
}
else

*actif_op=0;
if ((event.motion.x>=bt.position_bouton[12].x) && (event.motion.x<=(bt.position_bouton[12].x + bt.position_bouton[12].w))&&(event.motion.y>=bt.position_bouton[12].y)&&(event.motion.y<=(bt.position_bouton[12].y+bt.position_bouton[12].h)))
{
*actif_op=2;
}
if ((event.motion.x>=bt.position_bouton[15].x) && (event.motion.x<=(bt.position_bouton[15].x + bt.position_bouton[15].w))&&(event.motion.y>=bt.position_bouton[15].y)&&(event.motion.y<=(bt.position_bouton[15].y+bt.position_bouton[15].h)))
{
*actif_op=3;
}
if ((event.motion.x>=bt.position_bouton[17].x) && (event.motion.x<=(bt.position_bouton[17].x + bt.position_bouton[17].w))&&(event.motion.y>=bt.position_bouton[17].y)&&(event.motion.y<=(bt.position_bouton[17].y+bt.position_bouton[17].h)))
{
*actif_op=4;
}

}
void afficher_boutons_options(Background B,bouton bt,int actif_op,int clic_volume,SDL_Surface* screen)
{
modif_volume(bt,clic_volume,screen);
switch (actif_op)
{
case 0:
SDL_BlitSurface(bt.image_bouton[10],NULL,screen,&(bt.position_bouton[10]));
if(bt.tap_screen % 2 ==0)
SDL_BlitSurface(bt.image_bouton[12],NULL,screen,&(bt.position_bouton[12]));
else
SDL_BlitSurface(bt.image_bouton[14],NULL,screen,&(bt.position_bouton[14]));
SDL_BlitSurface(bt.image_bouton[15],NULL,screen,&(bt.position_bouton[15]));
SDL_BlitSurface(bt.image_bouton[17],NULL,screen,&(bt.position_bouton[17]));

break;
case 1:
SDL_BlitSurface(bt.image_bouton[11],NULL,screen,&(bt.position_bouton[11]));
if(bt.tap_screen % 2 ==0)
SDL_BlitSurface(bt.image_bouton[12],NULL,screen,&(bt.position_bouton[12]));
SDL_BlitSurface(bt.image_bouton[15],NULL,screen,&(bt.position_bouton[15]));
SDL_BlitSurface(bt.image_bouton[17],NULL,screen,&(bt.position_bouton[17]));

break;
case 2:
SDL_BlitSurface(bt.image_bouton[10],NULL,screen,&(bt.position_bouton[10]));
SDL_BlitSurface(bt.image_bouton[13],NULL,screen,&(bt.position_bouton[13]));
SDL_BlitSurface(bt.image_bouton[15],NULL,screen,&(bt.position_bouton[15]));
SDL_BlitSurface(bt.image_bouton[17],NULL,screen,&(bt.position_bouton[17]));

break;
case 3:
SDL_BlitSurface(bt.image_bouton[10],NULL,screen,&(bt.position_bouton[10]));
if(bt.tap_screen % 2 ==0)
SDL_BlitSurface(bt.image_bouton[12],NULL,screen,&(bt.position_bouton[12]));
else
SDL_BlitSurface(bt.image_bouton[14],NULL,screen,&(bt.position_bouton[14]));
SDL_BlitSurface(bt.image_bouton[16],NULL,screen,&(bt.position_bouton[16]));
SDL_BlitSurface(bt.image_bouton[17],NULL,screen,&(bt.position_bouton[17]));

break;
case 4:
SDL_BlitSurface(bt.image_bouton[10],NULL,screen,&(bt.position_bouton[10]));
if(bt.tap_screen % 2 ==0)
SDL_BlitSurface(bt.image_bouton[12],NULL,screen,&(bt.position_bouton[12]));
else
SDL_BlitSurface(bt.image_bouton[14],NULL,screen,&(bt.position_bouton[14]));
SDL_BlitSurface(bt.image_bouton[15],NULL,screen,&(bt.position_bouton[15]));
SDL_BlitSurface(bt.image_bouton[18],NULL,screen,&(bt.position_bouton[18]));

break;
}
}
void clic_menu_background(Background B,bouton bt, int clic,int *niveau,int *continuer)
{
switch (clic)
{
case 1:
Mix_PlayChannel(-1,bt.effect,0);
(*niveau)=9;
break;

case 2:
Mix_PlayChannel(-1,bt.effect,0);
break;

case 3:
Mix_PlayChannel(-1,bt.effect,0);
(*niveau)=1;
break;

case 4:
Mix_PlayChannel(-1,bt.effect,0);
*continuer=0;
break;

case 5:
Mix_ResumeMusic();
break;

case 6:
Mix_PauseMusic();
break;
}
}
void clic_menu_options(bouton bt,int clic_op,int *niveau,SDL_Surface* screen)
{
switch (clic_op)
{
case 2:
Mix_PlayChannel(-1,bt.effect,0);
break;
}
}
void modif_volume(bouton bt,int clic_volume,SDL_Surface* screen)
{
switch(clic_volume)
{
case 1:
SDL_BlitSurface(bt.image_bouton[19],NULL,screen,&(bt.position_bouton[19]));
Mix_VolumeMusic(MIX_MAX_VOLUME/128);
Mix_VolumeChunk(bt.effect,MIX_MAX_VOLUME/128);
break;

case 2:
SDL_BlitSurface(bt.image_bouton[20],NULL,screen,&(bt.position_bouton[20]));
Mix_VolumeMusic(MIX_MAX_VOLUME/64);
Mix_VolumeChunk(bt.effect,MIX_MAX_VOLUME/64);
break;

case 3:
SDL_BlitSurface(bt.image_bouton[21],NULL,screen,&(bt.position_bouton[21]));
break;
Mix_VolumeMusic(MIX_MAX_VOLUME/32);
Mix_VolumeChunk(bt.effect,MIX_MAX_VOLUME/32);
case 4:
SDL_BlitSurface(bt.image_bouton[22],NULL,screen,&(bt.position_bouton[22]));
Mix_VolumeMusic(MIX_MAX_VOLUME/16);
Mix_VolumeChunk(bt.effect,MIX_MAX_VOLUME/16);
break;
case 5:
SDL_BlitSurface(bt.image_bouton[23],NULL,screen,&(bt.position_bouton[23]));
Mix_VolumeMusic(MIX_MAX_VOLUME/8);
Mix_VolumeChunk(bt.effect,MIX_MAX_VOLUME/8);
break;

case 6:
SDL_BlitSurface(bt.image_bouton[24],NULL,screen,&(bt.position_bouton[24]));
Mix_VolumeMusic(MIX_MAX_VOLUME/4);
Mix_VolumeChunk(bt.effect,MIX_MAX_VOLUME/4);
break;

case 7:
SDL_BlitSurface(bt.image_bouton[25],NULL,screen,&(bt.position_bouton[25]));
Mix_VolumeMusic(MIX_MAX_VOLUME/2);
//Mix_VolumeChunk(bt.effect,MIX_MAX_VOLUME/2);
break;

case 8:
SDL_BlitSurface(bt.image_bouton[26],NULL,screen,&(bt.position_bouton[26]));
Mix_VolumeMusic(MIX_MAX_VOLUME);
Mix_VolumeChunk(bt.effect,MIX_MAX_VOLUME);
break;
case 9:
SDL_BlitSurface(bt.image_bouton[27],NULL,screen,&(bt.position_bouton[27]));
Mix_VolumeMusic(MIX_MAX_VOLUME*2);
Mix_VolumeChunk(bt.effect,MIX_MAX_VOLUME*2);
break;

case 10:
SDL_BlitSurface(bt.image_bouton[28],NULL,screen,&(bt.position_bouton[28]));
Mix_VolumeMusic(MIX_MAX_VOLUME*3);
Mix_VolumeChunk(bt.effect,MIX_MAX_VOLUME*3);
break;

case 11:
SDL_BlitSurface(bt.image_bouton[29],NULL,screen,&(bt.position_bouton[29]));
Mix_VolumeMusic(MIX_MAX_VOLUME*4);
Mix_VolumeChunk(bt.effect,MIX_MAX_VOLUME*4);
break;

case 12:
SDL_BlitSurface(bt.image_bouton[30],NULL,screen,&(bt.position_bouton[30]));
Mix_VolumeMusic(MIX_MAX_VOLUME*5);
Mix_VolumeChunk(bt.effect,MIX_MAX_VOLUME*5);
break;

}
}
void animer_back(Background *B)
{
	if (B->fr>10)
    	{
        B->fr=0;
    	}
    	B->fr++;
    	B->m=B->menu[B->fr];
}
void afficher_right(Background B,SDL_Surface* screen)
{
SDL_BlitSurface(B.spaceship[0],NULL,screen,&(B.pos_spaceship));
}
void afficher_left(Background B,SDL_Surface* screen)
{
SDL_BlitSurface(B.spaceship[1],NULL,screen,&(B.pos_spaceship));
}
void deplacement_spaceship(Background *B)
{
if (B->pos_spaceship.x >1350)//posmax
{
	B->direction=0;
	
}
if(B->pos_spaceship.x<10)//posmin
{
	B->direction=1;
	
}
if ((B->direction)==0)
{
B->pos_spaceship.x-=6;
B->pos_spaceship.y+=2;
}
if((B->direction)==1)
{
B->pos_spaceship.x+=6;
B->pos_spaceship.y-=2;
}
}
void deplacement_spaceship_niveau(Background *B)
{
if (B->pos_spaceship.x >1500)//posmax
{
	B->direction=0;
	
}
if(B->pos_spaceship.x<10)//posmin
{
	B->direction=1;
	
}
if ((B->direction)==0)
{
B->pos_spaceship.x-=6;

}
if((B->direction)==1)
{
B->pos_spaceship.x+=6;

}
}

void afficher_right2(Background B,SDL_Surface* screen)
{
SDL_BlitSurface(B.spaceship[2],NULL,screen,&(B.pos_spaceship2));
}
void afficher_left2(Background B,SDL_Surface* screen)
{
SDL_BlitSurface(B.spaceship[3],NULL,screen,&(B.pos_spaceship2));
}
void deplacement_spaceship_niveau2(Background *B)
{
if (B->pos_spaceship2.x >1500)//posmax
{
	B->direction=0;
	
}
if(B->pos_spaceship2.x<10)//posmin
{
	B->direction=1;
	
}
if ((B->direction)==0)
{
B->pos_spaceship2.x-=6;

}
if((B->direction)==1)
{
B->pos_spaceship2.x+=6;

}
}










