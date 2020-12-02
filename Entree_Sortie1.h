#ifndef ENTREE_SORTIE_H_INCLUDED
#define ENTREE_SORTIE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "affichage.h"
int wait_loop0 = 10000;
int wait_loop1 = 6000;

void wait( int seconds )
{
    int i, j, k;
    for(i = 0; i < seconds; i++)
    {
        for(j = 0; j < wait_loop0; j++)
        {
            for(k = 0; k < wait_loop1; k++)
            {
                int volatile t = 120 * j * i + k;
                t = t + 5;
            }
        }
    }
}
int SAISIE_TAILLE()
{
    int n;

    do
    {
        printf("saisie la taille du tableau:\t");
        scanf("%d",&n);
    }while (!(n>1&&n<=50));

    return n;

}
int SAISIE_TAILLE5()
{
    int n;

    do
    {
        printf("saisie la taille du tableau:\t");
        scanf("%d",&n);
    }while (!(n>=5&&n<=50));

    return n;

}
int SAISIE_K(int l)
{
    int n;

    do
    {
        printf("saisie K:\t");
        scanf("%d",&n);
    }while (!(n>0&&n<l));

    return n;

}
int SAISIE_VALEUR()
{
    int val;
    printf("Entrer la valeur %c ajouter:\t",133);
    scanf("%d",&val);
    return val;
}
int SAISIE_VALEUR2()
{
    int val;
    printf("\n\nEntrer la valeur:\t");
    scanf("%d",&val);
    return val;
}
long int SAISIE_ENTIER()
{
    long int n;

    do
    {
        printf("Entrer un entier N: \t");
        scanf("%ld",&n);
    }while (!(n>0));

    return n;

}
int SAISIE_POSITION()
{
    int position;
    printf("Entrer une position:\t");
    scanf("%d",&position);
    return position;
}
int SAISIE_TAILLE_MATRICE1()
{
    int n;

    do
    {
        printf("saisie la taille du matrice:\t");
        scanf("%d",&n);
    }while (!(n>1&&n<=20));

    return n;

}

int SAISIE_TAILLE_MATRICE_L()
{
    int n;

    do
    {
        printf("saisie nombre de ligne du matrice:\t");
        scanf("%d",&n);
    }while (!(n>1&&n<=20));

    return n;

}

int SAISIE_TAILLE_MATRICE_C()
{
    int n;

    do
    {
        printf("saisie nombre de colonne du matrice:\t");
        scanf("%d",&n);
    }while (!(n>1&&n<=20));

    return n;

}
void REMPLIR1(long int t[],int n )
{
    int i;

    for(i=0;i<n;i++)
    {
        printf("T[%d]= ",i+1);
        scanf("%ld",&t[i]);
    }
}

void REMPLIR2(int t[],int n )
{
    int i;

    for(i=0;i<n;i++)
    {
        do
        {
            printf("T[%d]= ",i+1);
            scanf("%d",&t[i]);
        }while(!(t[i]>=0));

    }
}

void REMPLIR3(long int t[],int n )
{
    int i;

    for(i=0;i<n;i++)
    {
        do
        {
            printf("T[%d]= ",i+1);
            scanf("%ld",&t[i]);
        }while(!(t[i]>100));

    }
}

void REMPLIR4(int n ,long int T[n][n])
{
    int i,j;

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            printf("M[%d][%d]= ",i+1,j+1);
            scanf("%ld",&T[i][j]);
        }
}

void REMPLIR5(int l, int c,long int t[l][c] )
{
    int i,j;

    for(i=0;i<l;i++)
        for(j=0;j<c;j++)
        {
            printf("M[%d][%d]= ",i+1,j+1);
            scanf("%ld",&t[i][j]);
        }
}

void AFFICHER1(long int t[],int n,char str[] )
{
    int i;
    print_ligne_normal(str);
    printf("\n \n");
    wait(1);
    for(i=0;i<n;i++)
        printf("%ld\t",t[i]);

    printf(" \n \n \n");
    wait(4);

}

void AFFICHER2(long int t[],int n )
{
    int i;

    for(i=0;i<n;i++)
        printf("%ld\t",t[i]);
    wait(4);
}

void AFFICHER3(int n ,long int t[n][n],char str[])
{
    int i,j;

    printf("\n\n");
    printf(str);
    printf("\n\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%ld\t",t[i][j]);
        printf("\n");
    }
    wait(4);
}

void AFFICHER4(int l, int c,long int t[l][c],char str[] )
{
    int i,j;

    printf("\n\n");
    printf(str);
    printf("\n\n");

    for(i=0;i<l;i++)
    {
        for(j=0;j<c;j++)
            printf("%ld\t",t[i][j]);
        printf("\n");
    }
    wait(4);
}

#endif // ENTREE_SORTIE_H_INCLUDED
