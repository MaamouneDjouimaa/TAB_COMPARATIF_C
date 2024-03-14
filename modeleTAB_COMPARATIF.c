#include <string.h>
#include <stdbool.h>
#include "modeleTAB_COMPARATIF.h"

void entete()
{
    printf("********************************************\n");
    printf("**              TP_ASD3_HIS               **\n");
    printf("**   TABLEAU COMPARATIF (ALGO DE TRIE)    **\n");
    printf("**        PAR : Maamoune Djouimaa         **\n");
    printf("********************************************\n\n");
}

//entete
void menu()
{
    entete();
    printf("--------------------------------------------\n");
    printf("1. Cr%cer un tableau\n",130);
    printf("2. Trie %c Bulles\n",133);
    printf("3. Trie par S%clection\n",130);
    printf("4. Trie par Insertion\n");
    printf("5. Trie Rapide \n");
    printf("6. Trie par Fusion\n\n");
    printf("7. Tableau comparatif(Manuelle)\n");
    printf("8. Tableau comparatif(Automatique)\n\n");
    printf("i. Guide d'utilistation\n");
    printf("q. Quitter\n");
    printf("---------------------------------------------\n\n\n\n");
}

//procedure pour effacer la console
void clrScrean ()
{
    system("cls||clear");  //effacer la console
}

// cree un Tableau d'une Taille donnez.
void genTab (int *t ,int Taille)
{
    #define NB_MIN 1
    #define NB_MAX 1000
    srand(time(NULL));

    int i;
    for (i=0; i<Taille; i++)
    {
        t[i] = rand()%(NB_MAX-NB_MIN)+NB_MIN;
    }

}

//Afficher un tableau
void afficher(int tab[], int n)
{
    for (int i = 0; i < n; i++)
        printf(" %d |", tab[i]);
    printf("\n");
}


// Procédure qui copier un Tableau dans un autre
void copyTab (int *t, int *t_copy, int Taille)
{
    int i;

    for (i=0; i<Taille; i++)
    {
        t_copy[i] = t[i];
    }
}


// Les procédures de Trie
void triBulles (int *t, int n)  //trie a bulles
{
    bool permut;
    int i, tmp;

    do
    {
        permut = false;
        for (i=0; i<(n-1); i++)
        {
            if (t[i] > t[i+1])
            {
                tmp = t[i];
                t[i] = t[i+1];
                t[i+1] = tmp;
                permut = true;
            }
        }

    }while (permut == true);

}

void triSelection (int *t, int n)   //trie par selection
{
    int i,j,tmp ;

    for (i=0; i<n; i++)
    {
        for (j=i+1; j<=n; j++)
        {
            if (t[i] > t[j])
            {
                tmp = t[i];
                t[i] = t[j];
                t[j] = tmp;
            }
        }
    }
}

void triInsertion (int *t, int n)   //trie par insertion
{
    int i,j,tmp;
    bool stop;

    for (i=1; i<=n; i++)
    {
        j = i-1;
        stop = false;
        while ((j>=0) && (stop == false))
        {
            if (t[j+1] >= t[j])
                stop = true;
            else
            {
                tmp = t[j];
                t[j] = t[j+1];
                t[j+1] = tmp;
                j = j-1;
            }
        }
    }
}

void triRapide (int* t, int bInf, int bSup)//trie rapid
{
    int posPivot;

    if(bInf < bSup)
    {
       posPivot = partitionner(t, bInf, bSup) ;
       triRapide(t, bInf, posPivot-1);
       triRapide(t, posPivot+1, bSup);
    }

}

int partitionner(int *t, int bInf, int bSup)    //partitionner (trie rapid)
{
    int pivot, i, posPivot;

    pivot = t[bSup];
    posPivot = bInf;

    for(i=bInf; i<=bSup-1; i++)
    {
        if(t[i] <= pivot)
        {
            permuter(&t[i], &t[posPivot]);
            posPivot = posPivot+1;
        }
    }
    permuter(&t[posPivot], &t[bSup]);

    return (posPivot);
}

