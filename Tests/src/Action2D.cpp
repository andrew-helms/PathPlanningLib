#include "Action2D.hpp"

namespace PathPlanningLib
{
    namespace Tests
    {
        Action2D::Action2D(int moveX, int moveY, double cost)
        {
            m_MoveX = moveX;
            m_MoveY = moveY;
            m_Cost = cost;
        }
    }     
}