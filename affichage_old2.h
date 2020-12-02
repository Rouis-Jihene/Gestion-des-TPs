#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED
#include <string.h>
#include <myconio.h>
#include <time.h>
int wait_loop0 = 10000;
int wait_loop1 = 6000;
tp1_ex1_qu1="faire le remplissage puis l'affichage des element du tableau T13";
//void gr_fill_rect(int x, int y, int w, int h);
void wait( int seconds )
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
}
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
    textcolor(15);



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
}
void print_ligne_normal(char str[])
{
    int i;
    for(i=0;i<strlen(str);i++)
    {
        if(str[i]=='%')
        {
            printf("%c",130);
            i+=1;
            continue;
        }
        printf("%c",str[i]);
    }
}

void faire_espaces(char str[],int ligne)
{
    int i;
    for(i=0;i<strlen(str);i+=4)
    {
        gotoxy(i,ligne);
        printf("  ");

    }
}
void faire_espaces2(char str[],int ligne)
{
    int i;
    for(i=2;i<strlen(str);i+=4)
    {
        gotoxy(i,ligne);
        printf("  ");

    }
}
#endif // AFFICHAGE_H_INCLUDED
