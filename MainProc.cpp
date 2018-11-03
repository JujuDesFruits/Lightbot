#include "MainProc.h"


MainProc::MainProc()
{
    
}

std::vector<int> MainProc::lancerMainProc()
{
    return m_liste_MainAction;
}

void MainProc::reinitiliserMainProc()
{

    m_liste_MainAction.clear();
}

void MainProc::integrerProc(int action, std::vector<int>liste_action)
{
    for (int i=0;i<liste_action.size();i++){
        m_liste_MainAction.push_back(liste_action[i]);
        std::cout<<"nouvelle element dans main :"<<std::endl;
        std::cout<<liste_action[i]<<std::endl;
    }
    if (action!=0)
        m_liste_MainAction.push_back(action);
}
