#include "Plateau.h"

/**
 * @brief Charger le dictionnaire dans un tableau + stcoker à quelle indice le dictionnaire change de première lettre
 * @param[in] nomFichier : le fichier qu'on va lire
 * @param[in/out] dictionnaire : la variable où on va stocker les mots du dictionnaire
 * @param[in/out] indice_lettre_dico : le tableau qui va contenir les indices de la première apparition du'une lettre dans le dictionnaire
 * @return -1 si le dictionnaire n'a pas pu être lu ou 0 si il a pu être lu
 */
int chargerDictionnaire(const char* nomFichier, Dictionnaire& dictionnaire,int indice_lettre_dico[]) {
    ifstream in(nomFichier);
    if (!in) {//Vérifie si le dictionnaire peut être lu
        cout << "Le dictionnaire n'a pu être ouvert." << std::endl;
        return -1; // Erreur à l'ouverture du fichier
    }
    dictionnaire.dictionnaire = new Mot_dictionnaire[MAXMOTS];
    char opti = 'A';
    unsigned int tmp = 1;
    while (in >> setw(MAXTAILLEMOT) >> dictionnaire.dictionnaire[*dictionnaire.nbmots].Mot &&
           *dictionnaire.nbmots < MAXMOTS) {
        if (*dictionnaire.nbmots > 0 && dictionnaire.dictionnaire[*dictionnaire.nbmots-1].Mot[0] != dictionnaire.dictionnaire[*dictionnaire.nbmots].Mot[0]) {
            indice_lettre_dico[tmp] = *dictionnaire.nbmots;
            tmp+=1;
        }
        *dictionnaire.nbmots+=1;
    }
    indice_lettre_dico[tmp] = *dictionnaire.nbmots;

    in.close();
    return 0; // Chargement réussi
}
/**
 * @brief supprime un tas de carte
 * @param[in/ou] l : tas de carte
 */
void del_tas(Carte*& pioche)
{
    delete [] pioche;
    pioche = nullptr;
}

/**
 * @brief Initialise toutes les cartes du jeu
 * @param[in/out] pioche : le talon
 */
void initialiser_carte(Tas& pioche)
{
    char a[NB+1] = {"AABBCCDDEEEEEFGGHHIIIIJKLLMNNNOOPQRRRSSSTTTUUUVWXYZ"};
    for (unsigned int i = 0;i<NB;++i)//On parcourt toute la chaine de caractère et le tableau de carte pour donner les nom/points
    {
        pioche.carte[i].Nom = a[i];
        if (pioche.carte[i].Nom == 'A'||pioche.carte[i].Nom == 'E' || pioche.carte[i].Nom == 'I')
            pioche.carte[i].points = 10;
        else if (pioche.carte[i].Nom == 'B' || pioche.carte[i].Nom == 'F' || pioche.carte[i].Nom == 'X' || pioche.carte[i].Nom == 'Z')
            pioche.carte[i].points = 2;
        else if (pioche.carte[i].Nom == 'D' || pioche.carte[i].Nom == 'J')
            pioche.carte[i].points = 6;
        else if (pioche.carte[i].Nom == 'G' || pioche.carte[i].Nom == 'Q' || pioche.carte[i].Nom == 'Y')
            pioche.carte[i].points = 4;
        else
            pioche.carte[i].points = 8;
    }
}
/**
 * @brief Mélange les cartes d'un tas
 * @param[in/out] pioche : un tas de carte
 */
void melanger(Tas& pioche)
{
    srand(static_cast<unsigned int>(std::time(nullptr)));
    for(unsigned int i = 0; i < pioche.nb_carte; ++i)//On parcourt toute la pioche pour mélanger toutes les cartes
    {
        unsigned int indice = rand() % pioche.nb_carte;//On génère un nombre aléatoire
        Carte tmp = pioche.carte[indice];
        pioche.carte[indice] = pioche.carte[i];
        pioche.carte[i] = tmp;
    }
}
/**
 * @brief Distribue les cartes aux joueurs, dépose une carte du talon dans le tas exposées
 * @param[in/out] pioche : le talon
 * @param[in/out] l : la liste de joueur
 * @param[in/out] expose : le tas de cartes exposées
 */
void distribuer(Tas& pioche, Liste& l,Tas& expose)
{
    int newtaille = pioche.nb_carte - (DEBUT*(*l.Taille_enjeu));
    unsigned int tmp = pioche.nb_carte-UN;
    for (unsigned int i = 0; i < l.Taille;++i)//On parcourt toute la liste de joueur
    {
        if (l.liste_joueur[i]->nb_carte != DEBUT)//Verifie que le nb de carte de joueur n'est pas égale à 10
        {
            Carte* nouv = new Carte[DEBUT];
            delete [] l.liste_joueur[i]->Main;
            l.liste_joueur[i]->Main = nouv;
            l.liste_joueur[i]->nb_carte = DEBUT;
        }
        if (!l.liste_joueur[i]->Eliminer)//On verifier que le joueur n'est pas éliminé
        {
            for (unsigned int j = 0; j < DEBUT; ++j)//On parcourt sa main pour lui distribuer des cartes
            {
                l.liste_joueur[i]->Main[j] = pioche.carte[tmp];
                tmp-=1;

            }
        }
    }
    expose.carte[UN-1] = pioche.carte[tmp];//On donne la première carte de la pioche à l'exposée
    Carte* nouv = new Carte[newtaille];//On réduit la taille du talon

    for (unsigned int k = 0;k<newtaille;++k)//Creation du tableau dynamique
    {
        nouv[k] = pioche.carte[k];
    }
    delete [] pioche.carte;//On supprime l'ancien talon
    pioche.carte = nouv;
    pioche.nb_carte = newtaille;
}
/**
 * @brief Initialise le plateau
 * @param[in/out] plateau: le plateau contenant les mots posés
 */
void initialiser_plateau(Plateau& plateau)
{
    plateau.nb_mots = 0;
}
/**
 * @brief Supprime le plateau
 * @param[in/out] plateau: le plateau
 */
void delet_plateau(Plateau& plateau)
{
    for(unsigned int i = 0; i< plateau.nb_mots;++i)//On supprime tous les mots de plateau
    {

        delete [] plateau.Mots[i]->carte;
        plateau.Mots[i]->carte = nullptr;
        delete plateau.Mots[i];
        plateau.Mots[i] = nullptr;
    }
    delete plateau.Mots;//On supprime le plateau
    plateau.Mots = nullptr;
}