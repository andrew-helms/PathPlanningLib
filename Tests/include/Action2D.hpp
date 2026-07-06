#pragma once

#include <memory>

#include "IEdge.hpp"
#include "State2D.hpp"

namespace PathPlanningLib
{
    namespace Tests
    {
        class State2D;

        class Action2D /*: public IEdge*/
        {
        public:
            Action2D(int moveX, int moveY, double cost);
            ~Action2D();

            int GetMoveX() const;
            int GetMoveY() const;
            //std::shared_ptr<const IVertex> Apply(const IVertex& state) const override;
            std::shared_ptr<const State2D> Apply(const State2D& state) const;
            double GetCost() const { return m_Cost; };

        private:
            int m_MoveX;
            int m_MoveY;
            double m_Cost;
        };
    }
}