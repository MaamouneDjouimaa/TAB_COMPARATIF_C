#ifndef     modeleTAB_COMPARATIF_H
#define     modeleTAB_COMPARATIF_H	1

//procedure pour effacer la console
void clrScrean ();

//entete
void menu();
void entete();

//creer un Tableau de Taille donnez.
void genTab (int *t ,int Taille);

//Afficher un tableau
void afficher(int tab[], int n);

// Procédure qui copier un Tableau.
void copyTab (int *t, int *t_copy, int Taille);

// Les procédures de tri
void triBulles    (int *t, int n);  //Trie à bulles
void triSelection (int *t, int n);  //Trie par Selection
void triInsertion (int *t, int n);  //Trie par Insertion
void triRapide (int* t, int bInf, int bSup);  //Trie Rapide
int partitionner(int *t, int bInf, int bSup);  // partitionner (trie Rapide)
void permuter(int *x, int *y);  // Permuter (trie Rapide)
void triFusion(int tab[], int debut, int fin);  //Trie par fusion
void fusion(int tab[], int debut, int milieu, int fin); // fusion (Trie par fusion)

//procedure qui affiche le guide d'utilisation
void guideUTIL();

//procedure qui affiche le tableau comparatif
void tabCOMPARATIF(double matrice[6][10], int cpt_colonnes);
void tabCOMPARATIFAUTO(double matrice[6][10]);


#endif /* modeleTAB_COMPARATIF.h  */
