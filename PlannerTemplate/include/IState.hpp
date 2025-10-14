#pragma once

#include <vector>
#include <memory>

namespace PathPlanningLib
{
    namespace PlannerTemplate
    {
        class IState
        {
        public:
            IState() : m_CostMultiplier(1) {}
            virtual ~IState(){}

            virtual bool operator==(const IState& other) const = 0;
            virtual bool operator!=(const IState& other) const = 0;
            virtual std::size_t CalculateHash() const = 0;
            virtual inline double GetCostMultiplier() const {return m_CostMultiplier;}
            virtual bool IsValid() const = 0;

        protected:
            double m_CostMultiplier;
        };
    }
}


template<>
struct std::hash<PathPlanningLib::PlannerTemplate::IState>
{
    std::size_t operator()(const PathPlanningLib::PlannerTemplate::IState& state)
    {
        return state.CalculateHash();
    }
};