void permuter(int *x, int *y)   //permuter (trie rapid)
{
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

void triFusion(int tab[], int debut, int fin)   //Trie par fusion
{
    if (debut < fin)
    {
        // Trouvez le point milieu pour diviser le tableau en deux moitiés
        int m = (debut + fin) / 2;

        triFusion(tab, debut, m);
        triFusion(tab, m + 1, fin);
        // Fusionnez les deux moitiés triées
        fusion(tab, debut, m, fin);
    }
}

void fusion(int tab[], int debut, int milieu, int fin)  //fusion(Trie par fusion)
{
    int n1 = milieu - debut + 1;    //taille du tableau GAUCHE
    int n2 = fin - milieu;  //taille du tableau DROIT
    int G[n1], D[n2];   //Declaration des 2 tableau gauche et droit

    for (int i = 0; i < n1; i++)
        G[i] = tab[debut + i];

    for (int j = 0; j < n2; j++)
        D[j] = tab[milieu + 1 + j];

// i et j pointeurs pour G et D
//  k poineur pour maintenir l'index actuel du tableau trié final
    int i, j, k;
    i = 0;
    j = 0;
    k = debut;

    while (i < n1 && j < n2)
    {
        if (G[i] <= D[j])
        {
            tab[k] = G[i];
            i++;
        }
        else
        {
            tab[k] = D[j];
            j++;
        }
            k++;
    }

    // Copiez tous les éléments restants du tableau non vide
    while (i < n1)
    {
        tab[k] = G[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        tab[k] = D[j];
        j++;
        k++;
    }
}

//procedure qui affiche le guide d'utilisation
void guideUTIL()
{
    printf("Cet outil permet de mesurer les performances des diff%crents algorithmes de trie sur le m%cme jeu de valeurs.\n\n",130,136);
    printf("Guide d'utilisation : \n\n");
    printf("Selectioner Tableau comparatif(AUTOMATIQUE) sinon :\n\n");
    printf("1.Cr%cer un tableau \n2.Appliquer les algorithmes de trie\n",130);
    printf("3.Le tableau comparatif(manuelle) sera rempli au fur et %c mesure \n4.Le temps d'ex%ccution est exprim%c en second \n",133,130,130);
}


//procedure qui affiche le tableau comparatif
void tabCOMPARATIFAUTO(double matrice[6][10]) //les parametre : matrice
{
    printf("-----------------------------------------------------------------------------\n");
    printf("|                   |   %d      |   %d     |   %d     |   %d     |\n",(int)matrice[0][0], (int)matrice[0][1], (int)matrice[0][2], (int)matrice[0][3]);
    printf("-----------------------------------------------------------------------------\n");
    printf("|Trie %c Bulles      |   %.3f s   |   %.3f s   |   %.3f s   |   %.3f s   |\n",133, matrice[1][0], matrice[1][1], matrice[1][2], matrice[1][3]);
    printf("-----------------------------------------------------------------------------\n");
    printf("|Trie par S%clection |   %.3f s   |   %.3f s   |   %.3f s   |   %.3f s   |\n",130, matrice[2][0], matrice[2][1], matrice[2][2], matrice[2][3]);
    printf("-----------------------------------------------------------------------------\n");
    printf("|Trie par Insertion |   %.3f s   |   %.3f s   |   %.3f s   |   %.3f s   |\n",matrice[3][0], matrice[3][1], matrice[3][2], matrice[3][3]);
    printf("-----------------------------------------------------------------------------\n");
    printf("|Trie Rapide        |   %.3f s   |   %.3f s   |   %.3f s   |   %.3f s   |\n",matrice[4][0], matrice[4][1], matrice[4][2], matrice[4][3]);
    printf("-----------------------------------------------------------------------------\n");
    printf("|Trie par Fusion    |   %.3f s   |   %.3f s   |   %.3f s   |   %.3f s   |\n",matrice[5][0], matrice[5][1], matrice[5][2], matrice[5][3]);
    printf("-----------------------------------------------------------------------------\n");
}

void tabCOMPARATIF(double matrice[6][10], int cpt_colonnes) //les parametre : matrice et cpt colonnes compteur des tableaux cree par l'utulisateur
{
    int i;  //itérateur

    for (i=0 ;i<33+24*cpt_colonnes; i++) printf("-"); printf("\n");
    printf("|\t                  \t|\t");
    for (i=0; i<cpt_colonnes ;i++) {printf("%d\t\t|\t", (int) matrice [0][i]);} //afficher les tailles des tableaux dans la premiere colonnes du tableau comparatif

    printf("\n"); for (i=0 ;i<33+24*cpt_colonnes; i++) printf("-"); printf("\n");
    printf("|\tTrie %c Bulles     \t|\t",133);
    for (i=0; i<cpt_colonnes; i++)
        {
            if(matrice [1][i] == -1) // -1 (trie non effectuer)
                printf("   \t\t|\t");   //afficher VIDE
            else
                printf("%f s\t|\t", matrice [1][i]);    //affiche les temps dexecution du trie a bulles (Deuxième ligne ) [commentaires similaire pour les autres algo de trie]
        }

    printf("\n"); for (i=0 ;i<33+24*cpt_colonnes; i++) printf("-"); printf("\n");
    printf("|\tTrie par S%clection\t|\t",130);
    for (i=0; i<cpt_colonnes; i++)
        {
            if(matrice [2][i] == -1)
                printf("   \t\t|\t");
            else
                printf("%f s\t|\t", matrice [2][i]);
        }

    printf("\n"); for (i=0 ;i<33+24*cpt_colonnes; i++) printf("-"); printf("\n");
    printf("|\tTrie par Insertion\t|\t");
    for (i=0; i<cpt_colonnes; i++)
        {
            if(matrice [3][i] == -1)
                printf("   \t\t|\t");
            else
                printf("%f s\t|\t", matrice [3][i]);
        }

    printf("\n"); for (i=0 ;i<33+24*cpt_colonnes; i++) printf("-"); printf("\n");
    printf("|\tTrie Rapide \t\t|\t");
    for (i=0; i<cpt_colonnes; i++)
        {
            if(matrice [4][i] == -1)
                printf("   \t\t|\t");
            else
                printf("%f s\t|\t", matrice [4][i]);
        }
    printf("\n"); for (i=0 ;i<33+24*cpt_colonnes; i++) printf("-"); printf("\n");
    printf("|\tTrie par Fusion \t|\t");
    for (i=0; i<cpt_colonnes; i++)
        {
            if(matrice [5][i] == -1)
                printf("   \t\t|\t");
            else
                printf("%f s\t|\t", matrice [5][i]);
        }
    printf("\n"); for (i=0 ;i<33+24*cpt_colonnes; i++) printf("-"); printf("\n");

}
