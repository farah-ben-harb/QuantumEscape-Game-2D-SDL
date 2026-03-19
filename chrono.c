/** 
* @file chrono.c 
*/ 

#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>   
#include"chrono.h" 

/** 
* @brief To initialize the minimap m . 
* @param m the minimap 
* @param url the url of the image  
* @return Nothing 
*/ 

void initialiser_minimap(minimap *m)
{
char nomFich[30];
int i;
m->image_minimap=IMG_Load("minimap/minimap.png");
m->minimap2=IMG_Load("minimap/minimap2.png");
m->minimap3=IMG_Load("minimap/minimap3.png");
m->bonhomme=IMG_Load("minimap/Joueur_miniature.png");
m->ennemi=IMG_Load("minimap/ennemi.png");
m->position_minimap.x=0;
m->position_minimap.y=30;
m->position_bonhomme.x=40;
m->position_bonhomme.y=40;
m->position_ennemii.x=500;
m->position_ennemii.y=30;
for(i=0;i<15;i++)
{
sprintf(nomFich,"effet/%d.png",i);
m->fire[i]=IMG_Load(nomFich);
}
m->pos_effet.x=740;
m->pos_effet.y=30;
m->fr=0;
m->png=m->fire[0];
}
/** 
* @brief To update the minimap m . 
* @param posJoueur the position of the player
* @param posEnnemi the position of the ennemi
* @param redimensionnement
* @param m the minimap  
* @return Nothing 
*/ 

