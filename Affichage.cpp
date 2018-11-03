#include "Affichage.h"

const std::string POLICE = "/home/trijean/Bureau/Lightbot/Rainbow_Bridge_Personal_Use.ttf";
const     Position
COIN_MAIN {1366,72},
COIN_PROC {1367,416},
DIMS_ACTION {130, 130},

COIN_AVANCER {50,1000},
DIMS_AVANCER {50, 80},
COIN_TOURNER {150,1000},
DIMS_TOURNER {50, 80},
COIN_SAUTER {250,1000},
DIMS_SAUTER {50, 80},
COIN_ALLUMER {350,1000},
DIMS_ALLUMER {50, 80};

Affichage::Affichage()
{
    m_window.create(sf::VideoMode {1920, 1080, 32},
                    "LightBot",
                    sf::Style::Close
                    );

    m_window.setFramerateLimit(60);
}



void Affichage::affichageMenu()
{
    m_window.clear();
    m_Texture_Menu.loadFromFile("Menu.png");
    m_Sprite_Menu.setTexture(m_Texture_Menu);

    m_window.draw(m_Sprite_Menu);
    m_window.display();
}

void Affichage::affichageJeu(Terrain* damier, std::vector<int> liste_actions, std::vector<int> liste_Proc)
{
    m_window.clear();


    m_Texture_Jeu.loadFromFile("Jeu.png");
    m_Sprite_Jeu.setTexture(m_Texture_Jeu);

    m_window.draw(m_Sprite_Jeu);


    if (liste_actions.size()!=0&&liste_actions.size()<12)
        for(int i=0;i<liste_actions.size();i++){
            switch (liste_actions[i]) {
            case 1:
                m_texture_action.loadFromFile("Avancer.png");
                break;
            case 2:
                m_texture_action.loadFromFile("Tourner_Droite.png");
                break;
            case 3:
                m_texture_action.loadFromFile("Tourner_Gauche.png");
                break;
            case 4:
                m_texture_action.loadFromFile("Sauter.png");
                break;
            case 5:
                m_texture_action.loadFromFile("Allumer.png");
                break;
            default:
                break;
            }
            m_action_affichage.setPosition({DIMS_ACTION.x*(i%4)+COIN_PROC.x,DIMS_ACTION.y*(i/4)+COIN_PROC.y});
            m_action_affichage.setSize(DIMS_ACTION);
            m_action_affichage.setTexture(&m_texture_action);
            m_window.draw(m_action_affichage);
        }
    if (liste_Proc.size()!=0&&liste_actions.size()!=0&&liste_actions.size()<12&&liste_Proc.size()<8){
        int nb=liste_Proc.size()/liste_actions.size();
        for (int i=0;i<nb;i++){
            m_texture_action.loadFromFile("P1.png");
            m_action_affichage.setPosition({DIMS_ACTION.x*(i%4)+COIN_MAIN.x,DIMS_ACTION.y*(i/4)+COIN_MAIN.y});
            m_action_affichage.setSize(DIMS_ACTION);
            m_action_affichage.setTexture(&m_texture_action);
            m_window.draw(m_action_affichage);
        }
    }



    int nbDeCaseXouY=damier->TailleDamier();
    m_texture.loadFromFile("Fleche.png");
    m_cercle.setRadius(40.);
    m_cercleBis.setRadius(m_cercle.getRadius());
    m_cercle.setOrigin({m_cercle.getRadius(),m_cercle.getRadius()});
    m_cercleBis.setOrigin(m_cercle.getOrigin());
    m_cercle.setRotation(90);
    m_cercle.setPointCount(6);
    m_cercleBis.setPointCount(m_cercle.getPointCount());
    m_cercle.setOutlineThickness(1.0);
    m_cercleBis.setOutlineThickness(m_cercle.getOutlineThickness());
    for(int i=0;i<nbDeCaseXouY*nbDeCaseXouY;i++)
    {   if ((nbDeCaseXouY%2)==0){
            if (i%2==0){
                m_cercle.setPosition({(i%nbDeCaseXouY)*61+100,(i/nbDeCaseXouY)*70+130});
            }else{
                m_cercle.setPosition({(i%nbDeCaseXouY)*61+100,((i/nbDeCaseXouY)*70)+165});
            }}else {
            if ((i/nbDeCaseXouY)%2==0){
                if (i%2==0){
                    m_cercle.setPosition({(i%nbDeCaseXouY)*61+100,(i/nbDeCaseXouY)*70+130});
                }else{
                    m_cercle.setPosition({(i%nbDeCaseXouY)*61+100,((i/nbDeCaseXouY)*70)+165});
                }}else {
                if (i%2==1){
                    m_cercle.setPosition({(i%nbDeCaseXouY)*61+100,(i/nbDeCaseXouY)*70+130});
                }else{
                    m_cercle.setPosition({(i%nbDeCaseXouY)*61+100,((i/nbDeCaseXouY)*70)+165});
                }
            }
        }
        if (damier->caseVide(i)){
            m_couleur=sf::Color::Black;
            m_cercle.setFillColor(m_couleur);
        }else{
            if (damier->lumiereEteint(i)){
                m_couleur=sf::Color::Cyan;
                m_cercle.setFillColor(m_couleur);
            }else{
                if (damier->lumiereAllume(i)){
                    m_couleur=sf::Color::Blue;
                    m_cercle.setFillColor(m_couleur);
                }else{
                    if (damier->nbEtage(i)>1){
                        m_couleur=sf::Color::Magenta;
                        m_cercle.setFillColor(m_couleur);
                    }else{
                        if(damier->nbEtage(i)>0){
                            m_couleur=sf::Color::Yellow;
                            m_cercle.setFillColor(m_couleur);
                        }else{
                            m_couleur=sf::Color::Red;
                            m_cercle.setFillColor(m_couleur);

                        }
                    }
                }
            }
        }
        if (damier->directionRobot(i)==7){
            m_cercleBis.setTexture(&m_texture);
            m_cercleBis.setRotation(330);
            m_cercleBis.setPosition(m_cercle.getPosition());
        }
        if (damier->directionRobot(i)==8){
            m_cercleBis.setTexture(&m_texture);
            m_cercleBis.setRotation(30);
            m_cercleBis.setPosition(m_cercle.getPosition());
        }
        if (damier->directionRobot(i)==9){
            m_cercleBis.setTexture(&m_texture);
            m_cercleBis.setRotation(90);
            m_cercleBis.setPosition(m_cercle.getPosition());
        }
        if (damier->directionRobot(i)==1){
            m_cercleBis.setTexture(&m_texture);
            m_cercleBis.setRotation(270);
            m_cercleBis.setPosition(m_cercle.getPosition());
        }
        if (damier->directionRobot(i)==2){
            m_cercleBis.setTexture(&m_texture);
            m_cercleBis.setRotation(210);
            m_cercleBis.setPosition(m_cercle.getPosition());
        }
        if (damier->directionRobot(i)==3){
            m_cercleBis.setTexture(&m_texture);
            m_cercleBis.setRotation(150);
            m_cercleBis.setPosition(m_cercle.getPosition());
        }
        m_cercle.setOutlineColor(sf::Color::White);
        m_window.draw(m_cercle);
    }

    m_window.draw(m_cercleBis);
    m_window.display();
}
void Affichage::affichageChoixNiv()
{
    m_window.clear();
    m_Texture_Choix_Niveau.loadFromFile("Choix_Niveau.png");
    m_Sprite_Choix_Niveau.setTexture(m_Texture_Choix_Niveau);

    m_window.draw(m_Sprite_Choix_Niveau);


    m_window.display();
}
