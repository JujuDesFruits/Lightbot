#ifndef TERRAIN_H
#define TERRAIN_H
#include<vector>
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

#include<SFML/Graphics.hpp>
#include "Cases.h"

class Terrain
{
public:
    Terrain();
    /****************** Nom de la fonction **********************
    * caseVide                                          *
    ******************** Auteur , Dates *************************
    * Precigout Nathan                    *
    ********************* Description ***************************
    * vérifie que la case du terrain est vide            *
    *********************** Entrées *****************************
    * position 1d sous forme d'entier   *
    *********************** Sorties *****************************
    * bolléen vrai= la case est vide             *
    ***********************************************************/
    bool caseVide(int pos);
    /****************** Nom de la fonction **********************
    * lumiereEteint                                   *
    ******************** Auteur , Dates *************************
    * Precigout Nathan                   *
    ********************* Description ***************************
    * verifie que la case selectionner est etiente            *
    *********************** Entrées *****************************
    * position  1d  *
    *********************** Sorties *****************************
    * booléen vrai = la case est une lumière eteinte           *
    ***********************************************************/
    bool lumiereEteint(int pos);
    /****************** Nom de la fonction **********************
    * lumiereAllume()                                          *
    ******************** Auteur , Dates *************************
    * Precigout Nathan                  *
    ********************* Description ***************************
    * même chose              *
    *********************** Entrées *****************************
    *  meme chose    *
    *********************** Sorties *****************************
    * meme chose            *
    ***********************************************************/
    bool lumiereAllume(int pos);
    /****************** Nom de la fonction **********************
    * changerType                                             *
    ******************** Auteur , Dates *************************
    * Precigout Nathan                      *
    ********************* Description ***************************
    * permet de definir si la case est vide, allumé ou eteinte  *
    *********************** Entrées *****************************
    * position et le type de case quelle sera    *
    *********************** Sorties *****************************
    * Vous détaillez ici ce que renvoie la fonction             *
    ***********************************************************/
    void changerType(int pos, int type);
    /****************** Nom de la fonction **********************
    * changerdirection                                           *
    ******************** Auteur , Dates *************************
    * precigout nathan                     *
    ********************* Description ***************************
    * change la direction du robot si il est situer sur la case *
    *********************** Entrées *****************************
    * position et nouvelle direction    *
    *********************** Sorties *****************************
    * Vous détaillez ici ce que renvoie la fonction             *
    ***********************************************************/
    void changerDirection(int pos, int direction);
    /****************** Nom de la fonction **********************
    * nbEtage                                              *
    ******************** Auteur , Dates *************************
    * Precigout  nathan                   *
    ********************* Description ***************************
    * renvoit le nombre d'etage de la case              *
    *********************** Entrées *****************************
    *la meme qu'avant   *
    *********************** Sorties *****************************
    * la meme qu'avant            *
    ***********************************************************/
    int nbEtage(int pos);
    /****************** Nom de la fonction **********************
    * directionrobot                                              *
    ******************** Auteur , Dates *************************
    * Precigout nathan                      *
    ********************* Description ***************************
    * donne la direction de la case, permet aussi de savoir si il ya un robot sur la case              *
    *********************** Entrées *****************************
    * Vous décrivez ici les données en entrée de la fonction    *
    *********************** Sorties *****************************
    * Vous détaillez ici ce que renvoie la fonction             *
    ***********************************************************/
    int directionRobot(int pos);
    /****************** Nom de la fonction **********************
    * gagner                                           *
    ******************** Auteur , Dates *************************
    * Precigout nathan                     *
    ********************* Description ***************************
    * parcours le tableau pour definir si il reste une lumière eteinte             *
    *********************** Entrées *****************************
    * Vous décrivez ici les données en entrée de la fonction    *
    *********************** Sorties *****************************
    * Vous détaillez ici ce que renvoie la fonction             *
    ***********************************************************/
    bool gagner();
    /****************** Nom de la fonction **********************
    * pos_robot                                             *
    ******************** Auteur , Dates *************************
    * Precigout nathan                      *
    ********************* Description ***************************
    * renvoie la position du robot enregistre par pos_origine              *
    *********************** Entrées *****************************
    * Vous décrivez ici les données en entrée de la fonction    *
    *********************** Sorties *****************************
    * Vous détaillez ici ce que renvoie la fonction             *
    ***********************************************************/
    int pos_Robot();
    /****************** Nom de la fonction **********************
    * initialiserTerrain();                                   *
    ******************** Auteur , Dates *************************
    * trijean julien                      *
    ********************* Description ***************************
    * li un doc text et initialise le niveau avec les caractères lu
             change de niveau a evec un string spéciale séparant les nivs*
    *********************** Entrées *****************************
    * repertoire du doc et le niv qui sera initialiser    *
    *********************** Sorties *****************************
    * Vous détaillez ici ce que renvoie la fonction             *
    ***********************************************************/
    void initialiserTerrain(std::string doc, int niv);
    /****************** Nom de la fonction **********************
    * changerPos_Robot();                                    *
    ******************** Auteur , Dates *************************
    * precigout nathan               *
    ********************* Description ***************************
    * change la variable stokant la position du robot          *
    *********************** Entrées *****************************
    * Vous décrivez ici les données en entrée de la fonction    *
    *********************** Sorties *****************************
    * Vous détaillez ici ce que renvoie la fonction             *
    ***********************************************************/
    void changerPos_Robot(int nouvellePos);
    /****************** Nom de la fonction **********************
    *TailleDamier()                              *
    ******************** Auteur , Dates *************************
    * Precigout nathan                     *
    ********************* Description ***************************
    * renvoie la taille du damier à la racine carré car le damier
    * est toujours un carré de case           *
    *********************** Entrées *****************************
    * Vous décrivez ici les données en entrée de la fonction    *
    *********************** Sorties *****************************
    * Vous détaillez ici ce que renvoie la fonction             *
    ***********************************************************/
    int TailleDamier();
    ~Terrain();

protected:
    std::vector<Cases*> m_cases;

private:
    int m_TailleDamier;
    int m_PositionOrigine;


};

#endif // TERRAIN_H
