#ifndef TXT_H_INCLUDED
#define TXT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verify_exist_t(char str[])
{
    FILE *fichier;
    long int n=0;

    fichier=fopen(str,"r");

    if(fichier!=NULL)
    {
        fscanf(fichier,"%d ",&n);
        if(n!=0)
            return 1;
        else
        {
            gotoxy(1,1);
            printf("%s est vide! Remplir le fichier svp par les fonctions de remplissage!",str);
            return 0;
        }
    }
    else
    {
        printf("%s n",str);printf("\x27");printf("existe pas! Cr%cer un fichier svp!",130);
        return 0;
    }
}

int verify_exist_txt(char str[])
{
    FILE *fichier;
    long int n=0;

    fichier=fopen(str,"r");

    if(fichier!=NULL)

        return 1;

    else
    {
        printf("%s n",str);printf("\x27");printf("existe pas! Cr%cer un fichier svp!",130);
        return 0;
    }
}
void ecrire_txt(long int t[], int n,char str[])
{
    FILE *fichier;
    int i;

    fichier=fopen(str,"w");//C:/Utilisateurs/kadhi/testbib/
    fprintf(fichier,"%d\n",n);

    for(i=0;i<n;i++)
    {
        fprintf(fichier,"%ld ",t[i]);
    }

    fclose(fichier);
}

void ecrire_txt_matrice_carre( int n,long int t[n][n],char str[])
{
    FILE *fichier;
    int i,j;

    fichier=fopen(str,"w");//C:/Utilisateurs/kadhi/testbib/
    fprintf(fichier,"%d\n",n);

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            fprintf(fichier,"%ld ",t[i][j]);
        }
        fprintf(fichier,"\n");
    }

    fclose(fichier);
}

void ecrire_txt_matrice_lc( int l,int c,long int t[l][c],char str[])
{
    FILE *fichier;
    int i,j;

    fichier=fopen(str,"w");//C:/Utilisateurs/kadhi/testbib/
    fprintf(fichier,"%d ",l);
    fprintf(fichier,"%d \n",c);

    for(i=0;i<l;i++)
    {
        for(j=0;j<c;j++)
        {
            fprintf(fichier,"%ld ",t[i][j]);
        }
        fprintf(fichier,"\n");
    }

    fclose(fichier);
}
int lire_n_txt(char str[])
{
    int n=0;
    FILE *fichier;
    fichier=fopen(str,"r");
    fscanf(fichier,"%d ",&n);

    if(n<1)
    {
        printf("%s n",str);printf("\x27");printf("est pas ecrit correctement!!");
        return 0;
    }
    fclose(fichier);
    return n;
}

int lire_l_txt(char str[])
{
    int n=0;
    FILE *fichier;
    fichier=fopen(str,"r");
    fscanf(fichier,"%d ",&n);
    if(n==0)
    {
        printf("%s n est pas ecrit correctement!!",str);
        return 0;
    }
    fclose(fichier);
    return n;
}
int lire_c_txt(char str[])
{
    int n=0,b;
    FILE *fichier;
    fichier=fopen(str,"r");
    fscanf(fichier,"%d ",&b);
    fscanf(fichier,"%d ",&n);

    if(n<1)
    {
        printf("%s n est pas ecrit correctement!!",str);
        return 0;
    }
    fclose(fichier);
    return n;
}
void lire_txt(long int t[],int n,char str[])
{
    FILE *fichier;
    int i;
    fichier=fopen(str,"r");

    fscanf(fichier,"%d\n",&n);

    for(i=0;i<n;i++)
        fscanf(fichier,"%ld ",t+i);


    fclose(fichier);
}

void lire_txt_matrice_carre(int n,long int t[n][n],char str[])
{
    FILE *fichier;
    int i,j;
    fichier=fopen(str,"r");

    fscanf(fichier,"%d\n",&n);

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(j==n-1)
                fscanf(fichier,"%ld \n",&t[i][j]);
            else
                fscanf(fichier,"%ld ",&t[i][j]);
        }

    }
    fclose(fichier);
}
void lire_txt_lc(int l,int c,long int t[l][c],char str[])
{
    FILE *fichier;
    int i,j,n;
    fichier=fopen(str,"r");

    fscanf(fichier,"%d ",&n);
    fscanf(fichier,"%d\n",&n);

    for(i=0;i<l;i++)
    {
        for(j=0;j<c;j++)
        {
            if(j==n-1)
                fscanf(fichier,"%ld \n",&t[i][j]);
            else
                fscanf(fichier,"%ld ",&t[i][j]);
        }

    }
    fclose(fichier);
}
void lire_pdf(char str[])
{ ShellExecute(NULL,"open",str,NULL,NULL,SW_SHOWNORMAL);}



void Affiche_Date()
{
    textcolor(4);
    gotoxy(10,4);
    printf(" Bienvenue a ************ ");
    SYSTEMTIME str_t;
    GetSystemTime(&str_t);
    gotoxy(10,6);
    printf(" Le %2d-%2d-%4d %c %d:%d:%d \n",str_t.wDay,str_t.wMonth,str_t.wYear,133,str_t.wHour,str_t.wMinute,str_t.wSecond);
    textcolor(15);
}

#endif // TXT_H_INCLUDED
