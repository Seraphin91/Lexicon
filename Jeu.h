#ifndef SAE_CARTE_JEU_H
#define SAE_CARTE_JEU_H
#include "Plateau.h"
#include "Joueurs.h"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <fstream>



bool estMotValide(const char* mot,const Dictionnaire& dictinnaire,const int indice_lettre_dico[], unsigned int taille_mot);
bool partie(const Liste& l);
void elimination(Liste& l,int* taille_enjeu,unsigned int* commence);
void compte_points(Liste& l, int* nb);
void affiche_tour(const Liste& l);
void affiche_jeu(const Liste& l, const Tas& expo, const Plateau& plateau);
void next(Liste& l);
bool detient(const Liste& l, char carte);
unsigned int indice_carte_inventaire(const Liste& l, unsigned int indice, char carte);
void enleve_carte_inventaire(Liste& l, char lettre);
void supr_carte_inventaire(Liste&l, char lettre);
unsigned int avance_str(char a[], unsigned int indice);
unsigned int compte_droite(char a[], unsigned int indice);
unsigned int taille_char(char a[]);
bool Talon(Liste& l, Tas& pioche, Tas& expo,char carte);
bool exposee(Liste& l, Tas& expo, char carte);
bool poser(Liste& l, Plateau& plateau, char mot[], unsigned int taille,const Dictionnaire& dictionnaire,const int indice_lettre_dico[]);
bool remplacer(Liste& l , Plateau& plateau,const Dictionnaire& dictionnaire,unsigned int indice,char mot[],const int indice_lettre_dico[]);
bool completer(Liste& l, Plateau& plateau,const Dictionnaire& dictionnaire, unsigned int indice, char mot[],unsigned int taille,const int indice_lettre_dico[]);
void jouer( Liste& l, Tas& pioche, Tas& expo, Plateau& plateau,const Dictionnaire& dictionnaire,const int indice_lettre_dico[]);


#endif //SAE_CARTE_JEU_H
