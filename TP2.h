#ifndef TP2_H_INCLUDED
#define TP2_H_INCLUDED
#include "Entree_Sortie1.h"
#include <stdio.h>
#include <stdlib.h>
int menu ()
{
    int choix;
    printf("\t ****Menu Generale**** \n");
    printf("\t\t-1- Probleme 1 \n");
    printf("\t\t-2- Probleme 2 \n");
    printf("\t\t-3- Probleme 3 \n");
    printf("\t\t-4- Quiter le programme \n");
    do
    {
      printf("donner le choix:");
      scanf("%ld",&choix);
    }
    while (!(choix>=1&&choix<=4));
    return choix;
}
long int saisie ()
{
    long int n;
    do
    {
        printf("entrer un entier:");
        scanf("%ld",&n);
    }
    while (!(n>0));
    return n;
}
long int carre (long int n)
{
    long int s,i;
    for (s=0,i=1;i<=2*n;i=i+2)
        s+=i;
    return s;
}
void multiparfait(long int n)
{
    long int s,i;
    for (s=n+1,i=2;i<=n/2;i++)
    if (n%i==0)
        s+=i;
    if (s%n==0)
        printf("%ld est multiparfait \n",n);
    else
        printf("%ld n'est pas multiparfait \n",n);


}
void divisible_13(long int n)
{
    int u,ok=0;
    long int d,x;
    x=n;
    do
    {
        u=n%10;
        d=n/10;
        n=d+4*u;
        if ((n==13)||(n==26)||(n==39))
        {
            ok=1;
            break;
        }
    }
    while (n>=10);
    if (ok)
        printf("%ld est divisible par 13 \n",x);
    else
        printf("%ld n'est pas divisible par 13 \n",x);
}

void tp2_ex1_()
{
long int n;
int choix ;

do
{
    choix=menu();
if (choix!=4)
    n=saisie();
switch(choix)
{
case 1: printf("le carre de %ld=%ld ",n,carre(n));
        break;
case 2:multiparfait(n);
break;
case 3:divisible_13(n);
break;
case 4:printf("\n fin du programme \n");
break;
default:
    break;
}
getch();
}
while(choix!=4);
printf("\nbye bye.");

}

long int CARRE(long int N)
{
    long int S;
    int i;
    for (S=0,i=1;i<=2*N;i=i+2)
        S+=i;

    return S;
}

void MULTIPARFAIT(long int N)
{
    long int S=0,i;

    for(S=1+N,i=2;i<=N/2;i++)
        if (N%i==0)
            S=S+i;
    if (S%N==0)
        printf("%ld est un nombre multiparfait",N);
    else
        printf("%ld n'est pas un nombre multiparfait",N);
}

void DIVISIBLE_13(long int N)
{
    int u,ok=0;
    long int d,X;
    X=N;

    do
    {
        u=N%10;
        d=N/10;
        N=d+4*u;
        if (N==13||N==26||N==39)
            {
                ok=1;
                break;
            }
    }while(N>=10);

    if (ok==1)
        printf("%ld est divisible par 13",X);
    if (ok!=1)
        printf("%ld n'est pas divisible par 13",X);
}

int PREMIER(long int n)
{
    int i,test;

    if (n==1)
        test=0;
    else
        for(test=1,i=2;i<=2;i++)
            if (n%i==0)
                {
                    test=0;
                    break;
                }

    return test;
}

long int INVERSER_LONG_INT(long int n)
{
    long int inv=0;
    while(n)
    {
        inv=inv*10+n%10;
        n=n/10;
    }
    return inv;
}
int SUPER_PREMIER(long int n)
{
    int test=1;

    while(n)
        {
            if (PREMIER(n)==0)
                {
                    test=0;
                    break;
                }
        n=n/10;
        }
    return test;
}

void TESTER_SUPER_PREMIER(long int n)
{
    int y;
    if (PREMIER(n))
        {
            y=INVERSER_LONG_INT(n);
            if(SUPER_PREMIER(n)&&PREMIER(y))
                printf("\n%ld est super premier et premier dans les seux sens.",n);
            else
                if (PREMIER(y))
                    printf("\n%ld est premier dans les deux sens.",n);
                else if(SUPER_PREMIER(n))
                        printf("\n%ld est super premier.",n);
                    else
                        printf("\n%ld est ni super premier ni premier dans les deux sens.",n);
        }
    else
        printf("\n%ld n'est pas premier",n);

}

#endif // TP2_H_INCLUDED
