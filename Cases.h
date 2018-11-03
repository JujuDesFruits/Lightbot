#ifndef CASES_H
#define CASES_H

class Cases
{
public:
    /****************** Nom de la fonction **********************
    * Cases                                            *
    ******************** Auteur , Dates *************************
    * trijean julien                  *
    ********************* Description ***************************
    * constructeur par des int symbolisant le type(case allumé,
    * eteinte ou vide)           *
    *********************** Entrées *****************************
    * des int    *
    *********************** Sorties *****************************
    * Vous détaillez ici ce que renvoie la fonction             *
    ***********************************************************/
    Cases(int type, int direction, int hauteur);
    /****************** Nom de la fonction **********************
    * type                                              *
    ******************** Auteur , Dates *************************
    * trijean julien                     *
    ********************* Description ***************************
    * renvoie le type            *
    *********************** Entrées *****************************
    * Vous décrivez ici les données en entrée de la fonction    *
    *********************** Sorties *****************************
    * Vous détaillez ici ce que renvoie la fonction             *
    ***********************************************************/
    int type();
    /****************** Nom de la fonction **********************
    * changerType                                             *
    ******************** Auteur , Dates *************************
    * trijean julien                     *
    ********************* Description ***************************
    * Vous décrivez ici ce que fait cette fonction              *
    *********************** Entrées *****************************
    * Vous décrivez ici les données en entrée de la fonction    *
    *********************** Sorties *****************************
    * Vous détaillez ici ce que renvoie la fonction             *
    ***********************************************************/
    void changerLeType(int valeur);
    /****************** Nom de la fonction **********************
    * direction                                              *
    ******************** Auteur , Dates *************************
    * trijean julien                    *
    ********************* Description ***************************
    * renvoie la direction() de la case               *
    *********************** Entrées *****************************
    * Vous décrivez ici les données en entrée de la fonction    *
    *********************** Sorties *****************************
    * Vous détaillez ici ce que renvoie la fonction             *
    ***********************************************************/
    int direction();
    /****************** Nom de la fonction **********************
    * changerDirection                                              *
    ******************** Auteur , Dates *************************
    * trijean julien                  *
    ********************* Description ***************************
    * explicite             *
    *********************** Entrées *****************************
    * Vous décrivez ici les données en entrée de la fonction    *
    *********************** Sorties *****************************
    * Vous détaillez ici ce que renvoie la fonction             *
    ***********************************************************/
    void changerLaDirection(int valeur);
    /****************** Nom de la fonction **********************
    * hauteur                                           *
    ******************** Auteur , Dates *************************
    * trijean julien                     *
    ********************* Description ***************************
    * explicite             *
    *********************** Entrées *****************************
    * Vous décrivez ici les données en entrée de la fonction    *
    *********************** Sorties *****************************
    * Vous détaillez ici ce que renvoie la fonction             *
    ***********************************************************/
    int hauteur();
    ~Cases()=default;
private:
    int m_Type;
    int m_DirectionRobot;
    int m_Hauteur;
};

#endif // CASES_H
