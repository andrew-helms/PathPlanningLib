#pragma once
#include "IState.hpp"

namespace PathPlanningLib
{
    namespace PlannerTemplate
    {
        class IAction
        {
        public:
            IAction(){};
            virtual ~IAction(){};
            virtual std::shared_ptr<const IState> Apply(std::shared_ptr<const IState> state) const = 0;
            inline double GetCost() const { return m_Cost; };

        private:
            double m_Cost;
        };
    }
}