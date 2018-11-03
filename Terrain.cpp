#include "Terrain.h"

using namespace std;

Terrain::Terrain()
{
}

void Terrain::initialiserTerrain(string doc, int niv){
    fstream f;
    string s;
    f.open(doc.c_str(), ios::in);
    m_cases.clear();
    int cpt=1;
    if (!f.fail())
    {
        f>>s;
        int testNiveau=0;
        while (!f.eof())
        {
            if (testNiveau==niv){
                if (s=="V"){
                    m_cases.push_back(new Cases(0,0,0));
                    cpt++;}
                if (s=="C"){
                    m_cases.push_back(new Cases(1,0,0));
                    cpt++;}
                if (s=="CC"){
                    m_cases.push_back(new Cases(1,0,1));
                    cpt++;}
                if (s=="CCC"){
                    m_cases.push_back(new Cases(1,0,2));
                    cpt++;}
                if (s=="E"){
                    m_cases.push_back(new Cases(2,0,0));
                    cpt++;}
                if (s=="CE"){
                    m_cases.push_back(new Cases(2,0,1));
                    cpt++;}
                if (s=="CCE"){
                    m_cases.push_back(new Cases(2,0,2));
                    cpt++;}

                if (s=="7"){
                    m_cases.push_back(new Cases(1,7,0));
                    m_PositionOrigine=cpt-1;
                    cpt++;}
                if (s=="8"){
                    m_cases.push_back(new Cases(1,8,0));
                    m_PositionOrigine=cpt-1;
                    cpt++;}
                if (s=="1"){
                    m_cases.push_back(new Cases(1,1,0));
                    m_PositionOrigine=cpt-1;
                    cpt++;}
                if (s=="9"){
                    m_cases.push_back(new Cases(1,9,0));
                    m_PositionOrigine=cpt-1;
                    cpt++;}
                if (s=="2"){
                    m_cases.push_back(new Cases(1,2,0));
                    m_PositionOrigine=cpt-1;
                    cpt++;}
                if (s=="3"){
                    m_cases.push_back(new Cases(1,3,0));
                    m_PositionOrigine=cpt-1;
                    cpt++;}
                if (s=="C7"){
                    m_cases.push_back(new Cases(1,7,1));
                    m_PositionOrigine=cpt-1;
                    cpt++;}
                if (s=="CC7"){
                    m_cases.push_back(new Cases(1,7,2));
                    m_PositionOrigine=cpt-1;
                    cpt++;}
                if (s=="C8"){
                    m_cases.push_back(new Cases(1,8,1));
                    m_PositionOrigine=cpt-1;
                    cpt++;}
                if (s=="CC8"){
                    m_cases.push_back(new Cases(1,8,2));
                    m_PositionOrigine=cpt-1;
                    cpt++;}
                if (s=="C1"){
                    m_cases.push_back(new Cases(1,1,1));
                    m_PositionOrigine=cpt-1;
                    cpt++;}
                if (s=="CC1"){
                    m_cases.push_back(new Cases(1,1,2));
                    m_PositionOrigine=cpt-1;
                    cpt++;}
                if (s=="C3"){
                    m_cases.push_back(new Cases(1,3,1));
                    m_PositionOrigine=cpt-1;
                    cpt++;}
                if (s=="CC3"){
                    m_cases.push_back(new Cases(1,3,2));
                    m_PositionOrigine=cpt-1;
                    cpt++;}
                if (s=="C2"){
                    m_cases.push_back(new Cases(1,2,1));
                    m_PositionOrigine=cpt-1;
                    cpt++;}
                if (s=="CC2"){
                    m_cases.push_back(new Cases(1,2,2));
                    m_PositionOrigine=cpt-1;
                    cpt++;}
                if (s=="C9"){
                    m_cases.push_back(new Cases(1,9,1));
                    m_PositionOrigine=cpt-1;
                    cpt++;}
                if (s=="CC9"){
                    m_cases.push_back(new Cases(1,9,2));
                    m_PositionOrigine=cpt-1;
                    cpt++;}
            }
            if (s=="niveauSuivant"){
                testNiveau++;}
            f>>s;
        }
        f.close();
    }
    else
    {
        cerr << "Erreur Fichier : " << doc << endl;
        exit(EXIT_FAILURE);
    }
    m_TailleDamier=sqrt(cpt);
}

bool Terrain::caseVide(int pos)
{
    return (m_cases[pos]->type()==0);
}

bool Terrain::lumiereEteint(int pos)
{
    return (m_cases[pos]->type()==2);
}

bool Terrain::lumiereAllume(int pos)
{
    return (m_cases[pos]->type()==3);
}

void Terrain::changerType(int pos, int type)
{
    m_cases[pos]->changerLeType(type);
}

void Terrain::changerDirection(int pos, int direction)
{
    m_cases[pos]->changerLaDirection(direction);
}

int Terrain::nbEtage(int pos)
{
    return m_cases[pos]->hauteur();
}

int Terrain::directionRobot(int pos)
{
    return m_cases[pos]->direction();
}

bool Terrain::gagner()
{
    int i=0;
    bool verification =true;
    while (verification && i<m_cases.size()){
        if (lumiereEteint(i))
            verification=false;
        i++;
    }
    return verification;
}

int Terrain::pos_Robot()
{
    return m_PositionOrigine;
}

void Terrain::changerPos_Robot(int nouvellePos)
{
    m_PositionOrigine=nouvellePos;
}

int Terrain::TailleDamier()
{
    return m_TailleDamier;
}

Terrain::~Terrain()
{
    for ( auto n : m_cases)
    {
        delete n;
    }
}
