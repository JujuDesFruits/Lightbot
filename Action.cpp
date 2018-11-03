#include "Action.h"

Action::Action(Terrain * damier)
    :m_terrain{damier}
{
}

void Action::avancer()
{
    switch (m_terrain->directionRobot(m_terrain->pos_Robot())) {
    case 7:
        if (m_terrain->pos_Robot()-1>=0&&m_terrain->pos_Robot()-1<=m_terrain->TailleDamier()*m_terrain->TailleDamier()&&
                (m_terrain->pos_Robot()%m_terrain->TailleDamier()!=0))
            if ((m_terrain->nbEtage(m_terrain->pos_Robot())==m_terrain->nbEtage(m_terrain->pos_Robot()-1)&&m_terrain->pos_Robot()%2==1)&&
                    (!m_terrain->caseVide(m_terrain->pos_Robot()-1))){
                m_terrain->changerDirection(m_terrain->pos_Robot()-1,m_terrain->directionRobot(m_terrain->pos_Robot()));
                m_terrain->changerDirection(m_terrain->pos_Robot(),m_terrain->directionRobot(0));
                m_terrain->changerPos_Robot(m_terrain->pos_Robot()-1);
            }else
                if (m_terrain->pos_Robot()-m_terrain->TailleDamier()-1>=0&&m_terrain->pos_Robot()-m_terrain->TailleDamier()-1<=m_terrain->TailleDamier()*m_terrain->TailleDamier()&&
                        (m_terrain->pos_Robot()%m_terrain->TailleDamier()!=0))
                    if ((m_terrain->nbEtage(m_terrain->pos_Robot())==m_terrain->nbEtage(m_terrain->pos_Robot()-m_terrain->TailleDamier()-1)&&m_terrain->pos_Robot()%2==0)&&
                            (!m_terrain->caseVide(m_terrain->pos_Robot()-m_terrain->TailleDamier()-1))){
                        m_terrain->changerDirection(m_terrain->pos_Robot()-m_terrain->TailleDamier()-1,m_terrain->directionRobot(m_terrain->pos_Robot()));
                        m_terrain->changerDirection(m_terrain->pos_Robot(),m_terrain->directionRobot(0));
                        m_terrain->changerPos_Robot(m_terrain->pos_Robot()-m_terrain->TailleDamier()-1);
                    }
        break;
    case 8:
        if (m_terrain->pos_Robot()-m_terrain->TailleDamier()>=0&&m_terrain->pos_Robot()-m_terrain->TailleDamier()<=m_terrain->TailleDamier()*m_terrain->TailleDamier())
            if ((m_terrain->nbEtage(m_terrain->pos_Robot())==m_terrain->nbEtage(m_terrain->pos_Robot()-m_terrain->TailleDamier()))&&
                    (!m_terrain->caseVide(m_terrain->pos_Robot()-m_terrain->TailleDamier()))){
                m_terrain->changerDirection(m_terrain->pos_Robot()-m_terrain->TailleDamier(),m_terrain->directionRobot(m_terrain->pos_Robot()));
                m_terrain->changerDirection(m_terrain->pos_Robot(),m_terrain->directionRobot(0));
                m_terrain->changerPos_Robot(m_terrain->pos_Robot()-m_terrain->TailleDamier());
            }
        break;
    case 9:
        if (m_terrain->pos_Robot()+1>=0&&m_terrain->pos_Robot()+1<=m_terrain->TailleDamier()*m_terrain->TailleDamier()&&
                m_terrain->pos_Robot()%m_terrain->TailleDamier()!=m_terrain->TailleDamier()-1)
            if ((m_terrain->nbEtage(m_terrain->pos_Robot())==m_terrain->nbEtage(m_terrain->pos_Robot()+1)&&m_terrain->pos_Robot()%2==1)&&
                    (!m_terrain->caseVide(m_terrain->pos_Robot()+1))){
                m_terrain->changerDirection(m_terrain->pos_Robot()+1,m_terrain->directionRobot(m_terrain->pos_Robot()));
                m_terrain->changerDirection(m_terrain->pos_Robot(),m_terrain->directionRobot(0));
                m_terrain->changerPos_Robot(m_terrain->pos_Robot()+1);
            }else
                if (m_terrain->pos_Robot()-m_terrain->TailleDamier()+1>=0&&m_terrain->pos_Robot()-m_terrain->TailleDamier()+1<=m_terrain->TailleDamier()*m_terrain->TailleDamier()&&
                        (m_terrain->pos_Robot()%m_terrain->TailleDamier()!=m_terrain->TailleDamier()-1))
                    if ((m_terrain->nbEtage(m_terrain->pos_Robot())==m_terrain->nbEtage(m_terrain->pos_Robot()-m_terrain->TailleDamier()+1)&&m_terrain->pos_Robot()%2==0)&&
                            (!m_terrain->caseVide(m_terrain->pos_Robot()-m_terrain->TailleDamier()+1))){
                        m_terrain->changerDirection(m_terrain->pos_Robot()-m_terrain->TailleDamier()+1,m_terrain->directionRobot(m_terrain->pos_Robot()));
                        m_terrain->changerDirection(m_terrain->pos_Robot(),m_terrain->directionRobot(0));
                        m_terrain->changerPos_Robot(m_terrain->pos_Robot()-m_terrain->TailleDamier()+1);
                    }
        break;
    case 1:
        if (m_terrain->pos_Robot()+m_terrain->TailleDamier()-1>=0&&m_terrain->pos_Robot()+m_terrain->TailleDamier()-1<=m_terrain->TailleDamier()*m_terrain->TailleDamier()&&
                (m_terrain->pos_Robot()%m_terrain->TailleDamier()!=0))
            if ((m_terrain->nbEtage(m_terrain->pos_Robot())==m_terrain->nbEtage(m_terrain->pos_Robot()+m_terrain->TailleDamier()-1)&&m_terrain->pos_Robot()%2==1)&&
                    (!m_terrain->caseVide(m_terrain->pos_Robot()+m_terrain->TailleDamier()-1))){
                m_terrain->changerDirection(m_terrain->pos_Robot()+m_terrain->TailleDamier()-1,m_terrain->directionRobot(m_terrain->pos_Robot()));
                m_terrain->changerDirection(m_terrain->pos_Robot(),m_terrain->directionRobot(0));
                m_terrain->changerPos_Robot(m_terrain->pos_Robot()+m_terrain->TailleDamier()-1);
            }else
                if (m_terrain->pos_Robot()-1>=0&&m_terrain->pos_Robot()-1<=m_terrain->TailleDamier()*m_terrain->TailleDamier()&&
                        (m_terrain->pos_Robot()%m_terrain->TailleDamier()!=0))
                    if ((m_terrain->nbEtage(m_terrain->pos_Robot())==m_terrain->nbEtage(m_terrain->pos_Robot()-1)&&m_terrain->pos_Robot()%2==0)&&
                            (!m_terrain->caseVide(m_terrain->pos_Robot()-1))){
                        m_terrain->changerDirection(m_terrain->pos_Robot()-1,m_terrain->directionRobot(m_terrain->pos_Robot()));
                        m_terrain->changerDirection(m_terrain->pos_Robot(),m_terrain->directionRobot(0));
                        m_terrain->changerPos_Robot(m_terrain->pos_Robot()-1);
                    }
        break;
    case 2:
        if (m_terrain->pos_Robot()+m_terrain->TailleDamier()>=0&&m_terrain->pos_Robot()+m_terrain->TailleDamier()<=m_terrain->TailleDamier()*m_terrain->TailleDamier())
            if ((m_terrain->nbEtage(m_terrain->pos_Robot())==m_terrain->nbEtage(m_terrain->pos_Robot()+m_terrain->TailleDamier()))&&
                    (!m_terrain->caseVide(m_terrain->pos_Robot()+m_terrain->TailleDamier()))){
                m_terrain->changerDirection(m_terrain->pos_Robot()+m_terrain->TailleDamier(),m_terrain->directionRobot(m_terrain->pos_Robot()));
                m_terrain->changerDirection(m_terrain->pos_Robot(),m_terrain->directionRobot(0));
                m_terrain->changerPos_Robot(m_terrain->pos_Robot()+m_terrain->TailleDamier());
            }
        break;
    case 3:
        if ((m_terrain->pos_Robot()+m_terrain->TailleDamier()+1>=0&&m_terrain->pos_Robot()+m_terrain->TailleDamier()+1<=m_terrain->TailleDamier()*m_terrain->TailleDamier())&&
                (m_terrain->pos_Robot()%m_terrain->TailleDamier()!=m_terrain->TailleDamier()-1))
            if ((m_terrain->nbEtage(m_terrain->pos_Robot())==m_terrain->nbEtage(m_terrain->pos_Robot()+m_terrain->TailleDamier()+1)&&m_terrain->pos_Robot()%2==1)&&
                    (!m_terrain->caseVide(m_terrain->pos_Robot()+m_terrain->TailleDamier()+1))){
                m_terrain->changerDirection(m_terrain->pos_Robot()+m_terrain->TailleDamier()+1,m_terrain->directionRobot(m_terrain->pos_Robot()));
                m_terrain->changerDirection(m_terrain->pos_Robot(),m_terrain->directionRobot(0));
                m_terrain->changerPos_Robot(m_terrain->pos_Robot()+m_terrain->TailleDamier()+1);
            }else
                if ((m_terrain->pos_Robot()+1>=0&&m_terrain->pos_Robot()+1<=m_terrain->TailleDamier()*m_terrain->TailleDamier())&&
                        (m_terrain->pos_Robot()%m_terrain->TailleDamier()!=m_terrain->TailleDamier()-1))
                    if ((m_terrain->nbEtage(m_terrain->pos_Robot())==m_terrain->nbEtage(m_terrain->pos_Robot()+1)&&m_terrain->pos_Robot()%2==0)&&
                            (!m_terrain->caseVide(m_terrain->pos_Robot()+1))){
                        m_terrain->changerDirection(m_terrain->pos_Robot()+1,m_terrain->directionRobot(m_terrain->pos_Robot()));
                        m_terrain->changerDirection(m_terrain->pos_Robot(),m_terrain->directionRobot(0));
                        m_terrain->changerPos_Robot(m_terrain->pos_Robot()+1);
                    }
        break;
    default:
        break;
    }


}

