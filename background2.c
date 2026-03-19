#include "background2.h"

void initialiser_background3 (background2 *b)
{
    b->BgPos.x = 0;
    b->BgPos.y = 0;
//b->background=NULL;
b->bg=NULL;

b->camera.x=0;
b->camera.y=0;
b->camera.w=791;
b->camera.h=834;

b->camera2.x = 0;
b->camera2.y = 0;
b->camera2.w = 791;
b->camera2.h = 834;
//b->background=IMG_Load("bg_final.jpg");
b->mask=IMG_Load("mask.jpg");
b->bg=SDL_LoadBMP("level1.bmp");
}

void afficher_background3 (SDL_Surface *screen,background2 *b)
{
    SDL_Rect test;
    test.x = 791;
    test.y = 0;
SDL_BlitSurface(b->bg,&b->camera,screen,&b->BgPos);
SDL_BlitSurface(b->bg,&b->camera2,screen,&test);
}

void scrolling_right2 (background2 *b,perso *p,SDL_Surface *screen,Input I,Input I2)
{
	if (I.right == 1 )
    	{
	   if (b->camera.x<10000 - 791)
	   {
		//b->x_relative+=p->xvelocity;
		b->camera.x+=p->speedX;
    		p->rect_relative.x+=p->speedX;

	   }
        }
	if (I2.right == 1)
	{
	   if (b->camera2.x<10000 - 791)
	   {
		b->camera2.x+=p->speedX;
		p->rect_relative.x+=p->speedX;
	   }
	}	
}
void scrolling_left2 (background2 *b,perso *p,SDL_Surface *screen,Input I,Input I2)
{
	if (I.left == 1)
	{
	   if (b->camera.x>0)
	   {
		//b->x_relative+=p->xvelocity;
		b->camera.x-=p->speedX;
    		p->rect_relative.x-=p->speedX;
	   }
	}
	if (I2.left == 1)
	{
	   if (b->camera2.x>0)
	   {
		b->camera2.x-=p->speedX;
		p->rect_relative.x-=p->speedX;
	   }
	}
}
