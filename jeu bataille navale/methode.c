#include "define.h"


//verifie si la coordonné et valide et attribue la bonne valeur au tableau
void verifPos(char posi,coordonnee coord,int tab[TAILLETAB][TAILLETAB],int taille_bateau)
{
    int verif =0;

    fflush(stdin);
    if (posi == 'v')
    {
        for (int i=0;i<taille_bateau;i++)
        {
            if ((tab[coord.y][coord.x +i] != 0) || (coord.x + taille_bateau)>TAILLETAB )
            {
                verif = 1;
            }
        }
         if (verif ==0)
            {
                for (int i=0;i<taille_bateau;i++)
                {
                    for (int j=0;j<taille_bateau;j++)
                    {
                        tab[coord.y][coord.x +i] = 1;
                    }
                }
            }

    }
    if (posi == 'h')
    {
        for (int i=0;i<taille_bateau;i++)
        {
            if ((tab[coord.y+i][coord.x] != 0) || (coord.y + taille_bateau)>TAILLETAB )
            {
                verif = 1;
            }
        }
        if (verif ==0)
        {
            for (int i=0;i<taille_bateau;i++)
            {
                for (int j=0;j<taille_bateau;j++)
                {
                    tab[coord.y+i][coord.x] = 1;
                }
            }
        }
    }
    if (verif == 1)
    {
        printf("desoler, cette coordonnee n est pas valide\n");
        selecPos(taille_bateau,tab);
    }
}

void initalTableau(int tab[TAILLETAB][TAILLETAB])
{
    for (int i=0;i<TAILLETAB;i++)
    {
        for (int j=0;j<TAILLETAB;j++)
        {
            tab[i][j] =0;
        }
    }
}

void selecPos(int taille_bateau,int tab[TAILLETAB][TAILLETAB])
{
    coordonnee coord;
    char chara,posi;
    int nb;

     //choix de la position en vertical ou horizontale
    printf("choisissez H pour horizontal et V pour vertical\n");
    afficheTableau(tab);
    scanf("%c",&posi);
    system("cls");

    if ((posi != 'v') && (posi != 'h'))
    {
         do{
            fflush(stdin);
            printf("mauvaise coordonnee, choisissez H pour horizontal et V pour vertical \n");
            afficheTableau(tab);
            scanf("%c",&posi);
            system("cls");
        }while((posi != 'v') && (posi != 'h'));
    }

    fflush(stdin);

    //choix de la colone
    printf("choisissez une colonne (a - j)\n");
    afficheTableau(tab);
    scanf("%c",&chara);
    system("cls");

    if ((chara < 'a') || (chara > 'j'))
    {
         do{
            fflush(stdin);
            printf("mauvaise coordonnee, choisissez une colonne (a - j) \n");
            afficheTableau(tab);
            scanf("%c",&chara);
            system("cls");
        }while((chara < 'a') || (chara > 'j'));

   }
    coord.x = translateChar(chara);


    //choix de la ligne
    printf("choisissez une ligne (1 - 10)\n");
    afficheTableau(tab);
    scanf("%d",&nb);
    system("cls");

    if ((nb < 1) || (nb > 10))
    {
         do{
            fflush(stdin);
            printf("mauvaise coordonnee, choisissez une ligne (1 - 10) \n");
            afficheTableau(tab);
            scanf("%d",&nb);
            system("cls");
        }while((nb < 1) || (nb > 10));
    }
    coord.y = nb-1;

    verifPos(posi,coord,tab,taille_bateau);



}

void intitialisationPlat (int tab[TAILLETAB][TAILLETAB],int j)
{
    coordonnee coord;
    const int porte_avion = 5;
    const int croiseur = 4;
    const int contre_torpilleur = 3;
    const int sous_marin = 3;
    const int torpilleur = 2;

    initalTableau(tab);

    gotoxy(0,0);
    printf("joueur %d, placez votre porte avion (5 cases)\n\n",j);
    selecPos(porte_avion,tab);
    afficheTableau(tab);

    gotoxy(0,0);
    printf("joueur %d, placez votre croiseur (4 cases)\n\n",j);
    selecPos(croiseur,tab);
    afficheTableau(tab);

    gotoxy(0,0);
    printf("joueur %d, placez votre contre torpilleur (3 cases)\n\n",j);
    selecPos(contre_torpilleur,tab);
    afficheTableau(tab);

    gotoxy(0,0);
    printf("joueur %d, placez votre sous-marin (3 cases)\n\n",j);
    selecPos(contre_torpilleur,tab);
    afficheTableau(tab);

    gotoxy(0,0);
    printf("joueur %d, placez votre torpilleur (2 cases)\n\n",j);
    selecPos(torpilleur,tab);
    afficheTableau(tab);









}