void MAJMinimap( perso p,Ennemi e, int redimensionnement,minimap *m,SDL_Rect camera)
{
SDL_Rect posJoueurABS,posEnnemiABS;
posJoueurABS.x = p.rect.x + camera.x;
posJoueurABS.y = p.rect.y + camera.y;

m->position_bonhomme.x=20+posJoueurABS.x * redimensionnement/100;
m->position_bonhomme.y=100+posJoueurABS.y * redimensionnement/100;

posEnnemiABS.x=e.position_ennemi.x + camera.x;
posEnnemiABS.y=e.position_ennemi.y + camera.y;

m->position_ennemii.x=(posEnnemiABS.x * redimensionnement/100);
m->position_ennemii.y=(100+posEnnemiABS.y * redimensionnement/100);

}
/** 
* @brief To show the minimap m . 
* @param scren the screen 
* @param m the minimap  
* @return Nothing 
*/ 
void afficher_minimap (minimap m, SDL_Surface *ecran)
{
    SDL_BlitSurface(m.image_minimap,NULL,ecran,&(m.position_minimap));
    SDL_BlitSurface(m.bonhomme,NULL,ecran,&(m.position_bonhomme));
    SDL_BlitSurface(m.ennemi,NULL,ecran,&(m.position_ennemii));
    SDL_BlitSurface(m.png,NULL,ecran,&(m.pos_effet));
}
/** 
* @brief To show the minimap m . 
* @param scren the screen 
* @param m the minimap  
* @return Nothing 
*/ 
void afficher_minimap2 (minimap m, SDL_Surface *ecran)
{
    SDL_BlitSurface(m.minimap2,NULL,ecran,&(m.position_minimap));
    SDL_BlitSurface(m.bonhomme,NULL,ecran,&(m.position_bonhomme));
    SDL_BlitSurface(m.ennemi,NULL,ecran,&(m.position_ennemii));
    SDL_BlitSurface(m.png,NULL,ecran,&(m.pos_effet));
}
/** 
* @brief To show the minimap m . 
* @param scren the screen 
* @param m the minimap  
* @return Nothing 
*/ 
void afficher_minimap3 (minimap m, SDL_Surface *ecran)
{
    SDL_BlitSurface(m.minimap3,NULL,ecran,&(m.position_minimap));
    SDL_BlitSurface(m.bonhomme,NULL,ecran,&(m.position_bonhomme));
    SDL_BlitSurface(m.ennemi,NULL,ecran,&(m.position_ennemii));
    SDL_BlitSurface(m.png,NULL,ecran,&(m.pos_effet));
}
/** 
* @brief To free the minimap m and the text t . 
* @param m the minimap  
* @param t the text 
* @return Nothing 
*/ 
void Liberer (minimap *m,text *t)
{
    SDL_FreeSurface(m->bonhomme);
    SDL_FreeSurface(m->image_minimap);
    SDL_FreeSurface(m->ennemi);
    SDL_FreeSurface(t->texte);
}
/** 
* @brief To initialize the text t . 
* @param t the text 
* @param temps   
* @return Nothing 
*/ 
void init_ttf(text *t,char temps[])
{
SDL_Color couleurNoire = {0, 0, 0}, couleurBlanche = {255, 255, 255};
t->police = TTF_OpenFont("SF_TransRobotics_Bold.ttf", 20);
t->texte = TTF_RenderText_Blended(t->police, temps, couleurBlanche);/* Initialisation du texte*/
        t->position_texte.x = 760;
        t->position_texte.y = 70;
}
/** 
* @brief To generate the time  . 
* @param tempss
* @param t the text
* @param temps
* @param tempsActuel
* @param tempsPrecedent
* @param compteur
* @param vrai_compteur
* @param temps   
* @return Nothing 
*/ 
void chronometre(int *tempss,text *t,char temps[],int *tempsActuel,int *tempsPrecedent,int *compteur,int *vrai_compteur)
{ 
	SDL_Color couleurNoire = {0, 0, 0}, couleurBlanche = {255, 255, 255};
        (*tempsActuel) = SDL_GetTicks();
        if ((*tempsActuel) - (*tempsPrecedent) >= 1000) /* Si 1000 ms au moins se sont écoulées */
        {
            (*compteur) += 1000;  /* On rajoute 1000 ms au compteur */
 
            if((*compteur) == 1000)
            {
               (*compteur) = 0;
               (*compteur)+= 1000;
            }
	(*vrai_compteur)=(*compteur)/1000;
 
            sprintf(temps, "TIME:%d", (*vrai_compteur)); /* On écrit dans la chaîne "temps" le nouveau temps */
            SDL_FreeSurface(t->texte); /* On supprime la surface précédente */
            t->texte = TTF_RenderText_Blended(t->police, temps,couleurBlanche); /* On écrit la chaîne temps dans la SDL_Surface */
            (*tempsPrecedent) = (*tempsActuel); /* On met à jour le tempsPrecedent */
        }

}
/** 
* @brief To detect the collision perfect pixel  . 
* @param p the perso 
* @param masque   
* @return collision 
*/ 
SDL_Color GetPixel (SDL_Surface *pSurface , int x , int y)
{
SDL_Color color ;
Uint32 col=0;
char* pPosition = (char*) pSurface->pixels ;
pPosition += (pSurface->pitch * y);
pPosition += (pSurface->format->BytesPerPixel * x);
memcpy(&col , pPosition , pSurface->format->BytesPerPixel);
SDL_GetRGB(col ,pSurface->format , &color.r , &color.g ,&color.b );
return (color) ;
}
/** 
* @brief To detect the collision perfect pixel  . 
* @param p the perso 
* @param masque   
* @return collision 
*/ 
int collisionPP(perso p,SDL_Surface *mask)
{
    int position_ref[16];
    SDL_Color color[8] ;
position_ref[0]=p.rect_relative.x;
position_ref[1]=p.rect_relative.y;
position_ref[2]=p.rect_relative.x+p.rect.w/2;
position_ref[3]=p.rect_relative.y;
position_ref[4]=p.rect_relative.x+p.rect.w;
position_ref[5]=p.rect_relative.y;
position_ref[6]=p.rect_relative.x;
position_ref[7]=p.rect_relative.y+p.rect.h/2;
position_ref[8]=p.rect_relative.x;
position_ref[9]=p.rect_relative.y+p.rect.h;
position_ref[10]=p.rect_relative.x;
position_ref[11]=p.rect_relative.y+p.rect.h;
position_ref[12]=p.rect_relative.x;
position_ref[13]=p.rect_relative.y+p.rect.h;
position_ref[14]=p.rect_relative.x;
position_ref[15]=p.rect_relative.y+p.rect.h/2;
        color[0]=GetPixel(mask,position_ref[0],position_ref[1]);
	color[1]=GetPixel(mask,position_ref[2],position_ref[3]);
	color[2]=GetPixel(mask,position_ref[4],position_ref[5]);
	color[3]=GetPixel(mask,position_ref[6],position_ref[7]);
	color[4]=GetPixel(mask,position_ref[8],position_ref[9]);
	color[5]=GetPixel(mask,position_ref[10],position_ref[11]);
	color[6]=GetPixel(mask,position_ref[12],position_ref[13]);
	color[7]=GetPixel(mask,position_ref[14],position_ref[15]);

    if (((color[0].r==0)  &&  (color[0].g==0)  &&  (color[0].b==0))||((color[1].r==0)  &&  (color[1].g==0)  &&  (color[1].b==0))||((color[2].r==0)  &&  (color[2].g==0)  &&  (color[2].b==0))||((color[3].r==0)  &&  (color[3].g==0)  &&  (color[3].b==0))||((color[4].r==0)  &&  (color[4].g==0)  &&  (color[4].b==0))||((color[5].r==0)  &&  (color[5].g==0)  &&  (color[5].b==0))||((color[6].r==0)  &&  (color[6].g==0)  &&  (color[6].b==0))||((color[7].r==0)  &&  (color[7].g==0)  &&  (color[7].b==0)))
{
	return 1;

}
    else if (((color[0].r==255)  &&  (color[0].g==255)  &&  (color[0].b==0))||((color[1].r==255)  &&  (color[1].g==255)  &&  (color[1].b==0))||((color[2].r==255)  &&  (color[2].g==255)  &&  (color[2].b==0))||((color[3].r==255)  &&  (color[3].g==255)  &&  (color[3].b==0))||((color[4].r==255)  &&  (color[4].g==255)  &&  (color[4].b==0))||((color[5].r==255)  &&  (color[5].g==255)  &&  (color[5].b==0))||((color[6].r==255)  &&  (color[6].g==255)  &&  (color[6].b==0))||((color[7].r==255)  &&  (color[7].g==255)  &&  (color[7].b==0)))
{
	return 2;

}
    else if (((color[0].r==0)  &&  (color[0].g==0)  &&  (color[0].b==255))||((color[1].r==0)  &&  (color[1].g==0)  &&  (color[1].b==255))||((color[2].r==0)  &&  (color[2].g==0)  &&  (color[2].b==255))||((color[3].r==0)  &&  (color[3].g==0)  &&  (color[3].b==255))||((color[4].r==0)  &&  (color[4].g==0)  &&  (color[4].b==255))||((color[5].r==0)  &&  (color[5].g==0)  &&  (color[5].b==255))||((color[6].r==0)  &&  (color[6].g==0)  &&  (color[6].b==255))||((color[7].r==0)  &&  (color[7].g==0)  &&  (color[7].b==255)))
{
	return 3;

}
    else if (((color[0].r==0)  &&  (color[0].g==255)  &&  (color[0].b==0))||((color[1].r==0)  &&  (color[1].g==255)  &&  (color[1].b==0))||((color[2].r==0)  &&  (color[2].g==255)  &&  (color[2].b==0))||((color[3].r==0)  &&  (color[3].g==255)  &&  (color[3].b==0))||((color[4].r==0)  &&  (color[4].g==255)  &&  (color[4].b==0))||((color[5].r==0)  &&  (color[5].g==255)  &&  (color[5].b==0))||((color[6].r==0)  &&  (color[6].g==255)  &&  (color[6].b==0))||((color[7].r==0)  &&  (color[7].g==255)  &&  (color[7].b==0)))
{
	return 4;

}

    else if (((color[0].r==255)  &&  (color[0].g==0)  &&  (color[0].b==255))||((color[1].r==255)  &&  (color[1].g==0)  &&  (color[1].b==255))||((color[2].r==255)  &&  (color[2].g==0)  &&  (color[2].b==255))||((color[3].r==255)  &&  (color[3].g==0)  &&  (color[3].b==255))||((color[4].r==255)  &&  (color[4].g==0)  &&  (color[4].b==255))||((color[5].r==255)  &&  (color[5].g==0)  &&  (color[5].b==255))||((color[6].r==255)  &&  (color[6].g==0)  &&  (color[6].b==255))||((color[7].r==255)  &&  (color[7].g==0)  &&  (color[7].b==255)))
{
	return 5;

}

else
    return 0;

}
void animer_effet(minimap *m)
{
 	if (m->fr>13)
    	{
        m->fr=0;
    	}
    	m->fr++;
    	m->png=m->fire[m->fr];
}
void MAJMinimap2( perso p,Ennemi e, int redimensionnement,minimap *m,SDL_Rect camera)
{
SDL_Rect posJoueurABS,posEnnemiABS;
posJoueurABS.x = p.rect.x + camera.x;
posJoueurABS.y = p.rect.y + camera.y;

m->position_bonhomme.x=20+posJoueurABS.x * redimensionnement/100;
m->position_bonhomme.y=100+posJoueurABS.y * redimensionnement/100;

posEnnemiABS.x=e.position_ennemi2.x + camera.x;
posEnnemiABS.y=e.position_ennemi2.y + camera.y;

m->position_ennemii.x=(20+posEnnemiABS.x * redimensionnement/100);
m->position_ennemii.y=(100+posEnnemiABS.y * redimensionnement/100);

}
void MAJMinimap3( perso p,Ennemi e, int redimensionnement,minimap *m,SDL_Rect camera)
{
SDL_Rect posJoueurABS,posEnnemiABS;
posJoueurABS.x = p.rect.x + camera.x;
posJoueurABS.y = p.rect.y + camera.y;

m->position_bonhomme.x=20+posJoueurABS.x * redimensionnement/100;
m->position_bonhomme.y=100+posJoueurABS.y * redimensionnement/100;

posEnnemiABS.x=e.position_ennemi3.x + camera.x;
posEnnemiABS.y=e.position_ennemi3.y + camera.y;

m->position_ennemii.x=(posEnnemiABS.x * redimensionnement/100);
m->position_ennemii.y=(100+posEnnemiABS.y * redimensionnement/100);

}
