#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED
#include <string.h>
#include <myconio.h>
#include "Entree_Sortie1.h"
tp2_ex1="----------------";
tp2_ex2="Tester et afficher si une entier n est super premier et premier dans les deux sens ou super premier ou premier dans les deux sens ou non.\n";

tp3_ex1_qu1="Transf%crer les %cl%cments de T1 dans V1 de telle sorte:\n * \t Les %cl%cments du rang impair de T1 sont rang%cs dans V1 en ordre inverse en commençant par la fin de T2\n * \t Les %cl%cments du rang pair de T1 sont rang%cs dans V1 ";
//dans le m%cme ordre.\n";
tp3_ex1_qu2="Tester la symétrie du tableau T2.\n";
tp3_ex1_qu3="Ranger les %cl%cments du tableau T3 dans l’ordre inverse sans utiliser un tableau suppl%cmentaire.\n";
/*tp3_ex1_qu4="Effectuer k rotations circulaires à gauche d’un tableau T4.\n";
tp3_ex1_qu5="Insérer une valeur val (avec 'val' introduite à partir du clavier) à une position pos (avec 'pos'introduite à partir du clavier) dans un tableau T5.\n";
tp3_ex1_qu6="Construire un tableau V2 comportant les entiers présents dans T6 et dans T7. (Sans répétition).\n"
tp3_ex1_qu7="Construire un tableau V3 comportant les entiers présents dans T6, mais absents dans T7. (Sans répétition).\n"

tp3_ex2_qu1="Afficher tous les éléments de T8 qui sont supérieurs à A et afficher le plus petit des éléments qui sont supérieurs à A.\n"
tp3_ex2_qu2="Chercher et afficher l’élément qui apparaît le plus dans le tableau T9 de taille N, ainsi que son nombre d’occurrences.\n"
tp3_ex2_qu3="Cercher la longueur, l’indice de début et de fin du plus long plateau de tableau T10.\n"

tp3_ex3="Chercher et afficher les nombres symétriques du tableau T11.\n"
tp3_ex4="Déplacer tous les éléments nuls à la fin du tableau T12.\n"

tp4_ex1_qu1="Calculer et retourner la somme de la première diagonale de la matrice M1.\n"
tp4_ex1_qu2="Calculer et retourner la somme du triangle inférieur droit de la matrice carrrée M1 de taille N.\n"

tp4_ex2="Vérifier et afficher si la matrice M2 est symétrique par rapport à la première ou la seconde diagonale.\n"

tp4_ex3="Chercher et afficher tous les points cols de la matrice M3.\n NB:On appelle un point COL de la matrice l’élément qui est le plus petit de sa ligne et le plus grand de sa colonne.\n"

tp5_ex1_qu1="Trier le tableau T13 par ordre croissant en utilisant le principe de tri par sélection.\n"
tp5_ex1_qu2="Trier le tableau T14 par ordre croissant en utilisant le principe de tri à bulles.\n"
tp5_ex1_qu3="Trier le tableau T15 par ordre croissant en utilisant le principe de tri par insertition.\n"

tp5_ex2_qu1="Chercher la première position de la valeur val (avec 'val' introduite à partir du clavier) dans le tableau T16 en utilisant le principe de la recherche séquentielle.\n"
tp5_ex2_qu2="Chercher la première position de la valeur "val" (avec 'val' saisie à partir du clavier) dans le tableau T17 qui est trié par ordre croissant en le principe de la recherche dichotomique.\n"
*/
void tete(char tp[],char ex[],char enonce[])
{
    int i,j;


    for(i=0;i<=10;i++)
    {
        clrscr();
        gotoxy(30,11);
        printf(tp);
        if(strlen(ex)>15)
        {
        gotoxy(28,13);
        printf(ex);
        }
        else
        {
            gotoxy(33,13);
            printf(ex);
        }
        for(j=10;j<=15;j++)
        {
            gotoxy(i,j);
            printf("|");
        }
        for(j=15;j>=10;j--)
        {
            gotoxy(80-i,j);
            printf("|");
        }
        gotoxy(11,i-1);
        printf("-----------------------------------------------------------");
        gotoxy(11,26-i);
        printf("-----------------------------------------------------------");
        wait(1);


    }
    printf("\n\n");
    textcolor(4);
    objectif();
    wait(1);
    textcolor(15);
    /*printf(enonce);
    printf("\n\n\n");
    textcolor(2);*/
    wait(1);
}
void objectif()
{
    char str[16]="l'objectif est:";
    int i,j,k;

    textcolor(4);
    delline(21);

    for(i=15;i>0;i--)
    {
        delline(21);
        for(j=0;j<=15-i;j++)
        {
            gotoxy(i+j,21);
            printf("%c",str[j]);
        }
        wait(2);
    }


}


#endif // AFFICHAGE_H_INCLUDED
