#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include"sauvegarde.h"
void initialiser_sauvgarde(sauvegarde *s)
{
s->background=IMG_Load("input/pause1.png");
s->background2=IMG_Load("input/pause2.png");
s->bouton[0]=IMG_Load("input/home.png");
s->bouton[1]=IMG_Load("input/home1.png");
s->bouton[2]=IMG_Load("input/save.png");
s->bouton[3]=IMG_Load("input/save1.png");
s->bouton[4]=IMG_Load("input/settings.png");
s->bouton[5]=IMG_Load("input/settings1.png");
s->boutonr[0]=IMG_Load("input/resume3.png");
s->boutonr[1]=IMG_Load("input/new_game3.png");
s->back=IMG_Load("options/back.jpg");

s->planet[0]=IMG_Load("options/0.png");
s->planet[1]=IMG_Load("options/1.png");
s->planet[2]=IMG_Load("options/2.png");

s->posbackground.x=0;
s->posbackground.y=0;


s->posbouton[0].x=800;
s->posbouton[0].y=550;
s->posbouton[0].w=s->bouton[0]->w;//al->bouton[0]->w
s->posbouton[0].h=s->bouton[0]->h;//al->bouton[0]->h

s->posbouton[1].x=800;
s->posbouton[1].y=400;
s->posbouton[1].w=s->bouton[2]->w;
s->posbouton[1].h=s->bouton[2]->h;

s->posbouton[2].x=800;
s->posbouton[2].y=250;
s->posbouton[2].w=s->bouton[4]->w;
s->posbouton[2].h=s->bouton[4]->h;

s->posboutonr[0].x=710;
s->posboutonr[0].y=500;
s->posboutonr[0].w=s->boutonr[0]->w;//al->bouton[0]->w
s->posboutonr[0].h=s->boutonr[0]->h;//al->bouton[0]->h

s->posboutonr[1].x=710;
s->posboutonr[1].y=270;
s->posboutonr[1].w=s->boutonr[1]->w;
s->posboutonr[1].h=s->boutonr[1]->h;

s->pos_planet[0].x=50;
s->pos_planet[0].y=350;
s->pos_planet[0].w=s->planet[0]->w;//al->bouton[0]->w
s->pos_planet[0].h=s->planet[0]->h;//al->bouton[0]->h

s->pos_planet[1].x=630;
s->pos_planet[1].y=350;
s->pos_planet[1].w=s->planet[1]->w;
s->pos_planet[1].h=s->planet[1]->h;

s->pos_planet[2].x=1200;
s->pos_planet[2].y=350;
s->pos_planet[2].w=s->planet[2]->w;
s->pos_planet[2].h=s->planet[2]->h;
s->niveau=1;
s->motion=0;
}
void afficher_sauvgarde(sauvegarde s,SDL_Surface* screen)
{
SDL_BlitSurface(s.background,NULL,screen,NULL);
switch(s.motion)
{
case 0:
SDL_BlitSurface(s.bouton[0],NULL,screen,&s.posbouton[0]);
SDL_BlitSurface(s.bouton[2],NULL,screen,&s.posbouton[1]);
SDL_BlitSurface(s.bouton[4],NULL,screen,&s.posbouton[2]);
break;

case 1:
SDL_BlitSurface(s.bouton[1],NULL,screen,&s.posbouton[0]);
SDL_BlitSurface(s.bouton[2],NULL,screen,&s.posbouton[1]);
SDL_BlitSurface(s.bouton[4],NULL,screen,&s.posbouton[2]);
break;

case 2:
SDL_BlitSurface(s.bouton[0],NULL,screen,&s.posbouton[0]);
SDL_BlitSurface(s.bouton[3],NULL,screen,&s.posbouton[1]);
SDL_BlitSurface(s.bouton[4],NULL,screen,&s.posbouton[2]);
break;
case 3:
SDL_BlitSurface(s.bouton[0],NULL,screen,&s.posbouton[0]);
SDL_BlitSurface(s.bouton[2],NULL,screen,&s.posbouton[1]);
SDL_BlitSurface(s.bouton[5],NULL,screen,&s.posbouton[2]);
break;
}
}
void afficher_resume(sauvegarde s,SDL_Surface* screen)
{
SDL_BlitSurface(s.background2,NULL,screen,NULL);
SDL_BlitSurface(s.boutonr[0],NULL,screen,&s.posboutonr[0]);
SDL_BlitSurface(s.boutonr[1],NULL,screen,&s.posboutonr[1]);
}
void afficher_enigmes(sauvegarde s,SDL_Surface* screen)
{
SDL_BlitSurface(s.back,NULL,screen,NULL);
SDL_BlitSurface(s.planet[0],NULL,screen,&s.pos_planet[0]);
SDL_BlitSurface(s.planet[1],NULL,screen,&s.pos_planet[1]);
SDL_BlitSurface(s.planet[2],NULL,screen,&s.pos_planet[2]);

}
void sauv (perso p,background b,Ennemi e,minimap m, char sauvegarde[],int vrai_compteur,Ennemi e2,Ennemi e3)
 {
   FILE* f=fopen(sauvegarde,"w");
   
   int i;
      if (f != NULL )
 {
	fprintf(f,"%d\n%d\n" ,p.rect.x,p.rect.y);
	fprintf(f,"%d\n%d\n" ,p.rect_relative.x,p.rect_relative.y);
	fprintf(f,"%d\n%d\n" ,b.camera.x,b.camera.y);
	fprintf(f,"%d\n%d\n" ,b.tap,b.niveau);
	fprintf(f,"%d\n%d\n" ,e.position_ennemi.x,e.position_ennemi.y);
	fprintf(f,"%d\n%d\n" ,e2.position_ennemi2.x,e2.position_ennemi2.y);
	fprintf(f,"%d\n%d\n" ,e3.position_ennemi3.x,e3.position_ennemi3.y);
	fprintf(f,"%d\n%d\n" ,e.vie,e.scor);
	fprintf(f,"%d\n%d\n" ,m.position_bonhomme.x,m.position_bonhomme.y);   
	fprintf(f,"%d\n%d\n" ,m.position_ennemii.x,m.position_ennemii.y);
	fprintf(f,"%d\n" ,vrai_compteur);

    
 
   fclose(f);
 }
}

