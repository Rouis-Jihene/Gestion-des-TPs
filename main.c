#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Entree_Sortie1.h"
#include "txt.h"
#include "affichage.h"
#include "tp3.h"
#include "tp4.h"
#include "tp5.h"
#include "tp2.h"
LRESULT CALLBACK WindowProcedure(HWND,UINT,WPARAM,LPARAM);
void AddMenus(HWND);
void AddControls(HWND);
void loadImage();
HWND hLogo;
HMENU hMenu;
HBITMAP hLogoImage,hGenerateImage;
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow)
{
    WNDCLASSW wc={0};

    wc.hbrBackground= (HBRUSH) COLOR_WINDOW;
    wc.hCursor= LoadCursor(NULL,IDC_ARROW);
    wc.hInstance=hInst;
    wc.lpszClassName=L"MyWindowClass";
    wc.lpfnWndProc= WindowProcedure;

    if(!RegisterClassW(&wc))
        return -1;

    CreateWindowW(L"MyWindowClass",L"Mini-projet Jihen_Rouis",WS_OVERLAPPEDWINDOW | WS_VISIBLE,100,100,490,500,NULL,NULL,NULL,NULL);

    MSG msg={0};

    while(GetMessage(&msg,NULL,NULL,NULL))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
return 0;
}

