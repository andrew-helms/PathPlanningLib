#pragma once
#include "IVertex.hpp"

namespace PathPlanningLib
{
    class IVertex;

    class IEdge
    {
    public:
        IEdge(double cost) : m_Cost(cost) {};
        virtual ~IEdge(){};
        virtual std::shared_ptr<const IVertex> Apply(const IVertex& state) const = 0;
        inline double GetCost() const { return m_Cost; };

    private:
        double m_Cost;
    };
}