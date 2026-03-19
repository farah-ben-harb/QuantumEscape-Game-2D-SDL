#include "background.h"
void initialiser_backround (background *b)
{
b->x_relative=0;
b->y_relative=-80;
//b->background=NULL;
b->bg=NULL;
b->pos.x=0;
b->pos.y=0;
b->camera.x=0;
b->camera.y=0;
b->camera.w=1582;
b->camera.h=834;
//b->background=IMG_Load("bg_final.jpg");
b->bg=SDL_LoadBMP("tache_background/level3.bmp");
b->bg2=SDL_LoadBMP("tache_background/level1.bmp");
b->bg3=SDL_LoadBMP("tache_background/level2.bmp");
b->mask=SDL_LoadBMP("tache_background/mask3.bmp");
b->mask2=SDL_LoadBMP("tache_background/mask2.bmp");
b->mask3=SDL_LoadBMP("tache_background/mask1.bmp");
b->niveau=-1;
b->tap=0;
b->story[0]=IMG_Load("images_background/0.jpg");
b->story[1]=IMG_Load("images_background/1.jpg");
b->story[2]=IMG_Load("images_background/2.jpg");
b->story[3]=IMG_Load("images_background/3.jpg");
b->story[4]=IMG_Load("images_background/4.jpg");
b->story[5]=IMG_Load("images_background/5.jpg");
b->story[6]=IMG_Load("images_background/6.jpg");
b->story[7]=SDL_LoadBMP("images_background/fin.bmp");
b->sound_level[0]=Mix_LoadWAV("sound_levels/niveau1_1.wav");
b->sound_level[1]=Mix_LoadWAV("sound_levels/niveau1_2.wav");
b->sound_level[2]=Mix_LoadWAV("sound_levels/niveau1_3.wav");
b->sound_level[3]=Mix_LoadWAV("sound_levels/niveau2_1.wav");
b->sound_level[4]=Mix_LoadWAV("sound_levels/niveau2_2.wav");
b->sound_level[5]=Mix_LoadWAV("sound_levels/niveau3_1.wav");
b->sound_level[6]=Mix_LoadWAV("sound_levels/niveau3_2.wav");
}

void afficher_background (SDL_Surface *screen,background *b)
{
SDL_BlitSurface(b->mask,&b->camera,screen,NULL);
SDL_BlitSurface(b->bg,&b->camera,screen,NULL);
}
void afficher_background_n2(SDL_Surface *screen,background *b)
{
SDL_BlitSurface(b->mask,&b->camera,screen,NULL);
SDL_BlitSurface(b->bg2,&b->camera,screen,NULL);
}
void afficher_background_n3(SDL_Surface *screen,background *b)
{
SDL_BlitSurface(b->mask,&b->camera,screen,NULL);
SDL_BlitSurface(b->bg3,&b->camera,screen,NULL);
}

void scrolling_right (background *b,perso *p,SDL_Surface *screen)
{
	if (b->camera.x<10000-1700)
	{
		//b->x_relative+=p->xvelocity;
		b->camera.x+=p->speedX;
    p->rect_relative.x+=p->speedX;

	}
}

void scrolling_left (background *b,perso *p,SDL_Surface *screen)
{
	if (b->camera.x>0)
	{
		//b->x_relative+=p->xvelocity;
		b->camera.x-=p->speedX;
    p->rect_relative.x-=p->speedX;

	}
}
void afficher_story(background b,SDL_Surface *screen)
{
switch(b.tap)
{
case 0:
SDL_BlitSurface(b.story[0],NULL,screen,NULL);
break;

case 1:
SDL_BlitSurface(b.story[1],NULL,screen,NULL);
break;

case 2:
SDL_BlitSurface(b.story[2],NULL,screen,NULL);
break;

case 4:
SDL_BlitSurface(b.story[3],NULL,screen,NULL);

break;

case 5:
SDL_BlitSurface(b.story[4],NULL,screen,NULL);

break;
case 7:
SDL_BlitSurface(b.story[5],NULL,screen,NULL);

break;
case 8:
SDL_BlitSurface(b.story[6],NULL,screen,NULL);
break;
}
}
void afficher_fin(background b,SDL_Surface *screen)
{
SDL_BlitSurface(b.story[7],NULL,screen,NULL);
}








