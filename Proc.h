#ifndef PROC_H
#define PROC_H
#include<vector>


class Proc
{
public:
    Proc();
    /****************** Nom de la fonction **********************
    * lancerAction()                                            *
    ******************** Auteur , Dates *************************
    * trijean julien                      *
    ********************* Description ***************************
    * renvoie un vecteur des actions stocké sous forme de int
              *
    *********************** Entrées *****************************
    * Vous décrivez ici les données en entrée de la fonction    *
    *********************** Sorties *****************************
    *unn vectur de int            *
    ***********************************************************/
    std::vector<int> lancerAction();
    /****************** Nom de la fonction **********************
    * initialiserProc();                                             *
    ******************** Auteur , Dates *************************
    *     trijean julien                *
    ********************* Description ***************************
    *     permet de nettoyer le vecteur stockant les actions          *
    *********************** Entrées *****************************
    * Vous décrivez ici les données en entrée de la fonction    *
    *********************** Sorties *****************************
    * Vous détaillez ici ce que renvoie la fonction             *
    ***********************************************************/
    void initialiserProc();
    /****************** Nom de la fonction **********************
    *integrerAction();                                         *
    ******************** Auteur , Dates *************************
    * trijean julien                     *
    ********************* Description ***************************
    * permet d'integrer des action sous forme de int dans le vecteur             *
    *********************** Entrées *****************************
    * Vous décrivez ici les données en entrée de la fonction    *
    *********************** Sorties *****************************
    * Vous détaillez ici ce que renvoie la fonction             *
    ***********************************************************/
    void integrerAction(int action);
private:
    std::vector<int>m_liste_action;
    const int m_TailleMax=12;
};

#endif // PROC_H
