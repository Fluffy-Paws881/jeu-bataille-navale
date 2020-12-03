#include "define.h"
int main()
{
    int tableauJ1[TAILLETAB][TAILLETAB],tableauJ2[TAILLETAB][TAILLETAB];
    int victJ1,victJ2;
    fflush(stdin);

    intitialisationPlat(&tableauJ1,1);
    intitialisationPlat(&tableauJ2,2);
    system("cls");

    do{
        tire(&tableauJ2,1);
        victJ1 = verifVictoire(&tableauJ2,1);

        tire(&tableauJ1,2);
        victJ2 = verifVictoire(&tableauJ1,2);
    }while(victJ1 ==1 && victJ2==1);

    system("cls");
    if (victJ1 == 2)
    {
        printf("felicitation joueur 1, vous avez gagne");
    }else{
        printf("felicitation joueur 2, vous avez gagne");
    }

    return 0;
}

