#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED
#include <string.h>
#include <myconio.h>
#include "Entree_Sortie1.h"
tp2_ex1="----------------";
tp2_ex2="Tester et afficher si une entier n est super premier et premier dans les deux sens ou super premier ou premier dans les deux sens ou non.\n";

tp3_ex1_qu1="Transf%crer les %cl%cments de T1 dans V1 de telle sorte:\n * \t Les %cl%cments du rang impair de T1 sont rang%cs dans V1 en ordre inverse en commen�ant par la fin de T2\n * \t Les %cl%cments du rang pair de T1 sont rang%cs dans V1 ";
//dans le m%cme ordre.\n";
tp3_ex1_qu2="Tester la sym�trie du tableau T2.\n";
tp3_ex1_qu3="Ranger les %cl%cments du tableau T3 dans l�ordre inverse sans utiliser un tableau suppl%cmentaire.\n";
/*tp3_ex1_qu4="Effectuer k rotations circulaires � gauche d�un tableau T4.\n";
tp3_ex1_qu5="Ins�rer une valeur val (avec 'val' introduite � partir du clavier) � une position pos (avec 'pos'introduite � partir du clavier) dans un tableau T5.\n";
tp3_ex1_qu6="Construire un tableau V2 comportant les entiers pr�sents dans T6 et dans T7. (Sans r�p�tition).\n"
tp3_ex1_qu7="Construire un tableau V3 comportant les entiers pr�sents dans T6, mais absents dans T7. (Sans r�p�tition).\n"

tp3_ex2_qu1="Afficher tous les �l�ments de T8 qui sont sup�rieurs � A et afficher le plus petit des �l�ments qui sont sup�rieurs � A.\n"
tp3_ex2_qu2="Chercher et afficher l��l�ment qui appara�t le plus dans le tableau T9 de taille N, ainsi que son nombre d�occurrences.\n"
tp3_ex2_qu3="Cercher la longueur, l�indice de d�but et de fin du plus long plateau de tableau T10.\n"

tp3_ex3="Chercher et afficher les nombres sym�triques du tableau T11.\n"
tp3_ex4="D�placer tous les �l�ments nuls � la fin du tableau T12.\n"

tp4_ex1_qu1="Calculer et retourner la somme de la premi�re diagonale de la matrice M1.\n"
tp4_ex1_qu2="Calculer et retourner la somme du triangle inf�rieur droit de la matrice carrr�e M1 de taille N.\n"

tp4_ex2="V�rifier et afficher si la matrice M2 est sym�trique par rapport � la premi�re ou la seconde diagonale.\n"

tp4_ex3="Chercher et afficher tous les points cols de la matrice M3.\n NB:On appelle un point COL de la matrice l��l�ment qui est le plus petit de sa ligne et le plus grand de sa colonne.\n"

tp5_ex1_qu1="Trier le tableau T13 par ordre croissant en utilisant le principe de tri par s�lection.\n"
tp5_ex1_qu2="Trier le tableau T14 par ordre croissant en utilisant le principe de tri � bulles.\n"
tp5_ex1_qu3="Trier le tableau T15 par ordre croissant en utilisant le principe de tri par insertition.\n"

tp5_ex2_qu1="Chercher la premi�re position de la valeur val (avec 'val' introduite � partir du clavier) dans le tableau T16 en utilisant le principe de la recherche s�quentielle.\n"
tp5_ex2_qu2="Chercher la premi�re position de la valeur "val" (avec 'val' saisie � partir du clavier) dans le tableau T17 qui est tri� par ordre croissant en le principe de la recherche dichotomique.\n"
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
