#include "Cases.h"


Cases::Cases(int type, int direction, int hauteur)
    :m_Type{type}
    ,m_DirectionRobot{direction}
    ,m_Hauteur{hauteur}
{
}

int Cases::type()
{
    return m_Type;
}

void Cases::changerLeType(int valeur)
{
    m_Type=valeur;
}

int Cases::direction()
{
    return m_DirectionRobot;
}

void Cases::changerLaDirection(int valeur)
{
    m_DirectionRobot=valeur;
}

int Cases::hauteur()
{
    return m_Hauteur;
}
