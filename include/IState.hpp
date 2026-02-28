#pragma once

#include <vector>
#include <memory>

namespace PathPlanningLib
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
        virtual std::vector<std::pair<std::shared_ptr<const IState&>, double>> GetConnections() const = 0;

    protected:
        double m_CostMultiplier;
    };
}


template<>
struct std::hash<PathPlanningLib::IState>
{
    std::size_t operator()(const PathPlanningLib::IState& state)
    {
        return state.CalculateHash();
    }
};