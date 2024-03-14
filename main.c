#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "modeleTAB_COMPARATIF.h"


int main()
{
    //Declaration des variables

    int *t,*tAUTO, *t_copy;    //t : tableau   t_copy : tableau pour copier t
    int N;         //taille des tableaux
    bool test ;         //pour tester si le tableau est cree
    char choix;         //pour stocker le choix d'utilisateur
    bool stop = false;  //stop = True si le choix = q (Quitter)

    double matrice[6][10];  //une ligne pour stocker les tailles des tableaux et 5 lignes pour stocker le temps dexecution des 10 algorithmes
    double matriceAUTO[6][10];  //une ligne pour stocker les tailles des tableaux et 5 lignes pour stocker le temps dexecution des 5 algorithmes
    int cpt_lignes;         //permet de remplire la matrice
    int cpt_colonnes = 0;   //permet de remplire la matrice

    clock_t debut , fin;    //pour mesurer le temps

    //remplire la matrice avec des (-1)
    //(au moment d'affichage on peut savoir si le trie n'est pas effectuée si matrice[x][x] = -1 )
    int l,c;
    for(l=0; l<6; l++)
    {
        for(c=0; c<10; c++)
        matrice[l][c] = -1;
    }

    do
    {
        clrScrean() ;   //effacer la console
        menu();       //entete du programme

        printf("CHOIX = "); //message pour l'utulisateur
        scanf(" %c",&choix);    //lire le choix

        bool testChoix = true;  //reçois faux quand le choix différent que {1,2,3,4,5,6,7,i,q}

        switch(choix)
        {
            case '1' :  //cree un tableau
                        clrScrean();       entete();
                        printf("1. Cr%cer un tableau\n",130);
                        printf("--------------------\n\n");

                        printf("Taille du tableau = ") ;    //demender la taille
                        scanf("%d", &N) ;  //lire la taille

                        t = malloc(N*sizeof(int)); //allocation dynamique du tableau t
                        t_copy = malloc(N*sizeof(int));    //allocation dynamique du tableau t_copy

                        matrice [0][cpt_colonnes] = N ;    //stocker la taille du tableau dans la matrice
                        cpt_colonnes = cpt_colonnes + 1;    //incrementer le compteur colonnes

                        genTab(t , N); //appelle de la procedure genTab
                        printf("\n>>La creation du tableau est termin%c\n",130);

                        if(N<=50)    afficher(t, N);

                        test = true ;   //test (cration du tableau) reçoit

                        break;

            case '2' :  //trie a bulles [commentaires similaire pour les autres]
                        clrScrean();    entete();
                        printf("2. Trie %c Bulles\n",133);
                        printf("-----------------\n\n");

                        if(test == false)   //aucun tableau est cree
                            printf(">>Erreur Veuillez cr%cer un tableau !\n",130);
                        else
                        {
                            copyTab (t, t_copy, N);    //appelle a la procedure copyTab (copier le tableau t dans t_copy)

                            debut = clock ();   //debut de calcule du temps
                            triBulles(t_copy, N) ; //appelle a la procedure triBulles
                            fin = clock (); //fin du calcule du temps

                            puts(">>Trie terminer\n");

                            if(N<=50)    afficher(t_copy, N);

                            printf("\nLe temps d'ex%ccution = %.3f s\n",130,(double)(fin - debut)/CLOCKS_PER_SEC);

                            cpt_lignes = 1; //la premier ligne de la matrice est reserver au trie a bulles
                            matrice [cpt_lignes][cpt_colonnes - 1] = ((double)(fin - debut)/CLOCKS_PER_SEC);    //remplire le la matrice avec le temps dexecution
                        }
                        break;

            case '3' :  //trie par selection
                        clrScrean();    entete();
                        printf("3. Trie par S%clection\n",130);
                        printf("----------------------\n\n");

                        if(test == false)
                            printf(">>Erreur Veuillez cr%cer un tableau !\n",130);
                        else
                        {
                            copyTab (t, t_copy, N);

                            debut = clock ();
                            triSelection(t_copy, N) ;
                            fin = clock ();

                            puts(">>Trie terminer");

                            if(N<=50)    afficher(t_copy, N);

                            printf("\nLe temps d'ex%ccution = %.3f s\n",130,(double)(fin - debut)/CLOCKS_PER_SEC);

                            cpt_lignes = 2;
                            matrice [cpt_lignes][cpt_colonnes - 1] = ((double)(fin - debut)/CLOCKS_PER_SEC);
                        }
                        break;

            case '4' :  //trie par insertion
                        clrScrean();    entete();
                        printf("4. Trie par Insertion\n");
                        printf("---------------------\n\n");

                        if(test == false)
                            printf(">>Erreur Veuillez cr%cer un tableau !\n",130);
                        else
                        {
                            copyTab (t, t_copy, N);

                            debut = clock ();
                            triInsertion(t_copy, N) ;
                            fin = clock ();

                            puts(">>Trie terminer");

                            if(N<=50)    afficher(t_copy, N);

                            printf("\nLe temps d'ex%ccution = %.3f s\n",130,(double)(fin - debut)/CLOCKS_PER_SEC);

                            cpt_lignes = 3;
                            matrice [cpt_lignes][cpt_colonnes - 1] = ((double)(fin - debut)/CLOCKS_PER_SEC);

                        }
                        break;

            case '5' :  //trie rapid
                        clrScrean();    entete();
                        printf("5. Trie Rapide \n");
                        printf("---------------\n\n");

                        if(test == false)
                            printf(">>Erreur Veuillez cr%cer un tableau !\n",130);
                        else
                        {
                            copyTab (t, t_copy, N);

                            debut = clock ();
                            triRapide(t_copy, 0, N);
                            fin = clock ();

                            puts(">>Trie terminer");

                            if(N<=50)    afficher(t_copy, N);

                            printf("\nLe temps d'ex%ccution = %.3f s\n",130,(double)(fin - debut)/CLOCKS_PER_SEC);

                            cpt_lignes = 4;
                            matrice [cpt_lignes][cpt_colonnes - 1] = ((double)(fin - debut)/CLOCKS_PER_SEC);

                        }
                        break;

            case '6' :  //trie par fusion
                        clrScrean();    entete();
                        printf("6. Trie par Fusion\n\n");
                        printf("------------------\n\n");

                        if(test == false)
                            printf(">>Erreur Veuillez cr%cer un tableau !\n",130);
                        else
                        {
                            copyTab (t, t_copy, N);

                            debut = clock ();
                            triFusion(t_copy, 0, N - 1);
                            fin = clock ();

                            puts(">>Trie terminer");

                            if(N<=50)    afficher(t_copy, N);

                            printf("\nLe temps d'ex%ccution = %.3f s\n",130,(double)(fin - debut)/CLOCKS_PER_SEC);

                            cpt_lignes = 5;
                            matrice [cpt_lignes][cpt_colonnes - 1] = ((double)(fin - debut)/CLOCKS_PER_SEC);

                        }
                        break;

            case '7' :  //afficher le tableau comparatif
                        clrScrean();    entete();
                        printf("7. Tableau comparatif(Manuelle)\n");
                        printf("-------------------------------\n\n");

                        tabCOMPARATIF(matrice, cpt_colonnes);    //appelle a la procedure tabCOMPARATIF
                        break;

            case '8' :  //afficher le tableau comparatif
                        clrScrean();    entete();
                        printf("8. Tableau comparatif(Automatique)\n");
                        printf("----------------------------------\n\n");

                        printf("Les algorithms sont en cours d'ex%ccution ... ",130);
                        int i;
                        int n = 5000;

                        for(i=0; i<4; i++)
                        {
                            tAUTO = malloc(n*sizeof(int)); //allocation dynamique du tableau t
                            t_copy = malloc(n*sizeof(int));    //allocation dynamique du tableau t_copy
                            genTab(tAUTO , n); //appelle de la procedure genTab

                            matriceAUTO[0][i] = n;

                            copyTab (tAUTO, t_copy, n);
                            debut = clock ();
                            triBulles(t_copy, n) ; //appelle a la procedure triBulles
                            fin = clock();
                            matriceAUTO [1][i] = ((double)(fin - debut)/CLOCKS_PER_SEC);

                            copyTab (tAUTO, t_copy, n);
                            debut = clock ();
                            triSelection(t_copy, n) ; //appelle a la procedure triBulles
                            fin = clock();
                            matriceAUTO [2][i] = ((double)(fin - debut)/CLOCKS_PER_SEC);

                            copyTab (tAUTO, t_copy, n);
                            debut = clock ();
                            triInsertion(t_copy, n) ; //appelle a la procedure triBulles
                            fin = clock();
                            matriceAUTO [3][i] = ((double)(fin - debut)/CLOCKS_PER_SEC);

                            copyTab (tAUTO, t_copy, n);
                            debut = clock ();
                            triRapide(t_copy, 0, n); //appelle a la procedure triBulles
                            fin = clock();
                            matriceAUTO [4][i] = ((double)(fin - debut)/CLOCKS_PER_SEC);

                            copyTab (tAUTO, t_copy, n);
                            debut = clock ();
                            triFusion(t_copy, 0, n - 1); //appelle a la procedure triBulles
                            fin = clock();
                            matriceAUTO [5][i] = ((double)(fin - debut)/CLOCKS_PER_SEC);

                            n = n+n;
                        }
                        clrScrean();    entete();
                        printf("8. Tableau comparatif(Automatique)\n");
                        printf("----------------------------------\n\n");
                        tabCOMPARATIFAUTO(matriceAUTO);// appel à la procedure tabCOMPARATIFAUTO

                        break;


            case 'i' :  //guide d'utilisation
                        clrScrean();    entete();
                        printf("i. Guide d'utilistation\n");
                        printf("-----------------------\n\n");

                        guideUTIL();    //appelle a la procedure guideUTIL
                        break;

            case 'q' :  //Quitter le programme
                        stop = true;
                        testChoix = false;
                        break;

            default  :  //choix différent que {1,2,3,4,5,6,7,i,q}
                        testChoix = false ;
                        break;
        }

        if(testChoix == true)//choix différent que {1,2,3,4,5,6,7,i,q}
        {
            printf("\n>Appuyez sur Entr%cr pour continuer ...\n",130);
            getchar();
            getchar();  //getchar() deux fois par ce que la première getchar() se lira la valeur dans le buffeur
        }

    }while(!stop); //tantque stop égale à faux

    return 0 ;
}