LRESULT CALLBACK WindowProcedure(HWND hWnd,UINT msg,WPARAM wp,LPARAM lp)
{
    long int t[100],V1[100],t1[100];
    int m[100][100];
    int n,n1,l,c;
    int val;
    FILE *fichier;
    switch(msg)
    {
    case WM_COMMAND:
        switch(wp)
        {
        case 3:
            //DestroyWindow(hWnd);
            val=MessageBoxW(hWnd,L"Voulez-vous quitter?",L"Attention",MB_YESNO|MB_ICONEXCLAMATION);
            if(val==IDYES)
            DestroyWindow(hWnd);

            break;
        case 211:
            clrscr();
            tete("travaus pratique 2","exercice 1","");
            print_enonce1(tp2_ex1);
            tp2_ex1_();
            break;

        case 212:
            clrscr();
            tete("travaus pratique 2","exercice 2","");
            print_enonce2(tp2_ex2_1,tp2_ex2_2);
            TESTER_SUPER_PREMIER(SAISIE_VALEUR2());
            break;
        case 311:
            clrscr();
            if(verify_exist_t("fichiers.txt")==0)
                break;

            n=lire_n_txt("fichiers.txt");
            if(n==0)
                break;
            lire_txt(t,n,"T1.txt");
            TRANSFERE(t,n,V1);
            tete("travaus pratique 3","exercice 1: question 1","");
            print_enonce4(tp3_ex1_qu1_1,tp3_ex1_qu1_2,tp3_ex1_qu1_3,tp3_ex1_qu1_4);
            AFFICHER1(t,n,"T1");
            AFFICHER1(V1,n,"V1");
            break;
        case 312:
            clrscr();
            if(verify_exist_t("T2.txt")==0)
                break;
            n=lire_n_txt("T2.txt");
            if(n==0)
                break;
            lire_txt(t,n,"T2.txt");
            tete("travaus pratique 3","exercice 1: question 2","");
            print_enonce1(tp3_ex1_qu2);
            AFFICHER1(t,n,"T2");
            printf("\n\n\n%d",SYMETRIQUE_TAB(n,t));
            break;
        case 313:
            clrscr();
            if(verify_exist_t("T3.txt")==0)
                break;

            n=lire_n_txt("T3.txt");
            if(n==0)
                break;
            lire_txt(t,n,"T3.txt");
            tete("travaus pratique 3","exercice 1: question 3","");
            print_enonce2(tp3_ex1_qu3_1,tp3_ex1_qu3_2);
            AFFICHER1(t,n,"T3 avant");
            INVERSE_TAB(t,n);
            AFFICHER1(t,n,"T3");
            break;
        case 314:
            clrscr();
            if(verify_exist_t("T4.txt")==0)
                break;
            n=lire_n_txt("T4.txt");
            if(n==0)
                break;
            lire_txt(t,n,"T4.txt");
            tete("travaus pratique 3","exercice 1: question 4","");
            print_enonce1(tp3_ex1_qu4);
            AFFICHER1(t,n,"T4 avant");
            ROTATION_CIRCULAIRE(t,n,SAISIE_K(n));
            printf("\n");
            AFFICHER1(t,n,"T4");
            break;
        case 315:
            clrscr();
            if(verify_exist_t("T5.txt")==0)
                break;
            n=lire_n_txt("T5.txt");
            if(n==0)
                break;
            lire_txt(t,n,"T5.txt");
            tete("travaus pratique 3","exercice 1: question 5","");
            print_enonce3(tp3_ex1_qu5_1,tp3_ex1_qu5_2,tp3_ex1_qu5_3);
            AFFICHER1(t,n,"T5 avant");
            INSERTION(t,n);
            printf("\n");
            AFFICHER1(t,n+1,"T5");
            break;
        case 316:
            clrscr();
            if(verify_exist_t("T6.txt")==0)
                break;
            if(verify_exist_t("T7.txt")==0)
                break;
            n=lire_n_txt("T6.txt");
            if(n==0)
                break;
            lire_txt(t,n,"T6.txt");
            n1=lire_n_txt("T7.txt");
            if(n1==0)
                break;
            lire_txt(t1,n,"T7.txt");
            tete("travaus pratique 3","exercice 1: question 6","");
            print_enonce2(tp3_ex1_qu6_1,tp3_ex1_qu6_2);
            AFFICHER1(t,n,"T6");
            AFFICHER1(t1,n1,"T7");
            PRESENTS(t,t1,n,n1);
            break;
        case 317:
            clrscr();
            if(verify_exist_t("T6.txt")==0)
                break;
            if(verify_exist_t("T7.txt")==0)
                break;
            n=lire_n_txt("T6.txt");
            if(n==0)
                break;
            lire_txt(t,n,"T6.txt");
            n1=lire_n_txt("T7.txt");
            if(n1==0)
                break;
            lire_txt(t1,n,"T7.txt");
            tete("travaus pratique 3","exercice 1: question 7","");
            print_enonce2(tp3_ex1_qu7_1,tp3_ex1_qu7_2);
            AFFICHER1(t,n,"T6");
            AFFICHER1(t1,n1,"T7");
            ABSENTS(t,t1,n,n1);
            break;
        case 318:
            clrscr();
            if(verify_exist_t("T8.txt")==0)
                break;
            n=lire_n_txt("T8.txt");
            if(n==0)
                break;
            lire_txt(t,n,"T8.txt");
            tete("travaus pratique 3","exercice 2: question 1","");
            print_enonce2(tp3_ex2_qu1_1,tp3_ex2_qu1_2);
            AFFICHER1(t,n,"T8");
            VAL_SUP_TAB(t,n,SAISIE_VALEUR2());
            break;
        case 319:
            clrscr();
            if(verify_exist_t("T9.txt")==0)
                break;
            n=lire_n_txt("T9.txt");
            if(n==0)
                break;
            lire_txt(t,n,"T9.txt");
            tete("travaus pratique 3","exercice 2: question 2","");
            print_enonce2(tp3_ex2_qu2_1,tp3_ex2_qu2_2);
            AFFICHER1(t,n,"T9");
            occurence(t,n);
            break;
        case 320:
            clrscr();
            if(verify_exist_t("T10.txt")==0)
                break;
            n=lire_n_txt("T10.txt");
            if(n==0)
                break;
            lire_txt(t,n,"T10.txt");
            tete("travaus pratique 3","exercice 2: question 3","");
            print_enonce2(tp3_ex2_qu3_1,tp3_ex2_qu3_2);
            AFFICHER1(t,n,"T10");
            PLATEAU(t,n);
            break;
        case 321:
            clrscr();
            if(verify_exist_t("T11.txt")==0)
                break;
            n=lire_n_txt("T11.txt");
            if(n==0)
                break;
            lire_txt(t,n,"T11.txt");
            tete("travaus pratique 3","exercice 3","");
            print_enonce1(tp3_ex3);
            AFFICHER1(t,n,"T11");
            SYM_TAB(t,n);
            break;
        case 322:
            clrscr();
            if(verify_exist_t("T12.txt")==0)
                break;
            n=lire_n_txt("T12.txt");
            if(n==0)
                break;
            lire_txt(t,n,"T12.txt");
            tete("travaus pratique 3","exercice 4","");
            print_enonce1(tp3_ex4);
            AFFICHER1(t,n,"T12 avant");
            DEPLACER(t,n);
            AFFICHER1(t,n,"T12");
            break;
        case 411:
            clrscr();
            if(verify_exist_t("M1.txt")==0)
                break;
            n=lire_n_txt("M1.txt");
            if(n==0)
                break;
            lire_txt_matrice_carre(n,m,"M1.txt");
            tete("travaus pratique 4","exercice 1: question 1","");
            print_enonce1(tp4_ex1_qu1);
            AFFICHER3(n,m,"M1");
            ex1_qu1(n,m);
            break;
        case 412:
            clrscr();
            if(verify_exist_t("M1.txt")==0)
                break;
            n=lire_n_txt("M1.txt");
            if(n==0)
                break;
            lire_txt_matrice_carre(n,m,"M1.txt");
            tete("travaus pratique 4","exercice 1: question 2","");
            print_enonce2(tp4_ex1_qu2_1,tp4_ex1_qu2_2);
            AFFICHER3(n,m,"M1");
            ex1_qu2(n,m);
            break;
        case 413:
            clrscr();
            if(verify_exist_t("M2.txt")==0)
                break;
            n=lire_n_txt("M2.txt");
            if(n==0)
                break;
            lire_txt_matrice_carre(n,m,"M2.txt");
            tete("travaus pratique 4","exercice 2","");
            print_enonce2(tp4_ex2_1,tp4_ex2_2);
            AFFICHER3(n,m,"M2");
            ex2(n,m);
            break;
        case 414:
            clrscr();
            if(verify_exist_t("M3.txt")==0)
                break;
            l=lire_l_txt("M3.txt");
            if(l==0)
                break;
            c=lire_c_txt("M3.txt");
            if(c==0)
                break;
            lire_txt_lc(l,c,m,"M3.txt");
            tete("travaus pratique 4","exercice 3","");
            print_enonce3(tp4_ex3_1,tp4_ex3_2,tp4_ex3_3);
            AFFICHER4(l,c,m,"M3");
            ex3(l,c,m);
            break;
        case 511:
            clrscr();
            if(verify_exist_t("T13.txt")==0)
                break;
            n=lire_n_txt("T13.txt");
            if(n==0)
                break;
            lire_txt(t,n,"T13.txt");
            tete("travaus pratique 5","exercice 1: question 1","");
            print_enonce2(tp5_ex1_qu1_1,tp5_ex1_qu1_2);
            AFFICHER1(t,n,"T13 avant");
            tp5_ex1_qu1(t,n);
            AFFICHER1(t,n,"T13");
            break;
        case 512:
            clrscr();
            if(verify_exist_t("T14.txt")==0)
                break;
            n=lire_n_txt("T14.txt");
            if(n==0)
                break;
            lire_txt(t,n,"T14.txt");
            tete("travaus pratique 5","exercice 1: question 2","");
            print_enonce2(tp5_ex1_qu2_1,tp5_ex1_qu2_2);
            AFFICHER1(t,n,"T14 avant");
            tp5_ex1_qu2(t,n);
            AFFICHER1(t,n,"T14");
            break;
        case 513:
            clrscr();
            if(verify_exist_t("T15.txt")==0)
                break;
            n=lire_n_txt("T15.txt");
            if(n==0)
                break;
            lire_txt(t,n,"T15.txt");
            tete("travaus pratique 5","exercice 1: question 3","");
            print_enonce2(tp5_ex1_qu3_1,tp5_ex1_qu3_2);
            AFFICHER1(t,n,"T15 avant");
            tp5_ex1_qu3(t,n);
            AFFICHER1(t,n,"T15");
            break;
        case 514:
            clrscr();
            if(verify_exist_t("T16.txt")==0)
                break;
            n=lire_n_txt("T16.txt");
            if(n==0)
                break;
            lire_txt(t,n,"T16.txt");
            tete("travaus pratique 5","exercice 2: question 1","");
            print_enonce3(tp5_ex2_qu1_1,tp5_ex2_qu1_2,tp5_ex2_qu1_3);
            AFFICHER1(t,n,"T16");
            tp5_ex2_qu1(t,n);
            break;
        case 515:
            clrscr();
            if(verify_exist_t("T17.txt")==0)
                break;
            n=lire_n_txt("T17.txt");
            if(n==0)
                break;
            lire_txt(t,n,"T17.txt");
            tete("travaus pratique 5","exercice 2: question 2","");
            print_enonce3(tp5_ex2_qu2_1,tp5_ex2_qu2_2,tp5_ex2_qu2_3);
            AFFICHER1(t,n,"T17");
            tp5_ex2_qu2(t,n);
            break;
        case 611:
            clrscr();
            if(verify_exist_txt("T1.txt")==0)
                break;
            n=SAISIE_TAILLE();
            REMPLIR2(t,n);
            ecrire_txt(t,n,"T1.txt");
            printf("\nmerci.");
            break;
        case 612:
            clrscr();
            if(verify_exist_t("T1.txt")==0)
                break;
            n=lire_n_txt("T1.txt");
            if(n==0)
                break;
            lire_txt(t,n,"T1.txt");
            AFFICHER1(t,n,"T1");
            break;
        case 613:
            clrscr();
            if(verify_exist_txt("T2.txt")==0)
                break;
            n=SAISIE_TAILLE();
            REMPLIR1(t,n);
            ecrire_txt(t,n,"T2.txt");
            printf("\nmerci.");
            break;
        case 614:
            clrscr();
            if(verify_exist_t("T2.txt")==0)
                break;
            n=lire_n_txt("T2.txt");
            if(n==0)
                break;
            lire_txt(t,n,"T2.txt");
            AFFICHER1(t,n,"T2");
            break;
        case 615:
            clrscr();
            if(verify_exist_txt("T3.txt")==0)
                break;
            n=SAISIE_TAILLE();
            REMPLIR1(t,n);
            ecrire_txt(t,n,"T3.txt");
            printf("\nmerci.");
            break;
        case 616:
            clrscr();
            if(verify_exist_t("T3.txt")==0)
                break;
            n=lire_n_txt("T3.txt");
            if(n==0)
                break;
            lire_txt(t,n,"T3.txt");
            AFFICHER1(t,n,"T3");
            break;
        case 617:
            clrscr();
            if(verify_exist_txt("T4.txt")==0)
                break;
            n=SAISIE_TAILLE();
            REMPLIR1(t,n);
            ecrire_txt(t,n,"T4.txt");
            printf("\nmerci.");
            break;
        case 618:
            clrscr();
            if(verify_exist_t("T4.txt")==0)
                break;
            n=lire_n_txt("T4.txt");
            if(n==0)
                break;
            lire_txt(t,n,"T4.txt");
            AFFICHER1(t,n,"T4");
            break;
        case 619:
            clrscr();
            if(verify_exist_txt("T5.txt")==0)
                break;
            n=SAISIE_TAILLE();
            REMPLIR1(t,n);
            ecrire_txt(t,n,"T5.txt");
            printf("\nmerci.");
            break;
        case 620:
            clrscr();
            if(verify_exist_t("T5.txt")==0)
                break;
            n=lire_n_txt("T5.txt");
            if(n==0)
                break;
            lire_txt(t,n,"T5.txt");
            AFFICHER1(t,n,"T5");
            break;
        case 621:
            clrscr();
            if(verify_exist_txt("T6.txt")==0)
                break;
            n=SAISIE_TAILLE();
            REMPLIR1(t,n);
            ecrire_txt(t,n,"T6.txt");
            printf("\nmerci.");
            break;
        case 622:
            clrscr();
            if(verify_exist_t("T6.txt")==0)
                break;
            n=lire_n_txt("T6.txt");
            if(n==0)
                break;
            lire_txt(t,n,"T6.txt");
            AFFICHER1(t,n,"T6");
            break;
        case 623:
            clrscr();
            if(verify_exist_txt("T7.txt")==0)
                break;
            n=SAISIE_TAILLE();
            REMPLIR1(t,n);
            ecrire_txt(t,n,"T7.txt");
            printf("\nmerci.");
            break;
        case 624:
            clrscr();
            if(verify_exist_t("T7.txt")==0)
                break;
            n=lire_n_txt("T7.txt");
            if(n==0)
                break;
            lire_txt(t,n,"T7.txt");
            AFFICHER1(t,n,"T7");
            break;
        case 625:
            clrscr();
            if(verify_exist_txt("T8.txt")==0)
                break;
            n=SAISIE_TAILLE();
            REMPLIR1(t,n);
            ecrire_txt(t,n,"T8.txt");
            printf("\nmerci.");
            break;
        case 626:
            clrscr;
            if(verify_exist_t("T8.txt")==0)
                break;
            n=lire_n_txt("T8.txt");
            if(n==0)
                break;
            lire_txt(t,n,"T8.txt");
            AFFICHER1(t,n,"T8");
            break;
        case 627:
            clrscr();
            if(verify_exist_txt("T9.txt")==0)
                break;
            n=SAISIE_TAILLE();
            REMPLIR1(t,n);
            ecrire_txt(t,n,"T9.txt");
            printf("\nmerci.");
            break;
        case 628:
            clrscr();
            if(verify_exist_t("T9.txt")==0)
                break;
            n=lire_n_txt("T9.txt");
            if(n==0)
                break;
            lire_txt(t,n,"T9.txt");
            AFFICHER1(t,n,"T9");
            break;
        case 629:
            clrscr();
            if(verify_exist_txt("T10.txt")==0)
                break;
            n=SAISIE_TAILLE();
            REMPLIR1(t,n);
            ecrire_txt(t,n,"T10.txt");
            printf("\nmerci.");
            break;
        case 630:
            clrscr();
            if(verify_exist_t("T10.txt")==0)
                break;
            n=lire_n_txt("T10.txt");
            if(n==0)
                break;
            lire_txt(t,n,"T10.txt");
            AFFICHER1(t,n,"T10");
            break;
        case 631:
            clrscr();
            if(verify_exist_txt("T11.txt")==0)
                break;
            n=SAISIE_TAILLE5();
            REMPLIR3(t,n);
            ecrire_txt(t,n,"T11.txt");
            printf("\nmerci.");
            break;
        case 632:
            clrscr();
            if(verify_exist_t("T11.txt")==0)
                break;
            n=lire_n_txt("T11.txt");
            if(n==0)
                break;
            lire_txt(t,n,"T11.txt");
            AFFICHER1(t,n,"T11");
            break;
        case 633:
            clrscr();
            if(verify_exist_txt("T12.txt")==0)
                break;
            n=SAISIE_TAILLE5();
            REMPLIR1(t,n);
            ecrire_txt(t,n,"T12.txt");
            printf("\nmerci.");
            break;
        case 634:
            clrscr();
            if(verify_exist_t("T12.txt")==0)
                break;
            n=lire_n_txt("T12.txt");
            if(n==0)
                break;
            lire_txt(t,n,"T12.txt");
            AFFICHER1(t,n,"T12");
            break;
        case 635:
            clrscr();
            if(verify_exist_txt("T13.txt")==0)
                break;
            n=SAISIE_TAILLE();
            REMPLIR1(t,n);
            ecrire_txt(t,n,"T13.txt");
            printf("\nmerci.");
            break;
        case 636:
            clrscr();
            if(verify_exist_t("T13.txt")==0)
                break;
            n=lire_n_txt("T13.txt");
            if(n==0)
                break;
            lire_txt(t,n,"T13.txt");
            AFFICHER1(t,n,"T13");
            break;
        case 637:
            clrscr();
            if(verify_exist_txt("T14.txt")==0)
                break;
            n=SAISIE_TAILLE();
            REMPLIR1(t,n);
            ecrire_txt(t,n,"T14.txt");
            printf("\nmerci.");
            break;
        case 638:
            clrscr();
            if(verify_exist_t("T14.txt")==0)
                break;
            n=lire_n_txt("T14.txt");
            if(n==0)
                break;
            lire_txt(t,n,"T14.txt");
            AFFICHER1(t,n,"T14");
            break;
        case 639:
            clrscr();
            if(verify_exist_txt("T15.txt")==0)
                break;
            n=SAISIE_TAILLE();
            REMPLIR1(t,n);
            ecrire_txt(t,n,"T15.txt");
            printf("\nmerci.");
            break;
        case 640:
            clrscr();
            if(verify_exist_t("T15.txt")==0)
                break;
            n=lire_n_txt("T15.txt");
            if(n==0)
                break;
            lire_txt(t,n,"T15.txt");
            AFFICHER1(t,n,"T15");
            break;
        case 641:
            clrscr();
            if(verify_exist_txt("T16.txt")==0)
                break;
            n=SAISIE_TAILLE();
            REMPLIR1(t,n);
            ecrire_txt(t,n,"T16.txt");
            printf("\nmerci.");
            break;
        case 642:
            clrscr();
            if(verify_exist_t("T16.txt")==0)
                break;
            n=lire_n_txt("T16.txt");
            if(n==0)
                break;
            lire_txt(t,n,"T16.txt");
            AFFICHER1(t,n,"T16");
            break;
        case 643:
            clrscr();
            if(verify_exist_txt("T17.txt")==0)
                break;
            n=SAISIE_TAILLE();
            REMPLIR1(t,n);
            ecrire_txt(t,n,"T17.txt");
            printf("\nmerci.");
            break;
        case 644:
            clrscr();
            if(verify_exist_t("T17.txt")==0)
                break;
            n=lire_n_txt("T17.txt");
            if(n==0)
                break;
            lire_txt(t,n,"T17.txt");
            AFFICHER1(t,n,"T17");
            break;
        case 711:
            clrscr();
            if(verify_exist_txt("M1.txt")==0)
                break;
            n=SAISIE_TAILLE_MATRICE1();
            REMPLIR4(n,t);
            ecrire_txt_matrice_carre(n,t,"M1.txt");
            printf("\nmerci.");
            break;
        case 712:
            clrscr();
            if(verify_exist_t("M1.txt")==0)
                break;
            n=lire_n_txt("M1.txt");
            if(n==0)
                break;
            lire_txt_matrice_carre(n,t,"M1.txt");
            AFFICHER3(n,t,"M1");
            break;
        case 713:
            clrscr();
            if(verify_exist_txt("M2.txt")==0)
                break;
            n=SAISIE_TAILLE_MATRICE1();
            REMPLIR4(n,t);
            ecrire_txt_matrice_carre(n,t,"M2.txt");
            printf("\nmerci.");
            break;
        case 714:
            clrscr();
            if(verify_exist_t("M2.txt")==0)
                break;
            n=lire_n_txt("M2.txt");
            if(n==0)
                break;
            lire_txt_matrice_carre(n,t,"M2.txt");
            AFFICHER3(n,t,"M2");
            break;
        case 715:
            clrscr();
            if(verify_exist_txt("M3.txt")==0)
                break;
            l=SAISIE_TAILLE_MATRICE_L();
            c=SAISIE_TAILLE_MATRICE_C();
            REMPLIR5(l,c,t);
            ecrire_txt_matrice_lc(l,c,t,"M3.txt");
            printf("\nmerci.");
            break;
        case 716:
            clrscr();
            if(verify_exist_t("M3.txt")==0)
                break;
            l=lire_l_txt("M3.txt");
            if(l==0)
                break;
            c=lire_c_txt("M3.txt");
            if(c==0)
                break;
            lire_txt_lc(l,c,t,"M3.txt");
            AFFICHER4(l,c,t,"M3");
            break;

        case 1002:
            lire_pdf("TP2 GI.pdf");
            break;
        case 1003:
            lire_pdf("TP3 GI.pdf");
            break;
        case 1004:
            lire_pdf("TP4 GI.pdf");
            break;
        case 1005:
            lire_pdf("TP5 GI.pdf");
            break;
        case 1006:
            lire_pdf("Projet.pdf");
            break;

        }
        break;
    case WM_CREATE:
        loadImage();
        AddMenus(hWnd);
        AddControls(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProcW(hWnd,msg,wp,lp);
    }
}

void AddMenus(HWND hWnd)
{
    hMenu=CreateMenu();
    HMENU hFileMenu=CreateMenu();
    HMENU hFileMenu2=CreateMenu();
    HMENU hFileMenu3=CreateMenu();
    HMENU hFileMenu4=CreateMenu();
    HMENU hFileMenu5=CreateMenu();
    HMENU hFileMenu6=CreateMenu();
    HMENU hFileMenu7=CreateMenu();
    HMENU hFileMenu8=CreateMenu();
    HMENU hFileMenu9=CreateMenu();
    HMENU hSubMenu2_1=CreateMenu();
    HMENU hSubMenu2_2=CreateMenu();
    HMENU hSubMenu3_1=CreateMenu();
    HMENU hSubMenu4_1=CreateMenu();
    HMENU hSubMenu4_2=CreateMenu();
    HMENU hSubMenu5_1=CreateMenu();
    HMENU hSubMenu5_2=CreateMenu();
    HMENU hSubMenu5_3=CreateMenu();
    HMENU hSubMenu5_4=CreateMenu();
    HMENU hSubMenu5_5=CreateMenu();
    HMENU hSubMenu5_6=CreateMenu();
    HMENU hSubMenu5_7=CreateMenu();
    HMENU hSubMenu5_8=CreateMenu();
    HMENU hSubMenu5_9=CreateMenu();
    HMENU hSubMenu5_10=CreateMenu();
    HMENU hSubMenu5_11=CreateMenu();
    HMENU hSubMenu5_12=CreateMenu();
    HMENU hSubMenu5_13=CreateMenu();
    HMENU hSubMenu5_14=CreateMenu();
    HMENU hSubMenu5_15=CreateMenu();
    HMENU hSubMenu5_16=CreateMenu();
    HMENU hSubMenu5_17=CreateMenu();
    HMENU hSubMenu6_1=CreateMenu();
    HMENU hSubMenu6_2=CreateMenu();
    HMENU hSubMenu6_3=CreateMenu();


    ///TP2
    AppendMenu(hFileMenu,MF_STRING,211,"exercice 1");
    AppendMenu(hFileMenu,MF_STRING,212,"exercice 2");
    AppendMenu(hFileMenu,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hFileMenu,MF_STRING,3,"exit");

    ///TP3

    AppendMenu(hSubMenu2_1,MF_STRING,311,"TRANSFERE");
    AppendMenu(hSubMenu2_1,MF_STRING,312,"SYMETRIQUE");
    AppendMenu(hSubMenu2_1,MF_STRING,313,"INVERSE");
    AppendMenu(hSubMenu2_1,MF_STRING,314,"ROTATION CIRCULAIRE");
    AppendMenu(hSubMenu2_1,MF_STRING,315,"INSERTION");
    AppendMenu(hSubMenu2_1,MF_STRING,316,"PRESENTS");
    AppendMenu(hSubMenu2_1,MF_STRING,317,"ABSENTS");
    AppendMenu(hFileMenu2,MF_POPUP,(UINT_PTR)hSubMenu2_1,"exercice 1");
    AppendMenu(hSubMenu2_2,MF_STRING,318,"SUPERIEUR");
    AppendMenu(hSubMenu2_2,MF_STRING,319,"OCCURENCE");
    AppendMenu(hSubMenu2_2,MF_STRING,320,"PLATEAU");
    AppendMenu(hFileMenu2,MF_POPUP,(UINT_PTR)hSubMenu2_2,"exercice 2");
    AppendMenu(hFileMenu2,MF_STRING,321,"exercice 3");
    AppendMenu(hFileMenu2,MF_STRING,322,"exercice 4");
    AppendMenu(hFileMenu2,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hFileMenu2,MF_STRING,3,"exit");

    ///TP4
    AppendMenu(hSubMenu3_1,MF_STRING,411,"SOMME_DIAG1");
    AppendMenu(hSubMenu3_1,MF_STRING,412,"SOMME");
    AppendMenu(hFileMenu3,MF_POPUP,(UINT_PTR)hSubMenu3_1,"exercice 1");
    AppendMenu(hFileMenu3,MF_STRING,413,"exercice 2");
    AppendMenu(hFileMenu3,MF_STRING,414,"exercice 3");
    AppendMenu(hFileMenu3,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hFileMenu3,MF_STRING,3,"exit");

    ///TP5
    AppendMenu(hSubMenu4_1,MF_STRING,511,"TRIE PAR SELECTION");
    AppendMenu(hSubMenu4_1,MF_STRING,512,"TRIE A BULLES");
    AppendMenu(hSubMenu4_1,MF_STRING,513,"TRIE PAR INSERTION");
    AppendMenu(hFileMenu4,MF_POPUP,(UINT_PTR)hSubMenu4_1,"exercice 1");
    AppendMenu(hSubMenu4_2,MF_STRING,514,"RECHERCHE SEQUENTIELLE");
    AppendMenu(hSubMenu4_2,MF_STRING,515,"RECHERCHE DICHOTOMIQUE");
    AppendMenu(hFileMenu4,MF_POPUP,(UINT_PTR)hSubMenu4_2,"exercice 2");
    AppendMenu(hFileMenu4,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hFileMenu4,MF_STRING,3,"exit");

    ///les tableaux
    AppendMenu(hSubMenu5_1,MF_STRING,611,"remplissage");
    AppendMenu(hSubMenu5_1,MF_STRING,612,"lecture");
    AppendMenu(hFileMenu5,MF_POPUP,(UINT_PTR)hSubMenu5_1,"tableau 1");
    AppendMenu(hSubMenu5_2,MF_STRING,613,"remplissage");
    AppendMenu(hSubMenu5_2,MF_STRING,614,"lecture");
    AppendMenu(hFileMenu5,MF_POPUP,(UINT_PTR)hSubMenu5_2,"tableau 2");
    AppendMenu(hSubMenu5_3,MF_STRING,615,"remplissage");
    AppendMenu(hSubMenu5_3,MF_STRING,616,"lecture");
    AppendMenu(hFileMenu5,MF_POPUP,(UINT_PTR)hSubMenu5_3,"tableau 3");
    AppendMenu(hSubMenu5_4,MF_STRING,617,"remplissage");
    AppendMenu(hSubMenu5_4,MF_STRING,618,"lecture");
    AppendMenu(hFileMenu5,MF_POPUP,(UINT_PTR)hSubMenu5_4,"tableau 4");
    AppendMenu(hSubMenu5_5,MF_STRING,619,"remplissage");
    AppendMenu(hSubMenu5_5,MF_STRING,620,"lecture");
    AppendMenu(hFileMenu5,MF_POPUP,(UINT_PTR)hSubMenu5_5,"tableau 5");
    AppendMenu(hSubMenu5_6,MF_STRING,621,"remplissage");
    AppendMenu(hSubMenu5_6,MF_STRING,622,"lecture");
    AppendMenu(hFileMenu5,MF_POPUP,(UINT_PTR)hSubMenu5_6,"tableau 6");
    AppendMenu(hSubMenu5_7,MF_STRING,623,"remplissage");
    AppendMenu(hSubMenu5_7,MF_STRING,624,"lecture");
    AppendMenu(hFileMenu5,MF_POPUP,(UINT_PTR)hSubMenu5_7,"tableau 7");
    AppendMenu(hSubMenu5_8,MF_STRING,625,"remplissage");
    AppendMenu(hSubMenu5_8,MF_STRING,626,"lecture");
    AppendMenu(hFileMenu5,MF_POPUP,(UINT_PTR)hSubMenu5_8,"tableau 8");
    AppendMenu(hSubMenu5_9,MF_STRING,627,"remplissage");
    AppendMenu(hSubMenu5_9,MF_STRING,628,"lecture");
    AppendMenu(hFileMenu5,MF_POPUP,(UINT_PTR)hSubMenu5_9,"tableau 9");
    AppendMenu(hSubMenu5_10,MF_STRING,629,"remplissage");
    AppendMenu(hSubMenu5_10,MF_STRING,630,"lecture");
    AppendMenu(hFileMenu5,MF_POPUP,(UINT_PTR)hSubMenu5_10,"tableau 10");
    AppendMenu(hSubMenu5_11,MF_STRING,631,"remplissage");
    AppendMenu(hSubMenu5_11,MF_STRING,632,"lecture");
    AppendMenu(hFileMenu5,MF_POPUP,(UINT_PTR)hSubMenu5_11,"tableau 11");
    AppendMenu(hSubMenu5_12,MF_STRING,633,"remplissage");
    AppendMenu(hSubMenu5_12,MF_STRING,634,"lecture");
    AppendMenu(hFileMenu5,MF_POPUP,(UINT_PTR)hSubMenu5_12,"tableau 12");
    AppendMenu(hSubMenu5_13,MF_STRING,635,"remplissage");
    AppendMenu(hSubMenu5_13,MF_STRING,636,"lecture");
    AppendMenu(hFileMenu5,MF_POPUP,(UINT_PTR)hSubMenu5_13,"tableau 13");
    AppendMenu(hSubMenu5_14,MF_STRING,637,"remplissage");
    AppendMenu(hSubMenu5_14,MF_STRING,638,"lecture");
    AppendMenu(hFileMenu5,MF_POPUP,(UINT_PTR)hSubMenu5_14,"tableau 14");
    AppendMenu(hSubMenu5_15,MF_STRING,639,"remplissage");
    AppendMenu(hSubMenu5_15,MF_STRING,640,"lecture");
    AppendMenu(hFileMenu5,MF_POPUP,(UINT_PTR)hSubMenu5_15,"tableau 15");
    AppendMenu(hSubMenu5_16,MF_STRING,641,"remplissage");
    AppendMenu(hSubMenu5_16,MF_STRING,642,"lecture");
    AppendMenu(hFileMenu5,MF_POPUP,(UINT_PTR)hSubMenu5_16,"tableau 16");
    AppendMenu(hSubMenu5_17,MF_STRING,643,"remplissage");
    AppendMenu(hSubMenu5_17,MF_STRING,644,"lecture");
    AppendMenu(hFileMenu5,MF_POPUP,(UINT_PTR)hSubMenu5_17,"tableau 17");
    AppendMenu(hFileMenu5,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hFileMenu5,MF_STRING,3,"exit");


    ///les matrices
    AppendMenu(hSubMenu6_1,MF_STRING,711,"remplissage");
    AppendMenu(hSubMenu6_1,MF_STRING,712,"lecture");
    AppendMenu(hFileMenu6,MF_POPUP,(UINT_PTR)hSubMenu6_1,"matrice 1");
    AppendMenu(hSubMenu6_2,MF_STRING,713,"remplissage");
    AppendMenu(hSubMenu6_2,MF_STRING,714,"lecture");
    AppendMenu(hFileMenu6,MF_POPUP,(UINT_PTR)hSubMenu6_2,"matrice 2");
    AppendMenu(hSubMenu6_3,MF_STRING,715,"remplissage");
    AppendMenu(hSubMenu6_3,MF_STRING,716,"lecture");
    AppendMenu(hFileMenu6,MF_POPUP,(UINT_PTR)hSubMenu6_3,"matrice 3");
    AppendMenu(hFileMenu6,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hFileMenu6,MF_STRING,3,"exit");


    ///pdf
    AppendMenu(hFileMenu8,MF_STRING,1002,"TP2");
    AppendMenu(hFileMenu8,MF_STRING,1003,"TP3");
    AppendMenu(hFileMenu8,MF_STRING,1004,"TP4");
    AppendMenu(hFileMenu8,MF_STRING,1005,"TP5");
    AppendMenu(hFileMenu8,MF_STRING,1006,"mini projet");
    AppendMenu(hFileMenu8,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hFileMenu8,MF_STRING,3,"exit");

    ///menu principal
    AppendMenu(hMenu,MF_POPUP,(UINT_PTR) hFileMenu,"TP2");
    AppendMenu(hMenu,MF_POPUP,(UINT_PTR) hFileMenu2,"TP3");
    AppendMenu(hMenu,MF_POPUP,(UINT_PTR) hFileMenu3,"TP4");
    AppendMenu(hMenu,MF_POPUP,(UINT_PTR) hFileMenu4,"TP5");
    AppendMenu(hMenu,MF_POPUP,(UINT_PTR) hFileMenu5,"les tableaux");
    AppendMenu(hMenu,MF_POPUP,(UINT_PTR) hFileMenu6,"les matrices");
    AppendMenu(hMenu,MF_POPUP,(UINT_PTR) hFileMenu7,"examen et DS");
    AppendMenu(hMenu,MF_POPUP,(UINT_PTR) hFileMenu8,"pdf");
    //AppendMenu(hMenu,MF_POPUP,(UINT_PTR) hFileMenu9,"rapport");

    SetMenu(hWnd,hMenu);
}

void AddControls(HWND hWnd)
{
    hLogo=CreateWindowW(L"static",NULL,WS_VISIBLE | WS_CHILD | SS_BITMAP,0,0,50,50,hWnd,NULL,NULL,NULL);
    SendMessageW(hLogo,STM_SETIMAGE,IMAGE_BITMAP,(LPARAM) hLogoImage);
}
void loadImage()
{
    hLogoImage=(HBITMAP)LoadImageW(NULL,L"poly.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
}

