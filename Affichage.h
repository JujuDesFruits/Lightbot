#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#include <SFML/Graphics.hpp>
#include<vector>

#include"Terrain.h"
#include"Cases.h"

using Position = sf::Vector2f;

class Affichage
{
public:
    Affichage();
    /****************** Nom de la fonction **********************
    * affichageMenu();                                        *
    ******************** Auteur , Dates *************************
    * nathan precigout                    *
    ********************* Description ***************************
    * affiche le menu avec les images realiser maison              *
    *********************** Entrées *****************************
    * Vous décrivez ici les données en entrée de la fonction    *
    *********************** Sorties *****************************
    * Vous détaillez ici ce que renvoie la fonction             *
    ***********************************************************/
    void affichageMenu();
    /****************** Nom de la fonction **********************
    * affichageJeu();                                              *
    ******************** Auteur , Dates *************************
    * trijean julien                     *
    ********************* Description ***************************
    * affiche le terrain en parcourant tous le tableau 1d et en
    * prenant en compte les case pair en impaire  et en verifiant
             leur type et direction pour l'affichage des couleur
et de la texture du robot (fleche)*+ affichage des actions
implementer via les vecteur les stackants
    *********************** Entrées *****************************
    * Vous décrivez ici les données en entrée de la fonction    *
    *********************** Sorties *****************************
    * Vous détaillez ici ce que renvoie la fonction             *
    ***********************************************************/
    void affichageJeu(Terrain *damier,std::vector<int> liste_actions,std::vector<int> liste_Proc);
    /****************** Nom de la fonction **********************
    * affichageChoixNiv();                                              *
    ******************** Auteur , Dates *************************
    * nathan precigout                      *
    ********************* Description ***************************
    * importation des images pour l'affichage du choix niv           *
    *********************** Entrées *****************************
    * Vous décrivez ici les données en entrée de la fonction    *
    *********************** Sorties *****************************
    * Vous détaillez ici ce que renvoie la fonction             *
    ***********************************************************/
    void affichageChoixNiv();
    ~Affichage()=default;

    sf::RenderWindow m_window;

private:
    sf::CircleShape m_cercle;
    sf::CircleShape m_cercleBis;
    sf::Texture m_texture_action;
    sf::Texture m_texture;
    sf::Color m_couleur;
    sf::RectangleShape m_action_affichage;

    bool  m_appli_running;
    sf::Texture m_Texture_Menu;
    sf::Sprite m_Sprite_Menu;
    sf::Texture m_Texture_Choix_Niveau;
    sf::Sprite m_Sprite_Choix_Niveau;
    sf::Texture m_Texture_Jeu;
    sf::Sprite m_Sprite_Jeu;
};

#endif // AFFICHAGE_H
