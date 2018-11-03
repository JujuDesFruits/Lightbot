#ifndef APPLI_H
#define APPLI_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <unistd.h>
#include <stdio.h>

#include "Terrain.h"
#include "Affichage.h"
#include "Action.h"
#include "Proc.h"
#include "MainProc.h"

using Position = sf::Vector2f;


class Appli : public Affichage
{
public:
    Appli();
    /****************** Nom de la fonction **********************
    * run                                             *
    ******************** Auteur , Dates *************************
    * nathan  precigout                    *
    ********************* Description ***************************
    * realise une boucle pour le jeu              *
    *********************** Entrées *****************************
    * Vous décrivez ici les données en entrée de la fonction    *
    *********************** Sorties *****************************
    * Vous détaillez ici ce que renvoie la fonction             *
    ***********************************************************/
    void run();
    /****************** Nom de la fonction **********************
    * jeux                                            *
    ******************** Auteur , Dates *************************
    * trijean julien                      *
    ********************* Description ***************************
    * appel les fonction de gestion d'affichage du jeux et gere
    * les vecteurs contenant les actions             *
    *********************** Entrées *****************************
    * Vous décrivez ici les données en entrée de la fonction    *
    *********************** Sorties *****************************
    * Vous détaillez ici ce que renvoie la fonction             *
    ***********************************************************/
    void jeux();
    /****************** Nom de la fonction **********************
    * choix niv                                              *
    ******************** Auteur , Dates *************************
    * nathan precigout                      *
    ********************* Description ***************************
    * initilise le terrain avec un niv selectionner              *
    *********************** Entrées *****************************
    * Vous décrivez ici les données en entrée de la fonction    *
    *********************** Sorties *****************************
    * Vous détaillez ici ce que renvoie la fonction             *
    ***********************************************************/
    void ChoixNiv();
    /****************** Nom de la fonction **********************
    * menu                                              *
    ******************** Auteur , Dates *************************
    * precigout nanthan                      *
    ********************* Description ***************************
    * appele l'affichage du menu              *
    *********************** Entrées *****************************
    * Vous décrivez ici les données en entrée de la fonction    *
    *********************** Sorties *****************************
    * Vous détaillez ici ce que renvoie la fonction             *
    ***********************************************************/
    void menu();
    /****************** Nom de la fonction **********************
    * mode                                              *
    ******************** Auteur , Dates *************************
    * trijean  julien                    *
    ********************* Description ***************************
    * se chrage de gerer le passage du menu au choix de niv au
    * jeu via un class d'etat              *
    *********************** Entrées *****************************
    * Vous décrivez ici les données en entrée de la fonction    *
    *********************** Sorties *****************************
    * Vous détaillez ici ce que renvoie la fonction             *
    ***********************************************************/
    void mode();
    /****************** Nom de la fonction **********************
    * evenement();                                              *
    ******************** Auteur , Dates *************************
    * nathan precigout / tuto 1                    *
    ********************* Description ***************************
    * se chagge de la detection de click              *
    *********************** Entrées *****************************
    * Vous décrivez ici les données en entrée de la fonction    *
    *********************** Sorties *****************************
    * Vous détaillez ici ce que renvoie la fonction             *
    ***********************************************************/
    void evenement();
    /****************** Nom de la fonction **********************
    * set mouse coord                                             *
    ******************** Auteur , Dates *************************
    * nathan precigout / tuto1                     *
    ********************* Description ***************************
    * obtien les coordonnée de la souris              *
    *********************** Entrées *****************************
    * Vous décrivez ici les données en entrée de la fonction    *
    *********************** Sorties *****************************
    * Vous détaillez ici ce que renvoie la fonction             *
    ***********************************************************/
    void set_mouse_coord(int x, int y);
    /****************** Nom de la fonction **********************
    * mouse bouton presse                                            *
    ******************** Auteur , Dates *************************
    * nathan precigout / tuto1                      *
    ********************* Description ***************************
    * se charge de tous les clic qui appelle des fonctions             *
    *********************** Entrées *****************************
    * Vous décrivez ici les données en entrée de la fonction    *
    *********************** Sorties *****************************
    * Vous détaillez ici ce que renvoie la fonction             *
    ***********************************************************/
    virtual void mouse_button_pressed ();
    /****************** Nom de la fonction **********************
    * souris dans rectangle                                               *
    ******************** Auteur , Dates *************************
    * nathan precigout / tuto 1                      *
    ********************* Description ***************************
    * verifie que les coordonne sont dans le rectangles              *
    *********************** Entrées *****************************
    * Vous décrivez ici les données en entrée de la fonction    *
    *********************** Sorties *****************************
    * Vous détaillez ici ce que renvoie la fonction             *
    ***********************************************************/
    virtual bool souris_dans_rectangle(const Position & coin, const Position & dims) const;
    /****************** Nom de la fonction **********************
    * clique_sur_bouton_menu();                                              *
    ******************** Auteur , Dates *************************
    * nathan precigout                      *
    ********************* Description ***************************
    * gere les boutons dans le menu              *
    *********************** Entrées *****************************
    * Vous décrivez ici les données en entrée de la fonction    *
    *********************** Sorties *****************************
    * Vous détaillez ici ce que renvoie la fonction             *
    ***********************************************************/
    void clique_sur_bouton_menu();

    ~Appli();


private:
    bool  m_appli_running;
    int m_lancer_des_actions=0;
    int m_niv;
    int m_Mode;
    std::vector<int> m_tmp_proc;
    std::vector<int> m_tmp_main;
    enum class Etat { MENU, JOUER, CHOIXNIV, QUITTER } m_etat;
    enum class Jeux { PLAY, STOP } m_play;


    sf::Texture  m_Texture_Menu_Jouer_Dessus;
    sf::Sprite  m_Sprite_Menu_Jouer_Dessus;
    sf::Texture  m_Texture_Menu_Quitter_Dessus;
    sf::Sprite  m_Sprite_Menu_Quitter_Dessus;

    Position m_mouse;            // position de la souris
    Terrain* m_damier;
    Action m_action;
    Proc* m_proc;
    MainProc* m_mainProc;


};

#endif // APPLI_H
