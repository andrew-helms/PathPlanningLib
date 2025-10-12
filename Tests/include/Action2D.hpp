#pragma once

#include "IAction.hpp"

#include "State2D.hpp"

namespace PathPlanningLib
{
    namespace Test
    {
        class Action2D : PathPlanningLib::PlannerTemplate::IAction
        {
        public:
            Action2D(int moveX, int moveY, double cost);
            ~Action2D();

            int GetMoveX() const;
            int GetMoveY() const;
            double GetCost() const override;
            std::shared_ptr<const PathPlanningLib::PlannerTemplate::IState> Apply(std::shared_ptr<const PathPlanningLib::PlannerTemplate::IState> state) const override;

        private:
            int m_MoveX;
            int m_MoveY;
            double m_Cost;
        };
    }
}