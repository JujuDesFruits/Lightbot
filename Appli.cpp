#include "Appli.h"

const std::string POLICE = "/home/trijean/Bureau/Lightbot/Rainbow_Bridge_Personal_Use.ttf";
const     Position COIN_JOUER {656,368},
DIMS_JOUER {549, 258},
COIN_QUITTER {1562,758},
DIMS_QUITTER {297, 199},
COIN_RETOUR_MENU {111,91},
DIMS_RETOUR_MENU {130, 130},
COIN_NIV1 {635,343},
DIMS_NIV1 {130, 130},
COIN_NIV2 {868,343},
DIMS_NIV2 {130, 130},
COIN_RETOUR_CHOIX{1033,27},
DIMS_RETOUR_CHOIX{130,130},
COIN_RECOMMENCER{1117,28},
DIMS_RECOMMENCER{130,130},
COIN_PLAY{1200,866},
DIMS_PLAY{248,128},



COIN_AVANCER {150,865},
DIMS_AVANCER {130, 130},
COIN_TOURNER_GAUCHE {297,865},
DIMS_TOURNER_GAUCHE {130, 130},
COIN_TOURNER_DROITE {440,865},
DIMS_TOURNER_DROITE {130, 130},
COIN_SAUTER {585,865},
DIMS_SAUTER {130, 130},
COIN_ALLUMER {730,865},
DIMS_ALLUMER {130, 130},
COIN_P1 {875,865},
DIMS_P1 {130, 130};

Appli::Appli()
    :m_damier{new Terrain()}
    ,m_proc{new Proc}
    ,m_mainProc{new MainProc}
    ,m_action{m_damier}
{
}


void Appli::run()
{
    m_appli_running = true;
    m_etat=Etat::MENU;

    while (m_appli_running) {
        evenement();
        mode();
    }
    m_window.close();
}


void Appli::mode()
{
    switch (m_etat) {
    case Etat::QUITTER:
        m_appli_running = false;
        break;
    case Etat::JOUER:
        jeux();
        break;
    case Etat::MENU:
        menu();
        break;
    case Etat::CHOIXNIV:
        ChoixNiv();
        break;
    default:
        break;
    }
}

void Appli::jeux()
{
    m_tmp_main.clear();
    m_tmp_main=m_mainProc->lancerMainProc();

    affichageJeu(m_damier, m_tmp_proc, m_tmp_main);

    if (m_tmp_main.size()<=m_lancer_des_actions){
        if (m_damier->gagner()){
            m_etat=Etat::CHOIXNIV;
            std::cout<<"GAGNER !!!"<<std::endl;
        }
        m_lancer_des_actions=0;
        m_play=Jeux::STOP;
    }

    if (m_play==Jeux::PLAY){
        sleep(1);
        std::cout<<"action"<<std::endl;
        switch (m_tmp_main[m_lancer_des_actions]) {
        case 1:
            m_action.avancer();
            m_lancer_des_actions++;
            break;
        case 2:
            m_action.tournerDroite();
            m_lancer_des_actions++;
            break;
        case 3:
            m_action.tournerGauche();
            m_lancer_des_actions++;
            break;
        case 4:
            m_action.sauter();
            m_lancer_des_actions++;
            break;
        case 5:
            m_action.allumer();
            m_lancer_des_actions++;
            break;
        default:
            std::cout<<"beug"<<std::endl;
            break;
        }
    }
}


void Appli::ChoixNiv()
{
    affichageChoixNiv();
}


void Appli::menu()
{
    affichageMenu();
    clique_sur_bouton_menu();
}




void Appli::evenement()
{
    sf::Event event;
    while (m_window.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed :
            m_appli_running = false;
            break;
        case sf::Event::MouseButtonPressed :
            //bouton = event.mouseButton.button;
            set_mouse_coord(event.mouseButton.x, event.mouseButton.y);
            mouse_button_pressed();
            break;
        case sf::Event::MouseButtonReleased :
            //bouton = event.mouseButton.button;
            set_mouse_coord(event.mouseButton.x, event.mouseButton.y);
            break;
        case sf::Event::MouseMoved :
            set_mouse_coord(event.mouseMove.x, event.mouseMove.y);
            break;
        default :
            break;
        }
    }
}


void Appli::set_mouse_coord(int x, int y)
{
    auto pos = m_window.mapPixelToCoords( {x, y});
    m_mouse = { pos.x, pos.y };
}


bool Appli::souris_dans_rectangle(const Position &coin, const Position &dims) const
{
    auto d = m_mouse - coin;
    return 0 <= d.x and d.x <= dims.x and 0 <= d.y and d.y <= dims.y;
}


