#ifndef SAE_CARTE_PLATEAU_H
#define SAE_CARTE_PLATEAU_H
// implémentation fonctions
#include <iomanip>
#include <fstream>
#include <iostream>
#include <ctime>
#include "Joueurs.h"


typedef struct {Carte* carte; unsigned int nb_carte;}Tas;
typedef struct {Carte* carte; unsigned int nb_carte;}Mots;
typedef struct {Mots** Mots; unsigned int nb_mots;}Plateau;
typedef struct {char Mot[MAXTAILLEMOT];}Mot_dictionnaire;
typedef struct {Mot_dictionnaire* dictionnaire; int* nbmots;}Dictionnaire;

int chargerDictionnaire(const char* nomFichier, Dictionnaire& dictionnaire,int indice_lettre_dico[]);
void del_tas(Carte*& pioche);
void initialiser_carte(Tas& pioche);
void melanger(Tas& pioche);
void distribuer(Tas& pioche, Liste& l,Tas& expose);
void initialiser_plateau(Plateau& plateau);
void delet_plateau(Plateau& plateau);

#endif //SAE_CARTE_PLATEAU_H
