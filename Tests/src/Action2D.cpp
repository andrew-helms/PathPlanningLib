#include <memory>
#include <iostream>

#include "Action2D.hpp"

namespace PathPlanningLib
{
    namespace Tests
    {
        Action2D::Action2D(int moveX, int moveY, double cost) : 
            m_MoveX(moveX),
            m_MoveY(moveY),
            m_Cost(cost)
        {

        }

        Action2D::~Action2D()
        {

        }

        //std::shared_ptr<const IVertex> Action2D::Apply(const IVertex& state) const
        //{
        //    const State2D& state2d = (const State2D&)state;
        //    //if (state2d)
        //    {
        //        return Apply(state2d);
        //    }
        //    //else
        //    {
        //        std::cout << "Not an expected type" << std::endl;
        //        return nullptr;
        //    }
        //}

        std::shared_ptr<const State2D> Action2D::Apply(const State2D& state) const
        {
            return std::make_shared<const State2D>(state.GetX() + m_MoveX, state.GetY() + m_MoveY);
        }

        int Action2D::GetMoveX() const
        {
            return m_MoveX;
        }

        int Action2D::GetMoveY() const
        {
            return m_MoveY;
        }
    }     
}