void Appli::mouse_button_pressed()
{if(souris_dans_rectangle(COIN_JOUER, DIMS_JOUER) && m_etat==Etat::MENU)
    {
        std::cout << "Choix niveau" << std::endl;
        m_etat=Etat::CHOIXNIV;
    }

    if (souris_dans_rectangle(COIN_QUITTER, DIMS_QUITTER) && m_etat==Etat::MENU)
    {
        std::cout << "Quitter" << std::endl;
        m_etat=Etat::QUITTER;

    }
    if (souris_dans_rectangle(COIN_RETOUR_MENU, DIMS_RETOUR_MENU) && m_etat==Etat::CHOIXNIV)
    {
        std::cout << "Retour au Menu" << std::endl;
        m_etat=Etat::MENU;
    }

    if (souris_dans_rectangle(COIN_RECOMMENCER, DIMS_RECOMMENCER) && m_etat==Etat::JOUER)
    {
        std::cout << "recommencer" << std::endl;
        m_damier->initialiserTerrain("map.txt",m_niv);
        m_proc->initialiserProc();
        m_mainProc->reinitiliserMainProc();
    }

    if (souris_dans_rectangle(COIN_PLAY, DIMS_PLAY) && m_etat==Etat::JOUER)
    {
        std::cout << "lancer action" << std::endl;
        m_play=Jeux::PLAY;
    }

    if (souris_dans_rectangle(COIN_NIV1, DIMS_NIV1) && m_etat==Etat::CHOIXNIV)
    {
        std::cout << "Niveau 1" << std::endl;
        m_etat=Etat::JOUER;
        m_niv=0;
        m_damier->initialiserTerrain("map.txt",m_niv);
        m_proc->initialiserProc();
        m_mainProc->reinitiliserMainProc();

    }

    if (souris_dans_rectangle(COIN_NIV2, DIMS_NIV2) && m_etat==Etat::CHOIXNIV)
    {
        std::cout << "Niveau 1" << std::endl;
        m_etat=Etat::JOUER;
        m_niv=1;
        m_damier->initialiserTerrain("map.txt",m_niv);
        m_proc->initialiserProc();
        m_mainProc->reinitiliserMainProc();

    }
    if (souris_dans_rectangle(COIN_RETOUR_CHOIX, DIMS_RETOUR_CHOIX) && m_etat==Etat::JOUER)
    {
        std::cout << "Retour choix" << std::endl;
        m_etat=Etat::CHOIXNIV;
    }


    if(souris_dans_rectangle(COIN_AVANCER, DIMS_AVANCER) && m_etat==Etat::JOUER)
    {
        std::cout << "avancer" << std::endl;
        m_tmp_proc.clear();
        m_proc->integrerAction(1);
        m_tmp_proc=m_proc->lancerAction();
    }

    if(souris_dans_rectangle(COIN_TOURNER_DROITE, DIMS_TOURNER_DROITE) && m_etat==Etat::JOUER)
    {
        std::cout << "tournerDroite" << std::endl;
        m_tmp_proc.clear();
        m_proc->integrerAction(2);
        m_tmp_proc=m_proc->lancerAction();
    }

    if(souris_dans_rectangle(COIN_TOURNER_GAUCHE, DIMS_TOURNER_GAUCHE) && m_etat==Etat::JOUER)
    {
        std::cout << "tournerGauche" << std::endl;
        m_tmp_proc.clear();
        m_proc->integrerAction(3);
        m_tmp_proc=m_proc->lancerAction();
    }

    if(souris_dans_rectangle(COIN_SAUTER, DIMS_SAUTER) && m_etat==Etat::JOUER)
    {
        std::cout << "sauter" << std::endl;
        m_tmp_proc.clear();
        m_proc->integrerAction(4);
        m_tmp_proc=m_proc->lancerAction();
    }

    if(souris_dans_rectangle(COIN_ALLUMER, DIMS_ALLUMER) && m_etat==Etat::JOUER)
    {
        std::cout << "allumer" << std::endl;
        m_tmp_proc.clear();
        m_proc->integrerAction(5);
        m_tmp_proc=m_proc->lancerAction();
    }
    if(souris_dans_rectangle(COIN_P1, DIMS_P1) && m_etat==Etat::JOUER)
    {
        std::cout << "Proc1" << std::endl;
        m_tmp_proc=m_proc->lancerAction();
        m_mainProc->integrerProc(0,m_tmp_proc);
    }
}

void Appli::clique_sur_bouton_menu()
{
    m_Texture_Menu_Jouer_Dessus.loadFromFile("Menu_Jouer_Dessus.png");
    m_Sprite_Menu_Jouer_Dessus.setTexture(m_Texture_Menu_Jouer_Dessus);
    m_Texture_Menu_Quitter_Dessus.loadFromFile("Menu_Quitter_Dessus.png");
    m_Sprite_Menu_Quitter_Dessus.setTexture(m_Texture_Menu_Quitter_Dessus);

    if (souris_dans_rectangle(COIN_JOUER, DIMS_JOUER))
    {
        m_window.draw(m_Sprite_Menu_Jouer_Dessus);

    }
    if (souris_dans_rectangle(COIN_QUITTER, DIMS_QUITTER))
    {
        m_window.draw(m_Sprite_Menu_Quitter_Dessus);

    }
    m_window.display();
}

Appli::~Appli()
{
    delete m_damier;
    delete m_proc;
    delete m_mainProc;
}
