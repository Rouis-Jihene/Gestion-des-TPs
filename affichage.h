#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED
#include <string.h>
#include <myconio.h>
#include <time.h>
#include "Entree_Sortie1.h"
//int wait_loop0 = 10000;
//int wait_loop1 = 6000;
///////////////1=é//////2=è/////3=ê////4=à///5=ç/////6='
tp2_ex1="Choisir dans un menu afin de r%c1soudre un probl%c2me sp%c1cifi%c1.";////è
tp2_ex2_1="Tester et afficher si un entier n est super premier et premier dans les";
tp2_ex2_2="deux sens ou super premier ou premier dans les deux sens ou non.";

tp3_ex1_qu1_1="Transf%c1rer les %c1l%c1ments de T1 dans V1 de telle sorte:";
tp3_ex1_qu1_2="* \t Les %c1l%c1ments du rang impair de T1 sont rang%c1s dans V1 en ordre inverse";
tp3_ex1_qu1_3="en commen%c5ant par la fin de T2.";////ç
tp3_ex1_qu1_4="* \tLes %c1l%c1ments du rang pair de T1 sont rang%c1s dans V1 dans le m%c3me ordre.";
tp3_ex1_qu2="Tester la sym%c1trie du tableau T2.";
tp3_ex1_qu3_1="Ranger les %c1l%c1ments du tableau T3 dans l%c6ordre inverse sans utiliser un tableau";////'
tp3_ex1_qu3_2="suppl%c1mentaire.";
tp3_ex1_qu4="Effectuer k rotations circulaires %c4 gauche d%c6un tableau T4.";
tp3_ex1_qu5_1="Ins%c1rer une valeur val (avec 'val' introduite %c4 partir du clavier) %c4 une";////à
tp3_ex1_qu5_2="position pos (avec %c6pos%c6 introduite %c4 partir du clavier) dans un";
tp3_ex1_qu5_3="tableau T5.";////à
///////////////1=é//////2=è/////3=ê////4=à///5=ç/////6='
tp3_ex1_qu6_1="Construire un tableau V2 comportant les entiers pr%c1sents dans T6 et dans T7";
tp3_ex1_qu6_2="(Sans r%c1p%c1tition).";
tp3_ex1_qu7_1="Construire un tableau V3 comportant les entiers pr%c1sents dans T6, mais absents";
tp3_ex1_qu7_2="dans T7 (Sans r%c1p%c1tition).";

tp3_ex2_qu1_1="Afficher tous les %c1l%c1ments de T8 qui sont sup%c1rieurs %c4 A et afficher le plus";////à
tp3_ex2_qu1_2="petit des %c1l%c1ments qui sont sup%c2rieurs %c4 A.";////à
tp3_ex2_qu2_1="Chercher et afficher l%c6%c1l%c1ment qui apparait le plus dans le tableau T9 de taille";//////'
tp3_ex2_qu2_2="N, ainsi que son nombre d’occurrences.";/////'
tp3_ex2_qu3_1="Chercher la longueur, l%c6indice de d%c1but et de fin du plus long plateau de";//////'
tp3_ex2_qu3_2="tableau T10.";

tp3_ex3="Chercher et afficher les nombres sym%c1triques du tableau T11.";
tp3_ex4="D%c1placer tous les %c1l%c1ments nuls %c4 la fin du tableau T12.";/////à

tp4_ex1_qu1="Calculer et retourner la somme de la premi%c2re diagonale de la matrice M1.";/////è
tp4_ex1_qu2_1="Calculer et retourner la somme du triangle inf%c1rieur droit de la matrice carr%c1";
tp4_ex1_qu2_2="M1 de taille N.";
///////////////1=é//////2=è/////3=ê////4=à///5=ç/////6='
tp4_ex2_1="V%c1rifier et afficher si la matrice M2 est sym%c1trique par rapport à la premi%c2re";//////è
tp4_ex2_2="ou la seconde diagonale.";

tp4_ex3_1="Chercher et afficher tous les points cols de la matrice M3.";
tp4_ex3_2="NB: On appelle un point COL de la matrice l%c6%c1l%c1ment qui est le plus petit de sa";///////'
tp4_ex3_3="ligne et le plus grand de sa colonne.";

tp5_ex1_qu1_1="Trier le tableau T13 par ordre croissant en utilisant le principe de tri par";
tp5_ex1_qu1_2="s%c1lection.";
tp5_ex1_qu2_1="Trier le tableau T14 par ordre croissant en utilisant le principe de tri %c4";///////à
tp5_ex1_qu2_2="bulles.";
tp5_ex1_qu3_1="Trier le tableau T15 par ordre croissant en utilisant le principe de tri par";
tp5_ex1_qu3_2="insertion.";

tp5_ex2_qu1_1="Chercher la premi%c2re position de la valeur val (avec %c6val%c6 introduite %c4 partir";////////è  à
tp5_ex2_qu1_2="du clavier) dans le tableau T16 en utilisant le principe de la recherche";
tp5_ex2_qu1_3="s%c1quentielle.";
tp5_ex2_qu2_1="Chercher la premi%c2re position de la valeur %c6val%c6 (avec %c6val%c6 saisie %c4 partir du";////////è  à
tp5_ex2_qu2_2="clavier) dans le tableau T17 qui est tri%c1 par ordre croissant en utilisant le";
tp5_ex2_qu2_3="principe de la recherche dichotomique.";

//void gr_fill_rect(int x, int y, int w, int h);
/*void wait( int seconds )
{   // this function needs to be finetuned for the specific microprocessor
    int i, j, k;
    for(i = 0; i < seconds; i++)
    {
        for(j = 0; j < wait_loop0; j++)
        {
            for(k = 0; k < wait_loop1; k++)
            {   // waste function, volatile makes sure it is not being optimized out by compiler
                int volatile t = 120 * j * i + k;
                t = t + 5;
            }
        }
    }
}*/
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
    printf("\n\n");

    objectif();
    textcolor(15);



}


