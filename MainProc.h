#ifndef MAINPROC_H
#define MAINPROC_H
#include "Proc.h"
#include<vector>
#include<iostream>

class MainProc
{
public:
    MainProc();
    /****************** Nom de la fonction **********************
    * lancerMainProc()                                              *
    ******************** Auteur , Dates *************************
    * trijean julien                     *
    ********************* Description ***************************
    * renvoie un vecteur stockan l'ensemble des actions du proc             *
    *********************** Entrées *****************************
    * Vous décrivez ici les données en entrée de la fonction    *
    *********************** Sorties *****************************
    * un vecteur             *
    ***********************************************************/
    std::vector<int> lancerMainProc();
    /****************** Nom de la fonction **********************
    * reinitiliserMainProc();                                             *
    ******************** Auteur , Dates *************************
    * trijean julien                      *
    ********************* Description ***************************
    * meme chose que dans le proc              *
    *********************** Entrées *****************************
    * Vous décrivez ici les données en entrée de la fonction    *
    *********************** Sorties *****************************
    * Vous détaillez ici ce que renvoie la fonction             *
    ***********************************************************/
    void reinitiliserMainProc();
    /****************** Nom de la fonction **********************
    * integrerProc();                                              *
    ******************** Auteur , Dates *************************
    * trijean julien                      *
    ********************* Description ***************************
    * integre des action et les actions du proc dans le main             *
    *********************** Entrées *****************************
    * Vous décrivez ici les données en entrée de la fonction    *
    *********************** Sorties *****************************
    * Vous détaillez ici ce que renvoie la fonction             *
    ***********************************************************/
    void integrerProc(int action, std::vector<int> liste_action);
private:
    std::vector<int>m_liste_MainAction;
    const int m_TailleMax=8;
};

#endif // MAINPROC_H
