#pragma once

#include <memory>

#include "IAction.hpp"
#include "State2D.hpp"

namespace PathPlanningLib
{
    namespace Tests
    {
        class Action2D : public IAction
        {
        public:
            Action2D(int moveX, int moveY, double cost);
            ~Action2D();

            int GetMoveX() const;
            int GetMoveY() const;
            std::shared_ptr<const IState> Apply(const IState& state) const override;
            std::shared_ptr<const State2D> Apply(const State2D& state) const;

        private:
            int m_MoveX;
            int m_MoveY;
        };
    }
}