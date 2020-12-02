#ifndef TP3_H_INCLUDED
#define TP3_H_INCLUDED
#include "Entree_Sortie1.h"

void TRANSFERE(int T1[],int n,int V1[])
{
    int i,j,k;
    for(i=0,j=0,k=n-1;i<n;i++)
        if(i%2==1)
            {
                V1[k]=T1[i];
                k--;
            }
        else
            {
                V1[j]=T1[i];
                j++;
            }

}

int SYMETRIQUE_TAB(int n, int T2[])
{
    int i,test=1;

    for(i=0;i<n/2;i++)
        if(T2[i]!=T2[n-i-1])
            {
                test=0;
                break;
            }

    return test;
}

void INVERSE_TAB(int T3[],int n)
{
    int i,j,r=0;

    for(i=0,j=n-1;i<n/2+1,j>n/2-1;i++,j--)
        {
            r=T3[i];
            T3[i]=T3[j];
            T3[j]=r;
        }

}

void ROTATION_CIRCULAIRE(int t[],int n, int k)
{
    int i;

    for(i=0;i<k;i++)
        rotation(t,n);

}
void rotation(int t[],int n)
{
    int i,val;

    val=t[0];
    for(i=0;i<n-1;i++)
        t[i]=t[i+1];
    t[n-1]=val;
}



void INSERTION(int T5[],int n)
{
    int i,val,pos;
    val=SAISIE_VALEUR();
    do
        {
            pos=SAISIE_POSITION();
        }
    while(!(pos>-1&&pos<n));
    for(i=n;i>=pos;i--)
        T5[i+1]=T5[i];
    T5[pos]=val;

}

int EXISTE(int T[],int n,int x)
{
    int ok=0,i;

    for(i=0;i<n;i++)
        if(T[i]==x)
        {
            ok=1;
            break;
        }
    return ok;
}

void PRESENTS(int T6[],int T7[],int n1,int n2)
{
    int V2[50],nv=0,i;
    for(i=0;i<n1;i++)
        if(EXISTE(T7,n1,T6[i])==1 && EXISTE(V2,nv,T6[i])==0)
            {
                V2[nv]=T6[i];
                nv++;
            }
    AFFICHER1(V2,nv,"V2");
}

void ABSENTS(int T6[],int T7[],int n1,int n2)
{
    int V3[50],nv=0,i;
    for(i=0;i<n1;i++)
        if(EXISTE(T7,n1,T6[i])==0 && EXISTE(V3,nv,T6[i])==0)
            {
                V3[nv]=T6[i];
                nv++;
            }
    AFFICHER1(V3,nv,"V3");
}


void VAL_SUP_TAB( int T[],int n,int val)
{
	int i,t[50],nu=0;

	for(i=0;i<n;i++)
		if(T[i]>val)
		{
			t[nu]=T[i];
			nu++;
		}
    if(nu==1)
    {
        printf("\nil y a seulement une valeur sup%crieure %c val:\t %d",130,133,t[0]);
    }
    else if(nu>1)
        {
            printf("\nles valeur sup%crieur %c val sont:\n",130,133);
            for(i=0;i<nu;i++)
                printf("%d\t",t[i]);
            printf("\nla valeur la plus petites des valeurs sup%crieur est:\t %d",130,plus_petite_valeur(t,nu));
        }
        else
        printf("\nIl n y a pas de valeur sup%crieure %c val dans le tableau T8.",130,133);



}
int plus_petite_valeur(int t[],int n)
{
    int i,val=t[0];

    for(i=0;i<n;i++)
        if(t[i]<val)
            val=t[i];
    return val;
}
void occurence(int tab[],int taille)
{
	int i,occ=0,occfinal=0,number,j;

	for(i=0;i<taille;i++)
	{
		occ=0;
		for(j=0;j<taille;j++)
			if(tab[j]==tab[i])occ++;
		if(occ>occfinal)
		{
			number=tab[i];
			occfinal=occ;
		}
	}

	printf("\nle nombre est %d et son occurence est %d",number,occfinal);
}
 void PLATEAU(int T10[],int N)
 {
     int i,pos_deb=0,pos_fin,cp=1,long_max=1;
     for(i=0;i<N-1;i++)
        if(T10[i]-T10[i+1]==0)
        {
            cp++;
            if(cp>long_max)
            {
                long_max=cp;
                pos_deb=i-cp+1;
                pos_fin=i;
            }
        }
        else
            cp=1;
    if(long_max>1)
    {
        printf("\nLa longueur = %d, l",long_max);
        printf("\x27");
        printf("indice de d%cbut = %d et de fin = %d du plus long plateau de T10 \n",130,pos_deb+1,pos_fin+1);
    }
    else
        printf("\nIl n'existe pas du plateau");
}
void DEPLACER(int T12[],int n)
{
    int i,j,r;
    for(i=0;i<n;i++)
    {
        if(T12[i]==0)
        {
            j=i;
            do
            {
             r=T12[j];
             T12[j]=T12[j+1];
             T12[j+1]=r;
             j++;
            }while(j<n-1);
            --n;
            --i;
        }
    }

}


long int INVERSE(long int y)
{
    long int inv=0;
    while(y)
    {
        inv=inv*10+y%10;
        y=y/10;
    }
    return inv;
}

int SYMETRIQUE_VAL(long int x)
{
    int ok=0;
    if(INVERSE(x)==x)
        ok=1;
        return ok;
}
void SYM_TAB(long int T11[],int n)
{
    int i,nu=0;
    long int V[100];
    for(i=0;i<n;i++)
        if(SYMETRIQUE_VAL(T11[i])==1)
        {
            V[nu]=T11[i];
            nu++;
        }

    if(nu==0)
        printf("\nil n a pas de nombres sym%ctriques dans le tableau.",130);
    else if(nu==1)
            printf("\nil y a seulement un nombre sym%ctrique:\t %ld",130,V[0]);
        else
            AFFICHER1(V,nu,"les nombres sym%c1triques sont:");
}




#endif // TP3_H_INCLUDED
