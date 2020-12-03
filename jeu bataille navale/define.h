#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define TAILLETAB 10

typedef struct coordonnee{
    int x,y;
} coordonnee;

extern int verifVictoire(int tab[TAILLETAB][TAILLETAB],int joueur);
extern void afficheJeu(int tab[TAILLETAB][TAILLETAB]);
extern void tire (int tab[TAILLETAB][TAILLETAB],int nb);
extern void gotoxy(short x, short y);
extern void afficheTableau(int tab[TAILLETAB][TAILLETAB]);
extern void verifPos(char posi,coordonnee coord,int tab[TAILLETAB][TAILLETAB],int taille_bateau);
extern void initalTableau(int tab[TAILLETAB][TAILLETAB]);
extern void selecPos(int taille_bateau,int tab[TAILLETAB][TAILLETAB]);
extern void intitialisationPlat (int tab[TAILLETAB][TAILLETAB],int j);
extern int translateChar(char charac);




#endif // DEFINE_H_INCLUDED