void load (perso *p,background *b,Ennemi *e,minimap *m,char sauvegarde[],int *vrai_compteur,Ennemi *e2,Ennemi *e3)

{
   FILE* f = fopen(sauvegarde,"r");
    
      if (f != NULL )
 {
	fscanf (f,"%hd\n%hd\n" ,&p->rect.x,&p->rect.y);
	fscanf (f,"%hd\n%hd\n" ,&p->rect_relative.x,&p->rect_relative.y);
	fscanf(f,"%hd\n%hd\n" ,&b->camera.x,&b->camera.y);
	fscanf(f,"%d\n%d\n" ,&b->tap,&b->niveau);
	fscanf (f,"%hd\n%hd\n" ,&e->position_ennemi.x,&e->position_ennemi.y);
	fscanf(f,"%hd\n%hd\n" ,&e2->position_ennemi2.x,&e3->position_ennemi2.y);
	fscanf(f,"%hd\n%hd\n" ,&e3->position_ennemi3.x,&e3->position_ennemi3.y);
	fscanf(f,"%d\n%d\n" ,&e->vie,&e->scor);
	fscanf(f,"%hd\n%hd\n" ,&m->position_bonhomme.x,&m->position_bonhomme.y);   
	fscanf(f,"%hd\n%hd\n" ,&m->position_ennemii.x,&m->position_ennemii.y);
	fscanf(f,"%d\n" ,&vrai_compteur);


 }
   fclose(f);
 }
void liberer_sauvgarde(sauvegarde *s)
{
int i;
for(i=0;i<6;i++)
{
SDL_FreeSurface(s->bouton[i]);
}
SDL_FreeSurface(s->background);
}










