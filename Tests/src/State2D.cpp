#include "State2D.hpp"

#include <iostream>

namespace PathPlanningLib
{
    namespace Tests
    {
        State2D::State2D(int x, int y) : IState()
        {
            m_X = x;
            m_Y = y;
        }

        State2D::~State2D()
        {

        }

        bool State2D::operator==(const PlannerTemplate::IState& other) const
        {
            if (State2D const* p = dynamic_cast<State2D const*>(&other))
            {
                return *this == *p;
            }
            else
            {
                return false;
            }
        }

        bool State2D::operator!=(const PlannerTemplate::IState& other) const
        {
            return !(*this == other);
        }

        bool State2D::operator==(const State2D& other) const
        {
            bool equals = m_X == other.GetX() && m_Y == other.GetY();

            return m_X == other.GetX() && m_Y == other.GetY();
        }

        bool State2D::operator!=(const State2D& other) const
        {
            return !(*this == other);
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

        bool State2D::IsValid() const 
        {
            return true;
        }
    }
}