#include "enigme.h"
enigme generer(){
    enigme e;
    int solution,ajout;
    int i;
    int nbr[4];

    srand( time( NULL ) );
    nbr[0]=rand() % 10;
    nbr[1]=nbr[0]+4;
    nbr[2]=nbr[1]-(rand() %10);
    nbr[3]=nbr[0]-nbr[2];
    
    sprintf(e.question,"(%d + %d) x (%d) - (%d) =?",nbr[0],nbr[1],nbr[2],nbr[3]);

    solution=(nbr[0]+nbr[1]) * (nbr[2])-(nbr[3]);

    srand( time( NULL ) );
    e.solution =1 + rand() % 3;
    if (e.solution==1)
    {
        sprintf(e.reponse1,"%d",solution);
        srand( time( NULL ) );
        ajout =rand() % 15;
        sprintf(e.reponse2,"%d",solution+ajout);
        srand( time( NULL ) );
        ajout =(rand() % 15)-20;
        sprintf(e.reponse3,"%d",solution+ajout);
    }
    if (e.solution==2)
    {
        sprintf(e.reponse2,"%d",solution);
        srand( time( NULL ) );
        ajout =rand() % 15;
        sprintf(e.reponse1,"%d",solution+ajout);
        srand( time( NULL ) );
        ajout =(rand() % 15)-20;
        sprintf(e.reponse3,"%d",solution+ajout);
    }
    if (e.solution==3)
    {
        sprintf(e.reponse3,"%d",solution);
        srand( time( NULL ) );
        ajout =rand() % 15;
        sprintf(e.reponse1,"%d",solution+ajout);
        srand( time( NULL ) );
        ajout =(rand() % 15)-20;
        sprintf(e.reponse2,"%d",solution+ajout);
    }
    return e;
    
    

}
void afficherEnigme(enigme *e, SDL_Surface * screen){
    
  
SDL_Surface *texte,*R1,*R2,*R3,*back,*bouton;
SDL_Rect posQ,pos1,pos2,pos3,posbouton1,posbouton2,posbouton3;
SDL_Color couleurNoire = {0, 0, 0};
TTF_Font *police = NULL,*police2 = NULL;



bouton=IMG_Load("enigme_hedi/bouton.png");
back=IMG_Load("enigme_hedi/background.jpg");


TTF_Init();
    
 
police = TTF_OpenFont("enigme_hedi/BodoniFLF-Italic.ttf", 95);
police2 = TTF_OpenFont("enigme_hedi/BodoniFLF-BoldItalic.ttf", 95);





    texte = TTF_RenderText_Blended(police, e->question, couleurNoire);
    R1 = TTF_RenderText_Blended(police2, e->reponse1, couleurNoire);
    R2 = TTF_RenderText_Blended(police2, e->reponse2, couleurNoire);
    R3 = TTF_RenderText_Blended(police2, e->reponse3, couleurNoire);




    posQ.x=350;
    posQ.y=300;
    pos1.x=300;
    pos1.y=560;
    posbouton1.x=250;
    posbouton1.y=550;
    pos2.x=600;
    pos2.y=560;
    posbouton2.x=550;
    posbouton2.y=550;
    pos3.x=920;
    pos3.y=560;
    posbouton3.x=850;
    posbouton3.y=550;



    SDL_BlitSurface(back, NULL, screen, NULL); 
    SDL_BlitSurface(texte, NULL, screen, &posQ); 
    SDL_BlitSurface(bouton,NULL,screen,&posbouton1);
    SDL_BlitSurface(bouton,NULL,screen,&posbouton2);
    SDL_BlitSurface(bouton,NULL,screen,&posbouton3);
    SDL_BlitSurface(R1, NULL, screen, &pos1); 
    SDL_BlitSurface(R2, NULL, screen, &pos2); 
    SDL_BlitSurface(R3, NULL, screen, &pos3); 
}