void objectif()
{
    char str[16]="l'objectif est:";
    int i,j,k;

    textcolor(2);
    //delline(21);

    for(i=15;i>0;i--)
    {

        //delline(21);
        gotoxy(1,21);
        printf("               ");
        for(j=0;j<=15-i;j++)
        {
            gotoxy(i+j,21);
            printf("%c",str[j]);
        }
        wait(1);
    }


}
str="Transf%crer les %cl%cments de T1 dans V1 de telle sorte:";

void print_enonce1(char str[])
{
    int i;

    gotoxy(1,23);

    print_ligne_normal(str);
    gotoxy(1,23);
    faire_espaces(str,23);
    wait(4);
    gotoxy(1,23);
    print_ligne_normal(str);
    printf("\n \n \n");
    wait(4);
}


void print_enonce2(char str[],char str2[])
{
    gotoxy(1,23);
    print_ligne_normal(str);
    gotoxy(1,24);
    print_ligne_normal(str2);
    gotoxy(1,23);
    faire_espaces(str,23);
    gotoxy(1,24);
    faire_espaces2(str2,24);
    wait(4);
    gotoxy(1,23);
    print_ligne_normal(str);
    gotoxy(1,24);
    print_ligne_normal(str2);
    printf("\n \n \n");
    wait(4);
}

void print_enonce3(char str[],char str2[],char str3[])
{
    gotoxy(1,23);
    print_ligne_normal(str);
    gotoxy(1,24);
    print_ligne_normal(str2);
    gotoxy(1,25);
    print_ligne_normal(str3);
    gotoxy(1,23);
    faire_espaces(str,23);
    gotoxy(1,24);
    faire_espaces2(str2,24);
    gotoxy(1,25);
    faire_espaces(str3,25);
    wait(4);
    gotoxy(1,23);
    print_ligne_normal(str);
    gotoxy(1,24);
    print_ligne_normal(str2);
    gotoxy(1,25);
    print_ligne_normal(str3);
    printf("\n \n \n");
    wait(4);
}

void print_enonce4(char str[],char str2[],char str3[],char str4[])
{
    gotoxy(1,23);
    print_ligne_normal(str);
    gotoxy(1,24);
    print_ligne_normal(str2);
    gotoxy(1,25);
    print_ligne_normal(str3);
    gotoxy(1,26);
    print_ligne_normal(str4);
    gotoxy(1,23);
    faire_espaces(str,23);
    gotoxy(1,24);
    faire_espaces2(str2,24);
    gotoxy(1,25);
    faire_espaces(str3,25);
    gotoxy(1,26);
    faire_espaces2(str4,26);
    wait(4);
    gotoxy(1,23);
    print_ligne_normal(str);
    gotoxy(1,24);
    print_ligne_normal(str2);
    gotoxy(1,25);
    print_ligne_normal(str3);
    gotoxy(1,26);
    print_ligne_normal(str4);
    printf("\n \n \n");
    wait(4);
}

void print_enonce5(char str[],char str2[],char str3[],char str4[],char str5[])
{
    gotoxy(1,23);
    print_ligne_normal(str);
    gotoxy(1,24);
    print_ligne_normal(str2);
    gotoxy(1,25);
    print_ligne_normal(str3);
    gotoxy(1,26);
    print_ligne_normal(str4);
    gotoxy(1,27);
    print_ligne_normal(str5);
    gotoxy(1,23);
    faire_espaces(str,23);
    gotoxy(1,24);
    faire_espaces2(str2,24);
    gotoxy(1,25);
    faire_espaces(str3,25);
    gotoxy(1,26);
    faire_espaces2(str4,26);
    gotoxy(1,27);
    faire_espaces(str5,27);
    wait(4);
    gotoxy(1,23);
    print_ligne_normal(str);
    gotoxy(1,24);
    print_ligne_normal(str2);
    gotoxy(1,25);
    print_ligne_normal(str3);
    gotoxy(1,26);
    print_ligne_normal(str4);
    gotoxy(1,27);
    print_ligne_normal(str5);
    printf("\n \n \n");
    wait(4);
}
void print_ligne_normal(char str[])
{
    int i;
    for(i=0;i<strlen(str);i++)
    {///////////////1=é//////2=è/////3=ê////4=à///5=ç/////6='
        if(str[i]=='%'&&str[i+2]=='6')
        {
            printf("\x27");
            i+=2;
            continue;
        }
        if(str[i]=='%'&&str[i+2]=='5')
        {
            printf("%c",135);
            i+=2;
            continue;
        }
        if(str[i]=='%'&&str[i+2]=='4')
        {
            printf("%c",133);
            i+=2;
            continue;
        }
        if(str[i]=='%'&&str[i+2]=='3')
        {
            printf("%c",136);
            i+=2;
            continue;
        }
        if(str[i]=='%'&&str[i+2]=='1')
        {
            printf("%c",130);
            i+=2;
            continue;
        }
        if(str[i]=='%'&&str[i+2]=='2')
        {
            printf("%c",138);
            i+=2;
            continue;
        }
        printf("%c",str[i]);
    }
}

void faire_espaces(char str[],int ligne)
{
    int i;
    for(i=0;i<strlen(str);i+=8)
    {
        gotoxy(i,ligne);
        printf("    ");

    }
}
void faire_espaces2(char str[],int ligne)
{
    int i;
    for(i=4;i<strlen(str);i+=8)
    {
        gotoxy(i,ligne);
        printf("    ");

    }
}
#endif // AFFICHAGE_H_INCLUDED
