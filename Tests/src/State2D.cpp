#include "State2D.hpp"

namespace PathPlanningLib
{
    namespace Test
    {
        State2D::State2D() : IState()
        {

        }

        State2D::~State2D()
        {

        }

        bool State2D::operator==(const PlannerTemplate::IState& other)
        {
            if (State2D const* p = dynamic_cast<State2D const*>(&other))
            {
                return m_X == p->GetX() && m_Y == p->GetY()
            }
            else {
                return false;
            }
        }

        size_t State2D::CalculateHash() const
        {
            return std::hash<int>()(m_X) ^ (std::hash<int>()(m_Y) << 1);
        }

        int State2D::GetX() const
        {
            return m_X;
        }

        int State2D::GetY() const
        {
            return m_Y;
        }
    }
}