void Action::tournerDroite()
{
    switch (m_terrain->directionRobot(m_terrain->pos_Robot())) {
    case 7:
        m_terrain->changerDirection(m_terrain->pos_Robot(),8);
        break;
    case 8:
        m_terrain->changerDirection(m_terrain->pos_Robot(),9);
        break;
    case 9:
        m_terrain->changerDirection(m_terrain->pos_Robot(),3);
        break;
    case 1:
        m_terrain->changerDirection(m_terrain->pos_Robot(),7);
        break;
    case 2:
        m_terrain->changerDirection(m_terrain->pos_Robot(),1);
        break;
    case 3:
        m_terrain->changerDirection(m_terrain->pos_Robot(),2);
        break;
    default:
        break;
    }
}

void Action::tournerGauche()
{
    switch (m_terrain->directionRobot(m_terrain->pos_Robot())) {
    case 7:
        m_terrain->changerDirection(m_terrain->pos_Robot(),1);
        break;
    case 8:
        m_terrain->changerDirection(m_terrain->pos_Robot(),7);
        break;
    case 9:
        m_terrain->changerDirection(m_terrain->pos_Robot(),8);
        break;
    case 1:
        m_terrain->changerDirection(m_terrain->pos_Robot(),2);
        break;
    case 2:
        m_terrain->changerDirection(m_terrain->pos_Robot(),3);
        break;
    case 3:
        m_terrain->changerDirection(m_terrain->pos_Robot(),9);
        break;
    default:
        break;
    }
}


