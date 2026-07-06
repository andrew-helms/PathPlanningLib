#pragma once

#include <vector>
#include <memory>

#include "IEdge.hpp"

namespace PathPlanningLib
{
    class IEdge;

    class IVertex
    {
    public:
        IVertex() : m_CostMultiplier(1) {}
        virtual ~IVertex(){}

        virtual bool operator==(const IVertex& other) const = 0;
        virtual bool operator!=(const IVertex& other) const = 0;
        virtual std::size_t CalculateHash() const = 0;
        virtual inline double GetCostMultiplier() const { return m_CostMultiplier; }
        virtual std::vector<std::pair<std::shared_ptr<const IEdge>, std::shared_ptr<const IVertex>>> GetEdges() const = 0;

    protected:
        double m_CostMultiplier;
    };
}


template<>
struct std::hash<PathPlanningLib::IVertex>
{
    std::size_t operator()(const PathPlanningLib::IVertex& state)
    {
        return state.CalculateHash();
    }
};