#ifndef TP5_H_INCLUDED
#define TP5_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
void tp5_ex1_qu1(int t[],int n)
{
    int i,j;int aux;

    for(i=0;i<n-1;i++)
    {
        j=indice_de_plus_petit(t,n,i);
        if(t[i]>t[j])
        {
            aux=t[i];
            t[i]=t[j];
            t[j]=aux;

        }
    }
}

int indice_de_plus_petit(int t[],int n,int l)
{
    int i,min=t[l],indice=l;
    for(i=l;i<n;i++)
        if(t[i]<min)
        {
            min=t[i];
            indice=i;
        }
        return indice;
}

void tp5_ex1_qu2(long int t[],int n)
{
    int i,l=n;

    for(i=0;i<l-1;i++)
    {
        permutations(t,n,l);

    }

}

void permutations(long int t[],int n,int l)
{
    int i;long int aux;

    for(i=0;i<n-1;i++)
        if(t[i]>t[i+1])
        {
            aux=t[i+1];
            t[i+1]=t[i];
            t[i]=aux;
        }

}

void tp5_ex1_qu3(long int t[],int n)
{
    int i,l=1,indice;long int aux;

    if(t[0]>t[1])
    {
        aux=t[0];
        t[0]=t[1];
        t[1]=aux;
    }

    for(i=2;i<n;i++)
    {
        indice=indice_de_permutation(t,n,i,t[i]);
        if(indice!=i)
            inserer(t,n,indice,i);

    }
}

void inserer(long int t[],int n,int indice1,int indice2)
{
    int i;
    long int mem=t[indice2],aux;

    for(i=indice2;i>indice1;i--)
        t[i]=t[i-1];

    t[indice1]=mem;

}

int indice_de_permutation(long int t[],int n,int l,int val)
{
    int i,indice=l;

    for(i=0;i<l;i++)
        if(t[i]>val)
        {
            indice=i;
            break;
        }

        return indice;
}

void tp5_ex2_qu1(long int t[],int n)
{
    long int val;int i;

    printf("donner la valeur: ");
    scanf("%ld",&val);

    for(i=0;i<n;i++)
        if(t[i]==val)
            break;

    if(i<n)
        printf("la premiere position de la valeur %ld est %d",val,i+1);
    else
        {
            printf("la valeur %ld n",val);printf("\x27");printf("existe pas dans le tableau.\n");
        }

}

void tp5_ex2_qu2(long int t[],int n)
{
    long int val;int i=0,j=n,pos=-1,k=0;

    printf("donner la valeur: ");
    scanf("%ld",&val);

    while(k<n&&i<j)
    {
        if(t[(i+j)/2]>val)
            j=j/2;
        else if(t[(i+j)/2]<val)
            i=(i+j)/2;
            else
            {
                j=j/2;
                pos=(i+j)/2;
            }
        k++;
    }

    if(pos==-1)
    {
        printf("la valeur %ld n",val);printf("\x27");printf("existe pas dans le tableau.\n");
    }
    else
        printf("la position de la valeur %ld est %d",val,pos+1);

}

#endif // TP5_H_INCLUDED