void Action::sauter()
{
    switch (m_terrain->directionRobot(m_terrain->pos_Robot())) {
    case 7:
        if (m_terrain->pos_Robot()-1>=0&&m_terrain->pos_Robot()-1<=m_terrain->TailleDamier()*m_terrain->TailleDamier()&&
                (m_terrain->pos_Robot()%m_terrain->TailleDamier()!=0))
            if ((m_terrain->nbEtage(m_terrain->pos_Robot())==m_terrain->nbEtage(m_terrain->pos_Robot()-1)+1&&m_terrain->pos_Robot()%2==1&&
                 (!m_terrain->caseVide(m_terrain->pos_Robot()-1)))
                    ||(m_terrain->nbEtage(m_terrain->pos_Robot())==m_terrain->nbEtage(m_terrain->pos_Robot()-1)-1&&m_terrain->pos_Robot()%2==1)&&
                    (!m_terrain->caseVide(m_terrain->pos_Robot()-1))){
                m_terrain->changerDirection(m_terrain->pos_Robot()-1,m_terrain->directionRobot(m_terrain->pos_Robot()));
                m_terrain->changerDirection(m_terrain->pos_Robot(),m_terrain->directionRobot(0));
                m_terrain->changerPos_Robot(m_terrain->pos_Robot()-1);
            }else
                if (m_terrain->pos_Robot()-m_terrain->TailleDamier()-1>=0&&m_terrain->pos_Robot()-m_terrain->TailleDamier()-1<=m_terrain->TailleDamier()*m_terrain->TailleDamier()&&
                        (m_terrain->pos_Robot()%m_terrain->TailleDamier()!=0))
                    if ((m_terrain->nbEtage(m_terrain->pos_Robot())==m_terrain->nbEtage(m_terrain->pos_Robot()-m_terrain->TailleDamier()-1)+1&&m_terrain->pos_Robot()%2==0&&
                         (!m_terrain->caseVide(m_terrain->pos_Robot()-m_terrain->TailleDamier()-1)))
                            ||(m_terrain->nbEtage(m_terrain->pos_Robot())==m_terrain->nbEtage(m_terrain->pos_Robot()-m_terrain->TailleDamier()-1)-1&&m_terrain->pos_Robot()%2==0&&
                               (!m_terrain->caseVide(m_terrain->pos_Robot()-m_terrain->TailleDamier()-1)))){
                        m_terrain->changerDirection(m_terrain->pos_Robot()-m_terrain->TailleDamier()-1,m_terrain->directionRobot(m_terrain->pos_Robot()));
                        m_terrain->changerDirection(m_terrain->pos_Robot(),m_terrain->directionRobot(0));
                        m_terrain->changerPos_Robot(m_terrain->pos_Robot()-m_terrain->TailleDamier()-1);
                    }
        break;
    case 8:
        if (m_terrain->pos_Robot()-m_terrain->TailleDamier()>=0&&m_terrain->pos_Robot()-m_terrain->TailleDamier()<=m_terrain->TailleDamier()*m_terrain->TailleDamier())
            if ((m_terrain->nbEtage(m_terrain->pos_Robot())==m_terrain->nbEtage(m_terrain->pos_Robot()-m_terrain->TailleDamier())+1&&
                 (!m_terrain->caseVide(m_terrain->pos_Robot()-m_terrain->TailleDamier())))
                    ||(m_terrain->nbEtage(m_terrain->pos_Robot())==m_terrain->nbEtage(m_terrain->pos_Robot()-m_terrain->TailleDamier()))-1&&
                    (!m_terrain->caseVide(m_terrain->pos_Robot()-m_terrain->TailleDamier()))){
                m_terrain->changerDirection(m_terrain->pos_Robot()-m_terrain->TailleDamier(),m_terrain->directionRobot(m_terrain->pos_Robot()));
                m_terrain->changerDirection(m_terrain->pos_Robot(),m_terrain->directionRobot(0));
                m_terrain->changerPos_Robot(m_terrain->pos_Robot()-m_terrain->TailleDamier());
            }
        break;
    case 9:
        if (m_terrain->pos_Robot()+1>=0&&m_terrain->pos_Robot()+1<=m_terrain->TailleDamier()*m_terrain->TailleDamier()&&
                m_terrain->pos_Robot()%m_terrain->TailleDamier()!=m_terrain->TailleDamier()-1)
            if ((m_terrain->nbEtage(m_terrain->pos_Robot())==m_terrain->nbEtage(m_terrain->pos_Robot()+1)+1&&m_terrain->pos_Robot()%2==1&&
                 (!m_terrain->caseVide(m_terrain->pos_Robot()+1)))
                    ||(m_terrain->nbEtage(m_terrain->pos_Robot())==m_terrain->nbEtage(m_terrain->pos_Robot()+1)-1&&m_terrain->pos_Robot()%2==1&&
                       (!m_terrain->caseVide(m_terrain->pos_Robot()+1)))){
                m_terrain->changerDirection(m_terrain->pos_Robot()+1,m_terrain->directionRobot(m_terrain->pos_Robot()));
                m_terrain->changerDirection(m_terrain->pos_Robot(),m_terrain->directionRobot(0));
                m_terrain->changerPos_Robot(m_terrain->pos_Robot()+1);
            }else
                if (m_terrain->pos_Robot()-m_terrain->TailleDamier()+1>=0&&m_terrain->pos_Robot()-m_terrain->TailleDamier()+1<=m_terrain->TailleDamier()*m_terrain->TailleDamier()&&
                        (m_terrain->pos_Robot()%m_terrain->TailleDamier()!=m_terrain->TailleDamier()-1))
                    if ((m_terrain->nbEtage(m_terrain->pos_Robot())==m_terrain->nbEtage(m_terrain->pos_Robot()-m_terrain->TailleDamier()+1)-1&&m_terrain->pos_Robot()%2==0&&
                         (!m_terrain->caseVide(m_terrain->pos_Robot()-m_terrain->TailleDamier()+1)))
                            ||(m_terrain->nbEtage(m_terrain->pos_Robot())==m_terrain->nbEtage(m_terrain->pos_Robot()-m_terrain->TailleDamier()+1)+1&&m_terrain->pos_Robot()%2==0&&
                               (!m_terrain->caseVide(m_terrain->pos_Robot()-m_terrain->TailleDamier()+1)))){
                        m_terrain->changerDirection(m_terrain->pos_Robot()-m_terrain->TailleDamier()+1,m_terrain->directionRobot(m_terrain->pos_Robot()));
                        m_terrain->changerDirection(m_terrain->pos_Robot(),m_terrain->directionRobot(0));
                        m_terrain->changerPos_Robot(m_terrain->pos_Robot()-m_terrain->TailleDamier()+1);
                    }
        break;
    case 1:
        if (m_terrain->pos_Robot()+m_terrain->TailleDamier()-1>=0&&m_terrain->pos_Robot()+m_terrain->TailleDamier()-1<=m_terrain->TailleDamier()*m_terrain->TailleDamier()&&
                (m_terrain->pos_Robot()%m_terrain->TailleDamier()!=0))
            if ((m_terrain->nbEtage(m_terrain->pos_Robot())==m_terrain->nbEtage(m_terrain->pos_Robot()+m_terrain->TailleDamier()-1)+1&&m_terrain->pos_Robot()%2==1&&
                 (!m_terrain->caseVide(m_terrain->pos_Robot()+m_terrain->TailleDamier()-1)))
                    ||(m_terrain->nbEtage(m_terrain->pos_Robot())==m_terrain->nbEtage(m_terrain->pos_Robot()+m_terrain->TailleDamier()-1)-1&&m_terrain->pos_Robot()%2==1&&
                       (!m_terrain->caseVide(m_terrain->pos_Robot()+m_terrain->TailleDamier()-1)))){
                m_terrain->changerDirection(m_terrain->pos_Robot()+m_terrain->TailleDamier()-1,m_terrain->directionRobot(m_terrain->pos_Robot()));
                m_terrain->changerDirection(m_terrain->pos_Robot(),m_terrain->directionRobot(0));
                m_terrain->changerPos_Robot(m_terrain->pos_Robot()+m_terrain->TailleDamier()-1);
            }else
                if (m_terrain->pos_Robot()-1>=0&&m_terrain->pos_Robot()-1<=m_terrain->TailleDamier()*m_terrain->TailleDamier()&&
                        (m_terrain->pos_Robot()%m_terrain->TailleDamier()!=0))
                    if ((m_terrain->nbEtage(m_terrain->pos_Robot())==m_terrain->nbEtage(m_terrain->pos_Robot()-1)-1&&m_terrain->pos_Robot()%2==0&&
                         (!m_terrain->caseVide(m_terrain->pos_Robot()-1)))
                            ||(m_terrain->nbEtage(m_terrain->pos_Robot())==m_terrain->nbEtage(m_terrain->pos_Robot()-1)+1&&m_terrain->pos_Robot()%2==0&&
                               (!m_terrain->caseVide(m_terrain->pos_Robot()-1)))){
                        m_terrain->changerDirection(m_terrain->pos_Robot()-1,m_terrain->directionRobot(m_terrain->pos_Robot()));
                        m_terrain->changerDirection(m_terrain->pos_Robot(),m_terrain->directionRobot(0));
                        m_terrain->changerPos_Robot(m_terrain->pos_Robot()-1);
                    }
        break;
    case 2:
        if (m_terrain->pos_Robot()+m_terrain->TailleDamier()>=0&&m_terrain->pos_Robot()+m_terrain->TailleDamier()<=m_terrain->TailleDamier()*m_terrain->TailleDamier())
            if ((m_terrain->nbEtage(m_terrain->pos_Robot())==m_terrain->nbEtage(m_terrain->pos_Robot()+m_terrain->TailleDamier())+1&&
                 (!m_terrain->caseVide(m_terrain->pos_Robot()+m_terrain->TailleDamier())))
                    ||(m_terrain->nbEtage(m_terrain->pos_Robot())==m_terrain->nbEtage(m_terrain->pos_Robot()+m_terrain->TailleDamier())-1&&
                       (!m_terrain->caseVide(m_terrain->pos_Robot()+m_terrain->TailleDamier())))){
                m_terrain->changerDirection(m_terrain->pos_Robot()+m_terrain->TailleDamier(),m_terrain->directionRobot(m_terrain->pos_Robot()));
                m_terrain->changerDirection(m_terrain->pos_Robot(),m_terrain->directionRobot(0));
                m_terrain->changerPos_Robot(m_terrain->pos_Robot()+m_terrain->TailleDamier());
            }
        break;
    case 3:
        if ((m_terrain->pos_Robot()+m_terrain->TailleDamier()+1>=0&&m_terrain->pos_Robot()+m_terrain->TailleDamier()+1<=m_terrain->TailleDamier()*m_terrain->TailleDamier())&&
                (m_terrain->pos_Robot()%m_terrain->TailleDamier()!=m_terrain->TailleDamier()-1))
            if ((m_terrain->nbEtage(m_terrain->pos_Robot())==m_terrain->nbEtage(m_terrain->pos_Robot()+m_terrain->TailleDamier()+1)+1&&m_terrain->pos_Robot()%2==1&&
                 (!m_terrain->caseVide(m_terrain->pos_Robot()+m_terrain->TailleDamier()+1)))
                    ||(m_terrain->nbEtage(m_terrain->pos_Robot())==m_terrain->nbEtage(m_terrain->pos_Robot()+m_terrain->TailleDamier()+1)-1&&m_terrain->pos_Robot()%2==1&&
                       (!m_terrain->caseVide(m_terrain->pos_Robot()+m_terrain->TailleDamier()+1)))){
                m_terrain->changerDirection(m_terrain->pos_Robot()+m_terrain->TailleDamier()+1,m_terrain->directionRobot(m_terrain->pos_Robot()));
                m_terrain->changerDirection(m_terrain->pos_Robot(),m_terrain->directionRobot(0));
                m_terrain->changerPos_Robot(m_terrain->pos_Robot()+m_terrain->TailleDamier()+1);
            }else
                if (m_terrain->pos_Robot()+1>=0&&m_terrain->pos_Robot()+1<=m_terrain->TailleDamier()*m_terrain->TailleDamier()&&
                        (m_terrain->pos_Robot()%m_terrain->TailleDamier()!=m_terrain->TailleDamier()-1))
                    if ((m_terrain->nbEtage(m_terrain->pos_Robot())==m_terrain->nbEtage(m_terrain->pos_Robot()+1)+1&&m_terrain->pos_Robot()%2==0&&
                         (!m_terrain->caseVide(m_terrain->pos_Robot()+1)))
                            ||(m_terrain->nbEtage(m_terrain->pos_Robot())==m_terrain->nbEtage(m_terrain->pos_Robot()+1)-1&&m_terrain->pos_Robot()%2==0&&
                               (!m_terrain->caseVide(m_terrain->pos_Robot()+1)))){
                        m_terrain->changerDirection(m_terrain->pos_Robot()+1,m_terrain->directionRobot(m_terrain->pos_Robot()));
                        m_terrain->changerDirection(m_terrain->pos_Robot(),m_terrain->directionRobot(0));
                        m_terrain->changerPos_Robot(m_terrain->pos_Robot()+1);
                    }
        break;
    default:
        break;
    }

}

void Action::allumer()
{
    if (m_terrain->lumiereEteint(m_terrain->pos_Robot())){
        m_terrain->changerType(m_terrain->pos_Robot(),3);
    }else{
        if (m_terrain->lumiereAllume(m_terrain->pos_Robot()))
            m_terrain->changerType(m_terrain->pos_Robot(),2);
    }
}
