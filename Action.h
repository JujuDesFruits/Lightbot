#ifndef ACTION_H
#define ACTION_H
#include "Proc.h"
#include "Terrain.h"

class Action
{
private:
    Terrain * m_terrain;
public:
    Action(Terrain *damier);
    /****************** Nom de la fonction **********************
    * avancer();                                              *
    ******************** Auteur , Dates *************************
    * trijean julien                     *
    ********************* Description ***************************
    * deplace la position du robot en fonction de sa position
    *  actuelle et de sa direction              *
    *********************** Entrées *****************************
    * Vous décrivez ici les données en entrée de la fonction    *
    *********************** Sorties *****************************
    * Vous détaillez ici ce que renvoie la fonction             *
    ***********************************************************/
    void avancer();
    /****************** Nom de la fonction **********************
    * tourner droite                                              *
    ******************** Auteur , Dates *************************
    *trijean julien                      *
    ********************* Description ***************************
    * change la diection du robot             *
    *********************** Entrées *****************************
    * Vous décrivez ici les données en entrée de la fonction    *
    *********************** Sorties *****************************
    * Vous détaillez ici ce que renvoie la fonction             *
    ***********************************************************/
    void tournerDroite();
    /****************** Nom de la fonction **********************
    * tournergauche                                             *
    ******************** Auteur , Dates *************************
    *trijean julien                      *
    ********************* Description ***************************
    * change la diection du robot             *
    *********************** Entrées *****************************
    * Vous décrivez ici les données en entrée de la fonction    *
    *********************** Sorties *****************************
    * Vous détaillez ici ce que renvoie la fonction             *
    ***********************************************************/
    void tournerGauche();
    /****************** Nom de la fonction **********************
    * sauter                                             *
    ******************** Auteur , Dates *************************
    * trijean julien                     *
    ********************* Description ***************************
    * fait avancer le robot si le niv d'etage n'est pas le même
    * avec la case sur laquel il va avancer              *
    *********************** Entrées *****************************
    * Vous décrivez ici les données en entrée de la fonction    *
    *********************** Sorties *****************************
    * Vous détaillez ici ce que renvoie la fonction             *
    ***********************************************************/
    void sauter();
    /****************** Nom de la fonction **********************
    * allumer                                              *
    ******************** Auteur , Dates *************************
    * trijean                      *
    ********************* Description ***************************
    * alumme la case si le robot se trouve sur une case a allumer             *
    *********************** Entrées *****************************
    * Vous décrivez ici les données en entrée de la fonction    *
    *********************** Sorties *****************************
    * Vous détaillez ici ce que renvoie la fonction             *
    ***********************************************************/
    void allumer();
    ~Action()=default;
};

#endif // ACTION_H