int translateChar(char charac)
{



    int retour;

    switch (charac)
    {
        case 'a':
            retour = 0;
        break;

        case 'b':
            retour = 1;
        break;

        case 'c':
            retour = 2;
        break;

        case 'd':
            retour = 3;
        break;

        case 'e':
            retour = 4;
        break;

        case 'f':
            retour = 5;
        break;

        case 'g':
            retour = 6;
        break;

        case 'h':
            retour = 7;
        break;

        case 'i':
            retour = 8;
        break;

        case 'j':
            retour = 9;
        break;
    }
    fflush(stdin);
    return retour;
}

void afficheTableau(int tab[TAILLETAB][TAILLETAB])
{
    fflush(stdin);
    int z = 40;
    int w = 10;

   gotoxy(40,9);

   printf("A B C D E F G H I J");


   for (int i=10;i<20;i++)
   {
       gotoxy(36,i);
       printf("%d|",i-9);
   }
    for (int i=0;i<TAILLETAB;i++)
    {
        gotoxy(z,w++);
        for(int j = 0; j < TAILLETAB;j++)
        {
            if (tab[i][j]==1)
            {
                 printf("= ");
            }else{
                printf("~ ");
            }

        }
    }

    gotoxy(0,15);

}
void gotoxy(short x, short y)
{
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Pos={x,y};
    SetConsoleCursorPosition(hConsole,Pos);
}

void tire (int tab[TAILLETAB][TAILLETAB],int nb)
{
    coordonnee coord;
    char chara;
    int ligne;

    fflush(stdin);

    gotoxy(0,0);
    printf("joueur %d , choisissez une colone (a - j)\n",nb);
    afficheJeu(tab);

    //choix de la colone
    scanf("%c",&chara);
    system("cls");

    if ((chara < 'a') || (chara > 'j'))
    {
         do{
            fflush(stdin);
            printf("mauvaise coordonnee, choisissez une colonne (a - j) \n");
            afficheJeu(tab);
            scanf("%c",&chara);
            system("cls");
        }while((chara < 'a') || (chara > 'j'));

   }
    coord.x = translateChar(chara);


      //choix de la ligne
    printf("choisissez une ligne (1 - 10)\n");
    afficheJeu(tab);
    scanf("%d",&ligne);
    system("cls");

    if ((ligne < 1) || (ligne > 10))
    {
         do{
            fflush(stdin);
            printf("mauvaise coordonnee, choisissez une ligne (1 - 10) \n");
            afficheJeu(tab);
            scanf("%d",&ligne);
            system("cls");
        }while((ligne < 1) || (ligne > 10));
    }
    coord.y = ligne-1;

    if (tab[coord.y][coord.x]==1)
    {
        tab[coord.y][coord.x]=3;
        printf("touche\n");
        getchar();
    }else{
        tab[coord.y][coord.x]=2;
        printf("rate\n");
        getchar();
    }
}

void afficheJeu(int tab[TAILLETAB][TAILLETAB])
{
    fflush(stdin);
    int z = 40;
    int w = 10;

   gotoxy(40,9);

   printf("A B C D E F G H I J");


   for (int i=10;i<20;i++)
   {
       gotoxy(36,i);
       printf("%d|",i-9);
   }
    for (int i=0;i<TAILLETAB;i++)
    {
        gotoxy(z,w++);
        for(int j = 0; j < TAILLETAB;j++)
        {
            if (tab[i][j]==3)
            {
                 printf("X ");
            }else if (tab[i][j]==2){
                printf("O ");
            }else{
                printf("~ ");
            }

        }
    }

    gotoxy(0,15);

}

int verifVictoire(int tab[TAILLETAB][TAILLETAB],int joueur)
{
    fflush(stdin);
    int x = 0;

     for (int i=0;i<TAILLETAB;i++)
    {
        for(int j = 0; j < TAILLETAB;j++)
        {
            if (tab[i][j]==1)
            {
                 x =1;
            }
        }
    }
    if ((x == 0) && (joueur==1))
    {
        x = 2;
    }else if ((x == 0) && (joueur==2)) {
       x = 3;
    }

    return x;
}
