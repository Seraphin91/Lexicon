#include "Jeu.h"
#include "Joueurs.h"
#include "Plateau.h"
#include <iostream>


int main(int argc, const char* argv[]) {

    int nb_joueur = atoi(argv[1]);
    /*int nb_joueur = 4;*/
    if(nb_joueur <  2 || nb_joueur > 4)//Vérifie que le nombre de joueur est d'au moins 2 et au max 4
    {
        return 1;
    }
    Dictionnaire dictionnaire;
    int nb_mot_dictionnaire = 0;
    dictionnaire.nbmots = &nb_mot_dictionnaire;
    int indice_lettre_dico[MAXTAILLEMOT+1];
    indice_lettre_dico[0] = 0;
    if(chargerDictionnaire("ods4.txt",dictionnaire,indice_lettre_dico) < 0)
        return 1;
    Liste l;
    l.Taille= nb_joueur;
    l.Taille_enjeu = &nb_joueur;
    initialiser_liste_joueur(l,l.Taille);
    cout << "(Commandes valides : TEPRC)" << endl;
    unsigned int com = 0;
    unsigned int* commence = &com;
    cin.putback('\0');
    while (std::cin.get() != '\0') {
        // vide le buffer
    }
    while(partie(l))
    {
        Tas pioche;
        pioche.nb_carte = NB;
        pioche.carte = new Carte [NB];
        Tas expose;
        expose.nb_carte = UN;
        expose.carte = new Carte [UN];
        Plateau plateau;
        initialiser_carte(pioche);
        melanger(pioche);
        distribuer(pioche,l,expose);
        initialiser_plateau(plateau);
        unsigned int i;
        do
        {
            i = l.enjeu[0]->numero;
            jouer(l,pioche,expose,plateau,dictionnaire,indice_lettre_dico);
        }
        while(l.liste_joueur[i-1]->nb_carte != 0);//Tant qu'au tous les joueurs ont des cartes
        compte_points(l,l.Taille_enjeu);
        affiche_tour(l);
        elimination(l,l.Taille_enjeu,commence);
        del_tas(pioche.carte);
        del_tas(expose.carte);
        if(plateau.nb_mots > 0)
            delet_plateau(plateau);
    }
    cout << "La partie est finie";
    delete [] dictionnaire.dictionnaire;
    dictionnaire.dictionnaire = nullptr;
    del_joueur(l,nb_joueur);
    return 0;
}
