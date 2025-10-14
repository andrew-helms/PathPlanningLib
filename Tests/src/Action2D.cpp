#include <memory>

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

        std::shared_ptr<const PathPlanningLib::PlannerTemplate::IState> Action2D::Apply(std::shared_ptr<const PathPlanningLib::PlannerTemplate::IState> state) const
        {
            auto state2d = std::dynamic_pointer_cast<const State2D>(state);
            if (state2d)
            {
                return Apply(state2d);
            }
            else
            {
                return nullptr;
            }
        }

        std::shared_ptr<const State2D> Action2D::Apply(std::shared_ptr<const State2D> state) const
        {
            return std::make_shared<const State2D>(state->GetX() + m_MoveX, state->GetY() + m_MoveY);
        }
    }     
}