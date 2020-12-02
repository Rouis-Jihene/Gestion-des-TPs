#ifndef TP4_H_INCLUDED
#define TP4_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
void ex1_qu1(int n,int m[n][n])
{
    int i;long int somme=0;

    for(i=0;i<n;i++)
        somme+=m[i][i];

    printf("\n\nla somme de la premi%cre diagonal de la matrice est %ld",138,somme);

}

void ex1_qu2(int n,int m[n][n])
{
    int i,j;long int somme=0;

    for(i=0;i<n;i++)
        for(j=i;j<n;j++)
            somme+=m[j][i];

    printf("\n\nla somme du triangle inf%crieur droit de la matrice est %ld",130,somme);
}

void ex2(int n,int m[n][n])
{
    int i,j;int ok=1,ok2=1;

    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
             if(m[i][j]!=m[j][i])
             {
                 ok=0;
                 break;
             }
    if(ok==0)
        break;
    }

    if(ok==1)printf("la matrice est sym%ctrique par rapport au premier diagonal. \n",130);

    int lignefix=n-1;
    int colonnefix=0;
    int lignevar=n-1;
    int colonnevar=0;

    while(colonnefix<n&&lignefix>=0)
    {
        colonnevar=colonnefix;
        lignevar=lignefix;
        while (colonnevar<n&&lignevar>=0)
        {
            if(m[lignefix][colonnevar]!=m[lignevar][colonnefix])
            {
                ok2=0;
                break;
            }
            colonnevar++;
            lignevar--;
        }
        if(ok2==0)
            break;
        lignefix--;
        colonnefix++;
    }

    if(ok2==1)printf("\nla matrice est sym%ctrique par rapport au deuxi%cme diagonal.",130,138);

    if(ok==0&&ok2==0)
        {
            printf("la matrice n");printf("\x27");printf("est pas sym%ctrique",130);
        }
}

void ex3(int l,int c,long int m[l][c])
{
    int i,j,p=0;

    for(i=0;i<l;i++)
        for(j=0;j<c;j++)
            if(grand_de_colonne(i,j,l,c,m)==1&&petit_de_ligne(i,j,l,c,m)==1)
            {
                printf("\nM3(%d,%d)=%ld est COL.",i,j,m[i][j]);
                p++;
            }

    if(p==0)
        printf("\nil n y a pas de point COL dans ce matrice.\n");
}

int petit_de_ligne(int ligne,int colonne,int l,int c,long int m[l][c])
{
    int i,ok=1;long int min=m[ligne][colonne];

    for(i=0;i<c;i++)
        if(m[ligne][i]<min)
        {
            ok=0;
            break;
        }

    return ok;
}

int grand_de_colonne(int ligne,int colonne,int l,int c,long int m[l][c])
{
    int i,ok=1;long int max=m[ligne][colonne];

    for(i=0;i<l;i++)
        if(m[i][colonne]>max)
        {
            ok=0;
            break;
        }

    return ok;
}
#endif // TP4_H_INCLUDED
