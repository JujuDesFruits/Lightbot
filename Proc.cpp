#include "Proc.h"

Proc::Proc()
{
}

std::vector<int> Proc::lancerAction()
{
    return m_liste_action;
}

void Proc::initialiserProc()
{
    m_liste_action.clear();
}

void Proc::integrerAction(int action)
{
    if (m_liste_action.size()<m_TailleMax)
        m_liste_action.push_back(action);
}
