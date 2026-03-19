game: IA2.o amelior.o background.o perso.o ennemi.o chrono.o enigme.o fonctions.o background2.o enig.o sauvegarde.o minijeu.o enigme_statique.o main.o
	gcc  IA2.o amelior.o background.o perso.o ennemi.o chrono.o enigme.o fonctions.o background2.o enig.o sauvegarde.o minijeu.o enigme_statique.o main.o -o game -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -g
amelior.o:amelior.c
	gcc -c amelior.c -g
background.o:background.c
	gcc -c background.c -g
perso.o:perso.c
	gcc -c perso.c -g
ennemi.o:ennemi.c
	gcc -c ennemi.c -g
chrono.o:chrono.c
	gcc -c chrono.c -g
enigme.o:enigme.c
	gcc -c enigme.c -g
fonctions.o:fonctions.c
	gcc -c fonctions.c -g
IA2.o:IA2.c
	gcc -c IA2.c -g
background2.o:background2.c
	gcc -c background2.c -g
enig.o:enig.c
	gcc -c enig.c -g
sauvegarde.o:sauvegarde.c
	gcc -c sauvegarde.c -g
minijeu.o:minijeu.c
	gcc -c minijeu.c
enigme_statique.o:enigme_statique.c
	gcc -c enigme_statique.c -g
main.o:main.c
	gcc -c main.c -g

