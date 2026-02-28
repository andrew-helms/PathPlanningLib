#pragma once
#include "IState.hpp"

namespace PathPlanningLib
{
    class IAction
    {
    public:
        IAction(double cost) : m_Cost(cost) {};
        virtual ~IAction(){};
        virtual std::shared_ptr<const IState> Apply(const IState& state) const = 0;
        inline double GetCost() const { return m_Cost; };

    private:
        double m_Cost;
    };
}