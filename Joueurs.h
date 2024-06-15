#ifndef SAE_CARTE_JOUEURS_H
#define SAE_CARTE_JOUEURS_H
#include <iostream>
#include <ctime>
#include <iomanip>
#include <fstream>
using namespace std;
enum {NB = 51, DEBUT = 10,UN = 1,MAXMOTS = 369100,MAXTAILLEMOT = 26, MAX = 100};

typedef struct {char Nom; unsigned int points;}Carte;
typedef struct {unsigned int NB_points; Carte* Main; unsigned int nb_carte; bool Eliminer; unsigned int numero;}Joueur;
typedef struct {Joueur** liste_joueur;int Taille; Joueur** enjeu; int* Taille_enjeu;}Liste;

void initialiser_liste_joueur(Liste& l,int nb_joueur);
void del_joueur(Liste& l,int nb_joueur);
#endif //SAE_CARTE_JOUEURS_H
