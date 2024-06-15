#include "Joueurs.h"

/** * @brief initialise la liste de joueur ainsi que les joueurs
 * @param[in/out] l : la liste des joueurs
 * @param[in] nb_joueur : le nombre de joueur
 */
void initialiser_liste_joueur(Liste& l,int nb_joueur){
    l.liste_joueur = new Joueur* [nb_joueur];//on initialise la liste de joueur
    l.enjeu = new Joueur* [nb_joueur];
    for(unsigned int i = 0;i<nb_joueur;++i)//On initialise les joueurs
    {
        Joueur* j;
        j = new Joueur ;
        j->numero = i+1;
        j->Eliminer = false;
        j->NB_points = 0;
        j->Main = new Carte [DEBUT];
        j->nb_carte =DEBUT;
        l.liste_joueur[i] = j;
        l.enjeu[i] = j;
    }
}
/**
 * @brief supprime la liste de joueur ainsi que les joueurs
 * @param[in/out] l : la liste des joueurs
 * @param[in] nb_joueur : le nombre de joueur
 */
void del_joueur(Liste& l,int nb_joueur)
{
    for (unsigned int i = 0;i < nb_joueur;++i)//On supprime les joueurs
    {
        delete [] l.liste_joueur[i]->Main;
        delete l.liste_joueur[i];
    }
    delete [] l.liste_joueur;
    l.liste_joueur = nullptr;
    delete [] l.enjeu;
    l.enjeu = nullptr;

}